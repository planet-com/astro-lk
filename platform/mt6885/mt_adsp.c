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

#include <stdint.h>
#include <string.h>
#include <debug.h>
#include <platform.h>
#include <platform/mt_gpt.h>
#include <platform/boot_mode.h>
#include <part_interface.h>
#include <pal_typedefs.h>
#include <pal_assert.h>
#include <pal_log.h>
#include <platform/verified_boot.h>
#include <env.h>
#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>
#include <fdt_op.h>
#endif
#include <assert.h>
#include <platform/mt_adsp.h>
#if ENABLE_ADSP_EMI_PROTECTION
#include <platform/mt_emi_mpu.h>
#endif
#include <platform/errno.h>
#include <spm.h>  //mtcmos
#include <arch/ops.h>   // for arch_sync_cache_range()

#define ALIGN_TO(x, n)  \
    (((x) + ((n) - 1)) & ~((n) - 1))

static char module_prefix[] = "[ADSP]";
extern BOOT_ARGUMENT *g_boot_arg;
static uint32_t g_dram_size = ADSP_DRAM_SIZE;
static uint32_t g_total_dram_size = 0;
static unsigned int adsp_load_status = 0;
static void *dram_phys_addr;
static char *adsp_part_name = "audio_dsp"; /* name registered in partition */

struct adsp_mem_attr {
	uint32_t enable; /* default setting */
	uint32_t size;
};

static struct adsp_mem_attr mem_attr[AUDIO_MEM_TOTAL_NUM];

struct image_node image_table[ADSP_NUM_IMAGE] = {
	[ADSP_A_IMAGE_ITCM] = IMAGE_UNIT(ADSP_A_ITCM_NAME, ADSP_A_ITCM_BASE, ADSP_A_ITCM_SIZE),
	[ADSP_A_IMAGE_DTCM] = IMAGE_UNIT(ADSP_A_DTCM_NAME, ADSP_A_DTCM_BASE, ADSP_A_DTCM_SIZE),
	[ADSP_A_IMAGE_DRAM] = IMAGE_UNIT(ADSP_A_DRAM_NAME, 0,                ADSP_A_DRAM_SIZE),
	[ADSP_B_IMAGE_ITCM] = IMAGE_UNIT(ADSP_B_ITCM_NAME, ADSP_B_ITCM_BASE, ADSP_B_ITCM_SIZE),
	[ADSP_B_IMAGE_DTCM] = IMAGE_UNIT(ADSP_B_DTCM_NAME, ADSP_B_DTCM_BASE, ADSP_B_DTCM_SIZE),
	[ADSP_B_IMAGE_DRAM] = IMAGE_UNIT(ADSP_B_DRAM_NAME, 0,                ADSP_B_DRAM_SIZE),
};

static char *adsp_audio_mem_name[AUDIO_MEM_TOTAL_NUM] = {
	[AUDIO_MEM_VOIP_ID]         = "mtk_dsp_voip",
	[AUDIO_MEM_PRIMARY_ID]      = "mtk_dsp_primary",
	[AUDIO_MEM_OFFLOAD_ID]      = "mtk_dsp_offload",
	[AUDIO_MEM_DEEPBUFFER_ID]   = "mtk_dsp_deep",
	[AUDIO_MEM_PLAYBACK_ID]     = "mtk_dsp_playback",
	[AUDIO_MEM_MUSIC_ID]        = "mtk_dsp_music",
	[AUDIO_MEM_CAPTURE_UL1_ID]  = "mtk_dsp_capture1",
	[AUDIO_MEM_A2DP_ID]         = "mtk_dsp_a2dp",
	[AUDIO_MEM_DATAPROVIDER_ID] = "mtk_dsp_dataprovider",
	[AUDIO_MEM_CALL_FINAL_ID]   = "mtk_dsp_call_final",
	[AUDIO_MEM_FAST_ID]         = "mtk_dsp_fast",
	[AUDIO_MEM_KTV_ID]          = "mtk_dsp_ktv",
	[AUDIO_MEM_AFE_ID]          = "mtk_dsp_mem_afe",
};

static char *adsp_rsv_name[ADSP_RSV_TOTAL_NUM] = {
	[ADSP_RSV_IPIDMA_A]         = "adsp-rsv-ipidma-a",
	[ADSP_RSV_IPIDMA_B]         = "adsp-rsv-ipidma-b",
	[ADSP_RSV_LOGGER_A]         = "adsp-rsv-logger-a",
	[ADSP_RSV_LOGGER_B]         = "adsp-rsv-logger-b",
	[ADSP_RSV_C2C]              = "adsp-rsv-c2c",
	[ADSP_RSV_DBG_DUMP_A]       = "adsp-rsv-dbg-dump-a",
	[ADSP_RSV_DBG_DUMP_B]       = "adsp-rsv-dbg-dump-b",
	[ADSP_RSV_CORE_DUMP_A]      = "adsp-rsv-core-dump-a",
	[ADSP_RSV_CORE_DUMP_B]      = "adsp-rsv-core-dump-b",
	[ADSP_RSV_AUDIO]            = "adsp-rsv-audio",
};

extern void dsb(void);
extern int mboot_common_load_part(char *part_name, char *img_name, unsigned long addr);
extern int verify_load_adsp_image(char *part_name, void *addr);

static int calc_and_update_audio_rsv(void);
static int update_and_set_adsp_rsv_size(void);
static int get_adsp_sysram_info_from_dt(void);
static uint32_t parse_adsp_memory_from_dt(void);
static void set_adsp_image_base(uint32_t id, void *base);
static void set_adsp_image_size(uint32_t id, uint32_t size);
static void set_adsp_dram_remap(void *base);
static void print_adsp_image_info(void);

static char *adsp_partition_name(void)
{
	return adsp_part_name;
}

int load_adsp_image(char *part_name, char *img_name, void *addr)
{
	int ret = 0;

#ifdef MTK_SECURITY_SW_SUPPORT
	/* we use this API because audio dsp TCM 8 byte access
	 * limitation */
	ret = img_auth_stor(part_name, img_name, 0x1);
	if (ret != 0) {
		pal_log_err("<ASSERT> %s:line %d\n", __FILE__, __LINE__);
		PAL_ASSERT(0);
	}
#endif /* MTK_SECURITY_SW_SUPPORT */

	ret = mboot_common_load_part(part_name, img_name, (unsigned long)addr);
	dprintf(CRITICAL, "[ADSP]mboot_common_load_part ret=%d\n",ret);
	if (ret <= 0)
		ret = -1;

	return ret;
}

int load_adsp(void)
{
	int ret;
	char *part_name;

#ifdef DEVICE_TREE_SUPPORT
	g_dram_size = parse_adsp_memory_from_dt();
	if (!g_dram_size)
		goto error;
#else
	dprintf(CRITICAL, "[ADSP] \"DEVICE_TREE_SUPPORT\" is not defined\n");
#endif

	/* memory to store i/dtcm image from partition loader */
	g_total_dram_size= ALIGN_TO(g_dram_size + ADSP_TCM_TOTAL_SIZE, RESERVED_MEM_ALIGN);
	dram_phys_addr = (void *)(uint32_t)mblock_reserve_ext(&g_boot_arg->mblock_info, g_total_dram_size,
			 ADSP_DRAM_ADDR_ALIGN, ADSP_DRAM_ADDR_MAX, 0, ADSP_MEM_RESERVED_KEY);
	if (!dram_phys_addr) {
		dprintf(CRITICAL, "[ADSP] mblock_reserve address fail. phys view=0x%x, adsp view=0x%x\n",
			(uint32_t)dram_phys_addr, (uint32_t)image_table[ADSP_A_IMAGE_DRAM].base);
	} else {
		/* update target(adsp a & b) dram address */
		dprintf(INFO, "[ADSP] mblock_reserve success. phys view=0x%x, adsp view=0x%x\n",
			(uint32_t)dram_phys_addr, (uint32_t)image_table[ADSP_A_IMAGE_DRAM].base);
		set_adsp_dram_remap(dram_phys_addr);
		print_adsp_image_info();
	}

	part_name = adsp_partition_name();
	if(!part_name) {
		dprintf(CRITICAL, "[ADSP]get partition failed\n");
		goto error;
	}

	/* enable adsp clock & release CPU to access hifi3 */
	switch_adsp_power(true, false);
	adsp_sw_reset();

	/* load adsp image */
	ret = verify_load_adsp_image(part_name, dram_phys_addr);
	if (ret < 0) {
		dprintf(CRITICAL, "[ADSP]verify %s failed, ret=%d(-1: load image fail, -5:sram size<0, -6:sram size not 32*N)\n", part_name, ret);
		goto error;
	}

	/* disable adsp clock */
#ifndef BRINGUP_WR
	switch_adsp_power(false, true);
#endif
	/* clean dcache & icache before set up EMI MPU */
	arch_sync_cache_range((addr_t)dram_phys_addr, g_total_dram_size);

	/* setup EMI MPU
	 * domain 0: AP
	 * domain 10: ADSP
	 */
#if ENABLE_ADSP_EMI_PROTECTION
	struct emi_region_info_t region_info;

	region_info.start = (unsigned long long)(uint32_t)dram_phys_addr;
	region_info.end = (unsigned long long)((uint32_t)dram_phys_addr + g_total_dram_size - 0x1);
	region_info.region = MPU_REGION_ID_ADSP_RO_MEM;
	SET_ACCESS_PERMISSION(region_info.apc, UNLOCK,
				  FORBIDDEN, FORBIDDEN, FORBIDDEN, FORBIDDEN,
				  FORBIDDEN, NO_PROTECTION, FORBIDDEN, FORBIDDEN,
				  FORBIDDEN, FORBIDDEN, FORBIDDEN, FORBIDDEN,
				  FORBIDDEN, FORBIDDEN, FORBIDDEN, SEC_R_NSEC_R);
	emi_mpu_set_protection(&region_info);
#endif

	adsp_load_status = 1;
	dprintf(INFO, "%s(): done\n", __func__);
	return 0;

error:
	/*
	 * @ret = 0, malloc() error
	 * @ret < 0, eror code from load_adsp_image()
	*/
	adsp_load_status = 0;
	return -1;
}

#ifdef DEVICE_TREE_SUPPORT

static int update_and_set_adsp_rsv_size(void)
{
	int nodeoffset, len;
	void *fdt = get_kernel_fdt();
	const void *data;
	uint32_t mem_id, size, total_size = 0;
	fdt64_t rsv_size;

	if (fdt == NULL)
		panic("kernel fdt is NULL!\n");

	nodeoffset = fdt_node_offset_by_compatible(fdt, -1, ADSP_COMMON_DTS_COMPATIBLE);
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "[ADSP] Failed to find %s in dtb\n",
			ADSP_COMMON_DTS_COMPATIBLE);
		return -1;
	}

	for (mem_id = 0; mem_id < ADSP_RSV_TOTAL_NUM; mem_id ++) {
		data = fdt_getprop(fdt, nodeoffset, adsp_rsv_name[mem_id], &len);
		if (data) {
			size = fdt32_to_cpu(*(uint32_t *)data);
			total_size += size;
		} else {
			dprintf(CRITICAL, "[ADSP] get \"%s\" fail\n", adsp_rsv_name[mem_id]);
			continue;
		}
	}

	nodeoffset = fdt_node_offset_by_compatible(fdt, -1, ADSP_SHARE_DTS_COMPATIBLE);
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "[ADSP] %s is not found\n", ADSP_SHARE_DTS_COMPATIBLE);
		return -1;
	}

	/* update reserve memory size */
	rsv_size = cpu_to_fdt64((uint64_t)ALIGN_TO(total_size, RESERVED_MEM_ALIGN));
	fdt_setprop_inplace(fdt, nodeoffset, "size", &rsv_size, sizeof(rsv_size));

	return 0;
}

/* return value: size of total dram images */
static uint32_t parse_adsp_memory_from_dt(void)
{
	uint32_t adsp_dram_tail, adsp_dram_head;

	/* audio feature from dts */
	calc_and_update_audio_rsv();
	update_and_set_adsp_rsv_size();

	/* system from dts */
	get_adsp_sysram_info_from_dt();

	adsp_dram_head = (uint32_t)image_table[ADSP_A_IMAGE_DRAM].base;
	adsp_dram_tail = (uint32_t)image_table[ADSP_B_IMAGE_DRAM].base + image_table[ADSP_B_IMAGE_DRAM].size;
	if (!adsp_dram_head || !adsp_dram_tail ) {
		dprintf(CRITICAL, "%s error: adsp dram size is NULL!\n", __func__);
		return 0;
	} else if ((adsp_dram_tail - adsp_dram_head) > ADSP_DRAM_ADDR_ALIGN) {
		dprintf(CRITICAL, "%s error: adsp dram size 0x%x exceeds dram remap size!\n",
			__func__, (adsp_dram_tail - adsp_dram_head));
		return 0;
	}

	if ((uint32_t)image_table[ADSP_A_IMAGE_DRAM].base + image_table[ADSP_A_IMAGE_DRAM].size
		!= (uint32_t)image_table[ADSP_B_IMAGE_DRAM].base)
		dprintf(CRITICAL,  "%s dram image layout is not contiguous\n", __func__);

	return (adsp_dram_tail - adsp_dram_head);
}

static int calc_and_update_audio_rsv(void)
{
	int nodeoffset, len;
	void *fdt = get_kernel_fdt();
	const void *data;
	uint32_t mem_id, mem_offset;
	uint32_t total_mem = 0;
	bool afe_enable;
	fdt32_t rsv_size;

	/* get snd_audio_dsp node,
	   check audio feature set and calc total memory size
	*/
	nodeoffset = fdt_node_offset_by_compatible(fdt, -1, SND_ADSP_DTS_COMPATIBLE);
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "[ADSP] %s is not found\n", SND_ADSP_DTS_COMPATIBLE);
		return -1;
	}
	for (mem_id = 0; mem_id < AUDIO_MEM_TOTAL_NUM; mem_id ++) {
		if (mem_id < AUDIO_MEM_TASK_NUM)
			mem_offset = 4;
		else
			mem_offset = 1;
		data = fdt_getprop(fdt, nodeoffset, adsp_audio_mem_name[mem_id], &len);
		if (data) {
			mem_attr[mem_id].enable = fdt32_to_cpu(*(uint32_t *)data);
			mem_attr[mem_id].size = fdt32_to_cpu(*((uint32_t *)data + mem_offset));
		} else {
			dprintf(CRITICAL, "[ADSP] get \"%s\" fail\n", adsp_audio_mem_name[mem_id]);
			continue;
		}

		if (mem_id < AUDIO_MEM_TASK_NUM && mem_attr[mem_id].enable != 0) {
			total_mem += mem_attr[mem_id].size;
			afe_enable = true;
		}
	}

	/* architecture-specific */
	if (afe_enable && mem_attr[AUDIO_MEM_AFE_ID].enable)
		total_mem += mem_attr[AUDIO_MEM_AFE_ID].size;
	if (mem_attr[AUDIO_MEM_CALL_FINAL_ID].enable)
		total_mem -= mem_attr[AUDIO_MEM_CALL_FINAL_ID].size;

	/* write audio reserved memory back to adsp_common node */
	nodeoffset = fdt_node_offset_by_compatible(fdt, -1, ADSP_COMMON_DTS_COMPATIBLE);
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "[ADSP] %s is not found\n", ADSP_COMMON_DTS_COMPATIBLE);
		return -1;
	}
	rsv_size = cpu_to_fdt32(total_mem);
	fdt_setprop_inplace(fdt, nodeoffset, adsp_rsv_name[ADSP_RSV_AUDIO], &rsv_size, sizeof(rsv_size));

	dprintf(INFO, "%s update audio feature memory = 0x%x\n", __func__, total_mem);
	return 0;
}

static int get_adsp_sysram_info_from_dt(void)
{
	int nodeoffset, len;
	int n = 0;
	char compat_name[32];
	void *base = NULL;
	void *fdt = get_kernel_fdt();
	const void *fdt_data;
	uint32_t idx, size = 0, core_id = 0;
	uint32_t *data;

	for (idx = 0; idx < ADSP_NUM_IMAGE; idx++) {
		if (strstr(image_table[idx].name, "sram") == NULL) {
			continue;
		}
		memset(compat_name, 0, sizeof(compat_name));
		n = snprintf(compat_name, sizeof(compat_name), "%s_%d",
			ADSP_CORE_DTS_COMPATIBLE, core_id);
		if (n < 0 || n > (int)sizeof(compat_name))
			return -2;

		nodeoffset = fdt_node_offset_by_compatible(fdt, -1, compat_name);
		if (nodeoffset < 0) {
			dprintf(CRITICAL, "%s failed to find %s in dtb\n",
				__func__, compat_name);
			return -1;
		}

		fdt_data = fdt_getprop(fdt, nodeoffset, "system", &len);
		if (!fdt_data) {
			return -1;
		}
		data = (uint32_t *)fdt_data + 1;
		base = (void *)fdt32_to_cpu(*data);
		data = (uint32_t *)fdt_data + 3;
		size = fdt32_to_cpu(*data);

		set_adsp_image_base(idx, base);
		set_adsp_image_size(idx, size);
		core_id ++;
	}
	return 0;
}

int platform_fdt_adsp(void *fdt)
{
	int nodeoffset, ret = 0;
	uint32_t idx, coreid = 0;
	char compat_name[32];
	fdt32_t dram_base, dram_size, load;
	int n = 0;

	nodeoffset = fdt_node_offset_by_compatible(fdt, -1, ADSP_COMMON_DTS_COMPATIBLE);
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "[ADSP] Failed to find %s in dtb\n",
			ADSP_COMMON_DTS_COMPATIBLE);
		return -1;
	}
	load = cpu_to_fdt32(adsp_load_status);
	ret = fdt_setprop(fdt, nodeoffset, "load", &load, sizeof(load));
	if (ret < 0)
		return ret;

	/* dram base/size: image naming rule: hifi3_x_sram  */
	for (idx = 0; idx < ADSP_NUM_IMAGE; idx++) {
		if (strstr(image_table[idx].name, "sram") != NULL) {
			memset(compat_name, 0, sizeof(compat_name));
			n = snprintf(compat_name, sizeof(compat_name), "%s_%d",
					ADSP_CORE_DTS_COMPATIBLE, coreid);
			if (n < 0 || n > (int)sizeof(compat_name))
				return -2;

			nodeoffset = fdt_node_offset_by_compatible(fdt, -1, compat_name);
			if (nodeoffset < 0) {
				dprintf(CRITICAL, "[ADSP] Failed to find %s in dtb\n", compat_name);
				return -1;
			}

			/* pass parameter to kernel */
			dram_base = cpu_to_fdt32((uint32_t)image_table[idx].base);
			dram_size = cpu_to_fdt32(image_table[idx].size);
			ret = fdt_setprop(fdt, nodeoffset, "sysram",
					&dram_base, sizeof(dram_base));
			if (ret < 0)
				return ret;
			ret = fdt_setprop(fdt, nodeoffset, "sysram_size",
					&dram_size, sizeof(dram_size));
			if (ret < 0)
				return ret;
			dprintf(INFO, "[ADSP] set core_%d sysram base=0x%x, size=0x%x\n",
				coreid, (uint32_t)image_table[idx].base, image_table[idx].size);

			coreid ++;
		}
	}
	return ret;

}
#endif

int verify_load_adsp_image(char *part_name, void *addr)
{
	uint32_t idx, image_size;
	void *image_base;
	void *load_tcm_base;

	load_tcm_base = dram_phys_addr + g_dram_size;
	/* load/verify audio dsp images */
	for (idx = 0; idx < ADSP_NUM_IMAGE; idx ++) {
		if (strstr(image_table[idx].name, "iram") || strstr(image_table[idx].name, "dram")) {
			image_base = load_tcm_base;
		} else {
			image_base = image_table[idx].base;
		}
		image_size = load_adsp_image(part_name, image_table[idx].name, image_base);
		if (image_size > image_table[idx].size || image_size == 0) {
			dprintf(CRITICAL, "[ADSP] load_adsp_image fail %s(addr=0x%x, size=0x%x, expected size=0x%x)\n",
				image_table[idx].name, (uint32_t)image_table[idx].base, image_size, image_table[idx].size);
			return -1;
		} else {
			dprintf(INFO, "[ADSP] load image #%d %s success.(addr=0x%x, size=0x%x)\n",
				idx, image_table[idx].name, (uint32_t)image_base, image_size);
		}
		if (strstr(image_table[idx].name, "iram") ||  strstr(image_table[idx].name, "dram")) {
			memcpy(image_table[idx].base, load_tcm_base, image_size);
			load_tcm_base += image_size;
		}
	}

	return 0;
}

/* adsp power off (DSP suspend) */
void disable_adsp_hw(void)
{
	switch_adsp_power(false, false);

	dprintf(CRITICAL, "DISABLE ADSP\n");
}

/* platform driver */
static void set_adsp_image_base(uint32_t id, void *base)
{
	if (id >= ADSP_NUM_IMAGE) {
		dprintf(CRITICAL, "%s fail. id=%d\n", __func__, id);
		return;
	}
	image_table[id].base = base;
}

static void set_adsp_image_size(uint32_t id, uint32_t size)
{
	if (id >= ADSP_NUM_IMAGE) {
		dprintf(CRITICAL, "%s fail. id=%d\n", __func__, id);
		return;
	}
	image_table[id].size = size;
}

void set_adsp_dram_remap(void *base)
{
	image_table[ADSP_A_IMAGE_DRAM].base = base + ((uint32_t)image_table[ADSP_A_IMAGE_DRAM].base & 0x1FFFFFF);
#ifdef ADSP_B_DRAM_NAME
	image_table[ADSP_B_IMAGE_DRAM].base = base + ((uint32_t)image_table[ADSP_B_IMAGE_DRAM].base & 0x1FFFFFF);
#endif
}

void switch_adsp_power(bool on, bool dormant)
{
	dprintf(INFO, "%s on=%d dormant=%d\n", module_prefix, on, dormant);
	if (on) {
		/* 1. power on ADSP MTCMOS by spm */
		spm_mtcmos_ctrl_adsp_shut_down(STA_POWER_ON);
		/* 2. enable ADSP clock via reg
		 *    adsppll -> adsp sel -> adsp clock cg
		 */
		/* ADSPPLL on */
		DRV_SetReg32(ADSPPLL_CON3, (0x1 << 0));
		udelay(30); //30us delay
		DRV_ClrReg32(ADSPPLL_CON3, (0x1 << 1));
		udelay(1); //1us delay
		DRV_WriteReg32(ADSPPLL_CON1, ADSPPLL_700M_REG);
		DRV_SetReg32(ADSPPLL_CON0, (0x1 << 0));
		/* CLKMUX */
		DRV_SetReg32(CLK_CFG_13_CLR, (0x7 << ADSP_SEL_OFFSET));
		DRV_SetReg32(CLK_CFG_13_SET, (ADSPPLL_CK << ADSP_SEL_OFFSET));
		DRV_SetReg32(CLK_CFG_UPDATE1, (1 << ADSP_CK_UPDATE));
		/* ADSP CLK CG */
		DRV_ClrReg32(AUDIODSP_CK_CG, (CG_ENABLE << CG_OFFSET));
	} else {
		/* 1. disable clock via reg
		 *    adsp clock cg -> adsp sel -> adsppll
		 */
		/* ADSP CLK CG */
		DRV_SetReg32(AUDIODSP_CK_CG, (CG_ENABLE << CG_OFFSET));
		/* ADSP SEL */
		DRV_SetReg32(CLK_CFG_13_CLR, (0x7 << ADSP_SEL_OFFSET));
		DRV_SetReg32(CLK_CFG_13_SET, (CLK_26M_CK << ADSP_SEL_OFFSET));
		DRV_SetReg32(CLK_CFG_UPDATE1, (1 << ADSP_CK_UPDATE));
		/* ADSPPLL off */
		DRV_ClrReg32(ADSPPLL_CON0, (0x1 << 0));
		DRV_SetReg32(ADSPPLL_CON3, (0x1 << 1));
		DRV_ClrReg32(ADSPPLL_CON3, (0x1 << 0));
		/* 2. power off ADSP MTCMOS by spm */
		if (dormant) {
			dprintf(INFO, "%s bypass spm_mtcmos_ctrl_adsp_dormant(STA_POWER_DOWN)\n",
				module_prefix);
			spm_mtcmos_ctrl_adsp_dormant(STA_POWER_DOWN);
		} else {
			spm_mtcmos_ctrl_adsp_shut_down(STA_POWER_DOWN);
		}
	}
}

void adsp_sw_reset(void)
{
	DRV_SetReg32(ADSP_CFGREG_SW_RSTN, ADSP_SW_RSTN);
	udelay(1);
	DRV_ClrReg32(ADSP_CFGREG_SW_RSTN, ADSP_SW_RSTN);
}

static void print_adsp_image_info(void)
{
	uint32_t id;

	for (id = 0; id < ADSP_NUM_IMAGE; id++) {
		dprintf(INFO, "%s id=%d, base=0x%x, size=0x%x\n",
			__func__, id, (uint32_t)image_table[id].base, image_table[id].size);
	}
}

