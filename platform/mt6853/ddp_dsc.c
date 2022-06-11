/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2019. All rights reserved.
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

#define LOG_TAG "DSC"
#include "platform/ddp_reg.h"
#include "platform/ddp_info.h"
#include "platform/ddp_log.h"

#include "platform/ddp_reg_dsc.h"
#include "platform/disp_drv_platform.h"
#include "platform/primary_display.h"

int dsc_clock_on(DISP_MODULE_ENUM module, void *handle)
{
	DDPDBG("%s clock_on\n", ddp_get_module_name(module));

	ddp_enable_module_clock(module);

	return 0;
}

int dsc_clock_off(DISP_MODULE_ENUM module, void *handle)
{
	DDPDBG("%s clock_off\n", ddp_get_module_name(module));

	ddp_disable_module_clock(module);

	return 0;
}

int dsc_init(DISP_MODULE_ENUM module, void *handle)
{
	return dsc_clock_on(module, handle);
}

int dsc_deinit(DISP_MODULE_ENUM module, void *handle)
{
	return dsc_clock_off(module, handle);
}

int dsc_config(DISP_MODULE_ENUM module, disp_ddp_path_config *pConfig,
	void *handle)
{
	unsigned long base = DISPSYS_DSC_BASE;
	unsigned int height = pConfig->dst_h, width = pConfig->dst_w;

	unsigned int init_delay_limit, init_delay_height;
	unsigned int pic_group_width_m1;
	unsigned int pic_height_m1, pic_height_ext_m1, pic_height_ext_num;
	unsigned int slice_group_width_m1;
	unsigned int pad_num;
	unsigned int val;

	LCM_DSI_PARAMS *dsi = &pConfig->dsi_config;
	LCM_DSC_CONFIG_PARAMS *params = &dsi->dsc_params;

	if (dsi->dsc_enable == 0) {
		DISP_REG_SET_FIELD(handle, CON_FLD_DSC_EN,
			base + DISP_REG_DSC_CON, 0x1);
		DISP_REG_SET_FIELD(handle, CON_FLD_DISP_DSC_RELAY,
			base + DISP_REG_DSC_CON, 0x1);
		DISP_REG_SET(handle, base + DISP_REG_DSC_PIC_H, height - 1);
		DISP_REG_SET(handle, base + DISP_REG_DSC_PIC_W, width);

		return 0;
	}

	if (params->pic_width != width || params->pic_height != height) {
		DDPERR("%s size mismatch...", __func__);
		return 1;
	}

	val = 0x10001;
	DISP_REG_SET(handle, base + DISP_REG_DSC_CON, val);

	/* DSC Empty flag always high */
	DISP_REG_SET_FIELD(handle, CON_FLD_DSC_EMPTY_FLAG_ALWAYS_HIGH,
			base + DISP_REG_DSC_CON, 0x1);
	/* DSC output buffer as FHD(plus) */
	DISP_REG_SET(handle, base + DISP_REG_DSC_OBUF, 0x800002C2);

	init_delay_limit =
		((128 + (params->xmit_delay + 2) / 3) * 3 +
		params->slice_width - 1) / params->slice_width;
	init_delay_height =
		(init_delay_limit > 15) ? 15 : init_delay_limit;

	val = params->slice_mode + (init_delay_height << 8) + (1 << 16);
	DISP_REG_SET(handle, base + DISP_REG_DSC_MODE, val);

	pic_group_width_m1 = (width + 2) / 3 - 1;
	DISP_REG_SET(handle, base + DISP_REG_DSC_PIC_W,
		(pic_group_width_m1 << 16) + width);

	pic_height_m1 = height - 1;
	pic_height_ext_num = (height + params->slice_height - 1) /
	    params->slice_height;
	pic_height_ext_m1 = pic_height_ext_num * params->slice_height - 1;
	DISP_REG_SET(handle, base + DISP_REG_DSC_PIC_H,
		(pic_height_ext_m1 << 16) + pic_height_m1);

	slice_group_width_m1 = (params->slice_width + 2) / 3 - 1;
	DISP_REG_SET(handle, base + DISP_REG_DSC_SLICE_W,
		(slice_group_width_m1 << 16) + params->slice_width);

	DISP_REG_SET(handle, base + DISP_REG_DSC_SLICE_H,
		((params->slice_width % 3) << 30) +
		((pic_height_ext_num - 1) << 16) + params->slice_height - 1);

	DISP_REG_SET(handle, base + DISP_REG_DSC_CHUNK_SIZE,
		params->chunk_size);
	DISP_REG_SET(handle, base + DISP_REG_DSC_BUF_SIZE,
		params->chunk_size * params->slice_height);

	pad_num = (params->chunk_size + 2) / 3 * 3 - params->chunk_size;
	DISP_REG_SET(handle, base + DISP_REG_DSC_PAD, pad_num);

	if (params->dsc_cfg)
		DISP_REG_SET(handle, base + DISP_REG_DSC_CFG, params->dsc_cfg);
	else
		DISP_REG_SET(handle, base + DISP_REG_DSC_CFG, 0x22);

	if ((params->ver & 0xf) == 2)
		DISP_REG_SET_FIELD(handle, DSC_FLD_VER,
			base + DISP_REG_DSC_SHADOW, 0x2); /* DSC V1.2 */
	else
		DISP_REG_SET_FIELD(handle, DSC_FLD_VER,
			base + DISP_REG_DSC_SHADOW, 0x1); /* DSC V1.1 */

	/* set PPS */
	val = params->dsc_line_buf_depth + (params->bit_per_channel << 4) +
		(params->bit_per_pixel << 8) + (params->rct_on << 18) +
		(params->bp_enable << 19);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS0, val);

	val = (params->xmit_delay) + (params->dec_delay << 16);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS1, val);

	val = (params->scale_value) + (params->increment_interval << 16);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS2, val);

	val = (params->decrement_interval) + (params->line_bpg_offset << 16);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS3, val);

	val = (params->nfl_bpg_offset) + (params->slice_bpg_offset << 16);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS4, val);

	val = (params->initial_offset) + (params->final_offset << 16);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS5, val);

	val = (params->flatness_minqp) + (params->flatness_maxqp << 8) +
		(params->rc_model_size << 16);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS6, val);

	val = (params->rc_edge_factor) + (params->rc_quant_incr_limit0 << 8) +
		(params->rc_quant_incr_limit1 << 16) +
		(params->rc_tgt_offset_hi << 24) +
		(params->rc_tgt_offset_lo << 28);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS7, val);

	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS8, 0x382a1c0e);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS9, 0x69625446);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS10, 0x7b797770);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS11, 0x7e7d);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS12, 0x800880);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS13, 0xf8c100a1);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS14, 0xe8e3f0e3);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS15, 0xe103e0e3);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS16, 0xd943e123);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS17, 0xd185d965);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS18, 0xd1a7d1a5);
	DISP_REG_SET(handle, base + DISP_REG_DSC_PPS19, 0xd1ed);

	return 0;
}

int dsc_dump(DISP_MODULE_ENUM module, int level)
{
	unsigned long base = DISPSYS_DSC_BASE;

	DDPDUMP("== START: DISP DSC REGS ==\n");
	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0, INREG32(base + 0x0),
		0x4, INREG32(base + 0x4),
		0x8, INREG32(base + 0x8),
		0xC, INREG32(base + 0xC));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x10, INREG32(base + 0x10),
		0x18, INREG32(base + 0x18),
		0x1C, INREG32(base + 0x1C));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x20, INREG32(base + 0x20),
		0x24, INREG32(base + 0x24),
		0x28, INREG32(base + 0x28),
		0x2C, INREG32(base + 0x2C));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x30, INREG32(base + 0x30),
		0x34, INREG32(base + 0x34),
		0x38, INREG32(base + 0x38));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x80, INREG32(base + 0x80),
		0x84, INREG32(base + 0x84),
		0x88, INREG32(base + 0x88),
		0x8C, INREG32(base + 0x8C));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x90, INREG32(base + 0x90),
		0x94, INREG32(base + 0x94),
		0x98, INREG32(base + 0x98),
		0x9C, INREG32(base + 0x9C));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xA0, INREG32(base + 0xA0),
		0xA4, INREG32(base + 0xA4),
		0xA8, INREG32(base + 0xA8),
		0xAC, INREG32(base + 0xAC));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xB0, INREG32(base + 0xB0),
		0xB4, INREG32(base + 0xB4),
		0xB8, INREG32(base + 0xB8),
		0xBC, INREG32(base + 0xBC));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xC0, INREG32(base + 0xC0),
		0xC4, INREG32(base + 0xC4),
		0xC8, INREG32(base + 0xC8),
		0xCC, INREG32(base + 0xCC));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x100, INREG32(base + 0x100),
		0x104, INREG32(base + 0x104),
		0x108, INREG32(base + 0x108),
		0x10C, INREG32(base + 0x10C));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x110, INREG32(base + 0x110),
		0x114, INREG32(base + 0x114),
		0x118, INREG32(base + 0x118),
		0x11C, INREG32(base + 0x11C));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x120, INREG32(base + 0x120),
		0x124, INREG32(base + 0x124),
		0x128, INREG32(base + 0x128),
		0x12C, INREG32(base + 0x12C));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x130, INREG32(base + 0x130),
		0x134, INREG32(base + 0x134),
		0x138, INREG32(base + 0x138),
		0x13C, INREG32(base + 0x13C));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x140, INREG32(base + 0x140),
		0x144, INREG32(base + 0x144),
		0x148, INREG32(base + 0x148),
		0x14C, INREG32(base + 0x14C));

	DDPDUMP("0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x150, INREG32(base + 0x150),
		0x154, INREG32(base + 0x154),
		0x158, INREG32(base + 0x158),
		0x15C, INREG32(base + 0x15C));
	DDPDUMP("0x%04x=0x%08x\n", 0x200, INREG32(base + 0x200));

	return 0;
}

DDP_MODULE_DRIVER ddp_driver_dsc = {
	.init = dsc_init,
	.deinit = dsc_deinit,
	.config = dsc_config,
	.dump_info = dsc_dump,
};

