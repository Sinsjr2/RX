#pragma once
//=====================================================================//
/*!	@file
	@brief	RX600 グループ・16 ビットタイマパルスユニット定義
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2017 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RX/blob/master/LICENSE
*/
//=====================================================================//
#include "common/device.hpp"

namespace device {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief  16 ビットタイマパルスユニット（TPUa）
		@param[in]	base	ベースアドレス
		@param[in]	per		ペリフェラル型
		@param[in]	intra	割り込み要因Ａ
		@param[in]	intrb	割り込み要因Ｂ
		@param[in]	intrc	割り込み要因Ｃ
		@param[in]	intrd	割り込み要因Ｄ
		@param[in]	intru	割り込み要因Ｕ
		@param[in]	intrv	割り込み要因Ｖ
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <uint32_t base, peripheral per,
		uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv>
	struct tpux_t {

		//-----------------------------------------------------------------//
		/*!
			@brief  タイマコントロールレジスタ（TCR）
		*/
		//-----------------------------------------------------------------//
		struct tcr_t : public rw8_t<base + 0x00> {
			typedef rw8_t<base + 0x00> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 3> TPSC;
			bits_rw_t<io_, bitpos::B3, 2> CKEG;
			bits_rw_t<io_, bitpos::B5, 3> CCLR;
		};
		static tcr_t TCR;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマモードレジスタ（TMDR）
		*/
		//-----------------------------------------------------------------//
		struct tmdr_t : public rw8_t<base + 0x01> {
			typedef rw8_t<base + 0x01> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 4>  MD;
			bit_rw_t <io_, bitpos::B4>     BFA;
			bit_rw_t <io_, bitpos::B5>     BFB;
			bit_rw_t <io_, bitpos::B6>     ICSELB;
			bit_rw_t <io_, bitpos::B7>     ICSELD;
		};
		static tmdr_t TMDR;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマ I/O コントロールレジスタ（TIORH）
		*/
		//-----------------------------------------------------------------//
		struct tiorh_t : public rw8_t<base + 0x02> {
			typedef rw8_t<base + 0x02> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 4> IOA;
			bits_rw_t<io_, bitpos::B4, 4> IOB;
		};
		static tiorh_t TIORH;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマ I/O コントロールレジスタ（TIORL）
		*/
		//-----------------------------------------------------------------//
		struct tiorl_t : public rw8_t<base + 0x03> {
			typedef rw8_t<base + 0x03> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 4> IOC;
			bits_rw_t<io_, bitpos::B4, 4> IOD;
		};
		static tiorl_t TIORL;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマ割り込み許可レジスタ（TIER）
		*/
		//-----------------------------------------------------------------//
		struct tier_t : public rw8_t<base + 0x04> {
			typedef rw8_t<base + 0x04> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  TGIEA;
			bit_rw_t<io_, bitpos::B1>  TGIEB;
			bit_rw_t<io_, bitpos::B2>  TGIEC;
			bit_rw_t<io_, bitpos::B3>  TGIED;
			bit_rw_t<io_, bitpos::B4>  TCIEV;
			bit_rw_t<io_, bitpos::B5>  TCIEU;

			bit_rw_t<io_, bitpos::B7>  TTGE;
		};
		static tier_t TIER;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマステータスレジスタ（TSR）
		*/
		//-----------------------------------------------------------------//
		struct tsr_t : public rw8_t<base + 0x05> {
			typedef rw8_t<base + 0x05> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  TGFA;
			bit_rw_t<io_, bitpos::B1>  TGFB;
			bit_rw_t<io_, bitpos::B2>  TGFC;
			bit_rw_t<io_, bitpos::B3>  TGFD;
			bit_rw_t<io_, bitpos::B4>  TCFV;
			bit_rw_t<io_, bitpos::B5>  TCFU;

			bit_rw_t<io_, bitpos::B7>  TCFD;
		};
		static tsr_t TSR;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマカウンタ（TCNT）
		*/
		//-----------------------------------------------------------------//
		typedef rw16_t<base + 0x06> tcnt_t;
		static tcnt_t TCNT;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマジェネラルレジスタ A（TGRA）
		*/
		//-----------------------------------------------------------------//
		typedef rw16_t<base + 0x08> tgra_t;
		static tgra_t TGRA;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマジェネラルレジスタ B（TGRB）
		*/
		//-----------------------------------------------------------------//
		typedef rw16_t<base + 0x0A> tgrb_t;
		static tgrb_t TGRB;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマジェネラルレジスタ C（TGRC）
		*/
		//-----------------------------------------------------------------//
		typedef rw16_t<base + 0x0C> tgrc_t;
		static tgrc_t TGRC;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマジェネラルレジスタ D（TGRD）
		*/
		//-----------------------------------------------------------------//
		typedef rw16_t<base + 0x0E> tgrd_t;
		static tgrd_t TGRD;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマスタートレジスタ（TSTR）
		*/
		//-----------------------------------------------------------------//
		struct tstr_t : public rw8_t<0x00088100> {
			typedef rw8_t<0x00088100> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t <io_, bitpos::B0>  CST0;
			bit_rw_t <io_, bitpos::B1>  CST1;
			bit_rw_t <io_, bitpos::B2>  CST2;
			bit_rw_t <io_, bitpos::B3>  CST3;
			bit_rw_t <io_, bitpos::B4>  CST4;
			bit_rw_t <io_, bitpos::B5>  CST5;
		};
		static tstr_t TSTR;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマシンクロレジスタ（TSYR）
		*/
		//-----------------------------------------------------------------//
		struct tsyr_t : public rw8_t<0x00088101> {
			typedef rw8_t<0x00088101> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t <io_, bitpos::B0>  SYNC0;
			bit_rw_t <io_, bitpos::B1>  SYNC1;
			bit_rw_t <io_, bitpos::B2>  SYNC2;
			bit_rw_t <io_, bitpos::B3>  SYNC3;
			bit_rw_t <io_, bitpos::B4>  SYNC4;
			bit_rw_t <io_, bitpos::B5>  SYNC5;
		};
		static tsyr_t TSYR;


		//-----------------------------------------------------------------//
		/*!
			@brief  ノイズフィルタコントロールレジスタ（NFCR）
		*/
		//-----------------------------------------------------------------//
		struct nfcr_t : public rw8_t<base + 0x08> {
			typedef rw8_t<base + 0x08> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t <io_, bitpos::B0>     NFAEN;
			bit_rw_t <io_, bitpos::B1>     NFBEN;
			bit_rw_t <io_, bitpos::B2>     NFCEN;
			bit_rw_t <io_, bitpos::B3>     NFDEN;

			bits_rw_t<io_, bitpos::B4, 2>  NFCS;
		};
		static nfcr_t NFCR;


		//-----------------------------------------------------------------//
		/*!
			@brief  タイマスタートレジスタ（TSTR）のエイリアス
			@param[in]	f	動作停止にする場合「false」
		*/
		//-----------------------------------------------------------------//
		static void enable(bool f = true)
		{
			if(f) {
				TSTR |=  (1 << (static_cast<uint8_t>(per) - static_cast<uint8_t>(peripheral::TPU0)));
			} else {
				TSTR &= ~(1 << (static_cast<uint8_t>(per) - static_cast<uint8_t>(peripheral::TPU0)));
			}
		}


		//-----------------------------------------------------------------//
		/*!
			@brief	タイマシンクロレジスタ（TSYR）のエイリアス
			@param[in]	f	同期解除にする場合「false」
		*/
		//-----------------------------------------------------------------//
		static void sync(bool f = true)
		{
			if(f) {
				TSYR |=  (1 << (static_cast<uint8_t>(per) - static_cast<uint8_t>(peripheral::TPU0)));
			} else {
				TSYR &= ~(1 << (static_cast<uint8_t>(per) - static_cast<uint8_t>(peripheral::TPU0)));
			}
		}


		//-----------------------------------------------------------------//
		/*!
			@brief  割り込み要因番号を返すＡ
			@return 割り込み要因番号Ａ
		*/
		//-----------------------------------------------------------------//
		static uint8_t get_TGIA() { return intra; }


		//-----------------------------------------------------------------//
		/*!
			@brief  割り込み要因番号を返すＢ
			@return 割り込み要因番号Ｂ
		*/
		//-----------------------------------------------------------------//
		static uint8_t get_TGIB() { return intrb; }


		//-----------------------------------------------------------------//
		/*!
			@brief  割り込み要因番号を返すＣ
			@return 割り込み要因番号Ｃ
		*/
		//-----------------------------------------------------------------//
		static uint8_t get_TGIC() { return intrc; }


		//-----------------------------------------------------------------//
		/*!
			@brief  割り込み要因番号を返すＤ
			@return 割り込み要因番号Ｄ
		*/
		//-----------------------------------------------------------------//
		static uint8_t get_TGID() { return intrd; }


		//-----------------------------------------------------------------//
		/*!
			@brief  割り込み要因番号を返すＵ
			@return 割り込み要因番号Ｕ
		*/
		//-----------------------------------------------------------------//
		static uint8_t get_TGIU() { return intru; }


		//-----------------------------------------------------------------//
		/*!
			@brief  割り込み要因番号を返すＶ
			@return 割り込み要因番号Ｖ
		*/
		//-----------------------------------------------------------------//
		static uint8_t get_TGIV() { return intrv; }


		//-----------------------------------------------------------------//
		/*!
			@brief  ペリフェラル型を返す
			@return ペリフェラル型
		*/
		//-----------------------------------------------------------------//
		static peripheral get_peripheral() { return per; }
	};

	typedef tpux_t<0x00088110, peripheral::TPU0, 15, 16, 17, 18,  0, 19> TPU0;
	typedef tpux_t<0x00088120, peripheral::TPU1, 20, 21,  0,  0, 22, 23> TPU1;
	typedef tpux_t<0x00088130, peripheral::TPU2, 24, 25,  0,  0, 26, 27> TPU2;
	typedef tpux_t<0x00088140, peripheral::TPU3, 28, 29, 30, 31,  0, 32> TPU3;
	typedef tpux_t<0x00088150, peripheral::TPU4, 33, 34,  0,  0, 35, 36> TPU4;
	typedef tpux_t<0x00088160, peripheral::TPU5, 37, 38,  0,  0, 39, 40> TPU5;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tcr_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TCR;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tmdr_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TMDR;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tiorh_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TIORH;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tiorl_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TIORL;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tier_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TIER;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tsr_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TSR;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tcnt_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TCNT;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tgra_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TGRA;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tgrb_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TGRB;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tgrc_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TGRC;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tgrd_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TGRD;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tstr_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TSTR;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::tsyr_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::TSYR;
	template <uint32_t base, peripheral per, uint8_t intra, uint8_t intrb, uint8_t intrc, uint8_t intrd, uint8_t intru, uint8_t intrv> typename tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::nfcr_t tpux_t<base, per, intra, intrb, intrc, intrd, intru, intrv>::NFCR;
}
