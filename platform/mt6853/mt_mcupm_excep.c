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

#include <stdint.h>
#include <string.h>
#include <debug.h>
#include <platform/boot_mode.h>
#include <platform/partition.h>
#include <platform/verified_boot.h>
#include <platform/sec_policy.h>
#include <assert.h>
#include <platform/mt_mcupm.h>
#include <platform/errno.h>
#include <mt_mcupm.h>
#include <mt_mcupm_excep.h>
#include <reg.h>
#include <malloc.h>
#include <lib/crc.h>
#include <lib/zutil.h>
#include <lib/zlib.h>
#include <platform/mtk_wdt.h>

#ifdef MTK_3LEVEL_PAGETABLE
#include <arch/arm/mmu.h>
#include <stdlib.h>
#include <err.h>
#endif

struct mcupm_reg_save_st {
	uint32_t addr;
	uint32_t size;
};

struct mcupm_reg_save_st mcupm_reg_save_list[] = {
	{0x0C560000, 0x1000},
	{0x0C562000, 0x100},
};

void mcupm_do_regdump(uint32_t *out, uint32_t *out_end)
{
	int i = 0;
	void *from;
	uint32_t *buf = out;
	int size_limit = sizeof(mcupm_reg_save_list) / sizeof(struct mcupm_reg_save_st);
	uint32_t *update = NULL;
	int totalsize = 0;

	dprintf(CRITICAL, "mcupm mcupm_do_regdump\n");

	for (i = 0; i < size_limit; i++) {
		if (((uint32_t)buf + mcupm_reg_save_list[i].size
			+ sizeof(struct mcupm_reg_save_st)) > (uint32_t)out_end) {
			dprintf(CRITICAL, "[MCUPM] %s overflow\n", __func__);
			break;
		}
		*buf = mcupm_reg_save_list[i].addr;
		buf++;
		*buf = mcupm_reg_save_list[i].size;
		buf++;
		totalsize += 2;
		from = (void *)mcupm_reg_save_list[i].addr;
		memcpy(buf, from, mcupm_reg_save_list[i].size);
		buf += (mcupm_reg_save_list[i].size / sizeof(uint32_t));
		totalsize += (mcupm_reg_save_list[i].size / sizeof(uint32_t));
	}

	buf = buf - totalsize + 2;
	update = (unsigned int *)(DRV_Reg32(MCUPM_LAST_PCLRSP) + MCUPM_SRAM_BASE);
	buf = buf + (CPUEB_CFGREG_DBG_MON_PC/sizeof(uint32_t));

	DRV_WriteReg32(buf, DRV_Reg32(update));
	DRV_WriteReg32(buf+1, DRV_Reg32(update + 1));
	DRV_WriteReg32(buf+2, DRV_Reg32(update + 2));
}

#if 0
void mcupm_do_l1cdump(uint32_t *out, uint32_t *out_end)
{
	uint32_t *buf = out;
	uint32_t tmp;

	tmp = readl(R_SEC_CTRL);
	/* enable cache debug */
	writel(tmp | B_CORE0_CACHE_DBG_EN | B_CORE1_CACHE_DBG_EN, R_SEC_CTRL);
	if ((uint32_t)buf + MCUPM_L1C_SIZE > (uint32_t)out_end) {
		dprintf(CRITICAL, "[MCUPM] %s overflow\n", __func__);
		return;
	}
	memcpy(buf, (void *)R_CORE0_CACHE_RAM, MCUPM_L1C_SIZE);
	/* disable cache debug */
	writel(tmp, R_SEC_CTRL);
}
#endif

void mcupm_do_tbufdump(uint32_t *out, uint32_t *out_end)
{
	uint32_t *buf = out;
	unsigned int tbuf[8*4];
#if 0
	uint32_t tmp;
	int i;

	tmp = readl(MCUPM_TBUF_WPTR);
	for (i = 0; i < 7; i++) {
		//writel(tmp | (i << S_CORE_TBUF_DBG_SEL), R_CORE0_DBG_CTRL);
		writel(tmp, MCUPM_TBUF_ADDR);
		*(buf + 0) = readl(MCUPM_TBUF_DATA31_0);
		*(buf + 1) = readl(MCUPM_TBUF_DATA63_32);
		*(buf + 2) = readl(MCUPM_TBUF_DATA95_64);
		*(buf + 3) = readl(MCUPM_TBUF_DATA127_96);
		buf += 4;
        if (tmp == 0)
            tmp = 7;
        else tmp--;
	}
	for (i = 0; i < 32; i++) {
		dprintf(CRITICAL, "[MCUPM] tbuf %02d:0x%08x::0x%08x\n",
			i, *(out + i), *(out + i + 1));
	}
#endif
	memcpy(buf, (void *)(DRV_Reg32(MCUPM_LAST_TBUF) + MCUPM_SRAM_BASE), sizeof(tbuf));
}

/*
 * this function need MCUPM to keeping awaken
 * mcupm_crash_dump: dump mcupm tcm info.
 * @param MemoryDump:   mcupm dump struct
 * @param mcupm_core_id:  core id
 * @return:             mcupm dump size
 */

int mcupm_crash_dump(void *crash_buffer)
{
	unsigned int mcupm_dump_size;
	int ret = 0;
	struct MemoryDumpMCUPM *pMemoryDump;
	uint32_t tmp;

	tmp = DRV_Reg32(GPR_BASE_ADDR(0));

	/* region_info will be null when recovery boot fail, skip coredump */
	if (tmp == 0) {
		dprintf(CRITICAL, "[mcupm] mcupm_region_info = 0, skip coredump\n");
		return 0;
	}

	//set mmu
	ret = arch_mmu_map((uint64_t)tmp, (uint32_t)tmp,
		MMU_MEMORY_TYPE_NORMAL_WRITE_BACK |
		MMU_MEMORY_AP_P_RW_U_NA, BLOCK_SIZE);

	if (ret != NO_ERROR) {
		dprintf(CRITICAL, "kedump: mmu map to 0x%llx fail(%d), MCUPM dump might fail.\n", (uint64_t)tmp, ret);
		return 0;
	}

	pMemoryDump = (void *)crash_buffer;

	memcpy((void *)&(pMemoryDump->l2tcm), DRV_Reg32(MCUPM_DM_ADDR),DRV_Reg32(MCUPM_DM_SZ));

	/* dump sys registers */
	mcupm_do_regdump((void *)&(pMemoryDump->regdump),
		(void *)&(pMemoryDump->tbuf));

	mcupm_do_tbufdump((void *)&(pMemoryDump->tbuf), (void *)&(pMemoryDump->dram)); 
	mcupm_dump_size = MCUPM_L2TCM_SIZE + MCUPM_REGDUMP_SIZE + MCUPM_TBUF_SIZE;

	dprintf(CRITICAL, "[mcupm] mcupm_crash_dump success.\n");

	return mcupm_dump_size;
}
