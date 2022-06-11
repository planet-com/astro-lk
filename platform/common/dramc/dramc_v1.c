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
#include <libfdt.h>
#include <debug.h>

extern BOOT_ARGUMENT *g_boot_arg;

int set_fdt_dramc(void *fdt)
{
	int ret = 0;
	int offset;
	unsigned int i;
	unsigned int dram_type;
	unsigned int support_ch_cnt;
	unsigned int ch_cnt;
	unsigned int rk_cnt;
	unsigned int mr_cnt;
	unsigned int freq_cnt;
	unsigned int rk_size[DRAMC_MAX_RK];
	unsigned int mr_info[DRAMC_MR_CNT * 2];
	unsigned int freq_step[DRAMC_FREQ_CNT];

	if (!fdt)
		return -1;

	offset = fdt_path_offset(fdt, "/dramc");
	if (offset < 0) {
		offset = fdt_path_offset(fdt, "/soc/dramc");
		if(offset < 0){
			dprintf(INFO, "[%s] get_path_offset fail\n", __func__);
			return offset;
		}
	}

	dram_type = cpu_to_fdt32((unsigned int)(g_boot_arg->emi_info.dram_type));
	support_ch_cnt = cpu_to_fdt32((unsigned int)(g_boot_arg->emi_info.support_ch_cnt));
	ch_cnt = cpu_to_fdt32((unsigned int)(g_boot_arg->emi_info.ch_cnt));
	rk_cnt = cpu_to_fdt32((unsigned int)(g_boot_arg->emi_info.rk_cnt));
	mr_cnt = cpu_to_fdt32((unsigned int)(g_boot_arg->emi_info.mr_cnt));
	freq_cnt = cpu_to_fdt32((unsigned int)(g_boot_arg->emi_info.freq_cnt));

	/* unit of rank size: 1Gb (128MB) */
	for (i = 0; i < DRAMC_MAX_RK; i++) {
		if (i < rk_cnt) {
			rk_size[i] = (g_boot_arg->emi_info.rk_size[i] >> 27) & 0xFFFFFFFF;
			rk_size[i] = cpu_to_fdt32(rk_size[i]);
		} else {
			rk_size[i] = cpu_to_fdt32(0);
		}
	}

	for (i = 0; i < DRAMC_MR_CNT; i++) {
		if (i < mr_cnt) {
			mr_info[i * 2] = cpu_to_fdt32(
				(unsigned int)(g_boot_arg->emi_info.mr_info[i].mr_index));
			mr_info[i * 2 + 1] = cpu_to_fdt32(
				(unsigned int)(g_boot_arg->emi_info.mr_info[i].mr_value));
		} else {
			mr_info[i * 2] = cpu_to_fdt32(0);
			mr_info[i * 2 + 1] = cpu_to_fdt32(0);
		}
	}

	for (i = 0; i < DRAMC_FREQ_CNT; i++) {
		if (i < freq_cnt) {
			freq_step[i] = (unsigned int)(g_boot_arg->emi_info.freq_step[i]);
			freq_step[i] = cpu_to_fdt32(freq_step[i]);
		}else {
			freq_step[i] = cpu_to_fdt32(0);
		}
	}

	/* pass parameter to kernel */
	ret = fdt_setprop(fdt, offset, "dram_type", &dram_type, sizeof(dram_type));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "support_ch_cnt", &support_ch_cnt, sizeof(support_ch_cnt));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "ch_cnt", &ch_cnt, sizeof(ch_cnt));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "rk_cnt", &rk_cnt, sizeof(rk_cnt));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "mr_cnt", &mr_cnt, sizeof(mr_cnt));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "freq_cnt", &freq_cnt, sizeof(freq_cnt));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "rk_size", rk_size, sizeof(rk_size));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "mr", mr_info, sizeof(mr_info));
	if (ret < 0)
		return ret;

	ret = fdt_setprop(fdt, offset, "freq_step", freq_step, sizeof(freq_step));

	return ret;
}

