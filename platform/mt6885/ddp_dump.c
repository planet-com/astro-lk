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

#define LOG_TAG "DUMP"

#include <platform/ddp_info.h>
#include <platform/ddp_log.h>
#include <platform/ddp_path.h>
#include <platform/ddp_dump.h>
#include <platform/ddp_rdma.h>
#include <platform/disp_drv_platform.h>
#include "platform/ddp_reg.h"
#include <platform/ddp_dsi.h>
#include <platform/ddp_postmask.h>


static const char* ddp_signal[6][32] = {
	{
		"AFBC_WDMA0_SEL__TO__DISP_UFBC_WDMA0",
		"AFBC_WDMA1_SEL__TO__DISP_UFBC_WDMA1",
		"DISP_AAL0__TO__DISP_GAMMA0",
		"DISP_AAL0_SEL__TO__DISP_AAL0",
		"DISP_AAL1__TO__DISP_GAMMA1",
		"DISP_CCORR0__TO__DISP_CCORR0_SOUT",
		"DISP_CCORR0_SOUT_OUT0__TO__DISP_MDP_AAL4_SEL_IN0",
		"DISP_CCORR0_SOUT_OUT1__TO__DISP_AAL0_SEL_IN1",
		"DISP_CCORR1__TO__DISP_CCORR1_SOUT",
		"DISP_CCORR1_SOUT_OUT0__TO__DISP_MDP_AAL5_SEL_IN0",
		"DISP_CCORR1_SOUT_OUT1__TO__MDP_AAL1_SEL_IN1",
		"DISP_COLOR0__TO__DISP_COLOR0_OUT_SEL_IN0",
		"DISP_COLOR0_OUT_SEL__TO__DISP_CCORR0",
		"DISP_COLOR1__TO__DISP_COLOR1_OUT_SEL_IN0",
		"DISP_COLOR1_OUT_SEL__TO__DISP_CCORR1",
		"DISP_DITHER0__TO__DISP_DITHER0_MOUT",
		"DISP_DITHER0_MOUT_OUT0__TO__DSI0_SEL_IN1",
		"DISP_DITHER0_MOUT_OUT1__to__DISP_WDMA0_SEL_IN0",
		"DISP_DITHER0_MOUT_OUT2__TO__DSI1_SEL_IN2",
		"DISP_DITHER0_MOUT_OUT3__TO__DISP_PQ0_SOUT",
		"DISP_DITHER1__TO__DISP_DITHER1_MOUT",
		"DISP_DITHER1_MOUT_OUT0__TO__DSI1_SEL_IN1",
		"DISP_DITHER1_MOUT_OUT1__TO__DISP_WDMA1_SEL_IN0",
		"DISP_DITHER1_MOUT_OUT2__TO__DISP_PQ1_SOUT",
		"DISP_DP_WRAP_SEL__TO__DP_INTD0",
		"DISP_DSC_WRAP0_OUT0__TO__DISP_DSC_WRAP_SOUT",
		"DISP_DSC_WRAP0_OUT1__TO__DSI1_SEL_IN3",
		"DISP_DSC_WRAP_SOUT_OUT0__TO__DSI0_SEL_IN3",
		"DISP_DSC_WRAP_SOUT_OUT1__TO__DISP_DP_WRAP_SEL_IN0",
		"DISP_DSI0_DSC_WRAP_SOUT_OUT0__TO__DSI0_SEL_IN2",
		"DISP_DSI0_DSC_WRAP_SOUT_OUT1__TO__DISP_DSC_WRAP0_IN0",
		"DISP_GAMMA0__TO__DISP_POSTMASK0",
	},
	{
		"DISP_GAMMA1__TO__DISP_POSTMASK1",
		"DISP_MDP_AAL4_MDP_HDR4_SEL__TO__MDP_RSZ4",
		"DISP_MDP_AAL4_SEL__TO__MDP_AAL4",
		"DISP_MDP_AAL4_SOUT_OUT0__TO__DISP_AAL0_SEL_IN0",
		"DISP_MDP_AAL4_SOUT_OUT1__TO__DISP_MDP_AAL4_MDP_HDR4_SEL_IN1",
		"DISP_MDP_AAL5_MDP_HDR5_SEL__TO__MDP_RSZ5",
		"DISP_MDP_AAL5_SEL__TO__MDP_AAL5",
		"DISP_MDP_AAL5_SOUT_OUT0__TO__MDP_AAL1_SEL_IN0",
		"DISP_MDP_AAL5_SOUT_OUT1__TO__DISP_MDP_AAL5_MDP_HDR5_SEL_IN1",
		"DISP_MDP_TDSHP4_SOUT_OUT0__TO__DISP_OVL0_2L_IN1",
		"DISP_MDP_TDSHP4_SOUT_OUT1__TO__DISP_OVL0_IN1",
		"DISP_MDP_TDSHP5_SOUT_OUT0__TO__DISP_OVL1_2L_IN1",
		"DISP_MDP_TDSHP5_SOUT_OUT1__TO__DISP_OVL1_IN1",
		"DISP_MERGE0__TO__DISP_RDMA4_PQ0_MERGE0_SEL_IN2",
		"DISP_MERGE1__TO__DISP_DP_WRAP_SEL_IN1",
		"DISP_OVL0_2L_BLENDOUT_SOUT_OUT0__TO__DISP_TOVL0_OUT0_SEL_IN0",
		"DISP_OVL0_2L_BLENDOUT_SOUT_OUT1__TO__DISP_TOVL0_OUT1_SEL_IN0",
		"DISP_OVL0_2L_OUT0__TO__DISP_OVL0_2L_BLENDOUT_SOUT",
		"DISP_OVL0_2L_OUT1__TO__DISP_OVL0_2L_OVL1_OVL1_2L_BGOUT_SEL_IN1",
		"DISP_OVL0_2L_OUT2__TO__DISP_OVL0_OVL0_2L_PGOUT_SEL_IN1",
		"DISP_OVL0_2L_OVL1_OVL1_2L_BGOUT_SEL__TO__DISP_OVL0_IN0",
		"DISP_OVL0_BLENDOUT_SOUT_OUT0__TO__DISP_TOVL0_OUT0_SEL_IN1",
		"DISP_OVL0_BLENDOUT_SOUT_OUT1__TO__DISP_TOVL0_OUT1_SEL_IN1",
		"DISP_OVL0_OUT0__TO__DISP_OVL0_BLENDOUT_SOUT",
		"DISP_OVL0_OUT1__TO__DISP_OVL0_OVL1_OVL1_2L_BGOUT_SEL_IN1",
		"DISP_OVL0_OUT2__TO__DISP_OVL0_OVL0_2L_PGOUT_SEL_IN0",
		"DISP_OVL0_OVL0_2L_PGOUT_SEL__TO__DISP_TOVL0_PQOUT_MDP_RDMA4_SEL_IN1",
		"DISP_OVL0_OVL1_OVL1_2L_BGOUT_SEL__TO__DISP_OVL0_2L_IN0",
		"DISP_OVL1_2L_BGOUT_SOUT_OUT0__TO__DISP_OVL1_IN0",
		"DISP_OVL1_2L_BGOUT_SOUT_OUT1__TO__DISP_OVL1_OVL1_2L_BGOUT_SEL_IN0",
		"DISP_OVL1_2L_BLENDOUT_SOUT_OUT0__TO_DISP_TOVL1_OUT0_SEL_IN0",
		"DISP_OVL1_2L_BLENDOUT_SOUT_OUT1__TO__DISP_OVL1_OVL1_2L_BGOUT_SEL_IN0",
	},
	{
		"DISP_OVL1_2L_OUT0__TO__DISP_OVL1_2L_BLENDOUT_SOUT",
		"DISP_OVL1_2L_OUT1__TO__DISP_OVL1_2L_BGOUT_SOUT",
		"DISP_OVL1_2L_OUT2__TO__DISP_OVL1_OVL1_2L_PQOUT_SEL_IN1",
		"DISP_OVL1_BGOUT_SOUT_OUT0__TO__DISP_OVL1_2L_IN0",
		"DISP_OVL1_BGOUT_SOUT_OUT1__TO__DISP_OVL1_OVL1_2L_BGOUT_SEL_IN1",
		"DISP_OVL1_BLENDOUT_SOUT_OUT0__TO__DISP_TOVL1_OUT0_SEL_IN1",
		"DISP_OVL1_BLENDOUT_SOUT_OUT1__TO__DISP_TOVL1_OUT1_SEL_IN1",
		"DISP_OVL1_OUT0__TO__DISP_OVL1_BLENDOUT_SOUT",
		"DISP_OVL1_OUT1__TO__DISP_OVL1_BGOUT_SOUT",
		"DISP_OVL1_OUT2__TO__DISP_OVL1_OUT1_2L_PQOUT_SEL_IN0",
		"DISP_OVL1_OVL1_2L_BGOUT_SEL__TO__DISP_OVL1_OVL1_2L_BGOUT_SOUT",
		"DISP_OVL1_OVL1_2L_BGOUT_SOUT_OUT0__TO__DISP_OVL0_OVL1_OVL1_2L_BGOUT_SEL_IN",
		"DISP_OVL1_OVL1_2L_BGOUT_SOUT_OUT1__TO__DISP_OVL0_2L_OUT1_OVL1_2L_BGOUT_SEL_IN",
		"DISP_OVL1_OVL1_2L_PQOUT_SEL__TO__DISP_TOVL1_PQOUT_MDP_RDMA5_SEL_IN1",
		"DISP_OVL2_2L__TO__DISP_OVL2_2L_OUT0_MOUT",
		"DISP_OVL2_2L_OUT0_MOUT_OUT0__TO__DISP_RDMA4",
		"DISP_OVL2_2L_OUT0_MOUT_OUT1__TO__DISP_WDMA0_SEL_IN4",
		"DISP_OVL3_2L_OUT0__TO__DISP_OVL3_2L_OUT0_MOUT",
		"DISP_OVL3_2L_OUT0_MOUT_OUT0__TO__DISP_RDMA5",
		"DISP_OVL3_2L_OUT0_MOUT_OUT1__TO__DISP_WDMA1_SEL_IN4",
		"DISP_OVL3_2L_OUT1__TO__DISP_OVL2_2L",
		"DISP_POSTMASK0__TO__DISP_DITHER0",
		"DISP_POSTMASK1__TO__DISP_DITHER1",
		"DISP_PQ0_SOUT_OUT0__TO__DISP_MERGE0_IN0",
		"DISP_PQ0_SOUT_OUT1__TO__DISP_RDMA4_PQ0_MERGE0_SEL_IN1",
		"DISP_PQ1_SOUT_OUT0__TO__DISP_MERGE0_IN0",
		"DISP_PQ1_SOUT_OUT1__TO__DISP_RDMA5_PQ1_SEL_IN1",
		"DISP_RDMA0__TO__DISP_RDMA0_SOUT",
		"DISP_RDMA0_RSZ0_SEL__TO__DISP_RDMA0_RSZ0_SOUT",
		"DISP_RDMA0_RSZ0_SOUT_OUT0__TO__DSI0_SEL_IN0",
		"DISP_RDMA0_RSZ0_SOUT_OUT1__TO__DISP_COLOR0",
		"DISP_RDMA0_RSZ0_SOUT_OUT2__TO_DISP_COLOR0_OUT_SEL_IN1",
	},
	{
		"DISP_RDMA0_SEL__TO__DISP_RDMA0",
		"DISP_RDMA0_SOUT_OUT0__TO__DISP_RDMA0_RSZ0_SEL_IN0",
		"DISP_RDMA0_SOUT_OUT1__TO__DISP_RSZ0_SEL_IN2",
		"DISP_RDMA1__TO__DISP_RDMA1_SOUT",
		"DISP_RDMA1_TSZ1_SEL__TO__DISP_RDMA1_RSZ1_SOUT",
		"DISP_RDMA1_RSZ1_SOUT_OUT0__TO__DSI1_SEL_IN0",
		"DISP_RDMA1_RsZ1_SOUT_OUT1__TO__DISP_COLOR1",
		"DISP_RDMA1_RSZ1_SOUT_OUT2__TO__DISP_COLOR1_OUT_SEL_IN1",
		"DISP_RDMA1_SEL__TO__DISP_RDMA1",
		"DISP_RDMA1_SOUT_OUT0__TO__DISP_RDMA1_RSZ1_SEL_IN0",
		"DISP_RDMA1_SOUT_OUT1__TO__DISP_RSZ1_SEL_IN2",
		"DISP_RDMA2_RSZ0_RSZ1_SEL__TO__DISP_RDMA2_RSZ0_RSZ1_SOUT",
		"DISP_RDMA2_RSZ0_RSZ1_SOUT_OUT0__TO__DISP_OVL0_2L_IN2",
		"DISP_RDMA2_RSZ0_RSZ1_SOUT_OUT1__TO__DISP_OVL0_IN2",
		"DISP_RDMA3_SOUT_OUT0__TO__DISP_OVL1_2L_IN2",
		"DISP_RDMA3_SOUT_OUT1__TO__DISP_OVL1_IN2",
		"DISP_RDMA4__TO__DISP_RDMA4_SOUT",
		"DISP_RDMA4_PQ0_MERGE0_SEL__TO__DISP_DSI0_DSC_WRAP_SOUT",
		"DISP_RDMA4_SOUT_OUT0__TO__DISP_MERGE1_IN0",
		"DISP_RDMA4_SOUT_OUT1__TO__DISP_RDMA4_PQ0_MERGE0_SEL_IN0",
		"DISP_RDMA4_SOUT_OUT2__TO__DISP_DP_WRAP_SEL_IN2",
		"DISP_RDMA5__TO__DISP_RDMA5_SOUT",
		"DISP_RDMA5_PQ1_SEL__TO__DISP_DSC_WRAP0_IN1",
		"DISP_RDMA5_SOUT_OUT0__TO__DISP_MERGE1_IN1",
		"DISP_RDMA5_SOUT_OUT1__TO__DISP_RDMA5_PQ1_SEL_IN0",
		"DISP_RSZ0__TO__DISP_RSZ0_MOUT",
		"DISP_RSZ0_MOUT_OUT0__TO__DISP_RDMA0_SEL_IN1",
		"DISP_RSZ0_MOUT_OUT1__TO__DISP_WDMA0_SEL_IN1",
		"DISP_RSZ0_MOUT_OUT2__TO__DISP_RDMA0_RSZ0_SEL_IN1",
		"DISP_RSZ0_MOUT_OUT3__TO_DISP_RDMA2_RSZ0_RSZ1_SEL_IN0",
		"DISP_RSZ0_SEL__TO__DISP_RSZ0",
		"DISP_RSZ1__TO__DISP_RSZ1_MOUT",
	},
	{
		"DISP_RSZ1_MOUT_OUT0__TO__DISP_RDMA1_SEL_IN1",
		"DISP_RSZ1_MOUT_OUT1__TO__DISP_WDMA1_SEL_IN1",
		"DISP_RSZ1_MOUT_OUT2__TO__DISP_RDMA1_RSZ1_SEL_IN1",
		"DISP_RSZ1_MOUT_OUT3__TO__DISP_RDMA2_RSZ0_RSZ1_SEL_IN1",
		"DISP_RSZ1_MOUT_OUT4__TO__DISP_RDMA3_SOUT",
		"DISP_RSZ1_SEL__TO__DISP_RSZ1",
		"DISP_TOVL0_OUT0_MOUT_OUT0__TO__DISP_WDMA0_SEL_IN2",
		"DISP_TOVL0_OUT0_MOUT_OUT1__TO__DISP_RSZ0_SEL_IN0",
		"DISP_TOVL0_OUT0_MOUT_OUT2__TO__AFBC_WDMA0_SEL_IN0",
		"DISP_TOVL0_OUT0_SEL__TO__DISP_TOVL0_OUT0_MOUT",
		"DISP_TOVL0_OUT1_MOUT_OUT0__TO__DISP_RDMA0_SEL_IN0",
		"DISP_TOVL0_OUT1_MOUT_OUT1__TO__DISP_RSZ0_SEL_IN1",
		"DISP_TOVL0_OUT1_MOUT_OUT2__TO__DISP_WDMA0_SEL_IN3",
		"DISP_TOVL0_OUT1_MOUT_OUT3__TO__AFBC_WDMA0_SEL_IN1",
		"DISP_TOVL0_OUT1_SEL__TO__DISP_TOVL0_OUT1_MOUT",
		"DISP_TOVL0_PQOUT_MDP_RDMA4_SEL__TO__MDP_HDR4",
		"DISP_TOVL1_OUT0_MOUT_OUT0__TO__DISP_WDMA1_SEL_IN2",
		"DISP_TOVL1_OUT0_MOUT_OUT1__TO__DISP_RSZ1_SEL_IN0",
		"DISP_TOVL1_OUT0_MOUT_OUT2__TO__AFBC_WDMA1_SEL_IN0",
		"DISP_TOVL1_OUT0_SEL__TO__DISP_TOVL1_OUT0_MOUT",
		"DISP_TOVL1_OUT1_MOUT_OUT0__TO__DISP_RDMA1_SEL_IN0",
		"DISP_TOVL1_OUT1_MOUT_OUT1__TO__DISP_RSZ1_SEL_IN1",
		"DISP_TOVL1_OUT1_MOUT_OUT2__TO__DISP_WDMA1_SEL_IN3",
		"DISP_TOVL1_OUT1_MOUT_OUT3__TO__AFBC_WDMA1_SEL_IN1",
		"DISP_TOVL1_OUT1_SEL__TO__DISP_TOVL1_OUT1_MOUT",
		"DISP_TOVL1_PQOUT_MDP_RDMA5_SEL__TO__MDP_HDR5",
		"DISP_WDMA0_SEL__TO__DISP_WDMA0",
		"DISP_WDMA1_SEL__TO__DISP_WDMA1",
		"DSI0_SEL__TO__THP_LMT_DSI0",
		"DSI1_SEL__TO__THP_LMT_DSI1",
		"MDP_AAL1_SEL__TO__DISP_AAL1",
		"MDP_AAL4__TO__DISP_MDP_AAL4_SOUT",
	},
	{
		"MDP_AAL4_SOUT_OUT0__TO__DISP_MDP_AAL4_MDP_HDR4_SEL_IN0",
		"MDP_AAL4_SOUT_OUT1__TO__DISP_MDP_AAL4_SEL_IN1",
		"MDP_AAL5__TO__DISP_MDP_AAL5_SOUT",
		"MDP_AAL5_SOUT_OUT0__TO__DISP_MDP_AAL5_MDP_HDR5_SEL_IN0",
		"MDP_AAL5_SOUT_OUT1__TO__DIS_MDP_AAL5_SEL_IN1",
		"MDP_HDR4__TO__MDP_AAL4_SOUT",
		"MDP_HDR5__TO__MDP_AAL5_SOUT",
		"MDP_RDMA4__TO__DISP_TOVL0_PQOUT_MDP_RDMA4_SEL_IN0",
		"MDP_RDMA5__TO__DISP_TOVL1_PQOUT_MDP_RDMA5_SEL_IN0",
		"MDP_RSZ4__TO__MDP_TDSHP4",
		"MDP_RSZ5__TO__MDP_TDSHP5",
		"MDP_TDSHP4__TO__DISP_MDP_TDSHP4_SOUT",
		"MDP_TDSHP5__TO__DISP_MDP_TDSHP5_SOUT",
		"THP_LMT_DSI1__TO__DSI1",
	},

};

static char *ddp_greq_name(int bit)
{
	switch (bit) {
	case 0:
		return "OVL0";
	case 1:
		return "OVL0_2L";
	case 2:
		return "DISP_RDMA0";
	case 3:
		return "DISP_WDMA0";
	case 4:
		return "MDP_RDMA0";
	case 5:
		return "MDP_WDMA0";
	case 6:
		return "MDP_WROT0";
	case 7:
		return "DISP_FAKE";
	default:
		return NULL;
	}
}

static char *ddp_get_mutex_module0_name(unsigned int bit)
{
	switch (bit) {
		case 0:  return "disp_ovl0";
		case 1:  return "disp_ovl0_2l";
		case 2:  return "disp_rdma0";
		case 3: return "disp_wdma0";
		case 4: return "disp_color0";
		case 5: return "disp_ccorr0";
		case 6: return "disp_aal0";
		case 7: return "disp_gamma0";
		case 8: return "disp_dither0";
		case 9: return "dsi0";
		case 10: return "disp_rsz0";
		case 11: return "disp_pwm0";
		case 12: return "disp_ovl1";
		case 13: return "disp_ovl1_2l";
		case 14: return "disp_rdma1";
		case 15: return "disp_wdma1";
		case 16: return "disp_color1";
		case 17: return "disp_ccorr1";
		case 18: return "disp_aal1";
		case 19: return "disp_gamma1";
		case 20: return "disp_dither1";
		case 21: return "dsi1";
		case 22: return "disp_rsz1";
		case 23: return "disp_ovl2";
		case 24: return "disp_ovl3";
		case 25: return "disp_postmask0";
		case 26: return "disp_postmask1";
		case 27: return "disp_merge0";
		case 28: return "disp_merge1";
		case 29: return "disp_dsc_wrap";
		case 30: return "disp_dsc_wrap_1";
		case 31: return "dp_intf";
		default: return "mutex-unknown";
	}
}
static char *ddp_get_mutex_module1_name(unsigned int bit)
{
	switch (bit) {
		case 0:  return "mdp_aal4";
		default: return "mutex-unknown";
	}
}

char *ddp_get_fmt_name(DISP_MODULE_ENUM module, unsigned int fmt)
{
	if (module == DISP_MODULE_WDMA0) {
		switch (fmt) {
		case 0:
			return "rgb565";
		case 1:
			return "rgb888";
		case 2:
			return "rgba8888";
		case 3:
			return "argb8888";
		case 4:
			return "uyvy";
		case 5:
			return "yuy2";
		case 7:
			return "y-only";
		case 8:
			return "iyuv";
		case 12:
			return "nv12";
		default:
			DDPDUMP("ddp_get_fmt_name, unknown fmt=%d, module=%d\n", fmt, module);
			return "unknown";
		}
	} else if (module == DISP_MODULE_OVL0) {
		switch (fmt) {
		case 0:
			return "rgb565";
		case 1:
			return "rgb888";
		case 2:
			return "rgba8888";
		case 3:
			return "argb8888";
		case 4:
			return "uyvy";
		case 5:
			return "yuyv";
		default:
			DDPDUMP("ddp_get_fmt_name, unknown fmt=%d, module=%d\n", fmt, module);
			return "unknown";
		}
	} else if (module == DISP_MODULE_RDMA0) {
		switch (fmt) {
		case 0:
			return "rgb565";
		case 1:
			return "rgb888";
		case 2:
			return "rgba8888";
		case 3:
			return "argb8888";
		case 4:
			return "uyvy";
		case 5:
			return "yuyv";
		default:
			DDPDUMP("ddp_get_fmt_name, unknown fmt=%d, module=%d\n", fmt, module);
			return "unknown";
		}
	} else {
		DDPDUMP("ddp_get_fmt_name, unknown module=%d\n", module);
	}

	return "unknown";
}

static char *ddp_clock_0(int bit)
{
	switch (bit) {
	case 7:
		return "ovl0, ";
	case 8:
		return "ovl0_2L, ";
	case 9:
		return "disp_rsz0, ";
	case 10:
		return "rdma0, ";
	case 11:
		return "wdma0, ";
	case 12:
		return "color, ";
	case 13:
		return "ccorr, ";
	case 14:
		return "aal, ";
	case 15:
		return "gamma, ";
	case 16:
		return "dither, ";
	case 17:
		return "dsi0_mm(cg), ";
	case 19:
		return "smi_common(cg), ";
	case 20:
		return "smi_larb0(cg), ";
	case 21:
		return "smi_comm0(cg), ";
	case 22:
		return "smi_comm1(cg), ";
	case 28:
		return "dsi0_interface(cg), ";
	case 29:
		return "26M, ";
	default:
		return NULL;
	}
}

/* no need ddp_clock_1 */
/*
*	static char *ddp_clock_1(int bit)
*	{
*		switch (bit) {
*		case 0:
*			return "dsi0_mm(cg), ";
*		case 1:
*			return "dsi0_interface(cg), ";
*		case 7:
*			return "26M, ";
*		default:
*			return NULL;
*		}
*	}
*/


static void mutex_dump_reg(void)
{
	unsigned long module_base = DISPSYS_MUTEX_BASE;

	DDPDUMP("== START: DISP MUTEX registers ==\n");
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0, INREG32(module_base + 0x0),
		0x4, INREG32(module_base + 0x4),
		0x8, INREG32(module_base + 0x8),
		0xC, INREG32(module_base + 0xC));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x10, INREG32(module_base + 0x10),
		0x14, INREG32(module_base + 0x14),
		0x18, INREG32(module_base + 0x18),
		0x1C, INREG32(module_base + 0x1C));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x020, INREG32(module_base + 0x020),
		0x024, INREG32(module_base + 0x024),
		0x028, INREG32(module_base + 0x028),
		0x02C, INREG32(module_base + 0x02C));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x030, INREG32(module_base + 0x030),
		0x034, INREG32(module_base + 0x034),
		0x038, INREG32(module_base + 0x038),
		0x03C, INREG32(module_base + 0x03C));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x040, INREG32(module_base + 0x040),
		0x044, INREG32(module_base + 0x044),
		0x048, INREG32(module_base + 0x048),
		0x04C, INREG32(module_base + 0x04C));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x050, INREG32(module_base + 0x050),
		0x060, INREG32(module_base + 0x060),
		0x064, INREG32(module_base + 0x064),
		0x068, INREG32(module_base + 0x068));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x06C, INREG32(module_base + 0x06C),
		0x070, INREG32(module_base + 0x070),
		0x080, INREG32(module_base + 0x080),
		0x084, INREG32(module_base + 0x084));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x088, INREG32(module_base + 0x088),
		0x08C, INREG32(module_base + 0x08C),
		0x090, INREG32(module_base + 0x090),
		0x0A0, INREG32(module_base + 0x0A0));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0A4, INREG32(module_base + 0x0A4),
		0x0A8, INREG32(module_base + 0x0A8),
		0x0AC, INREG32(module_base + 0x0AC),
		0x0B0, INREG32(module_base + 0x0B0));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0C0, INREG32(module_base + 0x0C0),
		0x0C4, INREG32(module_base + 0x0C4),
		0x0C8, INREG32(module_base + 0x0C8),
		0x0CC, INREG32(module_base + 0x0CC));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0D0, INREG32(module_base + 0x0D0),
		0x0E0, INREG32(module_base + 0x0E0),
		0x0E4, INREG32(module_base + 0x0E4),
		0x0E8, INREG32(module_base + 0x0E8));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0EC, INREG32(module_base + 0x0EC),
		0x0F0, INREG32(module_base + 0x0F0),
		0x100, INREG32(module_base + 0x100),
		0x104, INREG32(module_base + 0x104));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x108, INREG32(module_base + 0x108),
		0x10C, INREG32(module_base + 0x10C),
		0x110, INREG32(module_base + 0x110),
		0x120, INREG32(module_base + 0x120));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x124, INREG32(module_base + 0x124),
		0x128, INREG32(module_base + 0x128),
		0x12C, INREG32(module_base + 0x12C),
		0x130, INREG32(module_base + 0x130));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x140, INREG32(module_base + 0x140),
		0x144, INREG32(module_base + 0x144),
		0x148, INREG32(module_base + 0x148),
		0x14C, INREG32(module_base + 0x14C));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x150, INREG32(module_base + 0x150),
		0x160, INREG32(module_base + 0x160),
		0x164, INREG32(module_base + 0x164),
		0x168, INREG32(module_base + 0x168));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x16C, INREG32(module_base + 0x16C),
		0x170, INREG32(module_base + 0x170),
		0x180, INREG32(module_base + 0x180),
		0x184, INREG32(module_base + 0x184));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x188, INREG32(module_base + 0x188),
		0x18C, INREG32(module_base + 0x18C),
		0x190, INREG32(module_base + 0x190),
		0x300, INREG32(module_base + 0x300));
	DDPDUMP("MUTEX: 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x304, INREG32(module_base + 0x304),
		0x30C, INREG32(module_base + 0x30C));
	DDPDUMP("-- END: DISP MUTEX registers --\n");

	return;
}



static void mutex_dump_analysis(void)
{
	int i = 0;
	int j = 0;
	char mutex_module[512] = { '\0' };
	char *p = NULL;
	int len = 0;
	unsigned int val;

	DDPDUMP("== DISP Mutex Analysis ==\n");
	for (i = 0; i < 5; i++) {
		p = mutex_module;
		len = 0;
		if (DISP_REG_GET(DISP_REG_CONFIG_MUTEX_MOD0(i)) == 0)
			continue;

		val = DISP_REG_GET(DISP_REG_CONFIG_MUTEX_SOF(i));
		len = sprintf(p, "MUTEX%d :SOF=%s,EOF=%s,WAIT=%d,module=(",
				  i,
				  ddp_get_mutex_sof_name(REG_FLD_VAL_GET(SOF_FLD_MUTEX0_SOF, val)),
				  ddp_get_mutex_sof_name(REG_FLD_VAL_GET(SOF_FLD_MUTEX0_EOF, val)),
				REG_FLD_VAL_GET(SOF_FLD_MUTEX0_SOF_WAIT, val));

		p += len;
		for (j = 0; j < 32; j++) {
			unsigned int regval = DISP_REG_GET(DISP_REG_CONFIG_MUTEX_MOD0(i));

			if ((regval & (1 << j))) {
				len = sprintf(p, "%s,", ddp_get_mutex_module0_name(j));
				p += len;
			}

			regval = DISP_REG_GET(DISP_REG_CONFIG_MUTEX_MOD1(i));

			if ((regval & (1 << j))) {
				len = sprintf(p, "%s,", ddp_get_mutex_module1_name(j));
				p += len;
			}
		}
		DDPDUMP("%s)\n", mutex_module);
	}
}


static void mmsys_config_dump_reg(void)
{
	unsigned long module_base = DISPSYS_CONFIG_BASE;

	DDPDUMP("== START: DISP MMSYS_CONFIG registers ==\n");
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x000, INREG32(module_base + 0x000),
		0x004, INREG32(module_base + 0x004),
		0x00C, INREG32(module_base + 0x00C),
		0x010, INREG32(module_base + 0x010));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x014, INREG32(module_base + 0x014),
		0x018, INREG32(module_base + 0x018),
		0x020, INREG32(module_base + 0x020),
		0x024, INREG32(module_base + 0x024));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x028, INREG32(module_base + 0x028),
		0x02C, INREG32(module_base + 0x02C),
		0x030, INREG32(module_base + 0x030),
		0x034, INREG32(module_base + 0x034));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x038, INREG32(module_base + 0x038),
		0x048, INREG32(module_base + 0x048),
		0x0F0, INREG32(module_base + 0x0F0),
		0x0F4, INREG32(module_base + 0x0F4));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0F8, INREG32(module_base + 0x0F8),
		0x100, INREG32(module_base + 0x100),
		0x104, INREG32(module_base + 0x104),
		0x108, INREG32(module_base + 0x108));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x110, INREG32(module_base + 0x110),
		0x114, INREG32(module_base + 0x114),
		0x118, INREG32(module_base + 0x118),
		0x120, INREG32(module_base + 0x120));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x124, INREG32(module_base + 0x124),
		0x128, INREG32(module_base + 0x128),
		0x130, INREG32(module_base + 0x130),
		0x134, INREG32(module_base + 0x134));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x138, INREG32(module_base + 0x138),
		0x140, INREG32(module_base + 0x140),
		0x144, INREG32(module_base + 0x144),
		0x150, INREG32(module_base + 0x150));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x180, INREG32(module_base + 0x180),
		0x184, INREG32(module_base + 0x184),
		0x190, INREG32(module_base + 0x190),
		0x200, INREG32(module_base + 0x200));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x204, INREG32(module_base + 0x204),
		0x208, INREG32(module_base + 0x208),
		0x20C, INREG32(module_base + 0x20C),
		0x210, INREG32(module_base + 0x210));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x214, INREG32(module_base + 0x214),
		0x218, INREG32(module_base + 0x218),
		0x220, INREG32(module_base + 0x220),
		0x224, INREG32(module_base + 0x224));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x228, INREG32(module_base + 0x228),
		0x22C, INREG32(module_base + 0x22C),
		0x230, INREG32(module_base + 0x230),
		0x234, INREG32(module_base + 0x234));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x238, INREG32(module_base + 0x238),
		0x800, INREG32(module_base + 0x800),
		0x804, INREG32(module_base + 0x804),
		0x808, INREG32(module_base + 0x808));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x80C, INREG32(module_base + 0x80C),
		0x810, INREG32(module_base + 0x810),
		0x814, INREG32(module_base + 0x814),
		0x818, INREG32(module_base + 0x818));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x81C, INREG32(module_base + 0x81C),
		0x820, INREG32(module_base + 0x820),
		0x824, INREG32(module_base + 0x824),
		0x828, INREG32(module_base + 0x828));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x82C, INREG32(module_base + 0x82C),
		0x830, INREG32(module_base + 0x830),
		0x834, INREG32(module_base + 0x834),
		0x838, INREG32(module_base + 0x838));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x83C, INREG32(module_base + 0x83C),
		0x840, INREG32(module_base + 0x840),
		0x844, INREG32(module_base + 0x844),
		0x848, INREG32(module_base + 0x848));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x84C, INREG32(module_base + 0x84C),
		0x854, INREG32(module_base + 0x854),
		0x858, INREG32(module_base + 0x858),
		0x85C, INREG32(module_base + 0x85C));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x860, INREG32(module_base + 0x860),
		0x864, INREG32(module_base + 0x864),
		0x868, INREG32(module_base + 0x868),
		0x870, INREG32(module_base + 0x870));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x874, INREG32(module_base + 0x874),
		0x878, INREG32(module_base + 0x878),
		0x88C, INREG32(module_base + 0x88C),
		0x890, INREG32(module_base + 0x890));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x894, INREG32(module_base + 0x894),
		0x898, INREG32(module_base + 0x898),
		0x89C, INREG32(module_base + 0x89C),
		0x8A0, INREG32(module_base + 0x8A0));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x8A4, INREG32(module_base + 0x8A4),
		0x8A8, INREG32(module_base + 0x8A8),
		0x8AC, INREG32(module_base + 0x8AC),
		0x8B0, INREG32(module_base + 0x8B0));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x8B4, INREG32(module_base + 0x8B4),
		0x8B8, INREG32(module_base + 0x8B8),
		0x8C0, INREG32(module_base + 0x8C0),
		0x8C4, INREG32(module_base + 0x8C4));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x8CC, INREG32(module_base + 0x8CC),
		0x8D0, INREG32(module_base + 0x8D0),
		0x8D4, INREG32(module_base + 0x8D4),
		0x8D8, INREG32(module_base + 0x8D8));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x8DC, INREG32(module_base + 0x8DC),
		0x8E0, INREG32(module_base + 0x8E0),
		0x8E4, INREG32(module_base + 0x8E4),
		0x8E8, INREG32(module_base + 0x8E8));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x8EC, INREG32(module_base + 0x8EC),
		0x8F0, INREG32(module_base + 0x8F0),
		0x908, INREG32(module_base + 0x908),
		0x90C, INREG32(module_base + 0x90C));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x910, INREG32(module_base + 0x910),
		0x914, INREG32(module_base + 0x914),
		0x918, INREG32(module_base + 0x918),
		0x91C, INREG32(module_base + 0x91C));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x920, INREG32(module_base + 0x920),
		0x924, INREG32(module_base + 0x924),
		0x928, INREG32(module_base + 0x928),
		0x934, INREG32(module_base + 0x934));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x938, INREG32(module_base + 0x938),
		0x93C, INREG32(module_base + 0x93C),
		0x940, INREG32(module_base + 0x940),
		0x944, INREG32(module_base + 0x944));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xF00, INREG32(module_base + 0xF00),
		0xF04, INREG32(module_base + 0xF04),
		0xF08, INREG32(module_base + 0xF08),
		0xF0C, INREG32(module_base + 0xF0C));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xF10, INREG32(module_base + 0xF10),
		0xF20, INREG32(module_base + 0xF20),
		0xF24, INREG32(module_base + 0xF24),
		0xF28, INREG32(module_base + 0xF28));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xF2C, INREG32(module_base + 0xF2C),
		0xF30, INREG32(module_base + 0xF30),
		0xF34, INREG32(module_base + 0xF34),
		0xF38, INREG32(module_base + 0xF38));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xF3C, INREG32(module_base + 0xF3C),
		0xF40, INREG32(module_base + 0xF40),
		0xF44, INREG32(module_base + 0xF44),
		0xF48, INREG32(module_base + 0xF48));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xF50, INREG32(module_base + 0xF50),
		0xF54, INREG32(module_base + 0xF54),
		0xF58, INREG32(module_base + 0xF58),
		0xF5C, INREG32(module_base + 0xF5C));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xF80, INREG32(module_base + 0xF80),
		0xF84, INREG32(module_base + 0xF84),
		0xF88, INREG32(module_base + 0xF88),
		0xF8C, INREG32(module_base + 0xF8C));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xF90, INREG32(module_base + 0xF90),
		0xF94, INREG32(module_base + 0xF94),
		0xF98, INREG32(module_base + 0xF98),
		0xFA0, INREG32(module_base + 0xFA0));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xFA4, INREG32(module_base + 0xFA4),
		0xFA8, INREG32(module_base + 0xFA8),
		0xFAC, INREG32(module_base + 0xFAC),
		0xFB0, INREG32(module_base + 0xFB0));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xFC0, INREG32(module_base + 0xFC0),
		0XFC4, INREG32(module_base + 0XFC4),
		0xFC8, INREG32(module_base + 0xFC8),
		0xFCC, INREG32(module_base + 0xFCC));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xFD0, INREG32(module_base + 0xFD0),
		0xFD4, INREG32(module_base + 0xFD4),
		0xFD8, INREG32(module_base + 0xFD8),
		0xFDC, INREG32(module_base + 0xFDC));
	DDPDUMP("MMSYS_CONFIG: 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0xFE0, INREG32(module_base + 0xFE0),
		0xFE4, INREG32(module_base + 0xFE4));
	DDPDUMP("-- END: DISP MMSYS_CONFIG registers --\n");

	return;
}


/* ------ clock:
Before power on mmsys:
CLK_CFG_0_CLR (address is 0x10000048) = 0x80000000 (bit 31).
Before using DISP_PWM0 or DISP_PWM1:
CLK_CFG_1_CLR(address is 0x10000058)=0x80 (bit 7).
Before using DPI pixel clock:
CLK_CFG_6_CLR(address is 0x100000A8)=0x80 (bit 7).

Only need to enable the corresponding bits of MMSYS_CG_CON0 and MMSYS_CG_CON1 for the modules:
smi_common, larb0, mdp_crop, fake_eng, mutex_32k, pwm0, pwm1, dsi0, dsi1, dpi.
Other bits could keep 1. Suggest to keep smi_common and larb0 always clock on.

--------valid & ready
example:
ovl0 -> ovl0_mout_ready=1 means engines after ovl_mout are ready for receiving data
	ovl0_mout_ready=0 means ovl0_mout can not receive data, maybe ovl0_mout or after engines config error
ovl0 -> ovl0_mout_valid=1 means engines before ovl0_mout is OK,
	ovl0_mout_valid=0 means ovl can not transfer data to ovl0_mout, means ovl0 or before engines are not ready.
*/

static void mmsys_config_dump_analysis(void)
{

	unsigned int i = 0, j;
	unsigned int reg = 0;
	char clock_on[512] = { '\0' };
	char *pos = NULL;
	const char *name;
	/* int len = 0; */
	unsigned int valid[6], ready[6];
	unsigned int greq;

	valid[0] = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DL_VALID0);
	valid[1] = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DL_VALID1);
	valid[2] = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DL_VALID2);
	valid[3] = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DL_VALID3);
	valid[4] = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DL_VALID4);
	valid[5] = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DL_VALID5);
	ready[0] = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DL_READY0);
	ready[1] = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DL_READY1);
	ready[2] = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DL_READY2);
	ready[3] = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DL_READY3);
	ready[4] = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DL_READY4);
	ready[5] = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_DL_READY5);
	greq = DISP_REG_GET(DISP_REG_CONFIG_SMI_LARB0_GREQ);

	DDPDUMP("== DISP MMSYS_CONFIG ANALYSIS ==\n");
#if 0 /* TODO: mmsys clk?? */
	DDPDUMP("mmsys clock=0x%x, CG_CON0=0x%x, CG_CON1=0x%x\n",
		DISP_REG_GET(DISP_REG_CLK_CFG_0_MM_CLK),
		DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON0),
		DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON1));
	if ((DISP_REG_GET(DISP_REG_CLK_CFG_0_MM_CLK) >> 31) & 0x1)
		DDPERR("mmsys clock abnormal!!\n");
#endif

	reg = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON0);
	for (i = 0; i < 32; i++) {
		if ((reg & (1 << i)) == 0) {
			name = ddp_clock_0(i);
			if (name)
				strncat(clock_on, name, sizeof(clock_on));
		}
	}

/* no need ddp_clock_1 */
/*
*	reg = DISP_REG_GET(DISP_REG_CONFIG_MMSYS_CG_CON1);
*	for (i = 0; i < 32; i++) {
*		if ((reg & (1 << i)) == 0) {
*			name = ddp_clock_1(i);
*			if (name)
*				strncat(clock_on, name,
*					(sizeof(clock_on) -
*					strlen(clock_on) - 1));
*		}
*	}
*/

	DDPDUMP("clock on modules:%s\n", clock_on);

	DDPDUMP("valid0=0x%x,valid1=0x%x,valid2=0x%x,ready0=0x%x,ready1=0x%x,ready2=0x%x,greq=0%x\n",
		valid[0], valid[1], valid[2], ready[0], ready[1], ready[2], greq);
	DDPDUMP("valid3=0x%x,valid4=0x%x,valid5=0x%x,ready3=0x%x,ready4=0x%x,ready5=0x%x\n",
		valid[3], valid[4], valid[5], ready[3], ready[4], ready[5]);

	for (j = 0; j < ARRAY_SIZE(valid); j++) {
		for (i = 0; i < 32; i++) {
			name = ddp_signal[j][i];
			if (!name)
				continue;

			pos = clock_on;

			if ((valid[j] & (1 << i)))
				pos += sprintf(pos, "%s,", "v");
			else
				pos += sprintf(pos, "%s,", "n");

			if ((ready[j] & (1 << i)))
				pos += sprintf(pos, "%s", "r");
			else
				pos += sprintf(pos, "%s", "n");

			pos += sprintf(pos, ": %s", name);

			DDPDUMP("%s\n", clock_on);
		}
	}

	/* greq: 1 means SMI dose not grant, maybe SMI hang */
	if (greq)
		DDPDUMP("smi greq not grant module: (greq: 1 means SMI dose not grant, maybe SMI hang)");

	clock_on[0] = '\0';
	for (i = 0; i < 32; i++) {
		if (greq & (1 << i)) {
			name = ddp_greq_name(i);
			if (!name)
				continue;
			strncat(clock_on, name, sizeof(clock_on));
		}
	}
	DDPDUMP("%s\n", clock_on);

}

static void gamma_dump_reg(void)
{
	unsigned long module_base = DISPSYS_GAMMA0_BASE;

	DDPDUMP("== START: DISP gamma0 registers ==\n");
	DDPDUMP("gamma0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0000, INREG32(module_base + 0x0000),
		0x0004, INREG32(module_base + 0x0004),
		0x0008, INREG32(module_base + 0x0008),
		0x000c, INREG32(module_base + 0x000c));
	DDPDUMP("gamma0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0010, INREG32(module_base + 0x0010),
		0x0020, INREG32(module_base + 0x0020),
		0x0024, INREG32(module_base + 0x0024),
		0x0028, INREG32(module_base + 0x0028));
	DDPDUMP("gamma0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x002c, INREG32(module_base + 0x002c),
		0x0030, INREG32(module_base + 0x0030),
		0x0034, INREG32(module_base + 0x0034),
		0x0700, INREG32(module_base + 0x0700));
	DDPDUMP("-- END: DISP gamma0 registers --\n");

}


static void gamma_dump_analysis(void)
{
	DDPDUMP("== DISP GAMMA ANALYSIS ==\n");
	DDPDUMP("gamma: en=%d, w=%d, h=%d, in_p_cnt=%d, in_l_cnt=%d, out_p_cnt=%d, out_l_cnt=%d\n",
		DISP_REG_GET(DISP_REG_GAMMA_EN),
		(DISP_REG_GET(DISP_REG_GAMMA_SIZE) >> 16) & 0x1fff,
		DISP_REG_GET(DISP_REG_GAMMA_SIZE) & 0x1fff,
		DISP_REG_GET(DISP_REG_GAMMA_INPUT_COUNT) & 0x1fff,
		(DISP_REG_GET(DISP_REG_GAMMA_INPUT_COUNT) >> 16) & 0x1fff,
		DISP_REG_GET(DISP_REG_GAMMA_OUTPUT_COUNT) & 0x1fff,
		(DISP_REG_GET(DISP_REG_GAMMA_OUTPUT_COUNT) >> 16) & 0x1fff);
}

static void color_dump_reg(DISP_MODULE_ENUM module)
{
	int idx = 0;
	unsigned long module_base = DISPSYS_COLOR0_BASE;

	DDPDUMP("== START: DISP COLOR%d registers ==\n", idx);
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000400, INREG32(module_base + 0x00000400),
		0x00000404, INREG32(module_base + 0x00000404),
		0x00000408, INREG32(module_base + 0x00000408),
		0x0000040C, INREG32(module_base + 0x0000040C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000410, INREG32(module_base + 0x00000410),
		0x00000418, INREG32(module_base + 0x00000418),
		0x0000041C, INREG32(module_base + 0x0000041C),
		0x00000420, INREG32(module_base + 0x00000420));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000428, INREG32(module_base + 0x00000428),
		0x0000042C, INREG32(module_base + 0x0000042C),
		0x00000430, INREG32(module_base + 0x00000430),
		0x00000434, INREG32(module_base + 0x00000434));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000438, INREG32(module_base + 0x00000438),
		0x00000484, INREG32(module_base + 0x00000484),
		0x00000488, INREG32(module_base + 0x00000488),
		0x0000048C, INREG32(module_base + 0x0000048C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000490, INREG32(module_base + 0x00000490),
		0x00000494, INREG32(module_base + 0x00000494),
		0x00000498, INREG32(module_base + 0x00000498),
		0x0000049C, INREG32(module_base + 0x0000049C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x000004A0, INREG32(module_base + 0x000004A0),
		0x000004A4, INREG32(module_base + 0x000004A4),
		0x000004A8, INREG32(module_base + 0x000004A8),
		0x000004AC, INREG32(module_base + 0x000004AC));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x000004B0, INREG32(module_base + 0x000004B0),
		0x000004B4, INREG32(module_base + 0x000004B4),
		0x000004B8, INREG32(module_base + 0x000004B8),
		0x000004BC, INREG32(module_base + 0x000004BC));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000620, INREG32(module_base + 0x00000620),
		0x00000624, INREG32(module_base + 0x00000624),
		0x00000628, INREG32(module_base + 0x00000628),
		0x0000062C, INREG32(module_base + 0x0000062C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000630, INREG32(module_base + 0x00000630),
		0x00000740, INREG32(module_base + 0x00000740),
		0x0000074C, INREG32(module_base + 0x0000074C),
		0x00000768, INREG32(module_base + 0x00000768));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x0000076C, INREG32(module_base + 0x0000076C),
		0x0000079C, INREG32(module_base + 0x0000079C),
		0x000007E0, INREG32(module_base + 0x000007E0),
		0x000007E4, INREG32(module_base + 0x000007E4));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x000007E8, INREG32(module_base + 0x000007E8),
		0x000007EC, INREG32(module_base + 0x000007EC),
		0x000007F0, INREG32(module_base + 0x000007F0),
		0x000007FC, INREG32(module_base + 0x000007FC));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000800, INREG32(module_base + 0x00000800),
		0x00000804, INREG32(module_base + 0x00000804),
		0x00000808, INREG32(module_base + 0x00000808),
		0x0000080C, INREG32(module_base + 0x0000080C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000810, INREG32(module_base + 0x00000810),
		0x00000814, INREG32(module_base + 0x00000814),
		0x00000818, INREG32(module_base + 0x00000818),
		0x0000081C, INREG32(module_base + 0x0000081C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000820, INREG32(module_base + 0x00000820),
		0x00000824, INREG32(module_base + 0x00000824),
		0x00000828, INREG32(module_base + 0x00000828),
		0x0000082C, INREG32(module_base + 0x0000082C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000830, INREG32(module_base + 0x00000830),
		0x00000834, INREG32(module_base + 0x00000834),
		0x00000838, INREG32(module_base + 0x00000838),
		0x0000083C, INREG32(module_base + 0x0000083C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000840, INREG32(module_base + 0x00000840),
		0x00000844, INREG32(module_base + 0x00000844),
		0x00000848, INREG32(module_base + 0x00000848),
		0x0000084C, INREG32(module_base + 0x0000084C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000850, INREG32(module_base + 0x00000850),
		0x00000854, INREG32(module_base + 0x00000854),
		0x00000858, INREG32(module_base + 0x00000858),
		0x0000085C, INREG32(module_base + 0x0000085C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000860, INREG32(module_base + 0x00000860),
		0x00000864, INREG32(module_base + 0x00000864),
		0x00000868, INREG32(module_base + 0x00000868),
		0x0000086C, INREG32(module_base + 0x0000086C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000870, INREG32(module_base + 0x00000870),
		0x00000874, INREG32(module_base + 0x00000874),
		0x00000878, INREG32(module_base + 0x00000878),
		0x0000087C, INREG32(module_base + 0x0000087C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000880, INREG32(module_base + 0x00000880),
		0x00000884, INREG32(module_base + 0x00000884),
		0x00000888, INREG32(module_base + 0x00000888),
		0x0000088C, INREG32(module_base + 0x0000088C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000890, INREG32(module_base + 0x00000890),
		0x00000894, INREG32(module_base + 0x00000894),
		0x00000898, INREG32(module_base + 0x00000898),
		0x0000089C, INREG32(module_base + 0x0000089C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x000008A0, INREG32(module_base + 0x000008A0),
		0x000008A4, INREG32(module_base + 0x000008A4),
		0x000008A8, INREG32(module_base + 0x000008A8),
		0x000008AC, INREG32(module_base + 0x000008AC));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x000008B0, INREG32(module_base + 0x000008B0),
		0x000008B4, INREG32(module_base + 0x000008B4),
		0x000008B8, INREG32(module_base + 0x000008B8),
		0x000008BC, INREG32(module_base + 0x000008BC));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x000008C0, INREG32(module_base + 0x000008C0),
		0x000008C4, INREG32(module_base + 0x000008C4),
		0x000008C8, INREG32(module_base + 0x000008C8),
		0x000008CC, INREG32(module_base + 0x000008CC));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x000008D0, INREG32(module_base + 0x000008D0),
		0x000008D4, INREG32(module_base + 0x000008D4),
		0x000008D8, INREG32(module_base + 0x000008D8),
		0x000008DC, INREG32(module_base + 0x000008DC));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x000008E0, INREG32(module_base + 0x000008E0),
		0x000008E4, INREG32(module_base + 0x000008E4),
		0x000008E8, INREG32(module_base + 0x000008E8),
		0x000008EC, INREG32(module_base + 0x000008EC));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x000008F0, INREG32(module_base + 0x000008F0),
		0x000008F4, INREG32(module_base + 0x000008F4),
		0x000008F8, INREG32(module_base + 0x000008F8),
		0x000008FC, INREG32(module_base + 0x000008FC));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000900, INREG32(module_base + 0x00000900),
		0x00000904, INREG32(module_base + 0x00000904),
		0x00000908, INREG32(module_base + 0x00000908),
		0x0000090C, INREG32(module_base + 0x0000090C));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000910, INREG32(module_base + 0x00000910),
		0x00000914, INREG32(module_base + 0x00000914),
		0x00000C00, INREG32(module_base + 0x00000C00),
		0x00000C04, INREG32(module_base + 0x00000C04));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000C08, INREG32(module_base + 0x00000C08),
		0x00000C0C, INREG32(module_base + 0x00000C0C),
		0x00000C10, INREG32(module_base + 0x00000C10),
		0x00000C14, INREG32(module_base + 0x00000C14));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000C18, INREG32(module_base + 0x00000C18),
		0x00000C28, INREG32(module_base + 0x00000C28),
		0x00000C50, INREG32(module_base + 0x00000C50),
		0x00000C54, INREG32(module_base + 0x00000C54));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000C60, INREG32(module_base + 0x00000C60),
		0x00000CA0, INREG32(module_base + 0x00000CA0),
		0x00000CB0, INREG32(module_base + 0x00000CB0),
		0x00000CF0, INREG32(module_base + 0x00000CF0));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000CF4, INREG32(module_base + 0x00000CF4),
		0x00000CF8, INREG32(module_base + 0x00000CF8),
		0x00000CFC, INREG32(module_base + 0x00000CFC),
		0x00000D00, INREG32(module_base + 0x00000D00));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000D04, INREG32(module_base + 0x00000D04),
		0x00000D08, INREG32(module_base + 0x00000D08),
		0x00000D0C, INREG32(module_base + 0x00000D0C),
		0x00000D10, INREG32(module_base + 0x00000D10));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000D14, INREG32(module_base + 0x00000D14),
		0x00000D18, INREG32(module_base + 0x00000D18),
		0x00000D1C, INREG32(module_base + 0x00000D1C),
		0x00000D20, INREG32(module_base + 0x00000D20));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000D24, INREG32(module_base + 0x00000D24),
		0x00000D28, INREG32(module_base + 0x00000D28),
		0x00000D2C, INREG32(module_base + 0x00000D2C),
		0x00000D30, INREG32(module_base + 0x00000D30));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000D34, INREG32(module_base + 0x00000D34),
		0x00000D38, INREG32(module_base + 0x00000D38),
		0x00000D3C, INREG32(module_base + 0x00000D3C),
		0x00000D40, INREG32(module_base + 0x00000D40));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x00000D44, INREG32(module_base + 0x00000D44),
		0x00000D48, INREG32(module_base + 0x00000D48),
		0x00000D4C, INREG32(module_base + 0x00000D4C),
		0x00000D50, INREG32(module_base + 0x00000D50));
	DDPDUMP("COLOR%d: 0x%04x=0x%08x, 0x%04x=0x%08x,  0x%04x=0x%08x\n",
		idx,
		0x00000D54, INREG32(module_base + 0x00000D54),
		0x00000D58, INREG32(module_base + 0x00000D58),
		0x00000D5C, INREG32(module_base + 0x00000D5C));
	DDPDUMP("-- END: DISP COLOR%d registers --\n", idx);

	return;
}


static void color_dump_analysis(DISP_MODULE_ENUM module)
{
	int index = 0;

	if (DISP_MODULE_COLOR0 == module) {
		index = 0;
	} else {
		DDPDUMP("error: DISP COLOR%d dose not exist!\n", index);
		return;
	}
	DDPDUMP("== DISP COLOR%d ANALYSIS ==\n", index);
	DDPDUMP("color%d: bypass=%d, w=%d, h=%d, pixel_cnt=%d, line_cnt=%d,\n",
		index,
		(DISP_REG_GET(DISP_COLOR_CFG_MAIN) >> 7) & 0x1,
		DISP_REG_GET(DISP_COLOR_INTERNAL_IP_WIDTH),
		DISP_REG_GET(DISP_COLOR_INTERNAL_IP_HEIGHT),
		DISP_REG_GET(DISP_COLOR_PXL_CNT_MAIN) & 0xffff,
		(DISP_REG_GET(DISP_COLOR_LINE_CNT_MAIN) >> 16) & 0x1fff);

	return;
}

static void aal_dump_reg(void)
{
	int i = 0;
	unsigned long module_base = DISPSYS_AAL0_BASE;

	DDPDUMP("== START: DISP AAL%d registers ==\n", i);
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000000, INREG32(module_base + 0x00000000),
		0x00000004, INREG32(module_base + 0x00000004),
		0x00000008, INREG32(module_base + 0x00000008),
		0x0000000C, INREG32(module_base + 0x0000000C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000010, INREG32(module_base + 0x00000010),
		0x00000020, INREG32(module_base + 0x00000020),
		0x00000024, INREG32(module_base + 0x00000024),
		0x00000028, INREG32(module_base + 0x00000028));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0000002C, INREG32(module_base + 0x0000002C),
		0x00000030, INREG32(module_base + 0x00000030),
		0x00000034, INREG32(module_base + 0x000004d8));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x000000B0, INREG32(module_base + 0x000000B0),
		0x000000C0, INREG32(module_base + 0x000000C0),
		0x000000FC, INREG32(module_base + 0x000000FC));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000204, INREG32(module_base + 0x00000204),
		0x0000020C, INREG32(module_base + 0x0000020C),
		0x00000214, INREG32(module_base + 0x00000214));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0000021C, INREG32(module_base + 0x0000021C),
		0x00000224, INREG32(module_base + 0x00000224),
		0x00000228, INREG32(module_base + 0x00000228),
		0x0000022C, INREG32(module_base + 0x0000022C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000230, INREG32(module_base + 0x00000230),
		0x00000234, INREG32(module_base + 0x00000234),
		0x00000238, INREG32(module_base + 0x00000238),
		0x0000023C, INREG32(module_base + 0x0000023C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000240, INREG32(module_base + 0x00000240),
		0x00000244, INREG32(module_base + 0x00000244),
		0x00000248, INREG32(module_base + 0x00000248),
		0x0000024C, INREG32(module_base + 0x0000024C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000250, INREG32(module_base + 0x00000250),
		0x00000254, INREG32(module_base + 0x00000254),
		0x00000258, INREG32(module_base + 0x00000258),
		0x0000025C, INREG32(module_base + 0x0000025C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000260, INREG32(module_base + 0x00000260),
		0x00000264, INREG32(module_base + 0x00000264),
		0x00000268, INREG32(module_base + 0x00000268),
		0x0000026C, INREG32(module_base + 0x0000026C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000270, INREG32(module_base + 0x00000270),
		0x00000274, INREG32(module_base + 0x00000274),
		0x00000278, INREG32(module_base + 0x00000278),
		0x0000027C, INREG32(module_base + 0x0000027C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000280, INREG32(module_base + 0x00000280),
		0x00000284, INREG32(module_base + 0x00000284),
		0x00000288, INREG32(module_base + 0x00000288),
		0x0000028C, INREG32(module_base + 0x0000028C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000290, INREG32(module_base + 0x00000290),
		0x00000294, INREG32(module_base + 0x00000294),
		0x00000298, INREG32(module_base + 0x00000298),
		0x0000029C, INREG32(module_base + 0x0000029C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x000002A0, INREG32(module_base + 0x000002A0),
		0x000002A4, INREG32(module_base + 0x000002A4),
		0x00000358, INREG32(module_base + 0x00000358),
		0x0000035C, INREG32(module_base + 0x0000035C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000360, INREG32(module_base + 0x00000360),
		0x00000364, INREG32(module_base + 0x00000364),
		0x00000368, INREG32(module_base + 0x00000368),
		0x0000036C, INREG32(module_base + 0x0000036C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000370, INREG32(module_base + 0x00000370),
		0x00000374, INREG32(module_base + 0x00000374),
		0x00000378, INREG32(module_base + 0x00000378),
		0x0000037C, INREG32(module_base + 0x0000037C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000380, INREG32(module_base + 0x00000380),
		0x000003B0, INREG32(module_base + 0x000003B0),
		0x0000040C, INREG32(module_base + 0x0000040C),
		0x00000410, INREG32(module_base + 0x00000410));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000414, INREG32(module_base + 0x00000414),
		0x00000418, INREG32(module_base + 0x00000418),
		0x0000041C, INREG32(module_base + 0x0000041C),
		0x00000420, INREG32(module_base + 0x00000420));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000424, INREG32(module_base + 0x00000424),
		0x00000428, INREG32(module_base + 0x00000428),
		0x0000042C, INREG32(module_base + 0x0000042C),
		0x00000430, INREG32(module_base + 0x00000430));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000434, INREG32(module_base + 0x00000434),
		0x00000440, INREG32(module_base + 0x00000440),
		0x00000444, INREG32(module_base + 0x00000444),
		0x00000448, INREG32(module_base + 0x00000448));
	DDPDUMP("-- END: DISP AAL%d registers --\n", i);

	return;
}

static void mdp_aal_dump_reg(DISP_MODULE_ENUM module)
{
	int i;
	unsigned long module_base = DISPSYS_MDP_AAL4_BASE;

	if (module == DISP_MODULE_MDP_AAL4)
		i = 0;
	else
		i = 1;

	DDPDUMP("== START: DISP MDP AAL%d registers ==\n", i);
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000000, INREG32(module_base + 0x00000000),
		0x00000004, INREG32(module_base + 0x00000004),
		0x00000008, INREG32(module_base + 0x00000008),
		0x0000000C, INREG32(module_base + 0x0000000C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000010, INREG32(module_base + 0x00000010),
		0x00000020, INREG32(module_base + 0x00000020),
		0x00000024, INREG32(module_base + 0x00000024),
		0x00000028, INREG32(module_base + 0x00000028));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0000002C, INREG32(module_base + 0x0000002C),
		0x00000030, INREG32(module_base + 0x00000030),
		0x00000034, INREG32(module_base + 0x00000034));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x000000B0, INREG32(module_base + 0x000000B0),
		0x000000C0, INREG32(module_base + 0x000000C0),
		0x000000FC, INREG32(module_base + 0x000000FC));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000204, INREG32(module_base + 0x00000204),
		0x0000020C, INREG32(module_base + 0x0000020C),
		0x00000214, INREG32(module_base + 0x00000214));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0000021C, INREG32(module_base + 0x0000021C),
		0x00000224, INREG32(module_base + 0x00000224),
		0x00000228, INREG32(module_base + 0x00000228),
		0x0000022C, INREG32(module_base + 0x0000022C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000230, INREG32(module_base + 0x00000230),
		0x00000234, INREG32(module_base + 0x00000234),
		0x00000238, INREG32(module_base + 0x00000238),
		0x0000023C, INREG32(module_base + 0x0000023C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000240, INREG32(module_base + 0x00000240),
		0x00000244, INREG32(module_base + 0x00000244),
		0x00000248, INREG32(module_base + 0x00000248),
		0x0000024C, INREG32(module_base + 0x0000024C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000250, INREG32(module_base + 0x00000250),
		0x00000254, INREG32(module_base + 0x00000254),
		0x00000258, INREG32(module_base + 0x00000258),
		0x0000025C, INREG32(module_base + 0x0000025C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000260, INREG32(module_base + 0x00000260),
		0x00000264, INREG32(module_base + 0x00000264),
		0x00000268, INREG32(module_base + 0x00000268),
		0x0000026C, INREG32(module_base + 0x0000026C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000270, INREG32(module_base + 0x00000270),
		0x00000274, INREG32(module_base + 0x00000274),
		0x00000278, INREG32(module_base + 0x00000278),
		0x0000027C, INREG32(module_base + 0x0000027C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000280, INREG32(module_base + 0x00000280),
		0x00000284, INREG32(module_base + 0x00000284),
		0x00000288, INREG32(module_base + 0x00000288),
		0x0000028C, INREG32(module_base + 0x0000028C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000290, INREG32(module_base + 0x00000290),
		0x00000294, INREG32(module_base + 0x00000294),
		0x00000298, INREG32(module_base + 0x00000298),
		0x0000029C, INREG32(module_base + 0x0000029C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x000002A0, INREG32(module_base + 0x000002A0),
		0x000002A4, INREG32(module_base + 0x000002A4),
		0x00000358, INREG32(module_base + 0x00000358),
		0x0000035C, INREG32(module_base + 0x0000035C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000360, INREG32(module_base + 0x00000360),
		0x00000364, INREG32(module_base + 0x00000364),
		0x00000368, INREG32(module_base + 0x00000368),
		0x0000036C, INREG32(module_base + 0x0000036C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000370, INREG32(module_base + 0x00000370),
		0x00000374, INREG32(module_base + 0x00000374),
		0x00000378, INREG32(module_base + 0x00000378),
		0x0000037C, INREG32(module_base + 0x0000037C));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000380, INREG32(module_base + 0x00000380),
		0x000003B0, INREG32(module_base + 0x000003B0),
		0x0000040C, INREG32(module_base + 0x0000040C),
		0x00000410, INREG32(module_base + 0x00000410));
	DDPDUMP("AAL:0x%04x= 0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000414, INREG32(module_base + 0x00000414),
		0x00000418, INREG32(module_base + 0x00000418),
		0x0000041C, INREG32(module_base + 0x0000041C),
		0x00000420, INREG32(module_base + 0x00000420));
	DDPDUMP("AAL:0x%04x= 0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000424, INREG32(module_base + 0x00000424),
		0x00000428, INREG32(module_base + 0x00000428),
		0x0000042C, INREG32(module_base + 0x0000042C),
		0x00000430, INREG32(module_base + 0x00000430));
	DDPDUMP("AAL: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000434, INREG32(module_base + 0x00000434),
		0x00000440, INREG32(module_base + 0x00000440),
		0x00000444, INREG32(module_base + 0x00000444),
		0x00000448, INREG32(module_base + 0x00000448));
	DDPDUMP("-- END: DISP AAL%d registers --\n", i);
}

static void aal_dump_analysis(void)
{
	DDPDUMP("== DISP AAL ANALYSIS ==\n");
	DDPDUMP("aal: bypass=%d, relay=%d, en=%d, w=%d, h=%d, in(%d,%d),out(%d,%d)\n",
		DISP_REG_GET(DISP_AAL_EN) == 0x0,
		DISP_REG_GET(DISP_AAL_CFG) & 0x01,
		DISP_REG_GET(DISP_AAL_EN),
		(DISP_REG_GET(DISP_AAL_SIZE) >> 16) & 0x1fff,
		DISP_REG_GET(DISP_AAL_SIZE) & 0x1fff,
		DISP_REG_GET(DISP_AAL_IN_CNT) & 0x1fff,
		(DISP_REG_GET(DISP_AAL_IN_CNT) >> 16) & 0x1fff,
		DISP_REG_GET(DISP_AAL_OUT_CNT) & 0x1fff,
		(DISP_REG_GET(DISP_AAL_OUT_CNT) >> 16) & 0x1fff);
}

static void pwm_dump_reg(DISP_MODULE_ENUM module)
{
	unsigned long module_base = DISPSYS_PWM0_BASE;

	DDPDUMP("== START: DISP PWM0 registers ==\n");
	DDPDUMP("PWM0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0, INREG32(module_base + 0x0),
		0x4, INREG32(module_base + 0x4),
		0x8, INREG32(module_base + 0x8),
		0xC, INREG32(module_base + 0xC));
	DDPDUMP("PWM0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x10, INREG32(module_base + 0x10),
		0x14, INREG32(module_base + 0x14),
		0x18, INREG32(module_base + 0x18),
		0x1C, INREG32(module_base + 0x1C));
	DDPDUMP("PWM0: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x80, INREG32(module_base + 0x80),
		0x28, INREG32(module_base + 0x28),
		0x2C, INREG32(module_base + 0x2C),
		0x30, INREG32(module_base + 0x30));
	DDPDUMP("PWM0: 0x%04x=0x%08x\n",
		0xC0, INREG32(module_base + 0xC0));
	DDPDUMP("-- END: DISP PWM0 registers --\n");

}


static void pwm_dump_analysis(DISP_MODULE_ENUM module)
{
	int index = 0;
	unsigned int reg_base = 0;

	if (module == DISP_MODULE_PWM0) {
		index = 0;
		reg_base = DISPSYS_PWM0_BASE;
	} else {
		index = 1;
		reg_base = DISPSYS_PWM0_BASE;
	}
	DDPDUMP("== DISP PWM%d REG_BASE:0x%08x ANALYSIS ==\n", index, reg_base);
#if 0 /* TODO: clk reg?? */
	DDPDUMP("pwm clock=%d\n", (DISP_REG_GET(DISP_REG_CLK_CFG_1_CLR) >> 7) & 0x1);
#endif

	return;
}



static void ccorr_dump_reg(void)
{
	int i = 0;
	unsigned long module_base = DISPSYS_CCORR0_BASE;

	DDPDUMP("== START: DISP CCORR%i registers ==\n", i);
	DDPDUMP("CCORR: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x000, INREG32(module_base + 0x000),
		0x004, INREG32(module_base + 0x004),
		0x008, INREG32(module_base + 0x008),
		0x00C, INREG32(module_base + 0x00C));
	DDPDUMP("CCORR: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x010, INREG32(module_base + 0x010),
		0x020, INREG32(module_base + 0x020),
		0x024, INREG32(module_base + 0x024),
		0x028, INREG32(module_base + 0x028));
	DDPDUMP("CCORR: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x02C, INREG32(module_base + 0x02C),
		0x030, INREG32(module_base + 0x030),
		0x080, INREG32(module_base + 0x080),
		0x084, INREG32(module_base + 0x084));
	DDPDUMP("CCORR: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x088, INREG32(module_base + 0x088),
		0x08C, INREG32(module_base + 0x08C),
		0x090, INREG32(module_base + 0x090),
		0x0A0, INREG32(module_base + 0x0A0));
	DDPDUMP("CCORR: 0x%04x=0x%08x\n",
		0x0C0, INREG32(module_base + 0x0C0));
	DDPDUMP("-- END: DISP CCORR%d registers --\n", i);


}


static void ccorr_dump_analyze(void)
{
	DDPDUMP("ccorr: en=%d, config=%d, w=%d, h=%d, in_p_cnt=%d, in_l_cnt=%d, out_p_cnt=%d, out_l_cnt=%d\n",
	     DISP_REG_GET(DISP_REG_CCORR_EN), DISP_REG_GET(DISP_REG_CCORR_CFG),
	     (DISP_REG_GET(DISP_REG_CCORR_SIZE) >> 16) & 0x1fff,
	     DISP_REG_GET(DISP_REG_CCORR_SIZE) & 0x1fff,
	     DISP_REG_GET(DISP_REG_CCORR_IN_CNT) & 0x1fff,
	     (DISP_REG_GET(DISP_REG_CCORR_IN_CNT) >> 16) & 0x1fff,
	     DISP_REG_GET(DISP_REG_CCORR_IN_CNT) & 0x1fff,
	     (DISP_REG_GET(DISP_REG_CCORR_IN_CNT) >> 16) & 0x1fff);
}

static void dither_dump_reg(void)
{
	int i = 0;
	unsigned long module_base = DISPSYS_DITHER0_BASE;

	DDPDUMP("== START: DISP DITHER%d registers ==\n", i);
	DDPDUMP("DITHER: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000000, INREG32(module_base + 0x00000000),
		0x00000004, INREG32(module_base + 0x00000004),
		0x00000008, INREG32(module_base + 0x00000008),
		0x0000000C, INREG32(module_base + 0x0000000C));
	DDPDUMP("DITHER: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000010, INREG32(module_base + 0x00000010),
		0x00000020, INREG32(module_base + 0x00000020),
		0x00000024, INREG32(module_base + 0x00000024),
		0x00000028, INREG32(module_base + 0x00000028));
	DDPDUMP("DITHER: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x0000002C, INREG32(module_base + 0x0000002C),
		0x00000030, INREG32(module_base + 0x00000030),
		0x000000C0, INREG32(module_base + 0x000000C0),
		0x00000100, INREG32(module_base + 0x00000100));
	DDPDUMP("DITHER: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000114, INREG32(module_base + 0x00000114),
		0x00000118, INREG32(module_base + 0x00000118),
		0x0000011C, INREG32(module_base + 0x0000011C),
		0x00000120, INREG32(module_base + 0x00000120));
	DDPDUMP("DITHER: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000124, INREG32(module_base + 0x00000124),
		0x00000128, INREG32(module_base + 0x00000128),
		0x0000012C, INREG32(module_base + 0x0000012C),
		0x00000130, INREG32(module_base + 0x00000130));
	DDPDUMP("DITHER: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x\n",
		0x00000134, INREG32(module_base + 0x00000134),
		0x00000138, INREG32(module_base + 0x00000138),
		0x0000013C, INREG32(module_base + 0x0000013C),
		0x00000140, INREG32(module_base + 0x00000140));
	DDPDUMP("DITHER: 0x%04x=0x%08x\n",
		0x00000144, INREG32(module_base + 0x00000144));
	DDPDUMP("-- END: DISP DITHER%d registers --\n", i);

}


static void dither_dump_analyze(void)
{
	DDPDUMP("dither: en=%d, config=%d, w=%d, h=%d, in_p_cnt=%d, in_l_cnt=%d, out_p_cnt=%d, out_l_cnt=%d\n",
		 DISP_REG_GET(DISPSYS_DITHER0_BASE + 0x000), DISP_REG_GET(DISPSYS_DITHER0_BASE + 0x020),
		 (DISP_REG_GET(DISP_REG_DITHER_SIZE) >> 16) & 0x1fff,
		 DISP_REG_GET(DISP_REG_DITHER_SIZE) & 0x1fff,
		 DISP_REG_GET(DISP_REG_DITHER_IN_CNT) & 0x1fff,
		 (DISP_REG_GET(DISP_REG_DITHER_IN_CNT) >> 16) & 0x1fff,
		 DISP_REG_GET(DISP_REG_DITHER_OUT_CNT) & 0x1fff,
		 (DISP_REG_GET(DISP_REG_DITHER_OUT_CNT) >> 16) & 0x1fff);

}


static void dsi_dump_reg(DISP_MODULE_ENUM module)
{
	DSI_DumpRegisters(module, 1);
#if 0
	if (DISP_MODULE_DSI0) {
		int i = 0;

		DDPDUMP("== DISP DSI0 REGS ==\n");
		for (i = 0; i < 25 * 16; i += 16) {
			DDPDUMP("DSI0+%04x: 0x%08x 0x%08x 0x%08x 0x%08x\n", i,
			       INREG32(DISPSYS_DSI0_BASE + i), INREG32(DISPSYS_DSI0_BASE + i + 0x4),
			       INREG32(DISPSYS_DSI0_BASE + i + 0x8),
			       INREG32(DISPSYS_DSI0_BASE + i + 0xc));
		}
		DDPDUMP("DSI0 CMDQ+0x200: 0x%08x 0x%08x 0x%08x 0x%08x\n",
		       INREG32(DISPSYS_DSI0_BASE + 0x200), INREG32(DISPSYS_DSI0_BASE + 0x200 + 0x4),
		       INREG32(DISPSYS_DSI0_BASE + 0x200 + 0x8),
		       INREG32(DISPSYS_DSI0_BASE + 0x200 + 0xc));
	}
#endif
}

static void dpi_dump_reg(void)
{
}

static void dpi_dump_analysis(void)
{
#if 0
	DDPDUMP("== DISP DPI ANALYSIS ==\n");
	/* TODO: mmsys clk?? */
	DDPDUMP("DPI clock=0x%x\n", DISP_REG_GET(DISP_REG_CLK_CFG_6_DPI));
	DDPDUMP("DPI  clock_clear=%d\n", (DISP_REG_GET(DISP_REG_CLK_CFG_6_CLR) >> 7) & 0x1);
	DDPDUMP("(0x000)S_ENABLE=0x%x\n", DISP_REG_GET(DISP_REG_SPLIT_ENABLE));
	DDPDUMP("(0x004)S_SW_RST=0x%x\n", DISP_REG_GET(DISP_REG_SPLIT_SW_RESET));
#endif
}

static int split_dump_regs(void)
{
	unsigned long module_base = DISPSYS_SPLIT0_BASE;
	unsigned int idx = 0;

	DDPDUMP("== START: DISP SPLIT registers ==\n");
	DDPDUMP("SPLIT%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x000, INREG32(module_base + 0x000),
		0x004, INREG32(module_base + 0x004),
		0x008, INREG32(module_base + 0x008),
		0x00C, INREG32(module_base + 0x00C));
	DDPDUMP("SPLIT%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x010, INREG32(module_base + 0x010),
		0x020, INREG32(module_base + 0x020),
		0x024, INREG32(module_base + 0x024),
		0x028, INREG32(module_base + 0x028));
	DDPDUMP("SPLIT%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x02C, INREG32(module_base + 0x02C),
		0x030, INREG32(module_base + 0x030),
		0x034, INREG32(module_base + 0x034),
		0x038, INREG32(module_base + 0x038));
	DDPDUMP("SPLIT%d: 0x%04x=0x%08x, 0x%04x=0x%08x, 0x%04x=0x%08x,	0x%04x=0x%08x\n",
		idx,
		0x03C, INREG32(module_base + 0x03C),
		0x040, INREG32(module_base + 0x040),
		0x044, INREG32(module_base + 0x044),
		0x48, INREG32(module_base + 0x48));
	DDPDUMP("SPLIT%d:  0x%04x=0x%08x\n",
		idx,
		0x080, INREG32(module_base + 0x080));
	DDPDUMP("-- END: DISP SPLIT registers --\n");
	return 0;
}





static int split_dump_analysis(void)
{
#if 0
	unsigned int pixel = DISP_REG_GET_FIELD(DEBUG_FLD_IN_PIXEL_CNT, DISP_REG_SPLIT_DEBUG);
	unsigned int state = DISP_REG_GET_FIELD(DEBUG_FLD_SPLIT_FSM, DISP_REG_SPLIT_DEBUG);

	DDPDUMP("== DISP SPLIT0 ANALYSIS ==\n");
	DDPDUMP("cur_pixel %u, state %s\n", pixel, split_state(state));
	return 0;
#else
	return 0;
#endif
}

extern int dsc_dump(DISP_MODULE_ENUM module, int level);

int ddp_dump_reg(DISP_MODULE_ENUM module)
{
	switch (module) {
	case DISP_MODULE_WDMA0:
		//wdma_dump_reg(module);
		break;
	case DISP_MODULE_RDMA0:
		RDMADump(module);
		break;
	case DISP_MODULE_OVL0:
	case DISP_MODULE_OVL0_2L:
		OVLDump(module);
		break;
	case DISP_MODULE_GAMMA0:
		gamma_dump_reg();
		break;
	case DISP_MODULE_CONFIG:
		mmsys_config_dump_reg();
		break;
	case DISP_MODULE_MUTEX:
		mutex_dump_reg();
		break;
	case DISP_MODULE_COLOR0:
		color_dump_reg(module);
		break;
	case DISP_MODULE_AAL0:
		aal_dump_reg();
		break;
	case DISP_MODULE_MDP_AAL4:
		mdp_aal_dump_reg(module);
		break;
	case DISP_MODULE_PWM0:
		/* pwm_dump_reg(module); */
		break;
	case DISP_MODULE_DSI0:
	case DISP_MODULE_DSI1:
	case DISP_MODULE_DSIDUAL:
		dsi_dump_reg(module);
		break;
	case DISP_MODULE_CCORR0:
		ccorr_dump_reg();
		break;
	case DISP_MODULE_DITHER0:
		dither_dump_reg();
		break;
	case DISP_MODULE_POSTMASK0:
		postmask_dump_reg(module);
		break;
	case DISP_MODULE_DSC:
		dsc_dump(module, 0);
		break;
	default:
		DDPDUMP("no dump_reg for module %s(%d)\n", ddp_get_module_name(module), module);
	}
	return 0;
}

int ddp_dump_analysis(DISP_MODULE_ENUM module)
{
	switch (module) {
	case DISP_MODULE_WDMA0:
		//wdma_dump_analysis(module);
		break;
	case DISP_MODULE_RDMA0:
		rdma_dump_analysis(module);
		break;
	case DISP_MODULE_OVL0:
	case DISP_MODULE_OVL0_2L:
		ovl_dump_analysis(module);
		break;
	case DISP_MODULE_GAMMA0:
		gamma_dump_analysis();
		break;
	case DISP_MODULE_CONFIG:
		mmsys_config_dump_analysis();
		break;
	case DISP_MODULE_MUTEX:
		mutex_dump_analysis();
		break;
	case DISP_MODULE_COLOR0:
		color_dump_analysis(module);
		break;
	case DISP_MODULE_AAL0:
		aal_dump_analysis();
		break;
	case DISP_MODULE_PWM0:
		/* pwm_dump_analysis(module); */
		break;
	case DISP_MODULE_DSI0:
	case DISP_MODULE_DSI1:
	case DISP_MODULE_DSIDUAL:
		dsi_analysis(module);
		break;
	case DISP_MODULE_CCORR0:
		ccorr_dump_analyze();
		break;
	case DISP_MODULE_DITHER0:
		dither_dump_analyze();
		break;
	case DISP_MODULE_POSTMASK0:
		postmask_dump_analysis(module);
		break;
	default:
		DDPDUMP("no dump_analysis for module %s(%d)\n", ddp_get_module_name(module),
			module);
	}
	return 0;
}
