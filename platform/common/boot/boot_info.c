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

#include <string.h>
#include <stdlib.h>
#include <pal_typedefs.h>
#include <pal_log.h>
#include <pal_assert.h>

#include <load_vfy_boot.h>
#include <boot_info.h>
#include <bootimg.h>
#include <boot_opt.h>
#include <img_workbuf.h>
#include <platform/boot_mode.h>
#include <part_interface.h>
#include <mkimg.h>
#include <odm_mdtbo.h>
#include <ufdt_overlay.h>
#include <platform/errno.h>
#include <mt_boot.h>
#include <target.h>

static struct boot_info g_boot_info;

/* get ramdisk image address when it's loaded */
static uint32_t get_bootimg_ramdisk_load_addr(void)
{
	int32_t kernel_sz = 0;
	uint32_t ramdisk_addr = 0;

	PAL_ASSERT(g_boot_info.hdr_loaded);
	PAL_ASSERT(g_boot_info.img_loaded);

	kernel_sz = get_kernel_sz();
	if (kernel_sz == 0)
		return 0;

	ramdisk_addr = g_boot_info.bootimg_load_addr + g_boot_info.page_sz +
			(uint32_t)kernel_sz;

	if (g_boot_info.kernel_with_mkimg_hdr)
		ramdisk_addr -= MKIMG_HDR_SZ;

	return (uint32_t)ramdisk_addr;
}

int relocate_ramdisk(uint32_t *ramdisk_addr, uint32_t *ramdisk_real_sz)
{
	uint32_t ramdisk_load_addr;
	int ret = 0;

	PAL_ASSERT(g_boot_info.hdr_loaded);
	switch (g_boot_info.bootimg_hdr_version){
	case BOOT_HEADER_VERSION_THREE:
		/* vendor_boot ramdisk offset */
		ramdisk_load_addr = g_boot_info.vendorbootimg_load_addr
			+ ROUNDUP(sizeof(struct vendor_boot_img_hdr_v3), g_boot_info.page_sz);
		PAL_ASSERT(g_boot_info.ramdisk_addr != 0);
		PAL_ASSERT(ramdisk_load_addr != 0);
		memcpy((void *)g_boot_info.ramdisk_addr,
			(void *)ramdisk_load_addr, g_boot_info.vendorboot_ramdisk_sz);
		/* concat boot image ramdisk */
		ramdisk_load_addr = get_bootimg_ramdisk_load_addr();
		memcpy((void *)(g_boot_info.ramdisk_addr + g_boot_info.vendorboot_ramdisk_sz),
			(void *)ramdisk_load_addr, g_boot_info.bootimg_ramdisk_sz);
		*ramdisk_addr = g_boot_info.ramdisk_addr;
		*ramdisk_real_sz = g_boot_info.bootimg_ramdisk_sz + g_boot_info.vendorboot_ramdisk_sz;
		break;
	case BOOT_HEADER_VERSION_TWO:
	case BOOT_HEADER_VERSION_ONE:
	case BOOT_HEADER_VERSION_ZERO:
		ramdisk_load_addr = get_bootimg_ramdisk_load_addr();
		PAL_ASSERT(g_boot_info.ramdisk_addr != 0);
		PAL_ASSERT(ramdisk_load_addr != 0);
#if (!defined(SYSTEM_AS_ROOT) && !defined(MTK_RECOVERY_RAMDISK_SPLIT))
		PAL_ASSERT(g_boot_info.bootimg_ramdisk_sz != 0);
#endif
		*ramdisk_addr = g_boot_info.ramdisk_addr;
		*ramdisk_real_sz = g_boot_info.bootimg_ramdisk_sz;
		memcpy((void *)g_boot_info.ramdisk_addr, (void *)ramdisk_load_addr, g_boot_info.bootimg_ramdisk_sz);
		break;
	default:
		pal_log_err("invalid boot image version\n");
		ret = -2;
	}
	return ret;
}

char *get_bootimg_partition_name(uint32_t bootimg_type)
{
	char *result = NULL;

	switch (bootimg_type) {
	case BOOTIMG_TYPE_RECOVERY:
#ifndef RECOVERY_AS_BOOT
#ifdef MTK_GPT_SCHEME_SUPPORT
		result = "recovery";
#else
		result = "RECOVERY";
#endif
		break;
#endif
	case BOOTIMG_TYPE_BOOT:
#ifdef MTK_GPT_SCHEME_SUPPORT
		result = "boot";
#else
		result = "BOOTIMG";
#endif
		break;
	default:
		break;
	}

	return result;
}
static int decap_dtb_from_kernel(void *bootimg_addr)
{
	unsigned int zimage_size;
	char *dtb_ptr;
	const char *dtb_sz;
	int ret = 0;
	uint32_t kernel_load_addr;
	const uint32_t fdt_magic_num = FDT_MAGIC;
	int i;

	if (!g_boot_info.hdr_loaded)
		return -2;

	if (g_is_64bit_kernel) {
		zimage_size = g_boot_info.kernel_sz;
		pal_log_info("64 bits kernel\n");
		pal_log_err("%s:boot image kernel_sz=0x%08x\n", __func__, zimage_size);
		dtb_ptr = (char *)(get_kernel_addr() + zimage_size);
		dtb_ptr -= 4;
		for (i = 0; i < (DTB_MAX_SIZE - 4); i++, dtb_ptr--) {
			/*
			  * dtb append after image.gz may not 4 byte alignment
			  */
			if (*(dtb_ptr + 3) == EXTRACT_UBYTE(fdt_magic_num, 0) &&
				*(dtb_ptr + 2) == EXTRACT_UBYTE(fdt_magic_num, 1) &&
				*(dtb_ptr + 1) == EXTRACT_UBYTE(fdt_magic_num, 2) &&
				*(dtb_ptr + 0) == EXTRACT_UBYTE(fdt_magic_num, 3)) {
				g_boot_info.dtb_load_addr = (uint32_t)dtb_ptr;
				break;
			}
		}
		if (g_boot_info.dtb_load_addr == 0) {
			pal_log_err("Can't find main device tree!\n");
			ret = -1;
			goto fail;
		}
		dtb_sz = dtb_ptr + 4;
		g_boot_info.dtb_img_size = (uint32_t)(*(dtb_sz) << 24) + (uint32_t)(*(dtb_sz + 1) << 16) +
					(uint32_t)(*(dtb_sz + 2) << 8) + (uint32_t)(*(dtb_sz + 3));
		zimage_size -= g_boot_info.dtb_img_size;
		g_boot_info.kernel_sz = zimage_size;
		pal_log_err("%s:zimage_size=0x%08x, g_boot_info.dtb_img_size=0x%08x\n", __func__,
				zimage_size, g_boot_info.dtb_img_size);
	} else {
		kernel_load_addr = get_kernel_addr();
		zimage_size = *(uint32_t *)((uint32_t)kernel_load_addr + 0x2c) -
			  *(uint32_t *)((uint32_t)kernel_load_addr + 0x28);
		g_boot_info.kernel_sz = zimage_size;
		dtb_ptr = (char *)(get_kernel_addr() + zimage_size);
		g_boot_info.dtb_load_addr = (uint32_t)dtb_ptr;
		/* It is not sure zImage is four byte alignment */
		if (!(*(dtb_ptr + 3) == EXTRACT_UBYTE(fdt_magic_num, 0) &&
			*(dtb_ptr + 2) == EXTRACT_UBYTE(fdt_magic_num, 1) &&
			*(dtb_ptr + 1) == EXTRACT_UBYTE(fdt_magic_num, 2) &&
			*(dtb_ptr + 0) == EXTRACT_UBYTE(fdt_magic_num, 3))) {
				pal_log_err("Can't find main device tree!\n");
				ret = -1;
				goto fail;
			}
			dtb_sz = dtb_ptr + 4;
			g_boot_info.dtb_img_size = (uint32_t)(*(dtb_sz) << 24) + (uint32_t)(*(dtb_sz + 1) << 16) +
						(uint32_t)(*(dtb_sz + 2) << 8) + (uint32_t)(*(dtb_sz + 3));
		pal_log_err("%s:zimage_size=0x%08x, g_boot_info.dtb_img_size=0x%08x\n", __func__,
				zimage_size, g_boot_info.dtb_img_size);
	}
fail:
	return ret;
}
static int decap_dtb_from_bootimg(void *bootimg_addr)
{
	char *dtb_ptr;
	int ret = 0;

	if (!g_boot_info.hdr_loaded)
		return -2;

	dtb_ptr = (char *)(bootimg_addr + g_boot_info.page_sz
				+ ROUNDUP(g_boot_info.kernel_sz, g_boot_info.page_sz)
				+ ROUNDUP(g_boot_info.bootimg_ramdisk_sz, g_boot_info.page_sz)
				+ ROUNDUP(g_boot_info.second_sz, g_boot_info.page_sz)
				+ ROUNDUP(g_boot_info.recovery_dtbo_size, g_boot_info.page_sz));
	if (g_boot_info.dtb_img_size == 0) {
		pal_log_err("can't find v2 dtb\n");
		ret = -1;
		goto fail;
	}
	/* Check dtb format comes with mkdtimg (table_header+table_entry+fdt_body) */
	if (DT_TABLE_MAGIC == fdt_magic(dtb_ptr))
	{
		struct dt_table_header *dt_tbl_hdr = (struct dt_table_header *)dtb_ptr;
		uint32_t dt_entry_count = fdt32_to_cpu(dt_tbl_hdr->dt_entry_count);
		g_boot_info.dtb_load_addr = (uint32_t)dtb_ptr + sizeof(struct dt_table_header)
			+ dt_entry_count * sizeof(struct dt_table_entry);
	}
	else if (FDT_MAGIC == fdt_magic(dtb_ptr))
		g_boot_info.dtb_load_addr = (uint32_t)dtb_ptr;
	else {
		pal_log_err("main dtb is not packed with valid fdt format!\n");
		ret = -2;
		goto fail;
	}
	g_boot_info.dtb_img_size = fdt_totalsize(g_boot_info.dtb_load_addr);
fail:
	return ret;
}
static int decap_dtbo_from_bootimg(void *bootimg_addr)
{
	struct dt_table_header *dt_tbl_hdr_buffer;
	uint32_t dtbo_idx;
	uint32_t dtbo_offset = 0;
	int ret = 0;

	if (!g_boot_info.hdr_loaded)
		return -2;

	/* this boot image is recovery image if recovery_dtbo_offset is not 0 */
	if (g_boot_info.recovery_dtbo_offset) {
		dt_tbl_hdr_buffer = (struct dt_table_header *)(g_boot_info.bootimg_load_addr + (uint32_t) g_boot_info.recovery_dtbo_offset);
		ret = parse_dtbo_tbl(dt_tbl_hdr_buffer, (uint32_t)get_odm_mdtbo_index(),
				&dtbo_idx,
				(uint32_t *)&(g_boot_info.dtbo_img_size), (uint32_t *)&dtbo_offset);
		if (ret == 0) {
			pal_log_err("%s dtbo_offset: %d, dtbo_size: %d\n", __func__, dtbo_offset, g_boot_info.dtbo_img_size);
			g_boot_info.dtbo_load_addr = g_boot_info.bootimg_load_addr + g_boot_info.recovery_dtbo_offset + dtbo_offset;
		} else {
			pal_log_err("parse_dtbo_tbl fail!\n");
			ret = -1;
			return ret;
		}
	}
	return ret;
}

static int decap_dtb_from_vendorbootimg(void *vendorbootimg_addr)
{
	char *dtb_ptr;
	int ret = 0;

	if (!g_boot_info.hdr_loaded)
		return -2;

	dtb_ptr = (char *)(vendorbootimg_addr + ROUNDUP(sizeof(struct vendor_boot_img_hdr_v3), g_boot_info.page_sz)
				+ ROUNDUP(g_boot_info.vendorboot_ramdisk_sz, g_boot_info.page_sz));
	if (g_boot_info.dtb_img_size == 0) {
		pal_log_err("can't find dtb\n");
		ret = -1;
		goto fail;
	}
	/* Check dtb format comes with mkdtimg (table_header+table_entry+fdt_body) */
	if (DT_TABLE_MAGIC == fdt_magic(dtb_ptr))
	{
		struct dt_table_header *dt_tbl_hdr = (struct dt_table_header *)dtb_ptr;
		uint32_t dt_entry_count = fdt32_to_cpu(dt_tbl_hdr->dt_entry_count);
		g_boot_info.dtb_load_addr = (uint32_t)dtb_ptr + sizeof(struct dt_table_header)
			+ dt_entry_count * sizeof(struct dt_table_entry);
	}
	else if (FDT_MAGIC == fdt_magic(dtb_ptr))
		g_boot_info.dtb_load_addr = (uint32_t)dtb_ptr;
	else {
		pal_log_err("main dtb is not packed with valid fdt format!\n");
		ret = -2;
		goto fail;
	}
	g_boot_info.dtb_img_size = fdt_totalsize(g_boot_info.dtb_load_addr);
fail:
	return ret;
}

static int vendorbootimg_decap(void *vendorbootimg_addr)
{
	int ret = 0;
	struct vendor_boot_img_hdr_v3 *vendorboot_v3_ptr = (struct vendor_boot_img_hdr_v3 *)vendorbootimg_addr;

	if (!vendorbootimg_addr) {
		pal_log_err("vendor_boot image is NULL\n");
		ret = -1;
		goto end;
	}
	g_boot_info.vendorbootimg_load_addr = (uint32_t)vendorboot_v3_ptr;
	g_boot_info.dtb_img_size = vendorboot_v3_ptr->dtb_size;
	g_boot_info.tags_addr = vendorboot_v3_ptr->tags_addr;
	/* boot image v3 fixed at 4096 bytes */
	g_boot_info.page_sz = 4096;
	g_boot_info.kernel_addr = vendorboot_v3_ptr->kernel_addr;
	g_boot_info.vendorboot_ramdisk_sz = vendorboot_v3_ptr->vendor_ramdisk_size;
	g_boot_info.ramdisk_addr = vendorboot_v3_ptr->ramdisk_addr;
	/* parse cmdline */
	platform_parse_bootopt(vendorboot_v3_ptr->cmdline);
end:
	return ret;
}

static int bootimg_decap(void *bootimg_addr)
{
	struct bootimg_hdr *pbootimg = bootimg_addr;
	struct boot_img_hdr_v3 *bootimg_v3_ptr = (struct boot_img_hdr_v3 *)bootimg_addr;
	struct vendor_boot_img_hdr_v3 *vendorboot_v3_ptr = (struct vendor_boot_img_hdr_v3 *)get_img_work_buf("vendor_boot");
	int ret = 0;

	if (!pbootimg) {
		pal_log_err("boot image is NULL\n");
		ret = -3;
		goto end;
	}
	if (FALSE == bootimg_hdr_valid((uint8_t *)pbootimg)) {
		pal_log_err("invalid boot image header\n");
		ret = -1;
		goto end;
	}
	g_boot_info.bootimg_hdr_version = pbootimg->header_version;
	g_boot_info.bootimg_load_addr = (uint32_t)pbootimg;
	switch (pbootimg->header_version) {
	case BOOT_HEADER_VERSION_THREE:
		g_boot_info.kernel_sz = bootimg_v3_ptr->kernel_size;
		g_boot_info.bootimg_ramdisk_sz = bootimg_v3_ptr->ramdisk_size;
		g_boot_info.bootimg_os_version = bootimg_v3_ptr->os_version;
		g_boot_info.second_addr = 0;
		g_boot_info.second_sz= 0;
		if (vendorbootimg_decap(vendorboot_v3_ptr) < 0) {
			pal_log_err("invalid vendorboot image header\n");
			ret = -4;
			goto end;
		}
		/* concat boot cmdline to vendor_boot cmdline */
		cmdline_append((const char *)vendorboot_v3_ptr->cmdline);
		cmdline_append((const char *)bootimg_v3_ptr->cmdline);
		break;
	case BOOT_HEADER_VERSION_TWO:
		g_boot_info.dtb_img_size = pbootimg->dtb_size;
	case BOOT_HEADER_VERSION_ONE:
		g_boot_info.recovery_dtbo_offset = pbootimg->recovery_dtbo_offset;
		g_boot_info.recovery_dtbo_size = pbootimg->recovery_dtbo_size;
	case BOOT_HEADER_VERSION_ZERO:
		g_boot_info.tags_addr = pbootimg->tags_addr;
		g_boot_info.page_sz = pbootimg->page_sz;
		g_boot_info.kernel_sz = pbootimg->kernel_sz;
		g_boot_info.kernel_addr = pbootimg->kernel_addr;
		g_boot_info.second_addr = pbootimg->second_addr;
		g_boot_info.second_sz= pbootimg->second_sz;
		g_boot_info.ramdisk_addr = pbootimg->ramdisk_addr;
		g_boot_info.bootimg_ramdisk_sz = pbootimg->ramdisk_sz;
		g_boot_info.bootimg_os_version = pbootimg->os_version;
		/* parse cmdline */
		platform_parse_bootopt(pbootimg->cmdline);
		/* ensure commandline is terminated */
		pbootimg->cmdline[BOOTIMG_ARGS_SZ - 1] = 0;
		/* append cmdline from bootimg hdr */
		cmdline_append((const char *)pbootimg->cmdline);
		break;
	default:
		pal_log_err("invalid boot image version\n");
		ret = -2;
	}
	g_boot_info.hdr_loaded = 1;
end:
	return ret;
}
int load_bootinfo_bootimg(void *bootimg_addr)
{
	int ret = 0;
	struct bootimg_hdr boot_hdr;
	void *bootimg_ptr;

	bootimg_ptr = get_img_work_buf("boot");

	if (bootimg_decap(bootimg_ptr) != 0)
		panic("boot image decapsulate fail!\n");

	boot_hdr.kernel_addr = g_boot_info.kernel_addr;
	boot_hdr.kernel_sz = g_boot_info.kernel_sz;
	boot_hdr.ramdisk_addr = g_boot_info.ramdisk_addr;
#ifdef LK_RAMDISK_MAX_SIZE
	boot_hdr.ramdisk_sz = LK_RAMDISK_MAX_SIZE;
#else
	boot_hdr.ramdisk_sz = g_boot_info.bootimg_ramdisk_sz + g_boot_info.vendorboot_ramdisk_sz;
#endif
	boot_hdr.tags_addr = g_boot_info.tags_addr;

	if (!boot_hdr.kernel_addr)
#ifdef LK_DYNAMIC_KERNEL_64_MAX_SIZE
		boot_hdr.kernel_addr = KERNEL_MBLOCK_LIMIT - LK_DYNAMIC_KERNEL_64_MAX_SIZE;
#else
		boot_hdr.kernel_addr = KERNEL_MBLOCK_LIMIT - LK_KERNEL_64_MAX_SIZE;
#endif
	if (!boot_hdr.ramdisk_addr)
		boot_hdr.ramdisk_addr = KERNEL_MBLOCK_LIMIT - ROUNDUP(boot_hdr.ramdisk_sz, PAGE_SIZE);
	if (!boot_hdr.tags_addr)
		boot_hdr.tags_addr = KERNEL_MBLOCK_LIMIT - DTB_MAX_SIZE;

	mboot_allocate_bootimg_from_mblock(&boot_hdr);

	g_boot_info.kernel_addr = boot_hdr.kernel_addr;
	g_boot_info.ramdisk_addr = boot_hdr.ramdisk_addr;
	g_boot_info.tags_addr = boot_hdr.tags_addr;

	setup_kernel_fdt((void *)g_boot_info.tags_addr);
	switch(g_boot_info.bootimg_hdr_version) {
	case BOOT_HEADER_VERSION_THREE:
		ret = decap_dtb_from_vendorbootimg((void *)g_boot_info.vendorbootimg_load_addr);
		break;
	case BOOT_HEADER_VERSION_TWO:
		ret = decap_dtb_from_bootimg((void *)g_boot_info.bootimg_load_addr);
		ret += decap_dtbo_from_bootimg((void *)g_boot_info.bootimg_load_addr);
		break;
	case BOOT_HEADER_VERSION_ONE:
		ret = decap_dtb_from_kernel((void *)g_boot_info.bootimg_load_addr);
		ret += decap_dtbo_from_bootimg((void *)g_boot_info.bootimg_load_addr);
		break;
	case BOOT_HEADER_VERSION_ZERO:
		ret = decap_dtb_from_kernel((void *)g_boot_info.bootimg_load_addr);
		break;
	}
	return ret;
}

uint32_t bootimg_hdr_valid(uint8_t *buf)
{
	if (strncmp((char *)buf, BOOTIMG_MAGIC, BOOTIMG_MAGIC_SZ) == 0)
		return 1;
	else
		return 0;
}

uint32_t mkimg_hdr_valid(uint8_t *buf)
{
	union mkimg_hdr *l_mkimg_hdr = (union mkimg_hdr *)buf;

	if (l_mkimg_hdr->info.magic == MKIMG_MAGIC)
		return 1;
	else
		return 0;
}

uint32_t load_bootimg_hdr(uint32_t bootimg_type)
{
	uint32_t ret = 0;
	char *part_name = NULL;
	unsigned long len;
	union mkimg_hdr mkimg_hdr_inst;
	struct bootimg_hdr boot_hdr;

	/* boot image header could be loaded only once */
	if (g_boot_info.hdr_loaded)
		return 0;

	part_name = get_bootimg_partition_name(bootimg_type);
	if (part_name == NULL) {
		pal_log_err("unknown boot image type: 0x%x\n", bootimg_type);
		return -1;
	}

	len = partition_read(part_name,
				(off_t)0,
				(uint8_t *)&boot_hdr,
				sizeof(boot_hdr));
	if (len != sizeof(boot_hdr)) {
		pal_log_err("boot image load fail: 0x%lu\n", len);
		return -1;
	}

	len = partition_read(part_name,
				(off_t)BOOTIMG_HDR_SZ,
				(uint8_t *)&mkimg_hdr_inst,
				sizeof(mkimg_hdr_inst.info));
	if (len != sizeof(mkimg_hdr_inst.info)) {
		pal_log_err("mkimg header load fail: 0x%lu\n", len);
		return -1;
	}

	if (FALSE == bootimg_hdr_valid((uint8_t *)&boot_hdr)) {
		pal_log_err("invalid boot image header\n");
		return -1;
	}

	if (mkimg_hdr_valid((uint8_t *)&mkimg_hdr_inst))
		g_boot_info.kernel_with_mkimg_hdr = 1;

	if (0 == ret) {
		g_boot_info.hdr_loaded = 1;
		g_boot_info.type = bootimg_type;
	}
	platform_parse_bootopt(boot_hdr.cmdline);
	return ret;
}

uint32_t get_recovery_dtbo_sz(void)
{
	PAL_ASSERT(g_boot_info.hdr_loaded);

	return (uint32_t)g_boot_info.recovery_dtbo_size;
}

uint64_t get_recovery_dtbo_offset(void)
{
	PAL_ASSERT(g_boot_info.hdr_loaded);

	return (uint64_t)g_boot_info.recovery_dtbo_offset;
}

uint32_t get_page_sz(void)
{
	PAL_ASSERT(g_boot_info.hdr_loaded);

	return (uint32_t)g_boot_info.page_sz;
}

/* get final kernel image location (after relocation) */
uint32_t get_kernel_target_addr(void)
{
	PAL_ASSERT(g_boot_info.hdr_loaded);

	return (uint32_t)g_boot_info.kernel_addr;
}

/* get kernel image address when it's loaded */
uint32_t get_kernel_addr(void)
{
	uint32_t kernel_addr = 0;

	PAL_ASSERT(g_boot_info.hdr_loaded);

	kernel_addr = g_boot_info.bootimg_load_addr + g_boot_info.page_sz;

	return (uint32_t)kernel_addr;
}

int32_t get_kernel_sz(void)
{
	uint32_t page_sz = 0;
	uint32_t kernel_sz = 0;
	int32_t out_kernel_sz = 0;

	PAL_ASSERT(g_boot_info.hdr_loaded);

	kernel_sz = g_boot_info.kernel_sz;
	page_sz = g_boot_info.page_sz;

	out_kernel_sz = (int32_t)(((kernel_sz + page_sz - 1) / page_sz) *
				page_sz);
	return out_kernel_sz;
}

uint32_t get_kernel_real_sz(void)
{
	PAL_ASSERT(g_boot_info.hdr_loaded);
	return g_boot_info.kernel_sz;
}

/* get final ramdisk image location (after relocation) */
uint32_t get_ramdisk_target_addr(void)
{
	PAL_ASSERT(g_boot_info.hdr_loaded);

	return (uint32_t)g_boot_info.ramdisk_addr;
}

uint32_t get_tags_addr(void)
{
	PAL_ASSERT(g_boot_info.hdr_loaded);
	return (uint32_t)g_boot_info.tags_addr;
}

uint32_t get_os_version(void)
{
	PAL_ASSERT(g_boot_info.hdr_loaded);
	return (uint32_t)g_boot_info.bootimg_os_version;
}

uint32_t get_header_version(void)
{
	PAL_ASSERT(g_boot_info.hdr_loaded);
	return (uint32_t)g_boot_info.bootimg_hdr_version;
}

uint32_t get_main_dtb_size(void)
{
	if (!g_boot_info.hdr_loaded)
		pal_log_err("%s: g_boot_info.hdr_loaded is 0\n", __func__);
	return (uint32_t)g_boot_info.dtb_img_size;
}

uint32_t get_main_dtb_load_addr(void)
{
	if (!g_boot_info.hdr_loaded)
		pal_log_err("%s: g_boot_info.hdr_loaded is 0\n", __func__);
	return (uint32_t)g_boot_info.dtb_load_addr;
}

uint32_t get_dtbo_load_addr(void)
{
	return g_boot_info.dtbo_load_addr;
}

uint32_t get_dtbo_img_size(void)
{
	return g_boot_info.dtbo_img_size;
}

void set_bootimg_loaded(uint32_t addr)
{
	PAL_ASSERT(g_boot_info.hdr_loaded);

	g_boot_info.img_loaded = 1;
}

void set_recovery_dtbo_loaded(void)
{
	g_boot_info.recovery_dtbo_loaded = 1;
	return;
}

uint32_t get_recovery_dtbo_loaded(void)
{
	return (uint32_t)g_boot_info.recovery_dtbo_loaded;
}

void set_bootimg_verified(void)
{
	g_boot_info.verified = 1;
	return;
}

void set_bootimg_verify_skipped(void)
{
	g_boot_info.vfy_skipped = 1;
	return;
}

void set_dtbo_load_addr(uint32_t dtbo_load_addr)
{
	assert(dtbo_load_addr != 0);
	g_boot_info.dtbo_load_addr = dtbo_load_addr;
}

void set_dtbo_img_size(uint32_t dtbo_img_size)
{
	assert(dtbo_img_size != 0);
	g_boot_info.dtbo_img_size = dtbo_img_size;
}
void set_recovery_img_loaded(void)
{
	g_boot_info.recovery_img_loaded = 1;
}

uint32_t get_recovery_img_loaded(void)
{
	return (uint32_t)g_boot_info.recovery_img_loaded;
}

