#pragma once
//=====================================================================//
/*!	@file
	@brief	RX66T グループ・ICUc 定義
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2018, 2019 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RX/blob/master/LICENSE
*/
//=====================================================================//
#include "RX600/icu_utils.hpp"

namespace device {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief  ICUA 定義基底クラス
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template<typename _>
	struct icu_t_ {

		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  ベクター・インデックス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		enum class VECTOR {
			NONE    = 0,	///< none 

			BUSERR  = 16,   ///< BSC

			RAMERR  = 18,	///< RAM

			FIFERR  = 21,   ///< FCU

			FRDYI   = 23,   ///< FCU

			SWINT2  = 26,   ///< ICU
			SWINT   = 27,   ///< ICU

			CMI0    = 28,   ///< CMT0
			CMI1    = 29,   ///< CMT1
			CMI2    = 30,   ///< CMT2
			CMI3    = 31,   ///< CMT3

			D0FIFO0 = 34,   ///< USB0
 			D1FIFO0 = 35,   ///< USB0

			SPRI0   = 38,   ///< RSPI0
			SPTI0   = 39,   ///< RSPI0

			RIIC_RXI0 = 52,   ///< RIIC0
			RIIC_TXI0 = 53,   ///< RIIC0

			RXI1    = 60,	///< SCI1
			TXI1    = 61,	///< SCI1

			IRQ0    = 64,   ///< ICU
			IRQ1    = 65,
			IRQ2    = 66,
			IRQ3    = 67,
			IRQ4    = 68,
			IRQ5    = 69,
			IRQ6    = 70,
			IRQ7    = 71,
			IRQ8    = 72,
			IRQ9    = 73,
			IRQ10   = 74,
			IRQ11   = 75,
			IRQ12   = 76,
			IRQ13   = 77,
			IRQ14   = 78,
			IRQ15   = 79,

			RXI5	= 84,	///< SCI5
			TXI5	= 85,	///< SCI5
			RXI6	= 86,	///< SCI6
			TXI6	= 87,	///< SCI6

			LVD1    = 88,   ///< LVD1
			LVD2    = 89,   ///< LVD2

			USBR0	= 90,	///< USB0

			RXI8	= 100,	///< SCI8
			TXI8	= 101,	///< SCI8
			RXI9	= 102,	///< SCI9
			TXI9	= 103,	///< SCI9

			GROUPBE0 = 106,	///< ICU

			GROUPBL0 = 110,	///< ICU
			GROUPBL1 = 111,	///< ICU
			GROUPAL0 = 112,	///< ICU

			RXI11	= 114,	///< SCI11
			TXI11	= 115,	///< SCI11
			RXI12	= 116,	///< SCI12
			TXI12	= 117,	///< SCI12

			DMAC0I  = 120,	///< DMAC
			DMAC1I  = 121,	///< DMAC
			DMAC2I  = 122,	///< DMAC
			DMAC3I  = 123,	///< DMAC
			DMAC74I = 124,	///< DMAC

			OSTDI   = 125,	///< OST

			S12ADI    = 128,  ///< S12AD
			S12GBADI  = 129,  ///< S12AD
			S12GCADI  = 130,  ///< S12AD

			S12ADI1   = 132,  ///< S12AD1
			S12GBADI1 = 133,  ///< S12AD1
			S12GCADI1 = 134,  ///< S12AD1

			S12ADI2   = 136,  ///< S12AD2
			S12GBADI2 = 137,  ///< S12AD2
			S12GCADI2 = 138,  ///< S12AD2

			CMIA0   = 146,	///< TMR0: CMIA0
			CMIB0   = 147,	///< TMR0: CMIB0
			OVI0    = 148,	///< TMR0: OVI0
			CMIA1   = 149,	///< TMR1: CMIA1
			CMIB1   = 150,	///< TMR1: CMIB1
			OVI1    = 151,	///< TMR1: OVI1
			CMIA2   = 152,	///< TMR2: CMIA2
			CMIB2   = 153,	///< TMR2: CMIB2
			OVI2    = 154,	///< TMR2: OVI2
			CMIA3   = 155,	///< TMR3: CMIA3
			CMIB3   = 156,	///< TMR3: CMIB3
			OVI3    = 157,	///< TMR3: OVI3
			CMIA4   = 158,	///< TMR4: CMIA4
			CMIB4   = 159,	///< TMR4: CMIB4
			OVI4    = 160,	///< TMR4: OVI4
			CMIA5   = 161,	///< TMR5: CMIA5
			CMIB5   = 162,	///< TMR5: CMIB5
			OVI5    = 163,	///< TMR5: OVI5
			CMIA6   = 164,	///< TMR6: CMIA6
			CMIB6   = 165,	///< TMR6: CMIB6
			OVI6    = 166,	///< TMR6: OVI6
			CMIA7   = 167,	///< TMR7: CMIA7
			CMIB7   = 168,	///< TMR7: CMIB7
			OVI7    = 169,	///< TMR7: OVI7

			RXF0    = 170,	///< CAN0
			TXF0    = 171,	///< CAN0
			RXM0    = 172,	///< CAN0
			TXM0    = 173,	///< CAN0

			USBI0	= 174,	///< USB0

			ELSR18I = 175,	///< ELC
			ELSR19I = 176,	///< ELC

			RD		= 177,	///< TSIP-Lite
			WR		= 178,	///< TSIP-Lite
			ERR		= 179,	///< TSIP-Lite

			CMPC0	= 180,	///< CMPC0
			CMPC1	= 181,	///< CMPC1
			CMPC2	= 182,	///< CMPC2
			CMPC3	= 183,	///< CMPC3
			CMPC4	= 184,	///< CMPC4
			CMPC5	= 185,	///< CMPC5

			INTA208 = 208,	///< PERIA
			INTA209 = 209,	///< PERIA
			INTA210 = 210,	///< PERIA
			INTA211 = 211,	///< PERIA
			INTA212 = 212,	///< PERIA
			INTA213 = 213,	///< PERIA
			INTA214 = 214,	///< PERIA
			INTA215 = 215,	///< PERIA
			INTA216 = 216,	///< PERIA
			INTA217 = 217,	///< PERIA
			INTA218 = 218,	///< PERIA
			INTA219 = 219,	///< PERIA
			INTA220 = 220,	///< PERIA
			INTA221 = 221,	///< PERIA
			INTA222 = 222,	///< PERIA
			INTA223 = 223,	///< PERIA
			INTA224 = 224,	///< PERIA
			INTA225 = 225,	///< PERIA
			INTA226 = 226,	///< PERIA
			INTA227 = 227,	///< PERIA
			INTA228 = 228,	///< PERIA
			INTA229 = 229,	///< PERIA
			INTA230 = 230,	///< PERIA
			INTA231 = 231,	///< PERIA
			INTA232 = 232,	///< PERIA
			INTA233 = 233,	///< PERIA
			INTA234 = 234,	///< PERIA
			INTA235 = 235,	///< PERIA
			INTA236 = 236,	///< PERIA
			INTA237 = 237,	///< PERIA
			INTA238 = 238,	///< PERIA
			INTA239 = 239,	///< PERIA
			INTA240 = 240,	///< PERIA
			INTA241 = 241,	///< PERIA
			INTA242 = 242,	///< PERIA
			INTA243 = 243,	///< PERIA
			INTA244 = 244,	///< PERIA
			INTA245 = 245,	///< PERIA
			INTA246 = 246,	///< PERIA
			INTA247 = 247,	///< PERIA
			INTA248 = 248,	///< PERIA
			INTA249 = 249,	///< PERIA
			INTA250 = 250,	///< PERIA
			INTA251 = 251,	///< PERIA
			INTA252 = 252,	///< PERIA
			INTA253 = 253,	///< PERIA
			INTA254 = 254,	///< PERIA
			INTA255 = 255	///< PERIA
		};


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  選択型割り込みＡ要因・ベクター・インデックス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		enum class VECTOR_SELA {
			NONE = 0,	///< なし

			TGIA0 = 1,	///< MTU0（TGRAのインプットキャプチャ /コンペアマッチ）
			TGIB0,		///< MTU0（TGRBのインプットキャプチャ /コンペアマッチ）
			TGIC0,		///< MTU0（TGRCのインプットキャプチャ /コンペアマッチ）
			TGID0,		///< MTU0（TGRDのインプットキャプチャ /コンペアマッチ）
			TCIV0,		///< MTU0（TCNTのオーバフロー）
			TGIE0,		///< MTU0（TGREのインプットキャプチャ /コンペアマッチ）
			TGIF0,		///< MTU0（TGRFのインプットキャプチャ /コンペアマッチ）

			TGIA1 = 8,	///< MTU1（TGRAのインプットキャプチャ /コンペアマッチ）
			TGIB1,		///< MTU1（TGRBのインプットキャプチャ /コンペアマッチ）
			TCIV1,		///< MTU1（TCNTのオーバフロー）
			TCIU1,		///< MTU1（TCNTのアンダフロー）

			TGIA2 = 12,	///< MTU2（TGRAのインプットキャプチャ /コンペアマッチ）
			TGIB2,		///< MTU2（TGRBのインプットキャプチャ /コンペアマッチ）
			TCIV2,		///< MTU2（TCNTのオーバフロー）
			TCIU2,		///< MTU2（TCNTのアンダフロー）

			TGIA3 = 16,	///< MTU3（TGRAのインプットキャプチャ /コンペアマッチ）
			TGIB3,		///< MTU3（TGRBのインプットキャプチャ /コンペアマッチ）
			TGIC3,		///< MTU3（TGRCのインプットキャプチャ /コンペアマッチ）
			TGID3,		///< MTU3（TGRDのインプットキャプチャ /コンペアマッチ）
			TCIV3,		///< MTU3（TCNTのオーバフロー）

			TGIA4 = 21,	///< MTU4（TGRAのインプットキャプチャ /コンペアマッチ）
			TGIB4,		///< MTU4（TGRBのインプットキャプチャ /コンペアマッチ）
			TGIC4,		///< MTU4（TGRCのインプットキャプチャ /コンペアマッチ）
			TGID4,		///< MTU4（TGRDのインプットキャプチャ /コンペアマッチ）
			TCIV4,		///< MTU4（TCNTのオーバフロー /アンダフロー（相補PWMモード時のみ））

			TGIU5 = 27,	///< MTU5（TGRUのインプットキャプチャ /コンペアマッチ）
			TGIV5,		///< MTU5（TGRVのインプットキャプチャ /コンペアマッチ）
			TGIW5,		///< MTU5（TGRWのインプットキャプチャ /コンペアマッチ）

			TGIA6 = 30,	///< MTU6（TGRAのインプットキャプチャ /コンペアマッチ）
			TGIB6,		///< MTU6（TGRBのインプットキャプチャ /コンペアマッチ）
			TGIC6,		///< MTU6（TGRCのインプットキャプチャ /コンペアマッチ）
			TGID6,		///< MTU6（TGRDのインプットキャプチャ /コンペアマッチ）
			TCIV6,		///< MTU6（TCNTのオーバフロー）

			TGIA7 = 35,	///< MTU7（TGRAのインプットキャプチャ /コンペアマッチ）
			TGIB7,		///< MTU7（TGRBのインプットキャプチャ /コンペアマッチ）
			TGIC7,		///< MTU7（TGRCのインプットキャプチャ /コンペアマッチ）
			TGID7,		///< MTU7（TGRDのインプットキャプチャ /コンペアマッチ）
			TCIV7,		///< MTU7（TCNTのオーバフロー /アンダフロー（相補PWMモード時のみ））

			TGIA9 = 47,	///< MTU9（TGRAのインプットキャプチャ /コンペアマッチ）
			TGIB9,		///< MTU9（TGRBのインプットキャプチャ /コンペアマッチ）
			TGIC9,		///< MTU9（TGRCのインプットキャプチャ /コンペアマッチ）
			TGID9,		///< MTU9（TGRDのインプットキャプチャ /コンペアマッチ）
			TCIV9,		///< MTU9（TCNTのオーバフロー）
			TGIE9,		///< MTU9（TGREのインプットキャプチャ /コンペアマッチ）
			TGIF9,		///< MTU9（TGRFのインプットキャプチャ /コンペアマッチ）

			GTCIA0 = 56,///< GPTW0 GTCIA0 (GTCCRA レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIB0,		///< GPTW0 GTCIB0 (GTCCRB レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIC0,		///< GPTW0 GTCIC0 (GTCCRCレジスタのコンペアマッチ)
			GTCID0,		///< GPTW0 GTCID0 (GTCCRDレジスタのコンペアマッチ)
			GDTE0,		///< GPTW0 GDTE0  (デッドタイムエラー )
			GTCIE0,		///< GPTW0 GTCIE0 (GTCCREレジスタのコンペアマッチ)
			GTCIF0,		///< GPTW0 GTCIF0 (GTCCRFレジスタのコンペアマッチ) 
			GTCIV0,		///< GPTW0 GTCIV0 (GTCNTカウンタのオーバフロー (GTPRレジスタのコンペアマッチ))
			GTCIU0,		///< GPTW0 GTCIU0 (GTCNTカウンタのアンダフロー ) 

			GTCIA1 = 65,///< GPTW1 GTCIA1 (GTCCRA レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIB1,		///< GPTW1 GTCIB1 (GTCCRB レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIC1,		///< GPTW1 GTCIC1 (GTCCRCレジスタのコンペアマッチ)
			GTCID1,		///< GPTW1 GTCID1 (GTCCRDレジスタのコンペアマッチ)
			GDTE1,		///< GPTW1 GDTE1  (デッドタイムエラー )
			GTCIE1,		///< GPTW1 GTCIE1 (GTCCREレジスタのコンペアマッチ)
			GTCIF1,		///< GPTW1 GTCIF1 (GTCCRFレジスタのコンペアマッチ) 
			GTCIV1,		///< GPTW1 GTCIV1 (GTCNTカウンタのオーバフロー (GTPRレジスタのコンペアマッチ))
			GTCIU1,		///< GPTW1 GTCIU1 (GTCNTカウンタのアンダフロー ) 

			GTCIA2 = 74,///< GPTW2 GTCIA2 (GTCCRA レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIB2,		///< GPTW2 GTCIB2 (GTCCRB レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIC2,		///< GPTW2 GTCIC2 (GTCCRCレジスタのコンペアマッチ)
			GTCID2,		///< GPTW2 GTCID2 (GTCCRDレジスタのコンペアマッチ)
			GDTE2,		///< GPTW2 GDTE2  (デッドタイムエラー )
			GTCIE2,		///< GPTW2 GTCIE2 (GTCCREレジスタのコンペアマッチ)
			GTCIF2,		///< GPTW2 GTCIF2 (GTCCRFレジスタのコンペアマッチ) 
			GTCIV2,		///< GPTW2 GTCIV2 (GTCNTカウンタのオーバフロー (GTPRレジスタのコンペアマッチ))
			GTCIU2,		///< GPTW2 GTCIU2 (GTCNTカウンタのアンダフロー ) 

			GTCIA3 = 83,///< GPTW3 GTCIA3 (GTCCRA レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIB3,		///< GPTW3 GTCIB3 (GTCCRB レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIC3,		///< GPTW3 GTCIC3 (GTCCRCレジスタのコンペアマッチ)
			GTCID3,		///< GPTW3 GTCID3 (GTCCRDレジスタのコンペアマッチ)
			GDTE3,		///< GPTW3 GDTE3  (デッドタイムエラー )
			GTCIE3,		///< GPTW3 GTCIE3 (GTCCREレジスタのコンペアマッチ)
			GTCIF3,		///< GPTW3 GTCIF3 (GTCCRFレジスタのコンペアマッチ) 
			GTCIV3,		///< GPTW3 GTCIV3 (GTCNTカウンタのオーバフロー (GTPRレジスタのコンペアマッチ))
			GTCIU3,		///< GPTW3 GTCIU3 (GTCNTカウンタのアンダフロー ) 

			GTCIA4 = 92,///< GPTW4 GTCIA4 (GTCCRA レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIB4,		///< GPTW4 GTCIB4 (GTCCRB レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIC4,		///< GPTW4 GTCIC4 (GTCCRCレジスタのコンペアマッチ)
			GTCID4,		///< GPTW4 GTCID4 (GTCCRDレジスタのコンペアマッチ)
			GDTE4,		///< GPTW4 GDTE4  (デッドタイムエラー )
			GTCIE4,		///< GPTW4 GTCIE4 (GTCCREレジスタのコンペアマッチ)
			GTCIF4,		///< GPTW4 GTCIF4 (GTCCRFレジスタのコンペアマッチ) 
			GTCIV4,		///< GPTW4 GTCIV4 (GTCNTカウンタのオーバフロー (GTPRレジスタのコンペアマッチ))
			GTCIU4,		///< GPTW4 GTCIU4 (GTCNTカウンタのアンダフロー ) 

			GTCIA5 =101,///< GPTW5 GTCIA5 (GTCCRA レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIB5,		///< GPTW5 GTCIB5 (GTCCRB レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIC5,		///< GPTW5 GTCIC5 (GTCCRCレジスタのコンペアマッチ)
			GTCID5,		///< GPTW5 GTCID5 (GTCCRDレジスタのコンペアマッチ)
			GDTE5,		///< GPTW5 GDTE5  (デッドタイムエラー )
			GTCIE5,		///< GPTW5 GTCIE5 (GTCCREレジスタのコンペアマッチ)
			GTCIF5,		///< GPTW5 GTCIF5 (GTCCRFレジスタのコンペアマッチ) 
			GTCIV5,		///< GPTW5 GTCIV5 (GTCNTカウンタのオーバフロー (GTPRレジスタのコンペアマッチ))
			GTCIU5,		///< GPTW5 GTCIU5 (GTCNTカウンタのアンダフロー ) 

			GTCIA6 =110,///< GPTW6 GTCIA6 (GTCCRA レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIB6,		///< GPTW6 GTCIB6 (GTCCRB レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIC6,		///< GPTW6 GTCIC6 (GTCCRCレジスタのコンペアマッチ)
			GTCID6,		///< GPTW6 GTCID6 (GTCCRDレジスタのコンペアマッチ)
			GDTE6,		///< GPTW6 GDTE6  (デッドタイムエラー )
			GTCIE6,		///< GPTW6 GTCIE6 (GTCCREレジスタのコンペアマッチ)
			GTCIF6,		///< GPTW6 GTCIF6 (GTCCRFレジスタのコンペアマッチ) 
			GTCIV6,		///< GPTW6 GTCIV6 (GTCNTカウンタのオーバフロー (GTPRレジスタのコンペアマッチ))
			GTCIU6,		///< GPTW6 GTCIU6 (GTCNTカウンタのアンダフロー ) 

			GTCIA7 =119,///< GPTW7 GTCIA7 (GTCCRA レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIB7,		///< GPTW7 GTCIB7 (GTCCRB レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIC7,		///< GPTW7 GTCIC7 (GTCCRCレジスタのコンペアマッチ)
			GTCID7,		///< GPTW7 GTCID7 (GTCCRDレジスタのコンペアマッチ)
			GDTE7,		///< GPTW7 GDTE7  (デッドタイムエラー )
			GTCIE7,		///< GPTW7 GTCIE7 (GTCCREレジスタのコンペアマッチ)
			GTCIF7,		///< GPTW7 GTCIF7 (GTCCRFレジスタのコンペアマッチ) 
			GTCIV7,		///< GPTW7 GTCIV7 (GTCNTカウンタのオーバフロー (GTPRレジスタのコンペアマッチ))
			GTCIU7,		///< GPTW7 GTCIU7 (GTCNTカウンタのアンダフロー ) 

			GTCIA8 =128,///< GPTW8 GTCIA8 (GTCCRA レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIB8,		///< GPTW8 GTCIB8 (GTCCRB レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIC8,		///< GPTW8 GTCIC8 (GTCCRCレジスタのコンペアマッチ)
			GTCID8,		///< GPTW8 GTCID8 (GTCCRDレジスタのコンペアマッチ)
			GDTE8,		///< GPTW8 GDTE8  (デッドタイムエラー )
			GTCIE8,		///< GPTW8 GTCIE8 (GTCCREレジスタのコンペアマッチ)
			GTCIF8,		///< GPTW8 GTCIF8 (GTCCRFレジスタのコンペアマッチ) 
			GTCIV8,		///< GPTW8 GTCIV8 (GTCNTカウンタのオーバフロー (GTPRレジスタのコンペアマッチ))
			GTCIU8,		///< GPTW8 GTCIU8 (GTCNTカウンタのアンダフロー ) 

			GTCIA9 =137,///< GPTW9 GTCIA9 (GTCCRA レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIB9,		///< GPTW9 GTCIB9 (GTCCRB レジスタのインプットキャプチャ /コンペアマッチ)
			GTCIC9,		///< GPTW9 GTCIC9 (GTCCRCレジスタのコンペアマッチ)
			GTCID9,		///< GPTW9 GTCID9 (GTCCRDレジスタのコンペアマッチ)
			GDTE9,		///< GPTW9 GDTE9  (デッドタイムエラー )
			GTCIE9,		///< GPTW9 GTCIE9 (GTCCREレジスタのコンペアマッチ)
			GTCIF9,		///< GPTW9 GTCIF9 (GTCCRFレジスタのコンペアマッチ) 
			GTCIV9,		///< GPTW9 GTCIV9 (GTCNTカウンタのオーバフロー (GTPRレジスタのコンペアマッチ))
			GTCIU9,		///< GPTW9 GTCIU9 (GTCNTカウンタのアンダフロー ) 
		};


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  GROUPBE0・ベクター・インデックス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		enum class VECTOR_BE0 {
			ERS0,	///< CAN0 / ERS0
		};


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  GROUPBL0・ベクター・インデックス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		enum class VECTOR_BL0 {
			TEI1 = 2,	///< SCI1 送信終了割り込み 
			ERI1 = 3,	///< SCI1 受信エラー割り込み

			TEI5 = 10,	///< SCI5 送信終了割り込み 
			ERI5 = 11,	///< SCI5 受信エラー割り込み
			TEI6 = 12,	///< SCI6 送信終了割り込み 
			ERI6 = 13,	///< SCI6 受信エラー割り込み

			TEI12 = 16,	///< SCI12 送信終了割り込み 
			ERI12 = 17,	///< SCI12 受信エラー割り込み

			FERRI = 26,	///< CAC 周波数エラー
			MENDI = 27,	///< CAC 測定終了
			OVFI  = 28,	///< CAC オーバフロー割り込み

			DOPCI = 29,	///< DOC データ演算回路割り込み
		};


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  GROUPBL1・ベクター・インデックス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		enum class VECTOR_BL1 {

			OEI5 = 8,	///< POE3
			OEI1 = 9,	///< POE3
			OEI2 = 10,	///< POE3
			OEI3 = 11,	///< POE3
			OEI4 = 12,	///< POE3

			TEI0 = 13,	///< RIIC0 / TEI0
			EEI0,		///< RIIC0 / EEI0

			TEI8 = 24,	///< SCI8 送信終了割り込み 
			ERI8 = 25,	///< SCI8 受信エラー割り込み
			TEI9 = 26,	///< SCI9 送信終了割り込み 
			ERI9 = 27,	///< SCI9 受信エラー割り込み
		};


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  GROUPAL0・ベクター・インデックス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		enum class VECTOR_AL0 {
			TEI11 = 12,	///< SCI12 送信終了割り込み 
			ERI11 = 13,	///< SCI12 受信エラー割り込み
		};


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  グループベクターの取得
			@param[in]	VEC		グループベクター型
			@return グループベクター
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static VECTOR get_group_vector(VECTOR_BL0 ivec) noexcept {
			return VECTOR::GROUPBL0;
		}


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  グループベクターの取得
			@param[in]	VEC		グループベクター型
			@return グループベクター
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static VECTOR get_group_vector(VECTOR_BL1 ivec) noexcept {
			return VECTOR::GROUPBL1;
		}


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  グループベクターの取得
			@param[in]	VEC		グループベクター型
			@return グループベクター
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static VECTOR get_group_vector(VECTOR_BE0 ivec) noexcept {
			return VECTOR::GROUPBE0;
		}


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  グループベクターの取得
			@param[in]	VEC		グループベクター型
			@return グループベクター
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		static VECTOR get_group_vector(VECTOR_AL0 ivec) noexcept {
			return VECTOR::GROUPAL0;
		}


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  IR レジスタ
			@param[in]	base	ベース・アドレス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t base>
		struct ir_t_ {

			rw8_t<base + 16> BUSERR;

			rw8_t<base + 18> RAMERR;

			rw8_t<base + 21> FIFERR;

			rw8_t<base + 23> FRDYI;

			rw8_t<base + 26> SWINT2;
			rw8_t<base + 27> SWINT;

			rw8_t<base + 28> CMI0;
			rw8_t<base + 29> CMI1;
			rw8_t<base + 30> CMI2;
			rw8_t<base + 31> CMI3;

			rw8_t<base + 34> D0FIFO0;
			rw8_t<base + 35> D1FIFO0;

			rw8_t<base + 38> SPRI0;
			rw8_t<base + 39> SPTI0;

			rw8_t<base + 52> RIIC_RXI0;
			rw8_t<base + 53> RIIC_TXI0;

			rw8_t<base + 60> RXI1;
			rw8_t<base + 61> TXI1;

			rw8_t<base + 64> IRQ0;
			rw8_t<base + 65> IRQ1;
			rw8_t<base + 66> IRQ2;
			rw8_t<base + 67> IRQ3;
			rw8_t<base + 68> IRQ4;
			rw8_t<base + 69> IRQ5;
			rw8_t<base + 70> IRQ6;
			rw8_t<base + 71> IRQ7;
			rw8_t<base + 72> IRQ8;
			rw8_t<base + 73> IRQ9;
			rw8_t<base + 74> IRQ10;
			rw8_t<base + 75> IRQ11;
			rw8_t<base + 76> IRQ12;
			rw8_t<base + 77> IRQ13;
			rw8_t<base + 78> IRQ14;
			rw8_t<base + 79> IRQ15;

			rw8_t<base + 84 > RXI5;
			rw8_t<base + 85 > TXI5;
			rw8_t<base + 86 > RXI6;
			rw8_t<base + 87 > TXI6;
			rw8_t<base + 88 > LVD1;
			rw8_t<base + 89 > LVD2;
			rw8_t<base + 90 > USBR0;

			rw8_t<base + 95 > IWUNI;
			rw8_t<base + 96 > WUNI;

			rw8_t<base + 100> RXI8;
			rw8_t<base + 101> TXI8;
			rw8_t<base + 102> RXI9;
			rw8_t<base + 103> TXI9;

			rw8_t<base + 106> GROUPBE0;

			rw8_t<base + 110> GROUPBL0;
			rw8_t<base + 111> GROUPBL1;
			rw8_t<base + 112> GROUPAL0;

			rw8_t<base + 114> RXI11;
			rw8_t<base + 115> TXI11;
			rw8_t<base + 116> RXI12;
			rw8_t<base + 117> TXI12;

			rw8_t<base + 120> DMAC0I;
			rw8_t<base + 121> DMAC1I;
			rw8_t<base + 122> DMAC2I;
			rw8_t<base + 123> DMAC3I;
			rw8_t<base + 124> DMAC74I;
			rw8_t<base + 125> OSTDI;

			rw8_t<base + 128> S12ADI;
			rw8_t<base + 129> S12GBADI;
			rw8_t<base + 130> S12GCADI;

			rw8_t<base + 132> S12ADI1;
			rw8_t<base + 133> S12GBADI1;
			rw8_t<base + 134> S12GCADI1;

			rw8_t<base + 136> S12ADI2;
			rw8_t<base + 137> S12GBADI2;
			rw8_t<base + 138> S12GCADI2;

			rw8_t<base + 146> CMIA0;
			rw8_t<base + 147> CMIB0;
			rw8_t<base + 148> OVI0;
			rw8_t<base + 149> CMIA1;
			rw8_t<base + 150> CMIB1;
			rw8_t<base + 151> OVI1;
			rw8_t<base + 152> CMIA2;
			rw8_t<base + 153> CMIB2;
			rw8_t<base + 154> OVI2;
			rw8_t<base + 155> CMIA3;
			rw8_t<base + 156> CMIB3;
			rw8_t<base + 157> OVI3;
			rw8_t<base + 158> CMIA4;
			rw8_t<base + 159> CMIB4;
			rw8_t<base + 160> OVI4;
			rw8_t<base + 161> CMIA5;
			rw8_t<base + 162> CMIB5;
			rw8_t<base + 163> OVI5;
			rw8_t<base + 164> CMIA6;
			rw8_t<base + 165> CMIB6;
			rw8_t<base + 166> OVI6;
			rw8_t<base + 167> CMIA7;
			rw8_t<base + 168> CMIB7;
			rw8_t<base + 169> OVI7;

			rw8_t<base + 170> RXF0;		///< CAN0
			rw8_t<base + 171> TXF0;
			rw8_t<base + 172> RXM0;
			rw8_t<base + 173> TXM0;
			rw8_t<base + 174> USBI0;

			rw8_t<base + 175> ELSR18I;
			rw8_t<base + 176> ELSR19I;

			rw8_t<base + 177> RD;
			rw8_t<base + 178> WR;
			rw8_t<base + 179> ERR;

			rw8_t<base + 180> CMPC0;
			rw8_t<base + 181> CMPC1;
			rw8_t<base + 182> CMPC2;
			rw8_t<base + 183> CMPC3;
			rw8_t<base + 184> CMPC4;
			rw8_t<base + 185> CMPC5;

			rw8_t<base + 208> INTA208;
			rw8_t<base + 209> INTA209;
			rw8_t<base + 210> INTA210;
			rw8_t<base + 211> INTA211;
			rw8_t<base + 212> INTA212;
			rw8_t<base + 213> INTA213;
			rw8_t<base + 214> INTA214;

			rw8_t<base + 215> INTA215;
			rw8_t<base + 216> INTA216;
			rw8_t<base + 217> INTA217;
			rw8_t<base + 218> INTA218;
			rw8_t<base + 219> INTA219;
			rw8_t<base + 220> INTA220;
			rw8_t<base + 221> INTA221;
			rw8_t<base + 222> INTA222;
			rw8_t<base + 223> INTA223;
			rw8_t<base + 224> INTA224;
			rw8_t<base + 225> INTA225;
			rw8_t<base + 226> INTA226;
			rw8_t<base + 227> INTA227;
			rw8_t<base + 228> INTA228;
			rw8_t<base + 229> INTA229;
			rw8_t<base + 230> INTA230;
			rw8_t<base + 231> INTA231;
			rw8_t<base + 232> INTA232;
			rw8_t<base + 233> INTA233;
			rw8_t<base + 234> INTA234;
			rw8_t<base + 235> INTA235;
			rw8_t<base + 236> INTA236;
			rw8_t<base + 237> INTA237;
			rw8_t<base + 238> INTA238;
			rw8_t<base + 239> INTA239;
			rw8_t<base + 240> INTA240;
			rw8_t<base + 241> INTA241;
			rw8_t<base + 242> INTA242;
			rw8_t<base + 243> INTA243;
			rw8_t<base + 244> INTA244;
			rw8_t<base + 245> INTA245;
			rw8_t<base + 246> INTA246;
			rw8_t<base + 247> INTA247;
			rw8_t<base + 248> INTA248;
			rw8_t<base + 249> INTA249;
			rw8_t<base + 250> INTA250;
			rw8_t<base + 251> INTA251;
			rw8_t<base + 252> INTA252;
			rw8_t<base + 253> INTA253;
			rw8_t<base + 254> INTA254;
			rw8_t<base + 255> INTA255;


			//-------------------------------------------------------------//
			/*!
				@brief  []オペレータ
				@param[in]	idx		インデックス（０～２５５）
				@return IR レジスターの参照
			*/
			//-------------------------------------------------------------//
			volatile uint8_t& operator [] (uint8_t idx) {
				return *reinterpret_cast<volatile uint8_t*>(base + idx);
			}
		};
		typedef ir_t_<0x00087010> ir_t;
		static ir_t IR;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  IER レジスタ
			@param[in]	base	ベース・アドレス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t base>
		struct ier_t_ {

			typedef rw8_t<base + 0x02> ier02;
			bit_rw_t<ier02, bitpos::B0>	BUSERR;
			bit_rw_t<ier02, bitpos::B2>	RAMERR;
			bit_rw_t<ier02, bitpos::B5>	FIFERR;
			bit_rw_t<ier02, bitpos::B7>	FRDYI;

			typedef rw8_t<base + 0x03> ier03;
			bit_rw_t<ier03, bitpos::B2>	SWINT2;
			bit_rw_t<ier03, bitpos::B3>	SWINT;
			bit_rw_t<ier03, bitpos::B4>	CMI0;
			bit_rw_t<ier03, bitpos::B5>	CMI1;
			bit_rw_t<ier03, bitpos::B6>	CMI2;
			bit_rw_t<ier03, bitpos::B7>	CMI3;

			typedef rw8_t<base + 0x04> ier04;
			bit_rw_t<ier04, bitpos::B2>	D0FIFO0;
			bit_rw_t<ier04, bitpos::B3>	D1FIFO0;

			bit_rw_t<ier04, bitpos::B6>	SPRI0;
			bit_rw_t<ier04, bitpos::B7>	SPTI0;

			typedef rw8_t<base + 0x06> ier06;
			bit_rw_t<ier06, bitpos::B4>	RIIC_RXI0;
			bit_rw_t<ier06, bitpos::B5>	RIIC_TXI0;

			typedef rw8_t<base + 0x07> ier07;
			bit_rw_t<ier07, bitpos::B4>	RXI1;
			bit_rw_t<ier07, bitpos::B5>	TXI1;

			typedef rw8_t<base + 0x08> ier08;
			bit_rw_t<ier08, bitpos::B0>	IRQ0;
			bit_rw_t<ier08, bitpos::B1>	IRQ1;
			bit_rw_t<ier08, bitpos::B2>	IRQ2;
			bit_rw_t<ier08, bitpos::B3>	IRQ3;
			bit_rw_t<ier08, bitpos::B4>	IRQ4;
			bit_rw_t<ier08, bitpos::B5>	IRQ5;
			bit_rw_t<ier08, bitpos::B6>	IRQ6;
			bit_rw_t<ier08, bitpos::B7>	IRQ7;
			typedef rw8_t<base + 0x09> ier09;
			bit_rw_t<ier09, bitpos::B0>	IRQ8;
			bit_rw_t<ier09, bitpos::B1>	IRQ9;
			bit_rw_t<ier09, bitpos::B2>	IRQ10;
			bit_rw_t<ier09, bitpos::B3>	IRQ11;
			bit_rw_t<ier09, bitpos::B4>	IRQ12;
			bit_rw_t<ier09, bitpos::B5>	IRQ13;
			bit_rw_t<ier09, bitpos::B6>	IRQ14;
			bit_rw_t<ier09, bitpos::B7>	IRQ15;

			typedef rw8_t<base + 0x0A> ier0A;
			bit_rw_t<ier0A, bitpos::B4>	RXI5;
			bit_rw_t<ier0A, bitpos::B5>	TXI5;
			bit_rw_t<ier0A, bitpos::B6>	RXI6;
			bit_rw_t<ier0A, bitpos::B7>	TXI6;

			typedef rw8_t<base + 0x0B> ier0B;
			bit_rw_t<ier0B, bitpos::B0>	LVD1;
			bit_rw_t<ier0B, bitpos::B1>	LVD2;
			bit_rw_t<ier0B, bitpos::B2>	USBR0;

			bit_rw_t<ier0B, bitpos::B7>	IWUNI;
			typedef rw8_t<base + 0x0C> ier0C;
			bit_rw_t<ier0C, bitpos::B0>	WUNI;

			bit_rw_t<ier0C, bitpos::B4>	RXI8;
			bit_rw_t<ier0C, bitpos::B5>	TXI8;
			bit_rw_t<ier0C, bitpos::B6>	RXI9;
			bit_rw_t<ier0C, bitpos::B7>	TXI9;

			typedef rw8_t<base + 0x0D> ier0D;
			bit_rw_t<ier0D, bitpos::B2>	GROUPBE0;

			bit_rw_t<ier0D, bitpos::B6>	GROUPBL0;
			bit_rw_t<ier0D, bitpos::B7>	GROUPBL1;
			typedef rw8_t<base + 0x0E> ier0E;
			bit_rw_t<ier0E, bitpos::B0>	GROUPAL0;

			bit_rw_t<ier0E, bitpos::B2>	RXI11;
			bit_rw_t<ier0E, bitpos::B3>	TXI11;
			bit_rw_t<ier0E, bitpos::B4>	RXI12;
			bit_rw_t<ier0E, bitpos::B5>	TXI12;

			typedef rw8_t<base + 0x0F> ier0F;
			bit_rw_t<ier0F, bitpos::B0>	DMAC0I;
			bit_rw_t<ier0F, bitpos::B1>	DMAC1I;
			bit_rw_t<ier0F, bitpos::B2>	DMAC2I;
			bit_rw_t<ier0F, bitpos::B3>	DMAC3I;
			bit_rw_t<ier0F, bitpos::B4>	DMAC74I;

			bit_rw_t<ier0F, bitpos::B5>	OSTDI;

			typedef rw8_t<base + 0x10> ier10;
			bit_rw_t<ier10, bitpos::B0>	S12ADI;
			bit_rw_t<ier10, bitpos::B1>	S12GBADI;
			bit_rw_t<ier10, bitpos::B2>	S12GCADI;

			bit_rw_t<ier10, bitpos::B4>	S12ADI1;
			bit_rw_t<ier10, bitpos::B5>	S12GBADI1;
			bit_rw_t<ier10, bitpos::B6>	S12GCADI1;

			typedef rw8_t<base + 0x11> ier11;
			bit_rw_t<ier11, bitpos::B0>	S12ADI2;
			bit_rw_t<ier11, bitpos::B1>	S12GBADI2;
			bit_rw_t<ier11, bitpos::B2>	S12GCADI2;

			typedef rw8_t<base + 0x12> ier12;
			bit_rw_t<ier12, bitpos::B2>	CMIA0;
			bit_rw_t<ier12, bitpos::B3>	CMIB0;
			bit_rw_t<ier12, bitpos::B4>	OVI0;
			bit_rw_t<ier12, bitpos::B5>	CMIA1;
			bit_rw_t<ier12, bitpos::B6>	CMIB1;
			bit_rw_t<ier12, bitpos::B7>	OVI1;
			typedef rw8_t<base + 0x13> ier13;
			bit_rw_t<ier13, bitpos::B0>	CMIA2;
			bit_rw_t<ier13, bitpos::B1>	CMIB2;
			bit_rw_t<ier13, bitpos::B2>	OVI2;
			bit_rw_t<ier13, bitpos::B3>	CMIA3;
			bit_rw_t<ier13, bitpos::B4>	CMIB3;
			bit_rw_t<ier13, bitpos::B5>	OVI3;
			bit_rw_t<ier13, bitpos::B6>	CMIA4;
			bit_rw_t<ier13, bitpos::B7>	CMIB4;
			typedef rw8_t<base + 0x14> ier14;
			bit_rw_t<ier14, bitpos::B0>	OVI4;
			bit_rw_t<ier14, bitpos::B1>	CMIA5;
			bit_rw_t<ier14, bitpos::B2>	CMIB5;
			bit_rw_t<ier14, bitpos::B3>	OVI5;
			bit_rw_t<ier14, bitpos::B4>	CMIA6;
			bit_rw_t<ier14, bitpos::B5>	CMIB6;
			bit_rw_t<ier14, bitpos::B6>	OVI6;
			bit_rw_t<ier14, bitpos::B7>	CMIA7;
			typedef rw8_t<base + 0x15> ier15;
			bit_rw_t<ier15, bitpos::B0>	CMIB7;
			bit_rw_t<ier15, bitpos::B1>	OVI7;
			bit_rw_t<ier15, bitpos::B2>	RXF0;
			bit_rw_t<ier15, bitpos::B3>	TXF0;
			bit_rw_t<ier15, bitpos::B4>	RXM0;
			bit_rw_t<ier15, bitpos::B5>	TXM0;
			bit_rw_t<ier15, bitpos::B6>	USBI0;
			bit_rw_t<ier15, bitpos::B7>	ELSR18I;
			typedef rw8_t<base + 0x16> ier16;
			bit_rw_t<ier16, bitpos::B0>	ELSR19I;
			bit_rw_t<ier16, bitpos::B1>	RD;
			bit_rw_t<ier16, bitpos::B2>	WR;
			bit_rw_t<ier16, bitpos::B3>	ERR;
			bit_rw_t<ier16, bitpos::B4>	CMPC0;
			bit_rw_t<ier16, bitpos::B5>	CMPC1;
			bit_rw_t<ier16, bitpos::B6>	CMPC2;
			bit_rw_t<ier16, bitpos::B7>	CMPC3;
			typedef rw8_t<base + 0x17> ier17;
			bit_rw_t<ier17, bitpos::B0>	CMPC4;
			bit_rw_t<ier17, bitpos::B1>	CMPC5;

			typedef rw8_t<base + 0x1A> ier1A;
			bit_rw_t<ier1A, bitpos::B0>	INTA208;
			bit_rw_t<ier1A, bitpos::B1>	INTA209;
			bit_rw_t<ier1A, bitpos::B2>	INTA210;
			bit_rw_t<ier1A, bitpos::B3>	INTA211;
			bit_rw_t<ier1A, bitpos::B4>	INTA212;
			bit_rw_t<ier1A, bitpos::B5>	INTA213;
			bit_rw_t<ier1A, bitpos::B6>	INTA214;
			bit_rw_t<ier1A, bitpos::B7>	INTA215;
			typedef rw8_t<base + 0x1B> ier1B;
			bit_rw_t<ier1B, bitpos::B0>	INTA216;
			bit_rw_t<ier1B, bitpos::B1>	INTA217;
			bit_rw_t<ier1B, bitpos::B2>	INTA218;
			bit_rw_t<ier1B, bitpos::B3>	INTA219;
			bit_rw_t<ier1B, bitpos::B4>	INTA220;
			bit_rw_t<ier1B, bitpos::B5>	INTA221;
			bit_rw_t<ier1B, bitpos::B6>	INTA222;
			bit_rw_t<ier1B, bitpos::B7>	INTA223;
			typedef rw8_t<base + 0x1C> ier1C;
			bit_rw_t<ier1C, bitpos::B0>	INTA224;
			bit_rw_t<ier1C, bitpos::B1>	INTA225;
			bit_rw_t<ier1C, bitpos::B2>	INTA226;
			bit_rw_t<ier1C, bitpos::B3>	INTA227;
			bit_rw_t<ier1C, bitpos::B4>	INTA228;
			bit_rw_t<ier1C, bitpos::B5>	INTA229;
			bit_rw_t<ier1C, bitpos::B6>	INTA230;
			bit_rw_t<ier1C, bitpos::B7>	INTA231;
			typedef rw8_t<base + 0x1D> ier1D;
			bit_rw_t<ier1D, bitpos::B0>	INTA232;
			bit_rw_t<ier1D, bitpos::B1>	INTA233;
			bit_rw_t<ier1D, bitpos::B2>	INTA234;
			bit_rw_t<ier1D, bitpos::B3>	INTA235;
			bit_rw_t<ier1D, bitpos::B4>	INTA236;
			bit_rw_t<ier1D, bitpos::B5>	INTA237;
			bit_rw_t<ier1D, bitpos::B6>	INTA238;
			bit_rw_t<ier1D, bitpos::B7>	INTA239;
			typedef rw8_t<base + 0x1E> ier1E;
			bit_rw_t<ier1E, bitpos::B0>	INTA240;
			bit_rw_t<ier1E, bitpos::B1>	INTA241;
			bit_rw_t<ier1E, bitpos::B2>	INTA242;
			bit_rw_t<ier1E, bitpos::B3>	INTA243;
			bit_rw_t<ier1E, bitpos::B4>	INTA244;
			bit_rw_t<ier1E, bitpos::B5>	INTA245;
			bit_rw_t<ier1E, bitpos::B6>	INTA246;
			bit_rw_t<ier1E, bitpos::B7>	INTA247;
			typedef rw8_t<base + 0x1F> ier1F;
			bit_rw_t<ier1F, bitpos::B0>	INTA248;
			bit_rw_t<ier1F, bitpos::B1>	INTA249;
			bit_rw_t<ier1F, bitpos::B2>	INTA250;
			bit_rw_t<ier1F, bitpos::B3>	INTA251;
			bit_rw_t<ier1F, bitpos::B4>	INTA252;
			bit_rw_t<ier1F, bitpos::B5>	INTA253;
			bit_rw_t<ier1F, bitpos::B6>	INTA254;
			bit_rw_t<ier1F, bitpos::B7>	INTA255;


			//-------------------------------------------------------------//
			/*!
				@brief  許可、不許可
				@param[in]	idx		インデックス（０～２５５）
				@param[in]	ena		許可／不許可
			*/
			//-------------------------------------------------------------//
			void enable(uint8_t idx, bool ena) noexcept
			{
				auto tmp = rd8_(base + (idx >> 3));
				if(ena) {
					tmp |=   1 << (idx & 7);
				} else {
					tmp &= ~(1 << (idx & 7));
				}
				wr8_(base + (idx >> 3), tmp);
			}


			//-------------------------------------------------------------//
			/*!
				@brief  許可状態を取得
				@param[in]	idx		インデックス（０～２５５）
				@return 許可状態（許可の場合「true」）
			*/
			//-------------------------------------------------------------//
			bool get(uint8_t idx) const noexcept
			{
				auto tmp = rd8_(base + (idx >> 3));
				return tmp & (1 << (idx & 7));
			}
		};
		typedef ier_t_<0x00087200> ier_t;
		static ier_t IER;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  IPR レジスタ @n
					全て、下位４ビットが有効
			@param[in]	base	ベース・アドレス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t base>
		struct ipr_t_ {

			rw8_t<base + 0  > BUSERR;

			rw8_t<base + 0  > RAMERR;

			rw8_t<base + 1  > FIFERR;

			rw8_t<base + 2  > FRDYI;

			rw8_t<base + 3  > SWINT2;
			rw8_t<base + 3  > SWINT;

			rw8_t<base + 4  > CMI0;
			rw8_t<base + 5  > CMI1;
			rw8_t<base + 6  > CMI2;
			rw8_t<base + 7  > CMI3;

			rw8_t<base + 34 > D0FIFO0;
			rw8_t<base + 35 > D1FIFO0;

			rw8_t<base + 38 > SPRI0;
			rw8_t<base + 39 > SPTI0;

			rw8_t<base + 52 > RIIC_RXI0;
			rw8_t<base + 53 > RIIC_TXI0;

			rw8_t<base + 60 > RXI1;
			rw8_t<base + 61 > TXI1;

			rw8_t<base + 64 > IRQ0;
			rw8_t<base + 65 > IRQ1;
			rw8_t<base + 66 > IRQ2;
			rw8_t<base + 67 > IRQ3;
			rw8_t<base + 68 > IRQ4;
			rw8_t<base + 69 > IRQ5;
			rw8_t<base + 70 > IRQ6;
			rw8_t<base + 71 > IRQ7;
			rw8_t<base + 72 > IRQ8;
			rw8_t<base + 73 > IRQ9;
			rw8_t<base + 74 > IRQ10;
			rw8_t<base + 75 > IRQ11;
			rw8_t<base + 76 > IRQ12;
			rw8_t<base + 77 > IRQ13;
			rw8_t<base + 78 > IRQ14;
			rw8_t<base + 79 > IRQ15;

			rw8_t<base + 84 > RXI5;
			rw8_t<base + 85 > TXI5;
			rw8_t<base + 86 > RXI6;
			rw8_t<base + 87 > TXI6;
			rw8_t<base + 88 > LVD1;
			rw8_t<base + 89 > LVD2;
			rw8_t<base + 90 > USBR0;

			rw8_t<base + 95 > IWUNI;
			rw8_t<base + 96 > WUNI;

			rw8_t<base + 100> RXI8;
			rw8_t<base + 101> TXI8;
			rw8_t<base + 102> RXI9;
			rw8_t<base + 103> TXI9;

			rw8_t<base + 106> GROUPBE0;

			rw8_t<base + 110> GROUPBL0;
			rw8_t<base + 111> GROUPBL1;
			rw8_t<base + 112> GROUPAL0;

			rw8_t<base + 114> RXI11;
			rw8_t<base + 115> TXI11;
			rw8_t<base + 116> RXI12;
			rw8_t<base + 117> TXI12;

			rw8_t<base + 120> DMAC0I;
			rw8_t<base + 121> DMAC1I;
			rw8_t<base + 122> DMAC2I;
			rw8_t<base + 123> DMAC3I;
			rw8_t<base + 124> DMAC74I;
			rw8_t<base + 125> OSTDI;

			rw8_t<base + 128> S12ADI;   ///< S12AD
			rw8_t<base + 129> S12GBADI;
			rw8_t<base + 130> S12GCADI;

			rw8_t<base + 132> S12ADI1;  ///< S12AD1
			rw8_t<base + 133> S12GBADI1;
			rw8_t<base + 134> S12GCADI1;

			rw8_t<base + 136> S12ADI2;  ///< S12AD2
			rw8_t<base + 137> S12GBADI2;
			rw8_t<base + 138> S12GCADI2;

			rw8_t<base + 146> CMIA0;	///< TMR0
			rw8_t<base + 146> CMIB0;
			rw8_t<base + 146> OVI0;
			rw8_t<base + 149> CMIA1;	///< TMR1
			rw8_t<base + 149> CMIB1;
			rw8_t<base + 149> OVI1;
			rw8_t<base + 152> CMIA2;	///< TMR2
			rw8_t<base + 152> CMIB2;
			rw8_t<base + 152> OVI2;
			rw8_t<base + 155> CMIA3;	///< TMR3
			rw8_t<base + 155> CMIB3;
			rw8_t<base + 155> OVI3;
			rw8_t<base + 158> CMIA4;	///< TMR4
			rw8_t<base + 158> CMIB4;
			rw8_t<base + 158> OVI4;
			rw8_t<base + 161> CMIA5;	///< TMR5
			rw8_t<base + 161> CMIB5;
			rw8_t<base + 161> OVI5;
			rw8_t<base + 164> CMIA6;	///< TMR6
			rw8_t<base + 164> CMIB6;
			rw8_t<base + 164> OVI6;
			rw8_t<base + 167> CMIA7;	///< TMR7
			rw8_t<base + 167> CMIB7;
			rw8_t<base + 167> OVI7;

			rw8_t<base + 170> RXF0;
			rw8_t<base + 170> TXF0;
			rw8_t<base + 170> RXM0;
			rw8_t<base + 170> TXM0;

			rw8_t<base + 174> USBI0;

			rw8_t<base + 175> ELSR18I;
			rw8_t<base + 176> ELSR19I;

			rw8_t<base + 177> RD;
			rw8_t<base + 177> WR;
			rw8_t<base + 179> ERR;

			rw8_t<base + 180> CMPC0;
			rw8_t<base + 181> CMPC1;
			rw8_t<base + 182> CMPC2;
			rw8_t<base + 183> CMPC3;
			rw8_t<base + 184> CMPC4;
			rw8_t<base + 185> CMPC5;

			rw8_t<base + 208> INTA208;
			rw8_t<base + 209> INTA209;
			rw8_t<base + 210> INTA210;
			rw8_t<base + 211> INTA211;
			rw8_t<base + 212> INTA212;
			rw8_t<base + 213> INTA213;
			rw8_t<base + 214> INTA214;
			rw8_t<base + 215> INTA215;
			rw8_t<base + 216> INTA216;
			rw8_t<base + 217> INTA217;
			rw8_t<base + 218> INTA218;
			rw8_t<base + 219> INTA219;
			rw8_t<base + 220> INTA220;
			rw8_t<base + 221> INTA221;
			rw8_t<base + 222> INTA222;
			rw8_t<base + 223> INTA223;
			rw8_t<base + 224> INTA224;
			rw8_t<base + 225> INTA225;
			rw8_t<base + 226> INTA226;
			rw8_t<base + 227> INTA227;
			rw8_t<base + 228> INTA228;
			rw8_t<base + 229> INTA229;
			rw8_t<base + 230> INTA230;
			rw8_t<base + 231> INTA231;
			rw8_t<base + 232> INTA232;
			rw8_t<base + 233> INTA233;
			rw8_t<base + 234> INTA234;
			rw8_t<base + 235> INTA235;
			rw8_t<base + 236> INTA236;
			rw8_t<base + 237> INTA237;
			rw8_t<base + 238> INTA238;
			rw8_t<base + 239> INTA239;
			rw8_t<base + 240> INTA240;
			rw8_t<base + 241> INTA241;
			rw8_t<base + 242> INTA242;
			rw8_t<base + 243> INTA243;
			rw8_t<base + 244> INTA244;
			rw8_t<base + 245> INTA245;
			rw8_t<base + 246> INTA246;
			rw8_t<base + 247> INTA247;
			rw8_t<base + 248> INTA248;
			rw8_t<base + 249> INTA249;
			rw8_t<base + 250> INTA250;
			rw8_t<base + 251> INTA251;
			rw8_t<base + 252> INTA252;
			rw8_t<base + 253> INTA253;
			rw8_t<base + 254> INTA254;
			rw8_t<base + 255> INTA255;


			//-------------------------------------------------------------//
			/*!
				@brief  []オペレータ
				@param[in]	idx		インデックス（０～２５５）
				@return IR レジスターの参照
			*/
			//-------------------------------------------------------------//
			volatile uint8_t& operator [] (uint8_t idx) {
				return *reinterpret_cast<volatile uint8_t*>(base + idx);
			}
		};
		typedef ipr_t_<0x00087300> ipr_t;
		static ipr_t IPR;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  DMAC 起動要因選択レジスタ m（DMRSRm）（m = DMAC チャネル番号）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		typedef rw8_t<0x00087400> dmrsr0_t;
		static dmrsr0_t DMRSR0;
		typedef rw8_t<0x00087404> dmrsr1_t;
		static dmrsr1_t DMRSR1;
		typedef rw8_t<0x00087408> dmrsr2_t;
		static dmrsr2_t DMRSR2;
		typedef rw8_t<0x0008740C> dmrsr3_t;
		static dmrsr3_t DMRSR3;
		typedef rw8_t<0x00087410> dmrsr4_t;
		static dmrsr4_t DMRSR4;
		typedef rw8_t<0x00087414> dmrsr5_t;
		static dmrsr5_t DMRSR5;
		typedef rw8_t<0x00087418> dmrsr6_t;
		static dmrsr6_t DMRSR6;
		typedef rw8_t<0x0008741C> dmrsr7_t;
		static dmrsr7_t DMRSR7;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  IRQ コントロールレジスタ i（IRQCRi）（i = 0 ～ 15）
			@param[in]	base	ベースアドレス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t base>
		struct irqcr_t : public rw8_t<base> {
			typedef rw8_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B2, 2>  IRQMD;
		};
		static irqcr_t<0x00087500>  IRQCR0;
		static irqcr_t<0x00087501>  IRQCR1;
		static irqcr_t<0x00087502>  IRQCR2;
		static irqcr_t<0x00087503>  IRQCR3;
		static irqcr_t<0x00087504>  IRQCR4;
		static irqcr_t<0x00087505>  IRQCR5;
		static irqcr_t<0x00087506>  IRQCR6;
		static irqcr_t<0x00087507>  IRQCR7;
		static irqcr_t<0x00087508>  IRQCR8;
		static irqcr_t<0x00087509>  IRQCR9;
		static irqcr_t<0x0008750A>  IRQCR10;
		static irqcr_t<0x0008750B>  IRQCR11;
		static irqcr_t<0x0008750C>  IRQCR12;
		static irqcr_t<0x0008750D>  IRQCR13;
		static irqcr_t<0x0008750E>  IRQCR14;
		static irqcr_t<0x0008750F>  IRQCR15;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  IRQ 端子デジタルフィルタ許可レジスタ 0（IRQFLTE0）
			@param[in]	base	ベースアドレス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t base>
		struct irqflte0_t_ : public rw8_t<base> {
			typedef rw8_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> FLTEN0;
			bit_rw_t<io_, bitpos::B1> FLTEN1;
			bit_rw_t<io_, bitpos::B2> FLTEN2;
			bit_rw_t<io_, bitpos::B3> FLTEN3;
			bit_rw_t<io_, bitpos::B4> FLTEN4;
			bit_rw_t<io_, bitpos::B5> FLTEN5;
			bit_rw_t<io_, bitpos::B6> FLTEN6;
			bit_rw_t<io_, bitpos::B7> FLTEN7;
		};
		typedef irqflte0_t_<0x00087520> irqflte0_t;
		static irqflte0_t IRQFLTE0;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  IRQ 端子デジタルフィルタ許可レジスタ 1（IRQFLTE1）
			@param[in]	base	ベースアドレス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t base>
		struct irqflte1_t_ : public rw8_t<base> {
			typedef rw8_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t<io_, bitpos::B0> FLTEN8;
			bit_rw_t<io_, bitpos::B1> FLTEN9;
			bit_rw_t<io_, bitpos::B2> FLTEN10;
			bit_rw_t<io_, bitpos::B3> FLTEN11;
			bit_rw_t<io_, bitpos::B4> FLTEN12;
			bit_rw_t<io_, bitpos::B5> FLTEN13;
			bit_rw_t<io_, bitpos::B6> FLTEN14;
			bit_rw_t<io_, bitpos::B7> FLTEN15;
		};
		typedef irqflte1_t_<0x00087521> irqflte1_t;
		static irqflte1_t IRQFLTE1;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief	IRQ 端子デジタルフィルタ設定レジスタ 0（IRQFLTC0）
			@param[in]	base	ベースアドレス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t base>
		struct irqfltc0_t_ : public rw16_t<base> {
			typedef rw16_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0,  2> FCLKSEL0;
			bits_rw_t<io_, bitpos::B2,  2> FCLKSEL1;
			bits_rw_t<io_, bitpos::B4,  2> FCLKSEL2;
			bits_rw_t<io_, bitpos::B6,  2> FCLKSEL3;
			bits_rw_t<io_, bitpos::B8,  2> FCLKSEL4;
			bits_rw_t<io_, bitpos::B10, 2> FCLKSEL5;
			bits_rw_t<io_, bitpos::B12, 2> FCLKSEL6;
			bits_rw_t<io_, bitpos::B14, 2> FCLKSEL7;
		};
		typedef irqfltc0_t_<0x00087528> irqfltc0_t;
		static irqfltc0_t IRQFLTC0;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief	IRQ 端子デジタルフィルタ設定レジスタ 1（IRQFLTC1）
			@param[in]	base	ベースアドレス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t base>
		struct irqfltc1_t_ : public rw16_t<base> {
			typedef rw16_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bits_rw_t<io_, bitpos::B0,  2> FCLKSEL8;
			bits_rw_t<io_, bitpos::B2,  2> FCLKSEL9;
			bits_rw_t<io_, bitpos::B4,  2> FCLKSEL10;
			bits_rw_t<io_, bitpos::B6,  2> FCLKSEL11;
			bits_rw_t<io_, bitpos::B8,  2> FCLKSEL12;
			bits_rw_t<io_, bitpos::B10, 2> FCLKSEL13;
			bits_rw_t<io_, bitpos::B12, 2> FCLKSEL14;
			bits_rw_t<io_, bitpos::B14, 2> FCLKSEL15;
		};
		typedef irqfltc1_t_<0x0008752A> irqfltc1_t;
		static irqfltc1_t IRQFLTC1;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  グループ割り込み要求レジスタ
			@param[in]	base	ベースアドレス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t base>
		struct grp_t_ : public ro32_t<base> {
			typedef ro32_t<base> io_;
			using io_::operator ();

			bit_ro_t <io_, bitpos::B0>  IS0;
			bit_ro_t <io_, bitpos::B1>  IS1;
			bit_ro_t <io_, bitpos::B2>  IS2;
			bit_ro_t <io_, bitpos::B3>  IS3;
			bit_ro_t <io_, bitpos::B4>  IS4;
			bit_ro_t <io_, bitpos::B5>  IS5;
			bit_ro_t <io_, bitpos::B6>  IS6;
			bit_ro_t <io_, bitpos::B7>  IS7;

			bit_ro_t <io_, bitpos::B8>  IS8;
			bit_ro_t <io_, bitpos::B9>  IS9;
			bit_ro_t <io_, bitpos::B10> IS10;
			bit_ro_t <io_, bitpos::B11> IS11;
			bit_ro_t <io_, bitpos::B12> IS12;
			bit_ro_t <io_, bitpos::B13> IS13;
			bit_ro_t <io_, bitpos::B14> IS14;
			bit_ro_t <io_, bitpos::B15> IS15;

			bit_ro_t <io_, bitpos::B16> IS16;
			bit_ro_t <io_, bitpos::B17> IS17;
			bit_ro_t <io_, bitpos::B18> IS18;
			bit_ro_t <io_, bitpos::B19> IS19;
			bit_ro_t <io_, bitpos::B20> IS20;
			bit_ro_t <io_, bitpos::B21> IS21;
			bit_ro_t <io_, bitpos::B22> IS22;
			bit_ro_t <io_, bitpos::B23> IS23;

			bit_ro_t <io_, bitpos::B24> IS24;
			bit_ro_t <io_, bitpos::B25> IS25;
			bit_ro_t <io_, bitpos::B26> IS26;
			bit_ro_t <io_, bitpos::B27> IS27;
			bit_ro_t <io_, bitpos::B28> IS28;
			bit_ro_t <io_, bitpos::B29> IS29;
			bit_ro_t <io_, bitpos::B30> IS30;
			bit_ro_t <io_, bitpos::B31> IS31;
		};


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  グループ BE0 割り込み要求レジスタ（GRPBE0）@n
					グループ BL0/1 割り込み要求レジスタ（GRPBL0/GRPBL1）@n
					グループ AL0/1 割り込み要求レジスタ（GRPAL0/GRPAL1）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		typedef grp_t_<0x00087600> grpbe0_t;
		static grpbe0_t GRPBE0;
		typedef grp_t_<0x00087630> grpbl0_t;
		static grpbl0_t GRPBL0;
		typedef grp_t_<0x00087634> grpbl1_t;
		static grpbl1_t GRPBL1;
		typedef grp_t_<0x00087830> grpal0_t;
		static grpal0_t GRPAL0;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  グループ割り込み要求許可レジスタ
			@param[in]	base	ベースアドレス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t base>
		struct gen_t_ : public rw32_t<base> {
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
			bit_rw_t<io_, bitpos::B6>  EN6;
			bit_rw_t<io_, bitpos::B7>  EN7;

			bit_rw_t<io_, bitpos::B8>  EN8;
			bit_rw_t<io_, bitpos::B9>  EN9;
			bit_rw_t<io_, bitpos::B10> EN10;
			bit_rw_t<io_, bitpos::B11> EN11;
			bit_rw_t<io_, bitpos::B12> EN12;
			bit_rw_t<io_, bitpos::B13> EN13;
			bit_rw_t<io_, bitpos::B14> EN14;
			bit_rw_t<io_, bitpos::B15> EN15;

			bit_rw_t<io_, bitpos::B16> EN16;
			bit_rw_t<io_, bitpos::B17> EN17;
			bit_rw_t<io_, bitpos::B18> EN18;
			bit_rw_t<io_, bitpos::B19> EN19;
			bit_rw_t<io_, bitpos::B20> EN20;
			bit_rw_t<io_, bitpos::B21> EN21;
			bit_rw_t<io_, bitpos::B22> EN22;
			bit_rw_t<io_, bitpos::B23> EN23;

			bit_rw_t<io_, bitpos::B24> EN24;
			bit_rw_t<io_, bitpos::B25> EN25;
			bit_rw_t<io_, bitpos::B26> EN26;
			bit_rw_t<io_, bitpos::B27> EN27;
			bit_rw_t<io_, bitpos::B28> EN28;
			bit_rw_t<io_, bitpos::B29> EN29;
			bit_rw_t<io_, bitpos::B30> EN30;
			bit_rw_t<io_, bitpos::B31> EN31;
		};


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  グループ BE0 割り込み要求許可レジスタ（GENBE0）@n
					グループ BL0/1 割り込み要求許可レジスタ（GENBL0/GENBL1/GENBL2）@n
					グループ AL0/1 割り込み要求許可レジスタ（GENAL0/GENAL1）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		typedef gen_t_<0x00087640> genbe0_t;
		static genbe0_t GENBE0;
		typedef gen_t_<0x00087670> genbl0_t;
		static genbl0_t GENBL0;
		typedef gen_t_<0x00087674> genbl1_t;
		static genbl1_t GENBL1;
		typedef gen_t_<0x00087870> genal0_t;
		static genal0_t GENAL0;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  グループ BE0 割り込みクリアレジスタ（GCRBE0）
			@param[in]	base	ベースアドレス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t base>
		struct gcrbe0_t_ : public rw32_t<base> {
			typedef rw32_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t <io_, bitpos::B0>  CLR0;
			bit_rw_t <io_, bitpos::B1>  CLR1;
			bit_rw_t <io_, bitpos::B2>  CLR2;
			bit_rw_t <io_, bitpos::B3>  CLR3;
			bit_rw_t <io_, bitpos::B4>  CLR4;
			bit_rw_t <io_, bitpos::B5>  CLR5;
			bit_rw_t <io_, bitpos::B6>  CLR6;
			bit_rw_t <io_, bitpos::B7>  CLR7;

			bit_rw_t <io_, bitpos::B8>  CLR8;
			bit_rw_t <io_, bitpos::B9>  CLR9;
			bit_rw_t <io_, bitpos::B10> CLR10;
			bit_rw_t <io_, bitpos::B11> CLR11;
			bit_rw_t <io_, bitpos::B12> CLR12;
			bit_rw_t <io_, bitpos::B13> CLR13;
			bit_rw_t <io_, bitpos::B14> CLR14;
			bit_rw_t <io_, bitpos::B15> CLR15;

			bit_rw_t <io_, bitpos::B16> CLR16;
			bit_rw_t <io_, bitpos::B17> CLR17;
			bit_rw_t <io_, bitpos::B18> CLR18;
			bit_rw_t <io_, bitpos::B19> CLR19;
			bit_rw_t <io_, bitpos::B20> CLR20;
			bit_rw_t <io_, bitpos::B21> CLR21;
			bit_rw_t <io_, bitpos::B22> CLR22;
			bit_rw_t <io_, bitpos::B23> CLR23;

			bit_rw_t <io_, bitpos::B24> CLR24;
			bit_rw_t <io_, bitpos::B25> CLR25;
			bit_rw_t <io_, bitpos::B26> CLR26;
			bit_rw_t <io_, bitpos::B27> CLR27;
			bit_rw_t <io_, bitpos::B28> CLR28;
			bit_rw_t <io_, bitpos::B29> CLR29;
			bit_rw_t <io_, bitpos::B30> CLR30;
			bit_rw_t <io_, bitpos::B31> CLR31;
		};
		typedef gcrbe0_t_<0x00087680> gcrbe0_t;
		static gcrbe0_t GCRBE0;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  選択型割り込み要求レジスタ
			@param[in]	base	ベースアドレス
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		template <uint32_t base>
		struct pixr_t_ : public rw8_t<base> {
			typedef rw8_t<base> io_;
			using io_::operator =;
			using io_::operator ();
			using io_::operator |=;
			using io_::operator &=;

			bit_rw_t <io_, bitpos::B0>  PIR0;
			bit_rw_t <io_, bitpos::B1>  PIR1;
			bit_rw_t <io_, bitpos::B2>  PIR2;
			bit_rw_t <io_, bitpos::B3>  PIR3;
			bit_rw_t <io_, bitpos::B4>  PIR4;
			bit_rw_t <io_, bitpos::B5>  PIR5;
			bit_rw_t <io_, bitpos::B6>  PIR6;
			bit_rw_t <io_, bitpos::B7>  PIR7;
		};


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
			@brief  選択型割り込み A 要求レジスタ k（PIARk）（k = 0h ～ Bh）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		typedef pixr_t_<0x00087900> piar0_t;
		static piar0_t PIAR0;
		typedef pixr_t_<0x00087901> piar1_t;
		static piar1_t PIAR1;
		typedef pixr_t_<0x00087902> piar2_t;
		static piar2_t PIAR2;
		typedef pixr_t_<0x00087903> piar3_t;
		static piar3_t PIAR3;
		typedef pixr_t_<0x00087904> piar4_t;
		static piar4_t PIAR4;
		typedef pixr_t_<0x00087905> piar5_t;
		static piar5_t PIAR5;
		typedef pixr_t_<0x00087906> piar6_t;
		static piar6_t PIAR6;
		typedef pixr_t_<0x00087907> piar7_t;
		static piar7_t PIAR7;
		typedef pixr_t_<0x00087908> piar8_t;
		static piar8_t PIAR8;
		typedef pixr_t_<0x00087909> piar9_t;
		static piar9_t PIAR9;
		typedef pixr_t_<0x0008790A> piara_t;
		static piara_t PIARA;
		typedef pixr_t_<0x0008790B> piarb_t;
		static piarb_t PIARB;


		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		/*!
		  @brief  選択型割り込み A 要因選択レジスタ n（SLIARn）（n = 208 ～ 255）
		*/
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
		typedef rw8_t<0x000879D0> sliar208_t;
		static sliar208_t SLIAR208;
		typedef rw8_t<0x000879D1> sliar209_t;
		static sliar209_t SLIAR209;
		typedef rw8_t<0x000879D2> sliar210_t;
		static sliar210_t SLIAR210;
		typedef rw8_t<0x000879D3> sliar211_t;
		static sliar211_t SLIAR211;
		typedef rw8_t<0x000879D4> sliar212_t;
		static sliar212_t SLIAR212;
		typedef rw8_t<0x000879D5> sliar213_t;
		static sliar213_t SLIAR213;
		typedef rw8_t<0x000879D6> sliar214_t;
		static sliar214_t SLIAR214;
		typedef rw8_t<0x000879D7> sliar215_t;
		static sliar215_t SLIAR215;
		typedef rw8_t<0x000879D8> sliar216_t;
		static sliar216_t SLIAR216;
		typedef rw8_t<0x000879D9> sliar217_t;
		static sliar217_t SLIAR217;
		typedef rw8_t<0x000879DA> sliar218_t;
		static sliar218_t SLIAR218;
		typedef rw8_t<0x000879DB> sliar219_t;
		static sliar219_t SLIAR219;
		typedef rw8_t<0x000879DC> sliar220_t;
		static sliar220_t SLIAR220;
		typedef rw8_t<0x000879DD> sliar221_t;
		static sliar221_t SLIAR221;
		typedef rw8_t<0x000879DE> sliar222_t;
		static sliar222_t SLIAR222;
		typedef rw8_t<0x000879DF> sliar223_t;
		static sliar223_t SLIAR223;

		typedef rw8_t<0x000879E0> sliar224_t;
		static sliar224_t SLIAR224;
		typedef rw8_t<0x000879E1> sliar225_t;
		static sliar225_t SLIAR225;
		typedef rw8_t<0x000879E2> sliar226_t;
		static sliar226_t SLIAR226;
		typedef rw8_t<0x000879E3> sliar227_t;
		static sliar227_t SLIAR227;
		typedef rw8_t<0x000879E4> sliar228_t;
		static sliar228_t SLIAR228;
		typedef rw8_t<0x000879E5> sliar229_t;
		static sliar229_t SLIAR229;
		typedef rw8_t<0x000879E6> sliar230_t;
		static sliar230_t SLIAR230;
		typedef rw8_t<0x000879E7> sliar231_t;
		static sliar231_t SLIAR231;
		typedef rw8_t<0x000879E8> sliar232_t;
		static sliar232_t SLIAR232;
		typedef rw8_t<0x000879E9> sliar233_t;
		static sliar233_t SLIAR233;
		typedef rw8_t<0x000879EA> sliar234_t;
		static sliar234_t SLIAR234;
		typedef rw8_t<0x000879EB> sliar235_t;
		static sliar235_t SLIAR235;
		typedef rw8_t<0x000879EC> sliar236_t;
		static sliar236_t SLIAR236;
		typedef rw8_t<0x000879ED> sliar237_t;
		static sliar237_t SLIAR237;
		typedef rw8_t<0x000879EE> sliar238_t;
		static sliar238_t SLIAR238;
		typedef rw8_t<0x000879EF> sliar239_t;
		static sliar239_t SLIAR239;

		typedef rw8_t<0x000879F0> sliar240_t;
		static sliar240_t SLIAR240;
		typedef rw8_t<0x000879F1> sliar241_t;
		static sliar241_t SLIAR241;
		typedef rw8_t<0x000879F2> sliar242_t;
		static sliar242_t SLIAR242;
		typedef rw8_t<0x000879F3> sliar243_t;
		static sliar243_t SLIAR243;
		typedef rw8_t<0x000879F4> sliar244_t;
		static sliar244_t SLIAR244;
		typedef rw8_t<0x000879F5> sliar245_t;
		static sliar245_t SLIAR245;
		typedef rw8_t<0x000879F6> sliar246_t;
		static sliar246_t SLIAR246;
		typedef rw8_t<0x000879F7> sliar247_t;
		static sliar247_t SLIAR247;
		typedef rw8_t<0x000879F8> sliar248_t;
		static sliar248_t SLIAR248;
		typedef rw8_t<0x000879F9> sliar249_t;
		static sliar249_t SLIAR249;
		typedef rw8_t<0x000879FA> sliar250_t;
		static sliar250_t SLIAR250;
		typedef rw8_t<0x000879FB> sliar251_t;
		static sliar251_t SLIAR251;
		typedef rw8_t<0x000879FC> sliar252_t;
		static sliar252_t SLIAR252;
		typedef rw8_t<0x000879FD> sliar253_t;
		static sliar253_t SLIAR253;
		typedef rw8_t<0x000879FE> sliar254_t;
		static sliar254_t SLIAR254;
		typedef rw8_t<0x000879FF> sliar255_t;
		static sliar255_t SLIAR255;

		typedef icu_utils::slixr_t<0x00087700> slixr_t;
		static slixr_t SLIXR;
	};
	typedef icu_t_<void> ICU;
	typedef icu_t_<void> icu_t;
	template <typename _> typename icu_t_<_>::ir_t        icu_t_<_>::IR;
	template <typename _> typename icu_t_<_>::ier_t       icu_t_<_>::IER;
	template <typename _> typename icu_t_<_>::ipr_t       icu_t_<_>::IPR;
	template <typename _> typename icu_t_<_>::dmrsr0_t    icu_t_<_>::DMRSR0;
	template <typename _> typename icu_t_<_>::dmrsr1_t    icu_t_<_>::DMRSR1;
	template <typename _> typename icu_t_<_>::dmrsr2_t    icu_t_<_>::DMRSR2;
	template <typename _> typename icu_t_<_>::dmrsr3_t    icu_t_<_>::DMRSR3;
	template <typename _> typename icu_t_<_>::dmrsr4_t    icu_t_<_>::DMRSR4;
	template <typename _> typename icu_t_<_>::dmrsr5_t    icu_t_<_>::DMRSR5;
	template <typename _> typename icu_t_<_>::dmrsr6_t    icu_t_<_>::DMRSR6;
	template <typename _> typename icu_t_<_>::dmrsr7_t    icu_t_<_>::DMRSR7;
	template <typename _> typename icu_t_<_>::irqflte0_t  icu_t_<_>::IRQFLTE0;
	template <typename _> typename icu_t_<_>::irqflte1_t  icu_t_<_>::IRQFLTE1;
	template <typename _> typename icu_t_<_>::irqfltc0_t  icu_t_<_>::IRQFLTC0;
	template <typename _> typename icu_t_<_>::irqfltc1_t  icu_t_<_>::IRQFLTC1;
	template <typename _> typename icu_t_<_>::grpbe0_t    icu_t_<_>::GRPBE0;
	template <typename _> typename icu_t_<_>::grpbl0_t    icu_t_<_>::GRPBL0;
	template <typename _> typename icu_t_<_>::grpbl1_t    icu_t_<_>::GRPBL1;
	template <typename _> typename icu_t_<_>::grpal0_t    icu_t_<_>::GRPAL0;
	template <typename _> typename icu_t_<_>::genbe0_t    icu_t_<_>::GENBE0;
	template <typename _> typename icu_t_<_>::genbl0_t    icu_t_<_>::GENBL0;
	template <typename _> typename icu_t_<_>::genbl1_t    icu_t_<_>::GENBL1;
	template <typename _> typename icu_t_<_>::genal0_t    icu_t_<_>::GENAL0;
	template <typename _> typename icu_t_<_>::gcrbe0_t    icu_t_<_>::GCRBE0;
	template <typename _> typename icu_t_<_>::piar0_t     icu_t_<_>::PIAR0;
	template <typename _> typename icu_t_<_>::piar1_t     icu_t_<_>::PIAR1;
	template <typename _> typename icu_t_<_>::piar2_t     icu_t_<_>::PIAR2;
	template <typename _> typename icu_t_<_>::piar3_t     icu_t_<_>::PIAR3;
	template <typename _> typename icu_t_<_>::piar4_t     icu_t_<_>::PIAR4;
	template <typename _> typename icu_t_<_>::piar5_t     icu_t_<_>::PIAR5;
	template <typename _> typename icu_t_<_>::piar6_t     icu_t_<_>::PIAR6;
	template <typename _> typename icu_t_<_>::piar7_t     icu_t_<_>::PIAR7;
	template <typename _> typename icu_t_<_>::piar8_t     icu_t_<_>::PIAR8;
	template <typename _> typename icu_t_<_>::piar9_t     icu_t_<_>::PIAR9;
	template <typename _> typename icu_t_<_>::piara_t     icu_t_<_>::PIARA;
	template <typename _> typename icu_t_<_>::piarb_t     icu_t_<_>::PIARB;
	template <typename _> typename icu_t_<_>::sliar208_t  icu_t_<_>::SLIAR208;
	template <typename _> typename icu_t_<_>::sliar209_t  icu_t_<_>::SLIAR209;
	template <typename _> typename icu_t_<_>::sliar210_t  icu_t_<_>::SLIAR210;
	template <typename _> typename icu_t_<_>::sliar211_t  icu_t_<_>::SLIAR211;
	template <typename _> typename icu_t_<_>::sliar212_t  icu_t_<_>::SLIAR212;
	template <typename _> typename icu_t_<_>::sliar213_t  icu_t_<_>::SLIAR213;
	template <typename _> typename icu_t_<_>::sliar214_t  icu_t_<_>::SLIAR214;
	template <typename _> typename icu_t_<_>::sliar215_t  icu_t_<_>::SLIAR215;
	template <typename _> typename icu_t_<_>::sliar216_t  icu_t_<_>::SLIAR216;
	template <typename _> typename icu_t_<_>::sliar217_t  icu_t_<_>::SLIAR217;
	template <typename _> typename icu_t_<_>::sliar218_t  icu_t_<_>::SLIAR218;
	template <typename _> typename icu_t_<_>::sliar219_t  icu_t_<_>::SLIAR219;
	template <typename _> typename icu_t_<_>::sliar220_t  icu_t_<_>::SLIAR220;
	template <typename _> typename icu_t_<_>::sliar221_t  icu_t_<_>::SLIAR221;
	template <typename _> typename icu_t_<_>::sliar222_t  icu_t_<_>::SLIAR222;
	template <typename _> typename icu_t_<_>::sliar223_t  icu_t_<_>::SLIAR223;
	template <typename _> typename icu_t_<_>::sliar224_t  icu_t_<_>::SLIAR224;
	template <typename _> typename icu_t_<_>::sliar225_t  icu_t_<_>::SLIAR225;
	template <typename _> typename icu_t_<_>::sliar226_t  icu_t_<_>::SLIAR226;
	template <typename _> typename icu_t_<_>::sliar227_t  icu_t_<_>::SLIAR227;
	template <typename _> typename icu_t_<_>::sliar228_t  icu_t_<_>::SLIAR228;
	template <typename _> typename icu_t_<_>::sliar229_t  icu_t_<_>::SLIAR229;
	template <typename _> typename icu_t_<_>::sliar230_t  icu_t_<_>::SLIAR230;
	template <typename _> typename icu_t_<_>::sliar231_t  icu_t_<_>::SLIAR231;
	template <typename _> typename icu_t_<_>::sliar232_t  icu_t_<_>::SLIAR232;
	template <typename _> typename icu_t_<_>::sliar233_t  icu_t_<_>::SLIAR233;
	template <typename _> typename icu_t_<_>::sliar234_t  icu_t_<_>::SLIAR234;
	template <typename _> typename icu_t_<_>::sliar235_t  icu_t_<_>::SLIAR235;
	template <typename _> typename icu_t_<_>::sliar236_t  icu_t_<_>::SLIAR236;
	template <typename _> typename icu_t_<_>::sliar237_t  icu_t_<_>::SLIAR237;
	template <typename _> typename icu_t_<_>::sliar238_t  icu_t_<_>::SLIAR238;
	template <typename _> typename icu_t_<_>::sliar239_t  icu_t_<_>::SLIAR239;
	template <typename _> typename icu_t_<_>::sliar240_t  icu_t_<_>::SLIAR240;
	template <typename _> typename icu_t_<_>::sliar241_t  icu_t_<_>::SLIAR241;
	template <typename _> typename icu_t_<_>::sliar242_t  icu_t_<_>::SLIAR242;
	template <typename _> typename icu_t_<_>::sliar243_t  icu_t_<_>::SLIAR243;
	template <typename _> typename icu_t_<_>::sliar244_t  icu_t_<_>::SLIAR244;
	template <typename _> typename icu_t_<_>::sliar245_t  icu_t_<_>::SLIAR245;
	template <typename _> typename icu_t_<_>::sliar246_t  icu_t_<_>::SLIAR246;
	template <typename _> typename icu_t_<_>::sliar247_t  icu_t_<_>::SLIAR247;
	template <typename _> typename icu_t_<_>::sliar248_t  icu_t_<_>::SLIAR248;
	template <typename _> typename icu_t_<_>::sliar249_t  icu_t_<_>::SLIAR249;
	template <typename _> typename icu_t_<_>::sliar250_t  icu_t_<_>::SLIAR250;
	template <typename _> typename icu_t_<_>::sliar251_t  icu_t_<_>::SLIAR251;
	template <typename _> typename icu_t_<_>::sliar252_t  icu_t_<_>::SLIAR252;
	template <typename _> typename icu_t_<_>::sliar253_t  icu_t_<_>::SLIAR253;
	template <typename _> typename icu_t_<_>::sliar254_t  icu_t_<_>::SLIAR254;
	template <typename _> typename icu_t_<_>::sliar255_t  icu_t_<_>::SLIAR255;
	template <typename _> typename icu_t_<_>::slixr_t     icu_t_<_>::SLIXR;
}
