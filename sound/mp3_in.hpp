#pragma once
//=====================================================================//
/*!	@file
	@brief	libmad を使った MP3 デコード・クラス @n
			※このクラスを使うには、libmad ライブラリーが必要
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2018 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RX/blob/master/LICENSE
*/
//=====================================================================//
#include <libmad/mad.h>
#include "common/file_io.hpp"
#include "sound/id3_mgr.hpp"
#include "sound/af_play.hpp"

extern "C" {
	void set_sample_rate(uint32_t freq);
};

namespace sound {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief	MP3 形式デコード・クラス
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	class mp3_in : public af_play {

		static const uint32_t INPUT_BUFFER_SIZE = 2048;

		mad_stream	mad_stream_;
		mad_frame	mad_frame_;
		mad_synth	mad_synth_;
		mad_timer_t	mad_timer_;

		uint8_t		input_buffer_[INPUT_BUFFER_SIZE + MAD_BUFFER_GUARD];

		// サブバンド領域フィルター特性用。
		mad_fixed_t		subband_filter_[32];
		bool			subband_filter_enable_;
		bool			id3v1_;

		uint32_t		time_;


		int fill_read_buffer_(utils::file_io& fin, mad_stream& strm)
 		{
			/* The input bucket must be filled if it becomes empty or if
			 * it's the first execution of the loop.
			 */
			if(strm.buffer == NULL || strm.error == MAD_ERROR_BUFLEN) {
				size_t size;
				size_t remaining;
				unsigned char* ptr;

				/* {2} libmad may not consume all bytes of the input
				 * buffer. If the last frame in the buffer is not wholly
				 * contained by it, then that frame's start is pointed by
				 * the next_frame member of the Stream structure. This
				 * common situation occurs when mad_frame_decode() fails,
				 * sets the stream error code to MAD_ERROR_BUFLEN, and
				 * sets the next_frame pointer to a non NULL value. (See
				 * also the comment marked {4} bellow.)
				 *
				 * When this occurs, the remaining unused bytes must be
				 * put back at the beginning of the buffer and taken in
				 * account before refilling the buffer. This means that
				 * the input buffer must be large enough to hold a whole
				 * frame at the highest observable bit-rate (currently 448
				 * kb/s). XXX=XXX Is 2016 bytes the size of the largest
				 * frame? (448000*(1152/32000))/8
				 */
				if(strm.next_frame != NULL) {
					remaining = strm.bufend - strm.next_frame;
					memmove(&input_buffer_[0], strm.next_frame, remaining);
					ptr  = &input_buffer_[remaining];
					size = INPUT_BUFFER_SIZE - remaining;
				} else {
					size = INPUT_BUFFER_SIZE;
					ptr  = &input_buffer_[0];
					remaining = 0;
				}

				/* Fill-in the buffer. If an error occurs print a message
				 * and leave the decoding loop. If the end of stream is
				 * reached we also leave the loop but the return status is
				 * left untouched.
				 */
				// ReadSize = BstdRead(ReadStart, 1, ReadSize, BstdFile);
				size_t req = size;
				size_t rs = fin.read(ptr, 1, req);
				if(id3v1_) {
					if(fin.tell() >= (fin.get_file_size() - 128)) return -1;
				} else {
					if(fin.eof()) return -1;
				}
				size = rs;
				if(rs < req) {
					memset(&ptr[rs], 0, MAD_BUFFER_GUARD);
					size += MAD_BUFFER_GUARD;
				}

				/* Pipe the new buffer content to libmad's stream decoder
				 * facility.
				 */
				mad_stream_buffer(&strm, &input_buffer_[0], size + remaining);
				strm.error = MAD_ERROR_NONE;
				return 0;
			} else {
				return 1;
			}
		}


		/****************************************************************************
		 * Applies a frequency-domain filter to audio data in the subband-domain.	*
		 ****************************************************************************/
		void apply_filter_(mad_frame& frame)
		{
			/* There is two application loops, each optimized for the number
			 * of audio channels to process. The first alternative is for
			 * two-channel frames, the second is for mono-audio.
			 */
			int num = MAD_NSBSAMPLES(&frame.header);
			if(frame.header.mode != MAD_MODE_SINGLE_CHANNEL) {
				for(int ch = 0; ch < 2; ++ch) {
					for(int s = 0; s < num; ++s) {
						for(int sb = 0; sb < 32; ++sb) {
							frame.sbsample[ch][s][sb] =
								mad_f_mul(frame.sbsample[ch][s][sb], subband_filter_[sb]);
						}
					}
				}
			} else {
				for(int s = 0; s < num; ++s) {
					for(int sb = 0; sb < 32; ++sb) {
						frame.sbsample[0][s][sb] =
							mad_f_mul(frame.sbsample[0][s][sb], subband_filter_[sb]);
					}
				}
			}
		}


		static const short SHRT_MAX_ = 32767;

		/****************************************************************************
		 * Converts a sample from mad's fixed point number format to a signed		*
		 * short (16 bits).															*
		 ****************************************************************************/
		static short MadFixedToSshort(mad_fixed_t v)
		{
			/* A fixed point number is formed of the following bit pattern:
			 *
			 * SWWWFFFFFFFFFFFFFFFFFFFFFFFFFFFF
			 * MSB                          LSB
			 * S ==> Sign (0 is positive, 1 is negative)
			 * W ==> Whole part bits
			 * F ==> Fractional part bits
			 *
			 * This pattern contains MAD_F_FRACBITS fractional bits, one
			 * should alway use this macro when working on the bits of a fixed
			 * point number. It is not guaranteed to be constant over the
			 * different platforms supported by libmad.
			 *
			 * The signed short value is formed, after clipping, by the least
			 * significant whole part bit, followed by the 15 most significant
			 * fractional part bits. Warning: this is a quick and dirty way to
			 * compute the 16-bit number, madplay includes much better
			 * algorithms.
			 */

			// Clipping..
			if(v >= MAD_F_ONE) {
				return SHRT_MAX_;
			}
			if(v <= -MAD_F_ONE) {
				return -SHRT_MAX_;
			}

			return (signed short)(v >> (MAD_F_FRACBITS - 15));
		}

	public:
		//-----------------------------------------------------------------//
		/*!
			@brief	コンストラクター
		*/
		//-----------------------------------------------------------------//
		mp3_in() : subband_filter_enable_(false), id3v1_(false), time_(0) { }


		//-----------------------------------------------------------------//
		/*!
			@brief	デコード
			@param[in]	fin		file_io コンテキスト（参照）
			@param[in]	out		オーディオ出力（参照）
			@return 正常終了なら「true」
		*/
		//-----------------------------------------------------------------//
		template <class AUDIO_OUT>
		bool decode(utils::file_io& fin, AUDIO_OUT& out)
		{
			id3_mgr id3;
			id3.parse(fin);
			if(tag_task_) {
				const auto& tag = id3.get_tag();
				tag_task_(fin, tag);
//				utils::format("Album:  '%s'\n") % tag.album_;
//				utils::format("Title:  '%s'\n") % tag.title_;
//				utils::format("Artist: '%s'\n") % tag.artist_;
//				utils::format("Year:    %s\n") % tag.year_;
//				utils::format("Disc:    %s\n") % tag.disc_;
//				utils::format("Track:   %s\n") % tag.track_;
			}

			mad_stream_init(&mad_stream_);
			mad_frame_init(&mad_frame_);
			mad_synth_init(&mad_synth_);
			mad_timer_reset(&mad_timer_);

			uint32_t forg = fin.tell();
			bool info = false;
			uint32_t pos = 0;
			uint32_t frame_count = 0;
			bool status = true;
			bool pause = false;
			while(fill_read_buffer_(fin, mad_stream_) >= 0) {

				CTRL ctrl = CTRL::NONE;
				if(ctrl_task_) {
					ctrl = ctrl_task_();
				}
				if(ctrl == CTRL::STOP) {
					out.mute();
					status = false;
					break;
				} else if(ctrl == CTRL::REPLAY) {
					out.mute();
					fin.seek(utils::file_io::SEEK::SET, forg);
					info = false;
					pos = 0;
					time_ = 0;
					frame_count = 0;
					status = true;
					pause = false;
					continue;
				} else if(ctrl == CTRL::PAUSE) {
					out.mute();
					pause = !pause;
				}
				if(pause) {
					utils::delay::milli_second(5);
					continue;
				}

				if(mad_frame_decode(&mad_frame_, &mad_stream_)) {
					if(MAD_RECOVERABLE(mad_stream_.error)) {
						continue;
					} else {
						if(mad_stream_.error == MAD_ERROR_BUFLEN) {
							continue;
						} else {
							status = false;
							break;
						}
					}
				}

				if(!info) {
					set_sample_rate(mad_frame_.header.samplerate);
					utils::format("Sample Rate: %d\n") % mad_frame_.header.samplerate;
					info = true;
				}

				frame_count++;
				mad_timer_add(&mad_timer_, mad_frame_.header.duration);

				if(subband_filter_enable_) {
					apply_filter_(mad_frame_);
				}

				mad_synth_frame(&mad_synth_, &mad_frame_);

				for(uint32_t i = 0; i < mad_synth_.pcm.length; ++i) {
					while((out.at_fifo().size() - out.at_fifo().length()) < 8) {
					}
					sound::wave_t t;
					if(MAD_NCHANNELS(&mad_frame_.header) == 1) {
						t.l_ch = t.r_ch = MadFixedToSshort(mad_synth_.pcm.samples[0][i]);
					} else {
						t.l_ch = MadFixedToSshort(mad_synth_.pcm.samples[0][i]);
						t.r_ch = MadFixedToSshort(mad_synth_.pcm.samples[1][i]);
					}
					out.at_fifo().put(t);
					++pos;
				}

				{
					uint32_t s = pos / mad_frame_.header.samplerate;
					if(s != time_) {
						if(update_task_) {
							update_task_(s);
						}
						time_ = s;
					}
				}
			}

			mad_synth_finish(&mad_synth_);
			mad_frame_finish(&mad_frame_);
			mad_stream_finish(&mad_stream_);

			return status;
		}
	};
}
