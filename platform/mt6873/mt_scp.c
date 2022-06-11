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
#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>
#include <fdt_op.h>
#endif
#include <assert.h>
#include <platform/mt_scp.h>
#if ENABLE_SCP_EMI_PROTECTION
#include <mt_emi_mpu.h>
#endif
#include <platform/errno.h>
#ifdef MTK_AB_OTA_UPDATER
#include "bootctrl.h"
#endif

extern void dsb(void);
extern unsigned int get_devinfo_with_index(unsigned int index);
extern u64 physical_memory_size(void);
extern int mboot_common_load_part(char *part_name, char *img_name, unsigned long addr);
extern void mtk_wdt_restart(void);

unsigned int get_scp_status(void);
static int verify_load_scp_image(char *part_name, void *addr);
int platform_scp_set_sram_region(int scp_A_sram_size);

#if defined(DEVICE_TREE_SUPPORT)
unsigned int get_scp_status(void);
unsigned int set_scp_status(unsigned int en);
int platform_fdt_scp_get_sram_size(void);
int platform_fdt_scp(void *fdt);
#else
unsigned int get_scp_status(void) { return 0; } /* return 0, if scp disable */
unsigned int set_scp_status(unsigned int en) { return 1; }  /* return 1, if fail */
int platform_fdt_scp_get_sram_size(void) { return -1; } /* return -1, if fail */
int platform_fdt_scp(void *fdt) { return 0; } /* return 0, if success */
#endif

extern BOOT_ARGUMENT *g_boot_arg;
static int load_scp_status = 0;
static void *dram_addr;
static char *scp_part_name[] = {"scp1", "scp2"};

static uint32_t roundup(uint32_t x, uint32_t y)
{
	return ((x + y - 1) / y) * y;
}

static int load_scp_image(char *part_name, char *img_name, void *addr)
{
	int ret;
#ifdef MTK_SECURITY_SW_SUPPORT
	uint32_t sec_ret;
	uint32_t scp_vfy_time;
	unsigned int policy_entry_idx = 0;
	unsigned int img_auth_required = 0;

	policy_entry_idx = get_policy_entry_idx(part_name);
	img_auth_required = get_vfy_policy(policy_entry_idx);
	/* verify cert chain of boot img */
	if (img_auth_required) {
		scp_vfy_time = get_timer(0);
		sec_ret = sec_img_auth_init(part_name, img_name, 0);
		if (sec_ret) {
			dprintf(CRITICAL, "[SBC] image %s auth init fail\n", img_name);
			assert(0);
		}
		dprintf(CRITICAL, "[SBC] image %s cert vfy pass(%d ms)\n", img_name, (unsigned int)get_timer(scp_vfy_time));
#ifdef MTK_SECURITY_ANTI_ROLLBACK
		sec_ret = sec_rollback_check(1);
		if (sec_ret) {
			dprintf(CRITICAL, "[SBC] image %s ver check fail...(0x%x)\n", img_name, sec_ret);
			assert(0);
		}
#endif
	}
#endif

	ret = mboot_common_load_part(part_name, img_name, (unsigned long)addr);
	dprintf(INFO, "%s(): load %s ret=%d\n", __func__, img_name, ret);
	if (ret <= 0)
		return -1;

#ifdef MTK_SECURITY_SW_SUPPORT
	if (img_auth_required) {
		scp_vfy_time = get_timer(0);
		sec_ret = sec_img_auth(addr, ret);
		if (sec_ret) {
			dprintf(CRITICAL, "[SBC] image %s auth check fail\n", img_name);
			assert(0);
		}
		dprintf(CRITICAL, "[SBC] %s vfy pass(%d ms)\n", img_name, (unsigned int)get_timer(scp_vfy_time));
	}
#endif

	return ret;
}

static char *scp_partition_name(void)
{
	int array_size = (int)(sizeof(scp_part_name) / sizeof(scp_part_name[0]));
	int i;

	for (i = 0; i < array_size; i++) {
		if (partition_get_active_bit_by_name(scp_part_name[i]) == 1)
			return scp_part_name[i];
	}

	dprintf(CRITICAL, "no scp partition with active bit marked, load %s\n", scp_part_name[0]);

	return scp_part_name[0];
}

#if 0
/******************************************************************************
* This function is used to change SRAM DELSEL for MT6761, and it will make the
* system more stable. It should be called before SCP is used.
******************************************************************************/
static void change_sram_delsel(void)
{
	DRV_WriteReg32(MBIST_AO_BASE + 0x24, 0x24F3001B);
	DRV_WriteReg32(MBIST_AO_BASE + 0x28, 0x001B24F3);
	DRV_WriteReg32(MBIST_AO_BASE + 0x2C, 0x24F324F3);
}
#endif

void scp_set_devapc_domain(void)
{
	/* devapc domain setting, Core0 = 1, Core1 = 1, ADSP = 0 */
	DRV_WriteReg32(R_SEC_DOMAIN, DOMAIN_SCP);
	DRV_WriteReg32(R_ADSP_DOMAIN, DOMAIN_ADSP);
}

/******************************************************************************
******************************************************************************/
int load_scp(void)
{
	int ret;
	int scp_A_sram_size = 0;
#ifdef MTK_AB_OTA_UPDATER
	#define SCP_PARTITION_NAME_SIZE    10
	char part_name[SCP_PARTITION_NAME_SIZE];
	char *p_AB_suffix;
	int part_name_len = 0;
#else
	char *part_name;
#endif

	/* check if scp is turned off manually*/
	if (get_scp_status() == 0) {
		dprintf(CRITICAL, "[SCP] get_scp_status disabled\n");
		goto error;
	}

	dram_addr = (void *)(unsigned int)mblock_reserve_ext(&g_boot_arg->mblock_info,
	            SCP_DRAM_SIZE, SCP_DRAM_ALIGN, DRAM_ADDR_MAX, 0, "SCP-reserved");

	dprintf(INFO, "[SCP] %s: dram_addr=%p, size= 0x%x\n", __func__, dram_addr, SCP_DRAM_SIZE);
	if (dram_addr == ((void *) 0)) {
		dprintf(CRITICAL, "[SCP] mblock_reserve fail\n");
		goto error;
	}

#ifdef MTK_AB_OTA_UPDATER
	p_AB_suffix = get_suffix();

	if (p_AB_suffix) {
		/* Compose the partition name for A/B systems. */
		memset(part_name, 0, SCP_PARTITION_NAME_SIZE);
		strncpy (part_name, "scp", strlen("scp"));
		part_name_len = strlen(part_name);

		strncpy((void*)&part_name[part_name_len], (void*)p_AB_suffix,
		        sizeof(part_name) - part_name_len);

		part_name[sizeof(part_name) - 1] = '\0';
	} else {
		dprintf(CRITICAL, "[SCP]get partition failed\n");
		goto error;
	}

#else
	part_name = scp_partition_name();
	if (!part_name) {
		dprintf(CRITICAL, "[SCP]get partition failed\n");
		goto error;
	}
#endif /* MTK_AB_OTA_UPDATER*/

	scp_A_sram_size = platform_fdt_scp_get_sram_size();

	dprintf(INFO, "[SCP] part_name=%s, scp_A_sram_size=%d\n",
	        part_name, scp_A_sram_size);
	if (scp_A_sram_size < 0) {
		goto error;
	}

	ret = verify_load_scp_image(part_name, dram_addr);
	if (ret < 0) {
		goto error;
	}

	/*clean dcache & icache before set up EMI MPU*/
	arch_sync_cache_range((addr_t)dram_addr, SCP_DRAM_SIZE);

	/*
	 * setup EMI MPU
	 * domain 0: AP
	 * domain 3: SCP
	 */
#if ENABLE_SCP_EMI_PROTECTION
	struct emi_region_info_t region_info;
	region_info.start = (unsigned long long)(unsigned int)dram_addr;
	region_info.end = (unsigned long long)(unsigned int)(dram_addr + SCP_DRAM_SIZE - 1);
	region_info.region = SCP_EMI_REGION;

	SET_ACCESS_PERMISSION(region_info.apc, UNLOCK,
	                      FORBIDDEN, FORBIDDEN, FORBIDDEN, FORBIDDEN,
	                      FORBIDDEN, FORBIDDEN, FORBIDDEN, FORBIDDEN,
	                      FORBIDDEN, FORBIDDEN, FORBIDDEN, FORBIDDEN,
	                      NO_PROTECTION, FORBIDDEN, FORBIDDEN, NO_PROTECTION);

	emi_mpu_set_protection(&region_info);
#endif

	dprintf(INFO, "%s(): done\n", __func__);

	load_scp_status = 1;

	return 0;

error:
	/*
	 * @ret = 0, malloc() error
	 * @ret < 0, error code from load_scp_image()
	 */
	load_scp_status = -1;

	return -1;
}

#if defined(DEVICE_TREE_SUPPORT)
int platform_fdt_scp(void *fdt)
{
	int nodeoffset;
	char *ret;

	nodeoffset = fdt_node_offset_by_compatible(fdt, -1, "mediatek,scp");
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "[SCP] %s: getting node from dtb fails\n", __func__);
		return 1; /* return 1, if fail */
	}

	if (load_scp_status <= 0)
		ret = "disabled";
	else
		ret = "okay";

	if (fdt_setprop(fdt, nodeoffset, "status", ret, strlen(ret)) < 0) {
		dprintf(CRITICAL, "[SCP] %s: set status fails\n", __func__);
		return 1; /* return 1, if fail */
	}

	dprintf(CRITICAL, "[SCP] set core status=%s\n", ret);

	return 0; /* return 0, if success */
}

/* Load SCP sram size from dts */
int platform_fdt_scp_get_sram_size(void)
{
	int nodeoffset;
	unsigned int *data = NULL;
	int len = 0;
	void *kernel_fdt = get_kernel_fdt();

	if (kernel_fdt == NULL)
		panic("kernel fdt is NULL!\n");

	dprintf(INFO, "%s()\n", __func__);

	nodeoffset = fdt_node_offset_by_compatible(kernel_fdt, -1, "mediatek,scp");
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "[SCP] mediatek,scp not found!\n");
		return -1;  /* return -1, if fail */
	}

	data = (unsigned int *) fdt_getprop(kernel_fdt, nodeoffset, "scp_sramSize", &len);
	if (data == NULL) {
		dprintf(CRITICAL, "[SCP] get scp_sramSize info fail\n");
		return -1;  /* return -1, if fail */
	}

	dprintf(INFO, "scp sram_size=%d, len=%d\n",
	        fdt32_to_cpu(*(unsigned int *)data), len);

	return fdt32_to_cpu(*(unsigned int *)data);
}

unsigned int get_scp_status(void)
{
	int scp_status;
	int nodeoffset;
	char *data = NULL;
	int len = 0;
	void *kernel_fdt = get_kernel_fdt();

	if (kernel_fdt == NULL)
		panic("kernel fdt is NULL!\n");

	nodeoffset = fdt_node_offset_by_compatible(kernel_fdt, -1, "mediatek,scp");
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "scp get node from dtb fail\n");
		return 0;
	}

	data = (char*)fdt_getprop(kernel_fdt, nodeoffset, "status", &len);
	if (data == NULL) {
		dprintf(CRITICAL, "scp get status from dtb fail\n");
		return 0;
	}

	if (strncmp(data, "okay", len) == 0)
		scp_status = 1; /* 1 goes for "enabled" */
	else
		scp_status = 0; /* 0 goes for "disabled" */

	char *scp_env = get_env("scp");
	scp_status = (scp_env == NULL) ? scp_status : atoi(scp_env);
	dprintf(CRITICAL,"[SCP] current setting is %d.\n", scp_status);

	return scp_status;
}

unsigned int set_scp_status(unsigned int en)
{
	char *SCP_STATUS[2] = {"0","1"};

	if (set_env("scp", SCP_STATUS[en]) == 0) {
		dprintf(CRITICAL,"[SCP]set SCP %s success. Plz reboot to make it applied.\n",SCP_STATUS[en]);
		return 0; /* return 0, if success*/
	} else {
		dprintf(CRITICAL,"[SCP]set SCP %s fail.\n",SCP_STATUS[en]);
		return 1; /* return 1, if fail */
	}
}

#endif

/******************************************************************************
******************************************************************************/
#ifdef MTK_TINYSYS_SCP_SUPPORT

unsigned int get_scp_scpctl(void)
{
	unsigned int scpctl = 0;
	int nodeoffset;
	char *data = NULL;
	int len = 0;
	char *prompt = "[SCPCTL]:";
	char *scpctl_env = NULL;
	void *kernel_fdt = get_kernel_fdt();

	if (kernel_fdt == NULL)
		panic("kernel fdt is NULL!\n");

	nodeoffset = fdt_node_offset_by_compatible(kernel_fdt, -1, "mediatek,scp");
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "%s get node failed\n", prompt);
		goto __skip_dtb;
	}

	data = (char *)fdt_getprop(kernel_fdt, nodeoffset, "scpctl", &len);
	if (data == NULL) {
		dprintf(CRITICAL, "%s scpctl fail\n", prompt);
		goto __skip_dtb;
	}

	scpctl = atoul(data);

__skip_dtb:
	scpctl_env = get_env("scpctl");
	if (scpctl_env != NULL) {
		/* skip leading white spaces */
		while (*scpctl_env == ' ')
			scpctl_env++;

		scpctl = atoul(scpctl_env);
	}

	dprintf(CRITICAL,"%s setting is 0x%x.\n", prompt, scpctl);
	return scpctl;
}

unsigned int set_scp_scpctl(unsigned int value)
{
	char *prompt = "[SCPCTL]:";
	char buf[16]; /* power of 2 for the length of the format, 0x######## */

	snprintf(buf, sizeof(buf), "0x%x", value);

	if (set_env("scpctl", buf) == 0) {
		dprintf(CRITICAL,"%s setting %s successed. please reboot.\n",prompt, buf);
		return 0; /* return 0, if success*/
	}
	else {
		dprintf(CRITICAL,"%s setting %s failed.\n", prompt, buf);
		return 1; /* return 1, if fail */
	}
}
#endif

/******************************************************************************
******************************************************************************/
unsigned int get_scp_log_thru_ap_uart(void)
{
	unsigned int enable = 0;
	char *env = get_env("scp_ap_uart");

	if (env == NULL) {
		dprintf(CRITICAL, "[SCP] Get SCP log thru AP UART: 0 (default)\n");
	} else {
		enable = atoi(env);
		dprintf(CRITICAL, "[SCP] Get SCP log thru AP UART: %d\n", enable);
	}
	return enable;
}


/******************************************************************************
* Caller must make sure that the argument "en" is less than 2.
******************************************************************************/
void set_scp_log_thru_ap_uart(unsigned int en)
{
	char *en_array[2] = {"0", "1"};

	if (set_env("scp_ap_uart", en_array[en]) == 0) {
		dprintf(CRITICAL, "[SCP] Set SCP log thru AP UART: %s\n", en_array[en]);
	} else {
		dprintf(CRITICAL, "[SCP] Failed to set SCP log thru AP UART to %s!\n",
			en_array[en]);
	}
}

static int verify_load_scp_image(char *part_name, void *addr)
{
	int img_size, ld_size, fw_size;
	int scp_sram_size, scp_dram_img_size;
	void *img_ptr, *ld_ptr, *fw_ptr;
	void *scp_dram_img_ptr, *scp_dram_backup_ptr = NULL;
	uint32_t reg_temp;
	struct scp_region_info_st *scp_region_info;


	/* step 0: set core0/1 RSTN */
	DRV_WriteReg32(R_CORE0_SW_RSTN_SET, 0x1);
	DRV_WriteReg32(R_CORE1_SW_RSTN_SET, 0x1);

	// step 1: enable sram, enable 1 block per time
	for (reg_temp = 0xffffffff; reg_temp != 0;) {
		reg_temp = reg_temp >> 1;
		DRV_WriteReg32(R_L2TCM_SRAM_PD0, reg_temp);
	}

	for (reg_temp = 0xffffffff; reg_temp != 0;) {
		reg_temp = reg_temp >> 1;
		DRV_WriteReg32(R_L2TCM_SRAM_PD1, reg_temp);
	}

	for (reg_temp = 0xffffffff; reg_temp != 0;) {
		reg_temp = reg_temp >> 1;
		DRV_WriteReg32(R_L2TCM_SRAM_PD2, reg_temp);
	}

	for (reg_temp = 0xffffffff; reg_temp != 0;) {
		reg_temp = reg_temp >> 1;
		DRV_WriteReg32(R_CPU0_SRAM_PD, reg_temp);
	}

	for (reg_temp = 0xffffffff; reg_temp != 0;) {
		reg_temp = reg_temp >> 1;
		DRV_WriteReg32(R_CPU1_SRAM_PD, reg_temp);
	}

	for (reg_temp = 0xffffffff; reg_temp != 0;) {
		reg_temp = reg_temp >> 1;
		DRV_WriteReg32(R_L1TCM_SRAM_PDN, reg_temp);
	}

	/* Clean SRAM. */
	memset((void *) SCP_SRAM_BASE, 0, SCP_SRAM_SIZE);

	// Layout of SCP reserved DRAM memory.
	/************************
	 * +------------------+ *
	 * |  SCP Loader      | *
	 * +------------------+ *
	 * |  SCP Firmware    | *
	 * +------------------+ *
	 ************************
	 *    SCP DRAM          *
	 ************************
	 *    SCP DRAM backup   *
	 ************************/

	// step 2: load/verify firmware
	img_ptr  = addr;
	img_size = load_scp_image(part_name, IMG_NAME_SCP_A, img_ptr);
	if (img_size <= 0) {
		dprintf(CRITICAL, "[SCP] load_scp_image fail %s\n", IMG_NAME_SCP_A);
		return -1;
	}

	ld_ptr  = addr;
	ld_size = SCP_LOADER_SIZE;

	fw_ptr  = addr + SCP_FW_OFFSET;
	fw_size = img_size;

	// step 3: load/verify scp_dram_img code (optional)
	scp_dram_img_ptr  = addr + SCP_DRAM_IMG_OFFSET;
	scp_dram_img_size = load_scp_image(part_name, DRM_NAME_SCP_A, scp_dram_img_ptr);

	if (scp_dram_img_size > 0) {
		dprintf(INFO, "[SCP] load_scp_image %s %d bytes (max size= 0x%x / 2 Cores).\n",
		              DRM_NAME_SCP_A, scp_dram_img_size, SCP_DRAM_IMG_SIZE);

		/* assert if size of feature placed in dram (size double due to Core 0 and Core 1)
		 * larger than SCP_DRAM_IMG_SIZE. */
		if ((roundup(scp_dram_img_size, 1024)*2) > SCP_DRAM_IMG_SIZE)
			ASSERT(0);

		// step 3.1 backup scp_dram_img code
		scp_dram_backup_ptr = scp_dram_img_ptr + roundup(scp_dram_img_size, 1024)*2;
		memcpy(scp_dram_backup_ptr, scp_dram_img_ptr, scp_dram_img_size);
	} else {
		dprintf(INFO, "[SCP] Not support- scp_dram_img\n");
	}

	// step 4: copy loader to sram
	memcpy((void *) SCP_SRAM_BASE, img_ptr, ld_size);

	// step 5: save firmware/cache info to sram
	scp_region_info = (struct scp_region_info_st*)(SCP_SRAM_BASE + 0x4);
	scp_region_info->ap_loader_start   = (uint32_t)ld_ptr;
	scp_region_info->ap_loader_size    = (uint32_t)ld_size;
	scp_region_info->ap_firmware_start = (uint32_t)fw_ptr;

#if defined(DEVICE_TREE_SUPPORT)
	scp_sram_size = platform_fdt_scp_get_sram_size();
#else
	scp_sram_size = SCP_SRAM_SIZE;
#endif
	dprintf(INFO, "[SCP]sram size=%u bytes\n", scp_sram_size);

	if (fw_size > scp_sram_size) {
		scp_region_info->ap_firmware_size = scp_sram_size;
		dprintf(INFO, "[SCP](overlay)firmware size %d bytes\n", scp_region_info->ap_firmware_size);
	} else {
		scp_region_info->ap_firmware_size = (uint32_t)fw_size;
	}

	scp_region_info->ap_dram_start = (uint32_t)scp_dram_img_ptr;
	scp_region_info->ap_dram_size  = (uint32_t)scp_dram_img_size;
	scp_region_info->ap_dram_backup_start = (uint32_t)scp_dram_backup_ptr;
	scp_region_info->scp_log_thru_ap_uart = get_scp_log_thru_ap_uart();
	scp_region_info->scpctl = get_scp_scpctl();

	dprintf(INFO, "scp_region_info->ap_loader_start 0x%x\n",      scp_region_info->ap_loader_start);
	dprintf(INFO, "scp_region_info->ap_loader_size 0x%x\n",       scp_region_info->ap_loader_size);
	dprintf(INFO, "scp_region_info->ap_firmware_start 0x%x\n",    scp_region_info->ap_firmware_start);
	dprintf(INFO, "scp_region_info->ap_firmware_size 0x%x\n",     scp_region_info->ap_firmware_size);
	dprintf(INFO, "scp_region_info->ap_dram_start 0x%x\n",        scp_region_info->ap_dram_start);
	dprintf(INFO, "scp_region_info->ap_dram_size 0x%x\n",         scp_region_info->ap_dram_size);
	dprintf(INFO, "scp_region_info->ap_dram_backup_start 0x%x\n", scp_region_info->ap_dram_backup_start);
	dprintf(INFO, "scp_region_info->scp_log_thru_ap_uart 0x%x\n", scp_region_info->scp_log_thru_ap_uart);
	dprintf(INFO, "scp_region_info->scpctl 0x%x\n", scp_region_info->scpctl);

	dsb();

//	SCP_JTAG_REG |= SCP_JTAG_EN;
	dsb();

	return 0;
}

void disable_scp_hw(void)
{
	/*
	SW_RSTN = 0x0
	SW_RSTN_DUAL = 0x0
	CLK_SW_SEL = 0x1 //switch to 32Khz
	CLK_ENABLE = 0x0 //disable any clk request
	SRAM_PDN = 0xffffff
	*/
	DRV_WriteReg32(R_CORE0_SW_RSTN_SET, 0x1);
	DRV_WriteReg32(R_CORE1_SW_RSTN_SET, 0x1);
	DRV_WriteReg32(R_SCP_CLK_SEL, 0x1);    /*turn off scp clock*/
	DRV_WriteReg32(R_SCP_CLK_EN, 0x0);
	DRV_WriteReg32(R_L1TCM_SRAM_PDN, 0xFFFFFFFF); /*turn off scp sram*/
	DRV_WriteReg32(R_L2TCM_SRAM_PD0, 0xFFFFFFFF);
	DRV_WriteReg32(R_L2TCM_SRAM_PD1, 0xFFFFFFFF);
	DRV_WriteReg32(R_L2TCM_SRAM_PD2, 0xFFFFFFFF);
	DRV_WriteReg32(R_CPU0_SRAM_PD, 0xFFFFFFFF);
	DRV_WriteReg32(R_CPU1_SRAM_PD, 0xFFFFFFFF);
	DRV_WriteReg32(R_TCM_TAIL_SRAM_PD, 0x3);

	dprintf(CRITICAL, "DISABLE SCP\n");
}
