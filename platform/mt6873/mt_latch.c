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

#include <reg.h>
#include <latch.h>
#include <debug.h>
#include <mt_reg_base.h>
#include <aee_platform_debug.h>
#include <dfd.h>

static unsigned long preisys_dump_offset[] = {
	0x500, /* PERIBUS_DBG0 */
	0x504, /* PERIBUS_DBG1 */
	0x508, /* PERIBUS_DBG2 */
	0x50C, /* PERIBUS_DBG3 */
	0x510, /* PERIBUS_DBG4 */
	0x514, /* PERIBUS_DBG5 */
	0x518, /* PERIBUS_DBG6 */
	0x51C, /* PERIBUS_DBG7 */
	0x520, /* PERIBUS_DBG8 */
	0x524, /* PERIBUS_DBG9 */
	0x528, /* PERIBUS_DBG10 */
	0x52C, /* PERIBUS_DBG11 */
	0x530, /* PERIBUS_DBG12 */
	0x534, /* PERIBUS_DBG13 */
	0x538, /* PERIBUS_DBG14 */
	0x53C, /* PERIBUS_DBG15 */
	0x580, /* PERIBUS_DBG16 */
	0x584, /* PERIBUS_DBG17 */
};

int plt_lastbus_is_timeout(const struct plt_cfg_bus_latch *self)
{
	unsigned int ctrl;
	unsigned long infra_base = INFRACFG_AO_BASE;
	unsigned long peri_base = PERICFG_BASE;

	if (!self) {
		dprintf(CRITICAL, "%s:%d: self is Null\n",
			__func__, __LINE__);
		return 0;
	}

	ctrl = (readl(infra_base + self->infrasys_offsets.bus_infra_ctrl) & 0x1) |
		(readl(peri_base + self->perisys_offsets.bus_peri_r1) & 0x1);

	return ctrl;
}

int plt_infrasys_dump(const struct plt_cfg_bus_latch *self,
					 char *buf, int *wp)
{
	unsigned int i;
	unsigned long infra_base = INFRACFG_AO_BASE;
	unsigned long peri_base = PERICFG_BASE;

	if (readl(infra_base + self->infrasys_offsets.bus_infra_ctrl) & 0x1)
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[LAST BUS] INFRASYS TIMEOUT:\n");

	if (readl(peri_base + self->perisys_offsets.bus_peri_r1) & 0x1)
		*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "[LAST BUS] PERISYS TIMEOUT:\n");

	if (self->num_infrasys_mon != 0) {
		for (i = 0; i <= self->num_infrasys_mon-1; ++i)
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "%08x\n",
				       readl(infra_base + self->infrasys_offsets.bus_infra_snapshot + 4*i));
	}

	return 0;
}

int plt_perisys_dump(const struct plt_cfg_bus_latch *self,
					char *buf, int *wp)
{
	unsigned int i;
	unsigned long peri_base = PERICFG_BASE;

	if (self->num_perisys_mon != 0) {
		for (i = 0; i <= self->num_perisys_mon-1; ++i)
			*wp += snprintf(buf + *wp, LATCH_BUF_LENGTH - *wp, "%08x\n",
			               readl(peri_base + preisys_dump_offset[i]));
	}

	return 0;
}

/*
 * XXX
 * workaround for mt6873
 * skip unnecessary timeout condition from master and slave
 *
 */
int lastbus_init_v2_infra_ao_init(const struct lastbus_monitor *m)
{
	/* disable master/slave idle */
	writel(0x3f, (unsigned long)m->base + 0x00c);
	writel(0x1c, (unsigned long)m->base + 0x010);

	writel(0xffff0008, m->base);
	writel(0xffff000c, m->base);

	return 0;
}

int lastbus_init_v2_peri_ao_init(const struct lastbus_monitor *m)
{
	/* disable master/slave idle */
	writel(0xe000007e, (unsigned long)m->base + 0x00c);

	writel(0xffff0008, m->base);
	writel(0xffff000c, m->base);

	return 0;
}

int lastbus_init_v2_fmem_ao_init(const struct lastbus_monitor *m)
{
	/* disable master/slave idle */
	writel(0x100, (unsigned long)m->base + 0x00c);
	writel(0x18, (unsigned long)m->base + 0x010);

	writel(0xffff0008, m->base);
	writel(0xffff000c, m->base);

	return 0;
}

void plt_setup_dfd_file_name(const struct plt_cfg_dfd *cfg_dfd)
{
	struct aee_db_file_info *files;

	files = get_file_info();
	strcpy(files[AEE_PLAT_DFD20].filename, "DFD.dfd");
	files[AEE_PLAT_DFD20].filesize = (unsigned int)cfg_dfd->large_buffer_length;
}

/* XXX */
#define DFD_STATUS	(0x0c53e0a4)

unsigned int plat_dfd_trigger_status(void)
{
	return readl(DFD_STATUS);

}

void plat_dump_dfd_status(void)
{
	dprintf(CRITICAL, "[dfd] dfd_trigger_status: 0x%x\n", plat_dfd_trigger_status());
}
