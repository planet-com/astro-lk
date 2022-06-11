/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2018. All rights reserved.
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

#ifndef _MT_ADSP_H_
#define _MT_ADSP_H_

#include <platform/mt_reg_base.h>

#include "memory_layout.h"

//#define FPGA_EARLY_DEVELOPMENT

struct image_node {
	char            *name;
	void            *base;
	uint32_t        size;
};

#define IMAGE_UNIT(iname, ibase, isize) {.name = iname, .base = (void *)ibase, .size = isize}

/* platform dependent address */
typedef enum {
	ADSP_A_IMAGE_ITCM = 0,
	ADSP_A_IMAGE_DTCM,
	ADSP_A_IMAGE_DRAM,
	ADSP_NUM_IMAGE,
} adsp_image_id;

#define ADSP_A_ITCM_NAME                "hifi3_a_iram"
#define ADSP_A_DTCM_NAME                "hifi3_a_dram"
#define ADSP_A_DRAM_NAME                "hifi3_a_sram"
#define ADSP_A_ITCM_BASE                0x10630000
#define ADSP_A_ITCM_SIZE                0x00009000
#define ADSP_A_DTCM_BASE                0x10610000
#define ADSP_A_DTCM_SIZE                0x00008000
#define ADSP_A_DRAM_BASE                0x56000000 //align adsp lsp: in adsp view

#ifdef FPGA_EARLY_DEVELOPMENT
#define ADSP_A_DRAM_SIZE                0x00282000
#else
#define ADSP_A_DRAM_SIZE                0x00700000
#endif

#define ADSP_TCM_TOTAL_SIZE        (ADSP_A_ITCM_SIZE + ADSP_A_DTCM_SIZE)
#define ADSP_DRAM_BASE             ADSP_A_DRAM_BASE
#define ADSP_DRAM_SIZE             (ADSP_A_DRAM_SIZE)        // mblock_reserve requires max 7MB + (32+36)KB
#define ADSP_DRAM_ADDR_MAX         (LK_ADSP_BASE + LK_ADSP_MAX_SIZE)
#define ADSP_DRAM_ADDR_ALIGN       0x10000

#define RESERVED_MEM_ALIGN         0x10000
#define MIN_SIZE_MEM_SEGMENT       0x400

#define MPUINFO_TOTAL_SIZE         (0x20)
#define MPUINFO_REGION_BASE        (ADSP_A_DTCM_BASE + ADSP_A_DTCM_SIZE \
							       - MPUINFO_TOTAL_SIZE)
#define MPUINFO_REGION_SIZE        (MPUINFO_REGION_BASE + 0x04)


/* emi setting */
#define MPU_REGION_ID_ADSP_RO_MEM       (28)
#define ENABLE_ADSP_EMI_PROTECTION      (1)

/************* macro for adsp clock config ******************************/
#define CLK_CFG_10                      (TOPCKGEN_BASE + 0x00E0)
#define CLK_CFG_10_SET                  (TOPCKGEN_BASE + 0x00E4)
#define CLK_CFG_10_CLR                  (TOPCKGEN_BASE + 0x00E8)
	#define ADSP_SEL_OFFSET             (6)
	#define CLK_26M_CK                  (0)
	#define ADSPPLL_CK                  (7)

/* control adsp clk cg */
#define MODULE_SW_CG_3_SET              (INFRACFG_AO_BASE + 0x0C0)
#define MODULE_SW_CG_3_CLR              (INFRACFG_AO_BASE + 0x0C4)
#define MODULE_SW_CG_3_STA              (INFRACFG_AO_BASE + 0x0C8)
	#define CG_OFFSET                   (27)
	#define CG_ENABLE                   (1)

#define ADSPPLL_CON0                    (APMIXED_BASE + 0x02B0)
#define ADSPPLL_CON1                    (APMIXED_BASE + 0x02B4)
#define ADSPPLL_PWR_CON0                (APMIXED_BASE + 0x02BC)

/* adsp CFGREG define */
#define ADSP_CFGREG_SW_RSTN             (ADSP_BASE + 0x0000)
	#define ADSP_SW_RSTN                (0x11)
#define ADSP_HIFI3_IO_CONFIG            (ADSP_BASE + 0x0008)
#define ADSP_DDREN_REQ                  (ADSP_BASE + 0x0044)
#define ADSP_SPM_REQ                    (ADSP_BASE + 0x0048)
#define ADSP_SPM_ACK                    (ADSP_BASE + 0x004C)

#define ADSP_COMMON_DTS_COMPATIBLE      "mediatek,adsp_common"
#define ADSP_CORE_DTS_COMPATIBLE        "mediatek,adsp_core"
#define ADSP_MEM_RESERVED_KEY           "mediatek,reserve-memory-adsp"
#define ADSP_SHARE_DTS_COMPATIBLE       "mediatek,reserve-memory-adsp_share"
#define SND_ADSP_DTS_COMPATIBLE         "mediatek,snd_audio_dsp"

#define BRINGUP_WR (1)

enum {
	AUDIO_MEM_VOIP_ID = 0,
	AUDIO_MEM_PRIMARY_ID,
	AUDIO_MEM_OFFLOAD_ID,
	AUDIO_MEM_DEEPBUFFER_ID,
	AUDIO_MEM_PLAYBACK_ID,
	AUDIO_MEM_MUSIC_ID,
	AUDIO_MEM_CAPTURE_UL1_ID,
	AUDIO_MEM_A2DP_ID,
	AUDIO_MEM_DATAPROVIDER_ID,
	AUDIO_MEM_CALL_FINAL_ID,
	AUDIO_MEM_FAST_ID,
	AUDIO_MEM_KTV_ID,
	AUDIO_MEM_AFE_ID,
	AUDIO_MEM_TOTAL_NUM,
	AUDIO_MEM_TASK_NUM = (AUDIO_MEM_KTV_ID - AUDIO_MEM_VOIP_ID + 1),
};

enum {
	ADSP_RSV_IPIDMA_A,
	ADSP_RSV_LOGGER_A,
	ADSP_RSV_DBG_DUMP_A,
	ADSP_RSV_CORE_DUMP_A,
	ADSP_RSV_AUDIO,
	ADSP_RSV_TOTAL_NUM,
};

struct adsp_region_info_t {
	uint32_t adsp_region_start;
	uint32_t adsp_region_size;
};

int load_adsp(void);
void disable_adsp_hw(void);
void switch_adsp_power(bool on, bool dormant);
void adsp_sw_reset(void);
int platform_fdt_adsp(void *fdt);

#endif /* _MT_ADSP_H_ */
