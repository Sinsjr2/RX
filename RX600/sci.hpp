#pragma once
//=====================================================================//
/*!	@file
	@brief	RX600 グループ・SCI 定義 SCI[jgh]
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2015, 2018 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RX/blob/master/LICENSE
*/
//=====================================================================//
#include "common/device.hpp"

namespace device {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief  SCI 定義基底クラス
		@param[in]	base	ベース・アドレス
		@param[in]	per		ペリフェラル型
		@param[in]	txv		送信ベクター
		@param[in]	rxv		受信ベクター
		@param[in]	INT		送信終了割り込みベクター型
		@param[in]	tev		送信終了割り込みベクター
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev>
	struct sci_t {

		//-----------------------------------------------------------------//
		/*!
			@brief  レシーブデータレジスタ (RDR)
		*/
		//-----------------------------------------------------------------//
		typedef ro8_t<base + 0x05> rdr_t;
		static rdr_t RDR;


		//-----------------------------------------------------------------//
		/*!
			@brief  レシーブデータレジスタ H 、 L 、 HL (RDRH 、 RDRL 、 RDRHL)
		*/
		//-----------------------------------------------------------------//
		typedef ro8_t<base + 0x10> rdrh_t;
		static rdrh_t RDRH;
		typedef ro8_t<base + 0x11> rdrl_t;
		static rdrl_t RDRL;
		typedef ro16_t<base + 0x10> rdrhl_t;
		static rdrhl_t RDRHL;


		//-----------------------------------------------------------------//
		/*!
			@brief  シリアルモードレジスタ (SMR)
		*/
		//-----------------------------------------------------------------//
		struct smr_t : public rw8_t<base + 0x00> {
			typedef rw8_t<base + 0x00> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 2> CKS;
			bit_rw_t <io_, bitpos::B2>	  MP;
			bit_rw_t <io_, bitpos::B3>	  STOP;
			bit_rw_t <io_, bitpos::B4>	  PM;
			bit_rw_t <io_, bitpos::B5>	  PE;
			bit_rw_t <io_, bitpos::B6>	  CHR;
			bit_rw_t <io_, bitpos::B7>	  CM;

			bits_rw_t<io_, bitpos::B2, 2> BCP;
			bit_rw_t <io_, bitpos::B6>	  BLK;
			bit_rw_t <io_, bitpos::B7>	  GM;
		};
		static smr_t SMR;


		//-----------------------------------------------------------------//
		/*!
			@brief  ビットレートレジスタ (BRR)
		*/
		//-----------------------------------------------------------------//
		typedef rw8_t<base + 0x01> brr_t;
		static brr_t BRR;


		//-----------------------------------------------------------------//
		/*!
			@brief	モジュレーションデューティレジスタ（MDDR）
		*/
		//-----------------------------------------------------------------//
		typedef rw8_t<base + 0x12> mddr_t;
		static mddr_t MDDR;


		//-----------------------------------------------------------------//
		/*!
			@brief  シリアルコントロールレジスタ (SCR)
		*/
		//-----------------------------------------------------------------//
		struct scr_t : public rw8_t<base + 0x02> {
			typedef rw8_t<base + 0x02> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 2> CKE;
			bit_rw_t <io_, bitpos::B2>	  TEIE;
			bit_rw_t <io_, bitpos::B3>	  MPIE;
			bit_rw_t <io_, bitpos::B4>	  RE;
			bit_rw_t <io_, bitpos::B5>	  TE;
			bit_rw_t <io_, bitpos::B6>	  RIE;
			bit_rw_t <io_, bitpos::B7>	  TIE;
		};
		static scr_t SCR;


		//-----------------------------------------------------------------//
		/*!
			@brief  トランスミットデータレジスタ (TDR)
		*/
		//-----------------------------------------------------------------//
		typedef rw8_t<base + 0x03> tdr_t;
		static tdr_t TDR;


		//-----------------------------------------------------------------//
		/*!
			@brief  シリアルステータスレジスタ (SSR)
		*/
		//-----------------------------------------------------------------//
		struct ssr_t : public rw8_t<base + 0x04> {
			typedef rw8_t<base + 0x04> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> MPBT;
			bit_rw_t<io_, bitpos::B1> MPB;
			bit_rw_t<io_, bitpos::B2> TEND;
			bit_rw_t<io_, bitpos::B3> PER;
			bit_rw_t<io_, bitpos::B4> FER;
			bit_rw_t<io_, bitpos::B5> ORER;
			bit_rw_t<io_, bitpos::B6> RDRF;
			bit_rw_t<io_, bitpos::B7> TDRE;
		};
		static ssr_t SSR;


 		//-----------------------------------------------------------------//
		/*!
			@brief  スマートカードモードレジスタ (SCMR)
		*/
		//-----------------------------------------------------------------//
		struct scmr_t : public rw8_t<base + 0x06> {
			typedef rw8_t<base + 0x06> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> SMIF;
			bit_rw_t<io_, bitpos::B2> SINV;
			bit_rw_t<io_, bitpos::B3> SDIR;
			bit_rw_t<io_, bitpos::B4> CHR1;
			bit_rw_t<io_, bitpos::B7> BCP2;
		};
		static scmr_t SCMR;


		//-----------------------------------------------------------------//
		/*!
			@brief  シリアル拡張レジスタ (SEMR)
		*/
		//-----------------------------------------------------------------//
		struct semr_t : public rw8_t<base + 0x07> {
			typedef rw8_t<base + 0x07> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> ACS0;
			bit_rw_t<io_, bitpos::B2> BRME;
			bit_rw_t<io_, bitpos::B4> ABCS;
			bit_rw_t<io_, bitpos::B5> NFEN;
			bit_rw_t<io_, bitpos::B6> BGDM;
			bit_rw_t<io_, bitpos::B7> RXDESEL;
		};
		static semr_t SEMR;


		//-----------------------------------------------------------------//
		/*!
			@brief  ノイズフィルタ設定レジスタ (SNFR)
		*/
		//-----------------------------------------------------------------//
		struct snfr_t : public rw8_t<base + 0x08> {
			typedef rw8_t<base + 0x08> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 3> NFCS;
		};
		static snfr_t SNFR;


		//-----------------------------------------------------------------//
		/*!
			@brief  I2C モードレジスタ１ (SIMR1)
		*/
		//-----------------------------------------------------------------//
		struct simr1_t : public rw8_t<base + 0x09> {
			typedef rw8_t<base + 0x09> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t <io_, bitpos::B0>    IICM;
			bits_rw_t<io_, bitpos::B3, 5> IICDL;
		};
		static simr1_t SIMR1;


		//-----------------------------------------------------------------//
		/*!
			@brief  I2C モードレジスタ２ (SIMR2)
		*/
		//-----------------------------------------------------------------//
		struct simr2_t : public rw8_t<base + 0x0A> {
			typedef rw8_t<base + 0x0A> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> IICINTM;
			bit_rw_t<io_, bitpos::B1> IICCSC;
			bit_rw_t<io_, bitpos::B5> IICACKT;
		};
		static simr2_t SIMR2;


		//-----------------------------------------------------------------//
		/*!
			@brief  I2C モードレジスタ３ (SIMR3)
		*/
		//-----------------------------------------------------------------//
		struct simr3_t : public rw8_t<base + 0x0B> {
			typedef rw8_t<base + 0x0B> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t <io_, bitpos::B0>    IICSTAREQ;
			bit_rw_t <io_, bitpos::B1>    IICRSTAREQ;
			bit_rw_t <io_, bitpos::B2>    IICSTPREQ;
			bit_rw_t <io_, bitpos::B3>    IICSTIF;
			bits_rw_t<io_, bitpos::B4, 2> IICSDAS;
			bits_rw_t<io_, bitpos::B6, 2> IICSCLS;
		};
		static simr3_t SIMR3;


		//-----------------------------------------------------------------//
		/*!
			@brief  I2C ステータスレジスタ (SISR)
		*/
		//-----------------------------------------------------------------//
		struct sisr_t : public rw8_t<base + 0x0C> {
			typedef rw8_t<base + 0x0C> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> IICACKR;
		};
		static sisr_t SISR;


		//-----------------------------------------------------------------//
		/*!
			@brief  SPI モードレジスタ (SPMR)
		*/
		//-----------------------------------------------------------------//
		struct spmr_t : public rw8_t<base + 0x0D> {
			typedef rw8_t<base + 0x0D> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> SSE;
			bit_rw_t<io_, bitpos::B1> CTSE;
			bit_rw_t<io_, bitpos::B2> MSS;
			bit_rw_t<io_, bitpos::B4> MFF;
			bit_rw_t<io_, bitpos::B6> CKPOL;
			bit_rw_t<io_, bitpos::B7> CKPH;
		};
		static spmr_t SPMR;


		//-----------------------------------------------------------------//
		/*!
			@brief  ペリフェラル型を返す
			@return ペリフェラル型
		*/
		//-----------------------------------------------------------------//
		static peripheral get_peripheral() { return per; }


		//-----------------------------------------------------------------//
		/*!
			@brief  送信割り込みベクターを返す
			@return ベクター型
		*/
		//-----------------------------------------------------------------//
		static ICU::VECTOR get_tx_vec() { return txv; }


		//-----------------------------------------------------------------//
		/*!
			@brief  受信割り込みベクターを返す
			@return ベクター型
		*/
		//-----------------------------------------------------------------//
		static ICU::VECTOR get_rx_vec() { return rxv; }


		//-----------------------------------------------------------------//
		/*!
			@brief  送信終了割り込みベクターを返す
			@return ベクター型
		*/
		//-----------------------------------------------------------------//
		static INT get_te_vec() { return tev; }
	};
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::rdr_t sci_t<base, per, txv, rxv, INT, tev>::RDR;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::rdrh_t  sci_t<base, per, txv, rxv, INT, tev>::RDRH;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::rdrl_t  sci_t<base, per, txv, rxv, INT, tev>::RDRL;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::rdrhl_t sci_t<base, per, txv, rxv, INT, tev>::RDRHL;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::smr_t   sci_t<base, per, txv, rxv, INT, tev>::SMR;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::brr_t   sci_t<base, per, txv, rxv, INT, tev>::BRR;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::mddr_t  sci_t<base, per, txv, rxv, INT, tev>::MDDR;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::scr_t   sci_t<base, per, txv, rxv, INT, tev>::SCR;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::tdr_t   sci_t<base, per, txv, rxv, INT, tev>::TDR;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::ssr_t   sci_t<base, per, txv, rxv, INT, tev>::SSR;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::scmr_t  sci_t<base, per, txv, rxv, INT, tev>::SCMR;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::semr_t  sci_t<base, per, txv, rxv, INT, tev>::SEMR;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::snfr_t  sci_t<base, per, txv, rxv, INT, tev>::SNFR;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::simr1_t sci_t<base, per, txv, rxv, INT, tev>::SIMR1;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::simr2_t sci_t<base, per, txv, rxv, INT, tev>::SIMR2;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::simr3_t sci_t<base, per, txv, rxv, INT, tev>::SIMR3;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::sisr_t  sci_t<base, per, txv, rxv, INT, tev>::SISR;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename sci_t<base, per, txv, rxv, INT, tev>::spmr_t  sci_t<base, per, txv, rxv, INT, tev>::SPMR;


	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief  SCIh 定義基底クラス
		@param[in]	base	ベース・アドレス
		@param[in]	per		ペリフェラル型
		@param[in]	txv		送信ベクター
		@param[in]	rxv		受信ベクター
		@param[in]	tev		送信終了ベクター
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev>
	struct scih_t : public sci_t<base, per, txv, rxv, INT, tev> {

		//-----------------------------------------------------------------//
		/*!
			@brief  拡張シリアルモード有効レジスタ (ESMER) @n
					※SIC12 にのみ有効なレジスタ
		*/
		//-----------------------------------------------------------------//
		struct esmer_t : public rw8_t<base + 0x20> {
			typedef rw8_t<base + 0x20> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> ESME;
		};
		static esmer_t ESMER;


		//-----------------------------------------------------------------//
		/*!
			@brief  コントロールレジスタ 0（CR0） @n
					※SIC12 にのみ有効なレジスタ
		*/
		//-----------------------------------------------------------------//
		struct cr0_t : public rw8_t<base + 0x21> {
			typedef rw8_t<base + 0x21> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_ro_t<io_, bitpos::B1> SCSF;
			bit_ro_t<io_, bitpos::B2> RXDSF;
			bit_rw_t<io_, bitpos::B3> BRME;
		};
		static cr0_t CR0;
	};
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename scih_t<base, per, txv, rxv, INT, tev>::esmer_t scih_t<base, per, txv, rxv, INT, tev>::ESMER;
	template <uint32_t base, peripheral per, ICU::VECTOR txv, ICU::VECTOR rxv, typename INT, INT tev> typename scih_t<base, per, txv, rxv, INT, tev>::cr0_t scih_t<base, per, txv, rxv, INT, tev>::CR0;


#if defined(SIG_RX24T)
	typedef sci_t<0x0008A020, peripheral::SCI1,
		ICU::VECTOR::TXI1, ICU::VECTOR::RXI1, ICU::VECTOR, ICU::VECTOR::TEI1> SCI1;
	typedef sci_t<0x0008A020, peripheral::SCI1C,
		ICU::VECTOR::TXI1, ICU::VECTOR::RXI1, ICU::VECTOR, ICU::VECTOR::TEI1> SCI1C;
	typedef sci_t<0x0008A0A0, peripheral::SCI5,
		ICU::VECTOR::TXI5, ICU::VECTOR::RXI5, ICU::VECTOR, ICU::VECTOR::TEI5> SCI5;
	typedef sci_t<0x0008A0A0, peripheral::SCI5C,
		ICU::VECTOR::TXI5, ICU::VECTOR::RXI5, ICU::VECTOR, ICU::VECTOR::TEI5> SCI5C;
	typedef sci_t<0x0008A0C0, peripheral::SCI6,
		ICU::VECTOR::TXI6, ICU::VECTOR::RXI6, ICU::VECTOR, ICU::VECTOR::TEI6> SCI6;
	typedef sci_t<0x0008A0C0, peripheral::SCI6C,
		ICU::VECTOR::TXI6, ICU::VECTOR::RXI6, ICU::VECTOR, ICU::VECTOR::TEI6> SCI6C;

#elif defined(SIG_RX64M) || defined(SIG_RX71M)
	typedef sci_t<0x0008A000, peripheral::SCI0,
		ICU::VECTOR::TXI0, ICU::VECTOR::RXI0, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI0> SCI0;
	typedef sci_t<0x0008A020, peripheral::SCI1,
		ICU::VECTOR::TXI1, ICU::VECTOR::RXI1, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI1> SCI1;
	typedef sci_t<0x0008A040, peripheral::SCI2,
		ICU::VECTOR::TXI2, ICU::VECTOR::RXI2, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI2> SCI2;
	typedef sci_t<0x0008A060, peripheral::SCI3,
		ICU::VECTOR::TXI3, ICU::VECTOR::RXI3, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI3> SCI3;
	typedef sci_t<0x0008A080, peripheral::SCI4,
		ICU::VECTOR::TXI4, ICU::VECTOR::RXI4, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI4> SCI4;
	typedef sci_t<0x0008A0A0, peripheral::SCI5,
		ICU::VECTOR::TXI5, ICU::VECTOR::RXI5, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI5> SCI5;
	typedef sci_t<0x0008A0C0, peripheral::SCI6,
		ICU::VECTOR::TXI6, ICU::VECTOR::RXI6, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI6> SCI6;
	typedef sci_t<0x0008A0E0, peripheral::SCI7,
		ICU::VECTOR::TXI7, ICU::VECTOR::RXI7, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI7> SCI7;

	typedef scih_t<0x0008B300, peripheral::SCI12,
		ICU::VECTOR::TXI12, ICU::VECTOR::RXI12, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI12> SCI12;

#elif defined(SIG_RX65N)
	typedef sci_t<0x0008A000, peripheral::SCI0,
		ICU::VECTOR::TXI0, ICU::VECTOR::RXI0, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI0> SCI0;
	typedef sci_t<0x0008A020, peripheral::SCI1,
		ICU::VECTOR::TXI1, ICU::VECTOR::RXI1, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI1> SCI1;
	typedef sci_t<0x0008A040, peripheral::SCI2,
		ICU::VECTOR::TXI2, ICU::VECTOR::RXI2, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI2> SCI2;
	typedef sci_t<0x0008A060, peripheral::SCI3,
		ICU::VECTOR::TXI3, ICU::VECTOR::RXI3, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI3> SCI3;
	typedef sci_t<0x0008A080, peripheral::SCI4,
		ICU::VECTOR::TXI4, ICU::VECTOR::RXI4, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI4> SCI4;
	typedef sci_t<0x0008A0A0, peripheral::SCI5,
		ICU::VECTOR::TXI5, ICU::VECTOR::RXI5, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI5> SCI5;
	typedef sci_t<0x0008A0C0, peripheral::SCI6,
		ICU::VECTOR::TXI6, ICU::VECTOR::RXI6, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI6> SCI6;
	typedef sci_t<0x0008A0E0, peripheral::SCI7,
		ICU::VECTOR::TXI7, ICU::VECTOR::RXI7, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI7> SCI7;

	typedef scih_t<0x0008B300, peripheral::SCI12,
		ICU::VECTOR::TXI12, ICU::VECTOR::RXI12, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI12> SCI12;
	typedef sci_t<0x0008A100, peripheral::SCI8,
		ICU::VECTOR::TXI8, ICU::VECTOR::RXI8,   ICU::VECTOR_BL1, ICU::VECTOR_BL1::TEI8>  SCI8;
	typedef sci_t<0x0008A120, peripheral::SCI9,
		ICU::VECTOR::TXI9, ICU::VECTOR::RXI9,   ICU::VECTOR_BL1, ICU::VECTOR_BL1::TEI9>  SCI9;
	typedef sci_t<0x000D0040, peripheral::SCI10,
		ICU::VECTOR::TXI10, ICU::VECTOR::RXI10, ICU::VECTOR_AL0, ICU::VECTOR_AL0::TEI10> SCI10;
	typedef sci_t<0x000D0060, peripheral::SCI11,
		ICU::VECTOR::TXI11, ICU::VECTOR::RXI11, ICU::VECTOR_AL0, ICU::VECTOR_AL0::TEI11> SCI11;

#elif defined(SIG_RX66T)
	typedef sci_t<0x0008A020, peripheral::SCI1,
		ICU::VECTOR::TXI1, ICU::VECTOR::RXI1, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI1> SCI1;

	typedef sci_t<0x0008A0A0, peripheral::SCI5,
		ICU::VECTOR::TXI5, ICU::VECTOR::RXI5, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI5> SCI5;
	typedef sci_t<0x0008A0C0, peripheral::SCI6,
		ICU::VECTOR::TXI6, ICU::VECTOR::RXI6, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI6> SCI6;

	typedef sci_t<0x0008A100, peripheral::SCI8,
		ICU::VECTOR::TXI8, ICU::VECTOR::RXI8, ICU::VECTOR_BL1, ICU::VECTOR_BL1::TEI8> SCI8;
	typedef sci_t<0x0008A120, peripheral::SCI9,
		ICU::VECTOR::TXI9, ICU::VECTOR::RXI9, ICU::VECTOR_BL1, ICU::VECTOR_BL1::TEI9> SCI9;

#elif defined(SIG_RX72M)
	typedef sci_t<0x0008A000, peripheral::SCI0,
		ICU::VECTOR::TXI0, ICU::VECTOR::RXI0, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI0> SCI0;
	typedef sci_t<0x0008A020, peripheral::SCI1,
		ICU::VECTOR::TXI1, ICU::VECTOR::RXI1, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI1> SCI1;
	typedef sci_t<0x0008A040, peripheral::SCI2,
		ICU::VECTOR::TXI2, ICU::VECTOR::RXI2, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI2> SCI2;
	typedef sci_t<0x0008A060, peripheral::SCI3,
		ICU::VECTOR::TXI3, ICU::VECTOR::RXI3, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI3> SCI3;
	typedef sci_t<0x0008A080, peripheral::SCI4,
		ICU::VECTOR::TXI4, ICU::VECTOR::RXI4, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI4> SCI4;
	typedef sci_t<0x0008A0A0, peripheral::SCI5,
		ICU::VECTOR::TXI5, ICU::VECTOR::RXI5, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI5> SCI5;
	typedef sci_t<0x0008A0C0, peripheral::SCI6,
		ICU::VECTOR::TXI6, ICU::VECTOR::RXI6, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI6> SCI6;
	typedef sci_t<0x0008A0E0, peripheral::SCI7,
		ICU::VECTOR::TXI7, ICU::VECTOR::RXI7, ICU::VECTOR_AL0, ICU::VECTOR_AL0::TEI7> SCI7;

	typedef sci_t<0x000D0000, peripheral::SCI8,
		ICU::VECTOR::TXI8, ICU::VECTOR::RXI8, ICU::VECTOR_AL0, ICU::VECTOR_AL0::TEI8> SCI8;
	typedef sci_t<0x000D0020, peripheral::SCI9,
		ICU::VECTOR::TXI9, ICU::VECTOR::RXI9, ICU::VECTOR_AL0, ICU::VECTOR_AL0::TEI9> SCI9;
	typedef sci_t<0x000D0040, peripheral::SCI10,
		ICU::VECTOR::TXI10, ICU::VECTOR::RXI10, ICU::VECTOR_AL0, ICU::VECTOR_AL0::TEI10> SCI10;
	typedef sci_t<0x000D0060, peripheral::SCI11,
		ICU::VECTOR::TXI11, ICU::VECTOR::RXI11, ICU::VECTOR_AL0, ICU::VECTOR_AL0::TEI11> SCI11;

	typedef scih_t<0x0008B300, peripheral::SCI12,
		ICU::VECTOR::TXI12, ICU::VECTOR::RXI12, ICU::VECTOR_BL0, ICU::VECTOR_BL0::TEI12> SCI12;

#endif
}
