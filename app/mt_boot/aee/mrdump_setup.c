/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2016. All rights reserved.
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

#include <block_generic_interface.h>
#include <malloc.h>
#include <printf.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <video.h>
#include <dev/mrdump.h>
#include <platform/mtk_key.h>
#include <platform/mtk_wdt.h>
#include <platform/mt_gpt.h>
#include <target/cust_key.h>
#include <platform/boot_mode.h>
#include <platform/ram_console.h>
#include <arch/ops.h>
#include <libfdt.h>
#include <platform.h>
#include "aee.h"
#include "mrdump_private.h"

/* +++ ddr reserve mode +++ */
extern BOOT_ARGUMENT *g_boot_arg;

static void mrdump_ddr_rsv_fdt(void *fdt, int offset, const void *enable)
{
	if (0 == fdt_setprop_string(fdt, offset, "mrdump,ddr_rsv", enable)) {
		dprintf(CRITICAL, "%s: set ddr_rsv = %s\n",
			__func__, (char*)enable);
	} else {
		dprintf(CRITICAL, "%s: failed to set ddr_rsv %s\n",
			__func__, (char*)enable);
	}
}

/* +++ mrdump control block params +++ */
static void mrdump_cb_fdt(void *fdt, int offset)
{
	int ret = fdt_setprop_u32(fdt, offset, "mrdump,cblock", MRDUMP_CB_ADDR);
	if (ret) {
		goto error;
	}
	ret = fdt_appendprop_u32(fdt, offset, "mrdump,cblock", MRDUMP_CB_SIZE);
	if (ret) {
		goto error;
	}
	return;
error:
	dprintf(CRITICAL, "%s: failed to set mrdump,cblock entry\n", __func__);
}

#if defined(MTK_MRDUMP_SUPPORT)
static void mrdump_lk_version_fdt(void *fdt, int offset, const void *lk_version)
{
	if (0 == fdt_setprop_string(fdt, offset, "mrdump,lk", lk_version)) {
		dprintf(CRITICAL, "%s: set lk_version = %s\n",
			__func__, (char*)lk_version);
	} else {
		dprintf(CRITICAL, "%s: failed to set lk_version %s\n",
			__func__, (char*)lk_version);
	}
}

#endif

/* +++ mrdump initialization +++ */
void mrdump_init(void *fdt)
{
	int res, chosen_offset;

	/* +++ mrdump_key +++ */
	mrdump_key_fdt_init(fdt);

	chosen_offset = fdt_path_offset(fdt, "/chosen");
	if (chosen_offset < 0) {
		dprintf(CRITICAL, "%s: /chosen not found\n", __func__);
		return;
	}

	/* +++ ddr rsv +++ */
	if (g_boot_arg->ddr_reserve_ready != AEE_MRDUMP_DDR_RSV_READY) {
		mrdump_ddr_rsv_fdt(fdt, chosen_offset, "no");
		dprintf(CRITICAL, "MT-RAMDUMP: DDR reserve mode not ready (0x%x)\n",
			g_boot_arg->ddr_reserve_ready);
		res = 0;
	}
	else {
		mrdump_ddr_rsv_fdt(fdt, chosen_offset, "yes");
		res = 1;
	}

	/* +++ mrdump control block params +++ */
	mrdump_cb_fdt(fdt, chosen_offset);

#if defined(MTK_MRDUMP_SUPPORT)
	if (res && (mrdump_check_enable() <= MRDUMP_ALWAYS_ENABLE)) {
		mrdump_lk_version_fdt(fdt, chosen_offset, MRDUMP_GO_DUMP);

	}

	/* default setting */
	int output_device = mrdump_get_default_output_device();
	if (output_device == MRDUMP_DEV_UNKNOWN)
		dprintf(CRITICAL, "MT-RAMDUMP: unknown output device.\n");
#endif

#ifdef MRDUMP_PARTITION_ENABLE
	mrdump_partition_resize();
#endif
}
