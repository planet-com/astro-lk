#include <platform/spm.h>
#include <debug.h>
#include "spm.h"
#include <mtk_wdt.h>

#ifdef MTK_GPU_DFD_SUPPORT

/* GPU DFD */
#define MFG_MISC_CON 0x10001600
#define MFG_DFD_TRIGGER (1<<19)
#define MFG_DFD_COMPLETE (1<<18)
#define MFG_DFD_CON_0 0x13FBFA00
#define MFG1_PORT_STEP2_0_MASK (0x3 << 21)
#define MFG1_PORT_STEP1_0_MASK (0x7 << 19)
#define DRM_MFG_REG 0x1000D060

void show_gpu_dfd_debug_msg(void)
{
	unsigned int status = spm_read(MFG_MISC_CON);
	unsigned int pwr = spm_read(DRM_MFG_REG);

	dprintf(CRITICAL, "%s: GPU DFD MFG_MISC_CON:0x%x, DRM_MFG_REG:0x%x\n",
		__func__, status, pwr);

	dprintf(CRITICAL, "%s: PWR_STATUS[0x1000616c]:0x%x, MFG0_PWR_CON[0x10006308]:0x%x\n",
		__func__, spm_read(0x1000616c), spm_read(0x10006308));
}

unsigned int mfg_set_power_off(void);

unsigned int mfg_set_power_on(void)
{
	unsigned int status = spm_read(MFG_MISC_CON);

	show_gpu_dfd_debug_msg();

	/* Read register MFG_MISC_CON (@ 0x1000_1600) bit [19:18] = 0x3 */
	if ((status & MFG_DFD_TRIGGER) == 0) {
		dprintf(CRITICAL, "%s: GPU DFD was not triggered (0x%x)\n", __func__, status);
		return 0;
	}

	if ((status & MFG_DFD_COMPLETE) == 0) {
		dprintf(CRITICAL, "%s: GPU DFD was not triggered completely(0x%x)\n", __func__, status);
		mfg_set_power_off();
		return 0;
	}

	// power on GPU
	dprintf(CRITICAL, "%s: GPU DFD Begin GPU0 MTCMOS\n", __func__);
	spm_mtcmos_ctrl_mfg0(STA_POWER_ON);
	dprintf(CRITICAL, "%s: GPU DFD end GPU0 MTCMOS\n", __func__);

	dprintf(CRITICAL, "%s: GPU DFD Begin GPU1 MTCMOS\n", __func__);
	spm_mtcmos_ctrl_mfg1(STA_POWER_ON);
	dprintf(CRITICAL, "%s: GPU DFD end GPU1 MTCMOS\n", __func__);

	{
		unsigned int dfd = spm_read(MFG_DFD_CON_0);
			dprintf(CRITICAL, "%s: GPU DFD MFG_DFD_CON_0:0x%x\n",
		__func__, dfd);
	}

	/* 2. Write register MFG_DFD_CON_0 (@ 0x13FB_FA00) = 0x0f000011 */
	spm_write(MFG_DFD_CON_0, 0x0F000011);

	return 1;
}

unsigned int mfg_set_power_off(void)
{
	/* 0. gpu hard reset */
	/*
	 * // [2] = mfg_rst, reset mfg
	 * Write register WDT_SWSYSRST (@ 0x1000_7018) = 0x88000004;
	 * Wait 10us;
	 * // [2] = mfg_rst, release reset
	 * Write register WDT_SWSYSRST (@ 0x1000_7018) = 0x88000000;
	 */
	dprintf(CRITICAL, "%s: gpu hard reset\n", __func__);
	mtk_wdt_swsysret_config(MTK_WDT_SWSYS_RST_GPU_RST, 1);
	udelay(10);
	mtk_wdt_swsysret_config(MTK_WDT_SWSYS_RST_GPU_RST, 0);

	/* 1. do fake power on */
	dprintf(CRITICAL, "%s: do fake power on\n", __func__);
	spm_mtcmos_ctrl_mfg0(STA_POWER_ON);
	spm_mtcmos_ctrl_mfg1(STA_POWER_ON);

	/* 2. disable gpu dfd */
	dprintf(CRITICAL, "%s: disable MFG_DFD_CON_0\n", __func__);
	spm_write(MFG_DFD_CON_0, 0x0);

	/* 3. clear wdt_mfg_pwr_on */
	dprintf(CRITICAL, "%s: DRM_MFG_REG, wdt_mfg_por_on = 0 \n", __func__);
	spm_write(DRM_MFG_REG, 0x77 << 24);

	/* 4. fake power off */
	dprintf(CRITICAL, "%s: GPU DFD Begin GPU1 MTCMOS off\n", __func__);
	spm_mtcmos_ctrl_mfg1(STA_POWER_DOWN);
	dprintf(CRITICAL, "%s: GPU DFD End GPU1 MTCMOS off\n", __func__);

	dprintf(CRITICAL, "%s: GPU DFD Begin GPU0 MTCMOS off\n", __func__);
	spm_mtcmos_ctrl_mfg0(STA_POWER_DOWN);
	dprintf(CRITICAL, "%s: GPU DFD End GPU0 MTCMOS off\n", __func__);

	return 1;
}

void mfg_clear_dfd(void)
{
	unsigned int status = spm_read(MFG_MISC_CON);

	/* Read register MFG_MISC_CON (@ 0x1000_1600) bit [19:18] = 0x3 */
	if ((status & MFG_DFD_TRIGGER) == 0) {
		dprintf(CRITICAL, "%s: GPU DFD was not triggered (0x%x)\n", __func__, status);
		return;
	}

	dprintf(CRITICAL, "%s: GPU DFD was triggered, clear it.\n", __func__);
	mfg_set_power_off();
}

#else
unsigned int mfg_set_power_on(void)
{
	return 0;
}

unsigned int mfg_set_power_off(void)
{
	return 0;
}

unsigned int mfg_clear_dfd(void)
{
	return 0;
}
#endif // MTK_GPU_DFD_SUPPORT
