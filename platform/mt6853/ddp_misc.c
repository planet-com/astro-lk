/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2015. All rights reserved.
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

#define LOG_TAG "MISC"

#include <platform/ddp_reg.h>
#include <platform/ddp_misc.h>
#include <platform/disp_drv_platform.h>

#include <debug.h>


void ddp_bypass_color(int idx, unsigned int width, unsigned int height, void * handle)
{
	dprintf(CRITICAL, "bypass color\n");
	DISP_REG_SET(NULL,DISP_COLOR_CFG_MAIN, 1<<7); //bypass color engine
	DISP_REG_SET(NULL,DISP_COLOR_INTERNAL_IP_WIDTH, width); //bypass color engine
	DISP_REG_SET(NULL,DISP_COLOR_INTERNAL_IP_HEIGHT, height); //bypass color engine
	DISP_REG_SET(NULL,DISP_COLOR_START, 0x1); // start
}

void ddp_bypass_ccorr(int idx, unsigned int width, unsigned int height, void * handle)
{
	dprintf(CRITICAL, "bypass ccorr\n");
	DISP_REG_MASK(NULL, (DISP_REG_CCORR_CFG - idx * 0x1000), 1, 1);
	DISP_REG_SET(NULL, (DISP_REG_CCORR_SIZE - idx * 0x1000), (width<<16)|height); //bypass color engine
	DISP_REG_SET(NULL, (DISP_REG_CCORR_EN - idx * 0x1000), 1);
}
static int ddp_ccorr_start(DISP_MODULE_ENUM module, void *handle)
{
#ifdef LK_BYPASS_SHADOW_REG
	DISP_REG_SET_FIELD(handle, FLD_CCORR_BYPASS_SHADOW,
			  DISP_REG_CCORR_SHADOW_CTRL, 0x1);
	DISP_REG_SET_FIELD(handle, FLD_CCORR_READ_WRK_REG,
			  DISP_REG_CCORR_SHADOW_CTRL, 0x1);

#endif

	return 0;
}
static int ddp_aal_start(DISP_MODULE_ENUM module, void *handle)
{
#ifdef LK_BYPASS_SHADOW_REG
	DISP_REG_SET_FIELD(handle, FLD_AAL_BYPASS_SHADOW,
			  DISP_REG_AAL_SHADOW_CTRL, 0x1);
	DISP_REG_SET_FIELD(handle, FLD_AAL_READ_WRK_REG,
			  DISP_REG_AAL_SHADOW_CTRL, 0x1);

#endif

	return 0;
}

void ddp_bypass_mdp_aal(unsigned int width, unsigned int height, void * handle)
{
	dprintf(CRITICAL, "bypass mdp_aal\n");

}

void ddp_bypass_aal(unsigned int width, unsigned int height, void * handle)
{
	dprintf(CRITICAL, "bypass aal\n");
	DISP_REG_SET_FIELD(handle, CFG_FLD_RELAY_MODE,   DISP_AAL_CFG, 0x1); //relay_mode
	DISP_REG_SET(handle, DISP_AAL_SIZE, (width<<16)|height); //bypass color engine
	DISP_REG_SET(handle, DISP_AAL_OUTPUT_SIZE, (width << 16) | height);
	DISP_REG_SET(handle,DISP_AAL_EN, 0x1); //bypass mode
}

void ddp_bypass_gamma(unsigned int width, unsigned int height, void * handle)
{
	dprintf(CRITICAL, "bypass gamma\n");
	DISP_REG_MASK(NULL,DISP_REG_GAMMA_CFG, 1, 1);
	DISP_REG_SET(NULL,DISP_REG_GAMMA_SIZE, (width<<16)|height); //bypass color engine
	DISP_REG_SET(handle,DISP_REG_GAMMA_EN, 0x1); //bypass mode
}
static int ddp_gamma_start(DISP_MODULE_ENUM module, void *handle)
{
#ifdef LK_BYPASS_SHADOW_REG
	DISP_REG_SET_FIELD(handle, FLD_GAMMA_BYPASS_SHADOW,
			  DISP_REG_GAMMA_SHADOW_CTRL, 0x1);
	DISP_REG_SET_FIELD(handle, FLD_GAMMA_READ_WRK_REG,
			  DISP_REG_GAMMA_SHADOW_CTRL, 0x1);

#endif

	return 0;
}

static int ddp_color_start(DISP_MODULE_ENUM module, void *handle)
{
#ifdef LK_BYPASS_SHADOW_REG
	DISP_REG_SET_FIELD(handle, FLD_COLOR_BYPASS_SHADOW,
			  DISP_REG_COLOR_SHADOW_CTRL, 0x1);
	DISP_REG_SET_FIELD(handle, FLD_COLOR_READ_WRK_REG,
			  DISP_REG_COLOR_SHADOW_CTRL, 0x1);

#endif

	return 0;
}

static int config_color(DISP_MODULE_ENUM module, disp_ddp_path_config* pConfig, void* cmdq)
{
	int color_idx;
	if (module == DISP_MODULE_COLOR0)
		color_idx = 0;
	else
		color_idx = 1;

	dprintf(CRITICAL, "config color dirty = %d\n", pConfig->dst_dirty);
	if (!pConfig->dst_dirty) {
		return 0;
	}
	ddp_bypass_color(color_idx,pConfig->dst_w, pConfig->dst_h,cmdq);
	return 0;
}

static int config_ccorr(DISP_MODULE_ENUM module, disp_ddp_path_config* pConfig, void* cmdq)
{
	int ccorr_idx;
	if (module == DISP_MODULE_CCORR0)
		ccorr_idx = 0;
	else
		ccorr_idx = 1;
	dprintf(CRITICAL, "config ccorr%d dirty = %d\n", ccorr_idx, pConfig->dst_dirty);
	if (!pConfig->dst_dirty) {
		return 0;
	}
	ddp_bypass_ccorr(ccorr_idx, pConfig->dst_w, pConfig->dst_h,cmdq);
	return 0;
}

static int config_mdp_aal(DISP_MODULE_ENUM module, disp_ddp_path_config *pConfig, void *cmdq)
{
	dprintf(CRITICAL, "config mdp_aal dirty = %d\n", pConfig->dst_dirty);
	if (!pConfig->dst_dirty) {
		return 0;
	}
	ddp_bypass_mdp_aal(pConfig->dst_w, pConfig->dst_h,cmdq);
	return 0;
}

static int config_aal(DISP_MODULE_ENUM module, disp_ddp_path_config* pConfig, void* cmdq)
{

	dprintf(CRITICAL, "config aal dirty = %d\n", pConfig->dst_dirty);
	if (!pConfig->dst_dirty) {
		return 0;
	}
	ddp_bypass_aal(pConfig->dst_w, pConfig->dst_h,cmdq);
	return 0;
}

static int config_gamma(DISP_MODULE_ENUM module, disp_ddp_path_config* pConfig, void* cmdq)
{
	dprintf(CRITICAL, "config gamma dirty = %d\n", pConfig->dst_dirty);
	if (!pConfig->dst_dirty) {
		return 0;
	}
	ddp_bypass_gamma(pConfig->dst_w, pConfig->dst_h,cmdq);
	return 0;
}

static int clock_on(DISP_MODULE_ENUM module,void * handle)
{
	ddp_enable_module_clock(module);
	return 0;
}

static int clock_off(DISP_MODULE_ENUM module,void * handle)
{
	ddp_disable_module_clock(module);
	return 0;
}

///////////////////////////////////////////////////////////

// color
DDP_MODULE_DRIVER ddp_driver_color = {
	.init            = clock_on,
	.deinit          = clock_off,
	.config          = config_color,
	.start           = ddp_color_start,
	.trigger         = NULL,
	.stop            = NULL,
	.reset           = NULL,
	.power_on        = clock_on,
	.power_off       = clock_off,
	.is_idle         = NULL,
	.is_busy         = NULL,
	.dump_info       = NULL,
	.bypass          = NULL,
	.build_cmdq      = NULL,
	.set_lcm_utils   = NULL,
};

// ccorr
DDP_MODULE_DRIVER ddp_driver_ccorr = {
	.init            = clock_on,
	.deinit          = clock_off,
	.config          = config_ccorr,
	.start           = ddp_ccorr_start,
	.trigger         = NULL,
	.stop            = NULL,
	.reset           = NULL,
	.power_on        = clock_on,
	.power_off       = clock_off,
	.is_idle         = NULL,
	.is_busy         = NULL,
	.dump_info       = NULL,
	.bypass          = NULL,
	.build_cmdq      = NULL,
	.set_lcm_utils   = NULL,
};

// aal
DDP_MODULE_DRIVER ddp_driver_aal = {
	.init            = clock_on,
	.deinit          = clock_off,
	.config          = config_aal,
	.start           = ddp_aal_start,
	.trigger         = NULL,
	.stop            = NULL,
	.reset           = NULL,
	.power_on        = clock_on,
	.power_off       = clock_off,
	.is_idle         = NULL,
	.is_busy         = NULL,
	.dump_info       = NULL,
	.bypass          = NULL,
	.build_cmdq      = NULL,
	.set_lcm_utils   = NULL,
};

// gamma
DDP_MODULE_DRIVER ddp_driver_gamma = {
	.init            = clock_on,
	.deinit          = clock_off,
	.config          = config_gamma,
	.start           = ddp_gamma_start,
	.trigger         = NULL,
	.stop            = NULL,
	.reset           = NULL,
	.power_on        = clock_on,
	.power_off       = clock_off,
	.is_idle         = NULL,
	.is_busy         = NULL,
	.dump_info       = NULL,
	.bypass          = NULL,
	.build_cmdq      = NULL,
	.set_lcm_utils   = NULL,
};
