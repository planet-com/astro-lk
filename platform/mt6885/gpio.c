/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2019. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

#include <platform/mt_reg_base.h>
#include <platform/mt_gpio.h>
#include <platform/gpio_cfg.h>
#include <debug.h>

/******************************************************************************
 MACRO Definition
******************************************************************************/
//#define  GIO_SLFTEST
#define GPIO_BRINGUP
#define GPIO_DEVICE "mt-gpio"
#define VERSION     GPIO_DEVICE
/*---------------------------------------------------------------------------*/
#define SUPPORT_MODE_MWR
#define REGSET (4)
#define REGCLR (8)
#define REGMWR (0xC)
/*---------------------------------------------------------------------------*/
#define GPIO_WR32(addr, data)           DRV_WriteReg32(addr, data)
#define GPIO_RD32(addr)                 DRV_Reg32(addr)
#define GPIO_SET_BITS(REG, BIT)         GPIO_WR32(REG + REGSET, BIT)
#define GPIO_CLR_BITS(REG, BIT)         GPIO_WR32(REG + REGCLR, BIT)
/*---------------------------------------------------------------------------*/
#define TRUE                            1
#define FALSE                           0
/*---------------------------------------------------------------------------*/
#define GPIOTAG                         "[GPIO] "
#define GPIOLOG(fmt, arg...)            dprintf(INFO,GPIOTAG fmt, ##arg)
#define GPIOMSG(fmt, arg...)            dprintf(INFO,fmt, ##arg)
#define GPIOERR(fmt, arg...)            dprintf(INFO,GPIOTAG "%5d: "fmt, __LINE__, ##arg)
#define GPIOFUC(fmt, arg...)            dprintf(INFO,GPIOTAG "%s\n", __FUNCTION__)
#define GIO_INVALID_OBJ(ptr)            ((ptr) != gpio_obj)
/******************************************************************************
Enumeration/Structure
******************************************************************************/
#ifdef FPGA_PLATFORM
S32 mt_set_gpio_drv(u32 pin, u32 drv)           {return RSUCCESS;}
S32 mt_get_gpio_drv(u32 pin)                    {return GPIO_DIR_UNSUPPORTED;}
s32 mt_set_gpio_dir(u32 pin, u32 dir)           {return RSUCCESS;}
s32 mt_get_gpio_dir(u32 pin)                    {return GPIO_DIR_UNSUPPORTED;}
s32 mt_set_gpio_pull_enable(u32 pin, u32 en)    {return RSUCCESS;}
s32 mt_get_gpio_pull_enable(u32 pin)            {return GPIO_PULL_EN_UNSUPPORTED;}
s32 mt_set_gpio_pull_select(u32 pin, u32 sel)   {return RSUCCESS;}
s32 mt_get_gpio_pull_select(u32 pin)            {return GPIO_PULL_UNSUPPORTED;}
s32 mt_set_gpio_smt(u32 pin, u32 enable)        {return RSUCCESS;}
s32 mt_get_gpio_smt(u32 pin)                    {return GPIO_SMT_UNSUPPORTED;}
s32 mt_set_gpio_ies(u32 pin, u32 enable)        {return RSUCCESS;}
s32 mt_get_gpio_ies(u32 pin)                    {return GPIO_IES_UNSUPPORTED;}
s32 mt_set_gpio_out(u32 pin, u32 output)        {return RSUCCESS;}
s32 mt_get_gpio_out(u32 pin)                    {return GPIO_OUT_UNSUPPORTED;}
s32 mt_get_gpio_in(u32 pin)                     {return GPIO_IN_UNSUPPORTED;}
s32 mt_set_gpio_mode(u32 pin, u32 mode)         {return RSUCCESS;}
s32 mt_get_gpio_mode(u32 pin)                   {return GPIO_MODE_UNSUPPORTED;}
#else
struct mt_gpio_obj {
	GPIO_REGS       *reg;
};
static struct mt_gpio_obj gpio_dat = {
	.reg  = (GPIO_REGS*)(GPIO_BASE),
};
static struct mt_gpio_obj *gpio_obj = &gpio_dat;
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_drv_chip(u32 pin, u32 drv)
{
	u32 reg;
	u32 val, mask;
	struct mt_gpio_obj *obj = gpio_obj;

	if (!obj)
		return -ERACCESS;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if (DRV_offset[pin].offset == (s8)-1)
		return GPIO_DRV_UNSUPPORTED;

	mask = ((1 << DRV_width[pin].width) - 1);
	/* check if set value beyond supported width */
	if (drv > mask)
		return -ERINVAL;

	reg = GPIO_RD32(DRV_addr[pin].addr);
	val = reg & ~(mask << DRV_offset[pin].offset);
	val |= (drv << DRV_offset[pin].offset);

	GPIO_WR32(DRV_addr[pin].addr, val);

	return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_drv_chip(u32 pin)
{
	u32 reg;
	u32 val, mask;
	struct mt_gpio_obj *obj = gpio_obj;

	if (!obj)
		return -ERACCESS;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if (DRV_offset[pin].offset == (s8)-1)
		return GPIO_DRV_UNSUPPORTED;

	reg = GPIO_RD32(DRV_addr[pin].addr);
	reg = reg >> DRV_offset[pin].offset;
	mask = (1 << DRV_width[pin].width) - 1;
	val = reg & mask;

	return val;
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_dir_chip(u32 pin, u32 dir)
{
	u32 pos;
	u32 bit;
	struct mt_gpio_obj *obj = gpio_obj;

	if (!obj)
		return -ERACCESS;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if (dir >= GPIO_DIR_MAX)
		return -ERINVAL;

	pos = pin / MAX_GPIO_REG_BITS;
	bit = pin % MAX_GPIO_REG_BITS;

	/* To reduce memory usage, we don't use DIR_addr[] array*/
	if (dir == GPIO_DIR_IN)
		GPIO_WR32(&obj->reg->dir[pos].rst, 1UL << bit);
	else
		GPIO_WR32(&obj->reg->dir[pos].set, 1UL << bit);

	return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_dir_chip(u32 pin)
{
	u32 pos;
	u32 bit;
	u32 reg;
	struct mt_gpio_obj *obj = gpio_obj;

	if (!obj)
		return -ERACCESS;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	pos = pin / MAX_GPIO_REG_BITS;
	bit = pin % MAX_GPIO_REG_BITS;

	/* To reduce memory usage, we don't use DIR_addr[] array*/
	reg = GPIO_RD32(&obj->reg->dir[pos].val);
	return (((reg & (1UL << bit)) != 0)? 1: 0);
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_out_chip(u32 pin, u32 output)
{
	u32 pos;
	u32 bit;
	struct mt_gpio_obj *obj = gpio_obj;

	if (!obj)
		return -ERACCESS;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if (output >= GPIO_OUT_MAX)
		return -ERINVAL;

	pos = pin / MAX_GPIO_REG_BITS;
	bit = pin % MAX_GPIO_REG_BITS;

	/* To reduce memory usage, we don't use DATAOUT_addr[] array*/
	if (output == GPIO_OUT_ZERO)
		GPIO_WR32(&obj->reg->dout[pos].rst, 1UL << bit);
	else
		GPIO_WR32(&obj->reg->dout[pos].set, 1UL << bit);

	return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_out_chip(u32 pin)
{
	u32 pos;
	u32 bit;
	u32 reg;
	struct mt_gpio_obj *obj = gpio_obj;

	if (!obj)
		return -ERACCESS;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	pos = pin / MAX_GPIO_REG_BITS;
	bit = pin % MAX_GPIO_REG_BITS;

	/* To reduce memory usage, we don't use DATAOUT_addr[] array*/
	reg = GPIO_RD32(&obj->reg->dout[pos].val);
	return (((reg & (1UL << bit)) != 0)? 1: 0);
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_in_chip(u32 pin)
{
	u32 pos;
	u32 bit;
	u32 reg;
	struct mt_gpio_obj *obj = gpio_obj;

	if (!obj)
		return -ERACCESS;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	pos = pin / MAX_GPIO_REG_BITS;
	bit = pin % MAX_GPIO_REG_BITS;

	/* To reduce memory usage, we don't use DIN_addr[] array*/
	reg = GPIO_RD32(&obj->reg->din[pos].val);
	return (((reg & (1UL << bit)) != 0)? 1: 0);
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_mode_chip(u32 pin, u32 mode)
{
	unsigned long pos;
	unsigned long bit;
	unsigned long data;
	struct mt_gpio_obj *obj = gpio_obj;
	u32 mask;

	if (!obj)
		return -ERACCESS;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if (mode >= GPIO_MODE_MAX)
		return -ERINVAL;

#ifdef SUPPORT_MODE_MWR
	mask = (1UL << (GPIO_MODE_BITS - 1)) - 1;
#else
	mask = (1UL << GPIO_MODE_BITS) - 1;
#endif

	mode = mode & mask;
	pos = pin / MAX_GPIO_MODE_PER_REG;
	bit = (pin % MAX_GPIO_MODE_PER_REG) * GPIO_MODE_BITS;

#ifdef SUPPORT_MODE_MWR
	data = (1UL << (bit + GPIO_MODE_BITS - 1)) | (mode << bit);
	GPIO_WR32(&obj->reg->mode[pos]._align1, data);
#else
	data = GPIO_RD32(&obj->reg->mode[pos].val);
	data &= (~(mask << bit));
	data |= (mode << bit);
	GPIO_WR32(&obj->reg->mode[pos].val, data);
#endif

	return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_mode_chip(u32 pin)
{
	unsigned long pos;
	unsigned long bit;
	unsigned long data;
	u32 mask;
	struct mt_gpio_obj *obj = gpio_obj;

	if (!obj)
		return -ERACCESS;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

#ifdef SUPPORT_MODE_MWR
	mask = (1UL << (GPIO_MODE_BITS - 1)) - 1;
#else
	mask = (1UL << GPIO_MODE_BITS) - 1;
#endif

	pos = pin / MAX_GPIO_MODE_PER_REG;
	bit = (pin % MAX_GPIO_MODE_PER_REG) * GPIO_MODE_BITS;

	data = GPIO_RD32(&obj->reg->mode[pos].val);
	return (data >> bit) & mask;
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_smt_chip(u32 pin, u32 enable)
{
	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if (SMT_offset[pin].offset == (s8)-1)
		return GPIO_SMT_UNSUPPORTED;

	if (enable == GPIO_SMT_DISABLE)
		GPIO_CLR_BITS(SMT_addr[pin].addr, 1UL << SMT_offset[pin].offset);
	else
		GPIO_SET_BITS(SMT_addr[pin].addr, 1UL << SMT_offset[pin].offset);

	return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_smt_chip(u32 pin)
{
	u32 reg;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if (SMT_offset[pin].offset == (s8)-1)
		return GPIO_SMT_UNSUPPORTED;

	reg = GPIO_RD32(SMT_addr[pin].addr);
	return ((reg & (1UL << SMT_offset[pin].offset)) ? 1 : 0);
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_ies_chip(u32 pin, u32 enable)
{
	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if (IES_offset[pin].offset == (s8)-1)
		return GPIO_IES_UNSUPPORTED;

	if (enable == GPIO_IES_DISABLE)
		GPIO_CLR_BITS(IES_addr[pin].addr, 1UL << IES_offset[pin].offset);
	else
		GPIO_SET_BITS(IES_addr[pin].addr, 1UL << IES_offset[pin].offset);

	return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_ies_chip(u32 pin)
{
	u32 reg;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if (IES_offset[pin].offset == (s8)-1)
		return GPIO_IES_UNSUPPORTED;

	reg = GPIO_RD32(IES_addr[pin].addr);
	return ((reg & (1UL << IES_offset[pin].offset)) ? 1 : 0);
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_pull_enable_chip(u32 pin, u32 en)
{
	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if ((PU_offset[pin].offset == (s8)-1) && (PUPD_offset[pin].offset == (s8)-1))
		return GPIO_PULL_EN_UNSUPPORTED;

	if (en == GPIO_PULL_DISABLE) {
		if (PU_offset[pin].offset == (s8)-1) {
			GPIO_CLR_BITS(R0_addr[pin].addr, 1UL << R0_offset[pin].offset);
			GPIO_CLR_BITS(R1_addr[pin].addr, 1UL << R1_offset[pin].offset);
		} else {
			GPIO_CLR_BITS(PU_addr[pin].addr, 1UL << PU_offset[pin].offset);
			GPIO_CLR_BITS(PD_addr[pin].addr, 1UL << PD_offset[pin].offset);
		}
	} else if (en == GPIO_PULL_ENABLE) {
		if (PU_offset[pin].offset == (s8)-1) {
			/* For PUPD+R0+R1 Type, mt_set_gpio_pull_enable does not know
			 * which one between PU and PD shall be enabled.
			 * Use R0 to guarantee at one resistor is set when lk
			 * apply default setting
			 */
			GPIO_SET_BITS(R0_addr[pin].addr, 1UL << R0_offset[pin].offset);
			GPIO_CLR_BITS(R1_addr[pin].addr, 1UL << R1_offset[pin].offset);
		} else {
			/* For PU + PD Ttype, mt_set_gpio_pull_enable does not know
			 * which one between PU and PD shall be enabled.
			 * Use mt_set_gpio_pull_select() or GPIO_PULL_ENABLE_Rx instead.
			 */
			 return GPIO_PULL_EN_UNSUPPORTED;
		}
	} else if (en == GPIO_PULL_ENABLE_R0) {
		if (PUPD_offset[pin].offset == (s8)-1)
			return GPIO_PULL_EN_UNSUPPORTED;
		/* IOConfig does not support MWR operation, so use CLR + SET */
		GPIO_SET_BITS(R0_addr[pin].addr, 1UL << R0_offset[pin].offset);
		GPIO_CLR_BITS(R1_addr[pin].addr, 1UL << R1_offset[pin].offset);
	} else if (en == GPIO_PULL_ENABLE_R1) {
		if (PUPD_offset[pin].offset == (s8)-1)
			return GPIO_PULL_EN_UNSUPPORTED;
		/* IOConfig does not support MWR operation, so use CLR + SET */
		GPIO_CLR_BITS(R0_addr[pin].addr, 1UL << R0_offset[pin].offset);
		GPIO_SET_BITS(R1_addr[pin].addr, 1UL << R1_offset[pin].offset);
	} else if (en == GPIO_PULL_ENABLE_R0R1) {
		if (PUPD_offset[pin].offset == (s8)-1)
			return GPIO_PULL_EN_UNSUPPORTED;
		GPIO_SET_BITS(R0_addr[pin].addr, 1UL << R0_offset[pin].offset);
		GPIO_SET_BITS(R1_addr[pin].addr, 1UL << R1_offset[pin].offset);
	} else {
		return -ERINVAL;
	}

	return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_pull_enable_chip(u32 pin)
{
	u32 reg, reg2;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if ((PU_offset[pin].offset == (s8)-1) && (PUPD_offset[pin].offset == (s8)-1))
		return GPIO_PULL_EN_UNSUPPORTED;

	if (PU_offset[pin].offset == (s8)-1) {
		reg = (GPIO_RD32(R0_addr[pin].addr) >> R0_offset[pin].offset) & 1;
		reg2 = (GPIO_RD32(R1_addr[pin].addr) >> R1_offset[pin].offset) & 1;
		return ((reg | reg2) ? 1 : 0);
	} else if (PUPD_offset[pin].offset == (s8)-1) {
		reg = (GPIO_RD32(PU_addr[pin].addr) >> PU_offset[pin].offset) & 1;
		reg2 = (GPIO_RD32(PD_addr[pin].addr) >> PD_offset[pin].offset) & 1;
		return ((reg | reg2) ? 1 : 0);
	}

	return -ERINVAL;
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_pull_select_chip(u32 pin, u32 sel)
{
	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if ((PU_offset[pin].offset == (s8)-1) && (PUPD_offset[pin].offset == (s8)-1))
		return GPIO_PULL_UNSUPPORTED;

	if (sel == GPIO_NO_PULL) {
		mt_set_gpio_pull_enable_chip(pin, GPIO_PULL_DISABLE);
		if (PU_offset[pin].offset == (s8)-1) {
			GPIO_SET_BITS(PUPD_addr[pin].addr, 1UL << PUPD_offset[pin].offset);
		} else {
			/* do nothting since already modified in mt_set_gpio_pull_enable_chip */
		}
	} else if (sel == GPIO_PULL_UP) {
		if (PU_offset[pin].offset == (s8)-1)
			GPIO_CLR_BITS(PUPD_addr[pin].addr, 1UL << PUPD_offset[pin].offset);
		else {
			GPIO_SET_BITS(PU_addr[pin].addr, 1UL << PU_offset[pin].offset);
			GPIO_CLR_BITS(PD_addr[pin].addr, 1UL << PD_offset[pin].offset);
		}
	} else if (sel == GPIO_PULL_DOWN) {
		if (PU_offset[pin].offset == (s8)-1)
			GPIO_SET_BITS(PUPD_addr[pin].addr, 1UL << PUPD_offset[pin].offset);
		else {
			GPIO_CLR_BITS(PU_addr[pin].addr, 1UL << PU_offset[pin].offset);
			GPIO_SET_BITS(PD_addr[pin].addr, 1UL << PD_offset[pin].offset);
		}
	} else {
		return -ERINVAL;
	}

	return RSUCCESS;
}
/*---------------------------------------------------------------------------*/
/* get pull-up or pull-down, regardless of resistor value */
s32 mt_get_gpio_pull_select_chip(u32 pin)
{
	u32 reg, reg2;

	if (pin >= MAX_GPIO_PIN)
		return -ERINVAL;

	if ((PU_offset[pin].offset == (s8)-1) && (PUPD_offset[pin].offset == (s8)-1))
		return GPIO_PULL_UNSUPPORTED;

	if (PU_offset[pin].offset == (s8)-1) {
		reg = GPIO_RD32(PUPD_addr[pin].addr);
		/* Reg value: 0 for PU, 1 for PD --> reverse return value */
		return (s32)((reg & (1UL << PUPD_offset[pin].offset)) ? GPIO_PULL_DOWN : GPIO_PULL_UP);
	} else if (PUPD_offset[pin].offset == (s8)-1) {
		reg = (GPIO_RD32(PU_addr[pin].addr) >> PU_offset[pin].offset) & 1;
		reg2 = (GPIO_RD32(PD_addr[pin].addr) >> PD_offset[pin].offset) & 1;
		if (reg)
			return GPIO_PULL_UP;
		else if (reg2)
			return GPIO_PULL_DOWN;
		else
			return GPIO_NO_PULL;
	}

	return -ERINVAL;
}
/*---------------------------------------------------------------------------*/
void mt_gpio_pin_decrypt(u32 *cipher)
{
	//just for debug, find out who used pin number directly
	if ((*cipher & (0x80000000)) == 0) {
		//GPIOERR("Pin %d decrypt warning! \n",*cipher);
		//dump_stack();
		//return;
	}

	//GPIOERR("Pin magic number is %x\n",*cipher);
	*cipher &= ~(0x80000000);
	return;
}
/*---------------------------------------------------------------------------*/
S32 mt_set_gpio_drv(u32 pin, u32 drv)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_set_gpio_drv_chip(pin,drv);
}
/*---------------------------------------------------------------------------*/
S32 mt_get_gpio_drv(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_get_gpio_drv_chip(pin);
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_dir(u32 pin, u32 dir)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_set_gpio_dir_chip(pin,dir);
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_dir(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_get_gpio_dir_chip(pin);
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_pull_enable(u32 pin, u32 enable)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_set_gpio_pull_enable_chip(pin,enable);
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_pull_enable(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_get_gpio_pull_enable_chip(pin);
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_pull_select(u32 pin, u32 select)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_set_gpio_pull_select_chip(pin,select);
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_pull_select(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_get_gpio_pull_select_chip(pin);
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_smt(u32 pin, u32 enable)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_set_gpio_smt_chip(pin,enable);
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_smt(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_get_gpio_smt_chip(pin);
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_ies(u32 pin, u32 enable)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_set_gpio_ies_chip(pin,enable);
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_ies(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_get_gpio_ies_chip(pin);
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_out(u32 pin, u32 output)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_set_gpio_out_chip(pin,output);
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_out(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_get_gpio_out_chip(pin);
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_in(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_get_gpio_in_chip(pin);
}
/*---------------------------------------------------------------------------*/
s32 mt_set_gpio_mode(u32 pin, u32 mode)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_set_gpio_mode_chip(pin,mode);
}
/*---------------------------------------------------------------------------*/
s32 mt_get_gpio_mode(u32 pin)
{
	mt_gpio_pin_decrypt(&pin);
	return mt_get_gpio_mode_chip(pin);
}
/*****************************************************************************/
/* Self test operation                                                           */
/*****************************************************************************/
#if GPIO_SELF_TEST
void mt_gpio_self_test(void)
{
	int i, val;
	for (i = 0; i < GPIO_MAX; i++) {
		s32 res,old;
		GPIOMSG("GPIO-%3d test\n", i);
		/*direction test*/
		old = mt_get_gpio_dir(i);
		if (old == 0 || old == 1) {
			GPIOLOG(" dir old = %d\n", old);
		} else {
			GPIOERR(" test dir fail: %d\n", old);
			break;
		}
		if ((res = mt_set_gpio_dir(i, GPIO_DIR_OUT)) != RSUCCESS) {
			GPIOERR(" set dir out fail: %d\n", res);
			break;
		} else if ((res = mt_get_gpio_dir(i)) != GPIO_DIR_OUT) {
			GPIOERR(" get dir out fail: %d\n", res);
			break;
		} else {
			/*output test*/
			s32 out = mt_get_gpio_out(i);
			if (out != 0 && out != 1) {
				GPIOERR(" get out fail = %d\n", old);
				break;
			}
			for (val = 0; val < GPIO_OUT_MAX; val++) {
				if ((res = mt_set_gpio_out(i,0)) != RSUCCESS) {
					GPIOERR(" set out[%d] fail: %d\n", val, res);
					break;
				} else if ((res = mt_get_gpio_out(i)) != 0) {
					GPIOERR(" get out[%d] fail: %d\n", val, res);
					break;
				}
			}
			if ((res = mt_set_gpio_out(i,out)) != RSUCCESS) {
				GPIOERR(" restore out fail: %d\n", res);
				break;
			}
		}

		if ((res = mt_set_gpio_dir(i, GPIO_DIR_IN)) != RSUCCESS) {
			GPIOERR(" set dir in fail: %d\n", res);
			break;
		} else if ((res = mt_get_gpio_dir(i)) != GPIO_DIR_IN) {
			GPIOERR(" get dir in fail: %d\n", res);
			break;
		} else {
			GPIOLOG(" input data = %d\n", res);
		}

		if ((res = mt_set_gpio_dir(i, old)) != RSUCCESS) {
			GPIOERR(" restore dir fail: %d\n", res);
			break;
		}
		for (val = 0; val < GPIO_PULL_EN_MAX; val++) {
			if ((res = mt_set_gpio_pull_enable(i,val)) != RSUCCESS) {
				GPIOERR(" set pullen[%d] fail: %d\n", val, res);
				break;
			} else if ((res = mt_get_gpio_pull_enable(i)) != val) {
				GPIOERR(" get pullen[%d] fail: %d\n", val, res);
				break;
			}
		}
		if ((res = mt_set_gpio_pull_enable(i, old)) != RSUCCESS) {
			GPIOERR(" restore pullen fail: %d\n", res);
			break;
		}

		/*pull select test*/
		old = mt_get_gpio_pull_select(i);
		if (old == 0 || old == 1)
			GPIOLOG(" pullsel old = %d\n", old);
		else {
			GPIOERR(" pullsel fail: %d\n", old);
			break;
		}
		for (val = 0; val < GPIO_PULL_MAX; val++) {
			if ((res = mt_set_gpio_pull_select(i,val)) != RSUCCESS) {
				GPIOERR(" set pullsel[%d] fail: %d\n", val, res);
				break;
			} else if ((res = mt_get_gpio_pull_select(i)) != val) {
				GPIOERR(" get pullsel[%d] fail: %d\n", val, res);
				break;
			}
		}
		if ((res = mt_set_gpio_pull_select(i, old)) != RSUCCESS) {
			GPIOERR(" restore pullsel fail: %d\n", res);
			break;
		}

		/*mode control*/
		old = mt_get_gpio_mode(i);
		if ((old >= GPIO_MODE_00) && (val < GPIO_MODE_MAX)) {
			GPIOLOG(" mode old = %d\n", old);
		} else {
			GPIOERR(" get mode fail: %d\n", old);
			break;
		}
		for (val = 0; val < GPIO_MODE_MAX; val++) {
			if ((res = mt_set_gpio_mode(i, val)) != RSUCCESS) {
				GPIOERR("set mode[%d] fail: %d\n", val, res);
				break;
			} else if ((res = mt_get_gpio_mode(i)) != val) {
				GPIOERR("get mode[%d] fail: %d\n", val, res);
				break;
			}
		}
		if ((res = mt_set_gpio_mode(i,old)) != RSUCCESS) {
			GPIOERR(" restore mode fail: %d\n", res);
			break;
		}
	}
	GPIOLOG("GPIO test done\n");
}
/*----------------------------------------------------------------------------*/
void mt_gpio_dump(void)
{
	GPIO_REGS *regs = (GPIO_REGS*)(GPIO_BASE);
	int idx;

	GPIOMSG("---# dir #-----------------------------------------------------------------\n");
	for (idx = 0; idx < sizeof(regs->dir)/sizeof(regs->dir[0]); idx++) {
		GPIOMSG("0x%04X ", regs->dir[idx].val);
		if (7 == (idx % 8)) GPIOMSG("\n");
	}
#if 0
	GPIOMSG("\n---# pullen #--------------------------------------------------------------\n");
	for (idx = 0; idx < sizeof(regs->pullen)/sizeof(regs->pullen[0]); idx++) {
		GPIOMSG("0x%04X ", regs->pullen[idx].val);
		if (7 == (idx % 8)) GPIOMSG("\n");
	}
	GPIOMSG("\n---# pullsel #-------------------------------------------------------------\n");
	for (idx = 0; idx < sizeof(regs->pullsel)/sizeof(regs->pullsel[0]); idx++) {
		GPIOMSG("0x%04X ", regs->pullsel[idx].val);
		if (7 == (idx % 8)) GPIOMSG("\n");
	}
#endif
	GPIOMSG("\n---# dout #----------------------------------------------------------------\n");
	for (idx = 0; idx < sizeof(regs->dout)/sizeof(regs->dout[0]); idx++) {
		GPIOMSG("0x%04X ", regs->dout[idx].val);
		if (7 == (idx % 8)) GPIOMSG("\n");
	}
	GPIOMSG("\n---# din  #----------------------------------------------------------------\n");
	for (idx = 0; idx < sizeof(regs->din)/sizeof(regs->din[0]); idx++) {
		GPIOMSG("0x%04X ", regs->din[idx].val);
		if (7 == (idx % 8)) GPIOMSG("\n");
	}
	GPIOMSG("\n---# mode #----------------------------------------------------------------\n");
	for (idx = 0; idx < sizeof(regs->mode)/sizeof(regs->mode[0]); idx++) {
		GPIOMSG("0x%04X ", regs->mode[idx].val);
		if (7 == (idx % 8)) GPIOMSG("\n");
	}
#if 0
	GPIOMSG("sim0 0x%04X ", regs->sim_ctrl[0].val);
	GPIOMSG("sim1 0x%04X ", regs->sim_ctrl[1].val);
	GPIOMSG("sim2 0x%04X ", regs->sim_ctrl[2].val);
	GPIOMSG("sim3 0x%04X ", regs->sim_ctrl[3].val);

	GPIOMSG("keypad0 0x%04X ", regs->kpad_ctrl[0].val);
	GPIOMSG("keypad1 0x%04X ", regs->kpad_ctrl[1].val);
#endif

	GPIOMSG("\n---------------------------------------------------------------------------\n");
}
/*---------------------------------------------------------------------------*/
#if 0
void mt_gpio_read_pin(GPIO_CFG* cfg, int method)
{
	if (method == 0) {
		GPIO_REGS *cur = (GPIO_REGS*)GPIO_BASE;
		u32 mask = (1UL << GPIO_MODE_BITS) - 1;
		int num, bit,idx=cfg->no;
		num = idx / MAX_GPIO_REG_BITS;
		bit = idx % MAX_GPIO_REG_BITS;
		cfg->pullsel= (cur->pullsel[num].val & (1UL << bit)) ? (1) : (0);
		cfg->din    = (cur->din[num].val & (1UL << bit)) ? (1) : (0);
		cfg->dout   = (cur->dout[num].val & (1UL << bit)) ? (1) : (0);
		cfg->pullen = (cur->pullen[num].val & (1UL << bit)) ? (1) : (0);
		cfg->dir    = (cur->dir[num].val & (1UL << bit)) ? (1) : (0);
		num = idx / MAX_GPIO_MODE_PER_REG;
		bit = idx % MAX_GPIO_MODE_PER_REG;
		cfg->mode   = (cur->mode[num].val >> (GPIO_MODE_BITS*bit)) & mask;
	} else if (method == 1) {
		int idx=cfg->no;
		cfg->pullsel= mt_get_gpio_pull_select(idx);
		cfg->din    = mt_get_gpio_in(idx);
		cfg->dout   = mt_get_gpio_out(idx);
		cfg->pullen = mt_get_gpio_pull_enable(idx);
		cfg->dir    = mt_get_gpio_dir(idx);
		cfg->mode   = mt_get_gpio_mode(idx);
	}
}
#endif
/*---------------------------------------------------------------------------*/
void mt_gpio_dump_addr(void)
{
	int idx;
	struct mt_gpio_obj *obj = gpio_obj;
	GPIO_REGS *reg = obj->reg;

	GPIOMSG("# direction\n");
	for (idx = 0; idx < sizeof(reg->dir)/sizeof(reg->dir[0]); idx++)
		GPIOMSG("val[%2d] %p\nset[%2d] %p\nrst[%2d] %p\n", idx, &reg->dir[idx].val, idx, &reg->dir[idx].set, idx, &reg->dir[idx].rst);
#if 0
	GPIOMSG("# pull enable\n");
	for (idx = 0; idx < sizeof(reg->pullen)/sizeof(reg->pullen[0]); idx++)
		GPIOMSG("val[%2d] %p\nset[%2d] %p\nrst[%2d] %p\n", idx, &reg->pullen[idx].val, idx, &reg->pullen[idx].set, idx, &reg->pullen[idx].rst);
	GPIOMSG("# pull select\n");
	for (idx = 0; idx < sizeof(reg->pullsel)/sizeof(reg->pullsel[0]); idx++)
		GPIOMSG("val[%2d] %p\nset[%2d] %p\nrst[%2d] %p\n", idx, &reg->pullsel[idx].val, idx, &reg->pullsel[idx].set, idx, &reg->pullsel[idx].rst);
#endif
	GPIOMSG("# data output\n");
	for (idx = 0; idx < sizeof(reg->dout)/sizeof(reg->dout[0]); idx++)
		GPIOMSG("val[%2d] %p\nset[%2d] %p\nrst[%2d] %p\n", idx, &reg->dout[idx].val, idx, &reg->dout[idx].set, idx, &reg->dout[idx].rst);
	GPIOMSG("# data input\n");
	for (idx = 0; idx < sizeof(reg->din)/sizeof(reg->din[0]); idx++)
		GPIOMSG("val[%2d] %p\n", idx, &reg->din[idx].val);
	GPIOMSG("# mode\n");
	for (idx = 0; idx < sizeof(reg->mode)/sizeof(reg->mode[0]); idx++)
		GPIOMSG("val[%2d] %p\nset[%2d] %p\nrst[%2d] %p\n", idx, &reg->mode[idx].val, idx, &reg->mode[idx].set, idx, &reg->mode[idx].rst);
}
#endif
#endif
