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

#include <debug.h>
#include <lk_builtin_dtb.h>
#include <libfdt.h>
#include <reg.h>

#include <emi-addr2dram.h>

#define MTK_EMI_DRAM_OFFSET 0x40000000
#define MTK_EMI_DISPATCH_RULE 0x0
#define MTK_EMI_HASH_RULE 0x7

const char *emicen_compatible[] = {
	"/soc/emicen",
	"/emicen",
	NULL
};

static unsigned int emi_a2d_con_offset[] = {
	0x00, 0x28, 0x38, 0x3c, 0x50,
};

static unsigned long offset;
static unsigned long max_mb;
static unsigned long disph = MTK_EMI_DISPATCH_RULE;
static unsigned int magics[8];
static unsigned int cas;
static unsigned long hash = MTK_EMI_HASH_RULE;
static unsigned int chab_rk0_sz, chab_rk1_sz;
static unsigned int chcd_rk0_sz, chcd_rk1_sz;
static unsigned int channels;
static unsigned int dualrk_ch0, dualrk_ch1;
static unsigned int chn_hash_lsb, chnpos;
static unsigned int chab_row_mask[2], chcd_row_mask[2];
static unsigned int chab_col_mask[2], chcd_col_mask[2];
static unsigned int dw32;
static unsigned int chn_4bank_mode;

static inline bool test_bit(long nr, const volatile unsigned long *addr)
{
	return ((*addr >> nr) & 1)? 1 : 0;
}
static inline void clear_bit(unsigned int nr, volatile unsigned long *p)
{
	*p &= ~(1UL << nr);
}

static inline unsigned long __ffs(unsigned long word)
{
	return (word & (~word + 1));
}

static void prepare_a2d(void)
{
	static int prepared = 0;
	void *fdt;
	int off, len, array_len, i;
	unsigned int *data;
	unsigned int emi_con_base;
	const unsigned int mask = 0x0000000f;
	unsigned int emi_cona, emi_conf, emi_conh, emi_conh_2nd, emi_conk;
	unsigned int tmp;

	if (prepared)
		return;

	array_len = sizeof(emicen_compatible) / sizeof(emicen_compatible[0]);
	fdt = get_lk_overlayed_dtb();
	for (i = 0; i < array_len; i++) {
		off = fdt_path_offset(fdt, emicen_compatible[i]);
		if (off >= 0)
			break;
	}
	if (i >= array_len) {
		dprintf(CRITICAL, "emi addr2dram couldn't find the emicen node)\n");
		return;
	}

	data = (unsigned int *)fdt_getprop(fdt, off, "reg", &len);
	if (!data || !len) {
		dprintf(CRITICAL, "emi addr2dram couldn't find property reg\n");
		return;
	}
	emi_con_base = fdt32_to_cpu(data[1]);

	array_len = sizeof(emi_a2d_con_offset) / sizeof(emi_a2d_con_offset[0]);
	data = (unsigned int *)fdt_getprop(fdt, off, "a2d_conf_offset", &len);
	if (data && len) {
		for (i = 0; i < array_len; i++)
			emi_a2d_con_offset[i] = fdt32_to_cpu(data[i]);
	}

	emi_cona = readl(emi_con_base + emi_a2d_con_offset[0]);
	emi_conf = readl(emi_con_base + emi_a2d_con_offset[1]);
	emi_conh = readl(emi_con_base + emi_a2d_con_offset[2]);
	emi_conh_2nd = readl(emi_con_base + emi_a2d_con_offset[3]);
	emi_conk = readl(emi_con_base + emi_a2d_con_offset[4]);

	data = (unsigned int *)fdt_getprop(fdt, off, "a2d_disph", &len);
	if (data && len)
		disph = fdt32_to_cpu(*data);

	data = (unsigned int *)fdt_getprop(fdt, off, "a2d_hash", &len);
	if (data && len)
		hash = fdt32_to_cpu(*data);

	offset = MTK_EMI_DRAM_OFFSET;

	magics[0] = emi_conf & mask;
	magics[1] = (emi_conf >> 4) & mask;
	magics[2] = (emi_conf >> 8) & mask;
	magics[3] = (emi_conf >> 12) & mask;
	magics[4] = (emi_conf >> 16) & mask;
	magics[5] = (emi_conf >> 20) & mask;
	magics[6] = (emi_conf >> 24) & mask;
	magics[7] = (emi_conf >> 28) & mask;

	dw32 = test_bit(1, (unsigned long *)&emi_cona) ? 1 : 0;

	channels = (emi_cona >> 8) & 0x3;
	cas = (emi_cona >> 18) & 0x3;
	cas += dw32 << 2;
	cas += ((emi_cona >> 26) & 1) << 3;
	cas = cas << 28;
	cas = cas << channels;

	dualrk_ch0 = test_bit(17, (unsigned long *)&emi_cona) ? 1 : 0;
	dualrk_ch1 = test_bit(16, (unsigned long *)&emi_cona) ? 1 : 0;

	chn_hash_lsb = 7 + (hash & (~hash + 1));
	if (hash)
		chnpos = chn_hash_lsb;
	else {
		chnpos = test_bit(3, (unsigned long *)&emi_cona) ? 2 : 0;
		chnpos |= test_bit(2, (unsigned long *)&emi_cona) ? 1 : 0;
	}

	tmp = (emi_conh >> 16) & 0xf;
	tmp += ((emi_conk >> 16) & 0xf) << 4;
	if (tmp)
		chab_rk0_sz = tmp << 8;
	else {
		tmp = (emi_cona >> 4) & 0x3;
		tmp += (emi_cona >> 12) & 0x3;
		tmp += test_bit(24, (unsigned long *)&emi_cona) ? 4 : 0;
		tmp += dw32;
		tmp += 7;
		chab_rk0_sz = 1 << tmp;
	}

	tmp = (emi_conh >> 20) & 0xf;
	tmp += ((emi_conk >> 20) & 0xf) << 4;
	if (tmp)
		chab_rk1_sz = tmp << 8;
	else if (!test_bit(17, (unsigned long *)&emi_cona))
		chab_rk1_sz = 0;
	else {
		tmp = (emi_cona >> 6) & 0x3;
		tmp += (emi_cona >> 14) & 0x3;
		tmp += test_bit(25, (unsigned long *)&emi_cona) ? 4 : 0;
		tmp += dw32;
		tmp += 7;
		chab_rk1_sz = 1 << tmp;
	}

	tmp = (emi_conh >> 24) & 0xf;
	tmp += ((emi_conk >> 24) & 0xf) << 4;
	if (tmp)
		chcd_rk0_sz = tmp << 8;
	else {
		tmp = (emi_cona >> 20) & 0x3;
		tmp += (emi_cona >> 28) & 0x3;
		tmp += test_bit(4, (unsigned long *)&emi_conh) ? 4 : 0;
		tmp += dw32;
		tmp += 7;
		chcd_rk0_sz = 1 << tmp;
	}

	tmp = (emi_conh >> 28) & 0xf;
	tmp += ((emi_conk >> 28) & 0xf) << 4;
	if (tmp)
		chcd_rk1_sz = tmp << 8;
	else if (!test_bit(16, (unsigned long *)&emi_cona))
		chcd_rk1_sz = 0;
	else {
		tmp = (emi_cona >> 22) & 0x3;
		tmp += (emi_cona >> 30) & 0x3;
		tmp += test_bit(5, (unsigned long *)&emi_conh) ? 4 : 0;
		tmp += dw32;
		tmp += 7;
		chcd_rk1_sz = 1 << tmp;
	}

	max_mb = chab_rk0_sz + chab_rk1_sz;
	max_mb += chcd_rk0_sz + chcd_rk0_sz;
	if ((channels > 1) || (disph > 0))
		max_mb *= 2;

	chab_row_mask[0] = (emi_cona >> 12) & 3;
	chab_row_mask[0] += test_bit(24, (unsigned long *)&emi_cona) ? 4 : 0;
	chab_row_mask[0] += 13;
	chab_row_mask[1] = (emi_cona >> 14) & 3;
	chab_row_mask[1] += test_bit(25, (unsigned long *)&emi_cona) ? 4 : 0;
	chab_row_mask[1] += 13;
	chcd_row_mask[0] = (emi_cona >> 28) & 3;
	chcd_row_mask[0] += test_bit(4, (unsigned long *)&emi_conh) ? 4 : 0;
	chcd_row_mask[0] += 13;
	chcd_row_mask[1] = (emi_cona >> 30) & 3;
	chcd_row_mask[1] += test_bit(5, (unsigned long *)&emi_conh) ? 4 : 0;
	chcd_row_mask[1] += 13;

	chab_col_mask[0] = (emi_cona >> 4) & 3;
	chab_col_mask[0] += 9;
	chab_col_mask[1] = (emi_cona >> 6) & 3;
	chab_col_mask[1] += 9;

	chcd_col_mask[0] = (emi_cona >> 20) & 3;
	chcd_col_mask[0] += 9;
	chcd_col_mask[1] = (emi_cona >> 22) & 3;
	chcd_col_mask[1] += 9;

	chn_4bank_mode = test_bit(6, (unsigned long *)&emi_conh_2nd) ? 1 : 0;

	prepared = 1;
}

static unsigned int use_a2d_magic(unsigned long addr, unsigned int bit)
{
	unsigned long magic;
	unsigned int ret;

	magic = magics[((bit >= 9) & (bit <= 16)) ? (bit - 9) : 0];

	ret = test_bit(bit, &addr) ? 1 : 0;
	ret ^= (test_bit(16, &addr) && test_bit(0, &magic)) ? 1 : 0;
	ret ^= (test_bit(17, &addr) && test_bit(1, &magic)) ? 1 : 0;
	ret ^= (test_bit(18, &addr) && test_bit(2, &magic)) ? 1 : 0;
	ret ^= (test_bit(19, &addr) && test_bit(3, &magic)) ? 1 : 0;

	return ret;
}

int emi_addr2dram(unsigned long addr, struct emi_addr_map *map)
{
	unsigned int tmp;
	unsigned long saddr, bfraddr, chnaddr;
	unsigned int max_rk0_sz;
	unsigned int row_mask, col_mask;
	bool ch_ab_not_cd;

	prepare_a2d();

	if (!map)
		return -1;
	else {
		map->emi = -1;
		map->channel = -1;
		map->rank = -1;
		map->bank = -1;
		map->row = -1;
		map->column = -1;
	}
	if (addr < offset)
		return -1;
	else
		addr -= offset;
	if ((addr >> 20) > max_mb)
		return -1;

	tmp = (test_bit(8, &addr) & test_bit(0, &disph)) ? 1 : 0;
	tmp ^= (test_bit(9, &addr) & test_bit(1, &disph)) ? 1 : 0;
	tmp ^= (test_bit(10, &addr) & test_bit(2, &disph)) ? 1 : 0;
	tmp ^= (test_bit(11, &addr) & test_bit(3, &disph)) ? 1 : 0;
	map->emi = tmp;

	saddr = addr;
	clear_bit(9, &saddr);
	clear_bit(10, &saddr);
	clear_bit(11, &saddr);
	clear_bit(12, &saddr);
	clear_bit(13, &saddr);
	clear_bit(14, &saddr);
	clear_bit(15, &saddr);
	clear_bit(16, &saddr);
	saddr |= use_a2d_magic(addr, 9) << 9;
	saddr |= use_a2d_magic(addr, 10) << 10;
	saddr |= use_a2d_magic(addr, 11) << 11;
	saddr |= use_a2d_magic(addr, 12) << 12;
	saddr |= use_a2d_magic(addr, 13) << 13;
	saddr |= use_a2d_magic(addr, 14) << 14;
	saddr |= use_a2d_magic(addr, 15) << 15;
	saddr |= use_a2d_magic(addr, 16) << 16;

	if (disph <= 0)
		bfraddr = saddr;
	else {
		tmp = 7 + __ffs(disph);
		bfraddr = (saddr >> (tmp + 1)) << tmp;
		bfraddr += saddr & ((1 << tmp) - 1);
	}

	if (bfraddr < cas)
		return -1;

	if (!channels)
		map->channel = channels;
	else if (hash) {
		tmp = (test_bit(8, &addr) && test_bit(0, &hash)) ? 1 : 0;
		tmp ^= (test_bit(9, &addr) && test_bit(1, &hash)) ? 1 : 0;
		tmp ^= (test_bit(10, &addr) && test_bit(2, &hash)) ? 1 : 0;
		tmp ^= (test_bit(11, &addr) && test_bit(3, &hash)) ? 1 : 0;
		map->channel = tmp;
	} else {
		if (channels == 1) {
			tmp = 0;
			switch (chnpos) {
			case 0:
				tmp = 7;
				break;
			case 1:
				tmp = 8;
				break;
			case 2:
				tmp = 9;
				break;
			case 3:
				tmp = 12;
				break;
			default:
				return -1;
			}
			map->channel = (bfraddr >> tmp) % 2;
		} else if (channels == 2) {
			tmp = 0;
			switch (chnpos) {
			case 0:
				tmp = 7;
				break;
			case 1:
				tmp = 8;
				break;
			case 2:
				tmp = 9;
				break;
			case 3:
				tmp = 12;
				break;
			default:
				return -1;
			}
			map->channel = (bfraddr >> tmp) % 4;
		} else {
			return -1;
		}
	}

	if (map->channel > 1)
		ch_ab_not_cd = 0;
	else {
		if (map->channel == 1)
			ch_ab_not_cd = (channels > 1) ? 1 : 0;
		else
			ch_ab_not_cd = 1;
	}

	max_rk0_sz = (ch_ab_not_cd) ? chab_rk0_sz : chcd_rk0_sz;
	max_rk0_sz = max_rk0_sz << 20;

	if (!channels)
		chnaddr = bfraddr;
	else if (chnpos > 3) {
		tmp = chn_hash_lsb;
		chnaddr = bfraddr >> (tmp + 1);
		chnaddr = chnaddr << tmp;
		chnaddr += bfraddr & ((1 << tmp) - 1);
	} else if (channels == 1 || channels == 2) {
		tmp = 0;
		switch (chnpos) {
		case 0:
			tmp = 7;
			break;
		case 1:
			tmp = 8;
			break;
		case 2:
			tmp = 9;
			break;
		case 3:
			tmp = 12;
			break;
		default:
			break;
		}
		chnaddr = bfraddr >> (tmp + (channels -1));
		chnaddr = chnaddr << tmp;
		chnaddr += bfraddr & ((1 << tmp) - 1);
	} else {
		return -1;
	}

	if ((map->channel) ? !dualrk_ch1 : !dualrk_ch0)
		map->rank = 0;
	else {
		if (chnaddr > max_rk0_sz)
			map->rank = 1;
		else
			map->rank = 0;
	}

	row_mask = (ch_ab_not_cd) ?
		((map->rank) ? chab_row_mask[1] : chab_row_mask[0]) :
		((map->rank) ? chcd_row_mask[1] : chcd_row_mask[0]);
	col_mask = (ch_ab_not_cd) ?
		((map->rank) ? chab_col_mask[1] : chab_col_mask[0]) :
		((map->rank) ? chcd_col_mask[1] : chcd_col_mask[0]);

	tmp = chnaddr - (max_rk0_sz * map->rank);
	tmp /= 1 << (dw32 + 1 + col_mask + 3);
	tmp &= (1 << row_mask) - 1;
	map->row = tmp;

	tmp = chnaddr;
	tmp /= 1 << (dw32 + 1 + col_mask);
	tmp &= ((!chn_4bank_mode) ? 8 : 4) - 1;
	map->bank = tmp;

	tmp = chnaddr;
	tmp /= 1 << (dw32 + 1);
	tmp &= (1 << col_mask) - 1;
	map->column = tmp;

	return 0;
}
