/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2020. All rights reserved.
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
#include <debug.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <platform/mt_typedefs.h>
#include <mblock.h>
#include <memory_layout.h>
#include <pal_typedefs.h>
#include <pal_log.h>
#include <platform/boot_mode.h>
#include <target.h>

#ifndef LK_DL_MAX_SIZE
#define LK_DL_MAX_SIZE SCRATCH_SIZE
#endif

#define VENDOR_BOOT_MBLOCK_LIMIT	0xc0000000

struct img_buf {
	const char *name[3];
	void *work_buf;
	uint32_t work_buf_len;
	void *(*alloc_work_buf)(uint32_t buf_len, const char *name);
	void (*free_work_buf)(void *buf, uint32_t len);
};

static void *bootimg_work_buf_alloc(uint32_t buf_len, const char *name);
static void bootimg_work_buf_free(void *buf, uint32_t len);
static void *vendorboot_work_buf_alloc(uint32_t buf_len, const char *name);
static void vendorboot_work_buf_free(void *buf, uint32_t len);

#undef MAX_IMG_NAME_LEN
#define MAX_IMG_NAME_LEN 12
static struct img_buf bootimgs[] = {
{
 .name={"boot", "recovery", NULL},
 .work_buf=0,
 .work_buf_len=0,
 .alloc_work_buf=bootimg_work_buf_alloc,
 .free_work_buf=bootimg_work_buf_free,
},
{
 .name={"vendor_boot", NULL, NULL},
 .work_buf=0,
 .work_buf_len=0,
 .alloc_work_buf=vendorboot_work_buf_alloc,
 .free_work_buf=vendorboot_work_buf_free,
}
};

static struct img_buf *find_img_buf(const char* name)
{
	uint32_t i;
	struct img_buf *found = NULL;
	const char **nameptr = NULL;
	for(i = 0 ; i < countof(bootimgs) ; i++) {
	    nameptr = bootimgs[i].name;
        while(*nameptr) {
            if (strncmp(*nameptr, name, MAX_IMG_NAME_LEN) == 0) {
                found = &bootimgs[i];
                goto end;
            }
            nameptr++;
        }
	}
end:
	return found;
}

static void *bootimg_work_buf_alloc(uint32_t buf_len, const char *name)
{
	/* reuse scratch buffer */
	if (buf_len > LK_DL_MAX_SIZE)
		return NULL;
	else
		return target_get_scratch_address();
}

static void bootimg_work_buf_free(void *buf, uint32_t len)
{
	/* do nothing */
}

static void *vendorboot_work_buf_alloc(uint32_t buf_len, const char *name)
{
	u64 mblock_vendorboot_work_buf;
	void *work_buf;
	uintptr_t mblock_vendorboot_work_buf_intptr;

	mblock_vendorboot_work_buf = mblock_reserve_ext(&g_boot_arg->mblock_info,
		(uint64_t)buf_len, PAGE_SIZE, (uint64_t)VENDOR_BOOT_MBLOCK_LIMIT,
		0, "vendorboot_work_buf");
	if (!mblock_vendorboot_work_buf) {
		dprintf(CRITICAL, "%s fail to mblock reserve\n", __func__);
		work_buf = NULL;
	} else {
		mblock_vendorboot_work_buf_intptr = (uintptr_t)mblock_vendorboot_work_buf;
		work_buf = (void *)mblock_vendorboot_work_buf_intptr;
	}

	return work_buf;
}

static void vendorboot_work_buf_free(void *buf, uint32_t len)
{
	int ret;

	ret = mblock_create(&g_boot_arg->mblock_info,
					&g_boot_arg->orig_dram_info,
					(uint64_t)((uintptr_t)buf & 0xffffffff), (uint64_t)(len & 0xffffffff));
	if (ret)
		dprintf(CRITICAL, "%s fail to mblock create\n", __func__);
}

void *bootimg_alloc_work_buf(const char *name, uint32_t img_len)
{
	struct img_buf *entry;
	void *buf;

	entry = find_img_buf(name);
	if (!entry) {
		pal_log_err("cannot find %s img_buf\n", name);
		return NULL;
	}
	if (entry->work_buf) {
		pal_log_err("allocate again?:%s\n", name);
		entry->free_work_buf(entry->work_buf, entry->work_buf_len);
	}
	buf = entry->alloc_work_buf(img_len, name);
	if (buf == NULL)
		goto error;
	entry->work_buf = buf;
	entry->work_buf_len = img_len;

	return buf;
error:
	entry->work_buf = NULL;
	entry->work_buf_len = 0;
	pal_log_err("%s allocate fail, request buf_len:0x%x\n", __func__, img_len);
	return NULL;
}

void bootimg_free_work_buf(const char *name)
{
	struct img_buf *entry;

	entry = find_img_buf(name);
	if (!entry) {
		pal_log_err("cannot find %s img_buf\n", name);
		return;
	}
	if (entry->work_buf)
		entry->free_work_buf(entry->work_buf, entry->work_buf_len);
	else
		pal_log_err("%s img_buf has been freed?\n", name);
	entry->work_buf = NULL;
	entry->work_buf_len = 0;
}

void *get_img_work_buf(const char *name)
{
	struct img_buf *entry;

	entry = find_img_buf(name);
	if (entry)
		return entry->work_buf;
	else
		return NULL;
}

void free_bootimgs(void)
{
	uint32_t i;
	struct img_buf *buf_ptr;

	for (i = 0 ; i < ARRAY_SIZE(bootimgs) ; i++) {
		buf_ptr = &bootimgs[i];
		if (buf_ptr->work_buf)
			bootimg_free_work_buf(buf_ptr->name[0]);
	}
}
