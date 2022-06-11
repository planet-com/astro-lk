/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2017. All rights reserved.
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
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/

#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <platform/plat_dbg_info.h>
#include <libfdt.h>
#include <debug.h>
#include <assert.h>

extern BOOT_ARGUMENT *g_boot_arg;
static int set_fdt_emimpu_info(void *fdt);
static int set_fdt_emiisu_info(void *fdt);

int set_fdt_emi_info(void *fdt)
{
	int ret = 0;
	int offset;
	unsigned int i;
	unsigned int ch_cnt;
	unsigned int rk_cnt;
	unsigned long long rank_size;
	unsigned int rk_size[DRAMC_MAX_RK][2];

	assert(g_boot_arg->emi_info.magic_tail == 0x20190831);

	if (!fdt)
		return -1;

	offset = fdt_path_offset(fdt, "/soc/emicen");
	if (offset < 0) {
		offset = fdt_path_offset(fdt, "/emicen");
		if (offset < 0)
			return offset;
	}

	ch_cnt = cpu_to_fdt32(g_boot_arg->emi_info.ch_cnt);
	rk_cnt = cpu_to_fdt32(g_boot_arg->emi_info.rk_cnt);

	for (i = 0; i < DRAMC_MAX_RK; i++) {
		if (i < g_boot_arg->emi_info.rk_cnt) {
			rank_size = g_boot_arg->emi_info.rk_size[i];
			rk_size[i][0] = cpu_to_fdt32(
				(unsigned int)(rank_size >> 32));
			rk_size[i][1] = cpu_to_fdt32(
				(unsigned int)(rank_size & 0xFFFFFFFF));
		} else {
			rk_size[i][0] = cpu_to_fdt32(0);
			rk_size[i][1] = cpu_to_fdt32(0);
		}
	}

	/* pass parameter to kernel */
	ret = fdt_setprop(fdt, offset, "ch_cnt", &ch_cnt, sizeof(ch_cnt));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "rk_cnt", &rk_cnt, sizeof(rk_cnt));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "rk_size", rk_size, sizeof(rk_size));
	if (ret < 0)
		return ret;

	ret = set_fdt_emimpu_info(fdt);
	if (ret < 0)
		return ret;

	ret = set_fdt_emiisu_info(fdt);

	return ret;
}

static int set_fdt_emimpu_info(void *fdt)
{
	int ret = 0;
	int offset;
	const unsigned long long dram_base = DRAM_PHY_ADDR;
	unsigned int dram_start[2];
	unsigned int dram_end[2];
	unsigned long long dram_size = 0;
	unsigned int i;

	offset = fdt_path_offset(fdt, "/soc/emimpu");
	if (offset < 0) {
		offset = fdt_path_offset(fdt, "/emimpu");
		if (offset < 0)
			return offset;
	}

	dram_start[0] = cpu_to_fdt32((unsigned int)(dram_base >> 32));
	dram_start[1] = cpu_to_fdt32((unsigned int)(dram_base & 0xFFFFFFFF));

	for (i = 0; i < g_boot_arg->emi_info.rk_cnt; i++)
		dram_size += g_boot_arg->emi_info.rk_size[i];
	dram_size += dram_base - 1;

	dram_end[0] = cpu_to_fdt32((unsigned int)(dram_size >> 32));
	dram_end[1] = cpu_to_fdt32((unsigned int)(dram_size & 0xFFFFFFFF));

	ret = fdt_setprop(fdt, offset, "dram_start",
		dram_start, sizeof(dram_start));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "dram_end",
		dram_end, sizeof(dram_end));

	return ret;
}

static int set_fdt_emiisu_info(void *fdt)
{
	int ret = 0;
	int offset;
	struct isu_info_t *isu_info = &(g_boot_arg->emi_info.isu_info);
	unsigned int buf_size;
	unsigned int buf_addr[2];
	unsigned int ver_addr[2];
	unsigned int con_addr[2];

	offset = fdt_path_offset(fdt, "/soc/emiisu");
	if (offset < 0) {
		offset = fdt_path_offset(fdt, "/emiisu");
		if (offset < 0)
			return offset;
	}

	buf_size = cpu_to_fdt32(isu_info->buf_size);

	buf_addr[0] = cpu_to_fdt32(
		(unsigned int)(isu_info->buf_addr >> 32));
	buf_addr[1] = cpu_to_fdt32(
		(unsigned int)(isu_info->buf_addr & 0xFFFFFFFF));

	ver_addr[0] = cpu_to_fdt32(
		(unsigned int)(isu_info->ver_addr >> 32));
	ver_addr[1] = cpu_to_fdt32(
		(unsigned int)(isu_info->ver_addr & 0xFFFFFFFF));

	con_addr[0] = cpu_to_fdt32(
		(unsigned int)(isu_info->con_addr >> 32));
	con_addr[1] = cpu_to_fdt32(
		(unsigned int)(isu_info->con_addr & 0xFFFFFFFF));

	ret |= fdt_setprop(fdt, offset, "buf_size",
		&buf_size, sizeof(buf_size));
	ret |= fdt_setprop(fdt, offset, "buf_addr",
		buf_addr, sizeof(buf_addr));
	ret |= fdt_setprop(fdt, offset, "ver_addr",
		ver_addr, sizeof(ver_addr));
	ret |= fdt_setprop(fdt, offset, "con_addr",
		con_addr, sizeof(con_addr));

	return ret;
}

