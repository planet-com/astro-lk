/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2019. All rights reserved.
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
#include <assert.h>
#include <platform/mt_gpt.h>
#include <platform/mt_emi_mpu.h>
#include <mtk_secure_api.h>
#include <debug.h>
#define MODULE_NAME "LK_LD_MD"
#include "ccci_ld_md_core.h"
#include "ccci_ld_md_errno.h"
#include "plat_atf_sec_call.h"

#define CCCI_USE_DFD_OFFSET_0

#ifdef CCCI_USE_DFD_OFFSET_0
#include <libfdt.h>
#include <fdt_op.h>
#include <dfd.h>
extern const struct plt_cfg_dfd cfg_dfd;
#endif

int md_sib_rw_remapping(unsigned long long addr);

#ifdef MTK_DFD_ENABLE_CACHE_DUMP
#define CCCI_SMEM_SIZE_DFD (8*1024*1024)
#else
#define CCCI_SMEM_SIZE_DFD (448*1024)
#endif

#define CCCI_SMEM_SIZE_UDC_NONCACHE (25536*1024)
#define CCCI_SMEM_SIZE_UDC_CACHE (512*1024)
#define CCCI_SMEM_WIFI_MD_PROXY (32*1024)
#define CCCI_SMEM_SIZE_CCB_DHL (2*1024*1024)
#define CCCI_SMEM_SIZE_RAW_DHL (62*1024*1024)
#define CCCI_SMEM_SIZE_LWA (0) // (8*1024*1024)
#define CCB_DATA_BUF_SIZE (CCCI_SMEM_SIZE_CCB_DHL + CCCI_SMEM_SIZE_RAW_DHL)
#define CACHABLE_SMEM_MAX_SIZE     (128*1024*1024)
#define CCB_DATA_BUF_DEFAULT_GEAR  12 /* NOTE: This value may be different at different platform */

/***************************************************************************************************
** Feature Option setting part
***************************************************************************************************/
#define ENABLE_EMI_PROTECTION
#define MPU_REGION_CONSYS_EN

#define CCCI_SECURE_RET_VALUE_LK 0xfffffffffffffff1

/*------------------------------------------------------------------------------------------------*/
/* Suppor function for share memory calculate */
/*------------------------------------------------------------------------------------------------*/
/* copy from kernel */
enum SMEM_USER_ID {
	/* this should remain to be 0 for backward compatibility */
	SMEM_USER_RAW_DBM = 0,

	/* sequence in CCB users matters, must align with ccb_configs[]  */
	SMEM_USER_CCB_START,
	SMEM_USER_CCB_DHL = SMEM_USER_CCB_START,
	SMEM_USER_CCB_MD_MONITOR,
	SMEM_USER_CCB_META,
	SMEM_USER_CCB_END = SMEM_USER_CCB_META,

	/* squence of other users does not matter */
	SMEM_USER_RAW_CCB_CTRL,
	SMEM_USER_RAW_DHL,
	SMEM_USER_RAW_MDM,
	SMEM_USER_RAW_NETD,
	SMEM_USER_RAW_USB,
	SMEM_USER_RAW_AUDIO,
	SMEM_USER_RAW_DFD,
	SMEM_USER_RAW_LWA,
	SMEM_USER_RAW_MDCCCI_DBG,
	SMEM_USER_RAW_MDSS_DBG,
	SMEM_USER_RAW_RUNTIME_DATA,
	SMEM_USER_RAW_FORCE_ASSERT,
	SMEM_USER_CCISM_SCP,
	SMEM_USER_RAW_MD2MD,
	SMEM_USER_RAW_RESERVED,
	SMEM_USER_CCISM_MCU,
	SMEM_USER_CCISM_MCU_EXP,
	SMEM_USER_SMART_LOGGING,
	SMEM_USER_RAW_MD_CONSYS,
	SMEM_USER_RAW_PHY_CAP,
	SMEM_USER_RAW_USIP,
	SMEM_USER_RESV_0,// Sync to MT6779 SMEM_USER_MAX_K,
	SMEM_USER_ALIGN_PADDING, // Sync to MT6779 SMEM_USER_NON_PADDING
	SMEM_USER_RAW_UDC_DATA,
	SMEM_USER_RAW_UDC_DESCTAB,
	SMEM_USER_RAW_AMMS_POS,
	SMEM_USER_RAW_AMMS_ALIGN_PADDING,
	SMEM_USER_MD_WIFI_PROXY,
	SMEM_USER_MD_NVRAM_CACHE,
	SMEM_USER_LAST, /* Make sure USER ID sync with Kernel before SMEM_USER_LAST */
	/* Note, if you add more user, please update the followig table: smem_align_ref[] */
};

static const unsigned int smem_align_ref[SMEM_USER_LAST] = {
	0, /* SMEM_USER_RAW_DBM */
	1024*1024, /* SMEM_USER_CCB_DHL */
	0, /* SMEM_USER_CCB_MD_MONITOR */
	0, /* SMEM_USER_CCB_META */
	0, /* SMEM_USER_RAW_CCB_CTRL */
	0, /* SMEM_USER_RAW_DHL */
	0, /* SMEM_USER_RAW_MDM */
	0, /* SMEM_USER_RAW_NETD */
	0, /* SMEM_USER_RAW_USB */
	0, /* SMEM_USER_RAW_AUDIO */
	16*1024*1024, /* SMEM_USER_RAW_DFD 97 */
	0, /* SMEM_USER_RAW_LWA */
	0, /* SMEM_USER_RAW_MDCCCI_DBG */
	0, /* SMEM_USER_RAW_MDSS_DBG */
	0, /* SMEM_USER_RAW_RUNTIME_DATA */
	0, /* SMEM_USER_RAW_FORCE_ASSERT */
	0, /* SMEM_USER_CCISM_SCP */
	0, /* SMEM_USER_RAW_MD2MD */
	0, /* SMEM_USER_RAW_RESERVED */
	0, /* SMEM_USER_CCISM_MCU */
	0, /* SMEM_USER_CCISM_MCU_EXP */
	0, /* SMEM_USER_SMART_LOGGING */
	64*1024, /* SMEM_USER_RAW_MD_CONSYS */
	0, /* SMEM_USER_RAW_PHY_CAP */
	128, /* SMEM_USER_RAW_USIP */
	0, /* SMEM_USER_RESV_0 */
	0, /* SMEM_USER_ALIGN_PADDING */
	4*1024, /* SMEM_USER_RAW_UDC_DATA */
	4*1024, /* SMEM_USER_RAW_UDC_DESCTAB */
	64*1024, /* SMEM_USER_RAW_AMMS_POS */
	0, /* SMEM_USER_RAW_AMMS_ALIGN_PADDING */
	0, /* SMEM_USER_MD_WIFI_PROXY */
	64, /* SMEM_USER_MD_NVRAM_CACHE */
};

static unsigned int get_align_ref(unsigned int id)
{
	if (id >= SMEM_USER_LAST)
		return 0;

	return smem_align_ref[id];
}

static unsigned int get_align_sz(unsigned int val, unsigned int align)
{
	unsigned int tmp;

	tmp = val;
	return ((val + align - 1) & (~(align - 1))) - tmp;
}

static unsigned int get_align_sz_by_user(unsigned int val, enum SMEM_USER_ID user)
{
	unsigned int align;

	align = get_align_ref(user);
	if (!align)
		return 0;

	return get_align_sz(val, align);
}


/*---------------------------------------------------------------------------------------------------*/
/* Global variable for share memory                                                                  */
/*---------------------------------------------------------------------------------------------------*/
static unsigned int ap_md1_smem_size_at_img;
static unsigned int amms_pos_size_at_img;
static unsigned int consys_size_at_img;
static unsigned int udc_support_at_img;
static unsigned int nv_cache_shm_size_at_img;

static unsigned int amms_pos_offset;

#define AP_MD1_SMEM_SIZE    0x100000
#define MAX_SMEM_SIZE       0x10000000 //history: 6M-->256M-->64M-->256M


typedef struct _smem_layout {
	unsigned long long base_addr;
	unsigned int ap_md1_smem_offset;
	/* ap_md1_smem_size: this is for MD MPU, not total ap_md1 share size. */
	unsigned int ap_md1_smem_size;
	unsigned int ap_md3_smem_offset;
	unsigned int ap_md3_smem_size;
	unsigned int md1_md3_smem_offset;
	unsigned int md1_md3_smem_size;
	unsigned int total_smem_size;
} smem_layout_t;
static smem_layout_t smem_info;


typedef struct _ccb_layout {
	unsigned long long ccb_data_buffer_addr;
	unsigned int ccb_data_buffer_size;
} ccb_layout_t;
static ccb_layout_t ccb_info;


typedef struct _nc_smem_node {
	unsigned int ap_offset;
	unsigned int md_offset;
	unsigned int size;
	unsigned int id;
} nc_smem_node;
static nc_smem_node nc_smem_info_ext[] = {
	{0, 0, 0, SMEM_USER_RAW_UDC_DATA},
	{0, 0, 0, SMEM_USER_MD_WIFI_PROXY},
	{0, 0, 0, SMEM_USER_RAW_DFD},
};
static void update_nc_smem_info(unsigned int id, unsigned int ap, unsigned int md, unsigned int size)
{
	unsigned int i;

	for (i = 0; i < sizeof(nc_smem_info_ext)/sizeof(nc_smem_node); i++) {
		if (nc_smem_info_ext[i].id == id) {
			nc_smem_info_ext[i].ap_offset = ap;
			nc_smem_info_ext[i].md_offset = md;
			nc_smem_info_ext[i].size = size;
			return;
		}
	}
	ALWAYS_LOG("un-support NC smem user id:%d\n", id);
	assert(0);
}

static void add_nc_smem_to_tag_inf(void)
{
	unsigned int num = sizeof(nc_smem_info_ext)/sizeof(nc_smem_node);

	if (insert_ccci_tag_inf("nc_smem_info_ext",
				(char*)nc_smem_info_ext, sizeof(nc_smem_info_ext)) < 0) {
		ALWAYS_LOG("insert nc_smem_info_ext fail\n");
		return;
	}
	if (insert_ccci_tag_inf("nc_smem_info_ext_num",
				(char*)&num, sizeof(int)) < 0)
		ALWAYS_LOG("insert nc_smem_info_ext_num fail\n");
}


static int get_nc_smem_info(unsigned int id, unsigned int *ap, unsigned int *md, unsigned int *size)
{
	unsigned int i;

	for (i = 0; i < sizeof(nc_smem_info_ext)/sizeof(nc_smem_node); i++) {
		if (nc_smem_info_ext[i].id == id) {
			*ap = nc_smem_info_ext[i].ap_offset;
			*md = nc_smem_info_ext[i].md_offset;
			*size = nc_smem_info_ext[i].size;
			return 0;
		}
	}

	ALWAYS_LOG("un-support NC smem user id:%d for get\n", id);
	return -1;
}


typedef struct _csmem_item {
	unsigned long long csmem_buffer_addr;
	unsigned int md_offset;
	unsigned int csmem_buffer_size;
	unsigned int item_cnt;
} csmem_item_t;
static csmem_item_t csmem_info;


#if WITH_GZ_MD_SHAREMEM
extern BOOT_ARGUMENT *g_boot_arg;
#endif

void plat_md_bank4_amms_pos_notify_secure(unsigned long ap_view_addr,
	unsigned long md_view_addr, unsigned long length)
{
	unsigned long addr_get,length_get;
	mt_secure_call(MTK_SIP_LK_AMMS_MD_POS_ADDR_AARCH32, ap_view_addr, 0, 0, 0);
	addr_get = mt_secure_call(MTK_SIP_LK_AMMS_GET_MD_POS_ADDR_AARCH32, 0, 0, 0, 0);
	mt_secure_call(MTK_SIP_LK_AMMS_MD_POS_MD_VIEW_ADDR_AARCH32, md_view_addr, 0, 0, 0);
	mt_secure_call(MTK_SIP_LK_AMMS_MD_POS_LENGTH_AARCH32, length, 0, 0, 0);
	length_get = mt_secure_call(MTK_SIP_LK_AMMS_GET_MD_POS_LENGTH_AARCH32, 0, 0, 0, 0);
	ALWAYS_LOG("mt_secure_call: set_pos_addr = 0x%lx(0x%lx), get_pos_addr = 0x%lx length=0x%lx get_length=0x%lx\n",
		ap_view_addr, md_view_addr, addr_get, length, length_get);
}

void plat_amms_pos_notify_secure(void *addr)
{
	/* notify other user, such as ATF */
	if (amms_pos_size_at_img)
		plat_md_bank4_amms_pos_notify_secure(
			(unsigned long)(addr + amms_pos_offset),
			0x40000000 + amms_pos_offset, amms_pos_size_at_img);
}


typedef struct _sib_item {
	unsigned long long md1_sib_addr;
	unsigned int md1_sib_size;
} sib_item_t;

#ifdef ENABLE_EMI_PROTECTION
static void md_sib_mpu_set(sib_item_t *sib_cfg);
#endif

static void sib_memory_init(void)
{
	unsigned int sib_size;
	sib_item_t sib_info;

	/* sib part */
	memset(&sib_info, 0, sizeof(sib_item_t));
	sib_size = str2uint(get_env("md1_phy_cap_gear"));
	ALWAYS_LOG("env[sib_size]%x.\n", sib_size);
	sib_info.md1_sib_size = sib_size * 1024 * 1024;
	if (sib_info.md1_sib_size > 0x60000000)
		sib_info.md1_sib_size = 0x60000000;
	if (sib_info.md1_sib_size) {
		sib_info.md1_sib_addr = resv_sib_named_memory("md1_sib_mem", sib_info.md1_sib_size);
		ALWAYS_LOG("md1_sib_addr = 0x%llx\n", sib_info.md1_sib_addr);
		if (sib_info.md1_sib_addr == NULL) {
			ALWAYS_LOG("allocate MD phy capture memory fail\n");
			return;
		} else
			md_sib_rw_remapping(sib_info.md1_sib_addr);
	} else {
		ALWAYS_LOG("MD phy capture memory size is 0\n");
		return;
	}

	if (insert_ccci_tag_inf("md1_sib_info", (char*)&sib_info,
	                        sizeof(sib_info)) < 0)
		ALWAYS_LOG("insert md1_sib_addr fail\n");
#ifdef ENABLE_EMI_PROTECTION
	md_sib_mpu_set(&sib_info);
#endif
}

#ifdef CCCI_USE_DFD_OFFSET_0
static int get_dfd_size_from_dts(unsigned int *dfd_size)
{
	int nodeoffset;
	unsigned int *data = NULL;
	int len = 0;
	int dfd_enabled;
	char *node_1 = "mediatek,dfd_cache";
	char *node_2 = "mediatek,enabled";
	void *kernel_fdt = get_kernel_fdt();

	if (kernel_fdt == NULL) {
		ALWAYS_LOG("[%s] error: kernel fdt is NULL!\n", __func__);
		return -1;
	}

	nodeoffset = fdt_node_offset_by_compatible(kernel_fdt, -1, node_1);
	if (nodeoffset < 0) {
		ALWAYS_LOG("[%s] error: '%s' not found!\n", __func__, node_1);
		return -1;
	}

	data = (unsigned int *)fdt_getprop(kernel_fdt,
			nodeoffset, node_2, &len);
	if (data == NULL) {
		ALWAYS_LOG("[%s] error: get '%s' fail.\n", __func__, node_2);
		return -1;
	}

	dfd_enabled =  fdt32_to_cpu(*(unsigned int *)data);

	if (dfd_enabled)
		*dfd_size = cfg_dfd.large_buffer_length;
	else
		*dfd_size = cfg_dfd.buffer_length;

	ALWAYS_LOG("[%s] DFD dfd_enabled = %d, len = %d, dfd_size = %u\n",
			__func__, dfd_enabled, len, *dfd_size);

	return 0;
}

static int cal_nc_share_mem_size(void)
{
	unsigned int align_sz, nc_size, offset, size;

	sib_memory_init(); /* Alloc large size memory, at 1st */
	/* MD Share memory layout */
	/*    AP    <-->   MD1    */
	smem_info.ap_md1_smem_offset = 0;
	smem_info.md1_md3_smem_offset = 0;
	smem_info.ap_md3_smem_offset = 0;
	smem_info.md1_md3_smem_size = 0;
	smem_info.ap_md3_smem_size = 0;

	nc_size = 0;

	/* DFD */
	if (get_dfd_size_from_dts(&size) < 0)
		size = CCCI_SMEM_SIZE_DFD;

	align_sz = get_align_sz_by_user(nc_size, SMEM_USER_RAW_DFD);
	ALWAYS_LOG("[NC] align size for DFD: 0x%x\n", align_sz);
	nc_size += align_sz;
	offset = nc_size;
	nc_size += size;
	ALWAYS_LOG("[NC] block: DFD: 0x%x(0x%x)<0x%x>\n", offset, size, nc_size);
	update_nc_smem_info(SMEM_USER_RAW_DFD, offset, offset, size);

	/* UDC */
	if (udc_support_at_img) {
		size = CCCI_SMEM_SIZE_UDC_NONCACHE;
		align_sz = get_align_sz_by_user(nc_size, SMEM_USER_RAW_UDC_DATA);
		ALWAYS_LOG("[NC] align size for UDC: 0x%x\n", align_sz);
		nc_size += align_sz;
		offset = nc_size;
		nc_size += size;
		ALWAYS_LOG("[NC] block: UDC: 0x%x(0x%x)<0x%x>\n", offset, size, nc_size);
		update_nc_smem_info(SMEM_USER_RAW_UDC_DATA, offset, offset, size);
	}

	/* WIFI Proxy */
	size = CCCI_SMEM_WIFI_MD_PROXY;
	align_sz = get_align_sz_by_user(nc_size, SMEM_USER_MD_WIFI_PROXY);
	ALWAYS_LOG("[NC] align size for WIFI Proxy: 0x%x\n", align_sz);
	nc_size += align_sz;
	offset = nc_size;
	nc_size += size;
	ALWAYS_LOG("[NC] block: WIFI proxy: 0x%x(0x%x)<0x%x>\n", offset, size, nc_size);
	update_nc_smem_info(SMEM_USER_MD_WIFI_PROXY, offset, offset, size);

	/* AMMS POS */
	if (amms_pos_size_at_img) {
		align_sz = get_align_sz_by_user(nc_size, SMEM_USER_RAW_AMMS_POS);
		ALWAYS_LOG("[NC] align size for AMMS POS: 0x%x\n", align_sz);
		nc_size += align_sz;
		amms_pos_offset = nc_size;
		align_sz = (nc_size + 0x400000 -1)&(~(0x400000 -1));
		align_sz -= nc_size;
		ALWAYS_LOG("[NC] align size for AMMS POS(4M): 0x%x\n", align_sz);
		amms_pos_size_at_img += align_sz;
		nc_size += amms_pos_size_at_img;
		/*pass AMMS POS size to Kernel*/
		if (insert_ccci_tag_inf("smem_amms_pos_size",
			(char*)&amms_pos_size_at_img, sizeof(int)) < 0)
			ALWAYS_LOG("insert amms_pos_size fail\n");
		ALWAYS_LOG("amms_pos_size: 0x%x\n", amms_pos_size_at_img);
	}

	/* AP/MD CCCI */
	offset = nc_size;
	size = AP_MD1_SMEM_SIZE;
	nc_size += size;
	ALWAYS_LOG("[NC] block: AP/MD CCCI: 0x%x(0x%x)<0x%x>\n", offset, size, nc_size);

	align_sz = get_align_sz(nc_size, 0x10000); /* 64K align */
	ALWAYS_LOG("[NC] align size for final: 0x%x\n", align_sz);
	nc_size += align_sz;
	smem_info.ap_md1_smem_size = nc_size;
	/* total_smem_size: in factly, this is for MD MPU, not ap-md share total size. */
	smem_info.total_smem_size = nc_size;

	ALWAYS_LOG("smem_info.ap_md1_smem_offset: %x\n", smem_info.ap_md1_smem_offset);
	ALWAYS_LOG("smem_info.ap_md1_smem_size: %x\n", smem_info.ap_md1_smem_size);
	ALWAYS_LOG("smem_info.ap_md3_smem_offset: %x\n", smem_info.ap_md3_smem_offset);
	ALWAYS_LOG("smem_info.ap_md3_smem_size: %x\n", smem_info.ap_md3_smem_size);
	ALWAYS_LOG("smem_info.md1_md3_smem_offset: %x\n", smem_info.md1_md3_smem_offset);
	ALWAYS_LOG("smem_info.md1_md3_smem_size: %x\n", smem_info.md1_md3_smem_size);
	ALWAYS_LOG("smem_info.total_smem_size: %x\n", smem_info.total_smem_size);
	ALWAYS_LOG("amms_pos_offset: %x\n", amms_pos_offset);

	add_nc_smem_to_tag_inf();

	return (int)smem_info.total_smem_size; /* non-cacheable */
}
#else
static int cal_nc_share_mem_size(void)
{
	unsigned int align_sz, nc_size, offset, size;

	sib_memory_init(); /* Alloc large size memory, at 1st */
	/* MD Share memory layout */
	/*    AP    <-->   MD1    */
	smem_info.ap_md1_smem_offset = 0;
	smem_info.md1_md3_smem_offset = 0;
	smem_info.ap_md3_smem_offset = 0;
	smem_info.md1_md3_smem_size = 0;
	smem_info.ap_md3_smem_size = 0;

	nc_size = 0;

	/* AP/MD CCCI */
	offset = 0;
	size = AP_MD1_SMEM_SIZE;
	nc_size += size;
	ALWAYS_LOG("[NC] block: AP/MD CCCI: 0x%x(0x%x)<0x%x>\n", offset, size, nc_size);

	/* UDC */
	if (udc_support_at_img) {
		size = CCCI_SMEM_SIZE_UDC_NONCACHE;
		align_sz = get_align_sz_by_user(nc_size, SMEM_USER_RAW_UDC_DATA);
		ALWAYS_LOG("[NC] align size for UDC: 0x%x\n", align_sz);
		nc_size += align_sz;
		offset = nc_size;
		nc_size += size;
		ALWAYS_LOG("[NC] block: UDC: 0x%x(0x%x)<0x%x>\n", offset, size, nc_size);
		update_nc_smem_info(SMEM_USER_RAW_UDC_DATA, offset, offset, size);
	}

	/* WIFI Proxy */
	size = CCCI_SMEM_WIFI_MD_PROXY;
	align_sz = get_align_sz_by_user(nc_size, SMEM_USER_MD_WIFI_PROXY);
	ALWAYS_LOG("[NC] align size for WIFI Proxy: 0x%x\n", align_sz);
	nc_size += align_sz;
	offset = nc_size;
	nc_size += size;
	ALWAYS_LOG("[NC] block: WIFI proxy: 0x%x(0x%x)<0x%x>\n", offset, size, nc_size);
	update_nc_smem_info(SMEM_USER_MD_WIFI_PROXY, offset, offset, size);

	/* DFD */
	size = CCCI_SMEM_SIZE_DFD;
	align_sz = get_align_sz_by_user(nc_size, SMEM_USER_RAW_DFD);
	ALWAYS_LOG("[NC] align size for DFD: 0x%x\n", align_sz);
	nc_size += align_sz;
	offset = nc_size;
	nc_size += size;
	ALWAYS_LOG("[NC] block: DFD: 0x%x(0x%x)<0x%x>\n", offset, size, nc_size);
	update_nc_smem_info(SMEM_USER_RAW_DFD, offset, offset, size);

	/* AMMS POS */
	if (amms_pos_size_at_img) {
		align_sz = get_align_sz_by_user(nc_size, SMEM_USER_RAW_AMMS_POS);
		ALWAYS_LOG("[NC] align size for AMMS POS: 0x%x\n", align_sz);
		nc_size += align_sz;
		amms_pos_offset = nc_size;
		align_sz = (nc_size + 0x400000 -1)&(~(0x400000 -1));
		align_sz -= nc_size;
		ALWAYS_LOG("[NC] align size for AMMS POS(4M): 0x%x\n", align_sz);
		amms_pos_size_at_img += align_sz;
		nc_size += amms_pos_size_at_img;
		/*pass AMMS POS size to Kernel*/
		if (insert_ccci_tag_inf("smem_amms_pos_size",
			(char*)&amms_pos_size_at_img, sizeof(int)) < 0)
			ALWAYS_LOG("insert amms_pos_size fail\n");
		ALWAYS_LOG("amms_pos_size: 0x%x\n", amms_pos_size_at_img);
	}

	align_sz = get_align_sz(nc_size, 0x10000); /* 64K align */
	ALWAYS_LOG("[NC] align size for final: 0x%x\n", align_sz);
	nc_size += align_sz;
	smem_info.ap_md1_smem_size = nc_size;
	/* total_smem_size: in factly, this is for MD MPU, not ap-md share total size. */
	smem_info.total_smem_size = nc_size;

	ALWAYS_LOG("smem_info.ap_md1_smem_offset: %x\n", smem_info.ap_md1_smem_offset);
	ALWAYS_LOG("smem_info.ap_md1_smem_size: %x\n", smem_info.ap_md1_smem_size);
	ALWAYS_LOG("smem_info.ap_md3_smem_offset: %x\n", smem_info.ap_md3_smem_offset);
	ALWAYS_LOG("smem_info.ap_md3_smem_size: %x\n", smem_info.ap_md3_smem_size);
	ALWAYS_LOG("smem_info.md1_md3_smem_offset: %x\n", smem_info.md1_md3_smem_offset);
	ALWAYS_LOG("smem_info.md1_md3_smem_size: %x\n", smem_info.md1_md3_smem_size);
	ALWAYS_LOG("smem_info.total_smem_size: %x\n", smem_info.total_smem_size);
	ALWAYS_LOG("amms_pos_offset: %x\n", amms_pos_offset);

	add_nc_smem_to_tag_inf();

	return (int)smem_info.total_smem_size; /* non-cacheable */
}
#endif

#define SMEM_MD_CONSYS_SIZE		(43*1024*1024)
#define SMEM_MD_NVRAM_CACHE_SIZE	(18*1024*1024) /* LID */
#define SMEM_MD_USIP_SIZE		(384*1024) /* Audio */


static csmem_item_t csmem_layout[] = {
{0, 0, SMEM_MD_CONSYS_SIZE,	 SMEM_USER_RAW_MD_CONSYS},
{0, 0, SMEM_MD_NVRAM_CACHE_SIZE, SMEM_USER_MD_NVRAM_CACHE},
{0, 0, (22*1024*1024),		 SMEM_USER_CCB_START},
{0, 0, 0,			 SMEM_USER_RAW_UDC_DESCTAB},
{0, 0, SMEM_MD_USIP_SIZE,	 SMEM_USER_RAW_USIP}, /* audio */
};


/* Dynamic CCB seciton */
struct ccb_gear_id_mapping {
	unsigned int gear_id;
	unsigned int size;
};

const struct ccb_gear_id_mapping ccb_support_tbl[] = {
	{1,    22 * 1024 * 1024},
	{2,    12 * 1024 * 1024},
	{3,     0 * 1024 * 1024},
	{4,    32 * 1024 * 1024},
	{11,    4 * 1024 * 1024},
	{12,    64 * 1024 * 1024}
};

static unsigned int get_ccb_size_from_gear_id(unsigned int gear_id)
{
	int i;

	for (i = 0; i < (int)(sizeof(ccb_support_tbl)/sizeof(struct ccb_gear_id_mapping)); i++) {
		if (gear_id == ccb_support_tbl[i].gear_id)
			return ccb_support_tbl[i].size;
	}

	return 0xFFFFFFFF;
}

static void set_ccb_gear_val(unsigned int gear_id)
{
	int ret;
	char env_buf[12];

	memset(env_buf, 0, sizeof(env_buf));
	snprintf(env_buf, sizeof(env_buf), "%u", gear_id);
	ret = set_env("md1_ccb_cap_gear", env_buf);
	if (ret < 0) {
		ALWAYS_LOG("set env[md1_ccb_cap_gear]fail, ret=%d\n", ret);
		assert(0);
	} else
		ALWAYS_LOG("set env[md1_ccb_cap_gear]%d\n", gear_id);
}

static unsigned int get_ccb_gear_val(void)
{
	unsigned int md1_ccb_cap_gear;
	unsigned int md1_ccb_size;

	if (g_boot_mode == META_BOOT || true == get_atm_enable_status()) {
		ALWAYS_LOG("meta mode[md1_ccb_cap_gear]%d\n", CCB_DATA_BUF_DEFAULT_GEAR);
		set_ccb_gear_val(CCB_DATA_BUF_DEFAULT_GEAR);
		return CCB_DATA_BUF_DEFAULT_GEAR;
	}
	md1_ccb_cap_gear = str2uint(get_env("md1_ccb_cap_gear"));
	if (md1_ccb_cap_gear != 0) {
		md1_ccb_size = get_ccb_size_from_gear_id(md1_ccb_cap_gear);
		if (md1_ccb_size == 0xFFFFFFFF) {
			ALWAYS_LOG("CCB cfg abnormal!!! un-support ccb gear id: %d\n", md1_ccb_cap_gear);
			assert(0);
		}
		ALWAYS_LOG("get env[md1_ccb_cap_gear]%d\n", md1_ccb_cap_gear);
		return md1_ccb_cap_gear;
	} else {
#ifdef MTK_DYNAMIC_CCB_BUFFER_GEAR_ID
		md1_ccb_cap_gear = MTK_DYNAMIC_CCB_BUFFER_GEAR_ID;
#else
		md1_ccb_cap_gear = CCB_DATA_BUF_DEFAULT_GEAR;
#endif
		set_ccb_gear_val(md1_ccb_cap_gear);
		return md1_ccb_cap_gear;
	}
}

static void set_gear_id_list()
{
	int ret;

	ret = set_env("md1_ccb_gear_list",
		"1(2,20);2(2,10);3(0,0);4(2,30);11(2,2);12(2,62)");

	if (ret) {
		ALWAYS_LOG("set_gear_id_list error: %x\n", ret);
	}
}

static int cal_c_smem_size_and_layout(int load_flag)
{
	unsigned int md1_ccb_cap_gear;
	unsigned int md1_bank4_cache_offset;
	unsigned int md1_ccb_size = CCB_DATA_BUF_SIZE;
	unsigned char * ccb_data_buf = NULL;

	unsigned char *cacheable_buf = NULL;
	unsigned int cacheable_buf_sz = 0;
	unsigned int i;
	unsigned int alignment;
	unsigned int offset;
	unsigned int region_size;
	unsigned int padding_size;

#if WITH_GZ_MD_SHAREMEM
	unsigned int mtee_support = 1;
#endif

	ALWAYS_LOG("smem_info.base_addr: %x\n", (unsigned int)smem_info.base_addr);

	md1_ccb_cap_gear = get_ccb_gear_val();
	md1_ccb_size = get_ccb_size_from_gear_id(md1_ccb_cap_gear);
	set_gear_id_list();
	ALWAYS_LOG("allocate ccb data buffer0x%x\n", md1_ccb_size);
	if (insert_ccci_tag_inf("ccb_gear_id", (char*)&md1_ccb_cap_gear, sizeof(unsigned int)) < 0)
		ALWAYS_LOG("insert ccb_gear_id fail\n");

	/* cacheable MD cacheable share memory layout */
	offset = 0;
	for (i = 0; i < sizeof(csmem_layout)/sizeof(csmem_item_t); i++) {
		/* Runtime update for special */
		switch (csmem_layout[i].item_cnt) {
		case SMEM_USER_RAW_MD_CONSYS:
			csmem_layout[i].csmem_buffer_size = consys_size_at_img;
			ALWAYS_LOG("cal_c_smem_size_and_layout: 0x%x\n", consys_size_at_img);
			break;
		case SMEM_USER_CCB_START:
			csmem_layout[i].csmem_buffer_size = md1_ccb_size;
			break;
		case SMEM_USER_RAW_UDC_DESCTAB:
			if (udc_support_at_img) {
				csmem_layout[i].csmem_buffer_size = CCCI_SMEM_SIZE_UDC_CACHE;
				ALWAYS_LOG("UDC cache size: 0x%x\n", CCCI_SMEM_SIZE_UDC_CACHE);
			}
			break;
		case SMEM_USER_MD_NVRAM_CACHE:
			if (nv_cache_shm_size_at_img) {
				csmem_layout[i].csmem_buffer_size = nv_cache_shm_size_at_img;
				ALWAYS_LOG("NV cache size adjust to: 0x%x\n",
						nv_cache_shm_size_at_img);
			}
			break;
		default:
			break;
		}
		region_size = csmem_layout[i].csmem_buffer_size;
		alignment = get_align_ref(csmem_layout[i].item_cnt);
		if (offset && alignment) {
			padding_size = get_align_sz(offset, alignment);
			if (padding_size) {
				offset += padding_size;
				cacheable_buf_sz += padding_size;
			}
		} else
			padding_size = 0;

		csmem_layout[i].md_offset = offset;
		cacheable_buf_sz += region_size;
		offset += region_size;
	}

	if (cacheable_buf_sz != 0) {
		ALWAYS_LOG("[C] before align: 0x%x\n", cacheable_buf_sz);
		cacheable_buf_sz += get_align_sz(cacheable_buf_sz, 0x10000);
		ALWAYS_LOG("[C] after align: 0x%x\n", cacheable_buf_sz);
		cacheable_buf = ccci_request_mem(cacheable_buf_sz, 0x90000000LL, 0x2000000L);
	}

	if (cacheable_buf_sz == 0) {
		csmem_info.csmem_buffer_addr = 0;
		csmem_info.csmem_buffer_size = 0;
		csmem_info.item_cnt = 0;

		ccb_info.ccb_data_buffer_addr = 0;
		ccb_info.ccb_data_buffer_size = 0;
		ALWAYS_LOG("allocate ccb data buffer share memory fail\n");
	} else {
		csmem_info.csmem_buffer_addr = (unsigned long long)((unsigned long)cacheable_buf);
		csmem_info.md_offset = MAX_SMEM_SIZE - CACHABLE_SMEM_MAX_SIZE;
		csmem_info.csmem_buffer_size = cacheable_buf_sz;
		csmem_info.item_cnt = sizeof(csmem_layout)/sizeof(csmem_item_t);

		ALWAYS_LOG("cache_buffer_addr: %x\n", (unsigned int)csmem_info.csmem_buffer_addr);
		ALWAYS_LOG("cache_buffer_size: %x\n", csmem_info.csmem_buffer_size);
		ALWAYS_LOG("cache_buffer_itm_cnt: %x\n", (unsigned int)csmem_info.item_cnt);

		for (i = 0; i < sizeof(csmem_layout)/sizeof(csmem_item_t); i++) {
			csmem_layout[i].csmem_buffer_addr = (unsigned long long)csmem_layout[i].md_offset
					+ csmem_info.csmem_buffer_addr;
			if (csmem_layout[i].item_cnt == SMEM_USER_CCB_START)
				ccb_data_buf = csmem_layout[i].csmem_buffer_addr;
		}

		if (insert_ccci_tag_inf("md1_bank4_cache_info", (char *)&csmem_info,
			sizeof(csmem_info)) < 0)
			ALWAYS_LOG("insert md1_smem_cahce_info fail\n");
		if (insert_ccci_tag_inf("md1_bank4_cache_layout", (char *)&csmem_layout,
			sizeof(csmem_layout)) < 0)
			ALWAYS_LOG("insert md1_smem_cahce_layout fail\n");

		for (i = 0; i < sizeof(csmem_layout)/sizeof(csmem_item_t); i++) {
			ALWAYS_LOG("cache[%d]_buffer_addr: %x\n", i,
				(unsigned int)csmem_layout[i].csmem_buffer_addr);
			ALWAYS_LOG("cache[%d]_buffer_offset: %x\n", i,
				(unsigned int)csmem_layout[i].md_offset);
			ALWAYS_LOG("cache[%d]_buffer_size: %x\n", i,
				csmem_layout[i].csmem_buffer_size);
		}

		ccb_info.ccb_data_buffer_addr = (unsigned long long)((unsigned long)ccb_data_buf);
		ccb_info.ccb_data_buffer_size = md1_ccb_size;

		/* CCB must in last 2*32M */
		md1_bank4_cache_offset = MAX_SMEM_SIZE - CACHABLE_SMEM_MAX_SIZE;
		if (insert_ccci_tag_inf("md1_smem_cahce_offset", (char*)&md1_bank4_cache_offset,
				sizeof(md1_bank4_cache_offset)) < 0)
			ALWAYS_LOG("insert md1_smem_cahce_offset fail\n");

		if (insert_ccci_tag_inf("ccb_info", (char*)&ccb_info, sizeof(ccb_layout_t)) < 0)
			ALWAYS_LOG("insert ccb_info fail\n");

		ALWAYS_LOG("ccb_info.ccb_data_buffer_addr: %x\n", (unsigned int)ccb_info.ccb_data_buffer_addr);
		ALWAYS_LOG("ccb_info.ccb_data_buffer_size: %x\n", ccb_info.ccb_data_buffer_size);
	}
	/* cacheable memory End */

	ALWAYS_LOG("smem_info.total_smem_size: %x\n", smem_info.total_smem_size);

	/* insert share memory layout to lk info */
	if (insert_ccci_tag_inf("smem_layout", (char*)&smem_info, sizeof(smem_layout_t)) < 0)
		ALWAYS_LOG("insert smem_layout fail\n");

	/* slot 5 */
#if WITH_GZ_MD_SHAREMEM
	if (g_boot_arg->gz_md_shm_pa && g_boot_arg->gz_md_shm_sz) {
		ALWAYS_LOG("mtee.base_addr: 0x%x, 0x%x\n",
			(unsigned int)g_boot_arg->gz_md_shm_pa, g_boot_arg->gz_md_shm_sz);
		if (insert_ccci_tag_inf("mtee_support", (char *)&mtee_support,
				sizeof(mtee_support)) < 0)
			ALWAYS_LOG("insert mtee_support fail\n");
	}
#endif

	return (int)smem_info.total_smem_size;
}

/***************************************************************************************************
** HW remap section
***************************************************************************************************/
extern unsigned int ddr_enable_4gb(void)__attribute__((weak));
static int is_4gb_ddr_support_en(void)
{
	int ret;
	if (ddr_enable_4gb) {
		ret = ddr_enable_4gb();
		ALWAYS_LOG("ddr_enable_4GB sta:%d\n", ret);
		return ret;
	} else {
		ALWAYS_LOG("ddr 4GB disable\n");
		return 0;
	}
}

int md_sib_rw_remapping(unsigned long long addr)
{
	unsigned long long md_sib_start_addr;
	size_t r1, r2, r3;
	size_t ret;

	ALWAYS_LOG("[%s] addr: 0x%llX\n", __func__, addr);

	md_sib_start_addr = addr;
	ret = mt_secure_call_ret4(MTK_SIP_BL_CCCI_CONTROL_AARCH32,
		MD_SIB_HW_REMAP,
		(u32)md_sib_start_addr, (u32)(md_sib_start_addr >> 32), 0,
		&r1, &r2, &r3);

	if (ret == (size_t)CCCI_SECURE_RET_VALUE_LK) {
		ALWAYS_LOG("[%s] error: MD_SIB_HW_REMAP fail: 0x%zX\n", __func__, ret);
		return -1;

	} else {
		ALWAYS_LOG("SIBLOG_BANK_MAP0 value:0x%X\n", r1);
		ALWAYS_LOG("SIBLOG_BANK_MAP1 value:0x%X\n", r2);
		ALWAYS_LOG("SIBLOG_BANK_MAP2 value:0x%X\n", r3);
	}

	return 0;
}

static int md_mem_ro_rw_remapping(unsigned int md_id, unsigned long long addr)
{
	unsigned long long md_img_start_addr;
	size_t ret, r1, r2, r3;

	ALWAYS_LOG("---> Map 0x00000000 to 0x%llx for MD%d\n", addr, md_id+1);
	md_img_start_addr = addr; /* 0M~256M */

	ret = mt_secure_call_ret4(MTK_SIP_BL_CCCI_CONTROL_AARCH32,
		MD_BANK0_HW_REMAP,
		(u32)md_img_start_addr, (u32)(md_img_start_addr >> 32), 0,
		&r1, &r2, &r3);

	if (ret == (size_t)CCCI_SECURE_RET_VALUE_LK) {
		ALWAYS_LOG("[%s] error: MD_BANK0_HW_REMAP fail: 0x%zX\n", __func__, ret);
		return -1;

	} else {
		ALWAYS_LOG("BANK0_MAP0 value:0x%X\n", r1);
		ALWAYS_LOG("BANK0_MAP1 value:0x%X\n", r2);
		ALWAYS_LOG("BANK0_MAP2 value:0x%X\n", r3);
	}
	/* md_img_start_addr = addr + 0x10000000; *//* 256M~512M ATF will add  */
	ret = mt_secure_call_ret4(MTK_SIP_BL_CCCI_CONTROL_AARCH32,
		MD_BANK1_HW_REMAP,
		(u32)md_img_start_addr, (u32)(md_img_start_addr >> 32), 0,
		&r1, &r2, &r3);

	if (ret == (size_t)CCCI_SECURE_RET_VALUE_LK) {
		ALWAYS_LOG("[%s] error: MD_BANK1_HW_REMAP fail: 0x%zX\n", __func__, ret);
		return -1;

	} else {
		ALWAYS_LOG("BANK1_MAP0 value:0x%zX\n", ret);
		ALWAYS_LOG("BANK1_MAP1 value:0x%X\n", r1);
		ALWAYS_LOG("BANK1_MAP2 value:0x%X\n", r2);
		ALWAYS_LOG("BANK1_MAP3 value:0x%X\n", r3);
	}

	return 0;
}


static int md_bank4_remapping_by_slot(unsigned int md_id, unsigned long long addr, int slot)
{
	unsigned long long md_smem_start_addr;
	size_t ret, r1;

	ALWAYS_LOG("[%s] addr: 0x%llX\n", __func__, addr);
	md_smem_start_addr = addr;

	ret = mt_secure_call_ret2(MTK_SIP_BL_CCCI_CONTROL_AARCH32,
		MD_BANK4_HW_REMAP,
		(u32)md_smem_start_addr, (u32)(md_smem_start_addr >> 32), (size_t)slot,
		&r1);

	if (ret == (size_t)CCCI_SECURE_RET_VALUE_LK) {
		ALWAYS_LOG("[%s] error: MD_BANK4_HW_REMAP fail: 0x%zX\n", __func__, ret);
		return -1;

	} else
		ALWAYS_LOG("BANK4_MAP(%d) value:0x%X\n", slot, r1);

	return 0;
}

static int md_smem_rw_remapping(unsigned int md_id, unsigned long long addr)
{
	unsigned int i, csmem_32M_cnt;
	ALWAYS_LOG("---> Map 0x40000000 to 0x%llx for MD%d\n", addr, md_id+1);
	csmem_32M_cnt =  8 - CACHABLE_SMEM_MAX_SIZE/(32*1024*1024);

	for (i = 0; i < csmem_32M_cnt; i++)
		md_bank4_remapping_by_slot(md_id, addr + 0x2000000*i, i);
#if WITH_GZ_MD_SHAREMEM
	if (g_boot_arg->gz_md_shm_pa && g_boot_arg->gz_md_shm_sz) {
		md_bank4_remapping_by_slot(MD_SYS1, g_boot_arg->gz_md_shm_pa, 5);
	}
#endif
	/* remapping cacheable to last 2*32M in bank4 */
	ALWAYS_LOG("---> Map 0x40000000+0x%x to 0x%llx for MD%d\n", csmem_info.md_offset,
		csmem_info.csmem_buffer_addr, md_id+1);
	for (i = csmem_32M_cnt; i < 8; i++)
		md_bank4_remapping_by_slot(md_id,
			csmem_info.csmem_buffer_addr + 0x2000000*(unsigned long long)(i-csmem_32M_cnt), i);

	return 0;
}

/* =================================================== */
/* MPU Region defination                               */
/* =================================================== */
/* Note: This structure should sync with Kernel!!!!    */
typedef unsigned long long mpu_att_t;

typedef struct _mpu_cfg {
	unsigned int start;
	unsigned int end;
	int region;
	unsigned int permission[EMI_MPU_DGROUP_NUM];
	int relate_region;
} mpu_cfg_t;

#define MPU_REGION_ID_MD1_ROM           10
#define MPU_REGION_ID_MD_DSP1           11 /*DSP RO*/
#define MPU_REGION_ID_MD_DSP2           12 /*DSP RW*/
#define MPU_REGION_ID_MD_DRDI           13
#define MPU_REGION_ID_MD1_MCURW_HWRW    14
#define MPU_REGION_ID_MD1_MCURW_HWRO    15
#define MPU_REGION_ID_MD1_MCURO_HWRW    16
#define MPU_REGION_ID_MD1_TRACE_TOP     17

#define MPU_REGION_ID_PADDING1          22
#define MPU_REGION_ID_MD_CONSYS         23
#define MPU_REGION_ID_MD1_C_SMEM        24  /* AP/MD SHM C */
#define MPU_REGION_ID_MD1_NC_SMEM       25  /* AP/MD SHM UC */

#define MPU_REGION_ID_AP                31
#define MPU_REGION_ID_TOTAL_NUM         (MPU_REGION_ID_AP + 1)

#define MPU_MDOMAIN_ID_AP           0
#define MPU_MDOMAIN_ID_MD1          1
#define MPU_MDOMAIN_ID_MDHW         7
#define MPU_MDOMAIN_ID_TOTAL_NUM    16

static const mpu_att_t mpu_att_default[MPU_REGION_ID_TOTAL_NUM][MPU_MDOMAIN_ID_TOTAL_NUM] = {
	/*===================================================================================================================*/
	/* No |  | D0(AP)    | D1(MD1)      | D2(CONN) | D3(SCP)  | D4(MM)       | D5(Rsv )      | D6(MFG)      | D7(MDHW)
		|D8(SSPM)	|D9(SPM) 	|D10(ADSP)   | D11-15(Rsv) */
	/*--------------+-----------------------------------------------------------------------------------------------------------------------*/
	/* 0*/{}, /*Secure OS*/
	/* 1*/{}, /*ATF*/
	/* 2*/{}, /*Secure Memory*/
	/* 3*/{}, /*Tinysys-SSPM ROM*/
	/* 4*/{}, /*Tinysys-SSPM share buffer*/
	/* 5*/{}, /*Tinysys-SCP ROM*/
	/* 6*/{}, /*Tinysys-SCP share buffer*/
	/* 7*/{}, /*Trusted UI*/
	/* 8*/{}, /*AMMS*/
	/* 9*/{}, /*AMMS*/
	/*10*/{ SEC_R_NSEC_R,   SEC_R_NSEC_R,  [2 ... 6] = FORBIDDEN, SEC_R_NSEC_R,     [8 ... 15] = FORBIDDEN},
	/*11*/{ SEC_R_NSEC_R,   SEC_R_NSEC_R,  [2 ... 6] = FORBIDDEN, SEC_R_NSEC_R,     [8 ... 15] = FORBIDDEN},
	/*12*/{ SEC_R_NSEC_R,   NO_PROTECTION, [2 ... 6] = FORBIDDEN, NO_PROTECTION,    [8 ... 15] = FORBIDDEN},
	/*13*/{ SEC_R_NSEC_R,   SEC_R_NSEC_R,  [2 ... 6] = FORBIDDEN, SEC_R_NSEC_R,     [8 ... 15] = FORBIDDEN}, /*DRDI*/
	/*14*/{ SEC_R_NSEC_R,   NO_PROTECTION, [2 ... 6] = FORBIDDEN, NO_PROTECTION,    [8 ... 15] = FORBIDDEN},
	/*15*/{ SEC_R_NSEC_R,   NO_PROTECTION, [2 ... 6] = FORBIDDEN, SEC_R_NSEC_R,     [8 ... 15] = FORBIDDEN},
	/*16*/{ SEC_R_NSEC_R,   SEC_R_NSEC_R,  [2 ... 6] = FORBIDDEN, NO_PROTECTION,    [8 ... 15] = FORBIDDEN},
	/*17*/{ SEC_R_NSEC_R,   [1 ... 6] = FORBIDDEN,                NO_PROTECTION,    [8 ... 15] = FORBIDDEN}, /*MD trace_top*/
	/*18*/{},
	/*19*/{},
	/*20*/{},
	/*21*/{}, /*VPU*/
	/*22*/{}, /* Padding */
	/*23*/{ SEC_R_NSEC_R,   NO_PROTECTION, NO_PROTECTION, [3 ... 6] = FORBIDDEN, NO_PROTECTION,    [8 ... 15] = FORBIDDEN}, /* WIFI Driver */
	/*24*/{ NO_PROTECTION,  NO_PROTECTION,  [2 ... 6] = FORBIDDEN, NO_PROTECTION, FORBIDDEN, FORBIDDEN,
		NO_PROTECTION, [11 ... 15] = FORBIDDEN},
	/*25*/{ NO_PROTECTION,  NO_PROTECTION, FORBIDDEN, NO_PROTECTION,[4 ... 6] = FORBIDDEN, NO_PROTECTION,
		[8 ... 15] = FORBIDDEN},
	/*26*/{}, /*WIFI EMI FW*/
	/*27*/{}, /*WMT*/
	/*28*/{}, /*ADSP*/
	/*29*/{}, /*GPS offload*/
	/*30*/{}, /*Set in LK MD dynamic*/
	/*31*/{}, /* no need setting */
};

#define MPU_STR_BUF_SIZE	64

static void get_mpu_attr_str(int lock, unsigned int apc[EMI_MPU_DGROUP_NUM], char buf[], int size)
{
	unsigned long long curr_attr;
	char ch = lock?'L':'U';

	if (EMI_MPU_DGROUP_NUM != 2) {
		ALWAYS_LOG("[error]abnormal mpu domain group number %d\n", EMI_MPU_DGROUP_NUM);
		return;
	}
	curr_attr = ((unsigned long long)apc[1] << 32) | apc[0];
	snprintf(buf, size, "%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld-%lld(%c)",
	         curr_attr&7, (curr_attr>>3)&7, (curr_attr>>6)&7, (curr_attr>>9)&7,
	         (curr_attr>>12)&7, (curr_attr>>15)&7, (curr_attr>>18)&7, (curr_attr>>21)&7,
	         (curr_attr>>32)&7, (curr_attr>>35)&7, (curr_attr>>38)&7, (curr_attr>>41)&7,
	         (curr_attr>>44)&7, (curr_attr>>47)&7, (curr_attr>>50)&7, (curr_attr>>53)&7, ch);
}

static const unsigned char region_mapping_at_hdr_md1[] = {
	MPU_REGION_ID_MD1_ROM, MPU_REGION_ID_MD1_MCURO_HWRW, MPU_REGION_ID_MD1_MCURW_HWRO,
	MPU_REGION_ID_MD1_MCURW_HWRW
};

static const int free_mpu_region[] = {MPU_REGION_ID_PADDING1, -1, -1};
static int curr_free_mpu_idx;
static int get_free_mpu_region(void)
{
	int ret;
	if (curr_free_mpu_idx < (int)(sizeof(free_mpu_region)/sizeof(int))) {
		ret = free_mpu_region[curr_free_mpu_idx];
		curr_free_mpu_idx++;
	} else
		ret = -LD_ERR_PLAT_MPU_REGION_EMPTY;
	return ret;
}


static void get_mpu_region_default_access_att(
	unsigned int apc[EMI_MPU_DGROUP_NUM], int region, int lock)
{
#ifdef ENABLE_EMI_PROTECTION
	SET_ACCESS_PERMISSION(apc, lock,
		mpu_att_default[region][15], mpu_att_default[region][14],
		mpu_att_default[region][13], mpu_att_default[region][12],
		mpu_att_default[region][11], mpu_att_default[region][10],
		mpu_att_default[region][9], mpu_att_default[region][8],
		mpu_att_default[region][7], mpu_att_default[region][6],
		mpu_att_default[region][5], mpu_att_default[region][4],
		mpu_att_default[region][3], mpu_att_default[region][2],
		mpu_att_default[region][1], mpu_att_default[region][0]);
#endif
}

static void mpu_attr_calculate(
	unsigned int apc[EMI_MPU_DGROUP_NUM], int region_id, unsigned int request_attr)
{
	mpu_att_t tmp_mpu_att[MPU_MDOMAIN_ID_TOTAL_NUM], i;
	for (i = 0; i < MPU_MDOMAIN_ID_TOTAL_NUM; i++)
		tmp_mpu_att[i] = mpu_att_default[region_id][i];

	/* AP MD1 MDHW: AP */
	if ((request_attr & 0xF) <= FORBIDDEN)
		tmp_mpu_att[MPU_MDOMAIN_ID_AP] = (request_attr & 0xF);
	/* AP MD1 MDHW: MD1 */
	request_attr = (request_attr >> 4);
	if ((request_attr & 0xF) <= FORBIDDEN)
		tmp_mpu_att[MPU_MDOMAIN_ID_MD1] = (request_attr & 0xF);
	/* AP MD1 MDHW: MDHW */
	request_attr = (request_attr >> 4);
	if ((request_attr & 0xF) <= FORBIDDEN)
		tmp_mpu_att[MPU_MDOMAIN_ID_MDHW] = (request_attr & 0xF);
#ifdef ENABLE_EMI_PROTECTION
	/* MPU region lock */
	SET_ACCESS_PERMISSION(apc, 1,
		tmp_mpu_att[15], tmp_mpu_att[14],
		tmp_mpu_att[13], tmp_mpu_att[12],
		tmp_mpu_att[11], tmp_mpu_att[10],
		tmp_mpu_att[9], tmp_mpu_att[8],
		tmp_mpu_att[7], tmp_mpu_att[6],
		tmp_mpu_att[5], tmp_mpu_att[4],
		tmp_mpu_att[3], tmp_mpu_att[2],
		tmp_mpu_att[1], tmp_mpu_att[0]);
#endif
}

static void ccci_mem_access_cfg(mpu_cfg_t *mpu_cfg_list, int clear)
{
#ifdef ENABLE_EMI_PROTECTION
	mpu_cfg_t *curr;
	struct emi_region_info_t region_info;
	unsigned int curr_attr[EMI_MPU_DGROUP_NUM];
	char buf[MPU_STR_BUF_SIZE];
	int i;

	if (NULL == mpu_cfg_list)
		return;

	SET_ACCESS_PERMISSION(curr_attr, 0,
		NO_PROTECTION, NO_PROTECTION, NO_PROTECTION, NO_PROTECTION,
		NO_PROTECTION, NO_PROTECTION, NO_PROTECTION, NO_PROTECTION,
		NO_PROTECTION, NO_PROTECTION, NO_PROTECTION, NO_PROTECTION,
		NO_PROTECTION, NO_PROTECTION, NO_PROTECTION, NO_PROTECTION);
	for (curr = mpu_cfg_list; curr->region != -1; curr++) {
		if (clear) {
			region_info.region = (unsigned int)curr->region;
			emi_mpu_clear_protection(&region_info);
			get_mpu_attr_str(0, curr_attr, buf, MPU_STR_BUF_SIZE);
			ALWAYS_LOG("Clr MPU:S:0x%x E:0x%x A:<%d>[0~15]%s\n",
				0, 0, curr->region, buf);
		} else {
			region_info.start = curr->start;
			region_info.end = curr->end;
			region_info.region = (unsigned int)curr->region;
			for (i = 0; i < EMI_MPU_DGROUP_NUM; i++)
				region_info.apc[i] = curr->permission[i];
			emi_mpu_set_protection(&region_info);
			get_mpu_attr_str(0, curr->permission, buf, MPU_STR_BUF_SIZE);
			ALWAYS_LOG("Set MPU:S:0x%x E:0x%x A:<%d>[0~15]%s\n",
				curr->start, curr->end, curr->region, buf);
		}
	}

#endif
}

/*--------- Implement one by one -------------------------------------------------------------------------------*/
int plat_get_padding_mpu_num(void)
{
	return (int)(sizeof(free_mpu_region)/sizeof(unsigned int)) - 1;
}

void plat_notify_secure(unsigned long base_addr)
{
	unsigned long addr_get;

	mt_secure_call(MTK_SIP_LK_AMMS_MD_BASE_ADDR_AARCH32, base_addr, 0, 0, 0);
	addr_get = mt_secure_call(MTK_SIP_LK_AMMS_GET_MD_BASE_ADDR_AARCH32, 0, 0, 0, 0);
	ALWAYS_LOG("mt_secure_call: set_addr = 0x%lx, get_addr = 0x%lx\n", base_addr, addr_get);
}

/*---------------------------------------------------------------------------------------------------*/
/* HW remap function implement                                      */
/*---------------------------------------------------------------------------------------------------*/
int plat_apply_hw_remap_for_md_ro_rw(void* info)
{
	modem_info_t *md_ld_info = (modem_info_t *)info;

	plat_notify_secure(md_ld_info->base_addr);
	return md_mem_ro_rw_remapping((unsigned int)md_ld_info->md_id, md_ld_info->base_addr);
}

int plat_apply_hw_remap_for_md_smem(void *addr, int size)
{
	/* For share memory final size depends on MD number, just store start address and size
	** actual setting will do later
	*/
	smem_info.base_addr = (unsigned long long)((unsigned long)addr);
	return 0;
}


int mtk_ccci_get_dfd_smem_info(unsigned long long *ap_addr, unsigned int *md_addr, unsigned int *size)
{
	unsigned int ap_offset;
	unsigned int md_offset;
	unsigned int smem_size;

	if (!smem_info.base_addr) {
		ALWAYS_LOG("[ccci]%s share memory not initialized done\n", __func__);
		return -1;
	}

	if (get_nc_smem_info(SMEM_USER_RAW_DFD, &ap_offset, &md_offset, &smem_size) < 0)
		return -1;

	if (ap_addr)
		*ap_addr = smem_info.base_addr + ap_offset;
	if (md_addr)
		*md_addr = 0x40000000 + md_offset;
	if (size)
		*size = smem_size;

	ALWAYS_LOG("[ccci]%s: ap_addr = 0x%llx, md_addr = 0x%x, size = 0x%x\n", __func__,
			smem_info.base_addr + ap_offset, 0x40000000 + md_offset, smem_size);

	return 0;
}


/*---------------------------------------------------------------------------------------------------*/
/* check header info collection by plat_post_hdr_info                                                */
/*---------------------------------------------------------------------------------------------------*/
void plat_post_hdr_info(void* hdr, int ver, int id)
{
	if (id == MD_SYS1) {
		ap_md1_smem_size_at_img =
			((struct md_check_header_v6*)hdr)->ap_md_smem_size;
		//parsing check-header: AMMS POS, CONSYS
		amms_pos_size_at_img =
			((struct md_check_header_v6*)hdr)->amms_pos_size;
		consys_size_at_img =
			((struct md_check_header_v6*)hdr)->consys_size;
		udc_support_at_img =
			((struct md_check_header_v6*)hdr)->udc_support;
		nv_cache_shm_size_at_img =
			((struct md_check_header_v6*)hdr)->nv_cache_shm_size;
		ALWAYS_LOG("[ccci]parse check-header: amms_pos_size = 0x%x, consys_size = 0x%x, udc_support = %d, nv_cache_size = 0x%x\n",
			amms_pos_size_at_img, consys_size_at_img,
			udc_support_at_img, nv_cache_shm_size_at_img);
	}
}

/*---------------------------------------------------------------------------------------------------*/
/* MPU static global variable and mpu relate function implement                                      */
/*---------------------------------------------------------------------------------------------------*/
#define MPU_REGION_TOTAL_NUM    (16) /* = MD1+MD3 */
static mpu_cfg_t mpu_tbl[MPU_REGION_TOTAL_NUM];
static int s_g_curr_mpu_num;
/*
** if set start=0x0, end=0x10000, the actural protected area will be 0x0-0x1FFFF,
** here we use 64KB align, MPU actually request 32KB align since MT6582, but this works...
** we assume emi_mpu_set_region_protection will round end address down to 64KB align.
*/
static void dump_received_pure_mpu_setting(struct image_section_desc *mem_info, int item_num)
{
	int i;
	for (i =0; i < item_num; i++)
		MPU_DBG_LOG("mpu sec dec %d: offset:%x, size:%x, mpu_attr:%x, ext_flag:%x, relate_idx:%x\n", i,
		            mem_info[i].offset, mem_info[i].size, mem_info[i].mpu_attr,
		            mem_info[i].ext_flag, mem_info[i].relate_idx);
}
static int find_bind_mpu_region(mpu_cfg_t *mpu_tbl_hdr, int item_num, unsigned int bind_key)
{
	int i;
	for (i = 0; i < item_num; i++) {
		if (mpu_tbl_hdr[i].relate_region == (int)bind_key)
			return i;
	}

	return -1;
}
static int md1_mpu_setting_process(void *p_md_ld_info, void *p_mem_info, mpu_cfg_t *mpu_tbl_hdr)
{
	modem_info_t *md_ld_info = (modem_info_t *)p_md_ld_info;
	struct image_section_desc *mem_info = (struct image_section_desc *)p_mem_info;
	int normal_region_num = 0;
	int total_region_num = 0;
	int curr_idx = 0;
	int i, j;
	int all_range_region_idx = -1;
	int bind_idx;
	int free_region_id;
	int didi_region_idx = -1;

	/* Calculate mpu num and padding num */
	for (i = 0; i < MPU_REGION_TOTAL_NUM; i++) {
		if ((mem_info[i].offset == 0) && (mem_info[i].size == 0))
			break;

		if (mem_info[i].ext_flag & MD_ALL_RANGE)
			all_range_region_idx = i;
		if (mem_info[i].ext_flag & MD_DRDI_REGION)
			didi_region_idx = i;
	}
	total_region_num = i;

	dump_received_pure_mpu_setting(mem_info, total_region_num);

	for (i = 0; i < total_region_num; i++) {
		if (mem_info[i].ext_flag & (MD_DRDI_REGION|MD_ALL_RANGE|NEED_REMOVE|NEED_MPU_MORE))
			continue;
		/* Process normal case first */
		if (curr_idx >= (int)(sizeof(region_mapping_at_hdr_md1)/sizeof(unsigned char))) {
			ALWAYS_LOG("[error]md%d: mpu region too more %d\n", md_ld_info->md_id+1,
			           (int)(sizeof(region_mapping_at_hdr_md1)/sizeof(unsigned char)));
			return -LD_ERR_PLAT_MPU_REGION_TOO_MORE;
		}
		mpu_tbl_hdr[curr_idx].start = (unsigned int)md_ld_info->base_addr + mem_info[i].offset;
		mpu_tbl_hdr[curr_idx].end = mpu_tbl_hdr[curr_idx].start + mem_info[i].size;
		mpu_tbl_hdr[curr_idx].end = ((mpu_tbl_hdr[curr_idx].end + 0xFFFF)&(~0xFFFF)) - 1;/* 64K align */
		mpu_attr_calculate(
			mpu_tbl_hdr[curr_idx].permission, region_mapping_at_hdr_md1[curr_idx], mem_info[i].mpu_attr);
		mpu_tbl_hdr[curr_idx].region = (int)region_mapping_at_hdr_md1[curr_idx];
		mpu_tbl_hdr[curr_idx].relate_region = mem_info[i].relate_idx;
		curr_idx++;
		normal_region_num++;
	}
	if (normal_region_num != (int)(sizeof(region_mapping_at_hdr_md1)/sizeof(unsigned char))) {
		ALWAYS_LOG("[error]md%d: mpu region not sync %d:%d\n", md_ld_info->md_id+1, normal_region_num,
		           (int)(sizeof(region_mapping_at_hdr_md1)/sizeof(unsigned char)));
		return -LD_ERR_PLAT_MPU_REGION_NUM_NOT_SYNC;
	}
	for (i = 0; i < total_region_num; i++) {
		if (mem_info[i].ext_flag & NEED_MPU_MORE) {
			bind_idx = find_bind_mpu_region(mpu_tbl_hdr, curr_idx, mem_info[i].relate_idx);
			if (bind_idx >= 0) {
				mpu_tbl_hdr[curr_idx].start = (unsigned int)md_ld_info->base_addr + mem_info[i].offset;
				mpu_tbl_hdr[curr_idx].end = mpu_tbl_hdr[curr_idx].start + mem_info[i].size;
				/* 64K align */
				mpu_tbl_hdr[curr_idx].end = ((mpu_tbl_hdr[curr_idx].end + 0xFFFF)&(~0xFFFF)) - 1;
				for (j = 0; j < EMI_MPU_DGROUP_NUM; j++)
					mpu_tbl_hdr[curr_idx].permission[j] = mpu_tbl_hdr[bind_idx].permission[j];
				/* setting relate region */
				free_region_id = get_free_mpu_region();
				if (free_region_id < 0) {
					ALWAYS_LOG("[error]abnormal free region id %d +\n", free_region_id);
					return -LD_ERR_PLAT_ABNORMAL_FREE_REGION;
				}
				mpu_tbl_hdr[curr_idx].region = free_region_id;
				mpu_tbl_hdr[curr_idx].relate_region = mem_info[i].relate_idx;
				mpu_tbl_hdr[bind_idx].relate_region = free_region_id;
				curr_idx++;
			} else {
				ALWAYS_LOG("md%d: padding array abnormal\n", md_ld_info->md_id+1);
				return -LD_ERR_PLAT_ABNORMAL_PAD_ARRAY;
			}
		}
	}

	/* Apply DRDI if needed */
	if (didi_region_idx >= 0) {
		get_mpu_region_default_access_att(mpu_tbl_hdr[curr_idx].permission, MPU_REGION_ID_MD_DRDI, 1);
		mpu_tbl_hdr[curr_idx].start = (unsigned int)md_ld_info->base_addr + mem_info[didi_region_idx].offset;
		mpu_tbl_hdr[curr_idx].end = mpu_tbl_hdr[curr_idx].start + mem_info[didi_region_idx].size;
		/* 64K align */
		mpu_tbl_hdr[curr_idx].end = ((mpu_tbl_hdr[curr_idx].end + 0xFFFF)&(~0xFFFF)) - 1;
		mpu_tbl_hdr[curr_idx].region = MPU_REGION_ID_MD_DRDI;
		mpu_tbl_hdr[curr_idx].relate_region = 0;
		curr_idx++;
	}

	/* Clear logic relate index to 0 to mark as end */
	for (i = 0; i < curr_idx; i++) {
		if (mpu_tbl_hdr[i].relate_region >= LOGIC_BINDING_IDX_START)
			mpu_tbl_hdr[i].relate_region = 0;
	}
	return curr_idx;
}

int plat_send_mpu_info_to_platorm(void *p_md_ld_info, void *p_mem_info)
{
	modem_info_t *md_ld_info = (modem_info_t *)p_md_ld_info;
	struct image_section_desc *mem_info = (struct image_section_desc *)p_mem_info;
	int md_id = md_ld_info->md_id;
	int ret;
	int i;
	char buf[MPU_STR_BUF_SIZE];

	if (md_id == MD_SYS1) {
		ret = md1_mpu_setting_process(p_md_ld_info, p_mem_info, &mpu_tbl[s_g_curr_mpu_num]);
		if (ret > 0)
			s_g_curr_mpu_num += ret;
	} else if (md_id == MD1_DSP) {
		/* RO part */
		get_mpu_region_default_access_att(mpu_tbl[s_g_curr_mpu_num].permission, MPU_REGION_ID_MD_DSP1, 1);
		mpu_tbl[s_g_curr_mpu_num].start = (unsigned int)md_ld_info->base_addr + mem_info[0].offset;
		mpu_tbl[s_g_curr_mpu_num].end = mpu_tbl[s_g_curr_mpu_num].start + mem_info[0].size;
		mpu_tbl[s_g_curr_mpu_num].region = MPU_REGION_ID_MD_DSP1;
		/* 64K align */
		mpu_tbl[s_g_curr_mpu_num].end = ((mpu_tbl[s_g_curr_mpu_num].end + 0xFFFF)&(~0xFFFF)) - 1;
		s_g_curr_mpu_num++;

		/* RW part */
		get_mpu_region_default_access_att(mpu_tbl[s_g_curr_mpu_num].permission, MPU_REGION_ID_MD_DSP2, 1);
		mpu_tbl[s_g_curr_mpu_num].start = (unsigned int)md_ld_info->base_addr + mem_info[1].offset;
		mpu_tbl[s_g_curr_mpu_num].end = mpu_tbl[s_g_curr_mpu_num].start + mem_info[1].size;
		mpu_tbl[s_g_curr_mpu_num].region = MPU_REGION_ID_MD_DSP2;
		/* 64K align */
		mpu_tbl[s_g_curr_mpu_num].end = ((mpu_tbl[s_g_curr_mpu_num].end + 0xFFFF)&(~0xFFFF)) - 1;
		s_g_curr_mpu_num++;
	}

	for (i =0; i < s_g_curr_mpu_num; i++) {
		get_mpu_attr_str(0, mpu_tbl[i].permission, buf, MPU_STR_BUF_SIZE);
		MPU_DBG_LOG("plat mpu dec %d: region:%d[%d], start:0x%x, end:0x%x, attr:%s\n", i,
		            mpu_tbl[i].region, mpu_tbl[i].relate_region, mpu_tbl[i].start, mpu_tbl[i].end, buf);
	}

	return 0;
}


#ifdef MPU_REGION_CONSYS_EN
static void emi_mpu_region_setting(unsigned int region, unsigned long long start, unsigned long long end, char name[])
{
#ifdef ENABLE_EMI_PROTECTION
	struct emi_region_info_t region_info;
	char buf[MPU_STR_BUF_SIZE];

	SET_ACCESS_PERMISSION(region_info.apc, 0,
		mpu_att_default[region][15], mpu_att_default[region][14],
		mpu_att_default[region][13], mpu_att_default[region][12],
		mpu_att_default[region][11], mpu_att_default[region][10],
		mpu_att_default[region][9], mpu_att_default[region][8],
		mpu_att_default[region][7], mpu_att_default[region][6],
		mpu_att_default[region][5], mpu_att_default[region][4],
		mpu_att_default[region][3], mpu_att_default[region][2],
		mpu_att_default[region][1], mpu_att_default[region][0]);

	region_info.start = start;
	region_info.end = end;
	region_info.region = region;
	emi_mpu_set_protection(&region_info);
	get_mpu_attr_str(0, region_info.apc, buf, MPU_STR_BUF_SIZE);
	ALWAYS_LOG("Set MPU:S:0x%llx E:0x%llx A:<%d>[0~15]%s(%s)\n",
		start, end, region, buf, name);
#endif

}

static void md_special_mpu_set()
{
	unsigned int i;

	for (i = 0; i < sizeof(csmem_layout)/sizeof(csmem_item_t); i++) {
		if (!csmem_layout[i].csmem_buffer_size) {
			ALWAYS_LOG("csmem[%d]<%d> size 0, skip\n", i, csmem_layout[i].item_cnt);
			continue;
		}
		if (csmem_layout[i].item_cnt == SMEM_USER_RAW_MD_CONSYS) {
			emi_mpu_region_setting(MPU_REGION_ID_MD_CONSYS,
				(csmem_layout[i].md_offset + csmem_info.csmem_buffer_addr),
				(csmem_layout[i].md_offset +csmem_layout[i].csmem_buffer_size + csmem_info.csmem_buffer_addr - 1),
				"CONSYS");
			break;
		}
	}
}

void md_sib_mpu_set(sib_item_t *sib_cfg)
{
	emi_mpu_region_setting(MPU_REGION_ID_MD1_TRACE_TOP, sib_cfg->md1_sib_addr,
				sib_cfg->md1_sib_addr + sib_cfg->md1_sib_size -1, "SIB");
}
#endif

static void boot_to_dummy_ap_mode(int load_md_flag);
/*------------------------------------------------------------------------------------------------*/
/* Note: This function using global variable
** if set start=0x0, end=0x10000, the actural protected area will be 0x0-0x1FFFF,
** here we use 64KB align, MPU actually request 32KB align since MT6582, but this works...
** we assume emi_mpu_set_region_protection will round end address down to 64KB align.
*/
int plat_apply_platform_setting(int load_md_flag)
{
	int smem_final_size;

#ifdef DUMMY_AP_MODE
	/* This function will never return */
	ALWAYS_LOG("boot to dummy ap mode!!!\n");
	boot_to_dummy_ap_mode(load_md_flag);
	return 0;
#endif

	/* Check loading validation */
	if (((load_md_flag & (1<<MD_SYS1)) == 0) && (load_md_flag & (1<<MD_SYS3))) {
		ALWAYS_LOG("md3 depends on md1,but md1 not loaded\n");
		return -LD_ERR_PLAT_MD1_NOT_RDY;
	}
	if ((load_md_flag & ((1<<MD_SYS1)|(1<<MD_SYS3))) == 0) {
		ALWAYS_LOG("both md1 and md3 not enable\n");
		return 0;
	}

	smem_final_size = cal_c_smem_size_and_layout(load_md_flag);
	ALWAYS_LOG("ap md1 share mem MPU need configure\n");
	mpu_tbl[s_g_curr_mpu_num].region = MPU_REGION_ID_MD1_NC_SMEM;
	get_mpu_region_default_access_att(mpu_tbl[s_g_curr_mpu_num].permission, MPU_REGION_ID_MD1_NC_SMEM, 0);
	mpu_tbl[s_g_curr_mpu_num].start = (unsigned int)smem_info.base_addr + smem_info.ap_md1_smem_offset;
	mpu_tbl[s_g_curr_mpu_num].end = (unsigned int)smem_info.base_addr + smem_info.ap_md1_smem_offset
	                                + smem_final_size; /* ap_md1 share && phy_cap had 2M overlap */
	mpu_tbl[s_g_curr_mpu_num].end = ((mpu_tbl[s_g_curr_mpu_num].end + 0xFFFF)&(~0xFFFF)) - 1;
	s_g_curr_mpu_num++;

	/* add for ccb data buffer mpu */
	mpu_tbl[s_g_curr_mpu_num].region = MPU_REGION_ID_MD1_C_SMEM;
	get_mpu_region_default_access_att(mpu_tbl[s_g_curr_mpu_num].permission, MPU_REGION_ID_MD1_C_SMEM, 0);
	mpu_tbl[s_g_curr_mpu_num].start = (unsigned int)csmem_info.csmem_buffer_addr;//ccb_info.ccb_data_buffer_addr;
	mpu_tbl[s_g_curr_mpu_num].end = (unsigned int)csmem_info.csmem_buffer_addr + csmem_info.csmem_buffer_size;//ccb_info.ccb_data_buffer_addr + ccb_info.ccb_data_buffer_size;
	mpu_tbl[s_g_curr_mpu_num].end = ((mpu_tbl[s_g_curr_mpu_num].end + 0xFFFF)&(~0xFFFF)) - 1;
	s_g_curr_mpu_num++;

	mpu_tbl[s_g_curr_mpu_num].region = -1; /* mark for end */
	/* Insert mpu tag info */
	if (insert_ccci_tag_inf("md_mpu_inf", (char*)mpu_tbl, sizeof(mpu_cfg_t)*s_g_curr_mpu_num) < 0)
		ALWAYS_LOG("insert md_mpu_inf fail\n");
	if (insert_ccci_tag_inf("md_mpu_num", (char*)&s_g_curr_mpu_num, sizeof(int)) < 0)
		ALWAYS_LOG("insert md_mpu_num fail\n");

	/* Apply all MPU setting */
	ccci_mem_access_cfg(mpu_tbl, 0);
#ifdef MPU_REGION_CONSYS_EN
	md_special_mpu_set();
#endif
	/* Apply share memory HW remap setting */
	if (load_md_flag & (1<<MD_SYS1))
		md_smem_rw_remapping(MD_SYS1, (unsigned int)(smem_info.base_addr + smem_info.ap_md1_smem_offset));

	return smem_final_size;
}

/*****************************************************************************/
/* Memory --- limit and align settings                                       */
/*****************************************************************************/
/* Share memory cacheable for MD */
#define SMEM_CACHE_ALIGNMENT	0x2000000L
#define SMEM_CACHE_LIMIT	0x90000000LL

/* Share memory non-cacheable for MD */
#define SMEM_NONCACHE_ALIGNMENT	0x2000000L
#define SMEM_NONCACHE_LIMIT	0x90000000LL

/* RO + RW memory non-cacheable for MD */
#define RO_RW_MEM_ALIGNMENT	0x2000000L
#ifdef DUMMY_AP_MODE
#define RO_RW_MEM_LIMIT		0xC0000000LL
#else
#define RO_RW_MEM_LIMIT		0xC0000000LL
#endif

/* SIB memory  */
#define SIB_SMEM_ALIGNMENT	0x8000000L
#define SIB_SMEM_LIMIT	0x200000000LL

/*------------------------------------------------------------------------------------------------*/
/* platform configure setting info.                                                               */
/*------------------------------------------------------------------------------------------------*/
long long plat_ccci_get_ld_md_plat_setting(char cfg_name[])
{
	if (strcmp(cfg_name, "share_memory_size") == 0) {

#ifdef DUMMY_AP_MODE
		return 0x200000;
#endif
		/* only for non-cacheable part. */
		return (long long)cal_nc_share_mem_size();
	}

	if (strcmp(cfg_name, "share_mem_limit") == 0)
		return 0x90000000LL;

	if (strcmp(cfg_name, "ro_rw_mem_limit") == 0)
		return 0xC0000000LL;

	if (strcmp(cfg_name, "ro_rw_mem_align") == 0)
		return 0x2000000LL;

	if (strcmp(cfg_name, "share_mem_align") == 0)
		return 0x2000000LL;

	if (strcmp(cfg_name, "ld_version") == 0) {

#ifdef DUMMY_AP_MODE
		return 0x20001;
#endif
		return 0x30000;/* xxxx_yyyy, xxxx: main id, yyyy sub id */
	}

	if (strcmp(cfg_name, "rat_plat_ver") == 0)
		return RAT_VER_93;

	return -1LL;
}

/* CCCI tag info memory */
#define TAG_MEM_ALIGNMENT	0x1000L
#define TAG_MEM_LIMIT		0xC0000000LL

#define PLAT_DEFAULT_CCB_GEAR	1

struct mem_attr_setting {
	char *name;
	unsigned long long limit;
	unsigned long align;
};

const struct mem_attr_setting c_md_mem_attr_cfg[] = {
	{"ap_md_c_smem",	SMEM_CACHE_LIMIT, SMEM_CACHE_ALIGNMENT},
	{"ap_md_nc_smem",	SMEM_NONCACHE_LIMIT, SMEM_NONCACHE_ALIGNMENT},
	{"md_mem_usage",	RO_RW_MEM_LIMIT, RO_RW_MEM_ALIGNMENT},
	{"ccci_tag_mem",	TAG_MEM_LIMIT, TAG_MEM_ALIGNMENT},
	{"md3rom",			RO_RW_MEM_LIMIT, RO_RW_MEM_ALIGNMENT},
	{"md1_sib_mem", 	SIB_SMEM_LIMIT, SIB_SMEM_ALIGNMENT},
	{NULL, 0LL, 0L},
};

int get_mem_limit_and_align(char key[], unsigned long long *limit, unsigned long *align)
{
	int i = 0;
	int mem_attr_num =
		sizeof(c_md_mem_attr_cfg)/sizeof(struct mem_attr_setting);

	while(1) {
		if (i >= mem_attr_num) {
			ALWAYS_LOG("invalid index i=%d\n", i);
			break;
		}
		if (!c_md_mem_attr_cfg[i].name)
			break;

		if (strcmp(key, c_md_mem_attr_cfg[i].name) == 0) {
			if (limit)
				*limit = c_md_mem_attr_cfg[i].limit;
			if (align)
				*align = c_md_mem_attr_cfg[i].align;
			return 0;
		}
		i++;
	}

	return -1;
}

#ifdef DUMMY_AP_MODE
#include <platform/mt_irq.h>
extern void dummy_ap_boot_up_md(int md_en_flag);
extern void load_modem_image(void);
extern int dummy_ap_irq_helper(unsigned int);

/* Remember add this function to file platform.c(platform code) */
void dummy_ap_entry(void)
{
	load_modem_image();
}

/* Remember add this function to file interrupts.c(platform code) */
void dummy_ap_irq_handler(unsigned int irq)
{
	if (dummy_ap_irq_helper(irq)) {
		mt_irq_ack(irq);
		mt_irq_unmask(irq);
	}
}

void boot_to_dummy_ap_mode(int load_md_flag)
{
	md_smem_rw_remapping(MD_SYS1, smem_info.base_addr);
	/* Before boot dummy AP, clear share memory */
	memset((void*)((unsigned long)smem_info.base_addr), 0, 0x200000);

	dummy_ap_boot_up_md(load_md_flag);
}

#endif

