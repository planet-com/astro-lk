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
#include <reg.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <platform/mt_reg_base.h>
#include <plat_debug_interface.h>
#include <systracker.h>
#include "utils.h"
#ifdef HAS_PLATFORM_BUS_DBG_BIT_FIELDS
#include <platform/systracker_fields.h>

#define TRACKER_VALID_S		PLT_TRACKER_VALID_S
#define TRACKER_VALID_E		PLT_TRACKER_VALID_E
#define TRACKER_SECURE_S	PLT_TRACKER_SECURE_S
#define TRACKER_SECURE_E	PLT_TRACKER_SECURE_E
#define TRACKER_ID_S		PLT_TRACKER_ID_S
#define TRACKER_ID_E		PLT_TRACKER_ID_E
#define TRACKER_DATA_SIZE_S	PLT_TRACKER_DATA_SIZE_S
#define TRACKER_DATA_SIZE_E	PLT_TRACKER_DATA_SIZE_E
#define TRACKER_BURST_LEN_S	PLT_TRACKER_BURST_LEN_S
#define TRACKER_BURST_LEN_E	PLT_TRACKER_BURST_LEN_E
#else /* else for HAS_PLATFORM_BUS_DBG_BIT_FIELDS */
#define TRACKER_VALID_S		26
#define TRACKER_VALID_E		26
#define TRACKER_SECURE_S	21
#define TRACKER_SECURE_E	21
#define TRACKER_ID_S		8
#define TRACKER_ID_E		20
#define TRACKER_DATA_SIZE_S	4
#define TRACKER_DATA_SIZE_E	6
#define TRACKER_BURST_LEN_S	0
#define TRACKER_BURST_LEN_E	3
#endif /* end of HAS_PLATFORM_BUS_DBG_BIT_FIELDS */

static int systracker_dump(char *buf, int *wp, unsigned int entry_num)
{
	unsigned int i;
	unsigned int reg_value;
	unsigned int entry_valid;
	unsigned int entry_secure;
	unsigned int entry_id;
	unsigned int entry_address;
	unsigned int entry_data_size;
	unsigned int entry_burst_length;

	if (buf == NULL || wp == NULL)
		return -1;

	/* Get tracker info and save to buf */

	/* check if we got AP tracker timeout */
	if (readl(BUS_DBG_CON) & BUS_DBG_CON_TIMEOUT) {
		*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp, "\n*************************** systracker ***************************\n");

		for (i = 0; i < entry_num; i++) {
			entry_address = readl(BUS_DBG_AR_TRACK_L(i));
			reg_value = readl(BUS_DBG_AR_TRACK_H(i));
			entry_valid = extract_n2mbits(reg_value, TRACKER_VALID_S, TRACKER_VALID_E);
			entry_secure = extract_n2mbits(reg_value, TRACKER_SECURE_S, TRACKER_SECURE_E);
			entry_id = extract_n2mbits(reg_value, TRACKER_ID_S, TRACKER_ID_E);
			entry_data_size = extract_n2mbits(reg_value, TRACKER_DATA_SIZE_S, TRACKER_DATA_SIZE_E);
			entry_burst_length = extract_n2mbits(reg_value, TRACKER_BURST_LEN_S, TRACKER_BURST_LEN_E);

			*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp,
						   "read entry = %d, valid = 0x%x, non-secure = 0x%x, read id = 0x%x, address = 0x%x, data_size = 0x%x, burst_length = 0x%x\n",
						   i, entry_valid, entry_secure, entry_id,
						   entry_address, entry_data_size, entry_burst_length);
		}

		for (i = 0; i < entry_num; i++) {
			entry_address = readl(BUS_DBG_AW_TRACK_L(i));
			reg_value = readl(BUS_DBG_AW_TRACK_H(i));
			entry_valid = extract_n2mbits(reg_value, TRACKER_VALID_S, TRACKER_VALID_E);
			entry_secure = extract_n2mbits(reg_value, TRACKER_SECURE_S, TRACKER_SECURE_E);
			entry_id = extract_n2mbits(reg_value, TRACKER_ID_S, TRACKER_ID_E);
			entry_data_size = extract_n2mbits(reg_value, TRACKER_DATA_SIZE_S, TRACKER_DATA_SIZE_E);
			entry_burst_length = extract_n2mbits(reg_value, TRACKER_BURST_LEN_S, TRACKER_BURST_LEN_E);

			*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp,
						   "write entry = %d, valid = 0x%x, non-secure = 0x%x, write id = 0x%x, address = 0x%x, data_size = 0x%x, burst_length = 0x%x\n",
						   i, entry_valid, entry_secure, entry_id, entry_address,
						   entry_data_size, entry_burst_length);
		}

		*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp,
				"write entry ~ %d, valid = 0x%x, data = 0x%x\n", entry_num - 2,
				((readl(BUS_DBG_W_TRACK_DATA_VALID)&(0x1<<6))>>6), readl(BUS_DBG_W_TRACK_DATA6));

		*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp,
				"write entry ~ %d, valid = 0x%x, data = 0x%x\n", entry_num - 1,
				((readl(BUS_DBG_W_TRACK_DATA_VALID)&(0x1<<7))>>7), readl(BUS_DBG_W_TRACK_DATA7));
	}

#ifdef BUSTRACKER
#include <platform/bustracker.h>
	/* check if we got infra tracker timeout */
	if (readl(INFRA_TRACKER_BASE) & BUSTRACKER_TIMEOUT) {
		*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp,
				"infra tracker timeout (0x%08x)\n", readl(INFRA_TRACKER_BASE));
		for (i = 0; i < INFRA_ENTRY_NUM; i++) {
			entry_address = readl(AR_TRACK_L(INFRA_TRACKER_BASE, i));
			reg_value = readl(AR_TRACK_H(INFRA_TRACKER_BASE, i));
			*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp,
							"read entry = %d, address = 0x%x, attribute = 0x%x\n",
							i, entry_address, reg_value);
		}
		for (i = 0; i < INFRA_ENTRY_NUM; i++) {
			entry_address = readl(AW_TRACK_L(INFRA_TRACKER_BASE, i));
			reg_value = readl(AW_TRACK_H(INFRA_TRACKER_BASE, i));
			*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp,
							"write entry = %d, address = 0x%x, attribute = 0x%x\n",
							i, entry_address, reg_value);
		}
	}

	/* check if we got peri tracker timeout */
	if (readl(PERI_TRACKER_BASE) & BUSTRACKER_TIMEOUT) {
		*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp,
				"peri tracker timeout (0x%08x)\n", readl(PERI_TRACKER_BASE));
		for (i = 0; i < PERI_ENTRY_NUM; i++) {
			entry_address = readl(AR_TRACK_L(PERI_TRACKER_BASE, i));
			reg_value = readl(AR_TRACK_H(PERI_TRACKER_BASE, i));
			*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp,
							"read entry = %d, address = 0x%x, attribute = 0x%x\n",
							i, entry_address, reg_value);
		}
		for (i = 0; i < PERI_ENTRY_NUM; i++) {
			entry_address = readl(AW_TRACK_L(PERI_TRACKER_BASE, i));
			reg_value = readl(AW_TRACK_H(PERI_TRACKER_BASE, i));
			*wp += snprintf(buf + *wp, SYSTRACKER_BUF_LENGTH - *wp,
							"write entry = %d, address = 0x%x, attribute = 0x%x\n",
							i, entry_address, reg_value);
		}
	}
#endif

	return strlen(buf);
}

int systracker_get(void **data, int *len, unsigned int entry_num)
{
	int ret;

	*len = 0;
	*data = malloc(SYSTRACKER_BUF_LENGTH);
	if (*data == NULL)
		return 0;

	ret = systracker_dump(*data, len, entry_num);
	if (ret < 0 || *len > SYSTRACKER_BUF_LENGTH) {
		*len = (*len > SYSTRACKER_BUF_LENGTH) ? SYSTRACKER_BUF_LENGTH : *len;
		return ret;
	}

	return 1;
}

void systracker_put(void **data)
{
	free(*data);
}
