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
#include <ctype.h>
#include <debug.h>
#ifdef DEVICE_TREE_SUPPORT
#include <fdt_op.h>
#include <libfdt.h>
#endif
#include <malloc.h>
#include <part_interface.h>
#include <platform/errno.h>
#include <platform/mt_gpt.h>
#include <platform/verified_boot.h>
#include <platform/boot_mode.h>
#include <platform/partition.h>
#include <stdlib.h>

/*The buffer layout in DDR is as follows:
 * The total is 45MBs.
 * [phyaddr offset]
 *  0x00000000  +---------------------------+  0
 *              |    Core#0 reset vector    |
 *  0x00100000  +---------------------------+  DSP_RST_VEC_SZ * 1
 *              |    Core#0 main program    |
 *  0x00400000  +---------------------------+  DSP_RST_VEC_SZ * 1 + DSP_PROG_SZ * 1
 *              |    Core#1 reset vector    |
 *  0x00500000  +---------------------------+  DSP_RST_VEC_SZ * 2 + DSP_PROG_SZ * 1
 *              |    Core#1 main program    |
 *  0x00800000  +---------------------------+  DSP_RST_VEC_SZ * 2 + DSP_PROG_SZ * 2
 *              |    Core#2 reset vector    |
 *  0x00900000  +---------------------------+  DSP_RST_VEC_SZ * 3 + DSP_PROG_SZ * 2
 *              |    Core#2 main program    |
 *  0x00C00000  +---------------------------+  DSP_RST_VEC_SZ * 3 + DSP_PROG_SZ * 3
 *              |         Algo area         |
 *  0x02950000  +---------------------------+  default IRAM_OFFSET
 *              |  main program#0 IRAM data |
 *  0x02980000  +---------------------------+
 *              |  main program#1 IRAM data |
 *  0x029B0000  +---------------------------+
 *              |  main program#2 IRAM data |
 *  0x029E0000  +---------------------------+
 *              |    Merged image header    |
 *  0x02A10000  +---------------------------+
 *              |          PRELOAD          |
 *              +---------------------------+
 *
 * the layout of main program IRAM data
 *
 *              +--------------------------+
 *              |  total iram segment num  |
 *              +--------------------------+
 *              |     offset to iram#0     |
 *              +--------------------------+
 *              |      dest of iram#0      |
 *              +--------------------------+
 *              |      size of iram#0      |
 *              +--------------------------+
 *              |     offset to iram#1     |
 *              +--------------------------+
 *              |      dest of iram#1      |
 *              +--------------------------+
 *              |      size of iram#1      |
 *              +--------------------------+
 *              |     offset to iram#2     |
 *              +--------------------------+
 *              |      dest of iram#2      |
 *              +--------------------------+
 *              |      size of iram#2      |
 *              +--------------------------+
 *              |        iram#0 data       |
 *              +--------------------------+
 *              |        iram#1 data       |
 *              +--------------------------+
 *              |        iram#2 data       |
 *              +--------------------------+
 *
 * num: number of segment for IRAM program
 * off: bin data offset from start of Main Prog. IRAM
 * dst: the dst address of bin data at IRAM
 * size: size of bin data
 * seg_data: bin data
 *
 *
 * layout of Preload
 *              +-----------------------+
 *              |   preload#0 program   |
 *              +-----------------------+
 *              |  preload#0 IRAM data  |
 *              +-----------------------+
 *              |   preload#1 program   |
 *              +-----------------------+
 *              |  preload#1 IRAM data  |
 *              +-----------------------+
 *              |          ...          |
 *              +-----------------------+
 *
 *
*/
extern int mboot_common_load_part(char *part_name,
				  char *img_name, unsigned long addr);
extern void mtk_wdt_restart(void);

/*****************************************************************************
 *                             Constants/Macros                              *
 *****************************************************************************/
#define MODULE_NAME "[LK_BOOT_VPU] "
/*
 * VERSION: Character layout: 00.000.000 : major.minor.reserved
 */
#define VERSION        (0x21006000)

#define ADDR_ALIGN     (0x00010000)
#define ADDR_MAX       (0xC0000000)
#define DEF_RSRV_SIZE  (0x02A10000) // default reserved ddr size for vpu
#define PROG_OFFSET    (0x00100000) // start address of main program (core0)

#define DSP_RST_VEC_SZ (0x00100000) // Reset vector for 1 VPU: 1MB
#define DSP_PROG_SZ    (0x00300000) // Main program for 1 VPU: 3MB
#define DEF_ALG_SZ     (0x01D50000) // default algo bank size for 3 VPUs

#define IRAM_SEG_SZ    (0x00010000) // max 64k for each iram region
#define DSP_BOOT_SZ    (DSP_RST_VEC_SZ + DSP_PROG_SZ)
#define SPARE_SZ       (0x00001000) // spare size for VPU

#define MAX_PART_SIZE  (0x00F00000)
#define ADDR_MASK      (0xFFF00000)
#define ALIGN_16       (0x00000010) // 16 bytes alignment for algo bin and iram prog so that vpu core can use DMA to copy
#define ALIGN_32       (0x00000020)
#define ALIGN_4K       (0x00001000)
#define ALIGN_64K      (0x00010000)
#define ALIGN_2M       (0x00200000)

#define MAIN_SEG_MAX   (50)
#define ALG_NAME_SIZE  (32)
#define HDR_STR_SIZE   (32)
#define VP6_MAGIC      (0x60)
#define PROP_LEN       (16)
#define MAX_DSP_NUM    (3)
#define NODE_CONT_LEN  (3)
#define MAJOR_VER(x)   (x & 0xFF000000)

#define IRAM_MAIN_HDR_SIZE (4 + MAIN_SEG_MAX * sizeof(struct iram_desc))
#define MAIN_IRAM_DESC_HDR_SIZE   ALIGN(IRAM_MAIN_HDR_SIZE, ALIGN_16)

#define LOG_CRI(format, args...)  dprintf(CRITICAL, MODULE_NAME format, ##args)
#define LOG_INF(format, args...)  dprintf(INFO, MODULE_NAME format, ##args)

#define DT_ID            "id"
#define DT_IRAM_DAT      "iram-data"
#define DT_ALGO          "algo"
#define DT_COMP          "compatible"
#define DT_BIN           "bin-phy-addr"
#define DT_BIN_SZ        "bin-size"
#define DT_HEAD          "img-head"
#define DT_PRE_BIN       "pre-bin"

#if (SCRATCH_SIZE < MAX_PART_SIZE)
#error SCRATCH_SIZE < MAX_PART_SIZE
#endif

/*****************************************************************************
 *                             Type declarations                             *
 *****************************************************************************/
enum CORE_NUM {
	CORE0 = 0,
	CORE1,
	CORE2,
	CORE_MAX,
};

enum _VPU_CORE_ENUM_ {
	VPU_CORE_0 = (VP6_MAGIC | (1 << CORE0)), /* bitwise to represent core index */
	VPU_CORE_1 = (VP6_MAGIC | (1 << CORE1)),
	VPU_CORE_2 = (VP6_MAGIC | (1 << CORE2)),
	VPU_CORE_MAX = 0x03,
};

enum auth_cmd {
	AUTH_INIT,
	AUTH_DO,
};

enum dt_prop {
	PROP_INIT,
	PRE_BIN,
};

enum DSP_ADDR {
	RESET_VEC = 0,
	MAIN_PROG = 1,
	IRAM = 2,
};

enum pre_flag {
	EXE_SEG  = (1 << 0),
	ZERO_SEG = (1 << 1),
};

enum {
	TOTAL_DSP,
	TOTAL_ALG_SZ,
	RESERVE_VAR2,
	RESERVE_VAR3,
	RESERVE_TOTAL,
};

struct iram_desc {
	unsigned int offset;
	unsigned int addr;
	unsigned int size;
};

struct seg_info {
	u32 vpu_core; /* core index */
	u32 off;      /* offset */
	u32 pAddr;    /* destination */
	u32 mem_sz;   /* mem. size byte to occupied */
	u32 file_sz;  /* file size byte to copy */
};

struct addr_param {
	int is_preload;
	int core;
	int iram_segment;
	int iram_num;
	u32 iram_hdr;
	u32 mblock;
	u32 iram_off;
	u32 phys_addr;
	u32 mem_sz;
	u32 ihdr_size;
	u32 preload_base;
	u32 preload_sz;
};

struct alg_info {
	u32 vpu_core; /* core index */
	u32 off;      /* offset */
	u32 file_sz;  /* file size byte to copy */
	char name[ALG_NAME_SIZE];
};

struct pre_info {
	u32 vpu_core;
	u32 off;
	u32 pAddr;
	u32 mem_sz;
	u32 file_sz;
	u32 flag;
	u32 info; // already aligned (to 4k or 64k) at packing stage
	u32 reserve;
	char name[ALG_NAME_SIZE];
};

struct img_info {
	int total_num;
	int hdr_size;
	int img_max;
	int pre_cnt;
	u32 dsp_num;
	u32 total_extra_sz;
	u32 total_alg_sz;
	void *head;
	char *name;
};

struct install_params {
	int   img_max;
	u32   mblock;
	u32   alg_dst;
	u32   pre_dst;
	u32   iram_off;
	char *name;
	int  *overlap;
	struct img_header *part_hdr;
};

struct prop_params {
	u32 dsp_num;
	u32 mblock;
	u32 aligned_size;
	u32 head_offset;
	u32 preload_offset;
	u32 iram_off;
	u32 alg_offset;
	u32 total_alg_sz;
};

struct img_header {
	int version;
	int build_date;
	int hdr_str[HDR_STR_SIZE / 4];
	int hdr_size;
	int img_size;
	int mem_size; // total preload segments size

	int segment_num;
	int seg_info; // offset
	int seg_size;

	int pre_num;
	int pre_info; // offset
	int pre_size;

	int alg_num;
	int alg_info; // offset

	int reserved[RESERVE_TOTAL];
};

/*****************************************************************************
 *                             Global variables                              *
 *****************************************************************************/
static char *part_name[] = {"cam_vpu1", "cam_vpu2", "cam_vpu3"};
static u32 vpu_m4u_addr[3][3] = {
	{0x7DA00000, 0x7DB00000, 0x7FF00000},
	{0x7E300000, 0x7E400000, 0x7FF00000},
	{0x7EC00000, 0x7ED00000, 0x7FF00000}
};

/*****************************************************************************
 *                             Functions/Interfaces                          *
 *****************************************************************************/
static int is_dsp_addr(unsigned int addr, unsigned int core, unsigned int block)
{
	return (addr & ADDR_MASK) == vpu_m4u_addr[core][block];
}

static inline int ascen(const int a, const int b)
{
	return a == b ? 0 : a < b ? -1 : 1;
}

static inline int descen(const int a, const int b)
{
	return -ascen(a, b);
}

static inline void swap(int *const a, int *const b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int check_overlap(int *addr, int len)
{
	int cnt = 0, i, cmp;
	int (*compare)(const int, const int);

	for (i = 0; i < len; ++i) {
		cmp = ascen(addr[i - 1], addr[i]);
		if (cmp == 0) {
			return true;
		}
		cnt += cmp;
	}

	compare = cnt <= 0 ? ascen : descen;

	for (i = 1; i < len; i+= cmp == -1 || i == 1 ? 1 : -1) {
		cmp = compare(addr[i - 1], addr[i]);
		if (cmp == 0) {
			return true;
		}
		if (cmp == 1) {
			swap(&addr[i], &addr[i - 1]);
		}
	}
	return false;
}

#ifdef DEVICE_TREE_SUPPORT
static void vpu_prop(void *t, int offset, const char *type, unsigned int prop)
{
	u64 value;
	value = cpu_to_fdt32(prop);
	fdt_setprop(t, offset, type, (char *)&value, sizeof(u32));
}

static void vpu_prop_array(void *t, int offset, const char *type, void *prop)
{
	fdt_setprop(t, offset, type, (char *)prop,
		sizeof(fdt32_t) * NODE_CONT_LEN);
}

static int vpu_prop_subnode(void *fdt, int parent, char *name)
{
	int offset;

	offset = fdt_subnode_offset(fdt, parent, name);
	if (offset < 0)
		offset = fdt_add_subnode(fdt, parent, name);
	if (offset < 0)
		LOG_CRI("fail to add subnode to fdt: %s\n", name);

	return offset;
}

#define COMP_MAX 32  // maximum length of VPU's compatible name at DTS

// v1: legacy, kernel-4.x
static int vpu_prop_create_v1(void *fdt, char *name, int core)
{
	int offset = 0;
	char comp[COMP_MAX];

	// compatible name: "mediatek,vpu_core[012]"
	if (snprintf(comp, COMP_MAX, "mediatek,vpu_core%d", core) <= 0)
		return -EINVAL;

	LOG_INF("vpu%d: create \"%s\", \"%s\"\n", core, name, comp);
	offset = fdt_path_offset(fdt, "/");
	if (offset < 0) {
		LOG_CRI("fail to get fdt offset: %d\n", offset);
		return -EINVAL;
	}

	// kernel-4.x device nodes are located at "/"
	offset = vpu_prop_subnode(fdt, offset, name);
	if (offset < 0)
		return -EINVAL;

	fdt_setprop_string(fdt, offset,	DT_COMP, comp);
	vpu_prop(fdt, offset, DT_ID, core);
	return offset;
}

// v2: common kernel, kernel-5.x
static int vpu_prop_create_v2(void *fdt, char *name, int core)
{
	int offset = 0;
	char comp[COMP_MAX];
	int i;

	// compatible name: "mediatek,mt68xx-vpu_core"
	if (snprintf(comp, COMP_MAX, "mediatek,%s-vpu_core", PLATFORM) <= 0)
		return -EINVAL;

	for (i = 0; i < COMP_MAX && comp[i]; i++)
		comp[i] = tolower(comp[i]);

	LOG_INF("vpu%d: create \"%s\", \"%s\"\n", core, name, comp);
	offset = fdt_path_offset(fdt, "/");
	if (offset < 0) {
		LOG_CRI("fail to get fdt offset: %d\n", offset);
		return -EINVAL;
	}

	// kernel-5.x (common kernel) device nodes are located at "/soc/"
	offset = vpu_prop_subnode(fdt, offset, "soc");
	offset = vpu_prop_subnode(fdt, offset, name);
	if (offset < 0)
		return -EINVAL;

	fdt_setprop_string(fdt, offset,	DT_COMP, comp);
	vpu_prop(fdt, offset, DT_ID, core);
	return offset;
}

static int vpu_prop_off(void *t, int core)
{
	bool soc = true;
	int off;
	char name[16];

	off = fdt_path_offset(t, "/soc");
	if (off < 0) {
		soc = false;
		off = fdt_path_offset(t, "/");
		if (off < 0)
			return -1;
	}

	snprintf(name, 16, "vpu_core%d", core);
	off = fdt_subnode_offset(t, off, name);

	if (off < 0) {
		LOG_INF("%s was not found, try to create\n", name);
		if (soc)
			off = vpu_prop_create_v2(t, name, core);
		else
			off = vpu_prop_create_v1(t, name, core);

		if (off < 0)
			LOG_INF("unable to create %s\n", name);
	}

	return off;
}
#endif

static int set_property(struct prop_params *prop)
{
#ifdef DEVICE_TREE_SUPPORT
	void *fdt = NULL;
	unsigned int i = 0, j, dsp_num = 0;
	int offset;
	fdt32_t iram_prop[3][NODE_CONT_LEN] = {{0}, {0}, {0}};
	fdt32_t alg_prop[NODE_CONT_LEN] = {0};
	u32 vpu_iram_data[3][NODE_CONT_LEN] = {
		{0x00000000, IRAM_SEG_SZ, 0x02950000},
		{0x00000000, IRAM_SEG_SZ, 0x02950000 + IRAM_SEG_SZ},
		{0x00000000, IRAM_SEG_SZ, 0x02950000 + (IRAM_SEG_SZ * 2)}
	};
	u32 vpu_alg[NODE_CONT_LEN] = {
		0x00000000, DEF_ALG_SZ, (DSP_BOOT_SZ * 3)};

	fdt = get_kernel_fdt();

	if (!fdt) {
		LOG_CRI("Null fdt\n");
		return -EINVAL;
	}

	dsp_num = prop->dsp_num;
	offset =vpu_prop_off(fdt, 0);
	if (offset < 0)
		return 0;

	vpu_alg[1] = prop->total_alg_sz;
	vpu_alg[2] = prop->alg_offset;

	for (i = 0; i < NODE_CONT_LEN; i++)
		alg_prop[i] = cpu_to_fdt32(vpu_alg[i]);

	for (i = 0; i < dsp_num; i++) {
		vpu_iram_data[i][2] =
		prop->alg_offset + prop->total_alg_sz + (i * IRAM_SEG_SZ);

		for (j = 0; j < NODE_CONT_LEN; j++)
			iram_prop[i][j] = cpu_to_fdt32(vpu_iram_data[i][j]);
	}

	vpu_prop(fdt, offset, DT_BIN, prop->mblock);
	vpu_prop(fdt, offset, DT_BIN_SZ, prop->aligned_size);
	vpu_prop(fdt, offset, DT_HEAD, prop->head_offset);
	vpu_prop(fdt, offset, DT_PRE_BIN, prop->preload_offset);

	vpu_prop_array(fdt, offset, DT_ALGO, (char *)&alg_prop);

	for (i = 0; i < dsp_num; i++) {
		offset = vpu_prop_off(fdt, i);
		if (offset < 0)
			continue;

		vpu_prop_array(fdt, offset, DT_IRAM_DAT,
			(char *)&iram_prop[i][0]);
	}
#endif
	return 0;
}

static int img_auth(unsigned int cmd, char *name, void *addr, int len)
{
	int ret = 0;
#ifdef MTK_SECURITY_SW_SUPPORT
	unsigned int idx = 0;
	unsigned int time = 0;

	switch (cmd) {
	case AUTH_INIT:
		idx = get_policy_entry_idx(name);
		ret = get_vfy_policy(idx);

		if (ret) {
			mtk_wdt_restart();
			time = get_timer(0);
			ret = (int)sec_img_auth_init(name, name, 0);

			if (ret) {
				LOG_CRI("fail to verify %s cert (0x%x)\n",
					name, ret);
				assert(0);
			}

			LOG_CRI("[SBC] %s cert vfy pass(%d ms)\n",
				name, (unsigned int)get_timer(time));

#ifdef MTK_SECURITY_ANTI_ROLLBACK
			ret = sec_rollback_check(1);
			if (ret) {
				LOG_CRI("fail to check %s version (0x%x)\n",
					name, ret);
				assert(0);
			}
#endif
		}
		break;
	case AUTH_DO:
		mtk_wdt_restart();
		time = get_timer(0);
		ret = (int)sec_img_auth(addr, len);

		if (ret) {
			LOG_CRI("fail to check %s hash (0x%x)\n", name, ret);
			assert(0);
		}

		LOG_CRI("[SBC] %s vfy pass(%d ms)\n", name,
			(unsigned int)get_timer(time));
		break;
	default :
		break;
	}
#endif
	return ret;
}

static unsigned int get_addr(struct addr_param *param)
{
	int offset = 0;
	u32 addr = param->phys_addr;
	u32 mblock = param->mblock;
	u32 *iram_num = NULL;
	struct iram_desc *desc = NULL;

	static u32 iram1_seg = MAIN_IRAM_DESC_HDR_SIZE;
	static u32 iram2_seg = MAIN_IRAM_DESC_HDR_SIZE;
	static u32 iram3_seg = MAIN_IRAM_DESC_HDR_SIZE;
	static u32 pre_seg = 0;

	if (is_dsp_addr(addr, CORE0, MAIN_PROG)) {
		offset = (int)(addr - vpu_m4u_addr[CORE0][MAIN_PROG]);
		mblock += DSP_RST_VEC_SZ;
	} else if (is_dsp_addr(addr, CORE1, MAIN_PROG)) {
		offset = (int)(addr - vpu_m4u_addr[CORE1][MAIN_PROG]);
		mblock += (DSP_BOOT_SZ + DSP_RST_VEC_SZ);
	} else if (is_dsp_addr(addr, CORE2, MAIN_PROG)) {
		offset = (int)(addr - vpu_m4u_addr[CORE2][MAIN_PROG]);
		mblock += ((DSP_BOOT_SZ << 1) + DSP_RST_VEC_SZ);
	} else if (is_dsp_addr(addr, CORE0, RESET_VEC)) {
		offset = (int)(addr - vpu_m4u_addr[CORE0][RESET_VEC]);
	} else if (is_dsp_addr(addr, CORE1, RESET_VEC)) {
		offset = (int)(addr - vpu_m4u_addr[CORE1][RESET_VEC]);
		mblock += DSP_BOOT_SZ;
	} else if (is_dsp_addr(addr, CORE2, RESET_VEC)) {
		offset = (int)(addr - vpu_m4u_addr[CORE2][RESET_VEC]);
		mblock += (DSP_BOOT_SZ << 1);
	} else if (is_dsp_addr(addr, CORE0, IRAM) && !param->is_preload) {
		param->iram_segment = 1;

		switch (param->core) {
		case VPU_CORE_0:
			offset = iram1_seg;
			mblock += param->iram_off;
			iram_num  = (u32 *)mblock;
			iram1_seg += ALIGN(param->mem_sz, ALIGN_16);
			break;
		case VPU_CORE_1:
			offset = iram2_seg;
			mblock += (param->iram_off + IRAM_SEG_SZ);
			iram_num  = (u32 *)mblock;
			iram2_seg += ALIGN(param->mem_sz, ALIGN_16);
			break;
		case VPU_CORE_2:
			offset = iram3_seg;
			mblock += param->iram_off + (IRAM_SEG_SZ << 1);
			iram_num  = (u32 *)mblock;
			iram3_seg += ALIGN(param->mem_sz, ALIGN_16);
			break;
		default:
			LOG_CRI("invalid segment core 0x%x\n", param->core);
			return 0;
		}

		param->iram_num = (*iram_num);

		//update iram descriptor
		desc = (void *)(mblock + sizeof(int));
		desc[param->iram_num].offset = offset;
		desc[param->iram_num].addr = addr;
		desc[param->iram_num].size = param->mem_sz;
		*iram_num = (param->iram_num + 1);
	} else if (param->is_preload) {
		if (is_dsp_addr(addr, CORE0, IRAM)) {
			param->iram_segment = 1;
			mblock += param->iram_off;
			param->iram_off += param->mem_sz;
		} else {
			param->iram_segment = 0;

			if (addr == 0xFFFFFFFF) {
				pre_seg += param->preload_sz;
				mblock += pre_seg;
				param->iram_off = pre_seg + param->ihdr_size;
				pre_seg += param->mem_sz;
			} else {
				mblock += (pre_seg +
					  (addr - param->preload_base));
			}
		}

		if (param->iram_hdr && param->iram_segment) {
			iram_num  = (unsigned int *)param->iram_hdr;
			param->iram_num = (*iram_num);
			desc = (void *)(param->iram_hdr + sizeof(int));
		}
	} else {
		LOG_CRI("invalid segment addr 0x%x\n", addr);
		return 0;
	}

	return (mblock + offset);
}

static int install_main(struct install_params *install)
{
	struct img_header *part_hdr = install->part_hdr;
	struct addr_param param;
	int j, ret = 0;
	int offset = 0, read_size = 0, zero = 0, info = part_hdr->seg_info;
	u32 dst = 0;
	struct seg_info *seg = (void *)((unsigned long)part_hdr + info);

	memset(&param, 0, sizeof(struct addr_param));

	for (j = 0; j < part_hdr->segment_num; j++) {
		offset = seg->off + part_hdr->hdr_size;
		read_size = seg->file_sz;

		param.core = seg->vpu_core;
		param.phys_addr = seg->pAddr;
		param.mem_sz = seg->mem_sz;
		param.mblock = install->mblock;
		param.iram_off = install->iram_off;
		param.iram_segment = 0;

		if (!(dst = get_addr(&param))) {
			ret = -EINVAL;
			break;
		}

		if (param.iram_segment) {
			LOG_INF("seg[%2d] [0x%05x:0x%05x] -> [0x%x/0x%x]: iram[0x%x:%d]\n",
				j, offset, read_size, seg->pAddr, dst,
				seg->vpu_core, param.iram_num);
		} else {
			LOG_INF("seg[%2d] [0x%05x:0x%05x] -> [0x%x/0x%x]\n",
				j, offset, read_size, seg->pAddr, dst);
		}

		if (seg->file_sz > 0) {
			if (offset + read_size > install->img_max) {
				LOG_CRI("%s partition offset error, offset 0x%x, read_size 0x%x\n",
					install->name, offset, read_size);
				ret = -EINVAL;
				break;
			} else {
				memcpy((void *)dst,
					(void *)((u8 *)part_hdr + offset),
					read_size);
			}
		}

		zero = seg->mem_sz - seg->file_sz;

		if (zero) {
			dst += seg->file_sz;
			LOG_INF("%-7s [0x%x:0x%x]\n", "zero", dst, zero);
			memset((void *)(dst), 0, zero);
		}
		seg++;
	}

	return ret;
}

static int install_preload(struct install_params *install)
{
	struct img_header *part_hdr = install->part_hdr;
	struct addr_param param;
	int j, ret = 0, idx = install->overlap[0];
	int offset = 0, read_size = 0, zero = 0, info = part_hdr->pre_info;
	u32 dst = 0;
	struct pre_info *pre = (void *)((unsigned long)part_hdr + info);

	memset(&param, 0, sizeof(struct addr_param));

	for (j = 0; j < part_hdr->pre_num; j++) {
		offset = pre->off + part_hdr->hdr_size + part_hdr->seg_size;
		read_size = (pre->pAddr == (unsigned int)0xFFFFFFFF) ?
			     pre->mem_sz : pre->file_sz;

		param.is_preload = true;
		param.core   = pre->vpu_core;
		param.phys_addr = pre->pAddr;
		param.mem_sz = pre->file_sz;
		param.mblock = install->pre_dst;
		param.iram_segment = 0;
		param.iram_hdr = 0;
		param.ihdr_size = (pre->pAddr == (unsigned int)0xFFFFFFFF) ?
			pre->mem_sz : 0;

		if ((pre->flag & EXE_SEG) == EXE_SEG) {
			param.phys_addr = pre->pAddr & 0xFFF00000;
			param.preload_base = param.phys_addr;
			param.preload_sz = pre->info;

			install->overlap[idx] = pre->pAddr & 0xFFF00000;
			install->overlap[0] = ++idx;
		}

		if (!(dst = get_addr(&param))) {
			ret = -EINVAL;
			break;
		}

		if (param.iram_segment) {
			LOG_INF("pre[%2d] [0x%05x:0x%06x] -> [0x%x/0x%x]: iram[0x%x:%d]\n",
				 j, offset, read_size, pre->pAddr, dst,
				 pre->vpu_core, param.iram_num);
		} else {
			if (pre->pAddr == 0xFFFFFFFF) {
				param.iram_hdr = dst;
				LOG_INF("pre[%2d] [0x%05x:0x%06x] -> [0x%x/0x%x]: iram[0x%x] head\n",
					 j, offset, pre->file_sz, pre->pAddr,
					 dst, pre->vpu_core);
			} else {
				param.iram_hdr = 0;
				LOG_INF("pre[%2d] [0x%05x:0x%06x] -> [0x%x/0x%x]\n",
					j, offset, read_size, pre->pAddr, dst);
			}
		}

		if (pre->file_sz > 0) {
			if (offset + read_size > install->img_max) {
				LOG_CRI("%s partition offset error, offset 0x%x, read_size 0x%x\n",
					install->name, offset, read_size);
				ret = -EINVAL;
				break;
			} else {
				memcpy((void *)dst,
					(void *)((u8 *)part_hdr + offset),
					read_size);
			}
		}

		zero = pre->mem_sz - pre->file_sz;
		pre->off = dst - install->mblock;

		if (zero && pre->pAddr != 0xFFFFFFFF) {
			dst += pre->file_sz;
			LOG_INF("%-7s [0x%x:0x%x]\n", "zero", dst, zero);
			memset((void *)(dst), 0, zero);
		}
		pre++;
	}

	return ret;
}

static int install_algo(struct install_params *install)
{
	struct img_header *part_hdr = install->part_hdr;
	int j, ret = 0;
	int offset = 0, read_size = 0, info = part_hdr->alg_info;
	u32 dst = install->alg_dst;
	struct alg_info *alg = (void *)((unsigned long)part_hdr + info);

	for (j = 0; j < part_hdr->alg_num; j++) {
		int new_offset = (int)(dst - install->mblock);
		offset = alg->off + part_hdr->hdr_size;
		read_size = alg->file_sz;

		LOG_INF("alg[%2d] [0x%06x:0x%06x] -> [0x%x] => 0x%x\n",
			j, offset, read_size, dst, new_offset);

		if (offset + read_size > install->img_max) {
			LOG_CRI("%s partition offset error, offset 0x%x, read_size 0x%x\n",
				install->name, offset, read_size);
			ret = -EINVAL;
			break;
		} else {
			memcpy((void *)dst,
				(void *)((u8 *)part_hdr + offset),
				read_size);
		}

		// change alg offset in partition header for driver to get real offset
		alg->off = new_offset;
		dst += ALIGN(alg->file_sz, ALIGN_16);
		alg++;
	}

	install->alg_dst = dst;
	return ret;
}

void *read_img(void)
{
	int i, len, need_auth = 0, pre_cnt = 0, alg_sum = 0, dsp_num = 0;
	int total_num = countof(part_name);
	char *name = NULL;
	int max = 0;
	unsigned long bin_size = 0, hdr_total = 0;
	struct img_header *head = NULL;
	struct img_info *info = calloc(total_num, sizeof(struct img_info));
	unsigned int img_buf = (unsigned int)SCRATCH_ADDR +
				SCRATCH_SIZE - DEF_RSRV_SIZE; //start from tail to avoid polluting kernel zimage
	void *part = (void *)img_buf;

	if (!info) {
		LOG_CRI("calloc fail\n");
		return NULL;
	}

	for (i = 0; i < total_num; i++) {
		info[i].total_num = total_num;
		name = part_name[i];
		max = partition_get_size_by_name(name);

		need_auth = img_auth(AUTH_INIT, name, NULL, 0);

		if ((len = mboot_common_load_part(
			name, name, (unsigned long)part)) < 0) {
			LOG_CRI("%s partition read error. len = %d\n",
				name, len);
			free(info);
			return NULL;
		}

		if (need_auth)
			img_auth(AUTH_DO, name, part, len);

		head = part;
		head->hdr_str[HDR_STR_SIZE/4 - 1] = 0;

		if (head->img_size > max) {
			LOG_CRI("img size(0x%x) exceeds!\n", head->img_size);
			free(info);
			return NULL;
		}

		if (MAJOR_VER(VERSION) != MAJOR_VER(head->version)) {
			LOG_CRI("version mismatch (%x/[%d]%x)\n",
				VERSION, i, head->version);
			free(info);
			return NULL;
		}

		info[i].head = head;
		info[i].name = name;
		info[i].img_max = max;

		bin_size += head->mem_size;
		LOG_INF("total preload mem size: 0x%x\n", head->mem_size);
		hdr_total += head->hdr_size;
		pre_cnt += head->pre_num;
		part += max;

		// cam_vpu1.img carries only main program & preload and does not carry normal libraries
		if (i)
			alg_sum += head->reserved[TOTAL_ALG_SZ];
		else
			dsp_num = head->reserved[TOTAL_DSP];
	}
	info[0].hdr_size = ALIGN(hdr_total, ALIGN_32);
	info[0].pre_cnt = pre_cnt;
	info[0].dsp_num = dsp_num ? dsp_num : 3;
	info[0].total_alg_sz = ALIGN(alg_sum, ALIGN_64K);

	bin_size = ALIGN(bin_size, ALIGN_4K);
	info[0].total_extra_sz = bin_size;
	return info;
}

int mt_load_vpu(void)
{
	int i, ret = 0, num;
	int *overlap = NULL;
	u32 *pIramNum;
	u32 mblock, head_dst, iram_off = 0, offset = 0, pre_dst = 0;
	u32 extra_size = 0, mblock_size = 0, aligned_size = 0;
	u32 alg_offset = 0;
	struct img_info *img = NULL;
	struct img_header *head = NULL;
	struct install_params params;
	struct prop_params prop;

	if (!(img = read_img())) {
		ret = -EINVAL;
		goto exit;
	}

	overlap = calloc((img->pre_cnt + 1), sizeof(int));
	extra_size = img->total_extra_sz;

	LOG_INF("extra_size: 0x%x\n", extra_size);

	mblock_size = (DSP_BOOT_SZ + IRAM_SEG_SZ) * img->dsp_num +
		img->total_alg_sz + img->hdr_size + extra_size + SPARE_SZ;

	aligned_size = ALIGN(mblock_size, ALIGN_64K);

	if (IS_ALIGNED(aligned_size, ALIGN_2M))
		aligned_size += ALIGN_64K;

	mblock = (u32)mblock_reserve_ext(&g_boot_arg->mblock_info,
		 (u64)aligned_size, ADDR_ALIGN, ADDR_MAX, 0, "vpu_binary");

	if (!mblock || !overlap) {
		LOG_CRI("vpu memory allocation failed.\n");
		ret = -ENOMEM;
		goto exit;
	}

	memset((void *)(mblock), 0, mblock_size);

	alg_offset = img->dsp_num * DSP_BOOT_SZ;
	iram_off = alg_offset + img->total_alg_sz;
	offset = mblock_size - img->hdr_size - extra_size;
	head_dst = mblock + offset;
	pre_dst = ALIGN(mblock + mblock_size, ALIGN_64K) - extra_size;

	LOG_INF("lk ver: %x\n", VERSION);
	LOG_INF("mblk:[0x%x:0x%x] | head:0x%x | alg: 0x%x | pre: 0x%x\n",
		mblock, mblock_size, head_dst, mblock + alg_offset,
		pre_dst);

	pIramNum  = (u32 *)(mblock + iram_off);
	*pIramNum = 0;
	pIramNum  = (u32 *)(mblock + iram_off + IRAM_SEG_SZ);
	*pIramNum = 0;
	pIramNum  = (u32 *)(mblock + iram_off + (IRAM_SEG_SZ << 1));
	*pIramNum = 0;

	num = img->total_num;

	memset(&params, 0, sizeof(struct install_params));
	memset(&prop, 0, sizeof(struct prop_params));
	overlap[0] = 1;
	params.mblock = mblock;
	params.iram_off = iram_off;
	params.pre_dst = pre_dst;
	params.alg_dst = mblock + alg_offset;
	params.overlap = overlap;

	memset(&prop, 0, sizeof(struct prop_params));

	prop.dsp_num = img->dsp_num;
	prop.iram_off = iram_off;
	prop.alg_offset = alg_offset;
	prop.total_alg_sz = img->total_alg_sz;
	prop.mblock = mblock;
	prop.aligned_size = aligned_size;
	prop.head_offset = offset;
	prop.preload_offset = pre_dst - mblock;

	if ((ret = set_property(&prop)) < 0)
		goto exit;

	for (i = 0 ; i < num ; i++) {
		params.img_max = img[i].img_max;
		params.name = img[i].name;
		head = params.part_hdr = img[i].head;

		LOG_INF("%s| v:%x str:%s sz:0x%x/0x%x s:%d a:%d v:%d\n",
			params.name, head->version, (char *)head->hdr_str,
			head->hdr_size, head->mem_size, head->segment_num,
			head->alg_num, head->pre_num);

		if ((ret = install_main(&params)))
			goto exit;

		if ((ret = install_preload(&params)))
			goto exit;

		if ((ret = install_algo(&params)))
			goto exit;

		LOG_INF("copy %s header(0x%X) to 0x%x\n",
			params.name, head->hdr_size, head_dst);
		memcpy((void *)head_dst, head, head->hdr_size);
		head_dst += head->hdr_size;
	}

	if (overlap[0] - 1) {
		if (check_overlap(&overlap[1], overlap[0] - 1))
			LOG_CRI("preload overlap\n");
	}
exit:
	if (img)
		free(img);
	if (overlap)
		free(overlap);

	return ret;
}

