/*
 * Copyright (c) 2015-2020 MICROTRUST Incorporated
 * All rights reserved
 *
 * This file and software is confidential and proprietary to MICROTRUST Inc.
 * Unauthorized copying of this file and software is strictly prohibited.
 * You MUST NOT disclose this file and software unless you get a license
 * agreement from MICROTRUST Incorporated.
 */

#ifndef __PLAT_TEEI_DBG_INFO_H__
#define __PLAT_TEEI_DBG_INFO_H__
#define ARCH64_TEEI_LOG_BUF_INFO 0xf400000f
#define ARCH32_TEEI_LOG_BUF_INFO 0xb400000f
extern unsigned int (* plat_teei_log_get)(u64 offset, int *len, CALLBACK dev_write);
extern void teei_log_init(void);
#endif
