/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2016. All rights reserved.
*
* BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
* THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
* CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
* SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
* STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
* CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*/
#ifndef __PLATFORM_DEBUG_H__
#define __PLATFORM_DEBUG_H__

#include <latch.h>
#include <dfd.h>

const struct plt_cfg_pc_latch cfg_pc_latch = {
	.nr_max_core = 8,
	.nr_max_big_core = 2,
	.anake_core_dbg_sel = 0x0220,
	.anake_core_dbg_mon = 0x0224,
	.spm_pwr_sts = 0x830,
	.plat_sram_flag0 = 0x0,
	.version = LASTPC_V2,
};

const struct plt_cfg_return_stack cfg_return_stack = {
	.nr_max_core = 8,
	.nr_max_big = 2,
	.nr_entry = 8,
	.dump = NULL,
	.decode = NULL,
};

int plt_infrasys_init(const struct lastbus_monitor *m);
extern int lastbus_init_v2_init_w_clr(const struct lastbus_monitor *m);
extern int lastbus_init_v2_infra_ao_init(const struct lastbus_monitor *m);
extern int lastbus_init_v2_peri_ao_init(const struct lastbus_monitor *m);
extern int lastbus_init_v2_fmem_ao_init(const struct lastbus_monitor *m);

const struct plt_cfg_bus_latch cfg_bus_latch = {
	.sw_version = LASTBUS_SW_V2,
	.supported = 1,
	.num_master_port = 3,
	.num_slave_port = 4,
	.mcusys_offsets = {
		.bus_mcu_m0 = 0x8320,
		.bus_mcu_s1 = 0x8340,
		.bus_mcu_m0_m = 0x8240,
		.bus_mcu_s1_m = 0x8260,
	},
	.v2 = {
		.used_num = 5,
		.monitors ={
			    {
				.name = "debug_ctrl_ao_INFRA_AO",
				.base = (void *)0x10023000,
				.num_ports = 25,
				.ops = {
					.init = lastbus_init_v2_infra_ao_init,
				},
			    },
			    {
				.name = "debug_ctrl_ao_PERI_AO",
				.base = (void *)0x1002b000,
				.num_ports = 34,
				.ops = {
					.init = lastbus_init_v2_peri_ao_init,
				},
			    },
			    {
				.name = "debug_ctrl_ao_PERI_AO2",
				.base = (void *)0x1002e000,
				.num_ports = 19,
				.ops = {
					.init = lastbus_init_v2_init_w_clr,
				},
			    },
			    {
				.name = "debug_ctrl_ao_PERI_PAR_AO",
				.base = (void *)0x10040000,
				.num_ports = 6,
				.ops = {
					.init = lastbus_init_v2_init_w_clr,
				},
			    },
			    {
				.name = "debug_ctrl_ao_FMEM_AO",
				.base = (void *)0x10042000,
				.num_ports = 20,
				.ops = {
					.init = lastbus_init_v2_fmem_ao_init,
				},
			    },
			   }, /* end of monitors */
	}, /* end of v2 */
}; /* end of cfg_bus_latch */

const struct plt_cfg_l2_parity_latch cfg_l2_parity_latch = {
	.supported = 0,
	.mp0_l2_cache_parity1_rdata = 0x007c,
	.mp0_l2_cache_parity2_rdata = 0x0080,
	.mp1_l2_cache_parity1_rdata = 0x22d0,
	.mp1_l2_cache_parity2_rdata = 0x22d4,
};

const struct plt_cfg_big_core cfg_big_core[] = {
	{
		.cpuid = 6,
		.nr_circular_buffer_entry = 128,
		.circular_buffer_addr = 0x0C533400,
	},
	{
		.cpuid = 7,
		.nr_circular_buffer_entry = 128,
		.circular_buffer_addr = 0x0C533C00,
	},
};

struct plt_circular_buffer_op circular_buffer_op = {
	.lock = NULL,
	.unlock = NULL,
};

#define MCU_ALL_PWR_ON_CTRL	(0x0C530B58)

/******* dfd *******/
#include "dfd.h"

const struct plt_cfg_dfd cfg_dfd = {
	.version = DFD_V3_0,
	.sw_version = DFD_SW_V3,
	.nr_header_row = 0,
	.buffer_addr = 0x0c600000,
	.buffer_length = 0x9d000,
	.large_buffer_length = 0x800000,
	.plat_sram_flag1 = 0,
	.plat_sram_flag2 = 0,
	.dfd_disable_devinfo_index = 25,
	.dfd_disable_bit = 12,
	.chip_id_offset = 0x18,
	.chip_id = {'6','8','5','3',0,0,0,0},
};

struct plt_dfd_op dfd_op = {
	.acquire_ram_control = NULL,
	.release_ram_control = NULL,
	.setup_dfd_file_name = plt_setup_dfd_file_name,
};

/******* etb *******/
#include "etb.h"

const struct plt_cfg_etb cfg_etb = {
	.nr_etb = 1,
	.total_etb_sz = 2000,
	.dem_base = 0x0d01a000,
	.etb = {
		{0x0d010000, 0},
	},
};

#endif
