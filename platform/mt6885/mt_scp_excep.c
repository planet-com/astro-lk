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
#include <platform/mt_scp.h>
#include <platform/errno.h>
#include <mt_scp.h>
#include <mt_scp_excep.h>
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

struct reg_save_st {
	uint32_t addr;
	uint32_t size;
};

struct reg_save_st reg_save_list[] = {
	/* size must 16 byte alignment */
	{0x10721000, 0x120},
	{0x10724000, 0x170},
	{0x10730000, 0x120},
	{0x10732000, 0x260},
	{0x10733000, 0x120},
	{0x10740000, 0x120},
	{0x10742000, 0x260},
	{0x10743000, 0x120},
	{0x10750000, 0x330},
	{0x10751000, 0x10},
	{0x10751400, 0x70},
	{0x10752000, 0x340},
	{0x107A5000, 0x110},
	{0x10001B14, 0x10},
};

void scp_do_regdump(uint32_t *out, uint32_t *out_end)
{
	int i = 0;
	void *from;
	uint32_t *buf = out;
	int size_limit = sizeof(reg_save_list) / sizeof(struct reg_save_st);

	for (i = 0; i < size_limit; i++) {
		if (((uint32_t)buf + reg_save_list[i].size
			+ sizeof(struct reg_save_st)) > (uint32_t)out_end) {
			dprintf(CRITICAL, "[SCP] %s overflow\n", __func__);
			break;
		}
		*buf = reg_save_list[i].addr;
		buf++;
		*buf = reg_save_list[i].size;
		buf++;
		from = (void *)reg_save_list[i].addr;
		memcpy(buf, from, reg_save_list[i].size);
		buf += (reg_save_list[i].size / sizeof(uint32_t));
	}
}

void scp_do_l1cdump(uint32_t *out, uint32_t *out_end)
{
	uint32_t *buf = out;
	uint32_t tmp;

	tmp = readl(R_SEC_CTRL);
	/* enable cache debug */
	writel(tmp | B_CORE0_CACHE_DBG_EN | B_CORE1_CACHE_DBG_EN, R_SEC_CTRL);
	if ((uint32_t)buf + MDUMP_L1C_SIZE > (uint32_t)out_end) {
		dprintf(CRITICAL, "[SCP] %s overflow\n", __func__);
		return;
	}
	memcpy(buf, (void *)R_CORE0_CACHE_RAM, MDUMP_L1C_SIZE);
	/* disable cache debug */
	writel(tmp, R_SEC_CTRL);
}

void scp_do_tbufdump(uint32_t *out, uint32_t *out_end)
{
	uint32_t *buf = out;
	uint32_t tmp, index, offset, wbuf_ptr;
	int i;

	wbuf_ptr = readl(R_CORE0_TBUF_WPTR);
	tmp = readl(R_CORE0_DBG_CTRL) & (~M_CORE_TBUF_DBG_SEL);
	for (i = 0; i < 16; i++) {
		index = (wbuf_ptr + i) / 2;
		offset = ((wbuf_ptr + i) % 2) * 0x8;
		writel(tmp | (index << S_CORE_TBUF_DBG_SEL), R_CORE0_DBG_CTRL);
		*(buf) = readl(R_CORE0_TBUF_DATA31_0 + offset);
		*(buf + 1) = readl(R_CORE0_TBUF_DATA63_32 + offset);
		buf += 2;
	}

	wbuf_ptr = readl(R_CORE1_TBUF_WPTR);
	tmp = readl(R_CORE1_DBG_CTRL) & (~M_CORE_TBUF_DBG_SEL);
	for (i = 0; i < 16; i++) {
		index = (wbuf_ptr + i) / 2;
		offset = ((wbuf_ptr + i) % 2) * 0x8;
		writel(tmp | (index << S_CORE_TBUF_DBG_SEL), R_CORE1_DBG_CTRL);
		*(buf) = readl(R_CORE1_TBUF_DATA31_0 + offset );
		*(buf + 1) = readl(R_CORE1_TBUF_DATA63_32 + offset);
		buf += 2;
	}

	for (i = 0; i < 16; i++) {
		dprintf(INFO, "[SCP] C0:%02d:0x%08x::0x%08x\n",
			i, *(out + i * 2), *(out + i * 2 + 1));
	}
	for (i = 0; i < 16; i++) {
		dprintf(INFO, "[SCP] C1:%02d:0x%08x::0x%08x\n",
			i, *(out + i * 2 + 16), *(out + i * 2 + 17));
	}
}

#define BUF_SIZE 65536
int scp_zip_compress(unsigned char* input, unsigned char* output, unsigned int input_size)
{

	int ret, flush;
	int have;
	z_stream strm;

	int i = 0;
	int j = 0;
	unsigned int avail_input_size = input_size;
	unsigned char *ibuf;
	unsigned char *obuf;

	ibuf = malloc(BUF_SIZE);
	if (ibuf == NULL)
		return Z_BUF_ERROR;

	obuf = malloc(BUF_SIZE);
	if (obuf == NULL) {
		free(ibuf);
		return Z_BUF_ERROR;
	}

	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	/* allocate deflate state */
	memset(&strm, 0, sizeof(z_stream));
	ret = deflateInit2(&strm, Z_BEST_COMPRESSION, Z_DEFLATED, 31, 8, Z_DEFAULT_STRATEGY);
	if (ret != Z_OK) {
		free(ibuf);
		free(obuf);
		return ret;
	}

	/* compress until end of file */
	do {
		strm.avail_in = BUF_SIZE;
		strm.next_in = ibuf;
		strm.avail_out = BUF_SIZE;
		strm.next_out = obuf;
		flush = Z_NO_FLUSH;
		if (avail_input_size < BUF_SIZE) {
			strm.avail_in = avail_input_size;
			flush = Z_FINISH;
		}

		memcpy(ibuf, (void *)&input[i], strm.avail_in);
		i += strm.avail_in;
		avail_input_size -= strm.avail_in;
		strm.next_in = ibuf;

		/* run deflate() on input until output buffer not full, finish
		   compression if all of source has been read in */
		do {
			strm.avail_out = BUF_SIZE;
			strm.next_out = obuf;
			ret = deflate(&strm, flush);    /* no bad return value */
			assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
			have = BUF_SIZE - strm.avail_out;
			memcpy((void *)&output[j], obuf, have);
			j+=have;
			mtk_wdt_restart();
		} while (strm.avail_out == 0);
		assert(strm.avail_in == 0);     /* all input will be used */
		/* done when last data in file processed */
	} while (flush != Z_FINISH);
	assert(ret == Z_STREAM_END);        /* stream will be complete */

	free(ibuf);
	free(obuf);
	/* clean up and return */
	(void)deflateEnd(&strm);
	return j;
}

/*
 * this function need SCP to keeping awaken
 * scp_crash_dump: dump scp tcm info.
 * @param MemoryDump:   scp dump struct
 * @param scp_core_id:  core id
 * @return:             scp dump size
 */

int scp_crash_dump(void *crash_buffer)
{
	unsigned int scp_dump_size;
	int datasize;
	struct MemoryDump *pMemoryDump;
	void *tmp_ptr;
	uint32_t dram_start = 0;
	uint32_t dram_size = 0;
	uint32_t tmp;
	struct scp_region_info_st* scp_region_info = (void *)(SCP_SRAM_BASE + 0x4);

	tmp = scp_region_info->ap_loader_start;
	tmp_ptr = pMemoryDump = (void *)tmp;

	/* region_info will be null when recovery boot fail, skip scp coredump */
	if (tmp == 0) {
		dprintf(CRITICAL, "[scp] scp_region_info = 0, skip coredump\n");
		return 0;
	}
	if (arch_mmu_map((uint64_t)tmp, (uint32_t)tmp,
		MMU_MEMORY_TYPE_NORMAL_WRITE_BACK | MMU_MEMORY_AP_P_RW_U_NA, SCP_DRAM_SIZE) != NO_ERROR) {
			dprintf(CRITICAL, "scp_crash_dump: tmp_dram error\n");
		return 0;
	}
	memset(tmp_ptr, 0, SCP_DRAM_OFFSET);
	memcpy((void *)&(pMemoryDump->l2tcm),
		(void *)(SCP_SRAM_BASE),(SCP_SRAM_SIZE));
	scp_do_l1cdump((void *)&(pMemoryDump->l1c),
		(void *)&(pMemoryDump->regdump));
	/* dump sys registers */
	scp_do_regdump((void *)&(pMemoryDump->regdump),
		(void *)&(pMemoryDump->tbuf));

	scp_do_tbufdump((void *)&(pMemoryDump->tbuf),
		(void *)&(pMemoryDump->dram));
	scp_dump_size = MDUMP_L2TCM_SIZE + MDUMP_L1C_SIZE
		+ MDUMP_REGDUMP_SIZE + MDUMP_TBUF_SIZE;
	/* L1C support? */
	if ((int)(scp_region_info->ap_dram_size) <= 0) {
		dprintf(INFO, "[scp] ap_dram_size <=0\n");
	} else {
		dram_start = (uint32_t)tmp_ptr + SCP_DRAM_OFFSET;
		dram_size = scp_region_info->ap_dram_size;

		if (dram_size > MDUMP_DRAM_SIZE) {
			dprintf(INFO, "ap_dram_size %x > %x, reset size\n", dram_size, MDUMP_DRAM_SIZE);
			dram_size = MDUMP_DRAM_SIZE;
		}
		/* beware, dest overwrite source memcpy, scp_dump_size must < 2MB */
		memcpy((void *)&(pMemoryDump->dram),
			(void *)dram_start, dram_size);
		scp_dump_size += ROUNDUP(dram_size, 4);
	}
	datasize = scp_zip_compress((void *)tmp_ptr, (void *)crash_buffer, scp_dump_size);
	return datasize;
}

