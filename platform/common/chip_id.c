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
#include <atags.h>
#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <debug.h>

/*chip id information*/
struct tag_chipid {
	u32 hw_code;
	u32 hw_subcode;
	u32 hw_ver;
	u32 sw_ver;
};

unsigned int __attribute__((weak)) mt_get_chip_sw_ver(void)
{
	return DRV_Reg32(APSW_VER);
}

unsigned int __attribute__((weak)) mt_get_chip_hw_ver(void)
{
	return DRV_Reg32(APHW_VER);
}

unsigned int __attribute__((weak)) mt_get_chip_hw_code(void)
{
	return DRV_Reg32(APHW_CODE);
}

unsigned int __attribute__((weak)) mt_get_chip_hw_subcode(void)
{
	return DRV_Reg32(APHW_SUBCODE);
}

unsigned int __attribute__((weak)) *target_atag_chipid(unsigned int *ptr)
{
	if (ptr == NULL)
		return NULL;
	*ptr++ = tag_size(tag_chipid);
	*ptr++ = mt_get_chip_hw_code();
	*ptr++ = mt_get_chip_hw_subcode();
	*ptr++ = mt_get_chip_hw_ver();
	*ptr++ = mt_get_chip_sw_ver();
	dprintf(CRITICAL, " hw_code = 0x%x\n", mt_get_chip_hw_code());
	dprintf(CRITICAL, " hw_subcode = 0x%x\n", mt_get_chip_hw_subcode());
	dprintf(CRITICAL, " hw_ver = 0x%x\n", mt_get_chip_hw_ver());
	dprintf(CRITICAL, " sw_ver = 0x%x\n", mt_get_chip_sw_ver());
	return ptr;
}
