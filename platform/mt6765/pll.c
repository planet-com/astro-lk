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
 * MediaTek Inc. (C) 2015. All rights reserved.
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

#include <platform/boot_mode.h>
#include <platform/mt_typedefs.h>
#include <platform/sec_devinfo.h>
#include <libfdt.h>
#include <debug.h>

#define APMIXED_BASE      (0x1000C000)

#define APLL1_CON0		(APMIXED_BASE + 0x28C)
#define APLL1_CON3		(APMIXED_BASE + 0x298)

#define PLL_PWR_CON0_PWR_ON_BIT 0
#define PLL_PWR_CON0_ISO_EN_BIT 1
#define PLL_CON0_EN_BIT 0

int set_fdt_pll(void *fdt)
{
	unsigned int armpll_ll_enable = 0;
	int project_id;
	int offset;
	int ret = 0;

	if (!fdt)
		return -1;

	offset = fdt_path_offset(fdt, "/apmixed");
	if (offset < 0)
		return offset;

	project_id = get_devinfo_with_index(30);
	dprintf(CRITICAL, "project_id = 0x%x\n", project_id);
	if (project_id != 0x8 && project_id != 0xF)
		armpll_ll_enable = 1;
	dprintf(CRITICAL, "armpll_ll_enable = 0x%x(0x%x)\n", armpll_ll_enable, offset);
	/* pass parameter to kernel */
	ret = fdt_setprop(fdt, offset, "armpll_ll_enable", &armpll_ll_enable, sizeof(armpll_ll_enable));

	return ret;
}

void mt_pll_clk_bootargs(void)
{
	//cmdline_append("clk_ignore_unused");
}

void mt_pll_turn_off(void)
{
#if 0
	cmdline_append("clk_ignore_unused");


	unsigned int temp;

    /***********************
      * xPLL Frequency Disable
      ************************/
	temp = DRV_Reg32(TVDPLL_CON0);
	DRV_WriteReg32(TVDPLL_CON0, temp & ~(1<<PLL_CON0_EN_BIT));

	temp = DRV_Reg32(APLL1_CON0);
	DRV_WriteReg32(APLL1_CON0, temp & ~(1<<PLL_CON0_EN_BIT));

	temp = DRV_Reg32(APLL2_CON0);
	DRV_WriteReg32(APLL2_CON0, temp & ~(1<<PLL_CON0_EN_BIT));

    /******************
    * xPLL PWR ISO Enable
    *******************/
	temp = DRV_Reg32(TVDPLL_PWR_CON0);
	DRV_WriteReg32(TVDPLL_PWR_CON0, temp | (1<<PLL_PWR_CON0_ISO_EN_BIT));

	temp = DRV_Reg32(APLL1_PWR_CON0);
	DRV_WriteReg32(APLL1_PWR_CON0, temp | (1<<PLL_PWR_CON0_ISO_EN_BIT));

	temp = DRV_Reg32(APLL2_PWR_CON0);
	DRV_WriteReg32(APLL2_PWR_CON0, temp | (1<<PLL_PWR_CON0_ISO_EN_BIT));

    /*************
    * xPLL PWR OFF
    **************/
	temp = DRV_Reg32(TVDPLL_PWR_CON0);
	DRV_WriteReg32(TVDPLL_PWR_CON0, temp & ~(1<<PLL_PWR_CON0_PWR_ON_BIT));

	temp = DRV_Reg32(APLL1_PWR_CON0);
	DRV_WriteReg32(APLL1_PWR_CON0, temp & ~(1<<PLL_PWR_CON0_PWR_ON_BIT));

	temp = DRV_Reg32(APLL2_PWR_CON0);
	DRV_WriteReg32(APLL2_PWR_CON0, temp & ~(1<<PLL_PWR_CON0_PWR_ON_BIT));
#endif
}

