#pragma once
//=====================================================================//
/*!	@file
	@brief	ルネサス RX デバイス選択
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2016, 2018 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RX/blob/master/LICENSE
*/
//=====================================================================//
#include "common/byte_order.h"
#include "common/vect.h"
#include "common/delay.hpp"
#include "common/device.hpp"

#include "RX600/lvda.hpp"
#include "RX600/bus.hpp"

#if defined(SIG_RX24T)
#include "RX24T/system.hpp"
#include "RX24T/system_io.hpp"
#include "RX600/gpt.hpp"
#include "RX24T/s12ad.hpp"
#include "RX24T/adc_in.hpp"
#include "RX24T/da.hpp"
#include "RX600/cmpc.hpp"
#include "RX24T/flash.hpp"
#include "RX24T/flash_io.hpp"
#include "RX24T/dac_out.hpp"

#elif defined(SIG_RX621) || defined(SIG_RX62N)
#include "RX62x/system.hpp"

#elif defined(SIG_RX64M) || defined(SIG_RX71M)
#include "RX600/system.hpp"
#include "RX600/system_io.hpp"
#include "RX600/dmac.hpp"
#include "RX600/elc.hpp"
#include "RX600/exdmac.hpp"
#include "RX600/mpc.hpp"
#include "RX600/tpu.hpp"
#include "RX600/gpt.hpp"
#include "RX600/ppg.hpp"
#include "RX600/cmtw.hpp"
#include "RX600/can.hpp"
#include "RX600/qspi.hpp"
#include "RX600/s12adc.hpp"
#include "RX600/adc_in.hpp"
#include "RX600/r12da.hpp"
#include "RX600/dac_out.hpp"
#include "RX600/sdram.hpp"
#include "RX600/etherc.hpp"
#include "RX600/eptpc.hpp"
#include "RX600/edmac.hpp"
#include "RX600/usb.hpp"
#include "RX600/usba.hpp"
#include "RX600/scif.hpp"
#include "RX600/rtc.hpp"
#include "RX600/rtc_io.hpp"
#include "RX600/wdta.hpp"
#include "RX600/flash.hpp"
#include "RX600/flash_io.hpp"
#include "RX600/ether_io.hpp"
#include "RX600/ssi.hpp"
#include "RX600/src.hpp"
#include "RX600/sdhi.hpp"
#include "RX600/sdhi_io.hpp"
#include "RX600/mmcif.hpp"
#include "RX600/pdc.hpp"
#include "RX600/standby_ram.hpp"
#include "RX600/ssi_io.hpp"
#include "RX600/dmac_mgr.hpp"

#elif defined(SIG_RX65N)
#include "RX600/system.hpp"
#include "RX600/system_io.hpp"
#include "RX600/dmac.hpp"
#include "RX600/elc.hpp"
#include "RX600/exdmac.hpp"
#include "RX600/mpc.hpp"
#include "RX600/tpu.hpp"
#include "RX600/ppg.hpp"
#include "RX600/cmtw.hpp"
#include "RX600/can.hpp"
#include "RX600/qspi.hpp"
#include "RX65x/s12adf.hpp"
#include "RX600/adc_in.hpp"
#include "RX600/r12da.hpp"
#include "RX600/dac_out.hpp"
#include "RX600/sdram.hpp"
#include "RX600/etherc.hpp"
#include "RX600/edmac.hpp"
#include "RX600/usb.hpp"
#include "RX600/rtc.hpp"
#include "RX600/rtc_io.hpp"
#include "RX600/wdta.hpp"
#include "RX600/flash.hpp"
#include "RX600/flash_io.hpp"
#include "RX600/ether_io.hpp"
#include "RX600/sdhi.hpp"
#include "RX600/sdhi_io.hpp"
#include "RX600/mmcif.hpp"
#include "RX600/pdc.hpp"
#include "RX600/standby_ram.hpp"
#include "RX65x/glcdc.hpp"
#include "RX65x/glcdc_io.hpp"
#include "RX65x/drw2d.hpp"
#include "RX65x/drw2d_mgr.hpp"
#include "RX600/dmac_mgr.hpp"

#elif defined(SIG_RX66T)
#include "RX600/system.hpp"
#include "RX600/system_io.hpp"
#include "RX600/dmac.hpp"
#include "RX600/elc.hpp"
#include "RX600/mpc.hpp"
#include "RX66T/gptw.hpp"
#include "RX66T/hrpwm.hpp"
#include "RX66T/poeg.hpp"
#include "RX600/can.hpp"
#include "RX600/r12da.hpp"
#include "RX600/dac_out.hpp"
#include "RX600/usb.hpp"
#include "RX600/wdta.hpp"
#include "RX600/flash.hpp"
#include "RX600/flash_io.hpp"
#include "RX600/cmpc.hpp"
#include "RX600/dmac_mgr.hpp"

#else
#  error "renesas.hpp: Requires SIG_XXX to be defined"
#endif

// RX マイコン共通ペリフェラル
#include "RX600/cac.hpp"
#include "RX600/dtc.hpp"
#include "RX600/port.hpp"
#include "RX600/mtu3.hpp"
#include "RX600/poe3.hpp"
#include "RX600/tmr.hpp"
#include "RX600/cmt.hpp"
#include "RX600/iwdt.hpp"
#include "RX600/sci.hpp"
#include "RX600/riic.hpp"
#include "RX600/rspi.hpp"
#include "RX600/crc.hpp"
#include "RX600/mpu.hpp"
#include "RX600/doc.hpp"
