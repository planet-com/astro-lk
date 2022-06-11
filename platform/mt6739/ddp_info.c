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

#define LOG_TAG "INFO"

#include <platform/ddp_log.h>
#include <platform/ddp_info.h>
#include <platform/disp_drv_platform.h>

char *ddp_get_module_name(DISP_MODULE_ENUM module)
{
	switch (module) {
	case DISP_MODULE_OVL0:
		return "ovl0 ";
	case DISP_MODULE_OVL1:
		return "ovl1 ";
	case DISP_MODULE_OVL0_2L:
		return "ovl0_2l ";
	case DISP_MODULE_OVL1_2L:
		return "ovl1_2l ";
	case DISP_MODULE_OVL0_VIRTUAL:
		return "ovl0_virt ";
	case DISP_MODULE_RDMA0:
		return "rdma0 ";
	case DISP_MODULE_RDMA1:
		return "rdma1 ";
	case DISP_MODULE_RDMA2:
		return "rdma2 ";
	case DISP_MODULE_WDMA0:
		return "wdma0 ";
	case DISP_MODULE_WDMA1:
		return "wdma1 ";
	case DISP_MODULE_COLOR0:
		return "color0 ";
	case DISP_MODULE_COLOR1:
		return "color1 ";
	case DISP_MODULE_CCORR0:
		return "ccorr0 ";
	case DISP_MODULE_CCORR1:
		return "ccorr1 ";
	case DISP_MODULE_AAL0:
		return "aal0 ";
	case DISP_MODULE_AAL1:
		return "aal1 ";
	case DISP_MODULE_GAMMA0:
		return "gamma0 ";
	case DISP_MODULE_GAMMA1:
		return "gamma1 ";
	case DISP_MODULE_OD:
		return "od ";
	case DISP_MODULE_DITHER0:
		return "dither0 ";
	case DISP_MODULE_DITHER1:
		return "dither1 ";
	case DISP_MODULE_PATH0:
		return "path0 ";
	case DISP_MODULE_PATH1:
		return "path1 ";
	case DISP_MODULE_UFOE:
		return "ufoe ";
	case DISP_MODULE_DSC:
		return "dsc ";
	case DISP_MODULE_SPLIT0:
		return "split0 ";
	case DISP_MODULE_DPI:
		return "dpi ";
	case DISP_MODULE_DSI0:
		return "dsi0 ";
	case DISP_MODULE_DSI1:
		return "dsi1 ";
	case DISP_MODULE_DSIDUAL:
		return "dsidual ";
	case DISP_MODULE_PWM0:
		return "pwm0 ";
	case DISP_MODULE_CONFIG:
		return "config ";
	case DISP_MODULE_MUTEX:
		return "mutex ";
	case DISP_MODULE_SMI_COMMON:
		return "smi_common";
	case DISP_MODULE_SMI_LARB0:
		return "smi_larb0";
	case DISP_MODULE_SMI_LARB1:
		return "smi_larb1";
	case DISP_MODULE_MIPI0:
		return "mipi0";
	case DISP_MODULE_MIPI1:
		return "mipi1";
	default:
		DDPMSG("invalid module id=%d", module);
		return "unknown";
	}
}
/*
int ddp_get_module_max_irq_bit(DISP_MODULE_ENUM module)
{
    switch(module)
    {
        case DISP_MODULE_UFOE   :    return 0;
        case DISP_MODULE_AAL    :    return 1;
        case DISP_MODULE_COLOR0 :    return 2;
        case DISP_MODULE_COLOR1 :    return 2;
        case DISP_MODULE_RDMA0  :    return 5;
        case DISP_MODULE_RDMA1  :    return 5;
        case DISP_MODULE_RDMA2  :    return 5;
        case DISP_MODULE_WDMA0  :    return 1;
        case DISP_MODULE_WDMA1  :    return 1;
        case DISP_MODULE_OVL0   :    return 3;
        case DISP_MODULE_OVL1   :    return 3;
        case DISP_MODULE_GAMMA  :    return 0;
        case DISP_MODULE_PWM0   :    return 0;
        case DISP_MODULE_PWM1   :    return 0;
        case DISP_MODULE_OD     :    return 0;
        case DISP_MODULE_MERGE  :    return 0;
        case DISP_MODULE_SPLIT0 :    return 0;
        case DISP_MODULE_SPLIT1 :    return 0;
        case DISP_MODULE_DSI0   :    return 6;
        case DISP_MODULE_DSI1   :    return 6;
        case DISP_MODULE_DSIDUAL:    return 6;
        case DISP_MODULE_DPI    :    return 2;
        case DISP_MODULE_SMI    :    return 0;
        case DISP_MODULE_CONFIG :    return 0;
        case DISP_MODULE_CMDQ   :    return 0;
        case DISP_MODULE_MUTEX  :    return 14;
        case DISP_MODULE_CCORR  :    return 0;
        case DISP_MODULE_DITHER :    return 0;
        default:
             DDPERR("invalid module id=%d", module);
    }
    return 0;
}
*/
unsigned int ddp_module_to_idx(int module)
{
	unsigned int id = 0;
	switch (module) {
	case DISP_MODULE_AAL0:
	case DISP_MODULE_COLOR0:
	case DISP_MODULE_RDMA0:
	case DISP_MODULE_WDMA0:
	case DISP_MODULE_OVL0:
	case DISP_MODULE_GAMMA0:
	case DISP_MODULE_PWM0:
	case DISP_MODULE_OD:
	case DISP_MODULE_SPLIT0:
	case DISP_MODULE_DSI0:
	case DISP_MODULE_DPI:
	case DISP_MODULE_DITHER0:
	case DISP_MODULE_CCORR0:
		id = 0;
		break;

	case DISP_MODULE_COLOR1:
	case DISP_MODULE_RDMA1:
	case DISP_MODULE_DSI1:
	case DISP_MODULE_OVL1:
	case DISP_MODULE_WDMA1:
		id = 1;
		break;
	case DISP_MODULE_RDMA2:
	case DISP_MODULE_DSIDUAL:
		id = 2;
		break;
	default:
		DDPERR("ddp_module_to_idx, module=0x%x\n", module);
	}

	return id;
}


int ddp_enable_module_clock(DISP_MODULE_ENUM module)
{
	DDPMSG("ddp_enable_module_clock: %s\n", ddp_get_module_name(module));
	switch (module) {
		case DISP_MODULE_SMI_COMMON:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_SMI_COMMON,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_GALS_COMMON0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_GALS_COMMON1,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);

			DISP_REG_SET_FIELD(NULL,  FLD_CG0_SMI_COMMON,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_SMI_LARB0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_SMI_LARB0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL,  FLD_CG0_SMI_LARB0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_OVL0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_OVL0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_OVL0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_COLOR0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_COLOR0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_COLOR0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_CCORR0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_CCORR0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_CCORR0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_AAL0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_AAL0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_AAL0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_RDMA0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_RDMA0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_RDMA0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_GAMMA0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_GAMMA0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_GAMMA0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_DSI0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DSI0_MM,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DSI0_IF,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_WDMA0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_WDMA0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_WDMA0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_DITHER0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DITHER0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DITHER0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_DBI:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DBI_MM,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DBI_IF,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_MUTEX:
			break;
		default:
			DDPERR("enable module clock unknow module %d \n",module);
	}
	return 0;
}

int ddp_disable_module_clock(DISP_MODULE_ENUM module)
{
	switch (module) {
		case DISP_MODULE_SMI_COMMON:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_GALS_COMMON1,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_GALS_COMMON0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_SMI_COMMON,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_SMI_COMMON,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_SMI_LARB0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_SMI_LARB0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_SMI_LARB0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_OVL0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_OVL0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_OVL0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_COLOR0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_COLOR0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_COLOR0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_CCORR0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_CCORR0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_CCORR0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_AAL0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_AAL0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_AAL0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_RDMA0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_RDMA0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_RDMA0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_GAMMA0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_GAMMA0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_GAMMA0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_DSI0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DSI0_MM,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DSI0_IF,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_WDMA0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_WDMA0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_WDMA0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_DITHER0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DITHER0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DITHER0,DISP_REG_CONFIG_MMSYS_DUMMY0,0);
			break;
		case DISP_MODULE_DBI:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DBI_MM,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DBI_IF,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_MUTEX:
			break;
		default:
			DDPERR("disable module clock unknow module %d \n",module);
	}
	DDPMSG("disable %s clk, CG0 0x%x, CG1 0x%x,dummy CON = 0x%x\n",
	       ddp_get_module_name(module), DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON0),DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON1),DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DUMMY0));
	return 0;
}



// dsi
extern DDP_MODULE_DRIVER ddp_driver_dsi0;
/*extern DDP_MODULE_DRIVER ddp_driver_dsi1;*/
/*extern DDP_MODULE_DRIVER ddp_driver_dsidual;*/
// dpi
//extern DDP_MODULE_DRIVER ddp_driver_dpi;

// ovl
extern DDP_MODULE_DRIVER ddp_driver_ovl;
// rdma
extern DDP_MODULE_DRIVER ddp_driver_rdma;

// color
extern DDP_MODULE_DRIVER ddp_driver_color;
// ccorr
extern DDP_MODULE_DRIVER ddp_driver_ccorr;
// aal
extern DDP_MODULE_DRIVER ddp_driver_aal;
// ufoe
//extern DDP_MODULE_DRIVER ddp_driver_ufoe;
// gamma
extern DDP_MODULE_DRIVER ddp_driver_gamma;
// dither
extern DDP_MODULE_DRIVER ddp_driver_dither;
// ccorr
//extern DDP_MODULE_DRIVER ddp_driver_ccorr;
// split
//extern DDP_MODULE_DRIVER ddp_driver_split;

// pwm
//extern DDP_MODULE_DRIVER ddp_driver_pwm;

DDP_MODULE_DRIVER  *ddp_modules_driver[DISP_MODULE_NUM] = {
	&ddp_driver_ovl,	/* DISP_MODULE_OVL0 = 0, */
	0,					/* DISP_MODULE_OVL1  , */
	&ddp_driver_ovl,	/* DISP_MODULE_OVL0_2L  , */
	&ddp_driver_ovl,	/* DISP_MODULE_OVL1_2L  , */
	0,					/* DISP_MODULE_OVL0_VIRTUAL */
	0,					/* DISP_MODULE_OVL0_2L_VIRTUAL */
	0,					/* DISP_MODULE_OVL1_2L_VIRTUAL */

	&ddp_driver_rdma,	/* DISP_MODULE_RDMA0 , */
	&ddp_driver_rdma,	/* DISP_MODULE_RDMA1 , */
	0,					/* DISP_MODULE_RDMA2 , */

	0,					/* DISP_MODULE_WDMA0 , */ /*10*/
	0,					/* DISP_MODULE_WDMA1 , */
	0,					/* DISP_MODULE_WDMA_VIRTUAL0 */
	0,					/* DISP_MODULE_WDMA_VIRTUAL1 */

	&ddp_driver_color,	/* DISP_MODULE_COLOR0, */
	0,					/* DISP_MODULE_COLOR1, */
	&ddp_driver_ccorr,	/* DISP_MODULE_CCORR0 , */
	0,					/* DISP_MODULE_CCORR1 , */
	&ddp_driver_aal,	/* DISP_MODULE_AAL0   , */
	0,					/* DISP_MODULE_AAL1   , */
	&ddp_driver_gamma,	/* DISP_MODULE_GAMMA0 , */ /*20*/
	0,					/* DISP_MODULE_GAMMA1 , */
	0,					/* DISP_MODULE_OD , */
	&ddp_driver_dither,	/* DISP_MODULE_DITHER0, */
	0,					/* DISP_MODULE_DITHER1, */

	0,					/* DISP_MODULE_PATH0 */
	0,					/* DISP_MODULE_PATH1 */
	0,					/*DISP_MODULE_UFOE_VIRTUAL*/

	0,					/* DISP_MODULE_UFOE  */
	0,					/* DISP_MODULE_DSC */
	0,					/* DISP_MODULE_DSC_2ND */ /*30*/
	0,					/* DISP_MODULE_SPLIT0, */

	0,					/* DISP_MODULE_DPI   , */
	0,					/* DISP_MODULE_DBI   , */

	&ddp_driver_dsi0,	/* DISP_MODULE_DSI0  , */
	0,					/* DISP_MODULE_DSI1  , */
	0,					/* DISP_MODULE_DSIDUAL, */

	0,					/* DISP_MODULE_PWM0   , */
	0,					/* DISP_MODULE_PWM1   , */

	0,					/* DISP_MODULE_CONFIG, */
	0,					/* DISP_MODULE_MUTEX, */ /*40*/
	0,					/* DISP_MODULE_SMI_COMMON, */
	0,					/* DISP_MODULE_SMI_LARB0 , */
	0,					/* DISP_MODULE_SMI_LARB1 , */

	0,					/* DISP_MODULE_MIPI0 */
	0,					/* DISP_MODULE_MIPI1 */
	0,					/* DISP_MODULE_RSZ0 */
	0,					/* DISP_MODULE_RSZ1 */
	0,					/* DISP_MODULE_NONE, */
};

