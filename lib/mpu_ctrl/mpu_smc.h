/*
 * Copyright (c) 2020 MediaTek Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __MPU_SMC_H__
#define __MPU_SMC_H__

enum MPU_REQ_ORIGIN_ZONE_ID {
	MPU_REQ_ORIGIN_LK_ZONE_SECOS = 0,
	MPU_REQ_ORIGIN_LK_ZONE_MAX = 1,

	MPU_REQ_ORIGIN_ZONE_INVALID = 0x7FFFFFFF
};

uint32_t sip_smc_protect_zone_request(enum MPU_REQ_ORIGIN_ZONE_ID zone_id,
				      uint64_t start_addr, uint64_t end_addr);

#endif
