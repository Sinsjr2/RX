#pragma once
//=====================================================================//
/*!	@file
	@brief	RX600 グループ A/D 制御
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2017, 2018 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RX/blob/master/LICENSE
*/
//=====================================================================//
#include "common/renesas.hpp"
#include "common/intr_utils.hpp"
#include "common/vect.h"

/// F_PCLKD は変換パラメーター計算で必要で、設定が無いとエラーにします。
#ifndef F_PCLKD
#  error "adc_in.hpp requires F_PCLKD to be defined"
#endif

namespace device {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief  A/D 制御クラス
		@param[in]	ADCU	A/D チャネル・ユニット
		@param[in]	TASK	割り込みタスク・ファンクタ
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <class ADCU, class TASK = utils::null_task>
	class adc_in {
	public:

		typedef ADCU value_type;

	private:
		static TASK task_;

		INTERRUPT_FUNC static void adi_task_()
		{
			task_();
		}

		uint8_t	level_;

		static inline void sleep_() { asm("nop"); }

	public:
		//-----------------------------------------------------------------//
		/*!
			@brief	コンストラクター
		 */
		//-----------------------------------------------------------------//
		adc_in() noexcept : level_(0) { }


		//-----------------------------------------------------------------//
		/*!
			@brief	スタート
			@param[in]	ana		アナログ入力チャンネル型
			@param[in]	level	割り込みレベル、０の場合はポーリング
			@return 成功なら「true」
		 */
		//-----------------------------------------------------------------//
		bool start(typename ADCU::analog ana, uint8_t level = 0) noexcept
		{
			level_ = level;

			// 基本変換時間（１マイクロ秒）＋マージン
			uint32_t n = F_PCLKD / 1000000 + 10;
			if(n > 255) return false;

			power_mgr::turn(ADCU::get_peripheral());
			ADCU::enable(ana);
			ADCU::ADANSA.set(ana);
			ADCU::ADSSTR.set(ana, n);

			return true;
		}


		//-----------------------------------------------------------------//
		/*!
			@brief	スキャン開始
		 */
		//-----------------------------------------------------------------//
		void scan() noexcept
		{
			if(level_) {
///				set_interrupt_task(adi_task_, static_cast<uint32_t>(ADCU::get_vec()));
///				icu_mgr::set_level(ADCU::get_peripheral(), level_);
				ADCU::ADCSR = ADCU::ADCSR.ADST.b() | ADCU::ADCSR.ADIE.b();
			} else {
				ADCU::ADCSR = ADCU::ADCSR.ADST.b();
			}
		}


		//-----------------------------------------------------------------//
		/*!
			@brief	変換状態の取得
			@return 変換中なら「true」
		 */
		//-----------------------------------------------------------------//
		bool get_state() const noexcept {
			return ADCU::ADCSR.ADST();
		}


		//-----------------------------------------------------------------//
		/*!
			@brief	読み込み同期
		 */
		//-----------------------------------------------------------------//
		void sync() const noexcept {
			while(ADCU::ADCSR.ADST() != 0) sleep_();
		}


		//-----------------------------------------------------------------//
		/*!
			@brief	A/D 変換結果を取得
			@param[in]	an	変換チャネル
			@return 変換結果（上位１０ビットが有効な値）
		 */
		//-----------------------------------------------------------------//
		uint16_t get(typename ADCU::analog an) const noexcept {
			return ADCU::ADDR(an);
		}
	};

	template <class ADCU, class TASK> TASK adc_in<ADCU, TASK>::task_;
}
