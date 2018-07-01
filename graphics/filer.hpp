#pragma once
//=====================================================================//
/*!	@file
	@brief	ファイル操作ユーティリティー
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2018 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RX/blob/master/LICENSE
*/
//=====================================================================//
#include "common/sdc_man.hpp"
#include "common/fixed_stack.hpp"

namespace graphics {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief	ファイラー制御型
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	enum class filer_ctrl {
		OPEN,		///< ファイラーを起動
		UP,			///< スクロール上
		DOWN,		///< スクロール下
		BACK,		///< ディレクトリーを戻る
		SELECT,		///< 選択
	};


	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief	制御データ構築
		@param[in]	pos		ファイラー制御型
		@param[in]	ctrl	制御データ（参照）
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	static inline void set(filer_ctrl pos, uint32_t& ctrl) noexcept
	{
		ctrl |= 1 << static_cast<uint8_t>(pos);
	}


	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief	ファイラー
		@param[in]	SDC	sdc_man クラス型
		@param[in]	RDR	render クラス型
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class SDC, class RDR>
	class filer {

		static const int16_t SPC = 2;                           ///< 文字間隙間
		static const int16_t FLN = RDR::font_height + SPC;      ///< 行幅
		static const int16_t SCN = (RDR::height - SPC) / FLN;   ///< 行数

		SDC&	sdc_;
		RDR&	rdr_;

		uint32_t	ctrl_;
		bool		open_;

		struct rdr_st {
			RDR&		rdr_;
			int16_t		vofs_;
			int16_t		vpos_;
			int16_t		hmax_;
			int16_t		sel_pos_;
			uint16_t	num_;

			rdr_st(RDR& rdr) noexcept : rdr_(rdr), vofs_(0), vpos_(0), hmax_(0), sel_pos_(0),
				num_(0)
			{ }
		};
		rdr_st	rdr_st_;

		struct pos_t {
			int16_t		vofs_;
			int16_t		sel_pos_;
			pos_t(int16_t vofs = 0, int16_t sel_pos = 0) noexcept :
				vofs_(vofs), sel_pos_(sel_pos) { }
		};
		typedef utils::fixed_stack<pos_t, 16> POS_STACK;
		POS_STACK		pos_stack_;


		static uint32_t ctrl_mask_(filer_ctrl ctrl) noexcept
		{
			return 1 << static_cast<uint8_t>(ctrl);
		}


		static void dir_draw_func_(const char* name, const FILINFO* fi, bool dir, void* opt)
			noexcept
		{
			rdr_st& t = *static_cast<rdr_st*>(opt);
			if(t.vpos_ >= 0 && t.vpos_ < RDR::height) {
				t.rdr_.set_fore_color(RDR::COLOR::White);
				t.rdr_.fill(SPC, t.vpos_, RDR::width - SPC * 2, RDR::font_height, 0x0000);
				if(dir) t.rdr_.draw_font(SPC, t.vpos_, '/');
			}
			if(dir) {
				t.rdr_.set_fore_color(RDR::COLOR::Blue);
			} else {
				t.rdr_.set_fore_color(RDR::COLOR::White);
			}
			auto w = t.rdr_.draw_text(SPC + 8, t.vpos_, name);
			if(t.hmax_ < w) t.hmax_ = w;

			t.vpos_ += FLN;
			++t.num_;
		}


		void start_dir_draw_() noexcept
		{
			uint32_t num = (RDR::height - 2) / (RDR::font_height + 2);
			rdr_st_.vpos_ = rdr_st_.vofs_ + 2;
			rdr_st_.num_ = 0;
			sdc_.start_dir_list("", dir_draw_func_, true, &rdr_st_);
		}


		void draw_sel_frame_(int16_t pos, uint16_t c)
		{
			int16_t h = RDR::font_height + 2;
			int16_t y = pos * h;
			rdr_.frame(0, y, rdr_st_.hmax_ + 3, h + 1, c);
		}


		void scan_dir_(bool back)
		{
			if(back) {
				if(pos_stack_.empty()) {
					rdr_st_.vofs_ = 0;
					rdr_st_.sel_pos_ = 0;
				} else {
					const auto& t = pos_stack_.pull();
					rdr_st_.vofs_ = t.vofs_;
					rdr_st_.sel_pos_ = t.sel_pos_;
				}
			} else {
				rdr_st_.vofs_ = 0;
				rdr_st_.sel_pos_ = 0;
			}
			start_dir_draw_();
		}

	public:
		//-----------------------------------------------------------------//
		/*!
			@brief	コンストラクター
		*/
		//-----------------------------------------------------------------//
		filer(SDC& sdc, RDR& rdr) noexcept : sdc_(sdc), rdr_(rdr),
			ctrl_(0), open_(false),
			rdr_st_(rdr_)
		{ }


		//-----------------------------------------------------------------//
		/*!
			@brief	アップデート（毎フレーム呼ぶ）
			@param[in]	ctrl	ファイラー制御
			@param[in]	dst		ファイル・パスを受け取り先
			@param[in]	dstlen	ファイル・パスを受け取りサイズ
			@return ファイルが選択された場合「true」
		*/
		//-----------------------------------------------------------------//
		bool update(uint32_t ctrl, char* dst, uint32_t dstlen) noexcept
		{
			uint32_t ptrg = ~ctrl_ &  ctrl;
			uint32_t ntrg =  ctrl_ & ~ctrl;
			ctrl_ = ctrl;

			if(!sdc_.get_mount()) {
				open_ = false;
				pos_stack_.clear();
				rdr_.clear(RDR::COLOR::Black);
				return false;
			}

			if(ptrg & ctrl_mask_(filer_ctrl::OPEN)) {
				open_ = !open_;
				rdr_.clear(RDR::COLOR::Black);
				if(open_) {
					scan_dir_(false);
				}
			}

			if(!open_) return false;

			{
				uint32_t n;
				bool f = sdc_.probe_dir_list(n);
				if(f) return false;
				if(rdr_st_.num_ < static_cast<int16_t>(n)) return false;
			}

			// 選択フレームの描画
			draw_sel_frame_(rdr_st_.sel_pos_, 0xffff);
			int16_t pos = rdr_st_.sel_pos_;
			if(ptrg & ctrl_mask_(filer_ctrl::UP)) {
				pos--;
			}
			if(ptrg & ctrl_mask_(filer_ctrl::DOWN)) {
				++pos;
			}
			int16_t vofs = rdr_st_.vofs_;
			int16_t scn = SCN;
			if(rdr_st_.num_ < scn) scn = rdr_st_.num_; 
			if(pos < 0) {
				pos = 0;
				vofs += FLN;
			} else if(pos >= scn) {
				pos = scn - 1;
				vofs -= FLN;
			}
			int16_t lim = 0;
			if(rdr_st_.num_ > scn) {
				lim = -(rdr_st_.num_ - scn) * FLN;
			}
			if(vofs > 0) {
				vofs = 0;
			} else if(vofs < lim) {
				vofs = lim;
			}
			if(vofs != rdr_st_.vofs_) {
				rdr_st_.vofs_ = vofs;
				start_dir_draw_();
			}
			
			if(pos != rdr_st_.sel_pos_) {
				draw_sel_frame_(rdr_st_.sel_pos_, 0x0000);
				rdr_st_.sel_pos_ = pos;
			}

			if(ptrg & ctrl_mask_(filer_ctrl::SELECT)) {
				uint32_t n = rdr_st_.sel_pos_ - rdr_st_.vofs_ / FLN;
				if(!sdc_.get_dir_path(n, dst, dstlen)) {
					return false;
				}
				uint32_t l = strlen(dst);
				if(dst[l - 1] == '/') {
					pos_stack_.push(pos_t(rdr_st_.vofs_, rdr_st_.sel_pos_));
					dst[l - 1] = 0;
					sdc_.cd(dst);
					rdr_.clear(RDR::COLOR::Black);
					scan_dir_(false);
				} else {
					rdr_.clear(RDR::COLOR::Black);
					open_ = false;
					return true;
				}
			}

			if(ptrg & ctrl_mask_(filer_ctrl::BACK)) {
				if(!pos_stack_.empty()) {
					sdc_.cd("..");
					rdr_.clear(RDR::COLOR::Black);
					scan_dir_(true);
				}
			}

			return false;
		}
	};
}