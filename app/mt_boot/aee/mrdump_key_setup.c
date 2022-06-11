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

#ifndef CFG_MTK_WDT_COMMON

#include <printf.h>

void mrdump_key_secure_enable(void)
{
	dprintf(CRITICAL, "%s: No MTK WDT Common Driver API\n", __func__);
}

void mrdump_key_fdt_init(void *fdt)
{
	dprintf(CRITICAL, "%s: No MTK WDT Common Driver API\n", __func__);
}

#else

#include <platform/mt_gpio.h>
#include <platform/mt_typedefs.h>
#include <mtk_wdt.h>
#include <pmic_common.h>
#include <printf.h>

static void mrdump_key_select_eint(int mrdump_key_pin)
{
	mt_set_gpio_pull_enable(mrdump_key_pin, GPIO_PULL_UP);
	mt_set_gpio_dir(mrdump_key_pin, GPIO_DIR_IN);
	mt_set_gpio_mode(mrdump_key_pin, GPIO_MODE_00);

	mtk_wdt_select_eint((unsigned int)mrdump_key_pin);
}

static void mrdump_key_apply(char *force_trigger,  char *rst_mode,
		int mrdump_key_pin)
{
	if (!rst_mode || !force_trigger) {
		dprintf(CRITICAL, "%s: no rst_mode or force_trigger\n",
			__func__);
		return;
	}

	if (!strncmp("SYSRST", force_trigger, strlen("SYSRST"))) {
		if (!strncmp(rst_mode, "IRQ", strlen("IRQ"))) {
			mtk_wdt_request_mode_set(MTK_WDT_STATUS_SYSRST_RST,
						 WD_REQ_IRQ_MODE);
			mtk_wdt_request_en_set(MTK_WDT_STATUS_SYSRST_RST,
					       WD_REQ_EN);
			enable_pmic_smart_reset(1);          /* 1st timeout */
			enable_pmic_smart_reset_shutdown(1); /* 2nd timeout */
		} else if (!strncmp(rst_mode, "RST", strlen("RST"))) {
			mtk_wdt_request_mode_set(MTK_WDT_STATUS_SYSRST_RST,
						 WD_REQ_RST_MODE);
			mtk_wdt_request_en_set(MTK_WDT_STATUS_SYSRST_RST,
					       WD_REQ_EN);
			enable_pmic_smart_reset(1);
			enable_pmic_smart_reset_shutdown(1);
		} else {
			dprintf(CRITICAL, "%s: bad rst_mode=%s in SYSRST\n",
					   __func__, rst_mode);
		}
	} else if (!strncmp("EINT", force_trigger, strlen("EINT"))) {
		if ((mrdump_key_pin < 0) || (mrdump_key_pin >12)) {
			dprintf(CRITICAL, "%s: incorrect mrdump_key_pin(%d)\n",
				__func__, mrdump_key_pin);
			return;
		}

		mrdump_key_select_eint(mrdump_key_pin);

		if (rst_mode && !strncmp(rst_mode, "IRQ", strlen("IRQ"))) {
			mtk_wdt_request_mode_set(MTK_WDT_STATUS_EINT_RST,
						 WD_REQ_IRQ_MODE);
			mtk_wdt_request_en_set(MTK_WDT_STATUS_EINT_RST,
					       WD_REQ_EN);
		} else if (rst_mode && !strncmp(rst_mode, "RST", strlen("RST"))) {
			mtk_wdt_request_mode_set(MTK_WDT_STATUS_EINT_RST,
						 WD_REQ_RST_MODE);
			mtk_wdt_request_en_set(MTK_WDT_STATUS_EINT_RST,
					       WD_REQ_EN);
		} else {
			dprintf(CRITICAL, "%s: bad rst_mode=%s in EINT\n",
					   __func__, rst_mode);
		}
	} else {
		dprintf(CRITICAL, "%s: no valid force_trigger info (%s)\n",
				   __func__, force_trigger);
	}
}

static char *force_mode;

void mrdump_key_secure_enable(void)
{
	force_mode = "SYSRST";
}

void mrdump_key_fdt_init(void *fdt)
{
	const char mrdump_key_compatible[] = "mediatek, mrdump_ext_rst-eint";
	int offset, len;
	const void *data;

	int mrdump_key_pin, *interrupts;
	char *rst_mode = "IRQ";

	if (!force_mode) {
#if defined(USER_BUILD)
		force_mode = "EINT";
#else
		force_mode = "SYSRST";
#endif
		dprintf(CRITICAL, "%s: force trigger default to %s\n", __func__, force_mode);
	} else {
		dprintf(CRITICAL, "%s: force trigger set to %s\n", __func__, force_mode);
	}

	offset = fdt_node_offset_by_compatible(fdt, -1, mrdump_key_compatible);
	if (offset < 0) {
		dprintf(CRITICAL, "%s not found\n", mrdump_key_compatible);
		return;
	}

	data = fdt_getprop(fdt, offset, "force_mode", &len);
	if (data) {
		dprintf(CRITICAL, "%s: force_mode = %s\n", __func__, (char *)data);
		force_mode = (char *)data;
	} else {
		dprintf(CRITICAL, "%s: no force_mode attribute default=%s\n",
			__func__, force_mode);
	}

	data = fdt_getprop(fdt, offset, "mode", &len);
	if (data) {
		dprintf(CRITICAL, "%s: rst_mode = %s\n", __func__, (char *)data);
		rst_mode = (char *)data;
	} else
		dprintf(CRITICAL, "%s: no mode attribute default=%s\n",
			__func__, rst_mode);

	data = fdt_getprop(fdt, offset, "interrupts", &len);
	if (data) {
		dprintf(CRITICAL, "%s: interrupts = 0x%x\n", __func__, *((int *)data));
		interrupts = (int *)data;
		mrdump_key_pin = (*interrupts/0x1000000);
		dprintf(CRITICAL, "%s: mrdump_key_pin = EINT%d\n", __func__, mrdump_key_pin);
	} else {
		dprintf(CRITICAL, "%s: no interrupts attribute\n", __func__);
		mrdump_key_pin = -1;
	}

	mrdump_key_apply(force_mode, rst_mode, mrdump_key_pin);
}
#endif
