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

extern DDP_MODULE_DRIVER ddp_driver_dsi0;
/* extern DDP_MODULE_DRIVER ddp_driver_dsi1; */
/* extern DDP_MODULE_DRIVER ddp_driver_dsidual; */
extern DDP_MODULE_DRIVER ddp_driver_ovl;
extern DDP_MODULE_DRIVER ddp_driver_rdma;
extern DDP_MODULE_DRIVER ddp_driver_color;
extern DDP_MODULE_DRIVER ddp_driver_ccorr;
extern DDP_MODULE_DRIVER ddp_driver_aal;
extern DDP_MODULE_DRIVER ddp_driver_gamma;
extern DDP_MODULE_DRIVER ddp_driver_postmask;
extern DDP_MODULE_DRIVER ddp_driver_dither;
/* extern DDP_MODULE_DRIVER ddp_driver_split; */
extern DDP_MODULE_DRIVER ddp_driver_pwm;
extern DDP_MODULE_DRIVER ddp_driver_dsc;

ddp_module  ddp_modules[DISP_MODULE_NUM] = {
		{DISP_MODULE_CONFIG, "disp_config", 0, NULL},
		{DISP_MODULE_MUTEX,"mutex", 0, NULL},
		{DISP_MODULE_SMI_COMMON,"sim_common",0,NULL},
		{DISP_MODULE_SMI_LARB0,"smi_larb0",0,NULL},
		{DISP_MODULE_SMI_LARB1,"smi_larb1",0,NULL},

		{DISP_MODULE_OVL0,"ovl0",1,&ddp_driver_ovl},
		{DISP_MODULE_OVL0_2L,"ovl0_2l",1,&ddp_driver_ovl},
		{DISP_MODULE_RDMA0,"rdma0",1,&ddp_driver_rdma},
		{DISP_MODULE_RSZ0,"disp_rsz0",1,NULL},
		{DISP_MODULE_COLOR0,"color0",1,&ddp_driver_color},

		{DISP_MODULE_CCORR0,"ccorr0",1,&ddp_driver_ccorr},
		{DISP_MODULE_AAL0,"aal0",1,&ddp_driver_aal},
		{DISP_MODULE_GAMMA0,"gamma0",1,&ddp_driver_gamma},
		{DISP_MODULE_POSTMASK0,"postmask0",1,&ddp_driver_postmask},
		{DISP_MODULE_DITHER0,"dither0",1,&ddp_driver_dither},

		{DISP_MODULE_DSC,"dsc0",1,&ddp_driver_dsc},
		{DISP_MODULE_DSC_WRAP0_CORE1,"dsc_wrap0_core1",1,NULL},
		{DISP_MODULE_DSI0,"dsi0",1,&ddp_driver_dsi0},
		{DISP_MODULE_WDMA0,"wdma0",1,NULL},
		{DISP_MODULE_UFBC_WDMA0,"wdma0",1,NULL},

		{DISP_MODULE_OVL2_2L,"ovl2_2l",1,&ddp_driver_ovl},
		{DISP_MODULE_RDMA4,"rdma4",1,&ddp_driver_rdma},
		{DISP_MODULE_DPI,"dpi",1,NULL},
		{DISP_MODULE_MDP_RDMA4,"mdp_rdma4",1,NULL},
		{DISP_MODULE_MDP_HDR4,"mdp_hdr4",1,NULL},

		{DISP_MODULE_MDP_RSZ4,"mdp_rsz4",1,NULL},
		{DISP_MODULE_MDP_AAL4,"mdp_aal4",1,&ddp_driver_aal},
		{DISP_MODULE_MDP_TDSHP4,"mdp_tdshp4",1,NULL},
		{DISP_MODULE_MDP_COLOR4,"mdp_color4",1,NULL},
		{DISP_MODULE_Y2R0,"y2r0",1,NULL},

		{DISP_MODULE_PWM0,"pwm0",0,NULL},
		{DISP_MODULE_DSIDUAL,"dsidual",0,NULL},
		{DISP_MODULE_DSI1,"dsi1",0,NULL},
		{DISP_MODULE_MIPI0,"mipi0",0,NULL},
		{DISP_MODULE_MIPI1,"mipi1",0,NULL},

		{DISP_MODULE_OVL0_2L_VIRTUAL0,"ovl0_2l_virt",1,NULL},
		{DISP_MODULE_OVL0_VIRTUAL0,"ovl0_virt",1,NULL},
		{DISP_MODULE_OVL0_OVL0_2L_VIRTUAL,"ovl0_ovl0_2l_virt",1,NULL},
		{DISP_MODULE_RDMA2_VIRTUAL,"rdma2_virt",1,NULL},
		{DISP_MODULE_DMDP_TDSHP4_SOUT,"dmdp_tdshp4_sout",1,NULL},

		{DISP_MODULE_SPLIT0,"split0",0,NULL},
		{DISP_MODULE_UNKNOWN,"unknown",0,NULL},
};


DDP_MODULE_DRIVER  *ddp_modules_driver[DISP_MODULE_NUM] = {0};
/* PMMSYS_CONFIG_REGS g_MMSYS_CONFIG_BASE = (PMMSYS_CONFIG_REGS)MMSYS_CONFIG_BASE; */
PDISP_SPLIT_REGS   g_DISP_SPLIT_BASE   = (PDISP_SPLIT_REGS)DISP_SPLIT0_BASE;
/* PDISP_DSI0_REGS    g_DISP_DSI0_BASE    = (PDISP_DSI0_REGS)DSI0_BASE; */
PDISP_MUTEX_REGS   g_DISP_MUTEX_BASE   = (PDISP_MUTEX_REGS)MM_MUTEX_BASE;
PDISP_OVL0_REGS    g_DISP_OVL0_BASE    = (PDISP_OVL0_REGS)OVL0_BASE;
/* Pmipi_tx_config_REGS g_mipi_tx_config0_BASE = (Pmipi_tx_config_REGS)MIPI_TX0_BASE; */

int ddp_enable_module_clock(DISP_MODULE_ENUM module)
{
#ifdef DISP_HELPER_STAGE_NORMAL_LK
	switch (module) {
		/* MMSYS_CG_CON0 */
		case DISP_MODULE_SMI_COMMON:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_MUTEX0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISPSYS_CONFIG,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL,FLD_CG0_SMI_COMMON,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL,FLD_CG0_SMI_GALS,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL,FLD_CG0_SMI_INFRA,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL,FLD_CG1_SMI_IOMMU,DISP_REG_CONFIG_MMSYS_CG_CLR1,1);
			break;
		case DISP_MODULE_SMI_LARB0:
			/* DISP_REG_SET_FIELD(NULL,FLD_CG0_SMI_LARB0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1); */
			break;
		case DISP_MODULE_SMI_LARB1:
			 /* DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_SMI_LARB1,DISP_REG_CONFIG_MMSYS_CG_CLR0,1); */
			break;
		case DISP_MODULE_OVL0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_OVL0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_OVL0_2L:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_OVL0_2L,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_RDMA0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_RDMA0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_WDMA0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_WDMA0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_COLOR0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_COLOR0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_CCORR0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_CCORR0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_AAL0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_AAL0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_MDP_AAL4:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_MDP_AAL4,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_GAMMA0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_GAMMA0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_POSTMASK0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_POSTMASK0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_DITHER0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DITHER0,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			break;
		case DISP_MODULE_DSI0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DSI0_MM,DISP_REG_CONFIG_MMSYS_CG_CLR0,1);
			DISP_REG_SET_FIELD(NULL,FLD_CG2_DSI0,DISP_REG_CONFIG_MMSYS_CG_CLR2,1);
			break;
		case DISP_MODULE_RSZ0:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DISP_RSZ0, DISP_REG_CONFIG_MMSYS_CG_CLR0, 1);
			break;
		case DISP_MODULE_DSC:
			DISP_REG_SET_FIELD(NULL, FLD_CG0_DISP_DSC, DISP_REG_CONFIG_MMSYS_CG_CLR0, 1);
			break;
		default:
			DDPERR("enable module clock unknow module %d \n",module);
	}
#endif
	return 0;
}

int ddp_disable_module_clock(DISP_MODULE_ENUM module)
{
#ifdef DISP_HELPER_STAGE_NORMAL_LK
	switch (module) {
		/* MMSYS_CG_CON0 */
		case DISP_MODULE_SMI_COMMON:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_MUTEX0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISPSYS_CONFIG,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL,FLD_CG1_SMI_IOMMU,DISP_REG_CONFIG_MMSYS_CG_SET1,1);
			DISP_REG_SET_FIELD(NULL,FLD_CG0_SMI_INFRA,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL,FLD_CG0_SMI_GALS,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			DISP_REG_SET_FIELD(NULL,FLD_CG0_SMI_COMMON,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_SMI_LARB0:
			/* DISP_REG_SET_FIELD(NULL,FLD_CG0_SMI_LARB0,DISP_REG_CONFIG_MMSYS_CG_SET0,1); */
			break;
		case DISP_MODULE_SMI_LARB1:
			/* DISP_REG_SET_FIELD(NULL,MMSYS_CG_FLD_CG0_SMI_LARB1,DISP_REG_CONFIG_MMSYS_CG_SET0,1); */
			break;
		case DISP_MODULE_OVL0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_OVL0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_OVL0_2L:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_OVL0_2L,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_RDMA0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_RDMA0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_WDMA0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_WDMA0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_COLOR0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_COLOR0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_CCORR0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_CCORR0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_AAL0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_AAL0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_MDP_AAL4:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_MDP_AAL4,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_GAMMA0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_GAMMA0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_POSTMASK0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_POSTMASK0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_DITHER0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DITHER0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_DSI0:
			DISP_REG_SET_FIELD(NULL,FLD_CG2_DSI0,DISP_REG_CONFIG_MMSYS_CG_SET2,1);
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DSI0_MM,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		case DISP_MODULE_RSZ0:
			DISP_REG_SET_FIELD(NULL,FLD_CG0_DISP_RSZ0,DISP_REG_CONFIG_MMSYS_CG_SET0,1);
			break;
		default:
			DDPERR("disable module clock unknow module %d \n",module);
	}
#endif
	DDPMSG("disable %s clk, CG0 0x%x, CG1 0x%x",
	       ddp_get_module_name(module),
	       DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON0),
	       DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON1));
	return 0;
}


unsigned int is_ddp_module(DISP_MODULE_ENUM module)
{
	if (module >= 0 && module < DISP_MODULE_NUM)
		return 1;
	else 
		return 0;
}

char *ddp_get_module_name(DISP_MODULE_ENUM module)
{
	if (is_ddp_module(module)) {
		return ddp_modules[module].module_name;
	} else {
		DDPMSG("invalid module id=%d", module);
		return "unknown";
	}
}


void ddp_init_modules_driver(void)
{
	unsigned int i = 0;
	for (i = 0; i < DISP_MODULE_NUM; i++) {
		ddp_modules_driver[i] = ddp_modules[i].module_driver;
	}
}

