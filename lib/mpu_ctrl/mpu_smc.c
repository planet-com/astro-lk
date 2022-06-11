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

#include <debug.h>
#include <stdlib.h>
#include <string.h>
#include <pal_typedefs.h>
#include <pal_log.h>
#include <platform.h>
#ifdef MTK_ENABLE_MPU_HAL_SUPPORT
#include <mpu_smc.h>
#endif
#ifdef MTK_SMC_ID_MGMT
#include <mtk_secure_api.h>
#else
extern unsigned long mt_secure_call(unsigned long, unsigned long, unsigned long,
				    unsigned long);
#endif

#define MPU_DEBUG_ENABLE (0)
#if (MPU_DEBUG_ENABLE)
#define MPU_DBG(fmt, ...) pal_log_info("[MPU]" fmt, ##__VA_ARGS__)
#else
#define MPU_DBG(fmt, ...)                                                      \
	do {                                                                   \
	} while (0)
#endif
#define MPU_ERR(fmt, ...) pal_log_err("[MPU]" fmt, ##__VA_ARGS__)

#define MTK_SIP_LK_MPU_PERM_SET_AARCH32 0x82000128
#define MTK_SIP_LK_MPU_PERM_SET_AARCH64 0xC2000128

static uint32_t get_zone_info(uint32_t zone_id, uint32_t op)
{
	uint32_t zone_info;

	zone_info = (op & 0x0000FFFF);
	zone_info |= ((zone_id & 0x0000FFFF) << 16);

	return zone_info;
}

/* Cut lower 16-bits for 64KB alignment.
 * So that we can use 32-bit variable to carry 48-bit physical address range.
 */
#define MPU_PHYSICAL_ADDR_SHIFT_BITS (16)

static inline uint32_t get_encoded_phys_addr(uint64_t addr)
{
	return (addr >> MPU_PHYSICAL_ADDR_SHIFT_BITS);
}

static inline uint32_t is_valid_zone(uint32_t zone)
{
	return (zone < MPU_REQ_ORIGIN_LK_ZONE_MAX);
}

#define SIZE_64K 0x00010000
static inline uint32_t is_valid_addr(uint64_t addr)
{
	if (addr == 0)
		return 0;
	if ((addr % SIZE_64K) != 0)
		return 0;
	return 1;
}

static inline uint32_t is_valid_size(uint32_t size)
{
	if (size == 0)
		return 0;
	if (size < SIZE_64K)
		return 0;
	if ((size % SIZE_64K) != 0)
		return 0;
	return 1;
}

#define DRAM_START_ADDR (0x40000000ULL)
#define MAX_PROTECT_SIZE (0x100000000ULL)
static inline uint32_t is_valid_range(uint64_t start, uint64_t end)
{
	if (start < DRAM_START_ADDR)
		return 0;
	if (end <= start)
		return 0;
	if ((end - start) >= MAX_PROTECT_SIZE)
		return 0;
	return 1;
}

uint32_t sip_smc_protect_zone_request(enum MPU_REQ_ORIGIN_ZONE_ID zone_id,
				      uint64_t start_addr, uint64_t end_addr)
{
	uint32_t zone_size = (uint32_t)((end_addr + 1) - start_addr);
	uint32_t zone_info, encoded_addr;
	uint32_t smc_ret = 0;
	uint32_t enable = 1;

	if (!is_valid_zone(zone_id)) {
		MPU_ERR("Invalid zone: %d\n", zone_id);
		return 1;
	}

	if (!is_valid_addr(start_addr) || !is_valid_size(zone_size)) {
		MPU_ERR("Invalid addr or size! 0x%llx - 0x%llx (0x%x)\n",
			start_addr, end_addr, zone_size);
		return 2;
	}

	if (!is_valid_range(start_addr, end_addr)) {
		MPU_ERR("Invalid range! 0x%llx - 0x%llx\n", start_addr,
			end_addr);
		return 3;
	}

	zone_info = get_zone_info(zone_id, enable);
	encoded_addr = get_encoded_phys_addr(start_addr);

	MPU_DBG("SMC args: 0x%x, 0x%x, 0x%x\n", encoded_addr, zone_size,
		zone_info);

#ifdef MTK_SMC_ID_MGMT
	smc_ret = mt_secure_call(MTK_SIP_LK_MPU_PERM_SET_AARCH32, encoded_addr,
				 zone_size, zone_info, 0);
#else
	smc_ret = mt_secure_call(MTK_SIP_LK_MPU_PERM_SET_AARCH32, encoded_addr,
				 zone_size, zone_info);
#endif
	if (smc_ret) {
		MPU_ERR("SMC Set failed: 0x%x!\n", smc_ret);
		return 4;
	}

	MPU_DBG("%s:%d SMC passed!\n", __func__, __LINE__);
	return 0;
}
