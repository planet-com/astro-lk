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

#include <debug.h>
#include <string.h>
#include <platform/clkbuf.h>
#include <platform/mt_pmic.h>
#include <platform/mt_pmic_wrap_init.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_typedefs.h>
#include <platform/upmu_hw.h>

#ifdef DEVICE_TREE_SUPPORT
#include <libfdt.h>
#include <lk_builtin_dtb.h>
#endif

#define CLKBUF_NODE	"mediatek,pmic_clock_buffer"
#define XO_MASK		0x7
#define XO_WCN_SHIFT	3
#define XO_EXT_SHIFT	12

#define VOTE_MASK	0x7ff
#define VOTE_SHIFT	0
#define CONN_VOTE_MASK	0xf
#define CONN_VOTE_SHIFT	4
#define PMIC_MASK	0xffff
#define PMIC_SHIFT	0

#define PMIFSPI_OTHER_INF_EN (PMIF_SPI_BASE + 0x0028)
	#define OTHER_INF_DCXO0_EN_MSK 0x1
	#define OTHER_INF_DCXO0_EN_SHFT 0

#define CLKBUF_DEBUG	1

enum clk_buf_id {
	XO_SOC = 0,
	XO_WCN,
	XO_NFC,
	XO_CEL,
	XO_EXT = 6,
};

static void clk_buf_mask_voter(unsigned int addr, unsigned int vote_mask,
			unsigned int vote_shift)
{
	unsigned int val = 0;

	pmic_read_interface(addr,
			&val,
			VOTE_MASK,
			VOTE_SHIFT);
	pmic_config_interface(addr,
			(val & (~(vote_mask << vote_shift))),
			VOTE_MASK,
			VOTE_SHIFT);
#if CLKBUF_DEBUG
	pmic_read_interface(addr,
			&val,
			VOTE_MASK,
			VOTE_SHIFT);
	dprintf(CRITICAL, "[CLKBUF] vote addr: 0x%x config to 0x%x\n",
			addr, val);
#endif
}

static void clk_buf_tcxo_config(void)
{
	unsigned int val = 0;

	pmic_config_interface(PMIC_XO_EXTBUF2_MODE_ADDR,
				0,
				PMIC_XO_EXTBUF2_MODE_MASK,
				PMIC_XO_EXTBUF2_MODE_SHIFT);
	pmic_config_interface(PMIC_XO_EXTBUF2_EN_M_ADDR,
				0,
				PMIC_XO_EXTBUF2_EN_M_MASK,
				PMIC_XO_EXTBUF2_EN_M_SHIFT);
	pmic_config_interface(PMIC_XO_EXTBUF7_MODE_ADDR,
				0,
				PMIC_XO_EXTBUF7_MODE_MASK,
				PMIC_XO_EXTBUF7_MODE_SHIFT);
	pmic_config_interface(PMIC_XO_EXTBUF7_EN_M_ADDR,
				0,
				PMIC_XO_EXTBUF7_EN_M_MASK,
				PMIC_XO_EXTBUF7_EN_M_SHIFT);

	clk_buf_mask_voter(PMIC_XO_WCN_VOTE_ADDR,
				CONN_VOTE_MASK,
				CONN_VOTE_SHIFT);
	clk_buf_mask_voter(PMIC_XO_CEL_VOTE_ADDR,
				CONN_VOTE_MASK,
				CONN_VOTE_SHIFT);
	clk_buf_mask_voter(PMIC_XO_EXT_VOTE_ADDR,
				CONN_VOTE_MASK,
				CONN_VOTE_SHIFT);

	DRV_WriteReg32(PMIFSPI_OTHER_INF_EN, (DRV_Reg32(PMIFSPI_OTHER_INF_EN)
		& ~(OTHER_INF_DCXO0_EN_MSK << OTHER_INF_DCXO0_EN_SHFT)));

#if CLKBUF_DEBUG
	pmic_read_interface(MT6359_DCXO_CW00,
				&val,
				PMIC_MASK,
				PMIC_SHIFT);
	dprintf(CRITICAL, "[CLKBUF] CW00: 0x%x\n", val);

	pmic_read_interface(MT6359_DCXO_CW09,
				&val,
				PMIC_MASK,
				PMIC_SHIFT);
	dprintf(CRITICAL, "[CLKBUF] CW09: 0x%x\n", val);

	val = DRV_Reg32(PMIFSPI_OTHER_INF_EN);
	dprintf(CRITICAL, "[CLKBUF] OTHER_INF_EN: 0x%x\n", val);
#endif
}

int clk_buf_init(void)
{
	char *tcxo_support = NULL;
#ifdef DEVICE_TREE_SUPPORT
	int nodeoffset;
	int len;
	void *fdt = get_lk_overlayed_dtb();

	if (fdt == NULL)
		panic("lk driver fdt is NULL! something wrong.\n");

	nodeoffset = fdt_node_offset_by_compatible(fdt, -1, CLKBUF_NODE);
	if (nodeoffset < 0) {
		dprintf(CRITICAL, "[CLKBUF] dts node not found\n");
		return 0;
	}

	tcxo_support = (char *)fdt_getprop(fdt,
					nodeoffset,
					"tcxo_support",
					&len);
	if (!tcxo_support) {
		dprintf(CRITICAL, "[CLKBUF] not support\n");
	}
#endif
	if (tcxo_support && !strcmp(tcxo_support, "true")) {
		clk_buf_tcxo_config();
		dprintf(CRITICAL, "[CLKBUF] TCXO Supported\n");
	}
	dprintf(CRITICAL, "[CLKBUF] Init\n");
	return 0;
}
