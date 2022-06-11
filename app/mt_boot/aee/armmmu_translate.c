#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KEHeader.h"

extern uint64_t get_mpt(void);
extern uint64_t kedump_mem_read(uint64_t data, unsigned long sz, void *buf);
#if 0
extern int sLOG(char *fmt, ...);
#define LOG(fmt, ...)           \
    do { \
        sLOG(fmt, ##__VA_ARGS__);       \
        printf(fmt, ##__VA_ARGS__); \
    } while(0)

#else
#define LOG(fmt, ...)
#endif
static int read_mem(uint64_t paddr, void *buf, unsigned long size)
{
	uint64_t ret = 0;

	ret = kedump_mem_read(paddr, size, buf);
	return (ret == size) ? 0 : -1;
}


#define PAGE_SIZE 4096
#define PNUM_64 (PAGE_SIZE / sizeof(uint64_t))
static uint64_t lxpage[PNUM_64];

/* ARM PGD/PMD first 3 pages for userspace, last 1 pages for kernel space */
#define PNUM_32 (PAGE_SIZE * 4 / sizeof(uint32_t))
static uint32_t l1page32[PNUM_32];

/* ARM L2 PTE 512 entry and each entry 4 bytes */
#define PNUM_L2_32 512
static uint32_t l2page32[PNUM_L2_32];

static uint64_t mmutable_64_translate_l3(uint64_t vptr,
		uint64_t ptable)
{
	int ret = 0;
	uint64_t pa;

	unsigned int lxidx = (vptr >> 12) & 0x1ff;
	if (lxidx >= PNUM_64) {
		LOG("address:0x%llx index:%d overflow error\n", vptr, lxidx);
		return 0;
	}

	memset(lxpage, 0, PAGE_SIZE);
	ret = read_mem(ptable, lxpage, PAGE_SIZE);
	if (ret == 0) {
		LOG("(%d)ent value:0x%llx\n", lxidx, lxpage[lxidx]);
	} else {
		return 0;
	}

	switch(lxpage[lxidx] & 3) {
		case 3:
			pa = (lxpage[lxidx] & 0x0000fffffffff000)
				+ (vptr & 0xfff);
			break;
		default:
			LOG("invalid (%d)ent value:0x%llx\n", lxidx,
					lxpage[lxidx]);
			pa = 0;
	}

	return pa;
}

static uint64_t mmutable_64_translate_l2(uint64_t vptr,
		uint64_t ptable)
{
	int ret = 0;
	uint64_t pa;
	uint64_t next_table_address;

	unsigned int lxidx = (vptr >> 21) & 0x1ff;
	if (lxidx >= PNUM_64) {
		LOG("address:0x%llx index:%d overflow error\n", vptr, lxidx);
		return 0;
	}

	memset(lxpage, 0, PAGE_SIZE);
	ret = read_mem(ptable, lxpage, PAGE_SIZE);
	if (ret == 0) {
		LOG("(%d)ent value:0x%llx\n", lxidx, lxpage[lxidx]);
	} else {
		return 0;
	}

	switch(lxpage[lxidx] & 3) {
		case 1:
			pa = (lxpage[lxidx] & 0x0000ffffffe00000)
				+ (vptr & 0x1fffff);
			break;
		case 3:
			next_table_address = lxpage[lxidx]
				& 0x0000fffffffff000;
			pa = mmutable_64_translate_l3(vptr,
					next_table_address);
			break;
		default:
			LOG("invalid (%d)ent value:0x%llx\n", lxidx,
					lxpage[lxidx]);
			pa = 0;
	}

	return pa;
}

static uint64_t mmutable_64_translate_l1(uint64_t vptr,
		uint64_t ptable)
{
	int ret = 0;
	uint64_t pa;
	uint64_t next_table_address;

	unsigned int lxidx = (vptr >> 30) & 0x1ff;
	if (lxidx >= PNUM_64) {
		LOG("address:0x%llx index:%d overflow error\n", vptr, lxidx);
		return 0;
	}

	memset(lxpage, 0, PAGE_SIZE);
	ret = read_mem(ptable, lxpage, PAGE_SIZE);
	if (ret == 0) {
		LOG("(%d)ent value:0x%llx\n", lxidx, lxpage[lxidx]);
	} else {
		return 0;
	}

	switch(lxpage[lxidx] & 3) {
		case 1:
			pa = (lxpage[lxidx] & 0x0000ffffc0000000)
				+ (vptr & 0x3fffffff);
			break;
		case 3:
			next_table_address = lxpage[lxidx]
				& 0x0000fffffffff000;
			pa = mmutable_64_translate_l2(vptr,
					next_table_address);
			break;
		default:
			LOG("invalid (%d)ent value:0x%llx\n", lxidx,
					lxpage[lxidx]);
			pa = 0;
	}

	return pa;
}

uint64_t v2p_64(uint64_t vptr)
{
	uint64_t mpt = get_mpt();
	/* LOG("mater_page_table:0x%llx, vptr:0x%llx\n", mpt, vptr); */

	if ((vptr & 0x8000000000000000) != 0) {
		return mmutable_64_translate_l1(vptr, mpt);
	} else {
		LOG("illegal address:0x%llx\n", vptr);
	}

	return 0;
}

static uint64_t mmutable_32_translate_l2(uint64_t vptr, uint64_t ptable)
{
	int ret;
	uint64_t pa = 0;

	unsigned int lxidx = (vptr >> 12) & 0x1ff;

	memset(l2page32, 0, sizeof(l2page32));
	ret = read_mem(ptable, l2page32, sizeof(l2page32));
	if (ret == 0) {
		LOG("(%d)ent value:0x%x\n", lxidx, l2page32[lxidx]);
	} else {
		LOG("invalid l2 page table:0x%llx\n", ptable);
		return 0;
	}

	if (l2page32[lxidx] & 1)
		pa = (l2page32[lxidx] & 0xfffff000) + (vptr & 0xfff);
	else
		LOG("invalid (%d)ent value:0x%x\n", lxidx, l2page32[lxidx]);

	return pa;
}

static uint64_t mmutable_32_translate_l1(uint64_t vptr, uint64_t ptable)
{
	int ret;
	uint64_t pa;
	uint64_t next_table_address;

	unsigned int lxidx = (vptr >> 20) & 0xfff;
	if (lxidx >= PNUM_32) {
		LOG("address:0x%llx index:%d overflow error\n", vptr, lxidx);
		return 0;
	}

	memset(l1page32, 0, sizeof(l1page32));
	ret = read_mem(ptable, l1page32, sizeof(l1page32));
	if (ret == 0) {
		LOG("(%d)ent value:0x%x\n", lxidx, l1page32[lxidx]);
	} else {
		LOG("invalid l1 page table:0x%llx\n", ptable);
		return 0;
	}

	switch(l1page32[lxidx] & 3) {
	case 1:
		/* PMD point address is 1KB allign */
		next_table_address = l1page32[lxidx] & 0xfffff000;
		pa = mmutable_32_translate_l2(vptr, next_table_address);
		break;
	case 2:
		/* [31:20]12bit as PMD index */
		pa = (l1page32[lxidx] & 0xfff00000) + (vptr & 0xfffff);
		break;
	default:
		LOG("invalid (%d)ent value:0x%x\n", lxidx, l1page32[lxidx]);
		pa = 0;
	}

	return pa;
}


uint64_t v2p_32(uint64_t vptr)
{
	uint64_t mpt = get_mpt();

	if (vptr > 0xbf000000) {
		return mmutable_32_translate_l1(vptr, mpt);
	} else {
		LOG("illegal address:0x%llx\n", vptr);
	}

	return 0;
}

