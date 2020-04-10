#pragma once
//=====================================================================//
/*!	@file
	@brief	RX24T/RX66T/RX64M/RX71M/RX65N RIICa 定義
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2016, 2020 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RX/blob/master/LICENSE
*/
//=====================================================================//
#include "common/device.hpp"

namespace device {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief  I 2 C バスインタフェース 定義
		@param[in]	base	ベース・アドレス
		@param[in]	per		ペリフェラル型
		@param[in]	INT		割り込みベクター型
		@param[in]	eev		「通信エラー、通信イベント」ベクター
		@param[in]	rxv		「受信データフル」ベクター
		@param[in]	txv		「送信データエンプティ」ベクター
		@param[in]	tev		「送信終了」ベクター
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <uint32_t base, peripheral per,
		typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev>
	struct riic_t {

		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バスコントロールレジスタ 1 (ICCR1)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct iccr1_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> SDAI;
			bit_rw_t<io_, bitpos::B1> SCLI;
			bit_rw_t<io_, bitpos::B2> SDAO;
			bit_rw_t<io_, bitpos::B3> SCLO;
			bit_rw_t<io_, bitpos::B4> SOWP;
			bit_rw_t<io_, bitpos::B5> CLO;
			bit_rw_t<io_, bitpos::B6> IICRST;
			bit_rw_t<io_, bitpos::B7> ICE;
		};
		typedef iccr1_t_<base + 0x00> iccr1_t;
		static iccr1_t ICCR1;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バスコントロールレジスタ 2 (ICCR2)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct iccr2_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B1> ST;
			bit_rw_t<io_, bitpos::B2> RS;
			bit_rw_t<io_, bitpos::B3> SP;
			bit_rw_t<io_, bitpos::B5> TRS;
			bit_rw_t<io_, bitpos::B6> MST;
			bit_rw_t<io_, bitpos::B7> BBSY;
		};
		typedef iccr2_t_<base + 0x01> iccr2_t;
		static iccr2_t ICCR2;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バスモードレジスタ 1 (ICMR1)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct icmr1_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 3> BC;
			bit_rw_t <io_, bitpos::B3>    BCWP;
			bits_rw_t<io_, bitpos::B4, 3> CKS;
			bit_rw_t <io_, bitpos::B7>    MTWP;
		};
		typedef icmr1_t_<base + 0x02> icmr1_t;
		static icmr1_t ICMR1;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バスモードレジスタ 2 (ICMR2)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct icmr2_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t <io_, bitpos::B0>    TMOS;
			bit_rw_t <io_, bitpos::B1>    TMOL;
			bit_rw_t <io_, bitpos::B2>    TMOH;
			bits_rw_t<io_, bitpos::B4, 3> SDDL;
			bit_rw_t <io_, bitpos::B7>    DLCS;
		};
		typedef icmr2_t_<base + 0x03> icmr2_t;
		static icmr2_t ICMR2;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バスモードレジスタ 3 (ICMR3)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct icmr3_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 2> NF;
			bit_rw_t <io_, bitpos::B2>    ACKBR;
			bit_rw_t <io_, bitpos::B3>    ACKBT;
			bit_rw_t <io_, bitpos::B4>    ACKWP;
			bit_rw_t <io_, bitpos::B5>    RDRFS;
			bit_rw_t <io_, bitpos::B6>    WAIT;
			bit_rw_t <io_, bitpos::B7>    SMBS;
		};
		typedef icmr3_t_<base + 0x04> icmr3_t;
		static icmr3_t ICMR3;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バスファンクション許可レジスタ (ICFER)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct icfer_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> TMOE;
			bit_rw_t<io_, bitpos::B1> MALE;
			bit_rw_t<io_, bitpos::B2> NALE;
			bit_rw_t<io_, bitpos::B3> SALE;
			bit_rw_t<io_, bitpos::B4> NACKE;
			bit_rw_t<io_, bitpos::B5> NFE;
			bit_rw_t<io_, bitpos::B6> SCLE;
			bit_rw_t<io_, bitpos::B7> FMPE;
		};
		typedef icfer_t_<base + 0x05> icfer_t;
		static icfer_t ICFER;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バスステータス許可レジスタ (ICSER)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct icser_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> SAR0E;
			bit_rw_t<io_, bitpos::B1> SAR1E;
			bit_rw_t<io_, bitpos::B2> SAR2E;
			bit_rw_t<io_, bitpos::B3> GCAE;
			bit_rw_t<io_, bitpos::B5> DIDE;
			bit_rw_t<io_, bitpos::B7> HOAE;
		};
		typedef icser_t_<base + 0x06> icser_t;
		static icser_t ICSER;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バス割り込み許可レジスタ (ICIER)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct icier_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> TMOIE;
			bit_rw_t<io_, bitpos::B1> ALIE;
			bit_rw_t<io_, bitpos::B2> STIE;
			bit_rw_t<io_, bitpos::B3> SPIE;
			bit_rw_t<io_, bitpos::B4> NAKIE;
			bit_rw_t<io_, bitpos::B5> RIE;
			bit_rw_t<io_, bitpos::B6> TEIE;
			bit_rw_t<io_, bitpos::B7> TIE;
		};
		typedef icier_t_<base + 0x07> icier_t;
		static icier_t ICIER;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バスステータスレジスタ 1 (ICSR1)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct icsr1_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> AAS0;
			bit_rw_t<io_, bitpos::B1> AAS1;
			bit_rw_t<io_, bitpos::B2> AAS2;
			bit_rw_t<io_, bitpos::B3> GCA;
			bit_rw_t<io_, bitpos::B5> DID;
			bit_rw_t<io_, bitpos::B7> HOA;
		};
		typedef icsr1_t_<base + 0x08> icsr1_t;
		static icsr1_t ICSR1;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バスステータスレジスタ 2 (ICSR2)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct icsr2_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> TMOF;
			bit_rw_t<io_, bitpos::B1> AL;
			bit_rw_t<io_, bitpos::B2> START;
			bit_rw_t<io_, bitpos::B3> STOP;
			bit_rw_t<io_, bitpos::B4> NACKF;
			bit_rw_t<io_, bitpos::B5> RDRF;
			bit_rw_t<io_, bitpos::B6> TEND;
			bit_rw_t<io_, bitpos::B7> TDRE;
		};
		typedef icsr2_t_<base + 0x09> icsr2_t;
		static icsr2_t ICSR2;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  スレーブアドレスレジスタ Ly (SARLy) (y=0 ～ 2)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct sarly_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t <io_, bitpos::B0>    SVA0;
			bits_rw_t<io_, bitpos::B1, 7> SVA;
		};
		typedef sarly_t_<base + 0x0A> sarl0_t;
		static sarl0_t SARL0;
		typedef sarly_t_<base + 0x0C> sarl1_t;
		static sarl1_t SARL1;
		typedef sarly_t_<base + 0x0E> sarl2_t;
		static sarl2_t SARL2;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  スレーブアドレスレジスタ Uy (SARUy) (y=0 ～ 2)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct saruy_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t <io_, bitpos::B0>    FS;
			bits_rw_t<io_, bitpos::B1, 2> SVA;
		};
		typedef saruy_t_<base + 0x0B> saru0_t;
		static saru0_t SARU0;
		typedef saruy_t_<base + 0x0D> saru1_t;
		static saru1_t SARU1;
		typedef saruy_t_<base + 0x0F> saru2_t;
		static saru2_t SARU2;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バスビットレート Low レジスタ (ICBRL)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct icbrl_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t <io_, bitpos::B0, 5> BRL;
		};
		typedef icbrl_t_<base + 0x10> icbrl_t;
		static icbrl_t ICBRL;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バスビットレート High レジスタ (ICBRH)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t ofs>
		struct icbrh_t_ : public rw8_t<ofs> {
			typedef rw8_t<ofs> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t <io_, bitpos::B0, 5> BRH;
		};
		typedef icbrh_t_<base + 0x11> icbrh_t;
		static icbrh_t ICBRH;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バス送信データレジスタ (ICDRT)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		typedef rw8_t<base + 0x12> icdrt_t;
		static icdrt_t ICDRT;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  I 2 C バス受信データレジスタ (ICDRR)
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		typedef rw8_t<base + 0x13> icdrr_t;
		static icdrr_t ICDRR;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  チャネルを返す
			@return チャネル
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static uint32_t get_chanel() {
			return (base >> 5) & 1;
		}

		//-----------------------------------------------------------------//
		/*!
			@brief  ペリフェラル型を返す
			@return ペリフェラル型
		*/
		//-----------------------------------------------------------------//
		static peripheral get_peripheral() { return per; }


		//-----------------------------------------------------------------//
		/*!
			@brief  「通信エラー、通信イベント」ベクターを返す
			@return ベクター型
		*/
		//-----------------------------------------------------------------//
		static ICU::VECTOR get_ee_vec() { return eev; }


		//-----------------------------------------------------------------//
		/*!
			@brief  「受信データフル」ベクターを返す
			@return ベクター型
		*/
		//-----------------------------------------------------------------//
		static ICU::VECTOR get_rx_vec() { return rxv; }


		//-----------------------------------------------------------------//
		/*!
			@brief  「送信データエンプティ」ベクターを返す
			@return ベクター型
		*/
		//-----------------------------------------------------------------//
		static ICU::VECTOR get_tx_vec() { return txv; }


		//-----------------------------------------------------------------//
		/*!
			@brief  「送信終了」ベクターを返す
			@return ベクター型
		*/
		//-----------------------------------------------------------------//
		static ICU::VECTOR get_te_vec() { return tev; }
	};
#if defined(SIG_RX24T)
	typedef riic_t<0x00088300, peripheral::RIIC0, ICU::VECTOR, ICU::VECTOR::RIIC_EEI0,
		ICU::VECTOR::RIIC_RXI0, ICU::VECTOR::RIIC_TXI0, ICU::VECTOR::RIIC_TEI0> RIIC0;
#elif defined(SIG_RX64M) || defined(SIG_RX71M)
	typedef riic_t<0x00088300, peripheral::RIIC0, ICU::VECTOR_BL1, ICU::VECTOR_BL1::EEI0,
		ICU::VECTOR::RIIC_RXI0, ICU::VECTOR::RIIC_TXI0, ICU::VECTOR_BL1::TEI0> RIIC0;
	typedef riic_t<0x00088340, peripheral::RIIC2, ICU::VECTOR_BL1, ICU::VECTOR_BL1::EEI2,
		ICU::VECTOR::RIIC_RXI2, ICU::VECTOR::RIIC_TXI2, ICU::VECTOR_BL1::TEI2> RIIC2;
#elif defined(SIG_RX65N)
	typedef riic_t<0x00088300, peripheral::RIIC0, ICU::VECTOR_BL1, ICU::VECTOR_BL1::EEI0,
		ICU::VECTOR::RIIC_RXI0, ICU::VECTOR::RIIC_TXI0, ICU::VECTOR_BL1::TEI0> RIIC0;
	typedef riic_t<0x00088320, peripheral::RIIC1, ICU::VECTOR_BL1, ICU::VECTOR_BL1::EEI1,
		ICU::VECTOR::RIIC_RXI1, ICU::VECTOR::RIIC_TXI1, ICU::VECTOR_BL1::TEI1> RIIC1;
	typedef riic_t<0x00088340, peripheral::RIIC2, ICU::VECTOR_BL1, ICU::VECTOR_BL1::EEI2,
		ICU::VECTOR::RIIC_RXI2, ICU::VECTOR::RIIC_TXI2, ICU::VECTOR_BL1::TEI2> RIIC2;
#elif defined(SIG_RX66T)
	typedef riic_t<0x00088300, peripheral::RIIC0, ICU::VECTOR_BL1, ICU::VECTOR_BL1::EEI0,
		ICU::VECTOR::RIIC_RXI0, ICU::VECTOR::RIIC_TXI0, ICU::VECTOR_BL1::TEI0> RIIC0;
#endif

	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::iccr1_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICCR1;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::iccr2_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICCR2;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::icmr1_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICMR1;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::icmr2_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICMR2;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::icmr3_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICMR3;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::icfer_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICFER;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::icser_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICSER;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::icier_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICIER;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::icsr1_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICSR1;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::icsr2_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICSR2;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::sarl0_t riic_t<base, per, INT, eev, rxv, txv, tev>::SARL0;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::sarl1_t riic_t<base, per, INT, eev, rxv, txv, tev>::SARL1;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::sarl2_t riic_t<base, per, INT, eev, rxv, txv, tev>::SARL2;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::saru0_t riic_t<base, per, INT, eev, rxv, txv, tev>::SARU0;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::saru1_t riic_t<base, per, INT, eev, rxv, txv, tev>::SARU1;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::saru2_t riic_t<base, per, INT, eev, rxv, txv, tev>::SARU2;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::icbrl_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICBRL;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::icbrh_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICBRH;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::icdrt_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICDRT;
	template <uint32_t base, peripheral per, typename INT, INT eev, ICU::VECTOR rxv, ICU::VECTOR txv, INT tev> typename riic_t<base, per, INT, eev, rxv, txv, tev>::icdrr_t riic_t<base, per, INT, eev, rxv, txv, tev>::ICDRR;
}
