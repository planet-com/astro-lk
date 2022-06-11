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

#ifndef _MT_SCP_H_
#define _MT_SCP_H_

#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */

/*platform dependent address*/
#define SCP_EMI_REGION                   6
#define ENABLE_SCP_EMI_PROTECTION       (1)

#define SCP_SRAM_SIZE           0x00100000

#define SCP_LOADER_OFFSET       0x0
#define SCP_LOADER_SIZE         0x2000      // 8K
#define SCP_FW_OFFSET           0x2000
#define SCP_DRAM_IMG_OFFSET     0x200000    // fix @ 2M
#ifdef MTK_MINIMUM_SCP_DRAM_SIZE
#define SCP_DRAM_IMG_SIZE       0x080000    // 0.5MB dram image
#else
#define SCP_DRAM_IMG_SIZE       0x100000    // 1.0MB dram image
#endif

#define SCP_DRAM_ALIGN          0x00100000  // due to l1c align = 1MB
#define SCP_DRAM_OFFSET         0x00200000  // fix @ 2M
#define SCP_DRAM_SIZE           (SCP_DRAM_OFFSET + SCP_DRAM_IMG_SIZE * 2)

#define DRAM_ADDR_MAX           0xC0000000  // max address can SCP remap
#define DRAM_4GB_MAX            0xFFFFFFFF
#define DRAM_4GB_OFFSET         0x40000000

#define SCP_SRAM_BASE           0x10500000
#define SCP_CFG_BASE            0x10700000

/*core 0/1 */
#define R_CORE0_SW_RSTN_CLR		(SCP_CFG_BASE + 0x30000)
#define R_CORE0_SW_RSTN_SET		(SCP_CFG_BASE + 0x30004)

#define R_CORE1_SW_RSTN_CLR		(SCP_CFG_BASE + 0x40000)
#define R_CORE1_SW_RSTN_SET		(SCP_CFG_BASE + 0x40004)

#define R_CORE0_DBG_CTRL		(SCP_CFG_BASE + 0x30010)
#define R_CORE1_DBG_CTRL		(SCP_CFG_BASE + 0x40010)
	#define M_CORE_TBUF_DBG_SEL	(7 << 4)
	#define S_CORE_TBUF_DBG_SEL	(4)

#define R_CORE0_WDT_IRQ 		(SCP_CFG_BASE + 0x30030)
#define R_CORE1_WDT_IRQ 		(SCP_CFG_BASE + 0x40030)
	#define B_WDT_IRQ		(1 << 0)

#define R_CORE0_WDT_CFG 		(SCP_CFG_BASE + 0x30034)
#define R_CORE1_WDT_CFG 		(SCP_CFG_BASE + 0x40034)
	#define V_INSTANT_WDT		0x80000000

#define R_CORE0_STATUS			(SCP_CFG_BASE + 0x30070)
	#define B_CORE_GATED		(1 << 0)
	#define B_CORE_HALT		(1 << 1)
#define R_CORE0_MON_PC			(SCP_CFG_BASE + 0x30080)
#define R_CORE0_MON_LR			(SCP_CFG_BASE + 0x30084)
#define R_CORE0_MON_SP			(SCP_CFG_BASE + 0x30088)
#define R_CORE0_TBUF_WPTR		(SCP_CFG_BASE + 0x3008c)

#define R_CORE0_MON_PC_LATCH	(SCP_CFG_BASE + 0x300d0)
#define R_CORE0_MON_LR_LATCH	(SCP_CFG_BASE + 0x300d4)
#define R_CORE0_MON_SP_LATCH	(SCP_CFG_BASE + 0x300d8)

#define R_CORE1_STATUS			(SCP_CFG_BASE + 0x40070)
#define R_CORE1_MON_PC			(SCP_CFG_BASE + 0x40080)
#define R_CORE1_MON_LR			(SCP_CFG_BASE + 0x40084)
#define R_CORE1_MON_SP			(SCP_CFG_BASE + 0x40088)
#define R_CORE1_TBUF_WPTR		(SCP_CFG_BASE + 0x4008c)

#define R_CORE1_MON_PC_LATCH	(SCP_CFG_BASE + 0x400d0)
#define R_CORE1_MON_LR_LATCH	(SCP_CFG_BASE + 0x400d4)
#define R_CORE1_MON_SP_LATCH	(SCP_CFG_BASE + 0x400d8)

#define R_CORE0_TBUF_DATA31_0		(SCP_CFG_BASE + 0x300e0)
#define R_CORE0_TBUF_DATA63_32		(SCP_CFG_BASE + 0x300e4)
#define R_CORE0_TBUF_DATA95_64		(SCP_CFG_BASE + 0x300e8)
#define R_CORE0_TBUF_DATA127_96 	(SCP_CFG_BASE + 0x300ec)

#define R_CORE1_TBUF_DATA31_0		(SCP_CFG_BASE + 0x400e0)
#define R_CORE1_TBUF_DATA63_32		(SCP_CFG_BASE + 0x400e4)
#define R_CORE1_TBUF_DATA95_64		(SCP_CFG_BASE + 0x400e8)
#define R_CORE1_TBUF_DATA127_96 	(SCP_CFG_BASE + 0x400ec)

#define R_SCP_CLK_SEL			(SCP_CFG_BASE + 0x21000)
#define R_SCP_CLK_EN			(SCP_CFG_BASE + 0x21004)
#define R_L1TCM_SRAM_PDN		(SCP_CFG_BASE + 0x2102C)
#define R_CPU0_SRAM_PD			(SCP_CFG_BASE + 0x21080)
#define R_CPU1_SRAM_PD			(SCP_CFG_BASE + 0x21084)
#define R_TCM_TAIL_SRAM_PD		(SCP_CFG_BASE + 0x21094)
#define R_CLK_CTRL_GENERAL_CTRL	(SCP_CFG_BASE + 0x2109C)

#define R_L2TCM_SRAM_PD0		(SCP_CFG_BASE + 0x210C0)
#define R_L2TCM_SRAM_PD1		(SCP_CFG_BASE + 0x210C4)
#define R_L2TCM_SRAM_PD2		(SCP_CFG_BASE + 0x210C8)

#define R_CORE0_CACHE_RAM		(SCP_CFG_BASE + 0x60000)
#define R_CORE1_CACHE_RAM		(SCP_CFG_BASE + 0x80000)

#define R_SEC_CTRL			(SCP_CFG_BASE + 0xa5000)
	#define B_CORE0_CACHE_DBG_EN	(1 << 28)
	#define B_CORE1_CACHE_DBG_EN	(1 << 29)

#define R_SEC_DOMAIN			(SCP_CFG_BASE + 0xA5080)
	#define S_CORE0_DOMAIN		(0)
	#define S_CORE1_DOMAIN		(4)
	#define S_DMA0_DOMAIN		(12)
	#define S_DMA1_DOMAIN		(16)
	#define S_SPI0_DOMAIN		(20)
	#define S_SPI1_DOMAIN		(24)
	#define S_SPI2_DOMAIN		(27)
	#define DOMAIN_SCP		((1 << S_SPI2_DOMAIN) | \
				        (1 << S_SPI1_DOMAIN) | \
				        (1 << S_SPI0_DOMAIN) | \
				        (1 << S_SPI0_DOMAIN) | \
				        (1 << S_DMA1_DOMAIN) | \
				        (1 << S_DMA0_DOMAIN) | \
				        (1 << S_CORE1_DOMAIN) | \
				        (1 << S_CORE0_DOMAIN))

#define R_ADSP_DOMAIN			(SCP_CFG_BASE + 0xA5088)
	#define S_ADSP_DOMAIN		(0)
	#define DOMAIN_ADSP		(0 << S_ADSP_DOMAIN)

/*image name definition*/
#define IMG_NAME_SCP_A		"tinysys-scp-RV33_A"
#define DRM_NAME_SCP_A		"tinysys-scp-RV33_A_dram"

/******************************************************************************
* 1. New entries must be appended to the end of the structure.
* 2. Do NOT use conditional option such as #ifdef inside the structure.
******************************************************************************/
struct scp_region_info_st {
	uint32_t ap_loader_start;
	uint32_t ap_loader_size;
	uint32_t ap_firmware_start;
	uint32_t ap_firmware_size;
	uint32_t ap_dram_start;
	uint32_t ap_dram_size;
	uint32_t ap_dram_backup_start;
	/*	This is the size of the structure.
	 *	It can act as a version number if entries can only be
	 *	added to (not deleted from) the structure.
	 *	It should be the first entry of the structure, but for
	 *	compatibility reason, it is appended here.
	 */
	uint32_t struct_size;
	uint32_t scp_log_thru_ap_uart;
	uint32_t TaskContext_ptr;
	uint32_t scpctl;
	uint32_t regdump_start;
	uint32_t regdump_size;
};

void scp_set_devapc_domain(void);
int load_scp(void);
void disable_scp_hw(void);
int platform_fdt_scp(void *fdt);

#endif

