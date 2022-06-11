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

#include <sys/types.h>
#include <ctype.h>
#include <stdint.h>
#include <platform/partition.h>
#include <platform/mt_typedefs.h>
#include <platform/boot_mode.h>
#include <platform/mt_reg_base.h>
#include <platform/errno.h>
#include <printf.h>
#include <string.h>
#include <malloc.h>
#include <libfdt.h>
#include <platform/mt_gpt.h>
#include <debug.h>
#include "ccci_ld_md_core.h"
#include "ccci_ld_md_errno.h"
#include <lk_load_md_wrapper.h>
#include <fdt_op.h>
#include <lk_builtin_dtb.h>
#define MODULE_NAME "LK_LD_MD"

/***************************************************************************************************
** Sub section:
**   Telephony operation parsing and prepare part
***************************************************************************************************/
/* For the following option setting, please check config.h after build, or $project.mk */
#ifdef MTK_PROTOCOL1_RAT_CONFIG
#define PS1_RAT_DEFAULT MTK_PROTOCOL1_RAT_CONFIG
#else
#define PS1_RAT_DEFAULT ""
#endif


/**************************************************************************************************************/
/* Global variable or table at this file                                                                      */
/**************************************************************************************************************/
static struct plat_info default_plat_info[] = {
	{"mediatek,MT6570", MD1}, {"mediatek,MT6580", 0}, {"mediatek,MT6763", MD1}, {"mediatek,MT6753", MD1|MD3}, {"mediatek,MT6755", MD1|MD3},
	{"mediatek,MT6735", MD1}, {"mediatek,MT6737", MD1}, {"mediatek,MT6750", MD1|MD3}, {"mediatek,MT6757", MD1|MD3},
	{"mediatek,MT6739", MD1}, {"mediatek,MT6761", MD1}, {"mediatek,MT6765", MD1}, {"mediatek,MT6768", MD1},
	{"mediatek,MT6771", MD1}, {"mediatek,mt6779", MD1}, {"mediatek,MT6785", MD1}, {"mediatek,mt6833", MD1},
	{"mediatek,MT6853", MD1}, {"mediatek,MT6873", MD1}, {"mediatek,MT6885", MD1}, {"mediatek,mt6893", MD1},
};

static int strcasecmp(const char *s1, const char *s2)
{
  int c1, c2;

  do {
	  c1 = tolower(*s1++);
	  c2 = tolower(*s2++);
  } while (c1 == c2 && c1 != 0);
  return c1 - c2;
}

static int radio_cfg_by_name(void *fdt, int offset, char name[])
{
	int len = 0;
	const void *fdt_tmp;

	fdt_tmp = fdt_getprop(fdt, offset, name, &len);
	if (!fdt_tmp || !len)
		return -1;

	return (int)fdt32_to_cpu(*(unsigned int *)fdt_tmp);
}

static char* get_plat_form_dt(void *fdt)
{
	int nodeoffset;
	int len = 0;
	const void* fdt_tmp;

	nodeoffset = fdt_path_offset(fdt, "/");
	fdt_tmp = fdt_getprop(fdt, nodeoffset, "compatible", &len);
	if (!fdt_tmp || !len)
		return NULL;
	return (char *)(fdt_tmp);
}

static int radio_cap_dts_confirm(void *fdt, int offset, char name[])
{
	int len = 0;
	const void *fdt_tmp;

	fdt_tmp = fdt_getprop(fdt, offset, "compatible", &len);
	if (!fdt_tmp || !len)
		return -1;

	if (strcmp((char*)fdt_tmp, name))
		return -1;

	return 0;
}

struct radio_md_cap_bit {
	char *key;
	unsigned int bit;
};

static struct radio_md_cap_bit radio_cap_bitmap_table[] =
{
	{"radio_md_g_en",  MD_CAP_GSM},
	{"radio_md_w_en",  MD_CAP_WCDMA},
	{"radio_md_t_en",  MD_CAP_TDS_CDMA},
	{"radio_md_c_en",  MD_CAP_CDMA2000},
	{"radio_md_lf_en", MD_CAP_FDD_LTE},
	{"radio_md_lt_en", MD_CAP_TDD_LTE},
	{"radio_md_nr_en", MD_CAP_NR},
};

static int get_radio_cfg_from_dt(void *fdt, unsigned int *radio_cap_bitmap)
{
	int nodeoffset;
	int ret;
	unsigned int i;

	if (!radio_cap_bitmap) {
		ALWAYS_LOG("cap bitmap is NULL\n");
		return -1;
	}

	nodeoffset = fdt_path_offset(fdt, "/radio_md_cfg");
	if (nodeoffset < 0) {
		ALWAYS_LOG("/radio_md_cfg disable at dts\n");
		return -1;
	}

	if (radio_cap_dts_confirm(fdt, nodeoffset, "mediatek,radio_md_cfg")) {
		ALWAYS_LOG("/radio_md_cfg compatible disable at dts\n");
		return -1;
	}

	for (i = 0; i < sizeof(radio_cap_bitmap_table)/sizeof(struct radio_md_cap_bit); i++) {
		ret = radio_cfg_by_name(fdt, nodeoffset, radio_cap_bitmap_table[i].key);
		if (ret < 0) {
			ALWAYS_LOG("radio cap:%s using default\n", radio_cap_bitmap_table[i].key);
			return -1;
		}
		if (ret > 0)
			*radio_cap_bitmap |= radio_cap_bitmap_table[i].bit;
	}

	return 0;
}

/**************************************************************************************************/
/* Local function for telephony                                                                   */
/**************************************************************************************************/
static unsigned int get_capability_bit(char cap_str[])
{
	if (cap_str == NULL)
		return 0;
	if ((strcmp(cap_str, "LF") == 0) || (strcmp(cap_str, "Lf") == 0) || (strcmp(cap_str, "lf") == 0))
		return MD_CAP_FDD_LTE;
	if ((strcmp(cap_str, "LT") == 0) || (strcmp(cap_str, "Lt") == 0) || (strcmp(cap_str, "lt") == 0))
		return MD_CAP_TDD_LTE;
	if ((strcmp(cap_str, "W") == 0) || (strcmp(cap_str, "w") == 0))
		return MD_CAP_WCDMA;
	if ((strcmp(cap_str, "C") == 0) || (strcmp(cap_str, "c") == 0))
		return MD_CAP_CDMA2000;
	if ((strcmp(cap_str, "T") == 0) || (strcmp(cap_str, "t") == 0))
		return MD_CAP_TDS_CDMA;
	if ((strcmp(cap_str, "G") == 0) || (strcmp(cap_str, "g") == 0))
		return MD_CAP_GSM;

	return 0;
}

#define MAX_CAP_STR_LENGTH  16
static unsigned int get_capablity_bit_map(char str[])
{
	char tmp_str[MAX_CAP_STR_LENGTH];
	int tmp_str_curr_pos = 0;
	unsigned int capability_bit_map = 0;
	int str_len;
	int i;

	if (str == NULL)
		return 0;

	str_len = strlen(str);
	for (i = 0; i < str_len; i++) {
		if (str[i] == ' ')
			continue;
		if (str[i] == '\t')
			continue;
		if ((str[i] == '/') || (str[i] == '_')) {
			if (tmp_str_curr_pos) {
				tmp_str[tmp_str_curr_pos] = 0;
				capability_bit_map |= get_capability_bit(tmp_str);
			}
			tmp_str_curr_pos = 0;
			continue;
		}
		if (tmp_str_curr_pos < (MAX_CAP_STR_LENGTH-1)) {
			tmp_str[tmp_str_curr_pos] = str[i];
			tmp_str_curr_pos++;
		} else
			break;
	}
	if (tmp_str_curr_pos) {
		tmp_str[tmp_str_curr_pos] = 0;
		capability_bit_map |= get_capability_bit(tmp_str);
	}

	return capability_bit_map;
}

static int get_md_bitmap(unsigned int tel_cap_bit_map, struct plat_info plat_list[], int num)
{
	int i;
	const void *fdt_plat;

	fdt_plat = get_plat_form_dt(get_lk_overlayed_dtb());
	if (!fdt_plat) {
		ALWAYS_LOG("error: fdt_plat is NULL; no platform matched\n");
		return 0;
	}

	if (tel_cap_bit_map) {
		for (i = 0; i < num; i++) {
			if (!strcasecmp(fdt_plat , plat_list[i].plat_name)) {
				if (plat_list[i].md_bitmap == MD1)
					return MD1;
				if (plat_list[i].md_bitmap == (MD1|MD3)){
					if(tel_cap_bit_map & MD_CAP_CDMA2000)
						return MD1|MD3;
					else
						return MD1;
				}
			}
		}
		if (i == num) {
			ALWAYS_LOG("no platform matched\n");
			return 0;
		}
	}

	return 0;
}

int ccci_ld_md_tel_init(void)
{
#ifndef LK_NO_SUPPORT_MD_CCCI
	int md_bitmap = 0;
	unsigned int default_cap_bit_map, dts_cap_bitmap;
	unsigned int plat_num = sizeof(default_plat_info)/sizeof(struct plat_info);

	/* Prepare default option setting */
	dts_cap_bitmap = 0;
	if (get_radio_cfg_from_dt(get_lk_overlayed_dtb(), &dts_cap_bitmap) < 0)
		default_cap_bit_map = get_capablity_bit_map(PS1_RAT_DEFAULT);
	else
		default_cap_bit_map = dts_cap_bitmap;
	if (default_cap_bit_map)
		md_bitmap = get_md_bitmap(default_cap_bit_map, default_plat_info, plat_num);
#endif
	return md_bitmap;
}
