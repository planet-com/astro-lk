/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2016. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */
#include <stdint.h>
#include <pal_typedefs.h>
#include <pal_log.h>
#include <part_interface.h>
#include <string.h>
#include <platform/mt_typedefs.h>
#include <block_generic_interface.h>
#include "part_dev.h"
#include "avb_util.h"
#include "bootctrl.h"
#include "debug.h"
#include "mmc_core.h"
#include "mmc_common_inter.h"
#include "ufs_aio_hcd.h"

#define BOOTCTR_PARTITION "misc"

static const char *suffix[2] = {BOOTCTRL_SUFFIX_A, BOOTCTRL_SUFFIX_B};
static struct bootloader_control boot_control;
static int bootctl_exists = 0;

int check_suffix_with_slot(const char *suffix)
{
	int slot = -1;

	if (suffix == NULL) {
		pal_log_err("[LK] input suffix is NULL\n");
		return -1;
	}

	if (!strcmp(suffix, BOOTCTRL_SUFFIX_A))
		slot = 0;
	else if (!strcmp(suffix, BOOTCTRL_SUFFIX_B))
		slot = 1;
	else
		pal_log_err("[LK] unknow slot suffix\n");

	return slot;
}

static void initDefaultBootControl(struct bootloader_control *bctrl) {
	int slot = 0;
	struct slot_metadata *slotp;

	bctrl->magic = BOOTCTRL_MAGIC;
	bctrl->version = BOOTCTRL_VERSION;
	bctrl->nb_slot = BOOTCTRL_NUM_SLOTS;

	/* Set highest priority and reset retry count */
	for (slot = 0; slot < BOOTCTRL_NUM_SLOTS; slot++) {
		slotp = &bctrl->slot_info[slot];
		slotp->successful_boot = 0;
		slotp->priority = BOOT_CONTROL_MAX_PRI;
		slotp->tries_remaining = BOOT_CONTROL_MAX_RETRY;
	}
	bctrl->crc32_le = avb_crc32((const uint8_t*)bctrl, sizeof(struct bootloader_control) - sizeof(uint32_t));
}

static int read_write_partition_info(struct bootloader_control *bctrl, int mode)
{
	int ret = -1;

	if (bctrl == NULL) {
		pal_log_err("[LK] read_write_partition_info failed, bctrl is NULL\n");
		return ret;
	}

	if (mode == READ_PARTITION) {
		if (boot_control.magic != BOOTCTRL_MAGIC) {
			if (partition_read(BOOTCTR_PARTITION, (off_t) OFFSETOF_SLOT_SUFFIX, (uint8_t *) &boot_control, (size_t) sizeof(struct bootloader_control)) <= 0) {
				pal_log_err("[LK] read boot_control fail\n");
				return ret;
			}
			bootctl_exists = 0;
			if (boot_control.magic != BOOTCTRL_MAGIC) {
				initDefaultBootControl(&boot_control);
				bootctl_exists = 0;
			} else {
				bootctl_exists = 1;
			}
		}
		memcpy(bctrl, &boot_control, sizeof(struct bootloader_control));
	} else if (mode == WRITE_PARTITION) {
		if (!bootctl_exists) {
			pal_log_info("[LK] skip bootctrl write because it's not inited\n");
			return 0;
		}
		bctrl->crc32_le = avb_crc32((const uint8_t *)bctrl, sizeof(struct bootloader_control) - sizeof(uint32_t));
		if (partition_write(BOOTCTR_PARTITION, (uint64_t) OFFSETOF_SLOT_SUFFIX, (uint8_t *) bctrl, (uint32_t) sizeof(struct bootloader_control)) <= 0) {
			pal_log_err("[LK] read_write_partition_info partition_write failed, unknown mode\n");
			return ret;
		}
	} else {
		pal_log_err("[LK] unknown mode, ret: 0x%x\n", ret);
		return ret;
	}

	return 0;
}

const char *get_suffix(void)
{
	int slot = 0, ret = -1;

	struct bootloader_control metadata;

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] read_partition_info failed, ret: 0x%x\n", ret);
		return NULL;
	}

	if(metadata.magic != BOOTCTRL_MAGIC) {
		pal_log_err("[LK] boot_ctrl magic number is not match %x , BOOTCTRL_MAGIC = %x\n",
				metadata.magic, BOOTCTRL_MAGIC);
		return NULL;
	} else {
		pal_log_info("[LK] boot_ctrl magic number is match, compare priority %d, %d\n", metadata.slot_info[0].priority, metadata.slot_info[1].priority);

		if (metadata.slot_info[0].priority >= metadata.slot_info[1].priority)
			slot = 0;
		else if (metadata.slot_info[0].priority < metadata.slot_info[1].priority)
			slot = 1;
	}

	return suffix[slot];
}

int get_slot_info(int slot, uint8_t *priority, uint8_t *tries_remaining, uint8_t *successful_boot) {
	int ret;
	struct bootloader_control metadata;

	if (slot < 0 || slot >= BOOTCTRL_NUM_SLOTS) {
		pal_log_err("[LK] set_active_slot failed, slot: 0x%x\n", slot);
		return 1;
	}

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] read_partition_info failed, ret: 0x%x\n", ret);
		return 1;
	}

	if(metadata.magic != BOOTCTRL_MAGIC) {
		pal_log_err("[LK] boot_ctrl magic number is not match %x , BOOTCTRL_MAGIC = %x\n",
				metadata.magic, BOOTCTRL_MAGIC);
		return 1;
	} else {
		*priority = metadata.slot_info[slot].priority;
		*tries_remaining = metadata.slot_info[slot].tries_remaining;
		*successful_boot = metadata.slot_info[slot].successful_boot;
	}
	return 0;
}

static int set_boot_region(int slot)
{
	int ret = -1;
	u32 boot_part = 0;

	part_dev_t *dev;

	dev = mt_part_get_device();

	if(slot == 0) {
#if defined(MTK_EMMC_SUPPORT)
		if (dev->blkdev->type == BOOTDEV_SDMMC)
			boot_part = EMMC_PART_BOOT1;
#endif
#if defined(MTK_UFS_SUPPORT)
		if (dev->blkdev->type == BOOTDEV_UFS)
			boot_part = ATTR_B_BOOT_LUN_EN_BOOT_LU_A;
#endif
	} else if(slot == 1) {
#if defined(MTK_EMMC_SUPPORT)
		if (dev->blkdev->type == BOOTDEV_SDMMC)
			boot_part = EMMC_PART_BOOT2;
#endif
#if defined(MTK_UFS_SUPPORT)
		if (dev->blkdev->type == BOOTDEV_UFS)
			boot_part = ATTR_B_BOOT_LUN_EN_BOOT_LU_B;
#endif
	}

#if defined(MTK_EMMC_SUPPORT)
		if (dev->blkdev->type == BOOTDEV_SDMMC) {
			ret = mmc_set_boot_part(boot_part);
			return ret;
		}
#endif

#if defined(MTK_UFS_SUPPORT)
		 extern struct ufs_hba g_ufs_hba;
		 struct ufs_hba *hba = &g_ufs_hba;
		 ret = ufs_aio_set_boot_lu(hba, boot_part);
#endif

	return ret;
}

int get_bootctrl_data(struct bootloader_control *metadata)
{
	int ret;

	ret = read_write_partition_info(metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] %s failed, ret: 0x%x\n", __func__, ret);
		return -1;
	}
	return 0;
}

int set_active_slot(const char *suffix)
{
	int slot = 0, slot1 = 0;
	int ret = -1;
	struct slot_metadata *slotp;

	struct bootloader_control metadata;

	slot = check_suffix_with_slot(suffix);
	if (slot < 0 || slot >= BOOTCTRL_NUM_SLOTS) {
		pal_log_err("[LK] set_active_slot failed, slot: 0x%x\n", slot);
		return -1;
	}

	if (suffix == NULL) {
		pal_log_err("[LK] input suffix is NULL\n");
		return -1;
	}

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] partition_read failed, ret: 0x%x\n", ret);
		return -1;
	}

	metadata.magic = BOOTCTRL_MAGIC;

	/* Set highest priority and reset retry count */
	slotp = &metadata.slot_info[slot];
	slotp->successful_boot = 0;
	slotp->priority = BOOT_CONTROL_MAX_PRI;
	slotp->tries_remaining = BOOT_CONTROL_MAX_RETRY;

	/* Ensure other slot doesn't have as high a priority. */
	slot1 = (slot == 0) ? 1 : 0;
	slotp = &metadata.slot_info[slot1];
	if (slotp->priority >= BOOT_CONTROL_MAX_PRI)
		slotp->priority = BOOT_CONTROL_MAX_PRI - 1;

		/* Switch boot part in boot region */
		ret = set_boot_region(slot);
		if (ret < 0) {
			pal_log_err("[LK] set boot part to slot %d fail, ret: 0x%x\n", slot, ret);
			return -1;
		}

	ret = read_write_partition_info(&metadata, WRITE_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] partition_write failed, ret: 0x%x\n", ret);
		return -1;
	}

	return 0;
}

uint8_t get_retry_count(const char *suffix)
{
	int slot = 0;
	int ret = -1;
	struct bootloader_control metadata;

	slot = check_suffix_with_slot(suffix);
	if (slot < 0 || slot >= BOOTCTRL_NUM_SLOTS) {
		pal_log_err("[LK] get_retry_count failed, slot: 0x%x\n", slot);
		return 0;
	}

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] partition_read failed, ret: 0x%x\n", ret);
		return 0;
	}

	return metadata.slot_info[slot].tries_remaining;
}

/* Return value:
	0: phone does not boot to home screen yet
	1: phone already boots to home screen
   -1: read misc partition error
*/
int get_bootup_status(const char *suffix)
{
	int slot = 0, ret = -1;
	struct bootloader_control metadata;

	slot = check_suffix_with_slot(suffix);
	if (slot < 0 || slot >= BOOTCTRL_NUM_SLOTS) {
		pal_log_err("set_not_boot_mode failed, slot: 0x%x\n", slot);
		return -1;
	}

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("partition_read failed, ret: 0x%x\n", ret);
		return -1;
	}

	return metadata.slot_info[slot].successful_boot;
}

/* Return value:
	0: slot is unbootable , tries_remaining equal to 0
	1: slot is bootable , tries_remaining larger than 0
   -1: read misc partition error
*/
int get_bootable_status(const char *suffix)
{
	int slot = 0, ret = -1;
	struct bootloader_control metadata;

	slot = check_suffix_with_slot(suffix);
	if (slot < 0 || slot >= BOOTCTRL_NUM_SLOTS) {
		pal_log_err("get_bootable_status failed, slot: 0x%x\n", slot);
		return -1;
	}

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("partition_read failed, ret: 0x%x\n", ret);
		return -1;
	}

	if (metadata.slot_info[slot].priority > 0)
		return 1;

	return 0;
}

int bootctrl_retry_decrease(int slot)
{
	int ret;
	struct bootloader_control metadata;
	struct slot_metadata *slotp;

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] partition_read failed, ret: 0x%x\n", ret);
		return -1;
	}

	slotp = &metadata.slot_info[slot];
	if (slotp->tries_remaining > 0 && !slotp->successful_boot) {
		slotp->tries_remaining--;
		ret = read_write_partition_info(&metadata, WRITE_PARTITION);
		if (ret < 0) {
			pal_log_err("[LK] partition_write failed, ret: 0x%x\n", ret);
			return -1;
		}
	}
	return 0;
}
int increase_tries_remaining(void)
{
	int slot = 0, ret = -1;
	struct slot_metadata *slotp;
	struct bootloader_control metadata;
	const char *suffix = NULL;

	suffix = get_suffix();
	slot = check_suffix_with_slot(suffix);
	if (slot < 0 || slot >= BOOTCTRL_NUM_SLOTS) {
		pal_log_err("[LK] check_suffix_with_slot failed, slot: 0x%x\n", slot);
		return -1;
	}

	ret = read_write_partition_info(&metadata, READ_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] partition_read failed, ret: 0x%x\n", ret);
		return -1;
	}

	slotp = &metadata.slot_info[slot];
	if (slotp->tries_remaining < BOOT_CONTROL_MAX_RETRY &&
		slotp->tries_remaining > 0 && !slotp->successful_boot)
		slotp->tries_remaining++;

	ret = read_write_partition_info(&metadata, WRITE_PARTITION);
	if (ret < 0) {
		pal_log_err("[LK] partition_write failed, ret: 0x%x\n", ret);
		return -1;
	}

	return 0;
}
