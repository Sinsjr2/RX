#pragma once
//=====================================================================//
/*!	@file
	@brief	オーディオ・コーデック・クラス
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2018, 2019 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RX/blob/master/LICENSE
*/
//=====================================================================//
#include "common/renesas.hpp"
#include "common/tpu_io.hpp"
#include "common/fixed_fifo.hpp"
#include "common/dir_list.hpp"
#include "sound/sound_out.hpp"
#include "sound/mp3_in.hpp"
#include "sound/wav_in.hpp"
#include "graphics/scaling.hpp"
#include "graphics/img_in.hpp"

namespace audio {

	typedef utils::sound_out<8192, 1024> SOUND_OUT;

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief  オーディオ・コーデック・クラス
		@param[in]	RDR	グラフィックス描画クラス
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template<class RDR>
	class codec {
	public:
		typedef sound::af_play::UPDATE_TASK UPDATE_TASK;
		typedef sound::af_play::CTRL CTRL_TASK;
		typedef img::scaling<RDR> SCALING;
		typedef img::img_in<SCALING> IMG_IN;

	private:
		RDR&		rdr_;
		typedef utils::dir_list DLIST;
		DLIST		dlist_;

		SCALING		scaling_;

		static volatile uint32_t	wpos_;

		/// DMAC 終了割り込み
		class dmac_term_task {
		public:
			void operator() () {
				device::DMAC0::DMCNT.DTE = 1;  // DMA を再スタート
				wpos_ = 0;
			}
		};

		typedef device::dmac_mgr<device::DMAC0, dmac_term_task> DMAC_MGR;
		DMAC_MGR	dmac_mgr_;

		uint32_t get_wave_pos_() { return (dmac_mgr_.get_count() & 0x3ff) ^ 0x3ff; }

		typedef device::R12DA DAC;
		typedef device::dac_out<DAC> DAC_OUT;
		DAC_OUT		dac_out_;

		static SOUND_OUT	sound_out_;

		class tpu_task {
		public:
			void operator() () {
				uint32_t tmp = wpos_;
				++wpos_;
				if((tmp ^ wpos_) & 64) {
					sound_out_.service(64);
				}
			}
		};

		typedef device::tpu_io<device::TPU0, tpu_task> TPU0;
		TPU0		tpu0_;

		typedef sound::mp3_in MP3_IN;
		MP3_IN		mp3_in_;
		typedef sound::wav_in WAV_IN;
		WAV_IN		wav_in_;

		UPDATE_TASK	update_task_;
		CTRL_TASK	ctrl_task_;

		IMG_IN		img_in_;

		int16_t render_text_(int16_t x, int16_t y, const char* text)
		{
			rdr_.swap_color();
			auto xx = rdr_.draw_text(vtx::spos(x, y), text);
			rdr_.swap_color();
			rdr_.draw_text(vtx::spos(x + 1, y + 1), text);
			return xx;
		}

		void sound_tag_task_(utils::file_io& fin, const sound::tag_t& tag)
		{
			rdr_.clear(graphics::def_color::Black);
			rdr_.sync_frame(false);

			scaling_.set_offset(vtx::spos(480 - 272, 0));
			if(tag.get_apic().len_ > 0) {
				if(!img_in_.select_decoder(tag.get_apic().ext_)) {
					scaling_.set_scale();
					img_in_.load("/NoImage.jpg");
				} else {
					auto pos = fin.tell();
					fin.seek(utils::file_io::SEEK::SET, tag.get_apic().ofs_);
					img::img_info ifo;
					if(!img_in_.info(fin, ifo)) {
						scaling_.set_scale();
						img_in_.load("/NoImage.jpg");
						rdr_.swap_color();
						rdr_.draw_text(vtx::spos(480 - 272, 0), "image decode error.");
						rdr_.swap_color();
					} else {
						auto n = std::max(ifo.width, ifo.height);
						scaling_.set_scale(272, n);
						img_in_.load(fin);
					}
					fin.seek(utils::file_io::SEEK::SET, pos);
				}
			} else {
				scaling_.set_scale();
				img_in_.load("/NoImage.jpg");
			}

			utils::format("Album:  '%s'\n") % tag.get_album().c_str();
			render_text_(0, 0 * 20, tag.get_album().c_str());
			utils::format("Title:  '%s'\n") % tag.get_title().c_str();
			render_text_(0, 1 * 20, tag.get_title().c_str());
			utils::format("Artist: '%s'\n") % tag.get_artist().c_str();
			render_text_(0, 2 * 20, tag.get_artist().c_str());
			utils::format("Year:    %s\n") % tag.get_year().c_str();
			render_text_(0, 3 * 20, tag.get_year().c_str());
			utils::format("Disc:    %s\n") % tag.get_disc().c_str();
			auto x = render_text_(0, 4 * 20, tag.get_disc().c_str());
			if(x > 0) x += 8;
			utils::format("Track:   %s\n") % tag.get_track().c_str();
			render_text_(x, 4 * 20, tag.get_track().c_str());
			rdr_.sync_frame(false);
		}


		void sound_update_task_(uint32_t t)
		{
			uint16_t sec = t % 60;
			uint16_t min = (t / 60) % 60;
			uint16_t hor = (t / 3600) % 24;
			char tmp[16];
			utils::sformat("%02d:%02d:%02d", tmp, sizeof(tmp)) % hor % min % sec;
			rdr_.set_fore_color(graphics::def_color::Black);
			rdr_.fill_box(vtx::srect(0, 5 * 20, 8 * 8, 16));
			rdr_.set_fore_color(graphics::def_color::White);
			rdr_.draw_text(vtx::spos(0, 5 * 20), tmp);
			rdr_.sync_frame(false);
		}


		bool play_mp3_(const char* fname)
		{
			utils::file_io fin;
			if(!fin.open(fname, "rb")) {
				return false;
			}
///			mp3_in_.set_ctrl_task([&]() { return ctrl_task_(); } );
//			mp3_in_.set_ctrl_task(ctrl_task_);
			mp3_in_.set_tag_task([&](utils::file_io& fin, const sound::tag_t& tag) {
				sound_tag_task_(fin, tag); } );
			mp3_in_.set_update_task([&](uint32_t t) { sound_update_task_(t); } );
			bool ret = mp3_in_.decode(fin, sound_out_);
			fin.close();
			return ret;
		}


		bool play_wav_(const char* fname)
		{
			utils::file_io fin;
			if(!fin.open(fname, "rb")) {
				return false;
			}
///			wav_in_.set_ctrl_task([&]() { return ctrl_task_(); } );
//			wav_in_.set_ctrl_task(ctrl_task_);
			wav_in_.set_tag_task([&](utils::file_io& fin, const sound::tag_t& tag) {
				sound_tag_task_(fin, tag); } );
			wav_in_.set_update_task([&](uint32_t t) { sound_update_task_(t); } );
			bool ret = wav_in_.decode(fin, sound_out_);
			fin.close();
			return ret;
		}


		struct loop_t {
			const char*	start;
			bool	enable;
		};
		loop_t	loop_t_;


		void play_loop_func_(const char* name, const FILINFO* fi, bool dir, void* option)
		{
			loop_t* t = static_cast<loop_t*>(option);
			if(t->enable) {
				const char* p = strrchr(t->start, '/');
				if(p != nullptr) ++p;
				else p = t->start;
				if(strcmp(name, p) != 0) {
					return;
				} else {
					t->enable = false;
				}
			}
			if(dir) {
				play_loop_(name, "");
			} else {
				play_file(name);
			}
		}


		void play_loop_(const char* root, const char* start)
		{
			loop_t_.start = start;
			if(strlen(start) != 0) {
				loop_t_.enable = true;
			} else {
				loop_t_.enable = false;
			}
			dlist_.start(root);
		}

	public:
		//-----------------------------------------------------------------//
		/*!
			@brief  コンストラクタ
			@param[in]	rdr		描画コンテキスト
		*/
		//-----------------------------------------------------------------//
		codec(RDR& rdr) noexcept :
			rdr_(rdr), dlist_(), scaling_(rdr), img_in_(scaling_)
		{ }


		//-----------------------------------------------------------------//
		/*!
			@brief	描画スケーリングの参照
			@return 描画スケーリング
		*/
		//-----------------------------------------------------------------//
		SCALING& at_scaling() noexcept { return scaling_; }


		//-----------------------------------------------------------------//
		/*!
			@brief	画像デコーダーの参照
			@return 画像デコーダー
		*/
		//-----------------------------------------------------------------//
		IMG_IN& at_img_in() noexcept { return img_in_; }


		//-----------------------------------------------------------------//
		/*!
			@brief	演奏アップデートの設定
			@param[in]	task	演奏アップデート
		*/
		//-----------------------------------------------------------------//
		void set_update_task(UPDATE_TASK task) noexcept {
			update_task_ = task;
		}


		//-----------------------------------------------------------------//
		/*!
			@brief  制御タスクの設定
			@param[in]	task	制御タスク
		*/
		//-----------------------------------------------------------------//
		void set_ctrl_task(CTRL_TASK task) noexcept {
			ctrl_task_ = task;
		}


		//-----------------------------------------------------------------//
		/*!
			@brief	サンプリング周期の設定
			@param[in]	freq	サンプリング周期 [Hz]
		*/
		//-----------------------------------------------------------------//
		void set_sample_rate(uint32_t freq) noexcept
		{
			uint8_t intr_level = 5;
			if(!tpu0_.start(freq, intr_level)) {
				utils::format("TPU0 start error...\n");
			}
		}





#if 0
		void dac_write(uint8_t ch, uint16_t val)
		{
			sound::wave_t t;
			val ^= 0x80;
			t.l_ch = (val << 8) | ((val & 0x7f) << 1);
			t.r_ch = (val << 8) | ((val & 0x7f) << 1);
			sound_out_.at_fifo().put(t);
		}
#endif


		//-----------------------------------------------------------------//
		/*!
			@brief  開始 @n
					※D/A変換の準備と、DMA の初期化など
		*/
		//-----------------------------------------------------------------//
		void start() noexcept
		{
			{  // 内臓１２ビット D/A の設定
				bool amp_ena = true;
				dac_out_.start(DAC_OUT::output::CH0_CH1, amp_ena);
				dac_out_.out0(0x8000);
				dac_out_.out1(0x8000);
			}

			// 波形メモリーの無音状態初期化
			sound_out_.mute();

			{  // サンプリング・タイマー設定
				set_sample_rate(44100);
			}

			{  // DMAC マネージャー開始
				uint8_t intr_level = 4;
				bool cpu_intr = true;
				auto ret = dmac_mgr_.start(tpu0_.get_intr_vec(), DMAC_MGR::trans_type::SP_DN_32,
					reinterpret_cast<uint32_t>(sound_out_.get_wave()), DAC::DADR0.address(),
					sound_out_.size(), intr_level, cpu_intr);
				if(!ret) {
					utils::format("DMAC Not start...\n");
				}
			}
		}


		//-----------------------------------------------------------------//
		/*!
			@brief  サービス @n
					周期的に呼び出す。@n
					※ワイルドカード指定で、開始した場合に、ディレクトリー @n
					を巡る処理を行う。
		*/
		//-----------------------------------------------------------------//
		void service() noexcept
		{
			dlist_.service(1,
				[&](const char* name, const FILINFO* fi, bool dir, void* option) {
					play_loop_func_(name, fi, dir, option);
				},
			true, &loop_t_);
		}


		//-----------------------------------------------------------------//
		/*!
			@brief  ファイル再生（ループ）
			@param[in]	root	ルート
			@param[in]	start	開始ファイル名
		*/
		//-----------------------------------------------------------------//
		void play_loop(const char* root, const char* start) noexcept
		{
			play_loop_(root, start);
		}


		//-----------------------------------------------------------------//
		/*!
			@brief  ファイル再生
			@param[in]	name	ファイル名
			@return 成功なら「true」
		*/
		//-----------------------------------------------------------------//
		bool play_file(const char* name) noexcept
		{
			const char* ext = strrchr(name, '.');
			if(ext == nullptr) return false;

			bool ret = false;
			if(strcmp(ext, ".mp3") == 0) {
				ret = play_mp3_(name);
			} else if(strcmp(ext, ".wav") == 0) {
				ret = play_wav_(name);
			}
			return ret;
		}


		//-----------------------------------------------------------------//
		/*!
			@brief  再生を停止
		*/
		//-----------------------------------------------------------------//
		void stop() noexcept {
			dlist_.stop();
		}
	};

	template<class RENDER>
	volatile uint32_t codec<RENDER>::wpos_;

	template<class RENDER>
	SOUND_OUT codec<RENDER>::sound_out_;

//	template<class RENDER>
//	volatile uint32_t codec<RENDER>::cycle_count_;
}

