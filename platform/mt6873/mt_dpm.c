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

#include <stdlib.h>                    /* for atoi() */
#include <stdint.h>
#include <string.h>
#include <debug.h>
#include <platform/mt_gpt.h>              // for get_timer()
#include <arch/ops.h>                     // for arch_sync_cache_range()
#include <platform/boot_mode.h>
#include <platform/verified_boot.h>
#include <verified_boot_common.h>
#include <platform/sec_policy.h>
#include <part_interface.h>
#include <env.h>
#include <platform/mt_reg_base.h>
#include <assert.h>
#include <platform/mt_dpm.h>
#include <platform/errno.h>
#ifdef MTK_AB_OTA_UPDATER
#include "bootctrl.h"
#endif

extern void dsb(void);
extern int mboot_common_load_part(char *part_name, char *img_name, unsigned long addr);

static int verify_load_DPM_image(char *part_name, void *addr);

extern BOOT_ARGUMENT *g_boot_arg;
static void *dpm_dram_addr;
static char *dpm_part_name[] = {"dpm_1", "dpm_2"};

static int load_DPM_image(char *part_name, char *img_name, void *addr)
{
	uint32_t sec_ret;
	uint32_t DPM_vfy_time;
	int ret;
#ifdef MTK_SECURITY_SW_SUPPORT
	unsigned int policy_entry_idx = 0;
	unsigned int img_auth_required = 0;

	policy_entry_idx = get_policy_entry_idx(part_name);
	img_auth_required = get_vfy_policy(policy_entry_idx);
	/* verify cert chain of boot img */
	if (img_auth_required) {
		DPM_vfy_time = get_timer(0);
		sec_ret = sec_img_auth_init(part_name, img_name, 0);
		if (sec_ret)
			return -1; //if user load call assert, if eng load, pass the information to kernel, and then trigger a kernel api dump
		dprintf(CRITICAL, "[SBC] image %s cert vfy pass(%d ms)\n", img_name, (unsigned int)get_timer(DPM_vfy_time));
#ifdef MTK_SECURITY_ANTI_ROLLBACK
		sec_ret = sec_rollback_check(1);
		if (sec_ret) {
			dprintf(CRITICAL, "%s ver check fail...(0x%x)\n", img_name, sec_ret);
			return -1; //if user load call assert, if eng load, pass the information to kernel, and then trigger a kernel api dump
		}
#endif
	}
#endif

	ret = mboot_common_load_part(part_name, img_name, (unsigned long)addr);
	dprintf(INFO, "%s(): load %s ret=%d\n", __func__, img_name, ret);
	if (ret <= 0)
		return -1; //if user load call assert, if eng load, pass the information to kernel, and then trigger a kernel api dump

	/* Sync cache to make sure all data flush to DRAM */
	//arch_sync_cache_range((addr_t)addr, DPM_DRAM_SIZE);

#ifdef MTK_SECURITY_SW_SUPPORT
	if (img_auth_required) {
		DPM_vfy_time = get_timer(0);
		sec_ret = sec_img_auth(addr, ret);
		if (sec_ret)
			return -1;  //if user load call assert, if eng load, pass the information to kernel, and then trigger a kernel api dump
		dprintf(CRITICAL, "[SBC] %s vfy pass(%d ms)\n", img_name, (unsigned int)get_timer(DPM_vfy_time));
	}
#endif

	return ret;
}

static char *dpm_partition_name(void)
{
	int array_size = (int)(sizeof(dpm_part_name) / sizeof(dpm_part_name[0]));
	int i;

	for (i = 0; i < array_size; i++) {

		/*
		 * >0: partition active
		 *  0: partition inactive
		 * -1: partition doesn't exist
		 */
		if (partition_get_active_bit_by_name(dpm_part_name[i]) > 0)
			return dpm_part_name[i];
	}

	dprintf(CRITICAL, "no DPM partition with active bit marked, load %s\n", dpm_part_name[0]);

	return dpm_part_name[0];
}

/******************************************************************************
******************************************************************************/
int load_dpm(void)
{
	int ret;
#ifdef MTK_AB_OTA_UPDATER
	#define DPM_PARTITION_NAME_SIZE    10
	char part_name[DPM_PARTITION_NAME_SIZE];
#else
	char *part_name;
#endif

	dpm_dram_addr = (void *)(unsigned int)mblock_reserve_ext(&g_boot_arg->mblock_info,
	            DPM_DRAM_SIZE, DPM_DRAM_SIZE, DRAM_ADDR_MAX, 0, "DPM-reserved");
	dprintf(INFO, "[DPM] %s: dpm_dram_addr=%p\n", __func__, dpm_dram_addr);

	if (dpm_dram_addr == ((void *) 0)) {
		dprintf(CRITICAL, "[DPM] mblock_reserve fail\n");		
		//if user load call assert, if eng load, pass the information to kernel, and then trigger a kernel api dump
		return -1;
	}

#ifdef MTK_AB_OTA_UPDATER
	/* Compose the partition name for A/B systems. */
	memset(part_name, 0, sizeof(part_name));
	strncpy (part_name, "dpm", sizeof(part_name));

	char *p_AB_suffix;
	int part_name_len = strlen(part_name);

	p_AB_suffix = get_suffix();

	if (p_AB_suffix) {
		strncpy((void*)&part_name[part_name_len], (void*)p_AB_suffix,
		        sizeof(part_name) - part_name_len);
	}
	part_name[sizeof(part_name) - 1] = '\0';

#else
	part_name = dpm_partition_name();

	if (!part_name) {
		dprintf(CRITICAL, "[DPM]get partition failed\n");
		//if user load call assert, if eng load, pass the information to kernel, and then trigger a kernel api dump
		return -1;
	}
#endif /* MTK_AB_OTA_UPDATER*/

	ret = verify_load_DPM_image(part_name, dpm_dram_addr);
	if (ret < 0) {
		//if user load call assert, if eng load, pass the information to kernel, and then trigger a kernel api dump
		return -1;
	}

	dprintf(INFO, "%s(): done\n", __func__);
	return 0;
}

static int verify_load_DPM_image(char *part_name, void *addr)
{
	void *pm_ptr, *dm_ptr;
	int pm_size, dm_size;

	// step 1: load/verify pm
	pm_ptr = addr;
	pm_size = load_DPM_image(part_name, DPM_PM, pm_ptr);
	if (pm_size <= 0) {
		dprintf(CRITICAL, "[DPM] load_DPM_image fail %s\n", DPM_PM);
		return -1;
	}
	// step 2: load/verify dm
	dm_ptr = addr + DPM_DM_OFFSET;
	dm_size = load_DPM_image(part_name, DPM_DM, dm_ptr);
	if (dm_size <= 0) {
		dprintf(CRITICAL, "[DPM] load_DPM_image fail %s\n", DPM_DM);
		return -1;
	}

	//config DPM SRAM layout
	dprintf(INFO, "[DPM] %s: pm_ptr=%p pm_size=0x%x dm_ptr=%p dm_size=0x%x\n", __func__, pm_ptr, pm_size, dm_ptr, dm_size);
	if (pm_size > 0x6000) { //pm > 24K
		//bigger than sram size
		return -1;
	}
	else if (pm_size > 0x4000) { //pm > 16K
		//DRV_WriteReg32(DPM_CFG_CH0, DRV_Reg32(DPM_CFG_CH0)|0x0);
	}
	else if (pm_size > 0x2000) { //pm > 8K
		DRV_WriteReg32(DPM_CFG_CH0, DRV_Reg32(DPM_CFG_CH0)|0x10000000);
	}
	else { //pm < 8K
		DRV_WriteReg32(DPM_CFG_CH0, DRV_Reg32(DPM_CFG_CH0)|0x20000000);
	}

	//   DPM DRAM layout
	/***********************
	*     PM: 24/16/8      *
	************************
	*     DM               *
	************************/

	// step 6: copy PM to DPM_SRAM
	memcpy((void *) DPM_PM1_SRAM_BASE, pm_ptr, pm_size);
	memcpy((void *) DPM_DM1_SRAM_BASE, dm_ptr, dm_size);

	// step 7: write bootargs
	DRV_WriteReg32(DPM_BARGS_CH0_REG0, 0x00000000);
	DRV_WriteReg32(DPM_BARGS_CH0_REG1, 0x00000000);

	dsb();

	//RST of CH0
	DRV_WriteReg32(DPM_CFG_CH0, DRV_Reg32(DPM_CFG_CH0)|0x1);

	return 0;
}
