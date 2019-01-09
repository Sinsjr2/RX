#pragma once
//=====================================================================//
/*!	@file
	@brief	RX64M/RX71M グループ EPTPC 定義
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2018 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RX/blob/master/LICENSE
*/
//=====================================================================//
#include "common/device.hpp"

namespace device {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief	イーサネットコントローラ用 PTP コントローラ (EPTPC)
		@param[in]	per	ペリフェラル
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <peripheral per>
	struct eptpc_t {

		//-----------------------------------------------------------------//
		/*!
			@brief  MINT 割り込み要因ステータスレジスタ (MIESR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct miesr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>   ST;
			bit_rw_t<io_, bitpos::B1>   SY0;
			bit_rw_t<io_, bitpos::B2>   SY1;
			bit_rw_t<io_, bitpos::B3>   PRC;

			bit_rw_t<io_, bitpos::B16>  CYC0;
			bit_rw_t<io_, bitpos::B17>  CYC1;
			bit_rw_t<io_, bitpos::B18>  CYC2;
			bit_rw_t<io_, bitpos::B19>  CYC3;
			bit_rw_t<io_, bitpos::B20>  CYC4;
			bit_rw_t<io_, bitpos::B21>  CYC5;
		};
		static miesr_t<0x000C4000>  MIESR;


		//-----------------------------------------------------------------//
		/*!
			@brief  MINT 割り込み要求許可レジスタ (MIEIPR)
		*/
		//-----------------------------------------------------------------//
		static miesr_t<0x000C4004>  MIEIPR;


		//-----------------------------------------------------------------//
		/*!
			@brief  ELC 出力 /IPLS 割り込み要求許可レジスタ (ELIPPR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct elippr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>   CYCP0;
			bit_rw_t<io_, bitpos::B1>   CYCP1;
			bit_rw_t<io_, bitpos::B2>   CYCP2;
			bit_rw_t<io_, bitpos::B3>   CYCP3;
			bit_rw_t<io_, bitpos::B4>   CYCP4;
			bit_rw_t<io_, bitpos::B5>   CYCP5;

			bit_rw_t<io_, bitpos::B8>   CYCN0;
			bit_rw_t<io_, bitpos::B9>   CYCN1;
			bit_rw_t<io_, bitpos::B10>  CYCN2;
			bit_rw_t<io_, bitpos::B11>  CYCN3;
			bit_rw_t<io_, bitpos::B12>  CYCN4;
			bit_rw_t<io_, bitpos::B13>  CYCN5;

			bit_rw_t<io_, bitpos::B16>  PLSP;
			bit_rw_t<io_, bitpos::B24>  PLSN;
		};
		static elippr_t<0x000C4010>  ELIPPR;


		//-----------------------------------------------------------------//
		/*!
			@brief  ELC 出力 /IPLS 割り込み許可自動クリア設定レジスタ (ELIPACR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		static elippr_t<0x000C4010>  ELIPACR;


		//-----------------------------------------------------------------//
		/*!
			@brief  STCA ステータスレジスタ (STSR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct stsr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  SYNC;
			bit_rw_t<io_, bitpos::B1>  SYNCOUT;

			bit_rw_t<io_, bitpos::B3>  SYNTOUT;
			bit_rw_t<io_, bitpos::B4>  W10D;
		};
		static stsr_t<0x000C4040>  STSR;


		//-----------------------------------------------------------------//
		/*!
			@brief  STCA ステータス通知許可レジスタ (STIPR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		static stsr_t<0x000C4044>  STIPR;


		//-----------------------------------------------------------------//
		/*!
			@brief	STCA クロック周波数設定レジスタ (STCFR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct stcfr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 2>  STCF;
		};
		static stcfr_t<0x000C4050>  STCFR;


		//-----------------------------------------------------------------//
		/*!
			@brief	STCA 動作モードレジスタ (STMR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct stmr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0,  8>  WINT;

			bit_rw_t <io_, bitpos::B13>     CMOD;

			bit_rw_t <io_, bitpos::B15>     W10S;
			bits_rw_t<io_, bitpos::B16, 4>  SYTH;
			bits_rw_t<io_, bitpos::B20, 4>  DVTH;

			bit_rw_t <io_, bitpos::B28>     ALEN0;
			bit_rw_t <io_, bitpos::B29>     ALEN1;
		};
		static stmr_t<0x000C4054>  STMR;


		//-----------------------------------------------------------------//
		/*!
			@brief	Sync メッセージ受信タイムアウトレジスタ (SYNTOR)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4058> SYNTOR;


		//-----------------------------------------------------------------//
		/*!
			@brief	IPLS 割り込み要求タイマ選択レジスタ (IPTSELR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct iptselr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  IPTSEL0;
			bit_rw_t<io_, bitpos::B1>  IPTSEL1;
			bit_rw_t<io_, bitpos::B2>  IPTSEL2;
			bit_rw_t<io_, bitpos::B3>  IPTSEL3;
			bit_rw_t<io_, bitpos::B4>  IPTSEL4;
			bit_rw_t<io_, bitpos::B5>  IPTSEL5;
		};
		static iptselr_t<0x000C4060>  IPTSELR;


		//-----------------------------------------------------------------//
		/*!
			@brief	MINT 割り込み要求タイマ選択レジスタ (MITSELR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct mitselr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  MINTEN0;
			bit_rw_t<io_, bitpos::B1>  MINTEN1;
			bit_rw_t<io_, bitpos::B2>  MINTEN2;
			bit_rw_t<io_, bitpos::B3>  MINTEN3;
			bit_rw_t<io_, bitpos::B4>  MINTEN4;
			bit_rw_t<io_, bitpos::B5>  MINTEN5;
		};
		static mitselr_t<0x000C4064>  MITSELR;


		//-----------------------------------------------------------------//
		/*!
			@brief	ELC 出力タイマ選択レジスタ (ELTSELR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct eltselr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  ELTDIS0;
			bit_rw_t<io_, bitpos::B1>  ELTDIS1;
			bit_rw_t<io_, bitpos::B2>  ELTDIS2;
			bit_rw_t<io_, bitpos::B3>  ELTDIS3;
			bit_rw_t<io_, bitpos::B4>  ELTDIS4;
			bit_rw_t<io_, bitpos::B5>  ELTDIS5;
		};
		static eltselr_t<0x000C4068>  ELTSELR;


		//-----------------------------------------------------------------//
		/*!
			@brief	時刻同期チャネル選択レジスタ (STCHSELR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct stchselr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  SYSEL;
		};
		static stchselr_t<0x000C406C>  STCHSELR;


		//-----------------------------------------------------------------//
		/*!
			@brief	スレーブ時刻同期スタートレジスタ (SYNSTARTR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct synstartr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  STR;
		};
		static synstartr_t<0x000C4080>  SYNSTARTR;


		//-----------------------------------------------------------------//
		/*!
			@brief	ローカルクロックカウンタ初期値ロード指示レジスタ (LCIVLDR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct lcivldr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  LOAD;
		};
		static lcivldr_t<0x000C4084>  LCIVLDR;


		//-----------------------------------------------------------------//
		/*!
			@brief	同期外れ検出しきい値レジスタ U (SYNTDARU)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4090> SYNTDARU;


		//-----------------------------------------------------------------//
		/*!
			@brief	同期外れ検出しきい値レジスタ L (SYNTDARL)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4094> SYNTDARL;


		//-----------------------------------------------------------------//
		/*!
			@brief	同期検出しきい値レジスタ U (SYNTDBRU)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4098> SYNTDBRU;


		//-----------------------------------------------------------------//
		/*!
			@brief	同期検出しきい値レジスタ L (SYNTDBRL)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C409C> SYNTDBRL;


		//-----------------------------------------------------------------//
		/*!
			@brief	ローカルクロックカウンタ初期値レジスタ U (LCIVRU)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C40B0> LCIVRU;


		//-----------------------------------------------------------------//
		/*!
			@brief	ローカルクロックカウンタ初期値レジスタ M (LCIVRM)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C40B4> LCIVRM;


		//-----------------------------------------------------------------//
		/*!
			@brief	ローカルクロックカウンタ初期値レジスタ L (LCIVRL)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C40B8> LCIVRL;


		//-----------------------------------------------------------------//
		/*!
			@brief	ワースト 10 値取得指示レジスタ (GETW10R)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct getw10r_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  GW10;
		};
		static getw10r_t<0x000C4124>  GETW10R;


		//-----------------------------------------------------------------//
		/*!
			@brief	プラス側傾き制限値レジスタ U (PLIMITRU)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4128> PLIMITRU;


		//-----------------------------------------------------------------//
		/*!
			@brief	プラス側傾き制限値レジスタ M (PLIMITRM)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C412C> PLIMITRM;


		//-----------------------------------------------------------------//
		/*!
			@brief	プラス側傾き制限値レジスタ L (PLIMITRL)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4130> PLIMITRL;


		//-----------------------------------------------------------------//
		/*!
			@brief	マイナス側傾き制限値レジスタ U (MLIMITRU)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4134> MLIMITRU;


		//-----------------------------------------------------------------//
		/*!
			@brief	マイナス側傾き制限値レジスタ M (MLIMITRM)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4138> MLIMITRM;


		//-----------------------------------------------------------------//
		/*!
			@brief	マイナス側傾き制限値レジスタ L (MLIMITRL)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C413C> MLIMITRL;


		//-----------------------------------------------------------------//
		/*!
			@brief	統計情報表示指示レジスタ (GETINFOR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct getinfor_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  INFO;
		};
		static getinfor_t<0x000C4140>  GETINFOR;


		//-----------------------------------------------------------------//
		/*!
			@brief	ローカルクロックカウンタ U (LCCVRU)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4170> LCCVRU;


		//-----------------------------------------------------------------//
		/*!
			@brief	ローカルクロックカウンタ M (LCCVRM)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4174> LCCVRM;


		//-----------------------------------------------------------------//
		/*!
			@brief	ローカルクロックカウンタ L (LCCVRL)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4178> LCCVRL;


		//-----------------------------------------------------------------//
		/*!
			@brief	プラス側傾きワースト 10 値レジスタ U (PW10VRU)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4210> PW10VRU;


		//-----------------------------------------------------------------//
		/*!
			@brief	プラス側傾きワースト 10 値レジスタ M (PW10VRM)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4214> PW10VRM;


		//-----------------------------------------------------------------//
		/*!
			@brief	プラス側傾きワースト 10 値レジスタ L (PW10VRL)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4218> PW10VRL;


		//-----------------------------------------------------------------//
		/*!
			@brief	マイナス側傾きワースト 10 値レジスタ U (MW10RU)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C42D0> MW10RU;


		//-----------------------------------------------------------------//
		/*!
			@brief	マイナス側傾きワースト 10 値レジスタ M (MW10RM)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C42D4> MW10RM;


		//-----------------------------------------------------------------//
		/*!
			@brief	マイナス側傾きワースト 10 値レジスタ L (MW10RL)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C42D8> MW10RL;


		//-----------------------------------------------------------------//
		/*!
			@brief	タイマスタート時刻設定レジスタ m (TMSTTRUm) (m=0~5)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4300> TMSTTRU0;
		static rw32_t<0x000C4310> TMSTTRU1;
		static rw32_t<0x000C4320> TMSTTRU2;
		static rw32_t<0x000C4330> TMSTTRU3;
		static rw32_t<0x000C4340> TMSTTRU4;
		static rw32_t<0x000C4350> TMSTTRU5;


		//-----------------------------------------------------------------//
		/*!
			@brief	タイマスタート時刻設定レジスタ m (TMSTTRLm) (m=0~5)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4304> TMSTTRL0;
		static rw32_t<0x000C4314> TMSTTRL1;
		static rw32_t<0x000C4324> TMSTTRL2;
		static rw32_t<0x000C4334> TMSTTRL3;
		static rw32_t<0x000C4344> TMSTTRL4;
		static rw32_t<0x000C4354> TMSTTRL5;


		//-----------------------------------------------------------------//
		/*!
			@brief	タイマ周期設定レジスタ m (TMCYCRm) (m=0~5)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4308> TMCYCR0;
		static rw32_t<0x000C4318> TMCYCR1;
		static rw32_t<0x000C4328> TMCYCR2;
		static rw32_t<0x000C4338> TMCYCR3;
		static rw32_t<0x000C4348> TMCYCR4;
		static rw32_t<0x000C4358> TMCYCR5;


		//-----------------------------------------------------------------//
		/*!
			@brief	タイマパルス幅設定レジスタ m (TMPLSRm) (m=0~5)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C430C> TMPLSR0;
		static rw32_t<0x000C431C> TMPLSR1;
		static rw32_t<0x000C432C> TMPLSR2;
		static rw32_t<0x000C433C> TMPLSR3;
		static rw32_t<0x000C434C> TMPLSR4;
		static rw32_t<0x000C435C> TMPLSR5;


		//-----------------------------------------------------------------//
		/*!
			@brief	タイマスタートレジスタ (TMSTARTR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct tmstartr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  EN0;
			bit_rw_t<io_, bitpos::B1>  EN1;
			bit_rw_t<io_, bitpos::B2>  EN2;
			bit_rw_t<io_, bitpos::B3>  EN3;
			bit_rw_t<io_, bitpos::B4>  EN4;
			bit_rw_t<io_, bitpos::B5>  EN5;
		};
		static tmstartr_t<0x000C437C>  TMSTARTR;


		//-----------------------------------------------------------------//
		/*!
			@brief	PRC-TC ステータスレジスタ (PRSR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct prsr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>   OVRE0;
			bit_rw_t<io_, bitpos::B1>   OVRE1;
			bit_rw_t<io_, bitpos::B2>   OVRE2;
			bit_rw_t<io_, bitpos::B3>   OVRE3;

			bit_rw_t<io_, bitpos::B8>   MACE;

			bit_rw_t<io_, bitpos::B28>  URE0;
			bit_rw_t<io_, bitpos::B29>  URE1;
		};
		static prsr_t<0x000C4400>  PRSR;


		//-----------------------------------------------------------------//
		/*!
			@brief	PRC-TC ステータス通知許可レジスタ (PRIPR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		static prsr_t<0x000C4404>  PRIPR;


		//-----------------------------------------------------------------//
		/*!
			@brief	チャネル 0 自局 MAC アドレスレジスタ U (PRMACRU0)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4410> PRMACRU0;


		//-----------------------------------------------------------------//
		/*!
			@brief	チャネル 0 自局 MAC アドレスレジスタ L (PRMACRL0)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4414> PRMACRL0;


		//-----------------------------------------------------------------//
		/*!
			@brief	チャネル 1 自局 MAC アドレスレジスタ U (PRMACRU1)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4418> PRMACRU1;


		//-----------------------------------------------------------------//
		/*!
			@brief	チャネル 1 自局 MAC アドレスレジスタ L (PRMACRL1)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C441C> PRMACRL1;


		//-----------------------------------------------------------------//
		/*!
			@brief	パケット送信抑止制御レジスタ (TRNDISR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct trndisr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 2>  TDIS;
		};
		static trndisr_t<0x000C4420>  TRNDISR;


		//-----------------------------------------------------------------//
		/*!
			@brief	中継モードレジスタ (TRNMR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct trnmr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>  MOD;

			bit_rw_t<io_, bitpos::B8>  FWD0;
			bit_rw_t<io_, bitpos::B9>  FWD1;
		};
		static trnmr_t<0x000C4430>  TRNMR;


		//-----------------------------------------------------------------//
		/*!
			@brief	カットスルー転送開始しきい値レジスタ (TRNCTTDR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct trncttdr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 11>  THVAL;
		};
		static trncttdr_t<0x000C4434>  TRNCTTDR;






		//-----------------------------------------------------------------//
		/*!
			@brief  ペリフェラル型を返す
			@return ペリフェラル型
		*/
		//-----------------------------------------------------------------//
		static peripheral get_peripheral() { return per; }
	};


	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief	イーサネットコントローラ用 PTP コントローラ x (EPTPCx)
		@param[in]	ofs	 オフセット
		@param[in]	per	ペリフェラル
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <uint32_t ofs, peripheral per>
	struct eptpcx_t {

		//-----------------------------------------------------------------//
		/*!
			@brief	SYNFP ステータスレジスタ (SYSR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct sysr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>   OFMUD;
			bit_rw_t<io_, bitpos::B1>   INTCHG;
			bit_rw_t<io_, bitpos::B2>   MPDUD;

			bit_rw_t<io_, bitpos::B4>   DRPTO;
			bit_rw_t<io_, bitpos::B5>   INTDEV;
			bit_rw_t<io_, bitpos::B6>   DRQOVR;

			bit_rw_t<io_, bitpos::B12>  RECLP;

			bit_rw_t<io_, bitpos::B14>  INFABT;

			bit_rw_t<io_, bitpos::B16>  RESDN;
			bit_rw_t<io_, bitpos::B17>  GENDN;
		};
		static sysr_t<0x000C4800 + ofs>  SYSR;


		//-----------------------------------------------------------------//
		/*!
			@brief	SYNFP ステータス通知許可レジスタ (SYIPR)
		*/
		//-----------------------------------------------------------------//
		static sysr_t<0x000C4804 + ofs>  SYIPR;


		//-----------------------------------------------------------------//
		/*!
			@brief	SYNFP MAC アドレスレジスタ U (SYMACRU)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4810 + ofs> SYMACRU;


		//-----------------------------------------------------------------//
		/*!
			@brief	SYNFP MAC アドレスレジスタ L (SYMACRL)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4814 + ofs> SYMACRL;


		//-----------------------------------------------------------------//
		/*!
			@brief	SYNFP LLC-CTL 値レジスタ (SYLLCCTLR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct syllcctlr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 8>  CTL;
		};
		static syllcctlr_t<0x000C4818 + ofs>  SYLLCCTLR;


		//-----------------------------------------------------------------//
		/*!
			@brief	SYNFP 自局 IP アドレスレジスタ (SYIPADDRR)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C481C + ofs> SYIPADDRR;


		//-----------------------------------------------------------------//
		/*!
			@brief	SYNFP 仕様・バージョン設定レジスタ (SYSPVRR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct syspvrr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 4>  VER;
			bits_rw_t<io_, bitpos::B4, 4>  TRSP;
		};
		static syspvrr_t<0x000C4840 + ofs>  SYSPVRR;


		//-----------------------------------------------------------------//
		/*!
			@brief	SYNFP ドメイン番号設定レジスタ (SYDOMR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct sydomr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 8>  DNUM;
		};
		static sydomr_t<0x000C4844 + ofs>  SYDOMR;


		//-----------------------------------------------------------------//
		/*!
			@brief	アナウンスメッセージフラグフィールド設定レジスタ (ANFR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct anfr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>   FLAG0;
			bit_rw_t<io_, bitpos::B1>   FLAG1;
			bit_rw_t<io_, bitpos::B2>   FLAG2;
			bit_rw_t<io_, bitpos::B3>   FLAG3;
			bit_rw_t<io_, bitpos::B4>   FLAG4;
			bit_rw_t<io_, bitpos::B5>   FLAG5;

			bit_rw_t<io_, bitpos::B8>   FLAG8;

			bit_rw_t<io_, bitpos::B10>  FLAG10;

			bit_rw_t<io_, bitpos::B13>  FLAG13;
			bit_rw_t<io_, bitpos::B14>  FLAG14;
		};
		static anfr_t<0x000C4850 + ofs>  ANFR;


		//-----------------------------------------------------------------//
		/*!
			@brief	Sync メッセージフラグフィールド設定レジスタ (SYNFR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct synfr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B8>   FLAG8;
			bit_rw_t<io_, bitpos::B9>   FLAG9;
			bit_rw_t<io_, bitpos::B10>  FLAG10;

			bit_rw_t<io_, bitpos::B13>  FLAG13;
			bit_rw_t<io_, bitpos::B14>  FLAG14;
		};
		static synfr_t<0x000C4854 + ofs>  SYNFR;


		//-----------------------------------------------------------------//
		/*!
			@brief	Delay_Req メッセージフラグフィールド設定レジスタ (DYRQFR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct dyrqfr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B10>  FLAG10;

			bit_rw_t<io_, bitpos::B13>  FLAG13;
			bit_rw_t<io_, bitpos::B14>  FLAG14;
		};
		static dyrqfr_t<0x000C4858 + ofs>  DYRQFR;


		//-----------------------------------------------------------------//
		/*!
			@brief	Delay_Resp メッセージフラグフィールド設定レジスタ (DYRPFR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct dyrpfr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B8>   FLAG8;
			bit_rw_t<io_, bitpos::B9>   FLAG9;
			bit_rw_t<io_, bitpos::B10>  FLAG10;

			bit_rw_t<io_, bitpos::B13>  FLAG13;
			bit_rw_t<io_, bitpos::B14>  FLAG14;
		};
		static dyrpfr_t<0x000C485C + ofs>  DYRPFR;


		//-----------------------------------------------------------------//
		/*!
			@brief	SYNFP 自局クロック ID レジスタ U (SYCIDRU)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4860 + ofs> SYCIDRU;


		//-----------------------------------------------------------------//
		/*!
			@brief	SYNFP 自局クロック ID レジスタ L (SYCIDRL)
		*/
		//-----------------------------------------------------------------//
		static rw32_t<0x000C4864 + ofs> SYCIDRL;


		//-----------------------------------------------------------------//
		/*!
			@brief	SYNFP 自局ポート番号レジスタ (SYPNUMR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct sypnumr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0, 16>   PNUM;
		};
		static sypnumr_t<0x000C4868 + ofs>  SYPNUMR;


		//-----------------------------------------------------------------//
		/*!
			@brief	SYNFP レジスタ値ロード指示レジスタ (SYRVLDR)
			@param[in]	base	ベースアドレス
		*/
		//-----------------------------------------------------------------//
		template <uint32_t base>
		struct syrvldr_t : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0>   BMIP;
			bit_rw_t<io_, bitpos::B1>   STUP;
			bit_rw_t<io_, bitpos::B2>   ANUP;
		};
		static syrvldr_t<0x000C4880 + ofs>  SYRVLDR;





		//-----------------------------------------------------------------//
		/*!
			@brief  ペリフェラル型を返す
			@return ペリフェラル型
		*/
		//-----------------------------------------------------------------//
		static peripheral get_peripheral() { return per; }
	};
	typedef eptpc_t<peripheral::EPTPC> EPTPC;
	typedef eptpcx_t<0x000, peripheral::EPTPC0> EPTPC0;
	typedef eptpcx_t<0x400, peripheral::EPTPC1> EPTPC1;
}
