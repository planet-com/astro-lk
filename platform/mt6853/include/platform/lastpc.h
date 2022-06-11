/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2016. All rights reserved.
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
#define DFD_REG_LENGTH              64
#define DFD_SW_V3_WA

//#define ENABLE_RETURN_STACK
#define SUPPORT_CACHE_DUMP

struct bit_pair { 
    unsigned int raw_offset;
    unsigned int bit_offset;
    unsigned int inv;
}; 

struct reg_collector { 
    struct bit_pair bit_pairs[DFD_REG_LENGTH]; 
}; 
struct little_core_spec {
	struct reg_collector spmc_power_state;
	struct reg_collector pc;
	struct reg_collector sp32;
	struct reg_collector fp32;
	struct reg_collector fp64;
	struct reg_collector sp_EL0;
	struct reg_collector sp_EL1;
	struct reg_collector sp_EL2;
	struct reg_collector sp_EL3;
	struct reg_collector elr_EL1;
	struct reg_collector elr_EL2;
	struct reg_collector elr_EL3;
	struct reg_collector raw_pc;
	struct reg_collector pc_iss;
	struct reg_collector full_pc_wr;
	struct reg_collector full_pc_ex1;
	struct reg_collector full_pc_ex2;
	struct reg_collector return_Stack_pointer;
	struct reg_collector return_Stack0;
	struct reg_collector return_Stack1;
	struct reg_collector return_Stack2;
	struct reg_collector return_Stack3;
	struct reg_collector return_Stack4;
	struct reg_collector return_Stack5;
	struct reg_collector return_Stack6;
	struct reg_collector return_Stack7;

};

struct big_core_spec {
	struct reg_collector edpcsr;
	struct reg_collector spmc_power_state;
	struct reg_collector i0_valid;
	struct reg_collector i0_pc;
	struct reg_collector i1_valid;
	struct reg_collector i1_pc;
	struct reg_collector last_branch;
	struct reg_collector sram_wr_ptr;
};

struct power_spec {
	struct reg_collector power_state;
};

struct mcusys_spec {
	struct reg_collector M0_AR_Pending_Counter;
	struct reg_collector M0_AW_Pending_Counter;
	struct reg_collector M1_AR_Pending_Counter;
	struct reg_collector M1_AW_Pending_Counter;
	struct reg_collector M2_AR_Pending_Counter;
	struct reg_collector M2_AW_Pending_Counter;
	struct reg_collector S0_AR_Pending_Counter;
	struct reg_collector S0_AW_Pending_Counter;
	struct reg_collector S1_AR_Pending_Counter;
	struct reg_collector S1_AW_Pending_Counter;
	struct reg_collector S2_AR_Pending_Counter;
	struct reg_collector S2_AW_Pending_Counter;
	struct reg_collector S3_AR_Pending_Counter;
	struct reg_collector S3_AW_Pending_Counter;
	struct reg_collector S4_AR_Pending_Counter;
	struct reg_collector S4_AW_Pending_Counter;
	struct reg_collector mp0_parity_err;
	struct reg_collector mp0_parity_index;
	struct reg_collector mp0_parity_banks;
	struct reg_collector mp0_parity_err_count;
	struct reg_collector mp1_parity_err;
	struct reg_collector mp1_parity_index;
	struct reg_collector mp1_parity_banks;
	struct reg_collector mp1_parity_err_count;
	struct reg_collector mp2_parity_err;
	struct reg_collector mp2_parity_index;
	struct reg_collector mp2_parity_banks;
	struct reg_collector mp2_parity_err_count;
	struct reg_collector mp0_L3_parity_err;
	struct reg_collector mp0_L3_parity_index;
	struct reg_collector mp0_L3_parity_bank;
	struct reg_collector mp0_L3_parity_err_count;
	struct reg_collector mp0_L3_parity_sap;
	struct reg_collector dfd_v35_enable;
};

struct power_spec spmc_power_state[] = {
	{		
			.power_state = {{
			{    0, 0,0}, /* core0 power_state bit0 */
			{    0,10,0}, /* core0 power_state bit1 */
			{    0, 0,2}, /* core0 power_state bit2 */
			{    0, 0,2}, /* core0 power_state bit3 */
			{    0, 0,2}, /* core0 power_state bit4 */
			{    0, 0,2}, /* core0 power_state bit5 */
			{    0, 0,2}, /* core0 power_state bit6 */
			{    0, 0,2}, /* core0 power_state bit7 */
			{    0, 0,2}, /* core0 power_state bit8 */
			{    0, 0,2}, /* core0 power_state bit9 */
			{    0, 0,2}, /* core0 power_state bit10 */
			{    0, 0,2}, /* core0 power_state bit11 */
			{    0, 0,2}, /* core0 power_state bit12 */
			{    0, 0,2}, /* core0 power_state bit13 */
			{    0, 0,2}, /* core0 power_state bit14 */
			{    0, 0,2}, /* core0 power_state bit15 */
			{    0, 0,2}, /* core0 power_state bit16 */
			{    0, 0,2}, /* core0 power_state bit17 */
			{    0, 0,2}, /* core0 power_state bit18 */
			{    0, 0,2}, /* core0 power_state bit19 */
			{    0, 0,2}, /* core0 power_state bit20 */
			{    0, 0,2}, /* core0 power_state bit21 */
			{    0, 0,2}, /* core0 power_state bit22 */
			{    0, 0,2}, /* core0 power_state bit23 */
			{    0, 0,2}, /* core0 power_state bit24 */
			{    0, 0,2}, /* core0 power_state bit25 */
			{    0, 0,2}, /* core0 power_state bit26 */
			{    0, 0,2}, /* core0 power_state bit27 */
			{    0, 0,2}, /* core0 power_state bit28 */
			{    0, 0,2}, /* core0 power_state bit29 */
			{    0, 0,2}, /* core0 power_state bit30 */
			{    0, 0,2}, /* core0 power_state bit31 */
			{    0, 0,2}, /* core0 power_state bit32 */
			{    0, 0,2}, /* core0 power_state bit33 */
			{    0, 0,2}, /* core0 power_state bit34 */
			{    0, 0,2}, /* core0 power_state bit35 */
			{    0, 0,2}, /* core0 power_state bit36 */
			{    0, 0,2}, /* core0 power_state bit37 */
			{    0, 0,2}, /* core0 power_state bit38 */
			{    0, 0,2}, /* core0 power_state bit39 */
			{    0, 0,2}, /* core0 power_state bit40 */
			{    0, 0,2}, /* core0 power_state bit41 */
			{    0, 0,2}, /* core0 power_state bit42 */
			{    0, 0,2}, /* core0 power_state bit43 */
			{    0, 0,2}, /* core0 power_state bit44 */
			{    0, 0,2}, /* core0 power_state bit45 */
			{    0, 0,2}, /* core0 power_state bit46 */
			{    0, 0,2}, /* core0 power_state bit47 */
			{    0, 0,2}, /* core0 power_state bit48 */
			{    0, 0,2}, /* core0 power_state bit49 */
			{    0, 0,2}, /* core0 power_state bit50 */
			{    0, 0,2}, /* core0 power_state bit51 */
			{    0, 0,2}, /* core0 power_state bit52 */
			{    0, 0,2}, /* core0 power_state bit53 */
			{    0, 0,2}, /* core0 power_state bit54 */
			{    0, 0,2}, /* core0 power_state bit55 */
			{    0, 0,2}, /* core0 power_state bit56 */
			{    0, 0,2}, /* core0 power_state bit57 */
			{    0, 0,2}, /* core0 power_state bit58 */
			{    0, 0,2}, /* core0 power_state bit59 */
			{    0, 0,2}, /* core0 power_state bit60 */
			{    0, 0,2}, /* core0 power_state bit61 */
			{    0, 0,2}, /* core0 power_state bit62 */
			{    0, 0,2}, /* core0 power_state bit63 */
			}},
	},
	{	/* core 1 */
			.power_state = {{
			{    0, 1,0}, /* core1 power_state bit0 */
			{    0,11,0}, /* core1 power_state bit1 */
			{    0, 0,2}, /* core1 power_state bit2 */
			{    0, 0,2}, /* core1 power_state bit3 */
			{    0, 0,2}, /* core1 power_state bit4 */
			{    0, 0,2}, /* core1 power_state bit5 */
			{    0, 0,2}, /* core1 power_state bit6 */
			{    0, 0,2}, /* core1 power_state bit7 */
			{    0, 0,2}, /* core1 power_state bit8 */
			{    0, 0,2}, /* core1 power_state bit9 */
			{    0, 0,2}, /* core1 power_state bit10 */
			{    0, 0,2}, /* core1 power_state bit11 */
			{    0, 0,2}, /* core1 power_state bit12 */
			{    0, 0,2}, /* core1 power_state bit13 */
			{    0, 0,2}, /* core1 power_state bit14 */
			{    0, 0,2}, /* core1 power_state bit15 */
			{    0, 0,2}, /* core1 power_state bit16 */
			{    0, 0,2}, /* core1 power_state bit17 */
			{    0, 0,2}, /* core1 power_state bit18 */
			{    0, 0,2}, /* core1 power_state bit19 */
			{    0, 0,2}, /* core1 power_state bit20 */
			{    0, 0,2}, /* core1 power_state bit21 */
			{    0, 0,2}, /* core1 power_state bit22 */
			{    0, 0,2}, /* core1 power_state bit23 */
			{    0, 0,2}, /* core1 power_state bit24 */
			{    0, 0,2}, /* core1 power_state bit25 */
			{    0, 0,2}, /* core1 power_state bit26 */
			{    0, 0,2}, /* core1 power_state bit27 */
			{    0, 0,2}, /* core1 power_state bit28 */
			{    0, 0,2}, /* core1 power_state bit29 */
			{    0, 0,2}, /* core1 power_state bit30 */
			{    0, 0,2}, /* core1 power_state bit31 */
			{    0, 0,2}, /* core1 power_state bit32 */
			{    0, 0,2}, /* core1 power_state bit33 */
			{    0, 0,2}, /* core1 power_state bit34 */
			{    0, 0,2}, /* core1 power_state bit35 */
			{    0, 0,2}, /* core1 power_state bit36 */
			{    0, 0,2}, /* core1 power_state bit37 */
			{    0, 0,2}, /* core1 power_state bit38 */
			{    0, 0,2}, /* core1 power_state bit39 */
			{    0, 0,2}, /* core1 power_state bit40 */
			{    0, 0,2}, /* core1 power_state bit41 */
			{    0, 0,2}, /* core1 power_state bit42 */
			{    0, 0,2}, /* core1 power_state bit43 */
			{    0, 0,2}, /* core1 power_state bit44 */
			{    0, 0,2}, /* core1 power_state bit45 */
			{    0, 0,2}, /* core1 power_state bit46 */
			{    0, 0,2}, /* core1 power_state bit47 */
			{    0, 0,2}, /* core1 power_state bit48 */
			{    0, 0,2}, /* core1 power_state bit49 */
			{    0, 0,2}, /* core1 power_state bit50 */
			{    0, 0,2}, /* core1 power_state bit51 */
			{    0, 0,2}, /* core1 power_state bit52 */
			{    0, 0,2}, /* core1 power_state bit53 */
			{    0, 0,2}, /* core1 power_state bit54 */
			{    0, 0,2}, /* core1 power_state bit55 */
			{    0, 0,2}, /* core1 power_state bit56 */
			{    0, 0,2}, /* core1 power_state bit57 */
			{    0, 0,2}, /* core1 power_state bit58 */
			{    0, 0,2}, /* core1 power_state bit59 */
			{    0, 0,2}, /* core1 power_state bit60 */
			{    0, 0,2}, /* core1 power_state bit61 */
			{    0, 0,2}, /* core1 power_state bit62 */
			{    0, 0,2}, /* core1 power_state bit63 */
			}},
	},
	{	/* core 2 */
			.power_state = {{
			{    0, 2,0}, /* core2 power_state bit0 */
			{    0,12,0}, /* core2 power_state bit1 */
			{    0, 0,2}, /* core2 power_state bit2 */
			{    0, 0,2}, /* core2 power_state bit3 */
			{    0, 0,2}, /* core2 power_state bit4 */
			{    0, 0,2}, /* core2 power_state bit5 */
			{    0, 0,2}, /* core2 power_state bit6 */
			{    0, 0,2}, /* core2 power_state bit7 */
			{    0, 0,2}, /* core2 power_state bit8 */
			{    0, 0,2}, /* core2 power_state bit9 */
			{    0, 0,2}, /* core2 power_state bit10 */
			{    0, 0,2}, /* core2 power_state bit11 */
			{    0, 0,2}, /* core2 power_state bit12 */
			{    0, 0,2}, /* core2 power_state bit13 */
			{    0, 0,2}, /* core2 power_state bit14 */
			{    0, 0,2}, /* core2 power_state bit15 */
			{    0, 0,2}, /* core2 power_state bit16 */
			{    0, 0,2}, /* core2 power_state bit17 */
			{    0, 0,2}, /* core2 power_state bit18 */
			{    0, 0,2}, /* core2 power_state bit19 */
			{    0, 0,2}, /* core2 power_state bit20 */
			{    0, 0,2}, /* core2 power_state bit21 */
			{    0, 0,2}, /* core2 power_state bit22 */
			{    0, 0,2}, /* core2 power_state bit23 */
			{    0, 0,2}, /* core2 power_state bit24 */
			{    0, 0,2}, /* core2 power_state bit25 */
			{    0, 0,2}, /* core2 power_state bit26 */
			{    0, 0,2}, /* core2 power_state bit27 */
			{    0, 0,2}, /* core2 power_state bit28 */
			{    0, 0,2}, /* core2 power_state bit29 */
			{    0, 0,2}, /* core2 power_state bit30 */
			{    0, 0,2}, /* core2 power_state bit31 */
			{    0, 0,2}, /* core2 power_state bit32 */
			{    0, 0,2}, /* core2 power_state bit33 */
			{    0, 0,2}, /* core2 power_state bit34 */
			{    0, 0,2}, /* core2 power_state bit35 */
			{    0, 0,2}, /* core2 power_state bit36 */
			{    0, 0,2}, /* core2 power_state bit37 */
			{    0, 0,2}, /* core2 power_state bit38 */
			{    0, 0,2}, /* core2 power_state bit39 */
			{    0, 0,2}, /* core2 power_state bit40 */
			{    0, 0,2}, /* core2 power_state bit41 */
			{    0, 0,2}, /* core2 power_state bit42 */
			{    0, 0,2}, /* core2 power_state bit43 */
			{    0, 0,2}, /* core2 power_state bit44 */
			{    0, 0,2}, /* core2 power_state bit45 */
			{    0, 0,2}, /* core2 power_state bit46 */
			{    0, 0,2}, /* core2 power_state bit47 */
			{    0, 0,2}, /* core2 power_state bit48 */
			{    0, 0,2}, /* core2 power_state bit49 */
			{    0, 0,2}, /* core2 power_state bit50 */
			{    0, 0,2}, /* core2 power_state bit51 */
			{    0, 0,2}, /* core2 power_state bit52 */
			{    0, 0,2}, /* core2 power_state bit53 */
			{    0, 0,2}, /* core2 power_state bit54 */
			{    0, 0,2}, /* core2 power_state bit55 */
			{    0, 0,2}, /* core2 power_state bit56 */
			{    0, 0,2}, /* core2 power_state bit57 */
			{    0, 0,2}, /* core2 power_state bit58 */
			{    0, 0,2}, /* core2 power_state bit59 */
			{    0, 0,2}, /* core2 power_state bit60 */
			{    0, 0,2}, /* core2 power_state bit61 */
			{    0, 0,2}, /* core2 power_state bit62 */
			{    0, 0,2}, /* core2 power_state bit63 */
			}},
	},
	{	/* core 3 */
			.power_state = {{
			{    0, 3,0}, /* core3 power_state bit0 */
			{    0,13,0}, /* core3 power_state bit1 */
			{    0, 0,2}, /* core3 power_state bit2 */
			{    0, 0,2}, /* core3 power_state bit3 */
			{    0, 0,2}, /* core3 power_state bit4 */
			{    0, 0,2}, /* core3 power_state bit5 */
			{    0, 0,2}, /* core3 power_state bit6 */
			{    0, 0,2}, /* core3 power_state bit7 */
			{    0, 0,2}, /* core3 power_state bit8 */
			{    0, 0,2}, /* core3 power_state bit9 */
			{    0, 0,2}, /* core3 power_state bit10 */
			{    0, 0,2}, /* core3 power_state bit11 */
			{    0, 0,2}, /* core3 power_state bit12 */
			{    0, 0,2}, /* core3 power_state bit13 */
			{    0, 0,2}, /* core3 power_state bit14 */
			{    0, 0,2}, /* core3 power_state bit15 */
			{    0, 0,2}, /* core3 power_state bit16 */
			{    0, 0,2}, /* core3 power_state bit17 */
			{    0, 0,2}, /* core3 power_state bit18 */
			{    0, 0,2}, /* core3 power_state bit19 */
			{    0, 0,2}, /* core3 power_state bit20 */
			{    0, 0,2}, /* core3 power_state bit21 */
			{    0, 0,2}, /* core3 power_state bit22 */
			{    0, 0,2}, /* core3 power_state bit23 */
			{    0, 0,2}, /* core3 power_state bit24 */
			{    0, 0,2}, /* core3 power_state bit25 */
			{    0, 0,2}, /* core3 power_state bit26 */
			{    0, 0,2}, /* core3 power_state bit27 */
			{    0, 0,2}, /* core3 power_state bit28 */
			{    0, 0,2}, /* core3 power_state bit29 */
			{    0, 0,2}, /* core3 power_state bit30 */
			{    0, 0,2}, /* core3 power_state bit31 */
			{    0, 0,2}, /* core3 power_state bit32 */
			{    0, 0,2}, /* core3 power_state bit33 */
			{    0, 0,2}, /* core3 power_state bit34 */
			{    0, 0,2}, /* core3 power_state bit35 */
			{    0, 0,2}, /* core3 power_state bit36 */
			{    0, 0,2}, /* core3 power_state bit37 */
			{    0, 0,2}, /* core3 power_state bit38 */
			{    0, 0,2}, /* core3 power_state bit39 */
			{    0, 0,2}, /* core3 power_state bit40 */
			{    0, 0,2}, /* core3 power_state bit41 */
			{    0, 0,2}, /* core3 power_state bit42 */
			{    0, 0,2}, /* core3 power_state bit43 */
			{    0, 0,2}, /* core3 power_state bit44 */
			{    0, 0,2}, /* core3 power_state bit45 */
			{    0, 0,2}, /* core3 power_state bit46 */
			{    0, 0,2}, /* core3 power_state bit47 */
			{    0, 0,2}, /* core3 power_state bit48 */
			{    0, 0,2}, /* core3 power_state bit49 */
			{    0, 0,2}, /* core3 power_state bit50 */
			{    0, 0,2}, /* core3 power_state bit51 */
			{    0, 0,2}, /* core3 power_state bit52 */
			{    0, 0,2}, /* core3 power_state bit53 */
			{    0, 0,2}, /* core3 power_state bit54 */
			{    0, 0,2}, /* core3 power_state bit55 */
			{    0, 0,2}, /* core3 power_state bit56 */
			{    0, 0,2}, /* core3 power_state bit57 */
			{    0, 0,2}, /* core3 power_state bit58 */
			{    0, 0,2}, /* core3 power_state bit59 */
			{    0, 0,2}, /* core3 power_state bit60 */
			{    0, 0,2}, /* core3 power_state bit61 */
			{    0, 0,2}, /* core3 power_state bit62 */
			{    0, 0,2}, /* core3 power_state bit63 */
			}},
	},
	{	/* core 4 */
			.power_state = {{
			{    0,32,0}, /* core4 power_state bit0 */
			{    0,42,0}, /* core4 power_state bit1 */
			{    0, 0,2}, /* core4 power_state bit2 */
			{    0, 0,2}, /* core4 power_state bit3 */
			{    0, 0,2}, /* core4 power_state bit4 */
			{    0, 0,2}, /* core4 power_state bit5 */
			{    0, 0,2}, /* core4 power_state bit6 */
			{    0, 0,2}, /* core4 power_state bit7 */
			{    0, 0,2}, /* core4 power_state bit8 */
			{    0, 0,2}, /* core4 power_state bit9 */
			{    0, 0,2}, /* core4 power_state bit10 */
			{    0, 0,2}, /* core4 power_state bit11 */
			{    0, 0,2}, /* core4 power_state bit12 */
			{    0, 0,2}, /* core4 power_state bit13 */
			{    0, 0,2}, /* core4 power_state bit14 */
			{    0, 0,2}, /* core4 power_state bit15 */
			{    0, 0,2}, /* core4 power_state bit16 */
			{    0, 0,2}, /* core4 power_state bit17 */
			{    0, 0,2}, /* core4 power_state bit18 */
			{    0, 0,2}, /* core4 power_state bit19 */
			{    0, 0,2}, /* core4 power_state bit20 */
			{    0, 0,2}, /* core4 power_state bit21 */
			{    0, 0,2}, /* core4 power_state bit22 */
			{    0, 0,2}, /* core4 power_state bit23 */
			{    0, 0,2}, /* core4 power_state bit24 */
			{    0, 0,2}, /* core4 power_state bit25 */
			{    0, 0,2}, /* core4 power_state bit26 */
			{    0, 0,2}, /* core4 power_state bit27 */
			{    0, 0,2}, /* core4 power_state bit28 */
			{    0, 0,2}, /* core4 power_state bit29 */
			{    0, 0,2}, /* core4 power_state bit30 */
			{    0, 0,2}, /* core4 power_state bit31 */
			{    0, 0,2}, /* core4 power_state bit32 */
			{    0, 0,2}, /* core4 power_state bit33 */
			{    0, 0,2}, /* core4 power_state bit34 */
			{    0, 0,2}, /* core4 power_state bit35 */
			{    0, 0,2}, /* core4 power_state bit36 */
			{    0, 0,2}, /* core4 power_state bit37 */
			{    0, 0,2}, /* core4 power_state bit38 */
			{    0, 0,2}, /* core4 power_state bit39 */
			{    0, 0,2}, /* core4 power_state bit40 */
			{    0, 0,2}, /* core4 power_state bit41 */
			{    0, 0,2}, /* core4 power_state bit42 */
			{    0, 0,2}, /* core4 power_state bit43 */
			{    0, 0,2}, /* core4 power_state bit44 */
			{    0, 0,2}, /* core4 power_state bit45 */
			{    0, 0,2}, /* core4 power_state bit46 */
			{    0, 0,2}, /* core4 power_state bit47 */
			{    0, 0,2}, /* core4 power_state bit48 */
			{    0, 0,2}, /* core4 power_state bit49 */
			{    0, 0,2}, /* core4 power_state bit50 */
			{    0, 0,2}, /* core4 power_state bit51 */
			{    0, 0,2}, /* core4 power_state bit52 */
			{    0, 0,2}, /* core4 power_state bit53 */
			{    0, 0,2}, /* core4 power_state bit54 */
			{    0, 0,2}, /* core4 power_state bit55 */
			{    0, 0,2}, /* core4 power_state bit56 */
			{    0, 0,2}, /* core4 power_state bit57 */
			{    0, 0,2}, /* core4 power_state bit58 */
			{    0, 0,2}, /* core4 power_state bit59 */
			{    0, 0,2}, /* core4 power_state bit60 */
			{    0, 0,2}, /* core4 power_state bit61 */
			{    0, 0,2}, /* core4 power_state bit62 */
			{    0, 0,2}, /* core4 power_state bit63 */
			}},
	},
	{	/* core 5 */
			.power_state = {{
			{    0,33,0}, /* core5 power_state bit0 */
			{    0,43,0}, /* core5 power_state bit1 */
			{    0, 0,2}, /* core5 power_state bit2 */
			{    0, 0,2}, /* core5 power_state bit3 */
			{    0, 0,2}, /* core5 power_state bit4 */
			{    0, 0,2}, /* core5 power_state bit5 */
			{    0, 0,2}, /* core5 power_state bit6 */
			{    0, 0,2}, /* core5 power_state bit7 */
			{    0, 0,2}, /* core5 power_state bit8 */
			{    0, 0,2}, /* core5 power_state bit9 */
			{    0, 0,2}, /* core5 power_state bit10 */
			{    0, 0,2}, /* core5 power_state bit11 */
			{    0, 0,2}, /* core5 power_state bit12 */
			{    0, 0,2}, /* core5 power_state bit13 */
			{    0, 0,2}, /* core5 power_state bit14 */
			{    0, 0,2}, /* core5 power_state bit15 */
			{    0, 0,2}, /* core5 power_state bit16 */
			{    0, 0,2}, /* core5 power_state bit17 */
			{    0, 0,2}, /* core5 power_state bit18 */
			{    0, 0,2}, /* core5 power_state bit19 */
			{    0, 0,2}, /* core5 power_state bit20 */
			{    0, 0,2}, /* core5 power_state bit21 */
			{    0, 0,2}, /* core5 power_state bit22 */
			{    0, 0,2}, /* core5 power_state bit23 */
			{    0, 0,2}, /* core5 power_state bit24 */
			{    0, 0,2}, /* core5 power_state bit25 */
			{    0, 0,2}, /* core5 power_state bit26 */
			{    0, 0,2}, /* core5 power_state bit27 */
			{    0, 0,2}, /* core5 power_state bit28 */
			{    0, 0,2}, /* core5 power_state bit29 */
			{    0, 0,2}, /* core5 power_state bit30 */
			{    0, 0,2}, /* core5 power_state bit31 */
			{    0, 0,2}, /* core5 power_state bit32 */
			{    0, 0,2}, /* core5 power_state bit33 */
			{    0, 0,2}, /* core5 power_state bit34 */
			{    0, 0,2}, /* core5 power_state bit35 */
			{    0, 0,2}, /* core5 power_state bit36 */
			{    0, 0,2}, /* core5 power_state bit37 */
			{    0, 0,2}, /* core5 power_state bit38 */
			{    0, 0,2}, /* core5 power_state bit39 */
			{    0, 0,2}, /* core5 power_state bit40 */
			{    0, 0,2}, /* core5 power_state bit41 */
			{    0, 0,2}, /* core5 power_state bit42 */
			{    0, 0,2}, /* core5 power_state bit43 */
			{    0, 0,2}, /* core5 power_state bit44 */
			{    0, 0,2}, /* core5 power_state bit45 */
			{    0, 0,2}, /* core5 power_state bit46 */
			{    0, 0,2}, /* core5 power_state bit47 */
			{    0, 0,2}, /* core5 power_state bit48 */
			{    0, 0,2}, /* core5 power_state bit49 */
			{    0, 0,2}, /* core5 power_state bit50 */
			{    0, 0,2}, /* core5 power_state bit51 */
			{    0, 0,2}, /* core5 power_state bit52 */
			{    0, 0,2}, /* core5 power_state bit53 */
			{    0, 0,2}, /* core5 power_state bit54 */
			{    0, 0,2}, /* core5 power_state bit55 */
			{    0, 0,2}, /* core5 power_state bit56 */
			{    0, 0,2}, /* core5 power_state bit57 */
			{    0, 0,2}, /* core5 power_state bit58 */
			{    0, 0,2}, /* core5 power_state bit59 */
			{    0, 0,2}, /* core5 power_state bit60 */
			{    0, 0,2}, /* core5 power_state bit61 */
			{    0, 0,2}, /* core5 power_state bit62 */
			{    0, 0,2}, /* core5 power_state bit63 */
			}},
	},
	{	/* core 6 */
			.power_state = {{
			{    0,34,0}, /* core6 power_state bit0 */
			{    0,44,0}, /* core6 power_state bit1 */
			{    0, 0,2}, /* core6 power_state bit2 */
			{    0, 0,2}, /* core6 power_state bit3 */
			{    0, 0,2}, /* core6 power_state bit4 */
			{    0, 0,2}, /* core6 power_state bit5 */
			{    0, 0,2}, /* core6 power_state bit6 */
			{    0, 0,2}, /* core6 power_state bit7 */
			{    0, 0,2}, /* core6 power_state bit8 */
			{    0, 0,2}, /* core6 power_state bit9 */
			{    0, 0,2}, /* core6 power_state bit10 */
			{    0, 0,2}, /* core6 power_state bit11 */
			{    0, 0,2}, /* core6 power_state bit12 */
			{    0, 0,2}, /* core6 power_state bit13 */
			{    0, 0,2}, /* core6 power_state bit14 */
			{    0, 0,2}, /* core6 power_state bit15 */
			{    0, 0,2}, /* core6 power_state bit16 */
			{    0, 0,2}, /* core6 power_state bit17 */
			{    0, 0,2}, /* core6 power_state bit18 */
			{    0, 0,2}, /* core6 power_state bit19 */
			{    0, 0,2}, /* core6 power_state bit20 */
			{    0, 0,2}, /* core6 power_state bit21 */
			{    0, 0,2}, /* core6 power_state bit22 */
			{    0, 0,2}, /* core6 power_state bit23 */
			{    0, 0,2}, /* core6 power_state bit24 */
			{    0, 0,2}, /* core6 power_state bit25 */
			{    0, 0,2}, /* core6 power_state bit26 */
			{    0, 0,2}, /* core6 power_state bit27 */
			{    0, 0,2}, /* core6 power_state bit28 */
			{    0, 0,2}, /* core6 power_state bit29 */
			{    0, 0,2}, /* core6 power_state bit30 */
			{    0, 0,2}, /* core6 power_state bit31 */
			{    0, 0,2}, /* core6 power_state bit32 */
			{    0, 0,2}, /* core6 power_state bit33 */
			{    0, 0,2}, /* core6 power_state bit34 */
			{    0, 0,2}, /* core6 power_state bit35 */
			{    0, 0,2}, /* core6 power_state bit36 */
			{    0, 0,2}, /* core6 power_state bit37 */
			{    0, 0,2}, /* core6 power_state bit38 */
			{    0, 0,2}, /* core6 power_state bit39 */
			{    0, 0,2}, /* core6 power_state bit40 */
			{    0, 0,2}, /* core6 power_state bit41 */
			{    0, 0,2}, /* core6 power_state bit42 */
			{    0, 0,2}, /* core6 power_state bit43 */
			{    0, 0,2}, /* core6 power_state bit44 */
			{    0, 0,2}, /* core6 power_state bit45 */
			{    0, 0,2}, /* core6 power_state bit46 */
			{    0, 0,2}, /* core6 power_state bit47 */
			{    0, 0,2}, /* core6 power_state bit48 */
			{    0, 0,2}, /* core6 power_state bit49 */
			{    0, 0,2}, /* core6 power_state bit50 */
			{    0, 0,2}, /* core6 power_state bit51 */
			{    0, 0,2}, /* core6 power_state bit52 */
			{    0, 0,2}, /* core6 power_state bit53 */
			{    0, 0,2}, /* core6 power_state bit54 */
			{    0, 0,2}, /* core6 power_state bit55 */
			{    0, 0,2}, /* core6 power_state bit56 */
			{    0, 0,2}, /* core6 power_state bit57 */
			{    0, 0,2}, /* core6 power_state bit58 */
			{    0, 0,2}, /* core6 power_state bit59 */
			{    0, 0,2}, /* core6 power_state bit60 */
			{    0, 0,2}, /* core6 power_state bit61 */
			{    0, 0,2}, /* core6 power_state bit62 */
			{    0, 0,2}, /* core6 power_state bit63 */
			}},
	},
	{	/* core 7 */
			.power_state = {{
			{    0,35,0}, /* core7 power_state bit0 */
			{    0,45,0}, /* core7 power_state bit1 */
			{    0, 0,2}, /* core7 power_state bit2 */
			{    0, 0,2}, /* core7 power_state bit3 */
			{    0, 0,2}, /* core7 power_state bit4 */
			{    0, 0,2}, /* core7 power_state bit5 */
			{    0, 0,2}, /* core7 power_state bit6 */
			{    0, 0,2}, /* core7 power_state bit7 */
			{    0, 0,2}, /* core7 power_state bit8 */
			{    0, 0,2}, /* core7 power_state bit9 */
			{    0, 0,2}, /* core7 power_state bit10 */
			{    0, 0,2}, /* core7 power_state bit11 */
			{    0, 0,2}, /* core7 power_state bit12 */
			{    0, 0,2}, /* core7 power_state bit13 */
			{    0, 0,2}, /* core7 power_state bit14 */
			{    0, 0,2}, /* core7 power_state bit15 */
			{    0, 0,2}, /* core7 power_state bit16 */
			{    0, 0,2}, /* core7 power_state bit17 */
			{    0, 0,2}, /* core7 power_state bit18 */
			{    0, 0,2}, /* core7 power_state bit19 */
			{    0, 0,2}, /* core7 power_state bit20 */
			{    0, 0,2}, /* core7 power_state bit21 */
			{    0, 0,2}, /* core7 power_state bit22 */
			{    0, 0,2}, /* core7 power_state bit23 */
			{    0, 0,2}, /* core7 power_state bit24 */
			{    0, 0,2}, /* core7 power_state bit25 */
			{    0, 0,2}, /* core7 power_state bit26 */
			{    0, 0,2}, /* core7 power_state bit27 */
			{    0, 0,2}, /* core7 power_state bit28 */
			{    0, 0,2}, /* core7 power_state bit29 */
			{    0, 0,2}, /* core7 power_state bit30 */
			{    0, 0,2}, /* core7 power_state bit31 */
			{    0, 0,2}, /* core7 power_state bit32 */
			{    0, 0,2}, /* core7 power_state bit33 */
			{    0, 0,2}, /* core7 power_state bit34 */
			{    0, 0,2}, /* core7 power_state bit35 */
			{    0, 0,2}, /* core7 power_state bit36 */
			{    0, 0,2}, /* core7 power_state bit37 */
			{    0, 0,2}, /* core7 power_state bit38 */
			{    0, 0,2}, /* core7 power_state bit39 */
			{    0, 0,2}, /* core7 power_state bit40 */
			{    0, 0,2}, /* core7 power_state bit41 */
			{    0, 0,2}, /* core7 power_state bit42 */
			{    0, 0,2}, /* core7 power_state bit43 */
			{    0, 0,2}, /* core7 power_state bit44 */
			{    0, 0,2}, /* core7 power_state bit45 */
			{    0, 0,2}, /* core7 power_state bit46 */
			{    0, 0,2}, /* core7 power_state bit47 */
			{    0, 0,2}, /* core7 power_state bit48 */
			{    0, 0,2}, /* core7 power_state bit49 */
			{    0, 0,2}, /* core7 power_state bit50 */
			{    0, 0,2}, /* core7 power_state bit51 */
			{    0, 0,2}, /* core7 power_state bit52 */
			{    0, 0,2}, /* core7 power_state bit53 */
			{    0, 0,2}, /* core7 power_state bit54 */
			{    0, 0,2}, /* core7 power_state bit55 */
			{    0, 0,2}, /* core7 power_state bit56 */
			{    0, 0,2}, /* core7 power_state bit57 */
			{    0, 0,2}, /* core7 power_state bit58 */
			{    0, 0,2}, /* core7 power_state bit59 */
			{    0, 0,2}, /* core7 power_state bit60 */
			{    0, 0,2}, /* core7 power_state bit61 */
			{    0, 0,2}, /* core7 power_state bit62 */
			{    0, 0,2}, /* core7 power_state bit63 */
			}},
	},
}; 

struct mcusys_spec mcusys[] = {
	{		/* core 0 */ 
			.M0_AR_Pending_Counter = {{
			{23866,13,1}, /* core0 M0_AR_Pending_Counter bit0 */
			{23788,13,1}, /* core0 M0_AR_Pending_Counter bit1 */
			{23786,13,1}, /* core0 M0_AR_Pending_Counter bit2 */
			{24756,13,1}, /* core0 M0_AR_Pending_Counter bit3 */
			{24754,13,1}, /* core0 M0_AR_Pending_Counter bit4 */
			{23864,13,1}, /* core0 M0_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M0_AR_Pending_Counter bit63 */
			}},
			.M1_AR_Pending_Counter = {{
			{23560,13,1}, /* core0 M1_AR_Pending_Counter bit0 */
			{23558,13,1}, /* core0 M1_AR_Pending_Counter bit1 */
			{23556,13,1}, /* core0 M1_AR_Pending_Counter bit2 */
			{23704,13,1}, /* core0 M1_AR_Pending_Counter bit3 */
			{23702,13,1}, /* core0 M1_AR_Pending_Counter bit4 */
			{23554,13,1}, /* core0 M1_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit63 */
			}},
			.M2_AR_Pending_Counter = {{
			{23770,13,1}, /* core0 M2_AR_Pending_Counter bit0 */
			{23768,13,1}, /* core0 M2_AR_Pending_Counter bit1 */
			{23782,13,1}, /* core0 M2_AR_Pending_Counter bit2 */
			{23776,13,1}, /* core0 M2_AR_Pending_Counter bit3 */
			{23774,13,1}, /* core0 M2_AR_Pending_Counter bit4 */
			{23772,13,1}, /* core0 M2_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M2_AR_Pending_Counter bit63 */
			}},
			.M0_AW_Pending_Counter = {{
			{23856,13,1}, /* core0 M0_AW_Pending_Counter bit0 */
			{23844,13,1}, /* core0 M0_AW_Pending_Counter bit1 */
			{23860,13,1}, /* core0 M0_AW_Pending_Counter bit2 */
			{23858,13,1}, /* core0 M0_AW_Pending_Counter bit3 */
			{23790,13,1}, /* core0 M0_AW_Pending_Counter bit4 */
			{23868,13,1}, /* core0 M0_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M0_AW_Pending_Counter bit63 */
			}},
			.M1_AR_Pending_Counter = {{
			{23746,13,1}, /* core0 M1_AR_Pending_Counter bit0 */
			{23748,13,1}, /* core0 M1_AR_Pending_Counter bit1 */
			{23708,13,1}, /* core0 M1_AR_Pending_Counter bit2 */
			{23706,13,1}, /* core0 M1_AR_Pending_Counter bit3 */
			{23712,13,1}, /* core0 M1_AR_Pending_Counter bit4 */
			{23710,13,1}, /* core0 M1_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M1_AR_Pending_Counter bit63 */
			}},
			.M2_AW_Pending_Counter = {{
			{23834,13,1}, /* core0 M2_AW_Pending_Counter bit0 */
			{23832,13,1}, /* core0 M2_AW_Pending_Counter bit1 */
			{23826,13,1}, /* core0 M2_AW_Pending_Counter bit2 */
			{23824,13,1}, /* core0 M2_AW_Pending_Counter bit3 */
			{23830,13,1}, /* core0 M2_AW_Pending_Counter bit4 */
			{23828,13,1}, /* core0 M2_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 M2_AW_Pending_Counter bit63 */
			}},
			.S4_AR_Pending_Counter = {{
			{23846,13,1}, /* core0 S4_AR_Pending_Counter bit0 */
			{23852,13,1}, /* core0 S4_AR_Pending_Counter bit1 */
			{23848,13,1}, /* core0 S4_AR_Pending_Counter bit2 */
			{23850,13,1}, /* core0 S4_AR_Pending_Counter bit3 */
			{23812,13,1}, /* core0 S4_AR_Pending_Counter bit4 */
			{23810,13,1}, /* core0 S4_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S4_AR_Pending_Counter bit63 */
			}},
			.S4_AW_Pending_Counter = {{
			{23798,13,1}, /* core0 S4_AW_Pending_Counter bit0 */
			{23800,13,1}, /* core0 S4_AW_Pending_Counter bit1 */
			{23802,13,1}, /* core0 S4_AW_Pending_Counter bit2 */
			{23804,13,1}, /* core0 S4_AW_Pending_Counter bit3 */
			{23806,13,1}, /* core0 S4_AW_Pending_Counter bit4 */
			{23808,13,1}, /* core0 S4_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S4_AW_Pending_Counter bit63 */
			}},
			.S3_AR_Pending_Counter = {{
			{23722,13,1}, /* core0 S3_AR_Pending_Counter bit0 */
			{23720,13,1}, /* core0 S3_AR_Pending_Counter bit1 */
			{23724,13,1}, /* core0 S3_AR_Pending_Counter bit2 */
			{23714,13,1}, /* core0 S3_AR_Pending_Counter bit3 */
			{23546,13,1}, /* core0 S3_AR_Pending_Counter bit4 */
			{23544,13,1}, /* core0 S3_AR_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S3_AR_Pending_Counter bit63 */
			}},
			.S3_AW_Pending_Counter = {{
			{23740,13,1}, /* core0 S3_AW_Pending_Counter bit0 */
			{23734,13,1}, /* core0 S3_AW_Pending_Counter bit1 */
			{23742,13,1}, /* core0 S3_AW_Pending_Counter bit2 */
			{23732,13,1}, /* core0 S3_AW_Pending_Counter bit3 */
			{23738,13,1}, /* core0 S3_AW_Pending_Counter bit4 */
			{23736,13,1}, /* core0 S3_AW_Pending_Counter bit5 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit6 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit7 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit8 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit9 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit10 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit11 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit12 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit13 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit14 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit15 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit16 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit17 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit18 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit19 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit20 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit21 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit22 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit23 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit24 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit25 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit26 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit27 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit28 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit29 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit30 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit31 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit32 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit33 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit34 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit35 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit36 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit37 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit38 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit39 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit40 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit41 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit42 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit43 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit44 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit45 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit46 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit47 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit48 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit49 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit50 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit51 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit52 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit53 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit54 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit55 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit56 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit57 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit58 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit59 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit60 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit61 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit62 */
			{    0, 0,2}, /* core0 S3_AW_Pending_Counter bit63 */
			}},
			.mp0_L3_parity_err = {{
			{11586, 9,0}, /* core0 mp0_L3_parity_err bit0 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit1 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit2 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit3 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit4 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit5 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit6 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit7 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit8 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit9 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit10 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit11 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit12 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit13 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit14 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err bit63 */
			}},
			.mp0_L3_parity_err_count = {{
			{10804, 9,0}, /* core0 mp0_L3_parity_err_count bit0 */
			{10698, 9,0}, /* core0 mp0_L3_parity_err_count bit1 */
			{10692, 9,0}, /* core0 mp0_L3_parity_err_count bit2 */
			{10800, 9,0}, /* core0 mp0_L3_parity_err_count bit3 */
			{10802, 9,0}, /* core0 mp0_L3_parity_err_count bit4 */
			{10798, 9,0}, /* core0 mp0_L3_parity_err_count bit5 */
			{10696, 9,0}, /* core0 mp0_L3_parity_err_count bit6 */
			{10694, 9,0}, /* core0 mp0_L3_parity_err_count bit7 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit8 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit9 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit10 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit11 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit12 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit13 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit14 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_err_count bit63 */
			}},
			.mp0_L3_parity_sap = {{
			{10702, 9,0}, /* core0 mp0_L3_parity_sap bit0 */
			{10806, 9,0}, /* core0 mp0_L3_parity_sap bit1 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit2 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit3 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit4 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit5 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit6 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit7 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit8 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit9 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit10 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit11 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit12 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit13 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit14 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_sap bit63 */
			}},
			.mp0_L3_parity_index = {{
			{10686, 9,0}, /* core0 mp0_L3_parity_index bit0 */
			{10682, 9,0}, /* core0 mp0_L3_parity_index bit1 */
			{11170, 9,0}, /* core0 mp0_L3_parity_index bit2 */
			{10616, 9,0}, /* core0 mp0_L3_parity_index bit3 */
			{11168, 9,0}, /* core0 mp0_L3_parity_index bit4 */
			{11594, 9,0}, /* core0 mp0_L3_parity_index bit5 */
			{10612, 9,0}, /* core0 mp0_L3_parity_index bit6 */
			{11136, 9,0}, /* core0 mp0_L3_parity_index bit7 */
			{10610, 9,0}, /* core0 mp0_L3_parity_index bit8 */
			{10952, 9,0}, /* core0 mp0_L3_parity_index bit9 */
			{10764, 9,0}, /* core0 mp0_L3_parity_index bit10 */
			{10758, 9,0}, /* core0 mp0_L3_parity_index bit11 */
			{11588, 9,0}, /* core0 mp0_L3_parity_index bit12 */
			{10808, 9,0}, /* core0 mp0_L3_parity_index bit13 */
			{10796, 9,0}, /* core0 mp0_L3_parity_index bit14 */
			{10826, 9,0}, /* core0 mp0_L3_parity_index bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_index bit63 */
			}},
			.mp0_L3_parity_bank = {{
			{10676, 9,0}, /* core0 mp0_L3_parity_bank bit0 */
			{10680, 9,0}, /* core0 mp0_L3_parity_bank bit1 */
			{10678, 9,0}, /* core0 mp0_L3_parity_bank bit2 */
			{10756, 9,0}, /* core0 mp0_L3_parity_bank bit3 */
			{11134, 9,0}, /* core0 mp0_L3_parity_bank bit4 */
			{11148, 9,0}, /* core0 mp0_L3_parity_bank bit5 */
			{10954, 9,0}, /* core0 mp0_L3_parity_bank bit6 */
			{10822, 9,0}, /* core0 mp0_L3_parity_bank bit7 */
			{11030, 9,0}, /* core0 mp0_L3_parity_bank bit8 */
			{11152, 9,0}, /* core0 mp0_L3_parity_bank bit9 */
			{11598, 9,0}, /* core0 mp0_L3_parity_bank bit10 */
			{11032, 9,0}, /* core0 mp0_L3_parity_bank bit11 */
			{11150, 9,0}, /* core0 mp0_L3_parity_bank bit12 */
			{10684, 9,0}, /* core0 mp0_L3_parity_bank bit13 */
			{11028, 9,0}, /* core0 mp0_L3_parity_bank bit14 */
			{11628, 9,0}, /* core0 mp0_L3_parity_bank bit15 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit16 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit17 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit18 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit19 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit20 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit21 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit22 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit23 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit24 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit25 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit26 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit27 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit28 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit29 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit30 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit31 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit32 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit33 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit34 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit35 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit36 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit37 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit38 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit39 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit40 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit41 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit42 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit43 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit44 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit45 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit46 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit47 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit48 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit49 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit50 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit51 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit52 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit53 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit54 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit55 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit56 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit57 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit58 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit59 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit60 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit61 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit62 */
			{    0, 0,2}, /* core0 mp0_L3_parity_bank bit63 */
			}},
			.dfd_v35_enable = {{
			{ 3426, 8,0}, /* core0 dfd_v35_enable bit0 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit1 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit2 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit3 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit4 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit5 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit6 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit7 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit8 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit9 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit10 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit11 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit12 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit13 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit14 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit15 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit16 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit17 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit18 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit19 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit20 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit21 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit22 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit23 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit24 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit25 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit26 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit27 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit28 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit29 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit30 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit31 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit32 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit33 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit34 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit35 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit36 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit37 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit38 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit39 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit40 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit41 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit42 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit43 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit44 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit45 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit46 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit47 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit48 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit49 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit50 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit51 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit52 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit53 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit54 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit55 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit56 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit57 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit58 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit59 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit60 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit61 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit62 */
			{    0, 0,2}, /* core0 dfd_v35_enable bit63 */
			}},
	},
}; 

struct little_core_spec little_core[] = {
	{		/* core 0 */ 
			.pc = {{
			{ 2688,34,1}, /* core0 pc bit0 */
			{ 2686,34,1}, /* core0 pc bit1 */
			{ 2684,34,1}, /* core0 pc bit2 */
			{ 2682,34,1}, /* core0 pc bit3 */
			{ 2592,34,1}, /* core0 pc bit4 */
			{ 2590,34,1}, /* core0 pc bit5 */
			{ 2588,34,1}, /* core0 pc bit6 */
			{ 2586,34,1}, /* core0 pc bit7 */
			{ 2584,34,1}, /* core0 pc bit8 */
			{ 2582,34,1}, /* core0 pc bit9 */
			{ 2580,34,1}, /* core0 pc bit10 */
			{ 2578,34,1}, /* core0 pc bit11 */
			{ 2600,34,1}, /* core0 pc bit12 */
			{ 2598,34,1}, /* core0 pc bit13 */
			{ 2596,34,1}, /* core0 pc bit14 */
			{ 2594,34,1}, /* core0 pc bit15 */
			{ 2448,34,1}, /* core0 pc bit16 */
			{ 2446,34,1}, /* core0 pc bit17 */
			{ 2444,34,1}, /* core0 pc bit18 */
			{ 2442,34,1}, /* core0 pc bit19 */
			{ 2432,34,1}, /* core0 pc bit20 */
			{ 2430,34,1}, /* core0 pc bit21 */
			{ 2428,34,1}, /* core0 pc bit22 */
			{ 2426,34,1}, /* core0 pc bit23 */
			{ 2352,34,1}, /* core0 pc bit24 */
			{ 2350,34,1}, /* core0 pc bit25 */
			{ 2348,34,1}, /* core0 pc bit26 */
			{ 2346,34,1}, /* core0 pc bit27 */
			{ 2344,34,1}, /* core0 pc bit28 */
			{ 2342,34,1}, /* core0 pc bit29 */
			{ 2340,34,1}, /* core0 pc bit30 */
			{ 2338,34,1}, /* core0 pc bit31 */
			{ 2656,34,1}, /* core0 pc bit32 */
			{ 2654,34,1}, /* core0 pc bit33 */
			{ 2652,34,1}, /* core0 pc bit34 */
			{ 2650,34,1}, /* core0 pc bit35 */
			{ 2616,34,1}, /* core0 pc bit36 */
			{ 2614,34,1}, /* core0 pc bit37 */
			{ 2612,34,1}, /* core0 pc bit38 */
			{ 2610,34,1}, /* core0 pc bit39 */
			{ 2632,34,1}, /* core0 pc bit40 */
			{ 2630,34,1}, /* core0 pc bit41 */
			{  676,34,1}, /* core0 pc bit42 */
			{ 2628,34,1}, /* core0 pc bit43 */
			{ 2626,34,1}, /* core0 pc bit44 */
			{ 2608,34,1}, /* core0 pc bit45 */
			{ 2606,34,1}, /* core0 pc bit46 */
			{ 2604,34,1}, /* core0 pc bit47 */
			{ 2602,34,1}, /* core0 pc bit48 */
			{ 2400,34,1}, /* core0 pc bit49 */
			{ 2398,34,1}, /* core0 pc bit50 */
			{ 2396,34,1}, /* core0 pc bit51 */
			{ 2394,34,1}, /* core0 pc bit52 */
			{ 2312,34,1}, /* core0 pc bit53 */
			{ 2310,34,1}, /* core0 pc bit54 */
			{ 2308,34,1}, /* core0 pc bit55 */
			{ 2306,34,1}, /* core0 pc bit56 */
			{ 2164,34,1}, /* core0 pc bit57 */
			{ 2162,34,1}, /* core0 pc bit58 */
			{ 2160,34,1}, /* core0 pc bit59 */
			{ 2158,34,1}, /* core0 pc bit60 */
			{  682,34,1}, /* core0 pc bit61 */
			{  680,34,1}, /* core0 pc bit62 */
			{ 2228,34,1}, /* core0 pc bit63 */
			}},
			.sp32 = {{
			{32298,34,0}, /* core0 sp32 bit0 */
			{40686,34,0}, /* core0 sp32 bit1 */
			{32308,34,0}, /* core0 sp32 bit2 */
			{40522,34,0}, /* core0 sp32 bit3 */
			{40684,34,0}, /* core0 sp32 bit4 */
			{40682,34,0}, /* core0 sp32 bit5 */
			{40680,34,0}, /* core0 sp32 bit6 */
			{40690,34,0}, /* core0 sp32 bit7 */
			{40688,34,0}, /* core0 sp32 bit8 */
			{40654,34,0}, /* core0 sp32 bit9 */
			{40520,34,0}, /* core0 sp32 bit10 */
			{40526,34,0}, /* core0 sp32 bit11 */
			{40524,34,0}, /* core0 sp32 bit12 */
			{40646,34,0}, /* core0 sp32 bit13 */
			{40652,34,0}, /* core0 sp32 bit14 */
			{40644,34,0}, /* core0 sp32 bit15 */
			{40642,34,0}, /* core0 sp32 bit16 */
			{40640,34,0}, /* core0 sp32 bit17 */
			{32264,34,0}, /* core0 sp32 bit18 */
			{40614,34,0}, /* core0 sp32 bit19 */
			{40612,34,0}, /* core0 sp32 bit20 */
			{40510,34,0}, /* core0 sp32 bit21 */
			{32260,34,0}, /* core0 sp32 bit22 */
			{40508,34,0}, /* core0 sp32 bit23 */
			{40490,34,0}, /* core0 sp32 bit24 */
			{40488,34,0}, /* core0 sp32 bit25 */
			{40564,34,0}, /* core0 sp32 bit26 */
			{40562,34,0}, /* core0 sp32 bit27 */
			{40560,34,0}, /* core0 sp32 bit28 */
			{40566,34,0}, /* core0 sp32 bit29 */
			{32258,34,0}, /* core0 sp32 bit30 */
			{32256,34,0}, /* core0 sp32 bit31 */
			{40362,34,0}, /* core0 sp32 bit32 */
			{40360,34,0}, /* core0 sp32 bit33 */
			{40354,34,0}, /* core0 sp32 bit34 */
			{40352,34,0}, /* core0 sp32 bit35 */
			{40358,34,0}, /* core0 sp32 bit36 */
			{40356,34,0}, /* core0 sp32 bit37 */
			{31992,34,0}, /* core0 sp32 bit38 */
			{40350,34,0}, /* core0 sp32 bit39 */
			{40348,34,0}, /* core0 sp32 bit40 */
			{40322,34,0}, /* core0 sp32 bit41 */
			{40320,34,0}, /* core0 sp32 bit42 */
			{32028,34,0}, /* core0 sp32 bit43 */
			{40318,34,0}, /* core0 sp32 bit44 */
			{32030,34,0}, /* core0 sp32 bit45 */
			{40316,34,0}, /* core0 sp32 bit46 */
			{32032,34,0}, /* core0 sp32 bit47 */
			{47404,34,0}, /* core0 sp32 bit48 */
			{47402,34,0}, /* core0 sp32 bit49 */
			{47400,34,0}, /* core0 sp32 bit50 */
			{47398,34,0}, /* core0 sp32 bit51 */
			{47332,34,0}, /* core0 sp32 bit52 */
			{47330,34,0}, /* core0 sp32 bit53 */
			{47328,34,0}, /* core0 sp32 bit54 */
			{47326,34,0}, /* core0 sp32 bit55 */
			{47340,34,0}, /* core0 sp32 bit56 */
			{47338,34,0}, /* core0 sp32 bit57 */
			{47336,34,0}, /* core0 sp32 bit58 */
			{47334,34,0}, /* core0 sp32 bit59 */
			{47348,34,0}, /* core0 sp32 bit60 */
			{47346,34,0}, /* core0 sp32 bit61 */
			{47344,34,0}, /* core0 sp32 bit62 */
			{47342,34,0}, /* core0 sp32 bit63 */
			}},
			.fp32 = {{
			{32654,34,0}, /* core0 fp32 bit0 */
			{32322,34,0}, /* core0 fp32 bit1 */
			{40906,34,0}, /* core0 fp32 bit2 */
			{40900,34,0}, /* core0 fp32 bit3 */
			{40976,34,0}, /* core0 fp32 bit4 */
			{40974,34,0}, /* core0 fp32 bit5 */
			{40972,34,0}, /* core0 fp32 bit6 */
			{32646,34,0}, /* core0 fp32 bit7 */
			{40970,34,0}, /* core0 fp32 bit8 */
			{32320,34,0}, /* core0 fp32 bit9 */
			{40896,34,0}, /* core0 fp32 bit10 */
			{40904,34,0}, /* core0 fp32 bit11 */
			{40898,34,0}, /* core0 fp32 bit12 */
			{32390,34,0}, /* core0 fp32 bit13 */
			{40908,34,0}, /* core0 fp32 bit14 */
			{40902,34,0}, /* core0 fp32 bit15 */
			{40920,34,0}, /* core0 fp32 bit16 */
			{40918,34,0}, /* core0 fp32 bit17 */
			{32418,34,0}, /* core0 fp32 bit18 */
			{32386,34,0}, /* core0 fp32 bit19 */
			{40894,34,0}, /* core0 fp32 bit20 */
			{32348,34,0}, /* core0 fp32 bit21 */
			{32412,34,0}, /* core0 fp32 bit22 */
			{32334,34,0}, /* core0 fp32 bit23 */
			{32336,34,0}, /* core0 fp32 bit24 */
			{32342,34,0}, /* core0 fp32 bit25 */
			{40916,34,0}, /* core0 fp32 bit26 */
			{40914,34,0}, /* core0 fp32 bit27 */
			{32388,34,0}, /* core0 fp32 bit28 */
			{40924,34,0}, /* core0 fp32 bit29 */
			{40922,34,0}, /* core0 fp32 bit30 */
			{32424,34,0}, /* core0 fp32 bit31 */
			{41026,34,0}, /* core0 fp32 bit32 */
			{32578,34,0}, /* core0 fp32 bit33 */
			{41036,34,0}, /* core0 fp32 bit34 */
			{41022,34,0}, /* core0 fp32 bit35 */
			{41024,34,0}, /* core0 fp32 bit36 */
			{41028,34,0}, /* core0 fp32 bit37 */
			{32580,34,0}, /* core0 fp32 bit38 */
			{32582,34,0}, /* core0 fp32 bit39 */
			{41032,34,0}, /* core0 fp32 bit40 */
			{41030,34,0}, /* core0 fp32 bit41 */
			{41040,34,0}, /* core0 fp32 bit42 */
			{32552,34,0}, /* core0 fp32 bit43 */
			{41038,34,0}, /* core0 fp32 bit44 */
			{40992,34,0}, /* core0 fp32 bit45 */
			{41034,34,0}, /* core0 fp32 bit46 */
			{40990,34,0}, /* core0 fp32 bit47 */
			{32614,34,0}, /* core0 fp32 bit48 */
			{41064,34,0}, /* core0 fp32 bit49 */
			{47526,34,0}, /* core0 fp32 bit50 */
			{47524,34,0}, /* core0 fp32 bit51 */
			{47520,34,0}, /* core0 fp32 bit52 */
			{47430,34,0}, /* core0 fp32 bit53 */
			{47428,34,0}, /* core0 fp32 bit54 */
			{47426,34,0}, /* core0 fp32 bit55 */
			{47422,34,0}, /* core0 fp32 bit56 */
			{47424,34,0}, /* core0 fp32 bit57 */
			{47420,34,0}, /* core0 fp32 bit58 */
			{41062,34,0}, /* core0 fp32 bit59 */
			{47418,34,0}, /* core0 fp32 bit60 */
			{47416,34,0}, /* core0 fp32 bit61 */
			{32634,34,0}, /* core0 fp32 bit62 */
			{47518,34,0}, /* core0 fp32 bit63 */
			}},
			.fp64 = {{
			{32172,34,0}, /* core0 fp64 bit0 */
			{31886,34,0}, /* core0 fp64 bit1 */
			{39704,34,0}, /* core0 fp64 bit2 */
			{39782,34,0}, /* core0 fp64 bit3 */
			{32160,34,0}, /* core0 fp64 bit4 */
			{39662,34,0}, /* core0 fp64 bit5 */
			{39650,34,0}, /* core0 fp64 bit6 */
			{39648,34,0}, /* core0 fp64 bit7 */
			{39682,34,0}, /* core0 fp64 bit8 */
			{39660,34,0}, /* core0 fp64 bit9 */
			{31822,34,0}, /* core0 fp64 bit10 */
			{31824,34,0}, /* core0 fp64 bit11 */
			{31818,34,0}, /* core0 fp64 bit12 */
			{32222,34,0}, /* core0 fp64 bit13 */
			{39680,34,0}, /* core0 fp64 bit14 */
			{32224,34,0}, /* core0 fp64 bit15 */
			{39722,34,0}, /* core0 fp64 bit16 */
			{39720,34,0}, /* core0 fp64 bit17 */
			{39778,34,0}, /* core0 fp64 bit18 */
			{39786,34,0}, /* core0 fp64 bit19 */
			{39780,34,0}, /* core0 fp64 bit20 */
			{39784,34,0}, /* core0 fp64 bit21 */
			{39706,34,0}, /* core0 fp64 bit22 */
			{39770,34,0}, /* core0 fp64 bit23 */
			{39768,34,0}, /* core0 fp64 bit24 */
			{39742,34,0}, /* core0 fp64 bit25 */
			{39776,34,0}, /* core0 fp64 bit26 */
			{39740,34,0}, /* core0 fp64 bit27 */
			{31826,34,0}, /* core0 fp64 bit28 */
			{39774,34,0}, /* core0 fp64 bit29 */
			{39772,34,0}, /* core0 fp64 bit30 */
			{31836,34,0}, /* core0 fp64 bit31 */
			{31976,34,0}, /* core0 fp64 bit32 */
			{31974,34,0}, /* core0 fp64 bit33 */
			{31972,34,0}, /* core0 fp64 bit34 */
			{39436,34,0}, /* core0 fp64 bit35 */
			{39438,34,0}, /* core0 fp64 bit36 */
			{39430,34,0}, /* core0 fp64 bit37 */
			{39426,34,0}, /* core0 fp64 bit38 */
			{39428,34,0}, /* core0 fp64 bit39 */
			{39394,34,0}, /* core0 fp64 bit40 */
			{39392,34,0}, /* core0 fp64 bit41 */
			{39424,34,0}, /* core0 fp64 bit42 */
			{39398,34,0}, /* core0 fp64 bit43 */
			{39402,34,0}, /* core0 fp64 bit44 */
			{39410,34,0}, /* core0 fp64 bit45 */
			{39396,34,0}, /* core0 fp64 bit46 */
			{39400,34,0}, /* core0 fp64 bit47 */
			{39408,34,0}, /* core0 fp64 bit48 */
			{46722,34,0}, /* core0 fp64 bit49 */
			{46720,34,0}, /* core0 fp64 bit50 */
			{46718,34,0}, /* core0 fp64 bit51 */
			{46708,34,0}, /* core0 fp64 bit52 */
			{46698,34,0}, /* core0 fp64 bit53 */
			{46696,34,0}, /* core0 fp64 bit54 */
			{46694,34,0}, /* core0 fp64 bit55 */
			{46692,34,0}, /* core0 fp64 bit56 */
			{46706,34,0}, /* core0 fp64 bit57 */
			{46704,34,0}, /* core0 fp64 bit58 */
			{46702,34,0}, /* core0 fp64 bit59 */
			{46700,34,0}, /* core0 fp64 bit60 */
			{32034,34,0}, /* core0 fp64 bit61 */
			{32042,34,0}, /* core0 fp64 bit62 */
			{32040,34,0}, /* core0 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{31878,34,0}, /* core0 sp_EL0 bit0 */
			{31882,34,0}, /* core0 sp_EL0 bit1 */
			{39692,34,0}, /* core0 sp_EL0 bit2 */
			{39816,34,0}, /* core0 sp_EL0 bit3 */
			{39652,34,0}, /* core0 sp_EL0 bit4 */
			{39654,34,0}, /* core0 sp_EL0 bit5 */
			{39658,34,0}, /* core0 sp_EL0 bit6 */
			{39656,34,0}, /* core0 sp_EL0 bit7 */
			{39686,34,0}, /* core0 sp_EL0 bit8 */
			{39684,34,0}, /* core0 sp_EL0 bit9 */
			{39688,34,0}, /* core0 sp_EL0 bit10 */
			{39690,34,0}, /* core0 sp_EL0 bit11 */
			{39822,34,0}, /* core0 sp_EL0 bit12 */
			{31850,34,0}, /* core0 sp_EL0 bit13 */
			{39820,34,0}, /* core0 sp_EL0 bit14 */
			{31848,34,0}, /* core0 sp_EL0 bit15 */
			{39698,34,0}, /* core0 sp_EL0 bit16 */
			{39824,34,0}, /* core0 sp_EL0 bit17 */
			{39830,34,0}, /* core0 sp_EL0 bit18 */
			{39828,34,0}, /* core0 sp_EL0 bit19 */
			{39826,34,0}, /* core0 sp_EL0 bit20 */
			{39696,34,0}, /* core0 sp_EL0 bit21 */
			{39702,34,0}, /* core0 sp_EL0 bit22 */
			{39806,34,0}, /* core0 sp_EL0 bit23 */
			{39804,34,0}, /* core0 sp_EL0 bit24 */
			{39700,34,0}, /* core0 sp_EL0 bit25 */
			{39808,34,0}, /* core0 sp_EL0 bit26 */
			{39810,34,0}, /* core0 sp_EL0 bit27 */
			{39814,34,0}, /* core0 sp_EL0 bit28 */
			{39812,34,0}, /* core0 sp_EL0 bit29 */
			{39694,34,0}, /* core0 sp_EL0 bit30 */
			{39818,34,0}, /* core0 sp_EL0 bit31 */
			{39446,34,0}, /* core0 sp_EL0 bit32 */
			{32134,34,0}, /* core0 sp_EL0 bit33 */
			{39444,34,0}, /* core0 sp_EL0 bit34 */
			{32136,34,0}, /* core0 sp_EL0 bit35 */
			{32132,34,0}, /* core0 sp_EL0 bit36 */
			{32128,34,0}, /* core0 sp_EL0 bit37 */
			{32130,34,0}, /* core0 sp_EL0 bit38 */
			{39390,34,0}, /* core0 sp_EL0 bit39 */
			{39388,34,0}, /* core0 sp_EL0 bit40 */
			{39004,34,0}, /* core0 sp_EL0 bit41 */
			{39002,34,0}, /* core0 sp_EL0 bit42 */
			{38960,34,0}, /* core0 sp_EL0 bit43 */
			{31934,34,0}, /* core0 sp_EL0 bit44 */
			{38958,34,0}, /* core0 sp_EL0 bit45 */
			{46754,34,0}, /* core0 sp_EL0 bit46 */
			{46752,34,0}, /* core0 sp_EL0 bit47 */
			{46750,34,0}, /* core0 sp_EL0 bit48 */
			{38964,34,0}, /* core0 sp_EL0 bit49 */
			{38962,34,0}, /* core0 sp_EL0 bit50 */
			{46748,34,0}, /* core0 sp_EL0 bit51 */
			{46738,34,0}, /* core0 sp_EL0 bit52 */
			{46730,34,0}, /* core0 sp_EL0 bit53 */
			{46736,34,0}, /* core0 sp_EL0 bit54 */
			{46728,34,0}, /* core0 sp_EL0 bit55 */
			{46726,34,0}, /* core0 sp_EL0 bit56 */
			{46724,34,0}, /* core0 sp_EL0 bit57 */
			{46746,34,0}, /* core0 sp_EL0 bit58 */
			{46734,34,0}, /* core0 sp_EL0 bit59 */
			{46732,34,0}, /* core0 sp_EL0 bit60 */
			{46744,34,0}, /* core0 sp_EL0 bit61 */
			{46742,34,0}, /* core0 sp_EL0 bit62 */
			{46740,34,0}, /* core0 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{31874,34,0}, /* core0 sp_EL1 bit0 */
			{39272,34,0}, /* core0 sp_EL1 bit1 */
			{31872,34,0}, /* core0 sp_EL1 bit2 */
			{39270,34,0}, /* core0 sp_EL1 bit3 */
			{39084,34,0}, /* core0 sp_EL1 bit4 */
			{39082,34,0}, /* core0 sp_EL1 bit5 */
			{39086,34,0}, /* core0 sp_EL1 bit6 */
			{39072,34,0}, /* core0 sp_EL1 bit7 */
			{39070,34,0}, /* core0 sp_EL1 bit8 */
			{39088,34,0}, /* core0 sp_EL1 bit9 */
			{39134,34,0}, /* core0 sp_EL1 bit10 */
			{39128,34,0}, /* core0 sp_EL1 bit11 */
			{39238,34,0}, /* core0 sp_EL1 bit12 */
			{39126,34,0}, /* core0 sp_EL1 bit13 */
			{39260,34,0}, /* core0 sp_EL1 bit14 */
			{39262,34,0}, /* core0 sp_EL1 bit15 */
			{39264,34,0}, /* core0 sp_EL1 bit16 */
			{39252,34,0}, /* core0 sp_EL1 bit17 */
			{31854,34,0}, /* core0 sp_EL1 bit18 */
			{39250,34,0}, /* core0 sp_EL1 bit19 */
			{39242,34,0}, /* core0 sp_EL1 bit20 */
			{39240,34,0}, /* core0 sp_EL1 bit21 */
			{39268,34,0}, /* core0 sp_EL1 bit22 */
			{39266,34,0}, /* core0 sp_EL1 bit23 */
			{39132,34,0}, /* core0 sp_EL1 bit24 */
			{39258,34,0}, /* core0 sp_EL1 bit25 */
			{39130,34,0}, /* core0 sp_EL1 bit26 */
			{39138,34,0}, /* core0 sp_EL1 bit27 */
			{39236,34,0}, /* core0 sp_EL1 bit28 */
			{39140,34,0}, /* core0 sp_EL1 bit29 */
			{39136,34,0}, /* core0 sp_EL1 bit30 */
			{31852,34,0}, /* core0 sp_EL1 bit31 */
			{39028,34,0}, /* core0 sp_EL1 bit32 */
			{32108,34,0}, /* core0 sp_EL1 bit33 */
			{39026,34,0}, /* core0 sp_EL1 bit34 */
			{39020,34,0}, /* core0 sp_EL1 bit35 */
			{32104,34,0}, /* core0 sp_EL1 bit36 */
			{39018,34,0}, /* core0 sp_EL1 bit37 */
			{32102,34,0}, /* core0 sp_EL1 bit38 */
			{39008,34,0}, /* core0 sp_EL1 bit39 */
			{39006,34,0}, /* core0 sp_EL1 bit40 */
			{39000,34,0}, /* core0 sp_EL1 bit41 */
			{38998,34,0}, /* core0 sp_EL1 bit42 */
			{38956,34,0}, /* core0 sp_EL1 bit43 */
			{31932,34,0}, /* core0 sp_EL1 bit44 */
			{38954,34,0}, /* core0 sp_EL1 bit45 */
			{38980,34,0}, /* core0 sp_EL1 bit46 */
			{38978,34,0}, /* core0 sp_EL1 bit47 */
			{46778,34,0}, /* core0 sp_EL1 bit48 */
			{46776,34,0}, /* core0 sp_EL1 bit49 */
			{46774,34,0}, /* core0 sp_EL1 bit50 */
			{46772,34,0}, /* core0 sp_EL1 bit51 */
			{46682,34,0}, /* core0 sp_EL1 bit52 */
			{46680,34,0}, /* core0 sp_EL1 bit53 */
			{46678,34,0}, /* core0 sp_EL1 bit54 */
			{46676,34,0}, /* core0 sp_EL1 bit55 */
			{46690,34,0}, /* core0 sp_EL1 bit56 */
			{46688,34,0}, /* core0 sp_EL1 bit57 */
			{46686,34,0}, /* core0 sp_EL1 bit58 */
			{46684,34,0}, /* core0 sp_EL1 bit59 */
			{46634,34,0}, /* core0 sp_EL1 bit60 */
			{46632,34,0}, /* core0 sp_EL1 bit61 */
			{46630,34,0}, /* core0 sp_EL1 bit62 */
			{46628,34,0}, /* core0 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{31870,34,0}, /* core0 sp_EL2 bit0 */
			{39094,34,0}, /* core0 sp_EL2 bit1 */
			{31868,34,0}, /* core0 sp_EL2 bit2 */
			{39234,34,0}, /* core0 sp_EL2 bit3 */
			{39080,34,0}, /* core0 sp_EL2 bit4 */
			{39078,34,0}, /* core0 sp_EL2 bit5 */
			{39076,34,0}, /* core0 sp_EL2 bit6 */
			{39074,34,0}, /* core0 sp_EL2 bit7 */
			{39092,34,0}, /* core0 sp_EL2 bit8 */
			{39090,34,0}, /* core0 sp_EL2 bit9 */
			{39232,34,0}, /* core0 sp_EL2 bit10 */
			{39158,34,0}, /* core0 sp_EL2 bit11 */
			{39146,34,0}, /* core0 sp_EL2 bit12 */
			{39254,34,0}, /* core0 sp_EL2 bit13 */
			{39276,34,0}, /* core0 sp_EL2 bit14 */
			{39256,34,0}, /* core0 sp_EL2 bit15 */
			{39274,34,0}, /* core0 sp_EL2 bit16 */
			{39248,34,0}, /* core0 sp_EL2 bit17 */
			{31858,34,0}, /* core0 sp_EL2 bit18 */
			{39144,34,0}, /* core0 sp_EL2 bit19 */
			{39142,34,0}, /* core0 sp_EL2 bit20 */
			{39166,34,0}, /* core0 sp_EL2 bit21 */
			{39096,34,0}, /* core0 sp_EL2 bit22 */
			{39164,34,0}, /* core0 sp_EL2 bit23 */
			{39162,34,0}, /* core0 sp_EL2 bit24 */
			{39230,34,0}, /* core0 sp_EL2 bit25 */
			{39228,34,0}, /* core0 sp_EL2 bit26 */
			{39156,34,0}, /* core0 sp_EL2 bit27 */
			{39154,34,0}, /* core0 sp_EL2 bit28 */
			{39160,34,0}, /* core0 sp_EL2 bit29 */
			{39152,34,0}, /* core0 sp_EL2 bit30 */
			{31866,34,0}, /* core0 sp_EL2 bit31 */
			{39040,34,0}, /* core0 sp_EL2 bit32 */
			{32148,34,0}, /* core0 sp_EL2 bit33 */
			{39038,34,0}, /* core0 sp_EL2 bit34 */
			{39032,34,0}, /* core0 sp_EL2 bit35 */
			{39030,34,0}, /* core0 sp_EL2 bit36 */
			{32106,34,0}, /* core0 sp_EL2 bit37 */
			{39024,34,0}, /* core0 sp_EL2 bit38 */
			{38988,34,0}, /* core0 sp_EL2 bit39 */
			{39022,34,0}, /* core0 sp_EL2 bit40 */
			{38996,34,0}, /* core0 sp_EL2 bit41 */
			{38994,34,0}, /* core0 sp_EL2 bit42 */
			{38986,34,0}, /* core0 sp_EL2 bit43 */
			{38984,34,0}, /* core0 sp_EL2 bit44 */
			{32074,34,0}, /* core0 sp_EL2 bit45 */
			{38982,34,0}, /* core0 sp_EL2 bit46 */
			{46770,34,0}, /* core0 sp_EL2 bit47 */
			{46762,34,0}, /* core0 sp_EL2 bit48 */
			{46768,34,0}, /* core0 sp_EL2 bit49 */
			{46760,34,0}, /* core0 sp_EL2 bit50 */
			{46758,34,0}, /* core0 sp_EL2 bit51 */
			{46756,34,0}, /* core0 sp_EL2 bit52 */
			{46650,34,0}, /* core0 sp_EL2 bit53 */
			{46648,34,0}, /* core0 sp_EL2 bit54 */
			{46646,34,0}, /* core0 sp_EL2 bit55 */
			{46644,34,0}, /* core0 sp_EL2 bit56 */
			{46642,34,0}, /* core0 sp_EL2 bit57 */
			{46640,34,0}, /* core0 sp_EL2 bit58 */
			{46638,34,0}, /* core0 sp_EL2 bit59 */
			{46636,34,0}, /* core0 sp_EL2 bit60 */
			{46766,34,0}, /* core0 sp_EL2 bit61 */
			{46764,34,0}, /* core0 sp_EL2 bit62 */
			{32070,34,0}, /* core0 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{31844,34,0}, /* core0 sp_EL3 bit0 */
			{31884,34,0}, /* core0 sp_EL3 bit1 */
			{39056,34,0}, /* core0 sp_EL3 bit2 */
			{39220,34,0}, /* core0 sp_EL3 bit3 */
			{39052,34,0}, /* core0 sp_EL3 bit4 */
			{39050,34,0}, /* core0 sp_EL3 bit5 */
			{39054,34,0}, /* core0 sp_EL3 bit6 */
			{39048,34,0}, /* core0 sp_EL3 bit7 */
			{39046,34,0}, /* core0 sp_EL3 bit8 */
			{39102,34,0}, /* core0 sp_EL3 bit9 */
			{39212,34,0}, /* core0 sp_EL3 bit10 */
			{39206,34,0}, /* core0 sp_EL3 bit11 */
			{39204,34,0}, /* core0 sp_EL3 bit12 */
			{39120,34,0}, /* core0 sp_EL3 bit13 */
			{39104,34,0}, /* core0 sp_EL3 bit14 */
			{39118,34,0}, /* core0 sp_EL3 bit15 */
			{39108,34,0}, /* core0 sp_EL3 bit16 */
			{31832,34,0}, /* core0 sp_EL3 bit17 */
			{39218,34,0}, /* core0 sp_EL3 bit18 */
			{39224,34,0}, /* core0 sp_EL3 bit19 */
			{39222,34,0}, /* core0 sp_EL3 bit20 */
			{39196,34,0}, /* core0 sp_EL3 bit21 */
			{39106,34,0}, /* core0 sp_EL3 bit22 */
			{39194,34,0}, /* core0 sp_EL3 bit23 */
			{39200,34,0}, /* core0 sp_EL3 bit24 */
			{39210,34,0}, /* core0 sp_EL3 bit25 */
			{39198,34,0}, /* core0 sp_EL3 bit26 */
			{39216,34,0}, /* core0 sp_EL3 bit27 */
			{39208,34,0}, /* core0 sp_EL3 bit28 */
			{39202,34,0}, /* core0 sp_EL3 bit29 */
			{39214,34,0}, /* core0 sp_EL3 bit30 */
			{31834,34,0}, /* core0 sp_EL3 bit31 */
			{39036,34,0}, /* core0 sp_EL3 bit32 */
			{32140,34,0}, /* core0 sp_EL3 bit33 */
			{39034,34,0}, /* core0 sp_EL3 bit34 */
			{32144,34,0}, /* core0 sp_EL3 bit35 */
			{32142,34,0}, /* core0 sp_EL3 bit36 */
			{32124,34,0}, /* core0 sp_EL3 bit37 */
			{32126,34,0}, /* core0 sp_EL3 bit38 */
			{32092,34,0}, /* core0 sp_EL3 bit39 */
			{32094,34,0}, /* core0 sp_EL3 bit40 */
			{32084,34,0}, /* core0 sp_EL3 bit41 */
			{38992,34,0}, /* core0 sp_EL3 bit42 */
			{31930,34,0}, /* core0 sp_EL3 bit43 */
			{38990,34,0}, /* core0 sp_EL3 bit44 */
			{32076,34,0}, /* core0 sp_EL3 bit45 */
			{38972,34,0}, /* core0 sp_EL3 bit46 */
			{38976,34,0}, /* core0 sp_EL3 bit47 */
			{38974,34,0}, /* core0 sp_EL3 bit48 */
			{46658,34,0}, /* core0 sp_EL3 bit49 */
			{46656,34,0}, /* core0 sp_EL3 bit50 */
			{46654,34,0}, /* core0 sp_EL3 bit51 */
			{46652,34,0}, /* core0 sp_EL3 bit52 */
			{46674,34,0}, /* core0 sp_EL3 bit53 */
			{46672,34,0}, /* core0 sp_EL3 bit54 */
			{46670,34,0}, /* core0 sp_EL3 bit55 */
			{46668,34,0}, /* core0 sp_EL3 bit56 */
			{46666,34,0}, /* core0 sp_EL3 bit57 */
			{46664,34,0}, /* core0 sp_EL3 bit58 */
			{46662,34,0}, /* core0 sp_EL3 bit59 */
			{38970,34,0}, /* core0 sp_EL3 bit60 */
			{46660,34,0}, /* core0 sp_EL3 bit61 */
			{38968,34,0}, /* core0 sp_EL3 bit62 */
			{38966,34,0}, /* core0 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{46886,34,0}, /* core0 elr_EL1 bit0 */
			{46884,34,0}, /* core0 elr_EL1 bit1 */
			{46888,34,0}, /* core0 elr_EL1 bit2 */
			{46954,34,0}, /* core0 elr_EL1 bit3 */
			{46890,34,0}, /* core0 elr_EL1 bit4 */
			{46882,34,0}, /* core0 elr_EL1 bit5 */
			{46880,34,0}, /* core0 elr_EL1 bit6 */
			{46874,34,0}, /* core0 elr_EL1 bit7 */
			{46872,34,0}, /* core0 elr_EL1 bit8 */
			{46870,34,0}, /* core0 elr_EL1 bit9 */
			{46952,34,0}, /* core0 elr_EL1 bit10 */
			{46950,34,0}, /* core0 elr_EL1 bit11 */
			{46914,34,0}, /* core0 elr_EL1 bit12 */
			{46948,34,0}, /* core0 elr_EL1 bit13 */
			{46878,34,0}, /* core0 elr_EL1 bit14 */
			{46904,34,0}, /* core0 elr_EL1 bit15 */
			{46868,34,0}, /* core0 elr_EL1 bit16 */
			{31856,34,0}, /* core0 elr_EL1 bit17 */
			{46958,34,0}, /* core0 elr_EL1 bit18 */
			{46956,34,0}, /* core0 elr_EL1 bit19 */
			{46906,34,0}, /* core0 elr_EL1 bit20 */
			{46946,34,0}, /* core0 elr_EL1 bit21 */
			{46876,34,0}, /* core0 elr_EL1 bit22 */
			{46912,34,0}, /* core0 elr_EL1 bit23 */
			{46910,34,0}, /* core0 elr_EL1 bit24 */
			{46908,34,0}, /* core0 elr_EL1 bit25 */
			{46944,34,0}, /* core0 elr_EL1 bit26 */
			{46942,34,0}, /* core0 elr_EL1 bit27 */
			{46940,34,0}, /* core0 elr_EL1 bit28 */
			{39246,34,0}, /* core0 elr_EL1 bit29 */
			{39244,34,0}, /* core0 elr_EL1 bit30 */
			{31864,34,0}, /* core0 elr_EL1 bit31 */
			{46612,34,0}, /* core0 elr_EL1 bit32 */
			{46850,34,0}, /* core0 elr_EL1 bit33 */
			{46848,34,0}, /* core0 elr_EL1 bit34 */
			{46846,34,0}, /* core0 elr_EL1 bit35 */
			{46844,34,0}, /* core0 elr_EL1 bit36 */
			{46834,34,0}, /* core0 elr_EL1 bit37 */
			{46832,34,0}, /* core0 elr_EL1 bit38 */
			{46830,34,0}, /* core0 elr_EL1 bit39 */
			{46828,34,0}, /* core0 elr_EL1 bit40 */
			{46818,34,0}, /* core0 elr_EL1 bit41 */
			{46816,34,0}, /* core0 elr_EL1 bit42 */
			{46814,34,0}, /* core0 elr_EL1 bit43 */
			{46812,34,0}, /* core0 elr_EL1 bit44 */
			{46802,34,0}, /* core0 elr_EL1 bit45 */
			{46800,34,0}, /* core0 elr_EL1 bit46 */
			{46798,34,0}, /* core0 elr_EL1 bit47 */
			{46796,34,0}, /* core0 elr_EL1 bit48 */
			{46602,34,0}, /* core0 elr_EL1 bit49 */
			{46594,34,0}, /* core0 elr_EL1 bit50 */
			{46600,34,0}, /* core0 elr_EL1 bit51 */
			{46598,34,0}, /* core0 elr_EL1 bit52 */
			{46592,34,0}, /* core0 elr_EL1 bit53 */
			{46590,34,0}, /* core0 elr_EL1 bit54 */
			{46596,34,0}, /* core0 elr_EL1 bit55 */
			{46588,34,0}, /* core0 elr_EL1 bit56 */
			{46618,34,0}, /* core0 elr_EL1 bit57 */
			{46610,34,0}, /* core0 elr_EL1 bit58 */
			{46608,34,0}, /* core0 elr_EL1 bit59 */
			{46606,34,0}, /* core0 elr_EL1 bit60 */
			{46604,34,0}, /* core0 elr_EL1 bit61 */
			{46616,34,0}, /* core0 elr_EL1 bit62 */
			{46614,34,0}, /* core0 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{46866,34,0}, /* core0 elr_EL2 bit0 */
			{46864,34,0}, /* core0 elr_EL2 bit1 */
			{46894,34,0}, /* core0 elr_EL2 bit2 */
			{46930,34,0}, /* core0 elr_EL2 bit3 */
			{46892,34,0}, /* core0 elr_EL2 bit4 */
			{46858,34,0}, /* core0 elr_EL2 bit5 */
			{46856,34,0}, /* core0 elr_EL2 bit6 */
			{46854,34,0}, /* core0 elr_EL2 bit7 */
			{46862,34,0}, /* core0 elr_EL2 bit8 */
			{46860,34,0}, /* core0 elr_EL2 bit9 */
			{46928,34,0}, /* core0 elr_EL2 bit10 */
			{46962,34,0}, /* core0 elr_EL2 bit11 */
			{46960,34,0}, /* core0 elr_EL2 bit12 */
			{46902,34,0}, /* core0 elr_EL2 bit13 */
			{46898,34,0}, /* core0 elr_EL2 bit14 */
			{46900,34,0}, /* core0 elr_EL2 bit15 */
			{46852,34,0}, /* core0 elr_EL2 bit16 */
			{31860,34,0}, /* core0 elr_EL2 bit17 */
			{46922,34,0}, /* core0 elr_EL2 bit18 */
			{46920,34,0}, /* core0 elr_EL2 bit19 */
			{46918,34,0}, /* core0 elr_EL2 bit20 */
			{46916,34,0}, /* core0 elr_EL2 bit21 */
			{46896,34,0}, /* core0 elr_EL2 bit22 */
			{39150,34,0}, /* core0 elr_EL2 bit23 */
			{46926,34,0}, /* core0 elr_EL2 bit24 */
			{46924,34,0}, /* core0 elr_EL2 bit25 */
			{46938,34,0}, /* core0 elr_EL2 bit26 */
			{39148,34,0}, /* core0 elr_EL2 bit27 */
			{46936,34,0}, /* core0 elr_EL2 bit28 */
			{46934,34,0}, /* core0 elr_EL2 bit29 */
			{46932,34,0}, /* core0 elr_EL2 bit30 */
			{31862,34,0}, /* core0 elr_EL2 bit31 */
			{46782,34,0}, /* core0 elr_EL2 bit32 */
			{46780,34,0}, /* core0 elr_EL2 bit33 */
			{46842,34,0}, /* core0 elr_EL2 bit34 */
			{46840,34,0}, /* core0 elr_EL2 bit35 */
			{46838,34,0}, /* core0 elr_EL2 bit36 */
			{46836,34,0}, /* core0 elr_EL2 bit37 */
			{46826,34,0}, /* core0 elr_EL2 bit38 */
			{46824,34,0}, /* core0 elr_EL2 bit39 */
			{46794,34,0}, /* core0 elr_EL2 bit40 */
			{46822,34,0}, /* core0 elr_EL2 bit41 */
			{46820,34,0}, /* core0 elr_EL2 bit42 */
			{46792,34,0}, /* core0 elr_EL2 bit43 */
			{46810,34,0}, /* core0 elr_EL2 bit44 */
			{46808,34,0}, /* core0 elr_EL2 bit45 */
			{46806,34,0}, /* core0 elr_EL2 bit46 */
			{46804,34,0}, /* core0 elr_EL2 bit47 */
			{46626,34,0}, /* core0 elr_EL2 bit48 */
			{46790,34,0}, /* core0 elr_EL2 bit49 */
			{46788,34,0}, /* core0 elr_EL2 bit50 */
			{46578,34,0}, /* core0 elr_EL2 bit51 */
			{46576,34,0}, /* core0 elr_EL2 bit52 */
			{46574,34,0}, /* core0 elr_EL2 bit53 */
			{46572,34,0}, /* core0 elr_EL2 bit54 */
			{46570,34,0}, /* core0 elr_EL2 bit55 */
			{46568,34,0}, /* core0 elr_EL2 bit56 */
			{46624,34,0}, /* core0 elr_EL2 bit57 */
			{46566,34,0}, /* core0 elr_EL2 bit58 */
			{46564,34,0}, /* core0 elr_EL2 bit59 */
			{46622,34,0}, /* core0 elr_EL2 bit60 */
			{46786,34,0}, /* core0 elr_EL2 bit61 */
			{46784,34,0}, /* core0 elr_EL2 bit62 */
			{46620,34,0}, /* core0 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{39064,34,0}, /* core0 elr_EL3 bit0 */
			{39062,34,0}, /* core0 elr_EL3 bit1 */
			{39100,34,0}, /* core0 elr_EL3 bit2 */
			{39188,34,0}, /* core0 elr_EL3 bit3 */
			{39068,34,0}, /* core0 elr_EL3 bit4 */
			{39066,34,0}, /* core0 elr_EL3 bit5 */
			{39098,34,0}, /* core0 elr_EL3 bit6 */
			{31880,34,0}, /* core0 elr_EL3 bit7 */
			{39060,34,0}, /* core0 elr_EL3 bit8 */
			{39058,34,0}, /* core0 elr_EL3 bit9 */
			{39172,34,0}, /* core0 elr_EL3 bit10 */
			{39186,34,0}, /* core0 elr_EL3 bit11 */
			{39168,34,0}, /* core0 elr_EL3 bit12 */
			{39226,34,0}, /* core0 elr_EL3 bit13 */
			{39112,34,0}, /* core0 elr_EL3 bit14 */
			{39124,34,0}, /* core0 elr_EL3 bit15 */
			{39110,34,0}, /* core0 elr_EL3 bit16 */
			{39116,34,0}, /* core0 elr_EL3 bit17 */
			{31830,34,0}, /* core0 elr_EL3 bit18 */
			{39122,34,0}, /* core0 elr_EL3 bit19 */
			{39170,34,0}, /* core0 elr_EL3 bit20 */
			{39192,34,0}, /* core0 elr_EL3 bit21 */
			{39114,34,0}, /* core0 elr_EL3 bit22 */
			{39190,34,0}, /* core0 elr_EL3 bit23 */
			{31828,34,0}, /* core0 elr_EL3 bit24 */
			{39184,34,0}, /* core0 elr_EL3 bit25 */
			{39182,34,0}, /* core0 elr_EL3 bit26 */
			{39176,34,0}, /* core0 elr_EL3 bit27 */
			{39174,34,0}, /* core0 elr_EL3 bit28 */
			{39180,34,0}, /* core0 elr_EL3 bit29 */
			{39178,34,0}, /* core0 elr_EL3 bit30 */
			{31846,34,0}, /* core0 elr_EL3 bit31 */
			{46078,34,0}, /* core0 elr_EL3 bit32 */
			{39044,34,0}, /* core0 elr_EL3 bit33 */
			{39042,34,0}, /* core0 elr_EL3 bit34 */
			{32156,34,0}, /* core0 elr_EL3 bit35 */
			{32154,34,0}, /* core0 elr_EL3 bit36 */
			{39016,34,0}, /* core0 elr_EL3 bit37 */
			{39014,34,0}, /* core0 elr_EL3 bit38 */
			{39012,34,0}, /* core0 elr_EL3 bit39 */
			{31902,34,0}, /* core0 elr_EL3 bit40 */
			{31920,34,0}, /* core0 elr_EL3 bit41 */
			{39010,34,0}, /* core0 elr_EL3 bit42 */
			{38948,34,0}, /* core0 elr_EL3 bit43 */
			{38952,34,0}, /* core0 elr_EL3 bit44 */
			{38950,34,0}, /* core0 elr_EL3 bit45 */
			{38946,34,0}, /* core0 elr_EL3 bit46 */
			{38944,34,0}, /* core0 elr_EL3 bit47 */
			{38942,34,0}, /* core0 elr_EL3 bit48 */
			{46538,34,0}, /* core0 elr_EL3 bit49 */
			{46586,34,0}, /* core0 elr_EL3 bit50 */
			{46584,34,0}, /* core0 elr_EL3 bit51 */
			{46536,34,0}, /* core0 elr_EL3 bit52 */
			{46534,34,0}, /* core0 elr_EL3 bit53 */
			{46532,34,0}, /* core0 elr_EL3 bit54 */
			{46530,34,0}, /* core0 elr_EL3 bit55 */
			{46528,34,0}, /* core0 elr_EL3 bit56 */
			{46582,34,0}, /* core0 elr_EL3 bit57 */
			{46526,34,0}, /* core0 elr_EL3 bit58 */
			{46524,34,0}, /* core0 elr_EL3 bit59 */
			{46084,34,0}, /* core0 elr_EL3 bit60 */
			{46082,34,0}, /* core0 elr_EL3 bit61 */
			{46080,34,0}, /* core0 elr_EL3 bit62 */
			{46580,34,0}, /* core0 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{44712,34,0}, /* core0 raw_pc bit0 */
			{19018,37,0}, /* core0 raw_pc bit1 */
			{19016,37,0}, /* core0 raw_pc bit2 */
			{19012,37,0}, /* core0 raw_pc bit3 */
			{19014,37,0}, /* core0 raw_pc bit4 */
			{44704,34,0}, /* core0 raw_pc bit5 */
			{44702,34,0}, /* core0 raw_pc bit6 */
			{19158,37,0}, /* core0 raw_pc bit7 */
			{19032,37,0}, /* core0 raw_pc bit8 */
			{19030,37,0}, /* core0 raw_pc bit9 */
			{19028,37,0}, /* core0 raw_pc bit10 */
			{19156,37,0}, /* core0 raw_pc bit11 */
			{19154,37,0}, /* core0 raw_pc bit12 */
			{19152,37,0}, /* core0 raw_pc bit13 */
			{19150,37,0}, /* core0 raw_pc bit14 */
			{19148,37,0}, /* core0 raw_pc bit15 */
			{19146,37,0}, /* core0 raw_pc bit16 */
			{19144,37,0}, /* core0 raw_pc bit17 */
			{19142,37,0}, /* core0 raw_pc bit18 */
			{19060,37,0}, /* core0 raw_pc bit19 */
			{19058,37,0}, /* core0 raw_pc bit20 */
			{19056,37,0}, /* core0 raw_pc bit21 */
			{19054,37,0}, /* core0 raw_pc bit22 */
			{19052,37,0}, /* core0 raw_pc bit23 */
			{19050,37,0}, /* core0 raw_pc bit24 */
			{19048,37,0}, /* core0 raw_pc bit25 */
			{19046,37,0}, /* core0 raw_pc bit26 */
			{19044,37,0}, /* core0 raw_pc bit27 */
			{19042,37,0}, /* core0 raw_pc bit28 */
			{19040,37,0}, /* core0 raw_pc bit29 */
			{19038,37,0}, /* core0 raw_pc bit30 */
			{19010,37,0}, /* core0 raw_pc bit31 */
			{19008,37,0}, /* core0 raw_pc bit32 */
			{19006,37,0}, /* core0 raw_pc bit33 */
			{19004,37,0}, /* core0 raw_pc bit34 */
			{19002,37,0}, /* core0 raw_pc bit35 */
			{19000,37,0}, /* core0 raw_pc bit36 */
			{18998,37,0}, /* core0 raw_pc bit37 */
			{18996,37,0}, /* core0 raw_pc bit38 */
			{18994,37,0}, /* core0 raw_pc bit39 */
			{18992,37,0}, /* core0 raw_pc bit40 */
			{18990,37,0}, /* core0 raw_pc bit41 */
			{18988,37,0}, /* core0 raw_pc bit42 */
			{18982,37,0}, /* core0 raw_pc bit43 */
			{18980,37,0}, /* core0 raw_pc bit44 */
			{18986,37,0}, /* core0 raw_pc bit45 */
			{18984,37,0}, /* core0 raw_pc bit46 */
			{44708,34,0}, /* core0 raw_pc bit47 */
			{44706,34,0}, /* core0 raw_pc bit48 */
			{36762,34,0}, /* core0 raw_pc bit49 */
			{    0, 0,2}, /* core0 raw_pc bit50 */
			{    0, 0,2}, /* core0 raw_pc bit51 */
			{    0, 0,2}, /* core0 raw_pc bit52 */
			{    0, 0,2}, /* core0 raw_pc bit53 */
			{    0, 0,2}, /* core0 raw_pc bit54 */
			{    0, 0,2}, /* core0 raw_pc bit55 */
			{    0, 0,2}, /* core0 raw_pc bit56 */
			{    0, 0,2}, /* core0 raw_pc bit57 */
			{    0, 0,2}, /* core0 raw_pc bit58 */
			{    0, 0,2}, /* core0 raw_pc bit59 */
			{    0, 0,2}, /* core0 raw_pc bit60 */
			{    0, 0,2}, /* core0 raw_pc bit61 */
			{    0, 0,2}, /* core0 raw_pc bit62 */
			{    0, 0,2}, /* core0 raw_pc bit63 */
			}},
			.pc_iss = {{
			{44752,34,0}, /* core0 pc_iss bit0 */
			{44760,34,0}, /* core0 pc_iss bit1 */
			{44758,34,0}, /* core0 pc_iss bit2 */
			{44764,34,0}, /* core0 pc_iss bit3 */
			{44762,34,0}, /* core0 pc_iss bit4 */
			{44750,34,0}, /* core0 pc_iss bit5 */
			{44756,34,0}, /* core0 pc_iss bit6 */
			{44754,34,0}, /* core0 pc_iss bit7 */
			{44768,34,0}, /* core0 pc_iss bit8 */
			{44766,34,0}, /* core0 pc_iss bit9 */
			{44746,34,0}, /* core0 pc_iss bit10 */
			{44744,34,0}, /* core0 pc_iss bit11 */
			{45102,34,0}, /* core0 pc_iss bit12 */
			{45100,34,0}, /* core0 pc_iss bit13 */
			{45098,34,0}, /* core0 pc_iss bit14 */
			{44748,34,0}, /* core0 pc_iss bit15 */
			{45096,34,0}, /* core0 pc_iss bit16 */
			{45090,34,0}, /* core0 pc_iss bit17 */
			{45088,34,0}, /* core0 pc_iss bit18 */
			{45082,34,0}, /* core0 pc_iss bit19 */
			{45080,34,0}, /* core0 pc_iss bit20 */
			{45086,34,0}, /* core0 pc_iss bit21 */
			{45084,34,0}, /* core0 pc_iss bit22 */
			{44782,34,0}, /* core0 pc_iss bit23 */
			{44780,34,0}, /* core0 pc_iss bit24 */
			{36740,34,0}, /* core0 pc_iss bit25 */
			{36738,34,0}, /* core0 pc_iss bit26 */
			{45094,34,0}, /* core0 pc_iss bit27 */
			{45092,34,0}, /* core0 pc_iss bit28 */
			{44742,34,0}, /* core0 pc_iss bit29 */
			{44740,34,0}, /* core0 pc_iss bit30 */
			{44778,34,0}, /* core0 pc_iss bit31 */
			{44700,34,0}, /* core0 pc_iss bit32 */
			{44698,34,0}, /* core0 pc_iss bit33 */
			{44696,34,0}, /* core0 pc_iss bit34 */
			{44694,34,0}, /* core0 pc_iss bit35 */
			{44680,34,0}, /* core0 pc_iss bit36 */
			{44678,34,0}, /* core0 pc_iss bit37 */
			{44692,34,0}, /* core0 pc_iss bit38 */
			{44688,34,0}, /* core0 pc_iss bit39 */
			{44686,34,0}, /* core0 pc_iss bit40 */
			{44684,34,0}, /* core0 pc_iss bit41 */
			{44682,34,0}, /* core0 pc_iss bit42 */
			{44690,34,0}, /* core0 pc_iss bit43 */
			{18930,37,0}, /* core0 pc_iss bit44 */
			{18928,37,0}, /* core0 pc_iss bit45 */
			{18926,37,0}, /* core0 pc_iss bit46 */
			{18924,37,0}, /* core0 pc_iss bit47 */
			{18922,37,0}, /* core0 pc_iss bit48 */
			{18920,37,0}, /* core0 pc_iss bit49 */
			{18918,37,0}, /* core0 pc_iss bit50 */
			{18880,37,0}, /* core0 pc_iss bit51 */
			{18904,37,0}, /* core0 pc_iss bit52 */
			{18902,37,0}, /* core0 pc_iss bit53 */
			{18916,37,0}, /* core0 pc_iss bit54 */
			{18914,37,0}, /* core0 pc_iss bit55 */
			{19026,37,0}, /* core0 pc_iss bit56 */
			{19020,37,0}, /* core0 pc_iss bit57 */
			{19036,37,0}, /* core0 pc_iss bit58 */
			{19034,37,0}, /* core0 pc_iss bit59 */
			{18900,37,0}, /* core0 pc_iss bit60 */
			{18898,37,0}, /* core0 pc_iss bit61 */
			{19024,37,0}, /* core0 pc_iss bit62 */
			{19022,37,0}, /* core0 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{44710,34,0}, /* core0 full_pc_wr bit0 */
			{    0, 0,2}, /* core0 full_pc_wr bit1 */
			{    0, 0,2}, /* core0 full_pc_wr bit2 */
			{    0, 0,2}, /* core0 full_pc_wr bit3 */
			{    0, 0,2}, /* core0 full_pc_wr bit4 */
			{    0, 0,2}, /* core0 full_pc_wr bit5 */
			{    0, 0,2}, /* core0 full_pc_wr bit6 */
			{    0, 0,2}, /* core0 full_pc_wr bit7 */
			{    0, 0,2}, /* core0 full_pc_wr bit8 */
			{    0, 0,2}, /* core0 full_pc_wr bit9 */
			{    0, 0,2}, /* core0 full_pc_wr bit10 */
			{    0, 0,2}, /* core0 full_pc_wr bit11 */
			{    0, 0,2}, /* core0 full_pc_wr bit12 */
			{    0, 0,2}, /* core0 full_pc_wr bit13 */
			{    0, 0,2}, /* core0 full_pc_wr bit14 */
			{    0, 0,2}, /* core0 full_pc_wr bit15 */
			{    0, 0,2}, /* core0 full_pc_wr bit16 */
			{    0, 0,2}, /* core0 full_pc_wr bit17 */
			{    0, 0,2}, /* core0 full_pc_wr bit18 */
			{    0, 0,2}, /* core0 full_pc_wr bit19 */
			{    0, 0,2}, /* core0 full_pc_wr bit20 */
			{    0, 0,2}, /* core0 full_pc_wr bit21 */
			{    0, 0,2}, /* core0 full_pc_wr bit22 */
			{    0, 0,2}, /* core0 full_pc_wr bit23 */
			{    0, 0,2}, /* core0 full_pc_wr bit24 */
			{    0, 0,2}, /* core0 full_pc_wr bit25 */
			{    0, 0,2}, /* core0 full_pc_wr bit26 */
			{    0, 0,2}, /* core0 full_pc_wr bit27 */
			{    0, 0,2}, /* core0 full_pc_wr bit28 */
			{    0, 0,2}, /* core0 full_pc_wr bit29 */
			{    0, 0,2}, /* core0 full_pc_wr bit30 */
			{    0, 0,2}, /* core0 full_pc_wr bit31 */
			{    0, 0,2}, /* core0 full_pc_wr bit32 */
			{    0, 0,2}, /* core0 full_pc_wr bit33 */
			{    0, 0,2}, /* core0 full_pc_wr bit34 */
			{    0, 0,2}, /* core0 full_pc_wr bit35 */
			{    0, 0,2}, /* core0 full_pc_wr bit36 */
			{    0, 0,2}, /* core0 full_pc_wr bit37 */
			{    0, 0,2}, /* core0 full_pc_wr bit38 */
			{    0, 0,2}, /* core0 full_pc_wr bit39 */
			{    0, 0,2}, /* core0 full_pc_wr bit40 */
			{    0, 0,2}, /* core0 full_pc_wr bit41 */
			{    0, 0,2}, /* core0 full_pc_wr bit42 */
			{    0, 0,2}, /* core0 full_pc_wr bit43 */
			{    0, 0,2}, /* core0 full_pc_wr bit44 */
			{    0, 0,2}, /* core0 full_pc_wr bit45 */
			{    0, 0,2}, /* core0 full_pc_wr bit46 */
			{    0, 0,2}, /* core0 full_pc_wr bit47 */
			{    0, 0,2}, /* core0 full_pc_wr bit48 */
			{    0, 0,2}, /* core0 full_pc_wr bit49 */
			{    0, 0,2}, /* core0 full_pc_wr bit50 */
			{    0, 0,2}, /* core0 full_pc_wr bit51 */
			{    0, 0,2}, /* core0 full_pc_wr bit52 */
			{    0, 0,2}, /* core0 full_pc_wr bit53 */
			{    0, 0,2}, /* core0 full_pc_wr bit54 */
			{    0, 0,2}, /* core0 full_pc_wr bit55 */
			{    0, 0,2}, /* core0 full_pc_wr bit56 */
			{    0, 0,2}, /* core0 full_pc_wr bit57 */
			{    0, 0,2}, /* core0 full_pc_wr bit58 */
			{    0, 0,2}, /* core0 full_pc_wr bit59 */
			{    0, 0,2}, /* core0 full_pc_wr bit60 */
			{    0, 0,2}, /* core0 full_pc_wr bit61 */
			{    0, 0,2}, /* core0 full_pc_wr bit62 */
			{    0, 0,2}, /* core0 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{37250,34,0}, /* core0 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core0 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{44772,34,0}, /* core0 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core0 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{ 7874,35,0}, /* core0 return_Stack_pointer bit0 */
			{ 7872,35,0}, /* core0 return_Stack_pointer bit1 */
			{ 7878,35,0}, /* core0 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core0 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{19482,35,0}, /* core0 return_Stack0 bit0 */
			{19480,35,0}, /* core0 return_Stack0 bit1 */
			{19478,35,0}, /* core0 return_Stack0 bit2 */
			{19476,35,0}, /* core0 return_Stack0 bit3 */
			{19266,35,0}, /* core0 return_Stack0 bit4 */
			{19264,35,0}, /* core0 return_Stack0 bit5 */
			{19262,35,0}, /* core0 return_Stack0 bit6 */
			{19260,35,0}, /* core0 return_Stack0 bit7 */
			{19274,35,0}, /* core0 return_Stack0 bit8 */
			{19272,35,0}, /* core0 return_Stack0 bit9 */
			{19270,35,0}, /* core0 return_Stack0 bit10 */
			{ 7838,35,0}, /* core0 return_Stack0 bit11 */
			{19268,35,0}, /* core0 return_Stack0 bit12 */
			{19250,35,0}, /* core0 return_Stack0 bit13 */
			{19248,35,0}, /* core0 return_Stack0 bit14 */
			{19246,35,0}, /* core0 return_Stack0 bit15 */
			{19244,35,0}, /* core0 return_Stack0 bit16 */
			{19442,35,0}, /* core0 return_Stack0 bit17 */
			{ 7836,35,0}, /* core0 return_Stack0 bit18 */
			{ 3022,35,0}, /* core0 return_Stack0 bit19 */
			{19440,35,0}, /* core0 return_Stack0 bit20 */
			{19438,35,0}, /* core0 return_Stack0 bit21 */
			{19436,35,0}, /* core0 return_Stack0 bit22 */
			{19426,35,0}, /* core0 return_Stack0 bit23 */
			{19424,35,0}, /* core0 return_Stack0 bit24 */
			{19422,35,0}, /* core0 return_Stack0 bit25 */
			{19420,35,0}, /* core0 return_Stack0 bit26 */
			{19434,35,0}, /* core0 return_Stack0 bit27 */
			{19432,35,0}, /* core0 return_Stack0 bit28 */
			{19430,35,0}, /* core0 return_Stack0 bit29 */
			{19428,35,0}, /* core0 return_Stack0 bit30 */
			{19394,35,0}, /* core0 return_Stack0 bit31 */
			{19392,35,0}, /* core0 return_Stack0 bit32 */
			{19390,35,0}, /* core0 return_Stack0 bit33 */
			{19388,35,0}, /* core0 return_Stack0 bit34 */
			{19378,35,0}, /* core0 return_Stack0 bit35 */
			{19376,35,0}, /* core0 return_Stack0 bit36 */
			{19374,35,0}, /* core0 return_Stack0 bit37 */
			{19372,35,0}, /* core0 return_Stack0 bit38 */
			{19362,35,0}, /* core0 return_Stack0 bit39 */
			{19360,35,0}, /* core0 return_Stack0 bit40 */
			{19358,35,0}, /* core0 return_Stack0 bit41 */
			{19356,35,0}, /* core0 return_Stack0 bit42 */
			{19498,35,0}, /* core0 return_Stack0 bit43 */
			{19496,35,0}, /* core0 return_Stack0 bit44 */
			{19494,35,0}, /* core0 return_Stack0 bit45 */
			{19492,35,0}, /* core0 return_Stack0 bit46 */
			{ 7846,35,0}, /* core0 return_Stack0 bit47 */
			{ 7844,35,0}, /* core0 return_Stack0 bit48 */
			{    0, 0,2}, /* core0 return_Stack0 bit49 */
			{    0, 0,2}, /* core0 return_Stack0 bit50 */
			{    0, 0,2}, /* core0 return_Stack0 bit51 */
			{    0, 0,2}, /* core0 return_Stack0 bit52 */
			{    0, 0,2}, /* core0 return_Stack0 bit53 */
			{    0, 0,2}, /* core0 return_Stack0 bit54 */
			{    0, 0,2}, /* core0 return_Stack0 bit55 */
			{    0, 0,2}, /* core0 return_Stack0 bit56 */
			{    0, 0,2}, /* core0 return_Stack0 bit57 */
			{    0, 0,2}, /* core0 return_Stack0 bit58 */
			{    0, 0,2}, /* core0 return_Stack0 bit59 */
			{    0, 0,2}, /* core0 return_Stack0 bit60 */
			{    0, 0,2}, /* core0 return_Stack0 bit61 */
			{    0, 0,2}, /* core0 return_Stack0 bit62 */
			{    0, 0,2}, /* core0 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{19490,35,0}, /* core0 return_Stack1 bit0 */
			{19488,35,0}, /* core0 return_Stack1 bit1 */
			{19486,35,0}, /* core0 return_Stack1 bit2 */
			{19484,35,0}, /* core0 return_Stack1 bit3 */
			{19242,35,0}, /* core0 return_Stack1 bit4 */
			{19240,35,0}, /* core0 return_Stack1 bit5 */
			{19466,35,0}, /* core0 return_Stack1 bit6 */
			{19238,35,0}, /* core0 return_Stack1 bit7 */
			{19236,35,0}, /* core0 return_Stack1 bit8 */
			{19258,35,0}, /* core0 return_Stack1 bit9 */
			{19256,35,0}, /* core0 return_Stack1 bit10 */
			{19464,35,0}, /* core0 return_Stack1 bit11 */
			{19254,35,0}, /* core0 return_Stack1 bit12 */
			{19252,35,0}, /* core0 return_Stack1 bit13 */
			{19474,35,0}, /* core0 return_Stack1 bit14 */
			{19472,35,0}, /* core0 return_Stack1 bit15 */
			{19470,35,0}, /* core0 return_Stack1 bit16 */
			{19468,35,0}, /* core0 return_Stack1 bit17 */
			{19462,35,0}, /* core0 return_Stack1 bit18 */
			{19460,35,0}, /* core0 return_Stack1 bit19 */
			{19410,35,0}, /* core0 return_Stack1 bit20 */
			{19408,35,0}, /* core0 return_Stack1 bit21 */
			{19406,35,0}, /* core0 return_Stack1 bit22 */
			{19404,35,0}, /* core0 return_Stack1 bit23 */
			{19418,35,0}, /* core0 return_Stack1 bit24 */
			{19416,35,0}, /* core0 return_Stack1 bit25 */
			{19414,35,0}, /* core0 return_Stack1 bit26 */
			{19412,35,0}, /* core0 return_Stack1 bit27 */
			{19402,35,0}, /* core0 return_Stack1 bit28 */
			{19400,35,0}, /* core0 return_Stack1 bit29 */
			{19398,35,0}, /* core0 return_Stack1 bit30 */
			{19396,35,0}, /* core0 return_Stack1 bit31 */
			{19386,35,0}, /* core0 return_Stack1 bit32 */
			{19384,35,0}, /* core0 return_Stack1 bit33 */
			{19382,35,0}, /* core0 return_Stack1 bit34 */
			{19380,35,0}, /* core0 return_Stack1 bit35 */
			{19370,35,0}, /* core0 return_Stack1 bit36 */
			{19368,35,0}, /* core0 return_Stack1 bit37 */
			{19366,35,0}, /* core0 return_Stack1 bit38 */
			{19364,35,0}, /* core0 return_Stack1 bit39 */
			{19354,35,0}, /* core0 return_Stack1 bit40 */
			{19346,35,0}, /* core0 return_Stack1 bit41 */
			{19344,35,0}, /* core0 return_Stack1 bit42 */
			{19352,35,0}, /* core0 return_Stack1 bit43 */
			{19350,35,0}, /* core0 return_Stack1 bit44 */
			{19342,35,0}, /* core0 return_Stack1 bit45 */
			{19348,35,0}, /* core0 return_Stack1 bit46 */
			{19340,35,0}, /* core0 return_Stack1 bit47 */
			{ 3024,35,0}, /* core0 return_Stack1 bit48 */
			{    0, 0,2}, /* core0 return_Stack1 bit49 */
			{    0, 0,2}, /* core0 return_Stack1 bit50 */
			{    0, 0,2}, /* core0 return_Stack1 bit51 */
			{    0, 0,2}, /* core0 return_Stack1 bit52 */
			{    0, 0,2}, /* core0 return_Stack1 bit53 */
			{    0, 0,2}, /* core0 return_Stack1 bit54 */
			{    0, 0,2}, /* core0 return_Stack1 bit55 */
			{    0, 0,2}, /* core0 return_Stack1 bit56 */
			{    0, 0,2}, /* core0 return_Stack1 bit57 */
			{    0, 0,2}, /* core0 return_Stack1 bit58 */
			{    0, 0,2}, /* core0 return_Stack1 bit59 */
			{    0, 0,2}, /* core0 return_Stack1 bit60 */
			{    0, 0,2}, /* core0 return_Stack1 bit61 */
			{    0, 0,2}, /* core0 return_Stack1 bit62 */
			{    0, 0,2}, /* core0 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{ 7850,35,0}, /* core0 return_Stack2 bit0 */
			{19282,35,0}, /* core0 return_Stack2 bit1 */
			{ 7848,35,0}, /* core0 return_Stack2 bit2 */
			{19280,35,0}, /* core0 return_Stack2 bit3 */
			{19278,35,0}, /* core0 return_Stack2 bit4 */
			{19234,35,0}, /* core0 return_Stack2 bit5 */
			{19276,35,0}, /* core0 return_Stack2 bit6 */
			{ 3028,35,0}, /* core0 return_Stack2 bit7 */
			{19232,35,0}, /* core0 return_Stack2 bit8 */
			{19230,35,0}, /* core0 return_Stack2 bit9 */
			{19218,35,0}, /* core0 return_Stack2 bit10 */
			{19228,35,0}, /* core0 return_Stack2 bit11 */
			{19216,35,0}, /* core0 return_Stack2 bit12 */
			{ 7834,35,0}, /* core0 return_Stack2 bit13 */
			{19214,35,0}, /* core0 return_Stack2 bit14 */
			{ 7832,35,0}, /* core0 return_Stack2 bit15 */
			{19212,35,0}, /* core0 return_Stack2 bit16 */
			{19202,35,0}, /* core0 return_Stack2 bit17 */
			{19200,35,0}, /* core0 return_Stack2 bit18 */
			{19198,35,0}, /* core0 return_Stack2 bit19 */
			{19196,35,0}, /* core0 return_Stack2 bit20 */
			{19178,35,0}, /* core0 return_Stack2 bit21 */
			{19176,35,0}, /* core0 return_Stack2 bit22 */
			{19174,35,0}, /* core0 return_Stack2 bit23 */
			{19172,35,0}, /* core0 return_Stack2 bit24 */
			{19170,35,0}, /* core0 return_Stack2 bit25 */
			{19168,35,0}, /* core0 return_Stack2 bit26 */
			{19166,35,0}, /* core0 return_Stack2 bit27 */
			{19164,35,0}, /* core0 return_Stack2 bit28 */
			{19138,35,0}, /* core0 return_Stack2 bit29 */
			{19136,35,0}, /* core0 return_Stack2 bit30 */
			{19134,35,0}, /* core0 return_Stack2 bit31 */
			{19132,35,0}, /* core0 return_Stack2 bit32 */
			{19538,35,0}, /* core0 return_Stack2 bit33 */
			{19536,35,0}, /* core0 return_Stack2 bit34 */
			{19534,35,0}, /* core0 return_Stack2 bit35 */
			{19532,35,0}, /* core0 return_Stack2 bit36 */
			{19522,35,0}, /* core0 return_Stack2 bit37 */
			{19520,35,0}, /* core0 return_Stack2 bit38 */
			{19518,35,0}, /* core0 return_Stack2 bit39 */
			{19516,35,0}, /* core0 return_Stack2 bit40 */
			{19514,35,0}, /* core0 return_Stack2 bit41 */
			{19512,35,0}, /* core0 return_Stack2 bit42 */
			{19510,35,0}, /* core0 return_Stack2 bit43 */
			{19508,35,0}, /* core0 return_Stack2 bit44 */
			{19338,35,0}, /* core0 return_Stack2 bit45 */
			{19336,35,0}, /* core0 return_Stack2 bit46 */
			{19334,35,0}, /* core0 return_Stack2 bit47 */
			{19332,35,0}, /* core0 return_Stack2 bit48 */
			{    0, 0,2}, /* core0 return_Stack2 bit49 */
			{    0, 0,2}, /* core0 return_Stack2 bit50 */
			{    0, 0,2}, /* core0 return_Stack2 bit51 */
			{    0, 0,2}, /* core0 return_Stack2 bit52 */
			{    0, 0,2}, /* core0 return_Stack2 bit53 */
			{    0, 0,2}, /* core0 return_Stack2 bit54 */
			{    0, 0,2}, /* core0 return_Stack2 bit55 */
			{    0, 0,2}, /* core0 return_Stack2 bit56 */
			{    0, 0,2}, /* core0 return_Stack2 bit57 */
			{    0, 0,2}, /* core0 return_Stack2 bit58 */
			{    0, 0,2}, /* core0 return_Stack2 bit59 */
			{    0, 0,2}, /* core0 return_Stack2 bit60 */
			{    0, 0,2}, /* core0 return_Stack2 bit61 */
			{    0, 0,2}, /* core0 return_Stack2 bit62 */
			{    0, 0,2}, /* core0 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{ 3030,35,0}, /* core0 return_Stack3 bit0 */
			{19322,35,0}, /* core0 return_Stack3 bit1 */
			{19320,35,0}, /* core0 return_Stack3 bit2 */
			{19318,35,0}, /* core0 return_Stack3 bit3 */
			{19316,35,0}, /* core0 return_Stack3 bit4 */
			{19290,35,0}, /* core0 return_Stack3 bit5 */
			{19288,35,0}, /* core0 return_Stack3 bit6 */
			{19286,35,0}, /* core0 return_Stack3 bit7 */
			{19284,35,0}, /* core0 return_Stack3 bit8 */
			{19226,35,0}, /* core0 return_Stack3 bit9 */
			{19224,35,0}, /* core0 return_Stack3 bit10 */
			{19222,35,0}, /* core0 return_Stack3 bit11 */
			{19220,35,0}, /* core0 return_Stack3 bit12 */
			{19210,35,0}, /* core0 return_Stack3 bit13 */
			{19208,35,0}, /* core0 return_Stack3 bit14 */
			{19206,35,0}, /* core0 return_Stack3 bit15 */
			{19204,35,0}, /* core0 return_Stack3 bit16 */
			{19194,35,0}, /* core0 return_Stack3 bit17 */
			{19192,35,0}, /* core0 return_Stack3 bit18 */
			{19190,35,0}, /* core0 return_Stack3 bit19 */
			{19188,35,0}, /* core0 return_Stack3 bit20 */
			{19186,35,0}, /* core0 return_Stack3 bit21 */
			{19184,35,0}, /* core0 return_Stack3 bit22 */
			{19182,35,0}, /* core0 return_Stack3 bit23 */
			{19180,35,0}, /* core0 return_Stack3 bit24 */
			{19162,35,0}, /* core0 return_Stack3 bit25 */
			{19160,35,0}, /* core0 return_Stack3 bit26 */
			{19158,35,0}, /* core0 return_Stack3 bit27 */
			{19156,35,0}, /* core0 return_Stack3 bit28 */
			{19130,35,0}, /* core0 return_Stack3 bit29 */
			{19128,35,0}, /* core0 return_Stack3 bit30 */
			{19126,35,0}, /* core0 return_Stack3 bit31 */
			{19124,35,0}, /* core0 return_Stack3 bit32 */
			{19546,35,0}, /* core0 return_Stack3 bit33 */
			{19544,35,0}, /* core0 return_Stack3 bit34 */
			{19542,35,0}, /* core0 return_Stack3 bit35 */
			{19540,35,0}, /* core0 return_Stack3 bit36 */
			{19530,35,0}, /* core0 return_Stack3 bit37 */
			{19528,35,0}, /* core0 return_Stack3 bit38 */
			{19526,35,0}, /* core0 return_Stack3 bit39 */
			{19524,35,0}, /* core0 return_Stack3 bit40 */
			{19506,35,0}, /* core0 return_Stack3 bit41 */
			{19504,35,0}, /* core0 return_Stack3 bit42 */
			{19502,35,0}, /* core0 return_Stack3 bit43 */
			{19500,35,0}, /* core0 return_Stack3 bit44 */
			{19330,35,0}, /* core0 return_Stack3 bit45 */
			{19328,35,0}, /* core0 return_Stack3 bit46 */
			{19326,35,0}, /* core0 return_Stack3 bit47 */
			{19324,35,0}, /* core0 return_Stack3 bit48 */
			{    0, 0,2}, /* core0 return_Stack3 bit49 */
			{    0, 0,2}, /* core0 return_Stack3 bit50 */
			{    0, 0,2}, /* core0 return_Stack3 bit51 */
			{    0, 0,2}, /* core0 return_Stack3 bit52 */
			{    0, 0,2}, /* core0 return_Stack3 bit53 */
			{    0, 0,2}, /* core0 return_Stack3 bit54 */
			{    0, 0,2}, /* core0 return_Stack3 bit55 */
			{    0, 0,2}, /* core0 return_Stack3 bit56 */
			{    0, 0,2}, /* core0 return_Stack3 bit57 */
			{    0, 0,2}, /* core0 return_Stack3 bit58 */
			{    0, 0,2}, /* core0 return_Stack3 bit59 */
			{    0, 0,2}, /* core0 return_Stack3 bit60 */
			{    0, 0,2}, /* core0 return_Stack3 bit61 */
			{    0, 0,2}, /* core0 return_Stack3 bit62 */
			{    0, 0,2}, /* core0 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{19314,35,0}, /* core0 return_Stack4 bit0 */
			{19312,35,0}, /* core0 return_Stack4 bit1 */
			{19310,35,0}, /* core0 return_Stack4 bit2 */
			{19308,35,0}, /* core0 return_Stack4 bit3 */
			{19306,35,0}, /* core0 return_Stack4 bit4 */
			{19304,35,0}, /* core0 return_Stack4 bit5 */
			{19302,35,0}, /* core0 return_Stack4 bit6 */
			{19300,35,0}, /* core0 return_Stack4 bit7 */
			{19298,35,0}, /* core0 return_Stack4 bit8 */
			{19296,35,0}, /* core0 return_Stack4 bit9 */
			{19294,35,0}, /* core0 return_Stack4 bit10 */
			{19292,35,0}, /* core0 return_Stack4 bit11 */
			{19458,35,0}, /* core0 return_Stack4 bit12 */
			{ 7842,35,0}, /* core0 return_Stack4 bit13 */
			{19456,35,0}, /* core0 return_Stack4 bit14 */
			{ 7840,35,0}, /* core0 return_Stack4 bit15 */
			{19454,35,0}, /* core0 return_Stack4 bit16 */
			{19452,35,0}, /* core0 return_Stack4 bit17 */
			{19450,35,0}, /* core0 return_Stack4 bit18 */
			{19448,35,0}, /* core0 return_Stack4 bit19 */
			{19446,35,0}, /* core0 return_Stack4 bit20 */
			{19444,35,0}, /* core0 return_Stack4 bit21 */
			{19146,35,0}, /* core0 return_Stack4 bit22 */
			{19144,35,0}, /* core0 return_Stack4 bit23 */
			{19142,35,0}, /* core0 return_Stack4 bit24 */
			{19140,35,0}, /* core0 return_Stack4 bit25 */
			{19154,35,0}, /* core0 return_Stack4 bit26 */
			{19152,35,0}, /* core0 return_Stack4 bit27 */
			{19150,35,0}, /* core0 return_Stack4 bit28 */
			{19148,35,0}, /* core0 return_Stack4 bit29 */
			{19122,35,0}, /* core0 return_Stack4 bit30 */
			{19120,35,0}, /* core0 return_Stack4 bit31 */
			{19118,35,0}, /* core0 return_Stack4 bit32 */
			{19116,35,0}, /* core0 return_Stack4 bit33 */
			{19114,35,0}, /* core0 return_Stack4 bit34 */
			{19112,35,0}, /* core0 return_Stack4 bit35 */
			{19110,35,0}, /* core0 return_Stack4 bit36 */
			{19108,35,0}, /* core0 return_Stack4 bit37 */
			{19046,35,0}, /* core0 return_Stack4 bit38 */
			{19044,35,0}, /* core0 return_Stack4 bit39 */
			{19042,35,0}, /* core0 return_Stack4 bit40 */
			{19040,35,0}, /* core0 return_Stack4 bit41 */
			{19054,35,0}, /* core0 return_Stack4 bit42 */
			{19052,35,0}, /* core0 return_Stack4 bit43 */
			{19050,35,0}, /* core0 return_Stack4 bit44 */
			{19048,35,0}, /* core0 return_Stack4 bit45 */
			{ 7854,35,0}, /* core0 return_Stack4 bit46 */
			{ 7852,35,0}, /* core0 return_Stack4 bit47 */
			{ 3026,35,0}, /* core0 return_Stack4 bit48 */
			{    0, 0,2}, /* core0 return_Stack4 bit49 */
			{    0, 0,2}, /* core0 return_Stack4 bit50 */
			{    0, 0,2}, /* core0 return_Stack4 bit51 */
			{    0, 0,2}, /* core0 return_Stack4 bit52 */
			{    0, 0,2}, /* core0 return_Stack4 bit53 */
			{    0, 0,2}, /* core0 return_Stack4 bit54 */
			{    0, 0,2}, /* core0 return_Stack4 bit55 */
			{    0, 0,2}, /* core0 return_Stack4 bit56 */
			{    0, 0,2}, /* core0 return_Stack4 bit57 */
			{    0, 0,2}, /* core0 return_Stack4 bit58 */
			{    0, 0,2}, /* core0 return_Stack4 bit59 */
			{    0, 0,2}, /* core0 return_Stack4 bit60 */
			{    0, 0,2}, /* core0 return_Stack4 bit61 */
			{    0, 0,2}, /* core0 return_Stack4 bit62 */
			{    0, 0,2}, /* core0 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{18982,35,0}, /* core0 return_Stack5 bit0 */
			{18980,35,0}, /* core0 return_Stack5 bit1 */
			{18978,35,0}, /* core0 return_Stack5 bit2 */
			{18976,35,0}, /* core0 return_Stack5 bit3 */
			{18958,35,0}, /* core0 return_Stack5 bit4 */
			{18942,35,0}, /* core0 return_Stack5 bit5 */
			{18956,35,0}, /* core0 return_Stack5 bit6 */
			{18954,35,0}, /* core0 return_Stack5 bit7 */
			{18952,35,0}, /* core0 return_Stack5 bit8 */
			{18940,35,0}, /* core0 return_Stack5 bit9 */
			{18938,35,0}, /* core0 return_Stack5 bit10 */
			{18936,35,0}, /* core0 return_Stack5 bit11 */
			{18918,35,0}, /* core0 return_Stack5 bit12 */
			{18916,35,0}, /* core0 return_Stack5 bit13 */
			{18914,35,0}, /* core0 return_Stack5 bit14 */
			{18912,35,0}, /* core0 return_Stack5 bit15 */
			{18886,35,0}, /* core0 return_Stack5 bit16 */
			{18884,35,0}, /* core0 return_Stack5 bit17 */
			{18882,35,0}, /* core0 return_Stack5 bit18 */
			{18880,35,0}, /* core0 return_Stack5 bit19 */
			{18838,35,0}, /* core0 return_Stack5 bit20 */
			{18836,35,0}, /* core0 return_Stack5 bit21 */
			{18834,35,0}, /* core0 return_Stack5 bit22 */
			{18832,35,0}, /* core0 return_Stack5 bit23 */
			{18830,35,0}, /* core0 return_Stack5 bit24 */
			{18828,35,0}, /* core0 return_Stack5 bit25 */
			{18826,35,0}, /* core0 return_Stack5 bit26 */
			{18824,35,0}, /* core0 return_Stack5 bit27 */
			{19014,35,0}, /* core0 return_Stack5 bit28 */
			{19012,35,0}, /* core0 return_Stack5 bit29 */
			{19010,35,0}, /* core0 return_Stack5 bit30 */
			{19008,35,0}, /* core0 return_Stack5 bit31 */
			{19022,35,0}, /* core0 return_Stack5 bit32 */
			{ 7894,35,0}, /* core0 return_Stack5 bit33 */
			{19020,35,0}, /* core0 return_Stack5 bit34 */
			{19018,35,0}, /* core0 return_Stack5 bit35 */
			{19016,35,0}, /* core0 return_Stack5 bit36 */
			{ 7892,35,0}, /* core0 return_Stack5 bit37 */
			{19086,35,0}, /* core0 return_Stack5 bit38 */
			{19084,35,0}, /* core0 return_Stack5 bit39 */
			{19082,35,0}, /* core0 return_Stack5 bit40 */
			{19080,35,0}, /* core0 return_Stack5 bit41 */
			{19062,35,0}, /* core0 return_Stack5 bit42 */
			{19060,35,0}, /* core0 return_Stack5 bit43 */
			{19058,35,0}, /* core0 return_Stack5 bit44 */
			{19056,35,0}, /* core0 return_Stack5 bit45 */
			{ 7862,35,0}, /* core0 return_Stack5 bit46 */
			{ 7860,35,0}, /* core0 return_Stack5 bit47 */
			{ 3034,35,0}, /* core0 return_Stack5 bit48 */
			{    0, 0,2}, /* core0 return_Stack5 bit49 */
			{    0, 0,2}, /* core0 return_Stack5 bit50 */
			{    0, 0,2}, /* core0 return_Stack5 bit51 */
			{    0, 0,2}, /* core0 return_Stack5 bit52 */
			{    0, 0,2}, /* core0 return_Stack5 bit53 */
			{    0, 0,2}, /* core0 return_Stack5 bit54 */
			{    0, 0,2}, /* core0 return_Stack5 bit55 */
			{    0, 0,2}, /* core0 return_Stack5 bit56 */
			{    0, 0,2}, /* core0 return_Stack5 bit57 */
			{    0, 0,2}, /* core0 return_Stack5 bit58 */
			{    0, 0,2}, /* core0 return_Stack5 bit59 */
			{    0, 0,2}, /* core0 return_Stack5 bit60 */
			{    0, 0,2}, /* core0 return_Stack5 bit61 */
			{    0, 0,2}, /* core0 return_Stack5 bit62 */
			{    0, 0,2}, /* core0 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{18990,35,0}, /* core0 return_Stack6 bit0 */
			{18988,35,0}, /* core0 return_Stack6 bit1 */
			{18986,35,0}, /* core0 return_Stack6 bit2 */
			{18984,35,0}, /* core0 return_Stack6 bit3 */
			{18950,35,0}, /* core0 return_Stack6 bit4 */
			{18926,35,0}, /* core0 return_Stack6 bit5 */
			{18948,35,0}, /* core0 return_Stack6 bit6 */
			{18946,35,0}, /* core0 return_Stack6 bit7 */
			{18944,35,0}, /* core0 return_Stack6 bit8 */
			{18924,35,0}, /* core0 return_Stack6 bit9 */
			{18922,35,0}, /* core0 return_Stack6 bit10 */
			{18920,35,0}, /* core0 return_Stack6 bit11 */
			{18902,35,0}, /* core0 return_Stack6 bit12 */
			{18900,35,0}, /* core0 return_Stack6 bit13 */
			{18898,35,0}, /* core0 return_Stack6 bit14 */
			{18896,35,0}, /* core0 return_Stack6 bit15 */
			{18894,35,0}, /* core0 return_Stack6 bit16 */
			{18892,35,0}, /* core0 return_Stack6 bit17 */
			{18890,35,0}, /* core0 return_Stack6 bit18 */
			{18888,35,0}, /* core0 return_Stack6 bit19 */
			{18862,35,0}, /* core0 return_Stack6 bit20 */
			{18860,35,0}, /* core0 return_Stack6 bit21 */
			{18858,35,0}, /* core0 return_Stack6 bit22 */
			{18856,35,0}, /* core0 return_Stack6 bit23 */
			{18846,35,0}, /* core0 return_Stack6 bit24 */
			{18844,35,0}, /* core0 return_Stack6 bit25 */
			{18842,35,0}, /* core0 return_Stack6 bit26 */
			{18840,35,0}, /* core0 return_Stack6 bit27 */
			{19006,35,0}, /* core0 return_Stack6 bit28 */
			{19004,35,0}, /* core0 return_Stack6 bit29 */
			{19002,35,0}, /* core0 return_Stack6 bit30 */
			{19000,35,0}, /* core0 return_Stack6 bit31 */
			{19030,35,0}, /* core0 return_Stack6 bit32 */
			{ 7886,35,0}, /* core0 return_Stack6 bit33 */
			{19028,35,0}, /* core0 return_Stack6 bit34 */
			{19026,35,0}, /* core0 return_Stack6 bit35 */
			{19024,35,0}, /* core0 return_Stack6 bit36 */
			{ 7884,35,0}, /* core0 return_Stack6 bit37 */
			{19102,35,0}, /* core0 return_Stack6 bit38 */
			{19100,35,0}, /* core0 return_Stack6 bit39 */
			{19098,35,0}, /* core0 return_Stack6 bit40 */
			{19096,35,0}, /* core0 return_Stack6 bit41 */
			{19070,35,0}, /* core0 return_Stack6 bit42 */
			{19068,35,0}, /* core0 return_Stack6 bit43 */
			{19066,35,0}, /* core0 return_Stack6 bit44 */
			{19064,35,0}, /* core0 return_Stack6 bit45 */
			{ 7866,35,0}, /* core0 return_Stack6 bit46 */
			{ 7864,35,0}, /* core0 return_Stack6 bit47 */
			{ 3036,35,0}, /* core0 return_Stack6 bit48 */
			{    0, 0,2}, /* core0 return_Stack6 bit49 */
			{    0, 0,2}, /* core0 return_Stack6 bit50 */
			{    0, 0,2}, /* core0 return_Stack6 bit51 */
			{    0, 0,2}, /* core0 return_Stack6 bit52 */
			{    0, 0,2}, /* core0 return_Stack6 bit53 */
			{    0, 0,2}, /* core0 return_Stack6 bit54 */
			{    0, 0,2}, /* core0 return_Stack6 bit55 */
			{    0, 0,2}, /* core0 return_Stack6 bit56 */
			{    0, 0,2}, /* core0 return_Stack6 bit57 */
			{    0, 0,2}, /* core0 return_Stack6 bit58 */
			{    0, 0,2}, /* core0 return_Stack6 bit59 */
			{    0, 0,2}, /* core0 return_Stack6 bit60 */
			{    0, 0,2}, /* core0 return_Stack6 bit61 */
			{    0, 0,2}, /* core0 return_Stack6 bit62 */
			{    0, 0,2}, /* core0 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{18974,35,0}, /* core0 return_Stack7 bit0 */
			{18972,35,0}, /* core0 return_Stack7 bit1 */
			{18970,35,0}, /* core0 return_Stack7 bit2 */
			{18968,35,0}, /* core0 return_Stack7 bit3 */
			{18966,35,0}, /* core0 return_Stack7 bit4 */
			{18934,35,0}, /* core0 return_Stack7 bit5 */
			{18964,35,0}, /* core0 return_Stack7 bit6 */
			{18962,35,0}, /* core0 return_Stack7 bit7 */
			{18960,35,0}, /* core0 return_Stack7 bit8 */
			{18932,35,0}, /* core0 return_Stack7 bit9 */
			{18930,35,0}, /* core0 return_Stack7 bit10 */
			{18928,35,0}, /* core0 return_Stack7 bit11 */
			{18910,35,0}, /* core0 return_Stack7 bit12 */
			{18908,35,0}, /* core0 return_Stack7 bit13 */
			{18906,35,0}, /* core0 return_Stack7 bit14 */
			{18904,35,0}, /* core0 return_Stack7 bit15 */
			{18878,35,0}, /* core0 return_Stack7 bit16 */
			{18876,35,0}, /* core0 return_Stack7 bit17 */
			{18874,35,0}, /* core0 return_Stack7 bit18 */
			{18872,35,0}, /* core0 return_Stack7 bit19 */
			{18870,35,0}, /* core0 return_Stack7 bit20 */
			{18868,35,0}, /* core0 return_Stack7 bit21 */
			{18866,35,0}, /* core0 return_Stack7 bit22 */
			{18864,35,0}, /* core0 return_Stack7 bit23 */
			{18854,35,0}, /* core0 return_Stack7 bit24 */
			{18852,35,0}, /* core0 return_Stack7 bit25 */
			{18850,35,0}, /* core0 return_Stack7 bit26 */
			{18848,35,0}, /* core0 return_Stack7 bit27 */
			{18998,35,0}, /* core0 return_Stack7 bit28 */
			{18996,35,0}, /* core0 return_Stack7 bit29 */
			{18994,35,0}, /* core0 return_Stack7 bit30 */
			{18992,35,0}, /* core0 return_Stack7 bit31 */
			{19038,35,0}, /* core0 return_Stack7 bit32 */
			{ 7890,35,0}, /* core0 return_Stack7 bit33 */
			{19036,35,0}, /* core0 return_Stack7 bit34 */
			{19034,35,0}, /* core0 return_Stack7 bit35 */
			{19032,35,0}, /* core0 return_Stack7 bit36 */
			{ 7888,35,0}, /* core0 return_Stack7 bit37 */
			{19094,35,0}, /* core0 return_Stack7 bit38 */
			{19092,35,0}, /* core0 return_Stack7 bit39 */
			{19090,35,0}, /* core0 return_Stack7 bit40 */
			{19088,35,0}, /* core0 return_Stack7 bit41 */
			{19078,35,0}, /* core0 return_Stack7 bit42 */
			{19076,35,0}, /* core0 return_Stack7 bit43 */
			{19074,35,0}, /* core0 return_Stack7 bit44 */
			{19072,35,0}, /* core0 return_Stack7 bit45 */
			{ 7858,35,0}, /* core0 return_Stack7 bit46 */
			{ 7856,35,0}, /* core0 return_Stack7 bit47 */
			{ 3032,35,0}, /* core0 return_Stack7 bit48 */
			{    0, 0,2}, /* core0 return_Stack7 bit49 */
			{    0, 0,2}, /* core0 return_Stack7 bit50 */
			{    0, 0,2}, /* core0 return_Stack7 bit51 */
			{    0, 0,2}, /* core0 return_Stack7 bit52 */
			{    0, 0,2}, /* core0 return_Stack7 bit53 */
			{    0, 0,2}, /* core0 return_Stack7 bit54 */
			{    0, 0,2}, /* core0 return_Stack7 bit55 */
			{    0, 0,2}, /* core0 return_Stack7 bit56 */
			{    0, 0,2}, /* core0 return_Stack7 bit57 */
			{    0, 0,2}, /* core0 return_Stack7 bit58 */
			{    0, 0,2}, /* core0 return_Stack7 bit59 */
			{    0, 0,2}, /* core0 return_Stack7 bit60 */
			{    0, 0,2}, /* core0 return_Stack7 bit61 */
			{    0, 0,2}, /* core0 return_Stack7 bit62 */
			{    0, 0,2}, /* core0 return_Stack7 bit63 */
			}},
	},
	{		/* core 1 */ 
			.pc = {{
			{ 2688,38,1}, /* core1 pc bit0 */
			{ 2686,38,1}, /* core1 pc bit1 */
			{ 2684,38,1}, /* core1 pc bit2 */
			{ 2682,38,1}, /* core1 pc bit3 */
			{ 2592,38,1}, /* core1 pc bit4 */
			{ 2590,38,1}, /* core1 pc bit5 */
			{ 2588,38,1}, /* core1 pc bit6 */
			{ 2586,38,1}, /* core1 pc bit7 */
			{ 2584,38,1}, /* core1 pc bit8 */
			{ 2582,38,1}, /* core1 pc bit9 */
			{ 2580,38,1}, /* core1 pc bit10 */
			{ 2578,38,1}, /* core1 pc bit11 */
			{ 2600,38,1}, /* core1 pc bit12 */
			{ 2598,38,1}, /* core1 pc bit13 */
			{ 2596,38,1}, /* core1 pc bit14 */
			{ 2594,38,1}, /* core1 pc bit15 */
			{ 2448,38,1}, /* core1 pc bit16 */
			{ 2446,38,1}, /* core1 pc bit17 */
			{ 2444,38,1}, /* core1 pc bit18 */
			{ 2442,38,1}, /* core1 pc bit19 */
			{ 2432,38,1}, /* core1 pc bit20 */
			{ 2430,38,1}, /* core1 pc bit21 */
			{ 2428,38,1}, /* core1 pc bit22 */
			{ 2426,38,1}, /* core1 pc bit23 */
			{ 2352,38,1}, /* core1 pc bit24 */
			{ 2350,38,1}, /* core1 pc bit25 */
			{ 2348,38,1}, /* core1 pc bit26 */
			{ 2346,38,1}, /* core1 pc bit27 */
			{ 2344,38,1}, /* core1 pc bit28 */
			{ 2342,38,1}, /* core1 pc bit29 */
			{ 2340,38,1}, /* core1 pc bit30 */
			{ 2338,38,1}, /* core1 pc bit31 */
			{ 2656,38,1}, /* core1 pc bit32 */
			{ 2654,38,1}, /* core1 pc bit33 */
			{ 2652,38,1}, /* core1 pc bit34 */
			{ 2650,38,1}, /* core1 pc bit35 */
			{ 2616,38,1}, /* core1 pc bit36 */
			{ 2614,38,1}, /* core1 pc bit37 */
			{ 2612,38,1}, /* core1 pc bit38 */
			{ 2610,38,1}, /* core1 pc bit39 */
			{ 2632,38,1}, /* core1 pc bit40 */
			{ 2630,38,1}, /* core1 pc bit41 */
			{  676,38,1}, /* core1 pc bit42 */
			{ 2628,38,1}, /* core1 pc bit43 */
			{ 2626,38,1}, /* core1 pc bit44 */
			{ 2608,38,1}, /* core1 pc bit45 */
			{ 2606,38,1}, /* core1 pc bit46 */
			{ 2604,38,1}, /* core1 pc bit47 */
			{ 2602,38,1}, /* core1 pc bit48 */
			{ 2400,38,1}, /* core1 pc bit49 */
			{ 2398,38,1}, /* core1 pc bit50 */
			{ 2396,38,1}, /* core1 pc bit51 */
			{ 2394,38,1}, /* core1 pc bit52 */
			{ 2312,38,1}, /* core1 pc bit53 */
			{ 2310,38,1}, /* core1 pc bit54 */
			{ 2308,38,1}, /* core1 pc bit55 */
			{ 2306,38,1}, /* core1 pc bit56 */
			{ 2164,38,1}, /* core1 pc bit57 */
			{ 2162,38,1}, /* core1 pc bit58 */
			{ 2160,38,1}, /* core1 pc bit59 */
			{ 2158,38,1}, /* core1 pc bit60 */
			{  682,38,1}, /* core1 pc bit61 */
			{  680,38,1}, /* core1 pc bit62 */
			{ 2228,38,1}, /* core1 pc bit63 */
			}},
			.sp32 = {{
			{32298,38,0}, /* core1 sp32 bit0 */
			{40686,38,0}, /* core1 sp32 bit1 */
			{32308,38,0}, /* core1 sp32 bit2 */
			{40522,38,0}, /* core1 sp32 bit3 */
			{40684,38,0}, /* core1 sp32 bit4 */
			{40682,38,0}, /* core1 sp32 bit5 */
			{40680,38,0}, /* core1 sp32 bit6 */
			{40690,38,0}, /* core1 sp32 bit7 */
			{40688,38,0}, /* core1 sp32 bit8 */
			{40654,38,0}, /* core1 sp32 bit9 */
			{40520,38,0}, /* core1 sp32 bit10 */
			{40526,38,0}, /* core1 sp32 bit11 */
			{40524,38,0}, /* core1 sp32 bit12 */
			{40646,38,0}, /* core1 sp32 bit13 */
			{40652,38,0}, /* core1 sp32 bit14 */
			{40644,38,0}, /* core1 sp32 bit15 */
			{40642,38,0}, /* core1 sp32 bit16 */
			{40640,38,0}, /* core1 sp32 bit17 */
			{32264,38,0}, /* core1 sp32 bit18 */
			{40614,38,0}, /* core1 sp32 bit19 */
			{40612,38,0}, /* core1 sp32 bit20 */
			{40510,38,0}, /* core1 sp32 bit21 */
			{32260,38,0}, /* core1 sp32 bit22 */
			{40508,38,0}, /* core1 sp32 bit23 */
			{40490,38,0}, /* core1 sp32 bit24 */
			{40488,38,0}, /* core1 sp32 bit25 */
			{40564,38,0}, /* core1 sp32 bit26 */
			{40562,38,0}, /* core1 sp32 bit27 */
			{40560,38,0}, /* core1 sp32 bit28 */
			{40566,38,0}, /* core1 sp32 bit29 */
			{32258,38,0}, /* core1 sp32 bit30 */
			{32256,38,0}, /* core1 sp32 bit31 */
			{40362,38,0}, /* core1 sp32 bit32 */
			{40360,38,0}, /* core1 sp32 bit33 */
			{40354,38,0}, /* core1 sp32 bit34 */
			{40352,38,0}, /* core1 sp32 bit35 */
			{40358,38,0}, /* core1 sp32 bit36 */
			{40356,38,0}, /* core1 sp32 bit37 */
			{31992,38,0}, /* core1 sp32 bit38 */
			{40350,38,0}, /* core1 sp32 bit39 */
			{40348,38,0}, /* core1 sp32 bit40 */
			{40322,38,0}, /* core1 sp32 bit41 */
			{40320,38,0}, /* core1 sp32 bit42 */
			{32028,38,0}, /* core1 sp32 bit43 */
			{40318,38,0}, /* core1 sp32 bit44 */
			{32030,38,0}, /* core1 sp32 bit45 */
			{40316,38,0}, /* core1 sp32 bit46 */
			{32032,38,0}, /* core1 sp32 bit47 */
			{47404,38,0}, /* core1 sp32 bit48 */
			{47402,38,0}, /* core1 sp32 bit49 */
			{47400,38,0}, /* core1 sp32 bit50 */
			{47398,38,0}, /* core1 sp32 bit51 */
			{47332,38,0}, /* core1 sp32 bit52 */
			{47330,38,0}, /* core1 sp32 bit53 */
			{47328,38,0}, /* core1 sp32 bit54 */
			{47326,38,0}, /* core1 sp32 bit55 */
			{47340,38,0}, /* core1 sp32 bit56 */
			{47338,38,0}, /* core1 sp32 bit57 */
			{47336,38,0}, /* core1 sp32 bit58 */
			{47334,38,0}, /* core1 sp32 bit59 */
			{47348,38,0}, /* core1 sp32 bit60 */
			{47346,38,0}, /* core1 sp32 bit61 */
			{47344,38,0}, /* core1 sp32 bit62 */
			{47342,38,0}, /* core1 sp32 bit63 */
			}},
			.fp32 = {{
			{32654,38,0}, /* core1 fp32 bit0 */
			{32322,38,0}, /* core1 fp32 bit1 */
			{40906,38,0}, /* core1 fp32 bit2 */
			{40900,38,0}, /* core1 fp32 bit3 */
			{40976,38,0}, /* core1 fp32 bit4 */
			{40974,38,0}, /* core1 fp32 bit5 */
			{40972,38,0}, /* core1 fp32 bit6 */
			{32646,38,0}, /* core1 fp32 bit7 */
			{40970,38,0}, /* core1 fp32 bit8 */
			{32320,38,0}, /* core1 fp32 bit9 */
			{40896,38,0}, /* core1 fp32 bit10 */
			{40904,38,0}, /* core1 fp32 bit11 */
			{40898,38,0}, /* core1 fp32 bit12 */
			{32390,38,0}, /* core1 fp32 bit13 */
			{40908,38,0}, /* core1 fp32 bit14 */
			{40902,38,0}, /* core1 fp32 bit15 */
			{40920,38,0}, /* core1 fp32 bit16 */
			{40918,38,0}, /* core1 fp32 bit17 */
			{32418,38,0}, /* core1 fp32 bit18 */
			{32386,38,0}, /* core1 fp32 bit19 */
			{40894,38,0}, /* core1 fp32 bit20 */
			{32348,38,0}, /* core1 fp32 bit21 */
			{32412,38,0}, /* core1 fp32 bit22 */
			{32334,38,0}, /* core1 fp32 bit23 */
			{32336,38,0}, /* core1 fp32 bit24 */
			{32342,38,0}, /* core1 fp32 bit25 */
			{40916,38,0}, /* core1 fp32 bit26 */
			{40914,38,0}, /* core1 fp32 bit27 */
			{32388,38,0}, /* core1 fp32 bit28 */
			{40924,38,0}, /* core1 fp32 bit29 */
			{40922,38,0}, /* core1 fp32 bit30 */
			{32424,38,0}, /* core1 fp32 bit31 */
			{41026,38,0}, /* core1 fp32 bit32 */
			{32578,38,0}, /* core1 fp32 bit33 */
			{41036,38,0}, /* core1 fp32 bit34 */
			{41022,38,0}, /* core1 fp32 bit35 */
			{41024,38,0}, /* core1 fp32 bit36 */
			{41028,38,0}, /* core1 fp32 bit37 */
			{32580,38,0}, /* core1 fp32 bit38 */
			{32582,38,0}, /* core1 fp32 bit39 */
			{41032,38,0}, /* core1 fp32 bit40 */
			{41030,38,0}, /* core1 fp32 bit41 */
			{41040,38,0}, /* core1 fp32 bit42 */
			{32552,38,0}, /* core1 fp32 bit43 */
			{41038,38,0}, /* core1 fp32 bit44 */
			{40992,38,0}, /* core1 fp32 bit45 */
			{41034,38,0}, /* core1 fp32 bit46 */
			{40990,38,0}, /* core1 fp32 bit47 */
			{32614,38,0}, /* core1 fp32 bit48 */
			{41064,38,0}, /* core1 fp32 bit49 */
			{47526,38,0}, /* core1 fp32 bit50 */
			{47524,38,0}, /* core1 fp32 bit51 */
			{47520,38,0}, /* core1 fp32 bit52 */
			{47430,38,0}, /* core1 fp32 bit53 */
			{47428,38,0}, /* core1 fp32 bit54 */
			{47426,38,0}, /* core1 fp32 bit55 */
			{47422,38,0}, /* core1 fp32 bit56 */
			{47424,38,0}, /* core1 fp32 bit57 */
			{47420,38,0}, /* core1 fp32 bit58 */
			{41062,38,0}, /* core1 fp32 bit59 */
			{47418,38,0}, /* core1 fp32 bit60 */
			{47416,38,0}, /* core1 fp32 bit61 */
			{32634,38,0}, /* core1 fp32 bit62 */
			{47518,38,0}, /* core1 fp32 bit63 */
			}},
			.fp64 = {{
			{32172,38,0}, /* core1 fp64 bit0 */
			{31886,38,0}, /* core1 fp64 bit1 */
			{39704,38,0}, /* core1 fp64 bit2 */
			{39782,38,0}, /* core1 fp64 bit3 */
			{32160,38,0}, /* core1 fp64 bit4 */
			{39662,38,0}, /* core1 fp64 bit5 */
			{39650,38,0}, /* core1 fp64 bit6 */
			{39648,38,0}, /* core1 fp64 bit7 */
			{39682,38,0}, /* core1 fp64 bit8 */
			{39660,38,0}, /* core1 fp64 bit9 */
			{31822,38,0}, /* core1 fp64 bit10 */
			{31824,38,0}, /* core1 fp64 bit11 */
			{31818,38,0}, /* core1 fp64 bit12 */
			{32222,38,0}, /* core1 fp64 bit13 */
			{39680,38,0}, /* core1 fp64 bit14 */
			{32224,38,0}, /* core1 fp64 bit15 */
			{39722,38,0}, /* core1 fp64 bit16 */
			{39720,38,0}, /* core1 fp64 bit17 */
			{39778,38,0}, /* core1 fp64 bit18 */
			{39786,38,0}, /* core1 fp64 bit19 */
			{39780,38,0}, /* core1 fp64 bit20 */
			{39784,38,0}, /* core1 fp64 bit21 */
			{39706,38,0}, /* core1 fp64 bit22 */
			{39770,38,0}, /* core1 fp64 bit23 */
			{39768,38,0}, /* core1 fp64 bit24 */
			{39742,38,0}, /* core1 fp64 bit25 */
			{39776,38,0}, /* core1 fp64 bit26 */
			{39740,38,0}, /* core1 fp64 bit27 */
			{31826,38,0}, /* core1 fp64 bit28 */
			{39774,38,0}, /* core1 fp64 bit29 */
			{39772,38,0}, /* core1 fp64 bit30 */
			{31836,38,0}, /* core1 fp64 bit31 */
			{31976,38,0}, /* core1 fp64 bit32 */
			{31974,38,0}, /* core1 fp64 bit33 */
			{31972,38,0}, /* core1 fp64 bit34 */
			{39436,38,0}, /* core1 fp64 bit35 */
			{39438,38,0}, /* core1 fp64 bit36 */
			{39430,38,0}, /* core1 fp64 bit37 */
			{39426,38,0}, /* core1 fp64 bit38 */
			{39428,38,0}, /* core1 fp64 bit39 */
			{39394,38,0}, /* core1 fp64 bit40 */
			{39392,38,0}, /* core1 fp64 bit41 */
			{39424,38,0}, /* core1 fp64 bit42 */
			{39398,38,0}, /* core1 fp64 bit43 */
			{39402,38,0}, /* core1 fp64 bit44 */
			{39410,38,0}, /* core1 fp64 bit45 */
			{39396,38,0}, /* core1 fp64 bit46 */
			{39400,38,0}, /* core1 fp64 bit47 */
			{39408,38,0}, /* core1 fp64 bit48 */
			{46722,38,0}, /* core1 fp64 bit49 */
			{46720,38,0}, /* core1 fp64 bit50 */
			{46718,38,0}, /* core1 fp64 bit51 */
			{46708,38,0}, /* core1 fp64 bit52 */
			{46698,38,0}, /* core1 fp64 bit53 */
			{46696,38,0}, /* core1 fp64 bit54 */
			{46694,38,0}, /* core1 fp64 bit55 */
			{46692,38,0}, /* core1 fp64 bit56 */
			{46706,38,0}, /* core1 fp64 bit57 */
			{46704,38,0}, /* core1 fp64 bit58 */
			{46702,38,0}, /* core1 fp64 bit59 */
			{46700,38,0}, /* core1 fp64 bit60 */
			{32034,38,0}, /* core1 fp64 bit61 */
			{32042,38,0}, /* core1 fp64 bit62 */
			{32040,38,0}, /* core1 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{31878,38,0}, /* core1 sp_EL0 bit0 */
			{31882,38,0}, /* core1 sp_EL0 bit1 */
			{39692,38,0}, /* core1 sp_EL0 bit2 */
			{39816,38,0}, /* core1 sp_EL0 bit3 */
			{39652,38,0}, /* core1 sp_EL0 bit4 */
			{39654,38,0}, /* core1 sp_EL0 bit5 */
			{39658,38,0}, /* core1 sp_EL0 bit6 */
			{39656,38,0}, /* core1 sp_EL0 bit7 */
			{39686,38,0}, /* core1 sp_EL0 bit8 */
			{39684,38,0}, /* core1 sp_EL0 bit9 */
			{39688,38,0}, /* core1 sp_EL0 bit10 */
			{39690,38,0}, /* core1 sp_EL0 bit11 */
			{39822,38,0}, /* core1 sp_EL0 bit12 */
			{31850,38,0}, /* core1 sp_EL0 bit13 */
			{39820,38,0}, /* core1 sp_EL0 bit14 */
			{31848,38,0}, /* core1 sp_EL0 bit15 */
			{39698,38,0}, /* core1 sp_EL0 bit16 */
			{39824,38,0}, /* core1 sp_EL0 bit17 */
			{39830,38,0}, /* core1 sp_EL0 bit18 */
			{39828,38,0}, /* core1 sp_EL0 bit19 */
			{39826,38,0}, /* core1 sp_EL0 bit20 */
			{39696,38,0}, /* core1 sp_EL0 bit21 */
			{39702,38,0}, /* core1 sp_EL0 bit22 */
			{39806,38,0}, /* core1 sp_EL0 bit23 */
			{39804,38,0}, /* core1 sp_EL0 bit24 */
			{39700,38,0}, /* core1 sp_EL0 bit25 */
			{39808,38,0}, /* core1 sp_EL0 bit26 */
			{39810,38,0}, /* core1 sp_EL0 bit27 */
			{39814,38,0}, /* core1 sp_EL0 bit28 */
			{39812,38,0}, /* core1 sp_EL0 bit29 */
			{39694,38,0}, /* core1 sp_EL0 bit30 */
			{39818,38,0}, /* core1 sp_EL0 bit31 */
			{39446,38,0}, /* core1 sp_EL0 bit32 */
			{32134,38,0}, /* core1 sp_EL0 bit33 */
			{39444,38,0}, /* core1 sp_EL0 bit34 */
			{32136,38,0}, /* core1 sp_EL0 bit35 */
			{32132,38,0}, /* core1 sp_EL0 bit36 */
			{32128,38,0}, /* core1 sp_EL0 bit37 */
			{32130,38,0}, /* core1 sp_EL0 bit38 */
			{39390,38,0}, /* core1 sp_EL0 bit39 */
			{39388,38,0}, /* core1 sp_EL0 bit40 */
			{39004,38,0}, /* core1 sp_EL0 bit41 */
			{39002,38,0}, /* core1 sp_EL0 bit42 */
			{38960,38,0}, /* core1 sp_EL0 bit43 */
			{31934,38,0}, /* core1 sp_EL0 bit44 */
			{38958,38,0}, /* core1 sp_EL0 bit45 */
			{46754,38,0}, /* core1 sp_EL0 bit46 */
			{46752,38,0}, /* core1 sp_EL0 bit47 */
			{46750,38,0}, /* core1 sp_EL0 bit48 */
			{38964,38,0}, /* core1 sp_EL0 bit49 */
			{38962,38,0}, /* core1 sp_EL0 bit50 */
			{46748,38,0}, /* core1 sp_EL0 bit51 */
			{46738,38,0}, /* core1 sp_EL0 bit52 */
			{46730,38,0}, /* core1 sp_EL0 bit53 */
			{46736,38,0}, /* core1 sp_EL0 bit54 */
			{46728,38,0}, /* core1 sp_EL0 bit55 */
			{46726,38,0}, /* core1 sp_EL0 bit56 */
			{46724,38,0}, /* core1 sp_EL0 bit57 */
			{46746,38,0}, /* core1 sp_EL0 bit58 */
			{46734,38,0}, /* core1 sp_EL0 bit59 */
			{46732,38,0}, /* core1 sp_EL0 bit60 */
			{46744,38,0}, /* core1 sp_EL0 bit61 */
			{46742,38,0}, /* core1 sp_EL0 bit62 */
			{46740,38,0}, /* core1 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{31874,38,0}, /* core1 sp_EL1 bit0 */
			{39272,38,0}, /* core1 sp_EL1 bit1 */
			{31872,38,0}, /* core1 sp_EL1 bit2 */
			{39270,38,0}, /* core1 sp_EL1 bit3 */
			{39084,38,0}, /* core1 sp_EL1 bit4 */
			{39082,38,0}, /* core1 sp_EL1 bit5 */
			{39086,38,0}, /* core1 sp_EL1 bit6 */
			{39072,38,0}, /* core1 sp_EL1 bit7 */
			{39070,38,0}, /* core1 sp_EL1 bit8 */
			{39088,38,0}, /* core1 sp_EL1 bit9 */
			{39134,38,0}, /* core1 sp_EL1 bit10 */
			{39128,38,0}, /* core1 sp_EL1 bit11 */
			{39238,38,0}, /* core1 sp_EL1 bit12 */
			{39126,38,0}, /* core1 sp_EL1 bit13 */
			{39260,38,0}, /* core1 sp_EL1 bit14 */
			{39262,38,0}, /* core1 sp_EL1 bit15 */
			{39264,38,0}, /* core1 sp_EL1 bit16 */
			{39252,38,0}, /* core1 sp_EL1 bit17 */
			{31854,38,0}, /* core1 sp_EL1 bit18 */
			{39250,38,0}, /* core1 sp_EL1 bit19 */
			{39242,38,0}, /* core1 sp_EL1 bit20 */
			{39240,38,0}, /* core1 sp_EL1 bit21 */
			{39268,38,0}, /* core1 sp_EL1 bit22 */
			{39266,38,0}, /* core1 sp_EL1 bit23 */
			{39132,38,0}, /* core1 sp_EL1 bit24 */
			{39258,38,0}, /* core1 sp_EL1 bit25 */
			{39130,38,0}, /* core1 sp_EL1 bit26 */
			{39138,38,0}, /* core1 sp_EL1 bit27 */
			{39236,38,0}, /* core1 sp_EL1 bit28 */
			{39140,38,0}, /* core1 sp_EL1 bit29 */
			{39136,38,0}, /* core1 sp_EL1 bit30 */
			{31852,38,0}, /* core1 sp_EL1 bit31 */
			{39028,38,0}, /* core1 sp_EL1 bit32 */
			{32108,38,0}, /* core1 sp_EL1 bit33 */
			{39026,38,0}, /* core1 sp_EL1 bit34 */
			{39020,38,0}, /* core1 sp_EL1 bit35 */
			{32104,38,0}, /* core1 sp_EL1 bit36 */
			{39018,38,0}, /* core1 sp_EL1 bit37 */
			{32102,38,0}, /* core1 sp_EL1 bit38 */
			{39008,38,0}, /* core1 sp_EL1 bit39 */
			{39006,38,0}, /* core1 sp_EL1 bit40 */
			{39000,38,0}, /* core1 sp_EL1 bit41 */
			{38998,38,0}, /* core1 sp_EL1 bit42 */
			{38956,38,0}, /* core1 sp_EL1 bit43 */
			{31932,38,0}, /* core1 sp_EL1 bit44 */
			{38954,38,0}, /* core1 sp_EL1 bit45 */
			{38980,38,0}, /* core1 sp_EL1 bit46 */
			{38978,38,0}, /* core1 sp_EL1 bit47 */
			{46778,38,0}, /* core1 sp_EL1 bit48 */
			{46776,38,0}, /* core1 sp_EL1 bit49 */
			{46774,38,0}, /* core1 sp_EL1 bit50 */
			{46772,38,0}, /* core1 sp_EL1 bit51 */
			{46682,38,0}, /* core1 sp_EL1 bit52 */
			{46680,38,0}, /* core1 sp_EL1 bit53 */
			{46678,38,0}, /* core1 sp_EL1 bit54 */
			{46676,38,0}, /* core1 sp_EL1 bit55 */
			{46690,38,0}, /* core1 sp_EL1 bit56 */
			{46688,38,0}, /* core1 sp_EL1 bit57 */
			{46686,38,0}, /* core1 sp_EL1 bit58 */
			{46684,38,0}, /* core1 sp_EL1 bit59 */
			{46634,38,0}, /* core1 sp_EL1 bit60 */
			{46632,38,0}, /* core1 sp_EL1 bit61 */
			{46630,38,0}, /* core1 sp_EL1 bit62 */
			{46628,38,0}, /* core1 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{31870,38,0}, /* core1 sp_EL2 bit0 */
			{39094,38,0}, /* core1 sp_EL2 bit1 */
			{31868,38,0}, /* core1 sp_EL2 bit2 */
			{39234,38,0}, /* core1 sp_EL2 bit3 */
			{39080,38,0}, /* core1 sp_EL2 bit4 */
			{39078,38,0}, /* core1 sp_EL2 bit5 */
			{39076,38,0}, /* core1 sp_EL2 bit6 */
			{39074,38,0}, /* core1 sp_EL2 bit7 */
			{39092,38,0}, /* core1 sp_EL2 bit8 */
			{39090,38,0}, /* core1 sp_EL2 bit9 */
			{39232,38,0}, /* core1 sp_EL2 bit10 */
			{39158,38,0}, /* core1 sp_EL2 bit11 */
			{39146,38,0}, /* core1 sp_EL2 bit12 */
			{39254,38,0}, /* core1 sp_EL2 bit13 */
			{39276,38,0}, /* core1 sp_EL2 bit14 */
			{39256,38,0}, /* core1 sp_EL2 bit15 */
			{39274,38,0}, /* core1 sp_EL2 bit16 */
			{39248,38,0}, /* core1 sp_EL2 bit17 */
			{31858,38,0}, /* core1 sp_EL2 bit18 */
			{39144,38,0}, /* core1 sp_EL2 bit19 */
			{39142,38,0}, /* core1 sp_EL2 bit20 */
			{39166,38,0}, /* core1 sp_EL2 bit21 */
			{39096,38,0}, /* core1 sp_EL2 bit22 */
			{39164,38,0}, /* core1 sp_EL2 bit23 */
			{39162,38,0}, /* core1 sp_EL2 bit24 */
			{39230,38,0}, /* core1 sp_EL2 bit25 */
			{39228,38,0}, /* core1 sp_EL2 bit26 */
			{39156,38,0}, /* core1 sp_EL2 bit27 */
			{39154,38,0}, /* core1 sp_EL2 bit28 */
			{39160,38,0}, /* core1 sp_EL2 bit29 */
			{39152,38,0}, /* core1 sp_EL2 bit30 */
			{31866,38,0}, /* core1 sp_EL2 bit31 */
			{39040,38,0}, /* core1 sp_EL2 bit32 */
			{32148,38,0}, /* core1 sp_EL2 bit33 */
			{39038,38,0}, /* core1 sp_EL2 bit34 */
			{39032,38,0}, /* core1 sp_EL2 bit35 */
			{39030,38,0}, /* core1 sp_EL2 bit36 */
			{32106,38,0}, /* core1 sp_EL2 bit37 */
			{39024,38,0}, /* core1 sp_EL2 bit38 */
			{38988,38,0}, /* core1 sp_EL2 bit39 */
			{39022,38,0}, /* core1 sp_EL2 bit40 */
			{38996,38,0}, /* core1 sp_EL2 bit41 */
			{38994,38,0}, /* core1 sp_EL2 bit42 */
			{38986,38,0}, /* core1 sp_EL2 bit43 */
			{38984,38,0}, /* core1 sp_EL2 bit44 */
			{32074,38,0}, /* core1 sp_EL2 bit45 */
			{38982,38,0}, /* core1 sp_EL2 bit46 */
			{46770,38,0}, /* core1 sp_EL2 bit47 */
			{46762,38,0}, /* core1 sp_EL2 bit48 */
			{46768,38,0}, /* core1 sp_EL2 bit49 */
			{46760,38,0}, /* core1 sp_EL2 bit50 */
			{46758,38,0}, /* core1 sp_EL2 bit51 */
			{46756,38,0}, /* core1 sp_EL2 bit52 */
			{46650,38,0}, /* core1 sp_EL2 bit53 */
			{46648,38,0}, /* core1 sp_EL2 bit54 */
			{46646,38,0}, /* core1 sp_EL2 bit55 */
			{46644,38,0}, /* core1 sp_EL2 bit56 */
			{46642,38,0}, /* core1 sp_EL2 bit57 */
			{46640,38,0}, /* core1 sp_EL2 bit58 */
			{46638,38,0}, /* core1 sp_EL2 bit59 */
			{46636,38,0}, /* core1 sp_EL2 bit60 */
			{46766,38,0}, /* core1 sp_EL2 bit61 */
			{46764,38,0}, /* core1 sp_EL2 bit62 */
			{32070,38,0}, /* core1 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{31844,38,0}, /* core1 sp_EL3 bit0 */
			{31884,38,0}, /* core1 sp_EL3 bit1 */
			{39056,38,0}, /* core1 sp_EL3 bit2 */
			{39220,38,0}, /* core1 sp_EL3 bit3 */
			{39052,38,0}, /* core1 sp_EL3 bit4 */
			{39050,38,0}, /* core1 sp_EL3 bit5 */
			{39054,38,0}, /* core1 sp_EL3 bit6 */
			{39048,38,0}, /* core1 sp_EL3 bit7 */
			{39046,38,0}, /* core1 sp_EL3 bit8 */
			{39102,38,0}, /* core1 sp_EL3 bit9 */
			{39212,38,0}, /* core1 sp_EL3 bit10 */
			{39206,38,0}, /* core1 sp_EL3 bit11 */
			{39204,38,0}, /* core1 sp_EL3 bit12 */
			{39120,38,0}, /* core1 sp_EL3 bit13 */
			{39104,38,0}, /* core1 sp_EL3 bit14 */
			{39118,38,0}, /* core1 sp_EL3 bit15 */
			{39108,38,0}, /* core1 sp_EL3 bit16 */
			{31832,38,0}, /* core1 sp_EL3 bit17 */
			{39218,38,0}, /* core1 sp_EL3 bit18 */
			{39224,38,0}, /* core1 sp_EL3 bit19 */
			{39222,38,0}, /* core1 sp_EL3 bit20 */
			{39196,38,0}, /* core1 sp_EL3 bit21 */
			{39106,38,0}, /* core1 sp_EL3 bit22 */
			{39194,38,0}, /* core1 sp_EL3 bit23 */
			{39200,38,0}, /* core1 sp_EL3 bit24 */
			{39210,38,0}, /* core1 sp_EL3 bit25 */
			{39198,38,0}, /* core1 sp_EL3 bit26 */
			{39216,38,0}, /* core1 sp_EL3 bit27 */
			{39208,38,0}, /* core1 sp_EL3 bit28 */
			{39202,38,0}, /* core1 sp_EL3 bit29 */
			{39214,38,0}, /* core1 sp_EL3 bit30 */
			{31834,38,0}, /* core1 sp_EL3 bit31 */
			{39036,38,0}, /* core1 sp_EL3 bit32 */
			{32140,38,0}, /* core1 sp_EL3 bit33 */
			{39034,38,0}, /* core1 sp_EL3 bit34 */
			{32144,38,0}, /* core1 sp_EL3 bit35 */
			{32142,38,0}, /* core1 sp_EL3 bit36 */
			{32124,38,0}, /* core1 sp_EL3 bit37 */
			{32126,38,0}, /* core1 sp_EL3 bit38 */
			{32092,38,0}, /* core1 sp_EL3 bit39 */
			{32094,38,0}, /* core1 sp_EL3 bit40 */
			{32084,38,0}, /* core1 sp_EL3 bit41 */
			{38992,38,0}, /* core1 sp_EL3 bit42 */
			{31930,38,0}, /* core1 sp_EL3 bit43 */
			{38990,38,0}, /* core1 sp_EL3 bit44 */
			{32076,38,0}, /* core1 sp_EL3 bit45 */
			{38972,38,0}, /* core1 sp_EL3 bit46 */
			{38976,38,0}, /* core1 sp_EL3 bit47 */
			{38974,38,0}, /* core1 sp_EL3 bit48 */
			{46658,38,0}, /* core1 sp_EL3 bit49 */
			{46656,38,0}, /* core1 sp_EL3 bit50 */
			{46654,38,0}, /* core1 sp_EL3 bit51 */
			{46652,38,0}, /* core1 sp_EL3 bit52 */
			{46674,38,0}, /* core1 sp_EL3 bit53 */
			{46672,38,0}, /* core1 sp_EL3 bit54 */
			{46670,38,0}, /* core1 sp_EL3 bit55 */
			{46668,38,0}, /* core1 sp_EL3 bit56 */
			{46666,38,0}, /* core1 sp_EL3 bit57 */
			{46664,38,0}, /* core1 sp_EL3 bit58 */
			{46662,38,0}, /* core1 sp_EL3 bit59 */
			{38970,38,0}, /* core1 sp_EL3 bit60 */
			{46660,38,0}, /* core1 sp_EL3 bit61 */
			{38968,38,0}, /* core1 sp_EL3 bit62 */
			{38966,38,0}, /* core1 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{46886,38,0}, /* core1 elr_EL1 bit0 */
			{46884,38,0}, /* core1 elr_EL1 bit1 */
			{46888,38,0}, /* core1 elr_EL1 bit2 */
			{46954,38,0}, /* core1 elr_EL1 bit3 */
			{46890,38,0}, /* core1 elr_EL1 bit4 */
			{46882,38,0}, /* core1 elr_EL1 bit5 */
			{46880,38,0}, /* core1 elr_EL1 bit6 */
			{46874,38,0}, /* core1 elr_EL1 bit7 */
			{46872,38,0}, /* core1 elr_EL1 bit8 */
			{46870,38,0}, /* core1 elr_EL1 bit9 */
			{46952,38,0}, /* core1 elr_EL1 bit10 */
			{46950,38,0}, /* core1 elr_EL1 bit11 */
			{46914,38,0}, /* core1 elr_EL1 bit12 */
			{46948,38,0}, /* core1 elr_EL1 bit13 */
			{46878,38,0}, /* core1 elr_EL1 bit14 */
			{46904,38,0}, /* core1 elr_EL1 bit15 */
			{46868,38,0}, /* core1 elr_EL1 bit16 */
			{31856,38,0}, /* core1 elr_EL1 bit17 */
			{46958,38,0}, /* core1 elr_EL1 bit18 */
			{46956,38,0}, /* core1 elr_EL1 bit19 */
			{46906,38,0}, /* core1 elr_EL1 bit20 */
			{46946,38,0}, /* core1 elr_EL1 bit21 */
			{46876,38,0}, /* core1 elr_EL1 bit22 */
			{46912,38,0}, /* core1 elr_EL1 bit23 */
			{46910,38,0}, /* core1 elr_EL1 bit24 */
			{46908,38,0}, /* core1 elr_EL1 bit25 */
			{46944,38,0}, /* core1 elr_EL1 bit26 */
			{46942,38,0}, /* core1 elr_EL1 bit27 */
			{46940,38,0}, /* core1 elr_EL1 bit28 */
			{39246,38,0}, /* core1 elr_EL1 bit29 */
			{39244,38,0}, /* core1 elr_EL1 bit30 */
			{31864,38,0}, /* core1 elr_EL1 bit31 */
			{46612,38,0}, /* core1 elr_EL1 bit32 */
			{46850,38,0}, /* core1 elr_EL1 bit33 */
			{46848,38,0}, /* core1 elr_EL1 bit34 */
			{46846,38,0}, /* core1 elr_EL1 bit35 */
			{46844,38,0}, /* core1 elr_EL1 bit36 */
			{46834,38,0}, /* core1 elr_EL1 bit37 */
			{46832,38,0}, /* core1 elr_EL1 bit38 */
			{46830,38,0}, /* core1 elr_EL1 bit39 */
			{46828,38,0}, /* core1 elr_EL1 bit40 */
			{46818,38,0}, /* core1 elr_EL1 bit41 */
			{46816,38,0}, /* core1 elr_EL1 bit42 */
			{46814,38,0}, /* core1 elr_EL1 bit43 */
			{46812,38,0}, /* core1 elr_EL1 bit44 */
			{46802,38,0}, /* core1 elr_EL1 bit45 */
			{46800,38,0}, /* core1 elr_EL1 bit46 */
			{46798,38,0}, /* core1 elr_EL1 bit47 */
			{46796,38,0}, /* core1 elr_EL1 bit48 */
			{46602,38,0}, /* core1 elr_EL1 bit49 */
			{46594,38,0}, /* core1 elr_EL1 bit50 */
			{46600,38,0}, /* core1 elr_EL1 bit51 */
			{46598,38,0}, /* core1 elr_EL1 bit52 */
			{46592,38,0}, /* core1 elr_EL1 bit53 */
			{46590,38,0}, /* core1 elr_EL1 bit54 */
			{46596,38,0}, /* core1 elr_EL1 bit55 */
			{46588,38,0}, /* core1 elr_EL1 bit56 */
			{46618,38,0}, /* core1 elr_EL1 bit57 */
			{46610,38,0}, /* core1 elr_EL1 bit58 */
			{46608,38,0}, /* core1 elr_EL1 bit59 */
			{46606,38,0}, /* core1 elr_EL1 bit60 */
			{46604,38,0}, /* core1 elr_EL1 bit61 */
			{46616,38,0}, /* core1 elr_EL1 bit62 */
			{46614,38,0}, /* core1 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{46866,38,0}, /* core1 elr_EL2 bit0 */
			{46864,38,0}, /* core1 elr_EL2 bit1 */
			{46894,38,0}, /* core1 elr_EL2 bit2 */
			{46930,38,0}, /* core1 elr_EL2 bit3 */
			{46892,38,0}, /* core1 elr_EL2 bit4 */
			{46858,38,0}, /* core1 elr_EL2 bit5 */
			{46856,38,0}, /* core1 elr_EL2 bit6 */
			{46854,38,0}, /* core1 elr_EL2 bit7 */
			{46862,38,0}, /* core1 elr_EL2 bit8 */
			{46860,38,0}, /* core1 elr_EL2 bit9 */
			{46928,38,0}, /* core1 elr_EL2 bit10 */
			{46962,38,0}, /* core1 elr_EL2 bit11 */
			{46960,38,0}, /* core1 elr_EL2 bit12 */
			{46902,38,0}, /* core1 elr_EL2 bit13 */
			{46898,38,0}, /* core1 elr_EL2 bit14 */
			{46900,38,0}, /* core1 elr_EL2 bit15 */
			{46852,38,0}, /* core1 elr_EL2 bit16 */
			{31860,38,0}, /* core1 elr_EL2 bit17 */
			{46922,38,0}, /* core1 elr_EL2 bit18 */
			{46920,38,0}, /* core1 elr_EL2 bit19 */
			{46918,38,0}, /* core1 elr_EL2 bit20 */
			{46916,38,0}, /* core1 elr_EL2 bit21 */
			{46896,38,0}, /* core1 elr_EL2 bit22 */
			{39150,38,0}, /* core1 elr_EL2 bit23 */
			{46926,38,0}, /* core1 elr_EL2 bit24 */
			{46924,38,0}, /* core1 elr_EL2 bit25 */
			{46938,38,0}, /* core1 elr_EL2 bit26 */
			{39148,38,0}, /* core1 elr_EL2 bit27 */
			{46936,38,0}, /* core1 elr_EL2 bit28 */
			{46934,38,0}, /* core1 elr_EL2 bit29 */
			{46932,38,0}, /* core1 elr_EL2 bit30 */
			{31862,38,0}, /* core1 elr_EL2 bit31 */
			{46782,38,0}, /* core1 elr_EL2 bit32 */
			{46780,38,0}, /* core1 elr_EL2 bit33 */
			{46842,38,0}, /* core1 elr_EL2 bit34 */
			{46840,38,0}, /* core1 elr_EL2 bit35 */
			{46838,38,0}, /* core1 elr_EL2 bit36 */
			{46836,38,0}, /* core1 elr_EL2 bit37 */
			{46826,38,0}, /* core1 elr_EL2 bit38 */
			{46824,38,0}, /* core1 elr_EL2 bit39 */
			{46794,38,0}, /* core1 elr_EL2 bit40 */
			{46822,38,0}, /* core1 elr_EL2 bit41 */
			{46820,38,0}, /* core1 elr_EL2 bit42 */
			{46792,38,0}, /* core1 elr_EL2 bit43 */
			{46810,38,0}, /* core1 elr_EL2 bit44 */
			{46808,38,0}, /* core1 elr_EL2 bit45 */
			{46806,38,0}, /* core1 elr_EL2 bit46 */
			{46804,38,0}, /* core1 elr_EL2 bit47 */
			{46626,38,0}, /* core1 elr_EL2 bit48 */
			{46790,38,0}, /* core1 elr_EL2 bit49 */
			{46788,38,0}, /* core1 elr_EL2 bit50 */
			{46578,38,0}, /* core1 elr_EL2 bit51 */
			{46576,38,0}, /* core1 elr_EL2 bit52 */
			{46574,38,0}, /* core1 elr_EL2 bit53 */
			{46572,38,0}, /* core1 elr_EL2 bit54 */
			{46570,38,0}, /* core1 elr_EL2 bit55 */
			{46568,38,0}, /* core1 elr_EL2 bit56 */
			{46624,38,0}, /* core1 elr_EL2 bit57 */
			{46566,38,0}, /* core1 elr_EL2 bit58 */
			{46564,38,0}, /* core1 elr_EL2 bit59 */
			{46622,38,0}, /* core1 elr_EL2 bit60 */
			{46786,38,0}, /* core1 elr_EL2 bit61 */
			{46784,38,0}, /* core1 elr_EL2 bit62 */
			{46620,38,0}, /* core1 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{39064,38,0}, /* core1 elr_EL3 bit0 */
			{39062,38,0}, /* core1 elr_EL3 bit1 */
			{39100,38,0}, /* core1 elr_EL3 bit2 */
			{39188,38,0}, /* core1 elr_EL3 bit3 */
			{39068,38,0}, /* core1 elr_EL3 bit4 */
			{39066,38,0}, /* core1 elr_EL3 bit5 */
			{39098,38,0}, /* core1 elr_EL3 bit6 */
			{31880,38,0}, /* core1 elr_EL3 bit7 */
			{39060,38,0}, /* core1 elr_EL3 bit8 */
			{39058,38,0}, /* core1 elr_EL3 bit9 */
			{39172,38,0}, /* core1 elr_EL3 bit10 */
			{39186,38,0}, /* core1 elr_EL3 bit11 */
			{39168,38,0}, /* core1 elr_EL3 bit12 */
			{39226,38,0}, /* core1 elr_EL3 bit13 */
			{39112,38,0}, /* core1 elr_EL3 bit14 */
			{39124,38,0}, /* core1 elr_EL3 bit15 */
			{39110,38,0}, /* core1 elr_EL3 bit16 */
			{39116,38,0}, /* core1 elr_EL3 bit17 */
			{31830,38,0}, /* core1 elr_EL3 bit18 */
			{39122,38,0}, /* core1 elr_EL3 bit19 */
			{39170,38,0}, /* core1 elr_EL3 bit20 */
			{39192,38,0}, /* core1 elr_EL3 bit21 */
			{39114,38,0}, /* core1 elr_EL3 bit22 */
			{39190,38,0}, /* core1 elr_EL3 bit23 */
			{31828,38,0}, /* core1 elr_EL3 bit24 */
			{39184,38,0}, /* core1 elr_EL3 bit25 */
			{39182,38,0}, /* core1 elr_EL3 bit26 */
			{39176,38,0}, /* core1 elr_EL3 bit27 */
			{39174,38,0}, /* core1 elr_EL3 bit28 */
			{39180,38,0}, /* core1 elr_EL3 bit29 */
			{39178,38,0}, /* core1 elr_EL3 bit30 */
			{31846,38,0}, /* core1 elr_EL3 bit31 */
			{46078,38,0}, /* core1 elr_EL3 bit32 */
			{39044,38,0}, /* core1 elr_EL3 bit33 */
			{39042,38,0}, /* core1 elr_EL3 bit34 */
			{32156,38,0}, /* core1 elr_EL3 bit35 */
			{32154,38,0}, /* core1 elr_EL3 bit36 */
			{39016,38,0}, /* core1 elr_EL3 bit37 */
			{39014,38,0}, /* core1 elr_EL3 bit38 */
			{39012,38,0}, /* core1 elr_EL3 bit39 */
			{31902,38,0}, /* core1 elr_EL3 bit40 */
			{31920,38,0}, /* core1 elr_EL3 bit41 */
			{39010,38,0}, /* core1 elr_EL3 bit42 */
			{38948,38,0}, /* core1 elr_EL3 bit43 */
			{38952,38,0}, /* core1 elr_EL3 bit44 */
			{38950,38,0}, /* core1 elr_EL3 bit45 */
			{38946,38,0}, /* core1 elr_EL3 bit46 */
			{38944,38,0}, /* core1 elr_EL3 bit47 */
			{38942,38,0}, /* core1 elr_EL3 bit48 */
			{46538,38,0}, /* core1 elr_EL3 bit49 */
			{46586,38,0}, /* core1 elr_EL3 bit50 */
			{46584,38,0}, /* core1 elr_EL3 bit51 */
			{46536,38,0}, /* core1 elr_EL3 bit52 */
			{46534,38,0}, /* core1 elr_EL3 bit53 */
			{46532,38,0}, /* core1 elr_EL3 bit54 */
			{46530,38,0}, /* core1 elr_EL3 bit55 */
			{46528,38,0}, /* core1 elr_EL3 bit56 */
			{46582,38,0}, /* core1 elr_EL3 bit57 */
			{46526,38,0}, /* core1 elr_EL3 bit58 */
			{46524,38,0}, /* core1 elr_EL3 bit59 */
			{46084,38,0}, /* core1 elr_EL3 bit60 */
			{46082,38,0}, /* core1 elr_EL3 bit61 */
			{46080,38,0}, /* core1 elr_EL3 bit62 */
			{46580,38,0}, /* core1 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{44712,38,0}, /* core1 raw_pc bit0 */
			{19018,41,0}, /* core1 raw_pc bit1 */
			{19016,41,0}, /* core1 raw_pc bit2 */
			{19012,41,0}, /* core1 raw_pc bit3 */
			{19014,41,0}, /* core1 raw_pc bit4 */
			{44704,38,0}, /* core1 raw_pc bit5 */
			{44702,38,0}, /* core1 raw_pc bit6 */
			{19158,41,0}, /* core1 raw_pc bit7 */
			{19032,41,0}, /* core1 raw_pc bit8 */
			{19030,41,0}, /* core1 raw_pc bit9 */
			{19028,41,0}, /* core1 raw_pc bit10 */
			{19156,41,0}, /* core1 raw_pc bit11 */
			{19154,41,0}, /* core1 raw_pc bit12 */
			{19152,41,0}, /* core1 raw_pc bit13 */
			{19150,41,0}, /* core1 raw_pc bit14 */
			{19148,41,0}, /* core1 raw_pc bit15 */
			{19146,41,0}, /* core1 raw_pc bit16 */
			{19144,41,0}, /* core1 raw_pc bit17 */
			{19142,41,0}, /* core1 raw_pc bit18 */
			{19060,41,0}, /* core1 raw_pc bit19 */
			{19058,41,0}, /* core1 raw_pc bit20 */
			{19056,41,0}, /* core1 raw_pc bit21 */
			{19054,41,0}, /* core1 raw_pc bit22 */
			{19052,41,0}, /* core1 raw_pc bit23 */
			{19050,41,0}, /* core1 raw_pc bit24 */
			{19048,41,0}, /* core1 raw_pc bit25 */
			{19046,41,0}, /* core1 raw_pc bit26 */
			{19044,41,0}, /* core1 raw_pc bit27 */
			{19042,41,0}, /* core1 raw_pc bit28 */
			{19040,41,0}, /* core1 raw_pc bit29 */
			{19038,41,0}, /* core1 raw_pc bit30 */
			{19010,41,0}, /* core1 raw_pc bit31 */
			{19008,41,0}, /* core1 raw_pc bit32 */
			{19006,41,0}, /* core1 raw_pc bit33 */
			{19004,41,0}, /* core1 raw_pc bit34 */
			{19002,41,0}, /* core1 raw_pc bit35 */
			{19000,41,0}, /* core1 raw_pc bit36 */
			{18998,41,0}, /* core1 raw_pc bit37 */
			{18996,41,0}, /* core1 raw_pc bit38 */
			{18994,41,0}, /* core1 raw_pc bit39 */
			{18992,41,0}, /* core1 raw_pc bit40 */
			{18990,41,0}, /* core1 raw_pc bit41 */
			{18988,41,0}, /* core1 raw_pc bit42 */
			{18982,41,0}, /* core1 raw_pc bit43 */
			{18980,41,0}, /* core1 raw_pc bit44 */
			{18986,41,0}, /* core1 raw_pc bit45 */
			{18984,41,0}, /* core1 raw_pc bit46 */
			{44708,38,0}, /* core1 raw_pc bit47 */
			{44706,38,0}, /* core1 raw_pc bit48 */
			{36762,38,0}, /* core1 raw_pc bit49 */
			{    0, 0,2}, /* core1 raw_pc bit50 */
			{    0, 0,2}, /* core1 raw_pc bit51 */
			{    0, 0,2}, /* core1 raw_pc bit52 */
			{    0, 0,2}, /* core1 raw_pc bit53 */
			{    0, 0,2}, /* core1 raw_pc bit54 */
			{    0, 0,2}, /* core1 raw_pc bit55 */
			{    0, 0,2}, /* core1 raw_pc bit56 */
			{    0, 0,2}, /* core1 raw_pc bit57 */
			{    0, 0,2}, /* core1 raw_pc bit58 */
			{    0, 0,2}, /* core1 raw_pc bit59 */
			{    0, 0,2}, /* core1 raw_pc bit60 */
			{    0, 0,2}, /* core1 raw_pc bit61 */
			{    0, 0,2}, /* core1 raw_pc bit62 */
			{    0, 0,2}, /* core1 raw_pc bit63 */
			}},
			.pc_iss = {{
			{44752,38,0}, /* core1 pc_iss bit0 */
			{44760,38,0}, /* core1 pc_iss bit1 */
			{44758,38,0}, /* core1 pc_iss bit2 */
			{44764,38,0}, /* core1 pc_iss bit3 */
			{44762,38,0}, /* core1 pc_iss bit4 */
			{44750,38,0}, /* core1 pc_iss bit5 */
			{44756,38,0}, /* core1 pc_iss bit6 */
			{44754,38,0}, /* core1 pc_iss bit7 */
			{44768,38,0}, /* core1 pc_iss bit8 */
			{44766,38,0}, /* core1 pc_iss bit9 */
			{44746,38,0}, /* core1 pc_iss bit10 */
			{44744,38,0}, /* core1 pc_iss bit11 */
			{45102,38,0}, /* core1 pc_iss bit12 */
			{45100,38,0}, /* core1 pc_iss bit13 */
			{45098,38,0}, /* core1 pc_iss bit14 */
			{44748,38,0}, /* core1 pc_iss bit15 */
			{45096,38,0}, /* core1 pc_iss bit16 */
			{45090,38,0}, /* core1 pc_iss bit17 */
			{45088,38,0}, /* core1 pc_iss bit18 */
			{45082,38,0}, /* core1 pc_iss bit19 */
			{45080,38,0}, /* core1 pc_iss bit20 */
			{45086,38,0}, /* core1 pc_iss bit21 */
			{45084,38,0}, /* core1 pc_iss bit22 */
			{44782,38,0}, /* core1 pc_iss bit23 */
			{44780,38,0}, /* core1 pc_iss bit24 */
			{36740,38,0}, /* core1 pc_iss bit25 */
			{36738,38,0}, /* core1 pc_iss bit26 */
			{45094,38,0}, /* core1 pc_iss bit27 */
			{45092,38,0}, /* core1 pc_iss bit28 */
			{44742,38,0}, /* core1 pc_iss bit29 */
			{44740,38,0}, /* core1 pc_iss bit30 */
			{44778,38,0}, /* core1 pc_iss bit31 */
			{44700,38,0}, /* core1 pc_iss bit32 */
			{44698,38,0}, /* core1 pc_iss bit33 */
			{44696,38,0}, /* core1 pc_iss bit34 */
			{44694,38,0}, /* core1 pc_iss bit35 */
			{44680,38,0}, /* core1 pc_iss bit36 */
			{44678,38,0}, /* core1 pc_iss bit37 */
			{44692,38,0}, /* core1 pc_iss bit38 */
			{44688,38,0}, /* core1 pc_iss bit39 */
			{44686,38,0}, /* core1 pc_iss bit40 */
			{44684,38,0}, /* core1 pc_iss bit41 */
			{44682,38,0}, /* core1 pc_iss bit42 */
			{44690,38,0}, /* core1 pc_iss bit43 */
			{18930,41,0}, /* core1 pc_iss bit44 */
			{18928,41,0}, /* core1 pc_iss bit45 */
			{18926,41,0}, /* core1 pc_iss bit46 */
			{18924,41,0}, /* core1 pc_iss bit47 */
			{18922,41,0}, /* core1 pc_iss bit48 */
			{18920,41,0}, /* core1 pc_iss bit49 */
			{18918,41,0}, /* core1 pc_iss bit50 */
			{18880,41,0}, /* core1 pc_iss bit51 */
			{18904,41,0}, /* core1 pc_iss bit52 */
			{18902,41,0}, /* core1 pc_iss bit53 */
			{18916,41,0}, /* core1 pc_iss bit54 */
			{18914,41,0}, /* core1 pc_iss bit55 */
			{19026,41,0}, /* core1 pc_iss bit56 */
			{19020,41,0}, /* core1 pc_iss bit57 */
			{19036,41,0}, /* core1 pc_iss bit58 */
			{19034,41,0}, /* core1 pc_iss bit59 */
			{18900,41,0}, /* core1 pc_iss bit60 */
			{18898,41,0}, /* core1 pc_iss bit61 */
			{19024,41,0}, /* core1 pc_iss bit62 */
			{19022,41,0}, /* core1 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{44710,38,0}, /* core1 full_pc_wr bit0 */
			{    0, 0,2}, /* core1 full_pc_wr bit1 */
			{    0, 0,2}, /* core1 full_pc_wr bit2 */
			{    0, 0,2}, /* core1 full_pc_wr bit3 */
			{    0, 0,2}, /* core1 full_pc_wr bit4 */
			{    0, 0,2}, /* core1 full_pc_wr bit5 */
			{    0, 0,2}, /* core1 full_pc_wr bit6 */
			{    0, 0,2}, /* core1 full_pc_wr bit7 */
			{    0, 0,2}, /* core1 full_pc_wr bit8 */
			{    0, 0,2}, /* core1 full_pc_wr bit9 */
			{    0, 0,2}, /* core1 full_pc_wr bit10 */
			{    0, 0,2}, /* core1 full_pc_wr bit11 */
			{    0, 0,2}, /* core1 full_pc_wr bit12 */
			{    0, 0,2}, /* core1 full_pc_wr bit13 */
			{    0, 0,2}, /* core1 full_pc_wr bit14 */
			{    0, 0,2}, /* core1 full_pc_wr bit15 */
			{    0, 0,2}, /* core1 full_pc_wr bit16 */
			{    0, 0,2}, /* core1 full_pc_wr bit17 */
			{    0, 0,2}, /* core1 full_pc_wr bit18 */
			{    0, 0,2}, /* core1 full_pc_wr bit19 */
			{    0, 0,2}, /* core1 full_pc_wr bit20 */
			{    0, 0,2}, /* core1 full_pc_wr bit21 */
			{    0, 0,2}, /* core1 full_pc_wr bit22 */
			{    0, 0,2}, /* core1 full_pc_wr bit23 */
			{    0, 0,2}, /* core1 full_pc_wr bit24 */
			{    0, 0,2}, /* core1 full_pc_wr bit25 */
			{    0, 0,2}, /* core1 full_pc_wr bit26 */
			{    0, 0,2}, /* core1 full_pc_wr bit27 */
			{    0, 0,2}, /* core1 full_pc_wr bit28 */
			{    0, 0,2}, /* core1 full_pc_wr bit29 */
			{    0, 0,2}, /* core1 full_pc_wr bit30 */
			{    0, 0,2}, /* core1 full_pc_wr bit31 */
			{    0, 0,2}, /* core1 full_pc_wr bit32 */
			{    0, 0,2}, /* core1 full_pc_wr bit33 */
			{    0, 0,2}, /* core1 full_pc_wr bit34 */
			{    0, 0,2}, /* core1 full_pc_wr bit35 */
			{    0, 0,2}, /* core1 full_pc_wr bit36 */
			{    0, 0,2}, /* core1 full_pc_wr bit37 */
			{    0, 0,2}, /* core1 full_pc_wr bit38 */
			{    0, 0,2}, /* core1 full_pc_wr bit39 */
			{    0, 0,2}, /* core1 full_pc_wr bit40 */
			{    0, 0,2}, /* core1 full_pc_wr bit41 */
			{    0, 0,2}, /* core1 full_pc_wr bit42 */
			{    0, 0,2}, /* core1 full_pc_wr bit43 */
			{    0, 0,2}, /* core1 full_pc_wr bit44 */
			{    0, 0,2}, /* core1 full_pc_wr bit45 */
			{    0, 0,2}, /* core1 full_pc_wr bit46 */
			{    0, 0,2}, /* core1 full_pc_wr bit47 */
			{    0, 0,2}, /* core1 full_pc_wr bit48 */
			{    0, 0,2}, /* core1 full_pc_wr bit49 */
			{    0, 0,2}, /* core1 full_pc_wr bit50 */
			{    0, 0,2}, /* core1 full_pc_wr bit51 */
			{    0, 0,2}, /* core1 full_pc_wr bit52 */
			{    0, 0,2}, /* core1 full_pc_wr bit53 */
			{    0, 0,2}, /* core1 full_pc_wr bit54 */
			{    0, 0,2}, /* core1 full_pc_wr bit55 */
			{    0, 0,2}, /* core1 full_pc_wr bit56 */
			{    0, 0,2}, /* core1 full_pc_wr bit57 */
			{    0, 0,2}, /* core1 full_pc_wr bit58 */
			{    0, 0,2}, /* core1 full_pc_wr bit59 */
			{    0, 0,2}, /* core1 full_pc_wr bit60 */
			{    0, 0,2}, /* core1 full_pc_wr bit61 */
			{    0, 0,2}, /* core1 full_pc_wr bit62 */
			{    0, 0,2}, /* core1 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{37250,38,0}, /* core1 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core1 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{44772,38,0}, /* core1 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core1 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{ 7874,39,0}, /* core1 return_Stack_pointer bit0 */
			{ 7872,39,0}, /* core1 return_Stack_pointer bit1 */
			{ 7878,39,0}, /* core1 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core1 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{19482,39,0}, /* core1 return_Stack0 bit0 */
			{19480,39,0}, /* core1 return_Stack0 bit1 */
			{19478,39,0}, /* core1 return_Stack0 bit2 */
			{19476,39,0}, /* core1 return_Stack0 bit3 */
			{19266,39,0}, /* core1 return_Stack0 bit4 */
			{19264,39,0}, /* core1 return_Stack0 bit5 */
			{19262,39,0}, /* core1 return_Stack0 bit6 */
			{19260,39,0}, /* core1 return_Stack0 bit7 */
			{19274,39,0}, /* core1 return_Stack0 bit8 */
			{19272,39,0}, /* core1 return_Stack0 bit9 */
			{19270,39,0}, /* core1 return_Stack0 bit10 */
			{ 7838,39,0}, /* core1 return_Stack0 bit11 */
			{19268,39,0}, /* core1 return_Stack0 bit12 */
			{19250,39,0}, /* core1 return_Stack0 bit13 */
			{19248,39,0}, /* core1 return_Stack0 bit14 */
			{19246,39,0}, /* core1 return_Stack0 bit15 */
			{19244,39,0}, /* core1 return_Stack0 bit16 */
			{19442,39,0}, /* core1 return_Stack0 bit17 */
			{ 7836,39,0}, /* core1 return_Stack0 bit18 */
			{ 3022,39,0}, /* core1 return_Stack0 bit19 */
			{19440,39,0}, /* core1 return_Stack0 bit20 */
			{19438,39,0}, /* core1 return_Stack0 bit21 */
			{19436,39,0}, /* core1 return_Stack0 bit22 */
			{19426,39,0}, /* core1 return_Stack0 bit23 */
			{19424,39,0}, /* core1 return_Stack0 bit24 */
			{19422,39,0}, /* core1 return_Stack0 bit25 */
			{19420,39,0}, /* core1 return_Stack0 bit26 */
			{19434,39,0}, /* core1 return_Stack0 bit27 */
			{19432,39,0}, /* core1 return_Stack0 bit28 */
			{19430,39,0}, /* core1 return_Stack0 bit29 */
			{19428,39,0}, /* core1 return_Stack0 bit30 */
			{19394,39,0}, /* core1 return_Stack0 bit31 */
			{19392,39,0}, /* core1 return_Stack0 bit32 */
			{19390,39,0}, /* core1 return_Stack0 bit33 */
			{19388,39,0}, /* core1 return_Stack0 bit34 */
			{19378,39,0}, /* core1 return_Stack0 bit35 */
			{19376,39,0}, /* core1 return_Stack0 bit36 */
			{19374,39,0}, /* core1 return_Stack0 bit37 */
			{19372,39,0}, /* core1 return_Stack0 bit38 */
			{19362,39,0}, /* core1 return_Stack0 bit39 */
			{19360,39,0}, /* core1 return_Stack0 bit40 */
			{19358,39,0}, /* core1 return_Stack0 bit41 */
			{19356,39,0}, /* core1 return_Stack0 bit42 */
			{19498,39,0}, /* core1 return_Stack0 bit43 */
			{19496,39,0}, /* core1 return_Stack0 bit44 */
			{19494,39,0}, /* core1 return_Stack0 bit45 */
			{19492,39,0}, /* core1 return_Stack0 bit46 */
			{ 7846,39,0}, /* core1 return_Stack0 bit47 */
			{ 7844,39,0}, /* core1 return_Stack0 bit48 */
			{    0, 0,2}, /* core1 return_Stack0 bit49 */
			{    0, 0,2}, /* core1 return_Stack0 bit50 */
			{    0, 0,2}, /* core1 return_Stack0 bit51 */
			{    0, 0,2}, /* core1 return_Stack0 bit52 */
			{    0, 0,2}, /* core1 return_Stack0 bit53 */
			{    0, 0,2}, /* core1 return_Stack0 bit54 */
			{    0, 0,2}, /* core1 return_Stack0 bit55 */
			{    0, 0,2}, /* core1 return_Stack0 bit56 */
			{    0, 0,2}, /* core1 return_Stack0 bit57 */
			{    0, 0,2}, /* core1 return_Stack0 bit58 */
			{    0, 0,2}, /* core1 return_Stack0 bit59 */
			{    0, 0,2}, /* core1 return_Stack0 bit60 */
			{    0, 0,2}, /* core1 return_Stack0 bit61 */
			{    0, 0,2}, /* core1 return_Stack0 bit62 */
			{    0, 0,2}, /* core1 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{19490,39,0}, /* core1 return_Stack1 bit0 */
			{19488,39,0}, /* core1 return_Stack1 bit1 */
			{19486,39,0}, /* core1 return_Stack1 bit2 */
			{19484,39,0}, /* core1 return_Stack1 bit3 */
			{19242,39,0}, /* core1 return_Stack1 bit4 */
			{19240,39,0}, /* core1 return_Stack1 bit5 */
			{19466,39,0}, /* core1 return_Stack1 bit6 */
			{19238,39,0}, /* core1 return_Stack1 bit7 */
			{19236,39,0}, /* core1 return_Stack1 bit8 */
			{19258,39,0}, /* core1 return_Stack1 bit9 */
			{19256,39,0}, /* core1 return_Stack1 bit10 */
			{19464,39,0}, /* core1 return_Stack1 bit11 */
			{19254,39,0}, /* core1 return_Stack1 bit12 */
			{19252,39,0}, /* core1 return_Stack1 bit13 */
			{19474,39,0}, /* core1 return_Stack1 bit14 */
			{19472,39,0}, /* core1 return_Stack1 bit15 */
			{19470,39,0}, /* core1 return_Stack1 bit16 */
			{19468,39,0}, /* core1 return_Stack1 bit17 */
			{19462,39,0}, /* core1 return_Stack1 bit18 */
			{19460,39,0}, /* core1 return_Stack1 bit19 */
			{19410,39,0}, /* core1 return_Stack1 bit20 */
			{19408,39,0}, /* core1 return_Stack1 bit21 */
			{19406,39,0}, /* core1 return_Stack1 bit22 */
			{19404,39,0}, /* core1 return_Stack1 bit23 */
			{19418,39,0}, /* core1 return_Stack1 bit24 */
			{19416,39,0}, /* core1 return_Stack1 bit25 */
			{19414,39,0}, /* core1 return_Stack1 bit26 */
			{19412,39,0}, /* core1 return_Stack1 bit27 */
			{19402,39,0}, /* core1 return_Stack1 bit28 */
			{19400,39,0}, /* core1 return_Stack1 bit29 */
			{19398,39,0}, /* core1 return_Stack1 bit30 */
			{19396,39,0}, /* core1 return_Stack1 bit31 */
			{19386,39,0}, /* core1 return_Stack1 bit32 */
			{19384,39,0}, /* core1 return_Stack1 bit33 */
			{19382,39,0}, /* core1 return_Stack1 bit34 */
			{19380,39,0}, /* core1 return_Stack1 bit35 */
			{19370,39,0}, /* core1 return_Stack1 bit36 */
			{19368,39,0}, /* core1 return_Stack1 bit37 */
			{19366,39,0}, /* core1 return_Stack1 bit38 */
			{19364,39,0}, /* core1 return_Stack1 bit39 */
			{19354,39,0}, /* core1 return_Stack1 bit40 */
			{19346,39,0}, /* core1 return_Stack1 bit41 */
			{19344,39,0}, /* core1 return_Stack1 bit42 */
			{19352,39,0}, /* core1 return_Stack1 bit43 */
			{19350,39,0}, /* core1 return_Stack1 bit44 */
			{19342,39,0}, /* core1 return_Stack1 bit45 */
			{19348,39,0}, /* core1 return_Stack1 bit46 */
			{19340,39,0}, /* core1 return_Stack1 bit47 */
			{ 3024,39,0}, /* core1 return_Stack1 bit48 */
			{    0, 0,2}, /* core1 return_Stack1 bit49 */
			{    0, 0,2}, /* core1 return_Stack1 bit50 */
			{    0, 0,2}, /* core1 return_Stack1 bit51 */
			{    0, 0,2}, /* core1 return_Stack1 bit52 */
			{    0, 0,2}, /* core1 return_Stack1 bit53 */
			{    0, 0,2}, /* core1 return_Stack1 bit54 */
			{    0, 0,2}, /* core1 return_Stack1 bit55 */
			{    0, 0,2}, /* core1 return_Stack1 bit56 */
			{    0, 0,2}, /* core1 return_Stack1 bit57 */
			{    0, 0,2}, /* core1 return_Stack1 bit58 */
			{    0, 0,2}, /* core1 return_Stack1 bit59 */
			{    0, 0,2}, /* core1 return_Stack1 bit60 */
			{    0, 0,2}, /* core1 return_Stack1 bit61 */
			{    0, 0,2}, /* core1 return_Stack1 bit62 */
			{    0, 0,2}, /* core1 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{ 7850,39,0}, /* core1 return_Stack2 bit0 */
			{19282,39,0}, /* core1 return_Stack2 bit1 */
			{ 7848,39,0}, /* core1 return_Stack2 bit2 */
			{19280,39,0}, /* core1 return_Stack2 bit3 */
			{19278,39,0}, /* core1 return_Stack2 bit4 */
			{19234,39,0}, /* core1 return_Stack2 bit5 */
			{19276,39,0}, /* core1 return_Stack2 bit6 */
			{ 3028,39,0}, /* core1 return_Stack2 bit7 */
			{19232,39,0}, /* core1 return_Stack2 bit8 */
			{19230,39,0}, /* core1 return_Stack2 bit9 */
			{19218,39,0}, /* core1 return_Stack2 bit10 */
			{19228,39,0}, /* core1 return_Stack2 bit11 */
			{19216,39,0}, /* core1 return_Stack2 bit12 */
			{ 7834,39,0}, /* core1 return_Stack2 bit13 */
			{19214,39,0}, /* core1 return_Stack2 bit14 */
			{ 7832,39,0}, /* core1 return_Stack2 bit15 */
			{19212,39,0}, /* core1 return_Stack2 bit16 */
			{19202,39,0}, /* core1 return_Stack2 bit17 */
			{19200,39,0}, /* core1 return_Stack2 bit18 */
			{19198,39,0}, /* core1 return_Stack2 bit19 */
			{19196,39,0}, /* core1 return_Stack2 bit20 */
			{19178,39,0}, /* core1 return_Stack2 bit21 */
			{19176,39,0}, /* core1 return_Stack2 bit22 */
			{19174,39,0}, /* core1 return_Stack2 bit23 */
			{19172,39,0}, /* core1 return_Stack2 bit24 */
			{19170,39,0}, /* core1 return_Stack2 bit25 */
			{19168,39,0}, /* core1 return_Stack2 bit26 */
			{19166,39,0}, /* core1 return_Stack2 bit27 */
			{19164,39,0}, /* core1 return_Stack2 bit28 */
			{19138,39,0}, /* core1 return_Stack2 bit29 */
			{19136,39,0}, /* core1 return_Stack2 bit30 */
			{19134,39,0}, /* core1 return_Stack2 bit31 */
			{19132,39,0}, /* core1 return_Stack2 bit32 */
			{19538,39,0}, /* core1 return_Stack2 bit33 */
			{19536,39,0}, /* core1 return_Stack2 bit34 */
			{19534,39,0}, /* core1 return_Stack2 bit35 */
			{19532,39,0}, /* core1 return_Stack2 bit36 */
			{19522,39,0}, /* core1 return_Stack2 bit37 */
			{19520,39,0}, /* core1 return_Stack2 bit38 */
			{19518,39,0}, /* core1 return_Stack2 bit39 */
			{19516,39,0}, /* core1 return_Stack2 bit40 */
			{19514,39,0}, /* core1 return_Stack2 bit41 */
			{19512,39,0}, /* core1 return_Stack2 bit42 */
			{19510,39,0}, /* core1 return_Stack2 bit43 */
			{19508,39,0}, /* core1 return_Stack2 bit44 */
			{19338,39,0}, /* core1 return_Stack2 bit45 */
			{19336,39,0}, /* core1 return_Stack2 bit46 */
			{19334,39,0}, /* core1 return_Stack2 bit47 */
			{19332,39,0}, /* core1 return_Stack2 bit48 */
			{    0, 0,2}, /* core1 return_Stack2 bit49 */
			{    0, 0,2}, /* core1 return_Stack2 bit50 */
			{    0, 0,2}, /* core1 return_Stack2 bit51 */
			{    0, 0,2}, /* core1 return_Stack2 bit52 */
			{    0, 0,2}, /* core1 return_Stack2 bit53 */
			{    0, 0,2}, /* core1 return_Stack2 bit54 */
			{    0, 0,2}, /* core1 return_Stack2 bit55 */
			{    0, 0,2}, /* core1 return_Stack2 bit56 */
			{    0, 0,2}, /* core1 return_Stack2 bit57 */
			{    0, 0,2}, /* core1 return_Stack2 bit58 */
			{    0, 0,2}, /* core1 return_Stack2 bit59 */
			{    0, 0,2}, /* core1 return_Stack2 bit60 */
			{    0, 0,2}, /* core1 return_Stack2 bit61 */
			{    0, 0,2}, /* core1 return_Stack2 bit62 */
			{    0, 0,2}, /* core1 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{ 3030,39,0}, /* core1 return_Stack3 bit0 */
			{19322,39,0}, /* core1 return_Stack3 bit1 */
			{19320,39,0}, /* core1 return_Stack3 bit2 */
			{19318,39,0}, /* core1 return_Stack3 bit3 */
			{19316,39,0}, /* core1 return_Stack3 bit4 */
			{19290,39,0}, /* core1 return_Stack3 bit5 */
			{19288,39,0}, /* core1 return_Stack3 bit6 */
			{19286,39,0}, /* core1 return_Stack3 bit7 */
			{19284,39,0}, /* core1 return_Stack3 bit8 */
			{19226,39,0}, /* core1 return_Stack3 bit9 */
			{19224,39,0}, /* core1 return_Stack3 bit10 */
			{19222,39,0}, /* core1 return_Stack3 bit11 */
			{19220,39,0}, /* core1 return_Stack3 bit12 */
			{19210,39,0}, /* core1 return_Stack3 bit13 */
			{19208,39,0}, /* core1 return_Stack3 bit14 */
			{19206,39,0}, /* core1 return_Stack3 bit15 */
			{19204,39,0}, /* core1 return_Stack3 bit16 */
			{19194,39,0}, /* core1 return_Stack3 bit17 */
			{19192,39,0}, /* core1 return_Stack3 bit18 */
			{19190,39,0}, /* core1 return_Stack3 bit19 */
			{19188,39,0}, /* core1 return_Stack3 bit20 */
			{19186,39,0}, /* core1 return_Stack3 bit21 */
			{19184,39,0}, /* core1 return_Stack3 bit22 */
			{19182,39,0}, /* core1 return_Stack3 bit23 */
			{19180,39,0}, /* core1 return_Stack3 bit24 */
			{19162,39,0}, /* core1 return_Stack3 bit25 */
			{19160,39,0}, /* core1 return_Stack3 bit26 */
			{19158,39,0}, /* core1 return_Stack3 bit27 */
			{19156,39,0}, /* core1 return_Stack3 bit28 */
			{19130,39,0}, /* core1 return_Stack3 bit29 */
			{19128,39,0}, /* core1 return_Stack3 bit30 */
			{19126,39,0}, /* core1 return_Stack3 bit31 */
			{19124,39,0}, /* core1 return_Stack3 bit32 */
			{19546,39,0}, /* core1 return_Stack3 bit33 */
			{19544,39,0}, /* core1 return_Stack3 bit34 */
			{19542,39,0}, /* core1 return_Stack3 bit35 */
			{19540,39,0}, /* core1 return_Stack3 bit36 */
			{19530,39,0}, /* core1 return_Stack3 bit37 */
			{19528,39,0}, /* core1 return_Stack3 bit38 */
			{19526,39,0}, /* core1 return_Stack3 bit39 */
			{19524,39,0}, /* core1 return_Stack3 bit40 */
			{19506,39,0}, /* core1 return_Stack3 bit41 */
			{19504,39,0}, /* core1 return_Stack3 bit42 */
			{19502,39,0}, /* core1 return_Stack3 bit43 */
			{19500,39,0}, /* core1 return_Stack3 bit44 */
			{19330,39,0}, /* core1 return_Stack3 bit45 */
			{19328,39,0}, /* core1 return_Stack3 bit46 */
			{19326,39,0}, /* core1 return_Stack3 bit47 */
			{19324,39,0}, /* core1 return_Stack3 bit48 */
			{    0, 0,2}, /* core1 return_Stack3 bit49 */
			{    0, 0,2}, /* core1 return_Stack3 bit50 */
			{    0, 0,2}, /* core1 return_Stack3 bit51 */
			{    0, 0,2}, /* core1 return_Stack3 bit52 */
			{    0, 0,2}, /* core1 return_Stack3 bit53 */
			{    0, 0,2}, /* core1 return_Stack3 bit54 */
			{    0, 0,2}, /* core1 return_Stack3 bit55 */
			{    0, 0,2}, /* core1 return_Stack3 bit56 */
			{    0, 0,2}, /* core1 return_Stack3 bit57 */
			{    0, 0,2}, /* core1 return_Stack3 bit58 */
			{    0, 0,2}, /* core1 return_Stack3 bit59 */
			{    0, 0,2}, /* core1 return_Stack3 bit60 */
			{    0, 0,2}, /* core1 return_Stack3 bit61 */
			{    0, 0,2}, /* core1 return_Stack3 bit62 */
			{    0, 0,2}, /* core1 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{19314,39,0}, /* core1 return_Stack4 bit0 */
			{19312,39,0}, /* core1 return_Stack4 bit1 */
			{19310,39,0}, /* core1 return_Stack4 bit2 */
			{19308,39,0}, /* core1 return_Stack4 bit3 */
			{19306,39,0}, /* core1 return_Stack4 bit4 */
			{19304,39,0}, /* core1 return_Stack4 bit5 */
			{19302,39,0}, /* core1 return_Stack4 bit6 */
			{19300,39,0}, /* core1 return_Stack4 bit7 */
			{19298,39,0}, /* core1 return_Stack4 bit8 */
			{19296,39,0}, /* core1 return_Stack4 bit9 */
			{19294,39,0}, /* core1 return_Stack4 bit10 */
			{19292,39,0}, /* core1 return_Stack4 bit11 */
			{19458,39,0}, /* core1 return_Stack4 bit12 */
			{ 7842,39,0}, /* core1 return_Stack4 bit13 */
			{19456,39,0}, /* core1 return_Stack4 bit14 */
			{ 7840,39,0}, /* core1 return_Stack4 bit15 */
			{19454,39,0}, /* core1 return_Stack4 bit16 */
			{19452,39,0}, /* core1 return_Stack4 bit17 */
			{19450,39,0}, /* core1 return_Stack4 bit18 */
			{19448,39,0}, /* core1 return_Stack4 bit19 */
			{19446,39,0}, /* core1 return_Stack4 bit20 */
			{19444,39,0}, /* core1 return_Stack4 bit21 */
			{19146,39,0}, /* core1 return_Stack4 bit22 */
			{19144,39,0}, /* core1 return_Stack4 bit23 */
			{19142,39,0}, /* core1 return_Stack4 bit24 */
			{19140,39,0}, /* core1 return_Stack4 bit25 */
			{19154,39,0}, /* core1 return_Stack4 bit26 */
			{19152,39,0}, /* core1 return_Stack4 bit27 */
			{19150,39,0}, /* core1 return_Stack4 bit28 */
			{19148,39,0}, /* core1 return_Stack4 bit29 */
			{19122,39,0}, /* core1 return_Stack4 bit30 */
			{19120,39,0}, /* core1 return_Stack4 bit31 */
			{19118,39,0}, /* core1 return_Stack4 bit32 */
			{19116,39,0}, /* core1 return_Stack4 bit33 */
			{19114,39,0}, /* core1 return_Stack4 bit34 */
			{19112,39,0}, /* core1 return_Stack4 bit35 */
			{19110,39,0}, /* core1 return_Stack4 bit36 */
			{19108,39,0}, /* core1 return_Stack4 bit37 */
			{19046,39,0}, /* core1 return_Stack4 bit38 */
			{19044,39,0}, /* core1 return_Stack4 bit39 */
			{19042,39,0}, /* core1 return_Stack4 bit40 */
			{19040,39,0}, /* core1 return_Stack4 bit41 */
			{19054,39,0}, /* core1 return_Stack4 bit42 */
			{19052,39,0}, /* core1 return_Stack4 bit43 */
			{19050,39,0}, /* core1 return_Stack4 bit44 */
			{19048,39,0}, /* core1 return_Stack4 bit45 */
			{ 7854,39,0}, /* core1 return_Stack4 bit46 */
			{ 7852,39,0}, /* core1 return_Stack4 bit47 */
			{ 3026,39,0}, /* core1 return_Stack4 bit48 */
			{    0, 0,2}, /* core1 return_Stack4 bit49 */
			{    0, 0,2}, /* core1 return_Stack4 bit50 */
			{    0, 0,2}, /* core1 return_Stack4 bit51 */
			{    0, 0,2}, /* core1 return_Stack4 bit52 */
			{    0, 0,2}, /* core1 return_Stack4 bit53 */
			{    0, 0,2}, /* core1 return_Stack4 bit54 */
			{    0, 0,2}, /* core1 return_Stack4 bit55 */
			{    0, 0,2}, /* core1 return_Stack4 bit56 */
			{    0, 0,2}, /* core1 return_Stack4 bit57 */
			{    0, 0,2}, /* core1 return_Stack4 bit58 */
			{    0, 0,2}, /* core1 return_Stack4 bit59 */
			{    0, 0,2}, /* core1 return_Stack4 bit60 */
			{    0, 0,2}, /* core1 return_Stack4 bit61 */
			{    0, 0,2}, /* core1 return_Stack4 bit62 */
			{    0, 0,2}, /* core1 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{18982,39,0}, /* core1 return_Stack5 bit0 */
			{18980,39,0}, /* core1 return_Stack5 bit1 */
			{18978,39,0}, /* core1 return_Stack5 bit2 */
			{18976,39,0}, /* core1 return_Stack5 bit3 */
			{18958,39,0}, /* core1 return_Stack5 bit4 */
			{18942,39,0}, /* core1 return_Stack5 bit5 */
			{18956,39,0}, /* core1 return_Stack5 bit6 */
			{18954,39,0}, /* core1 return_Stack5 bit7 */
			{18952,39,0}, /* core1 return_Stack5 bit8 */
			{18940,39,0}, /* core1 return_Stack5 bit9 */
			{18938,39,0}, /* core1 return_Stack5 bit10 */
			{18936,39,0}, /* core1 return_Stack5 bit11 */
			{18918,39,0}, /* core1 return_Stack5 bit12 */
			{18916,39,0}, /* core1 return_Stack5 bit13 */
			{18914,39,0}, /* core1 return_Stack5 bit14 */
			{18912,39,0}, /* core1 return_Stack5 bit15 */
			{18886,39,0}, /* core1 return_Stack5 bit16 */
			{18884,39,0}, /* core1 return_Stack5 bit17 */
			{18882,39,0}, /* core1 return_Stack5 bit18 */
			{18880,39,0}, /* core1 return_Stack5 bit19 */
			{18838,39,0}, /* core1 return_Stack5 bit20 */
			{18836,39,0}, /* core1 return_Stack5 bit21 */
			{18834,39,0}, /* core1 return_Stack5 bit22 */
			{18832,39,0}, /* core1 return_Stack5 bit23 */
			{18830,39,0}, /* core1 return_Stack5 bit24 */
			{18828,39,0}, /* core1 return_Stack5 bit25 */
			{18826,39,0}, /* core1 return_Stack5 bit26 */
			{18824,39,0}, /* core1 return_Stack5 bit27 */
			{19014,39,0}, /* core1 return_Stack5 bit28 */
			{19012,39,0}, /* core1 return_Stack5 bit29 */
			{19010,39,0}, /* core1 return_Stack5 bit30 */
			{19008,39,0}, /* core1 return_Stack5 bit31 */
			{19022,39,0}, /* core1 return_Stack5 bit32 */
			{ 7894,39,0}, /* core1 return_Stack5 bit33 */
			{19020,39,0}, /* core1 return_Stack5 bit34 */
			{19018,39,0}, /* core1 return_Stack5 bit35 */
			{19016,39,0}, /* core1 return_Stack5 bit36 */
			{ 7892,39,0}, /* core1 return_Stack5 bit37 */
			{19086,39,0}, /* core1 return_Stack5 bit38 */
			{19084,39,0}, /* core1 return_Stack5 bit39 */
			{19082,39,0}, /* core1 return_Stack5 bit40 */
			{19080,39,0}, /* core1 return_Stack5 bit41 */
			{19062,39,0}, /* core1 return_Stack5 bit42 */
			{19060,39,0}, /* core1 return_Stack5 bit43 */
			{19058,39,0}, /* core1 return_Stack5 bit44 */
			{19056,39,0}, /* core1 return_Stack5 bit45 */
			{ 7862,39,0}, /* core1 return_Stack5 bit46 */
			{ 7860,39,0}, /* core1 return_Stack5 bit47 */
			{ 3034,39,0}, /* core1 return_Stack5 bit48 */
			{    0, 0,2}, /* core1 return_Stack5 bit49 */
			{    0, 0,2}, /* core1 return_Stack5 bit50 */
			{    0, 0,2}, /* core1 return_Stack5 bit51 */
			{    0, 0,2}, /* core1 return_Stack5 bit52 */
			{    0, 0,2}, /* core1 return_Stack5 bit53 */
			{    0, 0,2}, /* core1 return_Stack5 bit54 */
			{    0, 0,2}, /* core1 return_Stack5 bit55 */
			{    0, 0,2}, /* core1 return_Stack5 bit56 */
			{    0, 0,2}, /* core1 return_Stack5 bit57 */
			{    0, 0,2}, /* core1 return_Stack5 bit58 */
			{    0, 0,2}, /* core1 return_Stack5 bit59 */
			{    0, 0,2}, /* core1 return_Stack5 bit60 */
			{    0, 0,2}, /* core1 return_Stack5 bit61 */
			{    0, 0,2}, /* core1 return_Stack5 bit62 */
			{    0, 0,2}, /* core1 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{18990,39,0}, /* core1 return_Stack6 bit0 */
			{18988,39,0}, /* core1 return_Stack6 bit1 */
			{18986,39,0}, /* core1 return_Stack6 bit2 */
			{18984,39,0}, /* core1 return_Stack6 bit3 */
			{18950,39,0}, /* core1 return_Stack6 bit4 */
			{18926,39,0}, /* core1 return_Stack6 bit5 */
			{18948,39,0}, /* core1 return_Stack6 bit6 */
			{18946,39,0}, /* core1 return_Stack6 bit7 */
			{18944,39,0}, /* core1 return_Stack6 bit8 */
			{18924,39,0}, /* core1 return_Stack6 bit9 */
			{18922,39,0}, /* core1 return_Stack6 bit10 */
			{18920,39,0}, /* core1 return_Stack6 bit11 */
			{18902,39,0}, /* core1 return_Stack6 bit12 */
			{18900,39,0}, /* core1 return_Stack6 bit13 */
			{18898,39,0}, /* core1 return_Stack6 bit14 */
			{18896,39,0}, /* core1 return_Stack6 bit15 */
			{18894,39,0}, /* core1 return_Stack6 bit16 */
			{18892,39,0}, /* core1 return_Stack6 bit17 */
			{18890,39,0}, /* core1 return_Stack6 bit18 */
			{18888,39,0}, /* core1 return_Stack6 bit19 */
			{18862,39,0}, /* core1 return_Stack6 bit20 */
			{18860,39,0}, /* core1 return_Stack6 bit21 */
			{18858,39,0}, /* core1 return_Stack6 bit22 */
			{18856,39,0}, /* core1 return_Stack6 bit23 */
			{18846,39,0}, /* core1 return_Stack6 bit24 */
			{18844,39,0}, /* core1 return_Stack6 bit25 */
			{18842,39,0}, /* core1 return_Stack6 bit26 */
			{18840,39,0}, /* core1 return_Stack6 bit27 */
			{19006,39,0}, /* core1 return_Stack6 bit28 */
			{19004,39,0}, /* core1 return_Stack6 bit29 */
			{19002,39,0}, /* core1 return_Stack6 bit30 */
			{19000,39,0}, /* core1 return_Stack6 bit31 */
			{19030,39,0}, /* core1 return_Stack6 bit32 */
			{ 7886,39,0}, /* core1 return_Stack6 bit33 */
			{19028,39,0}, /* core1 return_Stack6 bit34 */
			{19026,39,0}, /* core1 return_Stack6 bit35 */
			{19024,39,0}, /* core1 return_Stack6 bit36 */
			{ 7884,39,0}, /* core1 return_Stack6 bit37 */
			{19102,39,0}, /* core1 return_Stack6 bit38 */
			{19100,39,0}, /* core1 return_Stack6 bit39 */
			{19098,39,0}, /* core1 return_Stack6 bit40 */
			{19096,39,0}, /* core1 return_Stack6 bit41 */
			{19070,39,0}, /* core1 return_Stack6 bit42 */
			{19068,39,0}, /* core1 return_Stack6 bit43 */
			{19066,39,0}, /* core1 return_Stack6 bit44 */
			{19064,39,0}, /* core1 return_Stack6 bit45 */
			{ 7866,39,0}, /* core1 return_Stack6 bit46 */
			{ 7864,39,0}, /* core1 return_Stack6 bit47 */
			{ 3036,39,0}, /* core1 return_Stack6 bit48 */
			{    0, 0,2}, /* core1 return_Stack6 bit49 */
			{    0, 0,2}, /* core1 return_Stack6 bit50 */
			{    0, 0,2}, /* core1 return_Stack6 bit51 */
			{    0, 0,2}, /* core1 return_Stack6 bit52 */
			{    0, 0,2}, /* core1 return_Stack6 bit53 */
			{    0, 0,2}, /* core1 return_Stack6 bit54 */
			{    0, 0,2}, /* core1 return_Stack6 bit55 */
			{    0, 0,2}, /* core1 return_Stack6 bit56 */
			{    0, 0,2}, /* core1 return_Stack6 bit57 */
			{    0, 0,2}, /* core1 return_Stack6 bit58 */
			{    0, 0,2}, /* core1 return_Stack6 bit59 */
			{    0, 0,2}, /* core1 return_Stack6 bit60 */
			{    0, 0,2}, /* core1 return_Stack6 bit61 */
			{    0, 0,2}, /* core1 return_Stack6 bit62 */
			{    0, 0,2}, /* core1 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{18974,39,0}, /* core1 return_Stack7 bit0 */
			{18972,39,0}, /* core1 return_Stack7 bit1 */
			{18970,39,0}, /* core1 return_Stack7 bit2 */
			{18968,39,0}, /* core1 return_Stack7 bit3 */
			{18966,39,0}, /* core1 return_Stack7 bit4 */
			{18934,39,0}, /* core1 return_Stack7 bit5 */
			{18964,39,0}, /* core1 return_Stack7 bit6 */
			{18962,39,0}, /* core1 return_Stack7 bit7 */
			{18960,39,0}, /* core1 return_Stack7 bit8 */
			{18932,39,0}, /* core1 return_Stack7 bit9 */
			{18930,39,0}, /* core1 return_Stack7 bit10 */
			{18928,39,0}, /* core1 return_Stack7 bit11 */
			{18910,39,0}, /* core1 return_Stack7 bit12 */
			{18908,39,0}, /* core1 return_Stack7 bit13 */
			{18906,39,0}, /* core1 return_Stack7 bit14 */
			{18904,39,0}, /* core1 return_Stack7 bit15 */
			{18878,39,0}, /* core1 return_Stack7 bit16 */
			{18876,39,0}, /* core1 return_Stack7 bit17 */
			{18874,39,0}, /* core1 return_Stack7 bit18 */
			{18872,39,0}, /* core1 return_Stack7 bit19 */
			{18870,39,0}, /* core1 return_Stack7 bit20 */
			{18868,39,0}, /* core1 return_Stack7 bit21 */
			{18866,39,0}, /* core1 return_Stack7 bit22 */
			{18864,39,0}, /* core1 return_Stack7 bit23 */
			{18854,39,0}, /* core1 return_Stack7 bit24 */
			{18852,39,0}, /* core1 return_Stack7 bit25 */
			{18850,39,0}, /* core1 return_Stack7 bit26 */
			{18848,39,0}, /* core1 return_Stack7 bit27 */
			{18998,39,0}, /* core1 return_Stack7 bit28 */
			{18996,39,0}, /* core1 return_Stack7 bit29 */
			{18994,39,0}, /* core1 return_Stack7 bit30 */
			{18992,39,0}, /* core1 return_Stack7 bit31 */
			{19038,39,0}, /* core1 return_Stack7 bit32 */
			{ 7890,39,0}, /* core1 return_Stack7 bit33 */
			{19036,39,0}, /* core1 return_Stack7 bit34 */
			{19034,39,0}, /* core1 return_Stack7 bit35 */
			{19032,39,0}, /* core1 return_Stack7 bit36 */
			{ 7888,39,0}, /* core1 return_Stack7 bit37 */
			{19094,39,0}, /* core1 return_Stack7 bit38 */
			{19092,39,0}, /* core1 return_Stack7 bit39 */
			{19090,39,0}, /* core1 return_Stack7 bit40 */
			{19088,39,0}, /* core1 return_Stack7 bit41 */
			{19078,39,0}, /* core1 return_Stack7 bit42 */
			{19076,39,0}, /* core1 return_Stack7 bit43 */
			{19074,39,0}, /* core1 return_Stack7 bit44 */
			{19072,39,0}, /* core1 return_Stack7 bit45 */
			{ 7858,39,0}, /* core1 return_Stack7 bit46 */
			{ 7856,39,0}, /* core1 return_Stack7 bit47 */
			{ 3032,39,0}, /* core1 return_Stack7 bit48 */
			{    0, 0,2}, /* core1 return_Stack7 bit49 */
			{    0, 0,2}, /* core1 return_Stack7 bit50 */
			{    0, 0,2}, /* core1 return_Stack7 bit51 */
			{    0, 0,2}, /* core1 return_Stack7 bit52 */
			{    0, 0,2}, /* core1 return_Stack7 bit53 */
			{    0, 0,2}, /* core1 return_Stack7 bit54 */
			{    0, 0,2}, /* core1 return_Stack7 bit55 */
			{    0, 0,2}, /* core1 return_Stack7 bit56 */
			{    0, 0,2}, /* core1 return_Stack7 bit57 */
			{    0, 0,2}, /* core1 return_Stack7 bit58 */
			{    0, 0,2}, /* core1 return_Stack7 bit59 */
			{    0, 0,2}, /* core1 return_Stack7 bit60 */
			{    0, 0,2}, /* core1 return_Stack7 bit61 */
			{    0, 0,2}, /* core1 return_Stack7 bit62 */
			{    0, 0,2}, /* core1 return_Stack7 bit63 */
			}},
	},
	{		/* core 2 */ 
			.pc = {{
			{ 2688,42,1}, /* core2 pc bit0 */
			{ 2686,42,1}, /* core2 pc bit1 */
			{ 2684,42,1}, /* core2 pc bit2 */
			{ 2682,42,1}, /* core2 pc bit3 */
			{ 2592,42,1}, /* core2 pc bit4 */
			{ 2590,42,1}, /* core2 pc bit5 */
			{ 2588,42,1}, /* core2 pc bit6 */
			{ 2586,42,1}, /* core2 pc bit7 */
			{ 2584,42,1}, /* core2 pc bit8 */
			{ 2582,42,1}, /* core2 pc bit9 */
			{ 2580,42,1}, /* core2 pc bit10 */
			{ 2578,42,1}, /* core2 pc bit11 */
			{ 2600,42,1}, /* core2 pc bit12 */
			{ 2598,42,1}, /* core2 pc bit13 */
			{ 2596,42,1}, /* core2 pc bit14 */
			{ 2594,42,1}, /* core2 pc bit15 */
			{ 2448,42,1}, /* core2 pc bit16 */
			{ 2446,42,1}, /* core2 pc bit17 */
			{ 2444,42,1}, /* core2 pc bit18 */
			{ 2442,42,1}, /* core2 pc bit19 */
			{ 2432,42,1}, /* core2 pc bit20 */
			{ 2430,42,1}, /* core2 pc bit21 */
			{ 2428,42,1}, /* core2 pc bit22 */
			{ 2426,42,1}, /* core2 pc bit23 */
			{ 2352,42,1}, /* core2 pc bit24 */
			{ 2350,42,1}, /* core2 pc bit25 */
			{ 2348,42,1}, /* core2 pc bit26 */
			{ 2346,42,1}, /* core2 pc bit27 */
			{ 2344,42,1}, /* core2 pc bit28 */
			{ 2342,42,1}, /* core2 pc bit29 */
			{ 2340,42,1}, /* core2 pc bit30 */
			{ 2338,42,1}, /* core2 pc bit31 */
			{ 2656,42,1}, /* core2 pc bit32 */
			{ 2654,42,1}, /* core2 pc bit33 */
			{ 2652,42,1}, /* core2 pc bit34 */
			{ 2650,42,1}, /* core2 pc bit35 */
			{ 2616,42,1}, /* core2 pc bit36 */
			{ 2614,42,1}, /* core2 pc bit37 */
			{ 2612,42,1}, /* core2 pc bit38 */
			{ 2610,42,1}, /* core2 pc bit39 */
			{ 2632,42,1}, /* core2 pc bit40 */
			{ 2630,42,1}, /* core2 pc bit41 */
			{  676,42,1}, /* core2 pc bit42 */
			{ 2628,42,1}, /* core2 pc bit43 */
			{ 2626,42,1}, /* core2 pc bit44 */
			{ 2608,42,1}, /* core2 pc bit45 */
			{ 2606,42,1}, /* core2 pc bit46 */
			{ 2604,42,1}, /* core2 pc bit47 */
			{ 2602,42,1}, /* core2 pc bit48 */
			{ 2400,42,1}, /* core2 pc bit49 */
			{ 2398,42,1}, /* core2 pc bit50 */
			{ 2396,42,1}, /* core2 pc bit51 */
			{ 2394,42,1}, /* core2 pc bit52 */
			{ 2312,42,1}, /* core2 pc bit53 */
			{ 2310,42,1}, /* core2 pc bit54 */
			{ 2308,42,1}, /* core2 pc bit55 */
			{ 2306,42,1}, /* core2 pc bit56 */
			{ 2164,42,1}, /* core2 pc bit57 */
			{ 2162,42,1}, /* core2 pc bit58 */
			{ 2160,42,1}, /* core2 pc bit59 */
			{ 2158,42,1}, /* core2 pc bit60 */
			{  682,42,1}, /* core2 pc bit61 */
			{  680,42,1}, /* core2 pc bit62 */
			{ 2228,42,1}, /* core2 pc bit63 */
			}},
			.sp32 = {{
			{32298,42,0}, /* core2 sp32 bit0 */
			{40686,42,0}, /* core2 sp32 bit1 */
			{32308,42,0}, /* core2 sp32 bit2 */
			{40522,42,0}, /* core2 sp32 bit3 */
			{40684,42,0}, /* core2 sp32 bit4 */
			{40682,42,0}, /* core2 sp32 bit5 */
			{40680,42,0}, /* core2 sp32 bit6 */
			{40690,42,0}, /* core2 sp32 bit7 */
			{40688,42,0}, /* core2 sp32 bit8 */
			{40654,42,0}, /* core2 sp32 bit9 */
			{40520,42,0}, /* core2 sp32 bit10 */
			{40526,42,0}, /* core2 sp32 bit11 */
			{40524,42,0}, /* core2 sp32 bit12 */
			{40646,42,0}, /* core2 sp32 bit13 */
			{40652,42,0}, /* core2 sp32 bit14 */
			{40644,42,0}, /* core2 sp32 bit15 */
			{40642,42,0}, /* core2 sp32 bit16 */
			{40640,42,0}, /* core2 sp32 bit17 */
			{32264,42,0}, /* core2 sp32 bit18 */
			{40614,42,0}, /* core2 sp32 bit19 */
			{40612,42,0}, /* core2 sp32 bit20 */
			{40510,42,0}, /* core2 sp32 bit21 */
			{32260,42,0}, /* core2 sp32 bit22 */
			{40508,42,0}, /* core2 sp32 bit23 */
			{40490,42,0}, /* core2 sp32 bit24 */
			{40488,42,0}, /* core2 sp32 bit25 */
			{40564,42,0}, /* core2 sp32 bit26 */
			{40562,42,0}, /* core2 sp32 bit27 */
			{40560,42,0}, /* core2 sp32 bit28 */
			{40566,42,0}, /* core2 sp32 bit29 */
			{32258,42,0}, /* core2 sp32 bit30 */
			{32256,42,0}, /* core2 sp32 bit31 */
			{40362,42,0}, /* core2 sp32 bit32 */
			{40360,42,0}, /* core2 sp32 bit33 */
			{40354,42,0}, /* core2 sp32 bit34 */
			{40352,42,0}, /* core2 sp32 bit35 */
			{40358,42,0}, /* core2 sp32 bit36 */
			{40356,42,0}, /* core2 sp32 bit37 */
			{31992,42,0}, /* core2 sp32 bit38 */
			{40350,42,0}, /* core2 sp32 bit39 */
			{40348,42,0}, /* core2 sp32 bit40 */
			{40322,42,0}, /* core2 sp32 bit41 */
			{40320,42,0}, /* core2 sp32 bit42 */
			{32028,42,0}, /* core2 sp32 bit43 */
			{40318,42,0}, /* core2 sp32 bit44 */
			{32030,42,0}, /* core2 sp32 bit45 */
			{40316,42,0}, /* core2 sp32 bit46 */
			{32032,42,0}, /* core2 sp32 bit47 */
			{47404,42,0}, /* core2 sp32 bit48 */
			{47402,42,0}, /* core2 sp32 bit49 */
			{47400,42,0}, /* core2 sp32 bit50 */
			{47398,42,0}, /* core2 sp32 bit51 */
			{47332,42,0}, /* core2 sp32 bit52 */
			{47330,42,0}, /* core2 sp32 bit53 */
			{47328,42,0}, /* core2 sp32 bit54 */
			{47326,42,0}, /* core2 sp32 bit55 */
			{47340,42,0}, /* core2 sp32 bit56 */
			{47338,42,0}, /* core2 sp32 bit57 */
			{47336,42,0}, /* core2 sp32 bit58 */
			{47334,42,0}, /* core2 sp32 bit59 */
			{47348,42,0}, /* core2 sp32 bit60 */
			{47346,42,0}, /* core2 sp32 bit61 */
			{47344,42,0}, /* core2 sp32 bit62 */
			{47342,42,0}, /* core2 sp32 bit63 */
			}},
			.fp32 = {{
			{32654,42,0}, /* core2 fp32 bit0 */
			{32322,42,0}, /* core2 fp32 bit1 */
			{40906,42,0}, /* core2 fp32 bit2 */
			{40900,42,0}, /* core2 fp32 bit3 */
			{40976,42,0}, /* core2 fp32 bit4 */
			{40974,42,0}, /* core2 fp32 bit5 */
			{40972,42,0}, /* core2 fp32 bit6 */
			{32646,42,0}, /* core2 fp32 bit7 */
			{40970,42,0}, /* core2 fp32 bit8 */
			{32320,42,0}, /* core2 fp32 bit9 */
			{40896,42,0}, /* core2 fp32 bit10 */
			{40904,42,0}, /* core2 fp32 bit11 */
			{40898,42,0}, /* core2 fp32 bit12 */
			{32390,42,0}, /* core2 fp32 bit13 */
			{40908,42,0}, /* core2 fp32 bit14 */
			{40902,42,0}, /* core2 fp32 bit15 */
			{40920,42,0}, /* core2 fp32 bit16 */
			{40918,42,0}, /* core2 fp32 bit17 */
			{32418,42,0}, /* core2 fp32 bit18 */
			{32386,42,0}, /* core2 fp32 bit19 */
			{40894,42,0}, /* core2 fp32 bit20 */
			{32348,42,0}, /* core2 fp32 bit21 */
			{32412,42,0}, /* core2 fp32 bit22 */
			{32334,42,0}, /* core2 fp32 bit23 */
			{32336,42,0}, /* core2 fp32 bit24 */
			{32342,42,0}, /* core2 fp32 bit25 */
			{40916,42,0}, /* core2 fp32 bit26 */
			{40914,42,0}, /* core2 fp32 bit27 */
			{32388,42,0}, /* core2 fp32 bit28 */
			{40924,42,0}, /* core2 fp32 bit29 */
			{40922,42,0}, /* core2 fp32 bit30 */
			{32424,42,0}, /* core2 fp32 bit31 */
			{41026,42,0}, /* core2 fp32 bit32 */
			{32578,42,0}, /* core2 fp32 bit33 */
			{41036,42,0}, /* core2 fp32 bit34 */
			{41022,42,0}, /* core2 fp32 bit35 */
			{41024,42,0}, /* core2 fp32 bit36 */
			{41028,42,0}, /* core2 fp32 bit37 */
			{32580,42,0}, /* core2 fp32 bit38 */
			{32582,42,0}, /* core2 fp32 bit39 */
			{41032,42,0}, /* core2 fp32 bit40 */
			{41030,42,0}, /* core2 fp32 bit41 */
			{41040,42,0}, /* core2 fp32 bit42 */
			{32552,42,0}, /* core2 fp32 bit43 */
			{41038,42,0}, /* core2 fp32 bit44 */
			{40992,42,0}, /* core2 fp32 bit45 */
			{41034,42,0}, /* core2 fp32 bit46 */
			{40990,42,0}, /* core2 fp32 bit47 */
			{32614,42,0}, /* core2 fp32 bit48 */
			{41064,42,0}, /* core2 fp32 bit49 */
			{47526,42,0}, /* core2 fp32 bit50 */
			{47524,42,0}, /* core2 fp32 bit51 */
			{47520,42,0}, /* core2 fp32 bit52 */
			{47430,42,0}, /* core2 fp32 bit53 */
			{47428,42,0}, /* core2 fp32 bit54 */
			{47426,42,0}, /* core2 fp32 bit55 */
			{47422,42,0}, /* core2 fp32 bit56 */
			{47424,42,0}, /* core2 fp32 bit57 */
			{47420,42,0}, /* core2 fp32 bit58 */
			{41062,42,0}, /* core2 fp32 bit59 */
			{47418,42,0}, /* core2 fp32 bit60 */
			{47416,42,0}, /* core2 fp32 bit61 */
			{32634,42,0}, /* core2 fp32 bit62 */
			{47518,42,0}, /* core2 fp32 bit63 */
			}},
			.fp64 = {{
			{32172,42,0}, /* core2 fp64 bit0 */
			{31886,42,0}, /* core2 fp64 bit1 */
			{39704,42,0}, /* core2 fp64 bit2 */
			{39782,42,0}, /* core2 fp64 bit3 */
			{32160,42,0}, /* core2 fp64 bit4 */
			{39662,42,0}, /* core2 fp64 bit5 */
			{39650,42,0}, /* core2 fp64 bit6 */
			{39648,42,0}, /* core2 fp64 bit7 */
			{39682,42,0}, /* core2 fp64 bit8 */
			{39660,42,0}, /* core2 fp64 bit9 */
			{31822,42,0}, /* core2 fp64 bit10 */
			{31824,42,0}, /* core2 fp64 bit11 */
			{31818,42,0}, /* core2 fp64 bit12 */
			{32222,42,0}, /* core2 fp64 bit13 */
			{39680,42,0}, /* core2 fp64 bit14 */
			{32224,42,0}, /* core2 fp64 bit15 */
			{39722,42,0}, /* core2 fp64 bit16 */
			{39720,42,0}, /* core2 fp64 bit17 */
			{39778,42,0}, /* core2 fp64 bit18 */
			{39786,42,0}, /* core2 fp64 bit19 */
			{39780,42,0}, /* core2 fp64 bit20 */
			{39784,42,0}, /* core2 fp64 bit21 */
			{39706,42,0}, /* core2 fp64 bit22 */
			{39770,42,0}, /* core2 fp64 bit23 */
			{39768,42,0}, /* core2 fp64 bit24 */
			{39742,42,0}, /* core2 fp64 bit25 */
			{39776,42,0}, /* core2 fp64 bit26 */
			{39740,42,0}, /* core2 fp64 bit27 */
			{31826,42,0}, /* core2 fp64 bit28 */
			{39774,42,0}, /* core2 fp64 bit29 */
			{39772,42,0}, /* core2 fp64 bit30 */
			{31836,42,0}, /* core2 fp64 bit31 */
			{31976,42,0}, /* core2 fp64 bit32 */
			{31974,42,0}, /* core2 fp64 bit33 */
			{31972,42,0}, /* core2 fp64 bit34 */
			{39436,42,0}, /* core2 fp64 bit35 */
			{39438,42,0}, /* core2 fp64 bit36 */
			{39430,42,0}, /* core2 fp64 bit37 */
			{39426,42,0}, /* core2 fp64 bit38 */
			{39428,42,0}, /* core2 fp64 bit39 */
			{39394,42,0}, /* core2 fp64 bit40 */
			{39392,42,0}, /* core2 fp64 bit41 */
			{39424,42,0}, /* core2 fp64 bit42 */
			{39398,42,0}, /* core2 fp64 bit43 */
			{39402,42,0}, /* core2 fp64 bit44 */
			{39410,42,0}, /* core2 fp64 bit45 */
			{39396,42,0}, /* core2 fp64 bit46 */
			{39400,42,0}, /* core2 fp64 bit47 */
			{39408,42,0}, /* core2 fp64 bit48 */
			{46722,42,0}, /* core2 fp64 bit49 */
			{46720,42,0}, /* core2 fp64 bit50 */
			{46718,42,0}, /* core2 fp64 bit51 */
			{46708,42,0}, /* core2 fp64 bit52 */
			{46698,42,0}, /* core2 fp64 bit53 */
			{46696,42,0}, /* core2 fp64 bit54 */
			{46694,42,0}, /* core2 fp64 bit55 */
			{46692,42,0}, /* core2 fp64 bit56 */
			{46706,42,0}, /* core2 fp64 bit57 */
			{46704,42,0}, /* core2 fp64 bit58 */
			{46702,42,0}, /* core2 fp64 bit59 */
			{46700,42,0}, /* core2 fp64 bit60 */
			{32034,42,0}, /* core2 fp64 bit61 */
			{32042,42,0}, /* core2 fp64 bit62 */
			{32040,42,0}, /* core2 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{31878,42,0}, /* core2 sp_EL0 bit0 */
			{31882,42,0}, /* core2 sp_EL0 bit1 */
			{39692,42,0}, /* core2 sp_EL0 bit2 */
			{39816,42,0}, /* core2 sp_EL0 bit3 */
			{39652,42,0}, /* core2 sp_EL0 bit4 */
			{39654,42,0}, /* core2 sp_EL0 bit5 */
			{39658,42,0}, /* core2 sp_EL0 bit6 */
			{39656,42,0}, /* core2 sp_EL0 bit7 */
			{39686,42,0}, /* core2 sp_EL0 bit8 */
			{39684,42,0}, /* core2 sp_EL0 bit9 */
			{39688,42,0}, /* core2 sp_EL0 bit10 */
			{39690,42,0}, /* core2 sp_EL0 bit11 */
			{39822,42,0}, /* core2 sp_EL0 bit12 */
			{31850,42,0}, /* core2 sp_EL0 bit13 */
			{39820,42,0}, /* core2 sp_EL0 bit14 */
			{31848,42,0}, /* core2 sp_EL0 bit15 */
			{39698,42,0}, /* core2 sp_EL0 bit16 */
			{39824,42,0}, /* core2 sp_EL0 bit17 */
			{39830,42,0}, /* core2 sp_EL0 bit18 */
			{39828,42,0}, /* core2 sp_EL0 bit19 */
			{39826,42,0}, /* core2 sp_EL0 bit20 */
			{39696,42,0}, /* core2 sp_EL0 bit21 */
			{39702,42,0}, /* core2 sp_EL0 bit22 */
			{39806,42,0}, /* core2 sp_EL0 bit23 */
			{39804,42,0}, /* core2 sp_EL0 bit24 */
			{39700,42,0}, /* core2 sp_EL0 bit25 */
			{39808,42,0}, /* core2 sp_EL0 bit26 */
			{39810,42,0}, /* core2 sp_EL0 bit27 */
			{39814,42,0}, /* core2 sp_EL0 bit28 */
			{39812,42,0}, /* core2 sp_EL0 bit29 */
			{39694,42,0}, /* core2 sp_EL0 bit30 */
			{39818,42,0}, /* core2 sp_EL0 bit31 */
			{39446,42,0}, /* core2 sp_EL0 bit32 */
			{32134,42,0}, /* core2 sp_EL0 bit33 */
			{39444,42,0}, /* core2 sp_EL0 bit34 */
			{32136,42,0}, /* core2 sp_EL0 bit35 */
			{32132,42,0}, /* core2 sp_EL0 bit36 */
			{32128,42,0}, /* core2 sp_EL0 bit37 */
			{32130,42,0}, /* core2 sp_EL0 bit38 */
			{39390,42,0}, /* core2 sp_EL0 bit39 */
			{39388,42,0}, /* core2 sp_EL0 bit40 */
			{39004,42,0}, /* core2 sp_EL0 bit41 */
			{39002,42,0}, /* core2 sp_EL0 bit42 */
			{38960,42,0}, /* core2 sp_EL0 bit43 */
			{31934,42,0}, /* core2 sp_EL0 bit44 */
			{38958,42,0}, /* core2 sp_EL0 bit45 */
			{46754,42,0}, /* core2 sp_EL0 bit46 */
			{46752,42,0}, /* core2 sp_EL0 bit47 */
			{46750,42,0}, /* core2 sp_EL0 bit48 */
			{38964,42,0}, /* core2 sp_EL0 bit49 */
			{38962,42,0}, /* core2 sp_EL0 bit50 */
			{46748,42,0}, /* core2 sp_EL0 bit51 */
			{46738,42,0}, /* core2 sp_EL0 bit52 */
			{46730,42,0}, /* core2 sp_EL0 bit53 */
			{46736,42,0}, /* core2 sp_EL0 bit54 */
			{46728,42,0}, /* core2 sp_EL0 bit55 */
			{46726,42,0}, /* core2 sp_EL0 bit56 */
			{46724,42,0}, /* core2 sp_EL0 bit57 */
			{46746,42,0}, /* core2 sp_EL0 bit58 */
			{46734,42,0}, /* core2 sp_EL0 bit59 */
			{46732,42,0}, /* core2 sp_EL0 bit60 */
			{46744,42,0}, /* core2 sp_EL0 bit61 */
			{46742,42,0}, /* core2 sp_EL0 bit62 */
			{46740,42,0}, /* core2 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{31874,42,0}, /* core2 sp_EL1 bit0 */
			{39272,42,0}, /* core2 sp_EL1 bit1 */
			{31872,42,0}, /* core2 sp_EL1 bit2 */
			{39270,42,0}, /* core2 sp_EL1 bit3 */
			{39084,42,0}, /* core2 sp_EL1 bit4 */
			{39082,42,0}, /* core2 sp_EL1 bit5 */
			{39086,42,0}, /* core2 sp_EL1 bit6 */
			{39072,42,0}, /* core2 sp_EL1 bit7 */
			{39070,42,0}, /* core2 sp_EL1 bit8 */
			{39088,42,0}, /* core2 sp_EL1 bit9 */
			{39134,42,0}, /* core2 sp_EL1 bit10 */
			{39128,42,0}, /* core2 sp_EL1 bit11 */
			{39238,42,0}, /* core2 sp_EL1 bit12 */
			{39126,42,0}, /* core2 sp_EL1 bit13 */
			{39260,42,0}, /* core2 sp_EL1 bit14 */
			{39262,42,0}, /* core2 sp_EL1 bit15 */
			{39264,42,0}, /* core2 sp_EL1 bit16 */
			{39252,42,0}, /* core2 sp_EL1 bit17 */
			{31854,42,0}, /* core2 sp_EL1 bit18 */
			{39250,42,0}, /* core2 sp_EL1 bit19 */
			{39242,42,0}, /* core2 sp_EL1 bit20 */
			{39240,42,0}, /* core2 sp_EL1 bit21 */
			{39268,42,0}, /* core2 sp_EL1 bit22 */
			{39266,42,0}, /* core2 sp_EL1 bit23 */
			{39132,42,0}, /* core2 sp_EL1 bit24 */
			{39258,42,0}, /* core2 sp_EL1 bit25 */
			{39130,42,0}, /* core2 sp_EL1 bit26 */
			{39138,42,0}, /* core2 sp_EL1 bit27 */
			{39236,42,0}, /* core2 sp_EL1 bit28 */
			{39140,42,0}, /* core2 sp_EL1 bit29 */
			{39136,42,0}, /* core2 sp_EL1 bit30 */
			{31852,42,0}, /* core2 sp_EL1 bit31 */
			{39028,42,0}, /* core2 sp_EL1 bit32 */
			{32108,42,0}, /* core2 sp_EL1 bit33 */
			{39026,42,0}, /* core2 sp_EL1 bit34 */
			{39020,42,0}, /* core2 sp_EL1 bit35 */
			{32104,42,0}, /* core2 sp_EL1 bit36 */
			{39018,42,0}, /* core2 sp_EL1 bit37 */
			{32102,42,0}, /* core2 sp_EL1 bit38 */
			{39008,42,0}, /* core2 sp_EL1 bit39 */
			{39006,42,0}, /* core2 sp_EL1 bit40 */
			{39000,42,0}, /* core2 sp_EL1 bit41 */
			{38998,42,0}, /* core2 sp_EL1 bit42 */
			{38956,42,0}, /* core2 sp_EL1 bit43 */
			{31932,42,0}, /* core2 sp_EL1 bit44 */
			{38954,42,0}, /* core2 sp_EL1 bit45 */
			{38980,42,0}, /* core2 sp_EL1 bit46 */
			{38978,42,0}, /* core2 sp_EL1 bit47 */
			{46778,42,0}, /* core2 sp_EL1 bit48 */
			{46776,42,0}, /* core2 sp_EL1 bit49 */
			{46774,42,0}, /* core2 sp_EL1 bit50 */
			{46772,42,0}, /* core2 sp_EL1 bit51 */
			{46682,42,0}, /* core2 sp_EL1 bit52 */
			{46680,42,0}, /* core2 sp_EL1 bit53 */
			{46678,42,0}, /* core2 sp_EL1 bit54 */
			{46676,42,0}, /* core2 sp_EL1 bit55 */
			{46690,42,0}, /* core2 sp_EL1 bit56 */
			{46688,42,0}, /* core2 sp_EL1 bit57 */
			{46686,42,0}, /* core2 sp_EL1 bit58 */
			{46684,42,0}, /* core2 sp_EL1 bit59 */
			{46634,42,0}, /* core2 sp_EL1 bit60 */
			{46632,42,0}, /* core2 sp_EL1 bit61 */
			{46630,42,0}, /* core2 sp_EL1 bit62 */
			{46628,42,0}, /* core2 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{31870,42,0}, /* core2 sp_EL2 bit0 */
			{39094,42,0}, /* core2 sp_EL2 bit1 */
			{31868,42,0}, /* core2 sp_EL2 bit2 */
			{39234,42,0}, /* core2 sp_EL2 bit3 */
			{39080,42,0}, /* core2 sp_EL2 bit4 */
			{39078,42,0}, /* core2 sp_EL2 bit5 */
			{39076,42,0}, /* core2 sp_EL2 bit6 */
			{39074,42,0}, /* core2 sp_EL2 bit7 */
			{39092,42,0}, /* core2 sp_EL2 bit8 */
			{39090,42,0}, /* core2 sp_EL2 bit9 */
			{39232,42,0}, /* core2 sp_EL2 bit10 */
			{39158,42,0}, /* core2 sp_EL2 bit11 */
			{39146,42,0}, /* core2 sp_EL2 bit12 */
			{39254,42,0}, /* core2 sp_EL2 bit13 */
			{39276,42,0}, /* core2 sp_EL2 bit14 */
			{39256,42,0}, /* core2 sp_EL2 bit15 */
			{39274,42,0}, /* core2 sp_EL2 bit16 */
			{39248,42,0}, /* core2 sp_EL2 bit17 */
			{31858,42,0}, /* core2 sp_EL2 bit18 */
			{39144,42,0}, /* core2 sp_EL2 bit19 */
			{39142,42,0}, /* core2 sp_EL2 bit20 */
			{39166,42,0}, /* core2 sp_EL2 bit21 */
			{39096,42,0}, /* core2 sp_EL2 bit22 */
			{39164,42,0}, /* core2 sp_EL2 bit23 */
			{39162,42,0}, /* core2 sp_EL2 bit24 */
			{39230,42,0}, /* core2 sp_EL2 bit25 */
			{39228,42,0}, /* core2 sp_EL2 bit26 */
			{39156,42,0}, /* core2 sp_EL2 bit27 */
			{39154,42,0}, /* core2 sp_EL2 bit28 */
			{39160,42,0}, /* core2 sp_EL2 bit29 */
			{39152,42,0}, /* core2 sp_EL2 bit30 */
			{31866,42,0}, /* core2 sp_EL2 bit31 */
			{39040,42,0}, /* core2 sp_EL2 bit32 */
			{32148,42,0}, /* core2 sp_EL2 bit33 */
			{39038,42,0}, /* core2 sp_EL2 bit34 */
			{39032,42,0}, /* core2 sp_EL2 bit35 */
			{39030,42,0}, /* core2 sp_EL2 bit36 */
			{32106,42,0}, /* core2 sp_EL2 bit37 */
			{39024,42,0}, /* core2 sp_EL2 bit38 */
			{38988,42,0}, /* core2 sp_EL2 bit39 */
			{39022,42,0}, /* core2 sp_EL2 bit40 */
			{38996,42,0}, /* core2 sp_EL2 bit41 */
			{38994,42,0}, /* core2 sp_EL2 bit42 */
			{38986,42,0}, /* core2 sp_EL2 bit43 */
			{38984,42,0}, /* core2 sp_EL2 bit44 */
			{32074,42,0}, /* core2 sp_EL2 bit45 */
			{38982,42,0}, /* core2 sp_EL2 bit46 */
			{46770,42,0}, /* core2 sp_EL2 bit47 */
			{46762,42,0}, /* core2 sp_EL2 bit48 */
			{46768,42,0}, /* core2 sp_EL2 bit49 */
			{46760,42,0}, /* core2 sp_EL2 bit50 */
			{46758,42,0}, /* core2 sp_EL2 bit51 */
			{46756,42,0}, /* core2 sp_EL2 bit52 */
			{46650,42,0}, /* core2 sp_EL2 bit53 */
			{46648,42,0}, /* core2 sp_EL2 bit54 */
			{46646,42,0}, /* core2 sp_EL2 bit55 */
			{46644,42,0}, /* core2 sp_EL2 bit56 */
			{46642,42,0}, /* core2 sp_EL2 bit57 */
			{46640,42,0}, /* core2 sp_EL2 bit58 */
			{46638,42,0}, /* core2 sp_EL2 bit59 */
			{46636,42,0}, /* core2 sp_EL2 bit60 */
			{46766,42,0}, /* core2 sp_EL2 bit61 */
			{46764,42,0}, /* core2 sp_EL2 bit62 */
			{32070,42,0}, /* core2 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{31844,42,0}, /* core2 sp_EL3 bit0 */
			{31884,42,0}, /* core2 sp_EL3 bit1 */
			{39056,42,0}, /* core2 sp_EL3 bit2 */
			{39220,42,0}, /* core2 sp_EL3 bit3 */
			{39052,42,0}, /* core2 sp_EL3 bit4 */
			{39050,42,0}, /* core2 sp_EL3 bit5 */
			{39054,42,0}, /* core2 sp_EL3 bit6 */
			{39048,42,0}, /* core2 sp_EL3 bit7 */
			{39046,42,0}, /* core2 sp_EL3 bit8 */
			{39102,42,0}, /* core2 sp_EL3 bit9 */
			{39212,42,0}, /* core2 sp_EL3 bit10 */
			{39206,42,0}, /* core2 sp_EL3 bit11 */
			{39204,42,0}, /* core2 sp_EL3 bit12 */
			{39120,42,0}, /* core2 sp_EL3 bit13 */
			{39104,42,0}, /* core2 sp_EL3 bit14 */
			{39118,42,0}, /* core2 sp_EL3 bit15 */
			{39108,42,0}, /* core2 sp_EL3 bit16 */
			{31832,42,0}, /* core2 sp_EL3 bit17 */
			{39218,42,0}, /* core2 sp_EL3 bit18 */
			{39224,42,0}, /* core2 sp_EL3 bit19 */
			{39222,42,0}, /* core2 sp_EL3 bit20 */
			{39196,42,0}, /* core2 sp_EL3 bit21 */
			{39106,42,0}, /* core2 sp_EL3 bit22 */
			{39194,42,0}, /* core2 sp_EL3 bit23 */
			{39200,42,0}, /* core2 sp_EL3 bit24 */
			{39210,42,0}, /* core2 sp_EL3 bit25 */
			{39198,42,0}, /* core2 sp_EL3 bit26 */
			{39216,42,0}, /* core2 sp_EL3 bit27 */
			{39208,42,0}, /* core2 sp_EL3 bit28 */
			{39202,42,0}, /* core2 sp_EL3 bit29 */
			{39214,42,0}, /* core2 sp_EL3 bit30 */
			{31834,42,0}, /* core2 sp_EL3 bit31 */
			{39036,42,0}, /* core2 sp_EL3 bit32 */
			{32140,42,0}, /* core2 sp_EL3 bit33 */
			{39034,42,0}, /* core2 sp_EL3 bit34 */
			{32144,42,0}, /* core2 sp_EL3 bit35 */
			{32142,42,0}, /* core2 sp_EL3 bit36 */
			{32124,42,0}, /* core2 sp_EL3 bit37 */
			{32126,42,0}, /* core2 sp_EL3 bit38 */
			{32092,42,0}, /* core2 sp_EL3 bit39 */
			{32094,42,0}, /* core2 sp_EL3 bit40 */
			{32084,42,0}, /* core2 sp_EL3 bit41 */
			{38992,42,0}, /* core2 sp_EL3 bit42 */
			{31930,42,0}, /* core2 sp_EL3 bit43 */
			{38990,42,0}, /* core2 sp_EL3 bit44 */
			{32076,42,0}, /* core2 sp_EL3 bit45 */
			{38972,42,0}, /* core2 sp_EL3 bit46 */
			{38976,42,0}, /* core2 sp_EL3 bit47 */
			{38974,42,0}, /* core2 sp_EL3 bit48 */
			{46658,42,0}, /* core2 sp_EL3 bit49 */
			{46656,42,0}, /* core2 sp_EL3 bit50 */
			{46654,42,0}, /* core2 sp_EL3 bit51 */
			{46652,42,0}, /* core2 sp_EL3 bit52 */
			{46674,42,0}, /* core2 sp_EL3 bit53 */
			{46672,42,0}, /* core2 sp_EL3 bit54 */
			{46670,42,0}, /* core2 sp_EL3 bit55 */
			{46668,42,0}, /* core2 sp_EL3 bit56 */
			{46666,42,0}, /* core2 sp_EL3 bit57 */
			{46664,42,0}, /* core2 sp_EL3 bit58 */
			{46662,42,0}, /* core2 sp_EL3 bit59 */
			{38970,42,0}, /* core2 sp_EL3 bit60 */
			{46660,42,0}, /* core2 sp_EL3 bit61 */
			{38968,42,0}, /* core2 sp_EL3 bit62 */
			{38966,42,0}, /* core2 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{46886,42,0}, /* core2 elr_EL1 bit0 */
			{46884,42,0}, /* core2 elr_EL1 bit1 */
			{46888,42,0}, /* core2 elr_EL1 bit2 */
			{46954,42,0}, /* core2 elr_EL1 bit3 */
			{46890,42,0}, /* core2 elr_EL1 bit4 */
			{46882,42,0}, /* core2 elr_EL1 bit5 */
			{46880,42,0}, /* core2 elr_EL1 bit6 */
			{46874,42,0}, /* core2 elr_EL1 bit7 */
			{46872,42,0}, /* core2 elr_EL1 bit8 */
			{46870,42,0}, /* core2 elr_EL1 bit9 */
			{46952,42,0}, /* core2 elr_EL1 bit10 */
			{46950,42,0}, /* core2 elr_EL1 bit11 */
			{46914,42,0}, /* core2 elr_EL1 bit12 */
			{46948,42,0}, /* core2 elr_EL1 bit13 */
			{46878,42,0}, /* core2 elr_EL1 bit14 */
			{46904,42,0}, /* core2 elr_EL1 bit15 */
			{46868,42,0}, /* core2 elr_EL1 bit16 */
			{31856,42,0}, /* core2 elr_EL1 bit17 */
			{46958,42,0}, /* core2 elr_EL1 bit18 */
			{46956,42,0}, /* core2 elr_EL1 bit19 */
			{46906,42,0}, /* core2 elr_EL1 bit20 */
			{46946,42,0}, /* core2 elr_EL1 bit21 */
			{46876,42,0}, /* core2 elr_EL1 bit22 */
			{46912,42,0}, /* core2 elr_EL1 bit23 */
			{46910,42,0}, /* core2 elr_EL1 bit24 */
			{46908,42,0}, /* core2 elr_EL1 bit25 */
			{46944,42,0}, /* core2 elr_EL1 bit26 */
			{46942,42,0}, /* core2 elr_EL1 bit27 */
			{46940,42,0}, /* core2 elr_EL1 bit28 */
			{39246,42,0}, /* core2 elr_EL1 bit29 */
			{39244,42,0}, /* core2 elr_EL1 bit30 */
			{31864,42,0}, /* core2 elr_EL1 bit31 */
			{46612,42,0}, /* core2 elr_EL1 bit32 */
			{46850,42,0}, /* core2 elr_EL1 bit33 */
			{46848,42,0}, /* core2 elr_EL1 bit34 */
			{46846,42,0}, /* core2 elr_EL1 bit35 */
			{46844,42,0}, /* core2 elr_EL1 bit36 */
			{46834,42,0}, /* core2 elr_EL1 bit37 */
			{46832,42,0}, /* core2 elr_EL1 bit38 */
			{46830,42,0}, /* core2 elr_EL1 bit39 */
			{46828,42,0}, /* core2 elr_EL1 bit40 */
			{46818,42,0}, /* core2 elr_EL1 bit41 */
			{46816,42,0}, /* core2 elr_EL1 bit42 */
			{46814,42,0}, /* core2 elr_EL1 bit43 */
			{46812,42,0}, /* core2 elr_EL1 bit44 */
			{46802,42,0}, /* core2 elr_EL1 bit45 */
			{46800,42,0}, /* core2 elr_EL1 bit46 */
			{46798,42,0}, /* core2 elr_EL1 bit47 */
			{46796,42,0}, /* core2 elr_EL1 bit48 */
			{46602,42,0}, /* core2 elr_EL1 bit49 */
			{46594,42,0}, /* core2 elr_EL1 bit50 */
			{46600,42,0}, /* core2 elr_EL1 bit51 */
			{46598,42,0}, /* core2 elr_EL1 bit52 */
			{46592,42,0}, /* core2 elr_EL1 bit53 */
			{46590,42,0}, /* core2 elr_EL1 bit54 */
			{46596,42,0}, /* core2 elr_EL1 bit55 */
			{46588,42,0}, /* core2 elr_EL1 bit56 */
			{46618,42,0}, /* core2 elr_EL1 bit57 */
			{46610,42,0}, /* core2 elr_EL1 bit58 */
			{46608,42,0}, /* core2 elr_EL1 bit59 */
			{46606,42,0}, /* core2 elr_EL1 bit60 */
			{46604,42,0}, /* core2 elr_EL1 bit61 */
			{46616,42,0}, /* core2 elr_EL1 bit62 */
			{46614,42,0}, /* core2 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{46866,42,0}, /* core2 elr_EL2 bit0 */
			{46864,42,0}, /* core2 elr_EL2 bit1 */
			{46894,42,0}, /* core2 elr_EL2 bit2 */
			{46930,42,0}, /* core2 elr_EL2 bit3 */
			{46892,42,0}, /* core2 elr_EL2 bit4 */
			{46858,42,0}, /* core2 elr_EL2 bit5 */
			{46856,42,0}, /* core2 elr_EL2 bit6 */
			{46854,42,0}, /* core2 elr_EL2 bit7 */
			{46862,42,0}, /* core2 elr_EL2 bit8 */
			{46860,42,0}, /* core2 elr_EL2 bit9 */
			{46928,42,0}, /* core2 elr_EL2 bit10 */
			{46962,42,0}, /* core2 elr_EL2 bit11 */
			{46960,42,0}, /* core2 elr_EL2 bit12 */
			{46902,42,0}, /* core2 elr_EL2 bit13 */
			{46898,42,0}, /* core2 elr_EL2 bit14 */
			{46900,42,0}, /* core2 elr_EL2 bit15 */
			{46852,42,0}, /* core2 elr_EL2 bit16 */
			{31860,42,0}, /* core2 elr_EL2 bit17 */
			{46922,42,0}, /* core2 elr_EL2 bit18 */
			{46920,42,0}, /* core2 elr_EL2 bit19 */
			{46918,42,0}, /* core2 elr_EL2 bit20 */
			{46916,42,0}, /* core2 elr_EL2 bit21 */
			{46896,42,0}, /* core2 elr_EL2 bit22 */
			{39150,42,0}, /* core2 elr_EL2 bit23 */
			{46926,42,0}, /* core2 elr_EL2 bit24 */
			{46924,42,0}, /* core2 elr_EL2 bit25 */
			{46938,42,0}, /* core2 elr_EL2 bit26 */
			{39148,42,0}, /* core2 elr_EL2 bit27 */
			{46936,42,0}, /* core2 elr_EL2 bit28 */
			{46934,42,0}, /* core2 elr_EL2 bit29 */
			{46932,42,0}, /* core2 elr_EL2 bit30 */
			{31862,42,0}, /* core2 elr_EL2 bit31 */
			{46782,42,0}, /* core2 elr_EL2 bit32 */
			{46780,42,0}, /* core2 elr_EL2 bit33 */
			{46842,42,0}, /* core2 elr_EL2 bit34 */
			{46840,42,0}, /* core2 elr_EL2 bit35 */
			{46838,42,0}, /* core2 elr_EL2 bit36 */
			{46836,42,0}, /* core2 elr_EL2 bit37 */
			{46826,42,0}, /* core2 elr_EL2 bit38 */
			{46824,42,0}, /* core2 elr_EL2 bit39 */
			{46794,42,0}, /* core2 elr_EL2 bit40 */
			{46822,42,0}, /* core2 elr_EL2 bit41 */
			{46820,42,0}, /* core2 elr_EL2 bit42 */
			{46792,42,0}, /* core2 elr_EL2 bit43 */
			{46810,42,0}, /* core2 elr_EL2 bit44 */
			{46808,42,0}, /* core2 elr_EL2 bit45 */
			{46806,42,0}, /* core2 elr_EL2 bit46 */
			{46804,42,0}, /* core2 elr_EL2 bit47 */
			{46626,42,0}, /* core2 elr_EL2 bit48 */
			{46790,42,0}, /* core2 elr_EL2 bit49 */
			{46788,42,0}, /* core2 elr_EL2 bit50 */
			{46578,42,0}, /* core2 elr_EL2 bit51 */
			{46576,42,0}, /* core2 elr_EL2 bit52 */
			{46574,42,0}, /* core2 elr_EL2 bit53 */
			{46572,42,0}, /* core2 elr_EL2 bit54 */
			{46570,42,0}, /* core2 elr_EL2 bit55 */
			{46568,42,0}, /* core2 elr_EL2 bit56 */
			{46624,42,0}, /* core2 elr_EL2 bit57 */
			{46566,42,0}, /* core2 elr_EL2 bit58 */
			{46564,42,0}, /* core2 elr_EL2 bit59 */
			{46622,42,0}, /* core2 elr_EL2 bit60 */
			{46786,42,0}, /* core2 elr_EL2 bit61 */
			{46784,42,0}, /* core2 elr_EL2 bit62 */
			{46620,42,0}, /* core2 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{39064,42,0}, /* core2 elr_EL3 bit0 */
			{39062,42,0}, /* core2 elr_EL3 bit1 */
			{39100,42,0}, /* core2 elr_EL3 bit2 */
			{39188,42,0}, /* core2 elr_EL3 bit3 */
			{39068,42,0}, /* core2 elr_EL3 bit4 */
			{39066,42,0}, /* core2 elr_EL3 bit5 */
			{39098,42,0}, /* core2 elr_EL3 bit6 */
			{31880,42,0}, /* core2 elr_EL3 bit7 */
			{39060,42,0}, /* core2 elr_EL3 bit8 */
			{39058,42,0}, /* core2 elr_EL3 bit9 */
			{39172,42,0}, /* core2 elr_EL3 bit10 */
			{39186,42,0}, /* core2 elr_EL3 bit11 */
			{39168,42,0}, /* core2 elr_EL3 bit12 */
			{39226,42,0}, /* core2 elr_EL3 bit13 */
			{39112,42,0}, /* core2 elr_EL3 bit14 */
			{39124,42,0}, /* core2 elr_EL3 bit15 */
			{39110,42,0}, /* core2 elr_EL3 bit16 */
			{39116,42,0}, /* core2 elr_EL3 bit17 */
			{31830,42,0}, /* core2 elr_EL3 bit18 */
			{39122,42,0}, /* core2 elr_EL3 bit19 */
			{39170,42,0}, /* core2 elr_EL3 bit20 */
			{39192,42,0}, /* core2 elr_EL3 bit21 */
			{39114,42,0}, /* core2 elr_EL3 bit22 */
			{39190,42,0}, /* core2 elr_EL3 bit23 */
			{31828,42,0}, /* core2 elr_EL3 bit24 */
			{39184,42,0}, /* core2 elr_EL3 bit25 */
			{39182,42,0}, /* core2 elr_EL3 bit26 */
			{39176,42,0}, /* core2 elr_EL3 bit27 */
			{39174,42,0}, /* core2 elr_EL3 bit28 */
			{39180,42,0}, /* core2 elr_EL3 bit29 */
			{39178,42,0}, /* core2 elr_EL3 bit30 */
			{31846,42,0}, /* core2 elr_EL3 bit31 */
			{46078,42,0}, /* core2 elr_EL3 bit32 */
			{39044,42,0}, /* core2 elr_EL3 bit33 */
			{39042,42,0}, /* core2 elr_EL3 bit34 */
			{32156,42,0}, /* core2 elr_EL3 bit35 */
			{32154,42,0}, /* core2 elr_EL3 bit36 */
			{39016,42,0}, /* core2 elr_EL3 bit37 */
			{39014,42,0}, /* core2 elr_EL3 bit38 */
			{39012,42,0}, /* core2 elr_EL3 bit39 */
			{31902,42,0}, /* core2 elr_EL3 bit40 */
			{31920,42,0}, /* core2 elr_EL3 bit41 */
			{39010,42,0}, /* core2 elr_EL3 bit42 */
			{38948,42,0}, /* core2 elr_EL3 bit43 */
			{38952,42,0}, /* core2 elr_EL3 bit44 */
			{38950,42,0}, /* core2 elr_EL3 bit45 */
			{38946,42,0}, /* core2 elr_EL3 bit46 */
			{38944,42,0}, /* core2 elr_EL3 bit47 */
			{38942,42,0}, /* core2 elr_EL3 bit48 */
			{46538,42,0}, /* core2 elr_EL3 bit49 */
			{46586,42,0}, /* core2 elr_EL3 bit50 */
			{46584,42,0}, /* core2 elr_EL3 bit51 */
			{46536,42,0}, /* core2 elr_EL3 bit52 */
			{46534,42,0}, /* core2 elr_EL3 bit53 */
			{46532,42,0}, /* core2 elr_EL3 bit54 */
			{46530,42,0}, /* core2 elr_EL3 bit55 */
			{46528,42,0}, /* core2 elr_EL3 bit56 */
			{46582,42,0}, /* core2 elr_EL3 bit57 */
			{46526,42,0}, /* core2 elr_EL3 bit58 */
			{46524,42,0}, /* core2 elr_EL3 bit59 */
			{46084,42,0}, /* core2 elr_EL3 bit60 */
			{46082,42,0}, /* core2 elr_EL3 bit61 */
			{46080,42,0}, /* core2 elr_EL3 bit62 */
			{46580,42,0}, /* core2 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{44712,42,0}, /* core2 raw_pc bit0 */
			{19018,45,0}, /* core2 raw_pc bit1 */
			{19016,45,0}, /* core2 raw_pc bit2 */
			{19012,45,0}, /* core2 raw_pc bit3 */
			{19014,45,0}, /* core2 raw_pc bit4 */
			{44704,42,0}, /* core2 raw_pc bit5 */
			{44702,42,0}, /* core2 raw_pc bit6 */
			{19158,45,0}, /* core2 raw_pc bit7 */
			{19032,45,0}, /* core2 raw_pc bit8 */
			{19030,45,0}, /* core2 raw_pc bit9 */
			{19028,45,0}, /* core2 raw_pc bit10 */
			{19156,45,0}, /* core2 raw_pc bit11 */
			{19154,45,0}, /* core2 raw_pc bit12 */
			{19152,45,0}, /* core2 raw_pc bit13 */
			{19150,45,0}, /* core2 raw_pc bit14 */
			{19148,45,0}, /* core2 raw_pc bit15 */
			{19146,45,0}, /* core2 raw_pc bit16 */
			{19144,45,0}, /* core2 raw_pc bit17 */
			{19142,45,0}, /* core2 raw_pc bit18 */
			{19060,45,0}, /* core2 raw_pc bit19 */
			{19058,45,0}, /* core2 raw_pc bit20 */
			{19056,45,0}, /* core2 raw_pc bit21 */
			{19054,45,0}, /* core2 raw_pc bit22 */
			{19052,45,0}, /* core2 raw_pc bit23 */
			{19050,45,0}, /* core2 raw_pc bit24 */
			{19048,45,0}, /* core2 raw_pc bit25 */
			{19046,45,0}, /* core2 raw_pc bit26 */
			{19044,45,0}, /* core2 raw_pc bit27 */
			{19042,45,0}, /* core2 raw_pc bit28 */
			{19040,45,0}, /* core2 raw_pc bit29 */
			{19038,45,0}, /* core2 raw_pc bit30 */
			{19010,45,0}, /* core2 raw_pc bit31 */
			{19008,45,0}, /* core2 raw_pc bit32 */
			{19006,45,0}, /* core2 raw_pc bit33 */
			{19004,45,0}, /* core2 raw_pc bit34 */
			{19002,45,0}, /* core2 raw_pc bit35 */
			{19000,45,0}, /* core2 raw_pc bit36 */
			{18998,45,0}, /* core2 raw_pc bit37 */
			{18996,45,0}, /* core2 raw_pc bit38 */
			{18994,45,0}, /* core2 raw_pc bit39 */
			{18992,45,0}, /* core2 raw_pc bit40 */
			{18990,45,0}, /* core2 raw_pc bit41 */
			{18988,45,0}, /* core2 raw_pc bit42 */
			{18982,45,0}, /* core2 raw_pc bit43 */
			{18980,45,0}, /* core2 raw_pc bit44 */
			{18986,45,0}, /* core2 raw_pc bit45 */
			{18984,45,0}, /* core2 raw_pc bit46 */
			{44708,42,0}, /* core2 raw_pc bit47 */
			{44706,42,0}, /* core2 raw_pc bit48 */
			{36762,42,0}, /* core2 raw_pc bit49 */
			{    0, 0,2}, /* core2 raw_pc bit50 */
			{    0, 0,2}, /* core2 raw_pc bit51 */
			{    0, 0,2}, /* core2 raw_pc bit52 */
			{    0, 0,2}, /* core2 raw_pc bit53 */
			{    0, 0,2}, /* core2 raw_pc bit54 */
			{    0, 0,2}, /* core2 raw_pc bit55 */
			{    0, 0,2}, /* core2 raw_pc bit56 */
			{    0, 0,2}, /* core2 raw_pc bit57 */
			{    0, 0,2}, /* core2 raw_pc bit58 */
			{    0, 0,2}, /* core2 raw_pc bit59 */
			{    0, 0,2}, /* core2 raw_pc bit60 */
			{    0, 0,2}, /* core2 raw_pc bit61 */
			{    0, 0,2}, /* core2 raw_pc bit62 */
			{    0, 0,2}, /* core2 raw_pc bit63 */
			}},
			.pc_iss = {{
			{44752,42,0}, /* core2 pc_iss bit0 */
			{44760,42,0}, /* core2 pc_iss bit1 */
			{44758,42,0}, /* core2 pc_iss bit2 */
			{44764,42,0}, /* core2 pc_iss bit3 */
			{44762,42,0}, /* core2 pc_iss bit4 */
			{44750,42,0}, /* core2 pc_iss bit5 */
			{44756,42,0}, /* core2 pc_iss bit6 */
			{44754,42,0}, /* core2 pc_iss bit7 */
			{44768,42,0}, /* core2 pc_iss bit8 */
			{44766,42,0}, /* core2 pc_iss bit9 */
			{44746,42,0}, /* core2 pc_iss bit10 */
			{44744,42,0}, /* core2 pc_iss bit11 */
			{45102,42,0}, /* core2 pc_iss bit12 */
			{45100,42,0}, /* core2 pc_iss bit13 */
			{45098,42,0}, /* core2 pc_iss bit14 */
			{44748,42,0}, /* core2 pc_iss bit15 */
			{45096,42,0}, /* core2 pc_iss bit16 */
			{45090,42,0}, /* core2 pc_iss bit17 */
			{45088,42,0}, /* core2 pc_iss bit18 */
			{45082,42,0}, /* core2 pc_iss bit19 */
			{45080,42,0}, /* core2 pc_iss bit20 */
			{45086,42,0}, /* core2 pc_iss bit21 */
			{45084,42,0}, /* core2 pc_iss bit22 */
			{44782,42,0}, /* core2 pc_iss bit23 */
			{44780,42,0}, /* core2 pc_iss bit24 */
			{36740,42,0}, /* core2 pc_iss bit25 */
			{36738,42,0}, /* core2 pc_iss bit26 */
			{45094,42,0}, /* core2 pc_iss bit27 */
			{45092,42,0}, /* core2 pc_iss bit28 */
			{44742,42,0}, /* core2 pc_iss bit29 */
			{44740,42,0}, /* core2 pc_iss bit30 */
			{44778,42,0}, /* core2 pc_iss bit31 */
			{44700,42,0}, /* core2 pc_iss bit32 */
			{44698,42,0}, /* core2 pc_iss bit33 */
			{44696,42,0}, /* core2 pc_iss bit34 */
			{44694,42,0}, /* core2 pc_iss bit35 */
			{44680,42,0}, /* core2 pc_iss bit36 */
			{44678,42,0}, /* core2 pc_iss bit37 */
			{44692,42,0}, /* core2 pc_iss bit38 */
			{44688,42,0}, /* core2 pc_iss bit39 */
			{44686,42,0}, /* core2 pc_iss bit40 */
			{44684,42,0}, /* core2 pc_iss bit41 */
			{44682,42,0}, /* core2 pc_iss bit42 */
			{44690,42,0}, /* core2 pc_iss bit43 */
			{18930,45,0}, /* core2 pc_iss bit44 */
			{18928,45,0}, /* core2 pc_iss bit45 */
			{18926,45,0}, /* core2 pc_iss bit46 */
			{18924,45,0}, /* core2 pc_iss bit47 */
			{18922,45,0}, /* core2 pc_iss bit48 */
			{18920,45,0}, /* core2 pc_iss bit49 */
			{18918,45,0}, /* core2 pc_iss bit50 */
			{18880,45,0}, /* core2 pc_iss bit51 */
			{18904,45,0}, /* core2 pc_iss bit52 */
			{18902,45,0}, /* core2 pc_iss bit53 */
			{18916,45,0}, /* core2 pc_iss bit54 */
			{18914,45,0}, /* core2 pc_iss bit55 */
			{19026,45,0}, /* core2 pc_iss bit56 */
			{19020,45,0}, /* core2 pc_iss bit57 */
			{19036,45,0}, /* core2 pc_iss bit58 */
			{19034,45,0}, /* core2 pc_iss bit59 */
			{18900,45,0}, /* core2 pc_iss bit60 */
			{18898,45,0}, /* core2 pc_iss bit61 */
			{19024,45,0}, /* core2 pc_iss bit62 */
			{19022,45,0}, /* core2 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{44710,42,0}, /* core2 full_pc_wr bit0 */
			{    0, 0,2}, /* core2 full_pc_wr bit1 */
			{    0, 0,2}, /* core2 full_pc_wr bit2 */
			{    0, 0,2}, /* core2 full_pc_wr bit3 */
			{    0, 0,2}, /* core2 full_pc_wr bit4 */
			{    0, 0,2}, /* core2 full_pc_wr bit5 */
			{    0, 0,2}, /* core2 full_pc_wr bit6 */
			{    0, 0,2}, /* core2 full_pc_wr bit7 */
			{    0, 0,2}, /* core2 full_pc_wr bit8 */
			{    0, 0,2}, /* core2 full_pc_wr bit9 */
			{    0, 0,2}, /* core2 full_pc_wr bit10 */
			{    0, 0,2}, /* core2 full_pc_wr bit11 */
			{    0, 0,2}, /* core2 full_pc_wr bit12 */
			{    0, 0,2}, /* core2 full_pc_wr bit13 */
			{    0, 0,2}, /* core2 full_pc_wr bit14 */
			{    0, 0,2}, /* core2 full_pc_wr bit15 */
			{    0, 0,2}, /* core2 full_pc_wr bit16 */
			{    0, 0,2}, /* core2 full_pc_wr bit17 */
			{    0, 0,2}, /* core2 full_pc_wr bit18 */
			{    0, 0,2}, /* core2 full_pc_wr bit19 */
			{    0, 0,2}, /* core2 full_pc_wr bit20 */
			{    0, 0,2}, /* core2 full_pc_wr bit21 */
			{    0, 0,2}, /* core2 full_pc_wr bit22 */
			{    0, 0,2}, /* core2 full_pc_wr bit23 */
			{    0, 0,2}, /* core2 full_pc_wr bit24 */
			{    0, 0,2}, /* core2 full_pc_wr bit25 */
			{    0, 0,2}, /* core2 full_pc_wr bit26 */
			{    0, 0,2}, /* core2 full_pc_wr bit27 */
			{    0, 0,2}, /* core2 full_pc_wr bit28 */
			{    0, 0,2}, /* core2 full_pc_wr bit29 */
			{    0, 0,2}, /* core2 full_pc_wr bit30 */
			{    0, 0,2}, /* core2 full_pc_wr bit31 */
			{    0, 0,2}, /* core2 full_pc_wr bit32 */
			{    0, 0,2}, /* core2 full_pc_wr bit33 */
			{    0, 0,2}, /* core2 full_pc_wr bit34 */
			{    0, 0,2}, /* core2 full_pc_wr bit35 */
			{    0, 0,2}, /* core2 full_pc_wr bit36 */
			{    0, 0,2}, /* core2 full_pc_wr bit37 */
			{    0, 0,2}, /* core2 full_pc_wr bit38 */
			{    0, 0,2}, /* core2 full_pc_wr bit39 */
			{    0, 0,2}, /* core2 full_pc_wr bit40 */
			{    0, 0,2}, /* core2 full_pc_wr bit41 */
			{    0, 0,2}, /* core2 full_pc_wr bit42 */
			{    0, 0,2}, /* core2 full_pc_wr bit43 */
			{    0, 0,2}, /* core2 full_pc_wr bit44 */
			{    0, 0,2}, /* core2 full_pc_wr bit45 */
			{    0, 0,2}, /* core2 full_pc_wr bit46 */
			{    0, 0,2}, /* core2 full_pc_wr bit47 */
			{    0, 0,2}, /* core2 full_pc_wr bit48 */
			{    0, 0,2}, /* core2 full_pc_wr bit49 */
			{    0, 0,2}, /* core2 full_pc_wr bit50 */
			{    0, 0,2}, /* core2 full_pc_wr bit51 */
			{    0, 0,2}, /* core2 full_pc_wr bit52 */
			{    0, 0,2}, /* core2 full_pc_wr bit53 */
			{    0, 0,2}, /* core2 full_pc_wr bit54 */
			{    0, 0,2}, /* core2 full_pc_wr bit55 */
			{    0, 0,2}, /* core2 full_pc_wr bit56 */
			{    0, 0,2}, /* core2 full_pc_wr bit57 */
			{    0, 0,2}, /* core2 full_pc_wr bit58 */
			{    0, 0,2}, /* core2 full_pc_wr bit59 */
			{    0, 0,2}, /* core2 full_pc_wr bit60 */
			{    0, 0,2}, /* core2 full_pc_wr bit61 */
			{    0, 0,2}, /* core2 full_pc_wr bit62 */
			{    0, 0,2}, /* core2 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{37250,42,0}, /* core2 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core2 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{44772,42,0}, /* core2 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core2 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{ 7874,43,0}, /* core2 return_Stack_pointer bit0 */
			{ 7872,43,0}, /* core2 return_Stack_pointer bit1 */
			{ 7878,43,0}, /* core2 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core2 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{19482,43,0}, /* core2 return_Stack0 bit0 */
			{19480,43,0}, /* core2 return_Stack0 bit1 */
			{19478,43,0}, /* core2 return_Stack0 bit2 */
			{19476,43,0}, /* core2 return_Stack0 bit3 */
			{19266,43,0}, /* core2 return_Stack0 bit4 */
			{19264,43,0}, /* core2 return_Stack0 bit5 */
			{19262,43,0}, /* core2 return_Stack0 bit6 */
			{19260,43,0}, /* core2 return_Stack0 bit7 */
			{19274,43,0}, /* core2 return_Stack0 bit8 */
			{19272,43,0}, /* core2 return_Stack0 bit9 */
			{19270,43,0}, /* core2 return_Stack0 bit10 */
			{ 7838,43,0}, /* core2 return_Stack0 bit11 */
			{19268,43,0}, /* core2 return_Stack0 bit12 */
			{19250,43,0}, /* core2 return_Stack0 bit13 */
			{19248,43,0}, /* core2 return_Stack0 bit14 */
			{19246,43,0}, /* core2 return_Stack0 bit15 */
			{19244,43,0}, /* core2 return_Stack0 bit16 */
			{19442,43,0}, /* core2 return_Stack0 bit17 */
			{ 7836,43,0}, /* core2 return_Stack0 bit18 */
			{ 3022,43,0}, /* core2 return_Stack0 bit19 */
			{19440,43,0}, /* core2 return_Stack0 bit20 */
			{19438,43,0}, /* core2 return_Stack0 bit21 */
			{19436,43,0}, /* core2 return_Stack0 bit22 */
			{19426,43,0}, /* core2 return_Stack0 bit23 */
			{19424,43,0}, /* core2 return_Stack0 bit24 */
			{19422,43,0}, /* core2 return_Stack0 bit25 */
			{19420,43,0}, /* core2 return_Stack0 bit26 */
			{19434,43,0}, /* core2 return_Stack0 bit27 */
			{19432,43,0}, /* core2 return_Stack0 bit28 */
			{19430,43,0}, /* core2 return_Stack0 bit29 */
			{19428,43,0}, /* core2 return_Stack0 bit30 */
			{19394,43,0}, /* core2 return_Stack0 bit31 */
			{19392,43,0}, /* core2 return_Stack0 bit32 */
			{19390,43,0}, /* core2 return_Stack0 bit33 */
			{19388,43,0}, /* core2 return_Stack0 bit34 */
			{19378,43,0}, /* core2 return_Stack0 bit35 */
			{19376,43,0}, /* core2 return_Stack0 bit36 */
			{19374,43,0}, /* core2 return_Stack0 bit37 */
			{19372,43,0}, /* core2 return_Stack0 bit38 */
			{19362,43,0}, /* core2 return_Stack0 bit39 */
			{19360,43,0}, /* core2 return_Stack0 bit40 */
			{19358,43,0}, /* core2 return_Stack0 bit41 */
			{19356,43,0}, /* core2 return_Stack0 bit42 */
			{19498,43,0}, /* core2 return_Stack0 bit43 */
			{19496,43,0}, /* core2 return_Stack0 bit44 */
			{19494,43,0}, /* core2 return_Stack0 bit45 */
			{19492,43,0}, /* core2 return_Stack0 bit46 */
			{ 7846,43,0}, /* core2 return_Stack0 bit47 */
			{ 7844,43,0}, /* core2 return_Stack0 bit48 */
			{    0, 0,2}, /* core2 return_Stack0 bit49 */
			{    0, 0,2}, /* core2 return_Stack0 bit50 */
			{    0, 0,2}, /* core2 return_Stack0 bit51 */
			{    0, 0,2}, /* core2 return_Stack0 bit52 */
			{    0, 0,2}, /* core2 return_Stack0 bit53 */
			{    0, 0,2}, /* core2 return_Stack0 bit54 */
			{    0, 0,2}, /* core2 return_Stack0 bit55 */
			{    0, 0,2}, /* core2 return_Stack0 bit56 */
			{    0, 0,2}, /* core2 return_Stack0 bit57 */
			{    0, 0,2}, /* core2 return_Stack0 bit58 */
			{    0, 0,2}, /* core2 return_Stack0 bit59 */
			{    0, 0,2}, /* core2 return_Stack0 bit60 */
			{    0, 0,2}, /* core2 return_Stack0 bit61 */
			{    0, 0,2}, /* core2 return_Stack0 bit62 */
			{    0, 0,2}, /* core2 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{19490,43,0}, /* core2 return_Stack1 bit0 */
			{19488,43,0}, /* core2 return_Stack1 bit1 */
			{19486,43,0}, /* core2 return_Stack1 bit2 */
			{19484,43,0}, /* core2 return_Stack1 bit3 */
			{19242,43,0}, /* core2 return_Stack1 bit4 */
			{19240,43,0}, /* core2 return_Stack1 bit5 */
			{19466,43,0}, /* core2 return_Stack1 bit6 */
			{19238,43,0}, /* core2 return_Stack1 bit7 */
			{19236,43,0}, /* core2 return_Stack1 bit8 */
			{19258,43,0}, /* core2 return_Stack1 bit9 */
			{19256,43,0}, /* core2 return_Stack1 bit10 */
			{19464,43,0}, /* core2 return_Stack1 bit11 */
			{19254,43,0}, /* core2 return_Stack1 bit12 */
			{19252,43,0}, /* core2 return_Stack1 bit13 */
			{19474,43,0}, /* core2 return_Stack1 bit14 */
			{19472,43,0}, /* core2 return_Stack1 bit15 */
			{19470,43,0}, /* core2 return_Stack1 bit16 */
			{19468,43,0}, /* core2 return_Stack1 bit17 */
			{19462,43,0}, /* core2 return_Stack1 bit18 */
			{19460,43,0}, /* core2 return_Stack1 bit19 */
			{19410,43,0}, /* core2 return_Stack1 bit20 */
			{19408,43,0}, /* core2 return_Stack1 bit21 */
			{19406,43,0}, /* core2 return_Stack1 bit22 */
			{19404,43,0}, /* core2 return_Stack1 bit23 */
			{19418,43,0}, /* core2 return_Stack1 bit24 */
			{19416,43,0}, /* core2 return_Stack1 bit25 */
			{19414,43,0}, /* core2 return_Stack1 bit26 */
			{19412,43,0}, /* core2 return_Stack1 bit27 */
			{19402,43,0}, /* core2 return_Stack1 bit28 */
			{19400,43,0}, /* core2 return_Stack1 bit29 */
			{19398,43,0}, /* core2 return_Stack1 bit30 */
			{19396,43,0}, /* core2 return_Stack1 bit31 */
			{19386,43,0}, /* core2 return_Stack1 bit32 */
			{19384,43,0}, /* core2 return_Stack1 bit33 */
			{19382,43,0}, /* core2 return_Stack1 bit34 */
			{19380,43,0}, /* core2 return_Stack1 bit35 */
			{19370,43,0}, /* core2 return_Stack1 bit36 */
			{19368,43,0}, /* core2 return_Stack1 bit37 */
			{19366,43,0}, /* core2 return_Stack1 bit38 */
			{19364,43,0}, /* core2 return_Stack1 bit39 */
			{19354,43,0}, /* core2 return_Stack1 bit40 */
			{19346,43,0}, /* core2 return_Stack1 bit41 */
			{19344,43,0}, /* core2 return_Stack1 bit42 */
			{19352,43,0}, /* core2 return_Stack1 bit43 */
			{19350,43,0}, /* core2 return_Stack1 bit44 */
			{19342,43,0}, /* core2 return_Stack1 bit45 */
			{19348,43,0}, /* core2 return_Stack1 bit46 */
			{19340,43,0}, /* core2 return_Stack1 bit47 */
			{ 3024,43,0}, /* core2 return_Stack1 bit48 */
			{    0, 0,2}, /* core2 return_Stack1 bit49 */
			{    0, 0,2}, /* core2 return_Stack1 bit50 */
			{    0, 0,2}, /* core2 return_Stack1 bit51 */
			{    0, 0,2}, /* core2 return_Stack1 bit52 */
			{    0, 0,2}, /* core2 return_Stack1 bit53 */
			{    0, 0,2}, /* core2 return_Stack1 bit54 */
			{    0, 0,2}, /* core2 return_Stack1 bit55 */
			{    0, 0,2}, /* core2 return_Stack1 bit56 */
			{    0, 0,2}, /* core2 return_Stack1 bit57 */
			{    0, 0,2}, /* core2 return_Stack1 bit58 */
			{    0, 0,2}, /* core2 return_Stack1 bit59 */
			{    0, 0,2}, /* core2 return_Stack1 bit60 */
			{    0, 0,2}, /* core2 return_Stack1 bit61 */
			{    0, 0,2}, /* core2 return_Stack1 bit62 */
			{    0, 0,2}, /* core2 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{ 7850,43,0}, /* core2 return_Stack2 bit0 */
			{19282,43,0}, /* core2 return_Stack2 bit1 */
			{ 7848,43,0}, /* core2 return_Stack2 bit2 */
			{19280,43,0}, /* core2 return_Stack2 bit3 */
			{19278,43,0}, /* core2 return_Stack2 bit4 */
			{19234,43,0}, /* core2 return_Stack2 bit5 */
			{19276,43,0}, /* core2 return_Stack2 bit6 */
			{ 3028,43,0}, /* core2 return_Stack2 bit7 */
			{19232,43,0}, /* core2 return_Stack2 bit8 */
			{19230,43,0}, /* core2 return_Stack2 bit9 */
			{19218,43,0}, /* core2 return_Stack2 bit10 */
			{19228,43,0}, /* core2 return_Stack2 bit11 */
			{19216,43,0}, /* core2 return_Stack2 bit12 */
			{ 7834,43,0}, /* core2 return_Stack2 bit13 */
			{19214,43,0}, /* core2 return_Stack2 bit14 */
			{ 7832,43,0}, /* core2 return_Stack2 bit15 */
			{19212,43,0}, /* core2 return_Stack2 bit16 */
			{19202,43,0}, /* core2 return_Stack2 bit17 */
			{19200,43,0}, /* core2 return_Stack2 bit18 */
			{19198,43,0}, /* core2 return_Stack2 bit19 */
			{19196,43,0}, /* core2 return_Stack2 bit20 */
			{19178,43,0}, /* core2 return_Stack2 bit21 */
			{19176,43,0}, /* core2 return_Stack2 bit22 */
			{19174,43,0}, /* core2 return_Stack2 bit23 */
			{19172,43,0}, /* core2 return_Stack2 bit24 */
			{19170,43,0}, /* core2 return_Stack2 bit25 */
			{19168,43,0}, /* core2 return_Stack2 bit26 */
			{19166,43,0}, /* core2 return_Stack2 bit27 */
			{19164,43,0}, /* core2 return_Stack2 bit28 */
			{19138,43,0}, /* core2 return_Stack2 bit29 */
			{19136,43,0}, /* core2 return_Stack2 bit30 */
			{19134,43,0}, /* core2 return_Stack2 bit31 */
			{19132,43,0}, /* core2 return_Stack2 bit32 */
			{19538,43,0}, /* core2 return_Stack2 bit33 */
			{19536,43,0}, /* core2 return_Stack2 bit34 */
			{19534,43,0}, /* core2 return_Stack2 bit35 */
			{19532,43,0}, /* core2 return_Stack2 bit36 */
			{19522,43,0}, /* core2 return_Stack2 bit37 */
			{19520,43,0}, /* core2 return_Stack2 bit38 */
			{19518,43,0}, /* core2 return_Stack2 bit39 */
			{19516,43,0}, /* core2 return_Stack2 bit40 */
			{19514,43,0}, /* core2 return_Stack2 bit41 */
			{19512,43,0}, /* core2 return_Stack2 bit42 */
			{19510,43,0}, /* core2 return_Stack2 bit43 */
			{19508,43,0}, /* core2 return_Stack2 bit44 */
			{19338,43,0}, /* core2 return_Stack2 bit45 */
			{19336,43,0}, /* core2 return_Stack2 bit46 */
			{19334,43,0}, /* core2 return_Stack2 bit47 */
			{19332,43,0}, /* core2 return_Stack2 bit48 */
			{    0, 0,2}, /* core2 return_Stack2 bit49 */
			{    0, 0,2}, /* core2 return_Stack2 bit50 */
			{    0, 0,2}, /* core2 return_Stack2 bit51 */
			{    0, 0,2}, /* core2 return_Stack2 bit52 */
			{    0, 0,2}, /* core2 return_Stack2 bit53 */
			{    0, 0,2}, /* core2 return_Stack2 bit54 */
			{    0, 0,2}, /* core2 return_Stack2 bit55 */
			{    0, 0,2}, /* core2 return_Stack2 bit56 */
			{    0, 0,2}, /* core2 return_Stack2 bit57 */
			{    0, 0,2}, /* core2 return_Stack2 bit58 */
			{    0, 0,2}, /* core2 return_Stack2 bit59 */
			{    0, 0,2}, /* core2 return_Stack2 bit60 */
			{    0, 0,2}, /* core2 return_Stack2 bit61 */
			{    0, 0,2}, /* core2 return_Stack2 bit62 */
			{    0, 0,2}, /* core2 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{ 3030,43,0}, /* core2 return_Stack3 bit0 */
			{19322,43,0}, /* core2 return_Stack3 bit1 */
			{19320,43,0}, /* core2 return_Stack3 bit2 */
			{19318,43,0}, /* core2 return_Stack3 bit3 */
			{19316,43,0}, /* core2 return_Stack3 bit4 */
			{19290,43,0}, /* core2 return_Stack3 bit5 */
			{19288,43,0}, /* core2 return_Stack3 bit6 */
			{19286,43,0}, /* core2 return_Stack3 bit7 */
			{19284,43,0}, /* core2 return_Stack3 bit8 */
			{19226,43,0}, /* core2 return_Stack3 bit9 */
			{19224,43,0}, /* core2 return_Stack3 bit10 */
			{19222,43,0}, /* core2 return_Stack3 bit11 */
			{19220,43,0}, /* core2 return_Stack3 bit12 */
			{19210,43,0}, /* core2 return_Stack3 bit13 */
			{19208,43,0}, /* core2 return_Stack3 bit14 */
			{19206,43,0}, /* core2 return_Stack3 bit15 */
			{19204,43,0}, /* core2 return_Stack3 bit16 */
			{19194,43,0}, /* core2 return_Stack3 bit17 */
			{19192,43,0}, /* core2 return_Stack3 bit18 */
			{19190,43,0}, /* core2 return_Stack3 bit19 */
			{19188,43,0}, /* core2 return_Stack3 bit20 */
			{19186,43,0}, /* core2 return_Stack3 bit21 */
			{19184,43,0}, /* core2 return_Stack3 bit22 */
			{19182,43,0}, /* core2 return_Stack3 bit23 */
			{19180,43,0}, /* core2 return_Stack3 bit24 */
			{19162,43,0}, /* core2 return_Stack3 bit25 */
			{19160,43,0}, /* core2 return_Stack3 bit26 */
			{19158,43,0}, /* core2 return_Stack3 bit27 */
			{19156,43,0}, /* core2 return_Stack3 bit28 */
			{19130,43,0}, /* core2 return_Stack3 bit29 */
			{19128,43,0}, /* core2 return_Stack3 bit30 */
			{19126,43,0}, /* core2 return_Stack3 bit31 */
			{19124,43,0}, /* core2 return_Stack3 bit32 */
			{19546,43,0}, /* core2 return_Stack3 bit33 */
			{19544,43,0}, /* core2 return_Stack3 bit34 */
			{19542,43,0}, /* core2 return_Stack3 bit35 */
			{19540,43,0}, /* core2 return_Stack3 bit36 */
			{19530,43,0}, /* core2 return_Stack3 bit37 */
			{19528,43,0}, /* core2 return_Stack3 bit38 */
			{19526,43,0}, /* core2 return_Stack3 bit39 */
			{19524,43,0}, /* core2 return_Stack3 bit40 */
			{19506,43,0}, /* core2 return_Stack3 bit41 */
			{19504,43,0}, /* core2 return_Stack3 bit42 */
			{19502,43,0}, /* core2 return_Stack3 bit43 */
			{19500,43,0}, /* core2 return_Stack3 bit44 */
			{19330,43,0}, /* core2 return_Stack3 bit45 */
			{19328,43,0}, /* core2 return_Stack3 bit46 */
			{19326,43,0}, /* core2 return_Stack3 bit47 */
			{19324,43,0}, /* core2 return_Stack3 bit48 */
			{    0, 0,2}, /* core2 return_Stack3 bit49 */
			{    0, 0,2}, /* core2 return_Stack3 bit50 */
			{    0, 0,2}, /* core2 return_Stack3 bit51 */
			{    0, 0,2}, /* core2 return_Stack3 bit52 */
			{    0, 0,2}, /* core2 return_Stack3 bit53 */
			{    0, 0,2}, /* core2 return_Stack3 bit54 */
			{    0, 0,2}, /* core2 return_Stack3 bit55 */
			{    0, 0,2}, /* core2 return_Stack3 bit56 */
			{    0, 0,2}, /* core2 return_Stack3 bit57 */
			{    0, 0,2}, /* core2 return_Stack3 bit58 */
			{    0, 0,2}, /* core2 return_Stack3 bit59 */
			{    0, 0,2}, /* core2 return_Stack3 bit60 */
			{    0, 0,2}, /* core2 return_Stack3 bit61 */
			{    0, 0,2}, /* core2 return_Stack3 bit62 */
			{    0, 0,2}, /* core2 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{19314,43,0}, /* core2 return_Stack4 bit0 */
			{19312,43,0}, /* core2 return_Stack4 bit1 */
			{19310,43,0}, /* core2 return_Stack4 bit2 */
			{19308,43,0}, /* core2 return_Stack4 bit3 */
			{19306,43,0}, /* core2 return_Stack4 bit4 */
			{19304,43,0}, /* core2 return_Stack4 bit5 */
			{19302,43,0}, /* core2 return_Stack4 bit6 */
			{19300,43,0}, /* core2 return_Stack4 bit7 */
			{19298,43,0}, /* core2 return_Stack4 bit8 */
			{19296,43,0}, /* core2 return_Stack4 bit9 */
			{19294,43,0}, /* core2 return_Stack4 bit10 */
			{19292,43,0}, /* core2 return_Stack4 bit11 */
			{19458,43,0}, /* core2 return_Stack4 bit12 */
			{ 7842,43,0}, /* core2 return_Stack4 bit13 */
			{19456,43,0}, /* core2 return_Stack4 bit14 */
			{ 7840,43,0}, /* core2 return_Stack4 bit15 */
			{19454,43,0}, /* core2 return_Stack4 bit16 */
			{19452,43,0}, /* core2 return_Stack4 bit17 */
			{19450,43,0}, /* core2 return_Stack4 bit18 */
			{19448,43,0}, /* core2 return_Stack4 bit19 */
			{19446,43,0}, /* core2 return_Stack4 bit20 */
			{19444,43,0}, /* core2 return_Stack4 bit21 */
			{19146,43,0}, /* core2 return_Stack4 bit22 */
			{19144,43,0}, /* core2 return_Stack4 bit23 */
			{19142,43,0}, /* core2 return_Stack4 bit24 */
			{19140,43,0}, /* core2 return_Stack4 bit25 */
			{19154,43,0}, /* core2 return_Stack4 bit26 */
			{19152,43,0}, /* core2 return_Stack4 bit27 */
			{19150,43,0}, /* core2 return_Stack4 bit28 */
			{19148,43,0}, /* core2 return_Stack4 bit29 */
			{19122,43,0}, /* core2 return_Stack4 bit30 */
			{19120,43,0}, /* core2 return_Stack4 bit31 */
			{19118,43,0}, /* core2 return_Stack4 bit32 */
			{19116,43,0}, /* core2 return_Stack4 bit33 */
			{19114,43,0}, /* core2 return_Stack4 bit34 */
			{19112,43,0}, /* core2 return_Stack4 bit35 */
			{19110,43,0}, /* core2 return_Stack4 bit36 */
			{19108,43,0}, /* core2 return_Stack4 bit37 */
			{19046,43,0}, /* core2 return_Stack4 bit38 */
			{19044,43,0}, /* core2 return_Stack4 bit39 */
			{19042,43,0}, /* core2 return_Stack4 bit40 */
			{19040,43,0}, /* core2 return_Stack4 bit41 */
			{19054,43,0}, /* core2 return_Stack4 bit42 */
			{19052,43,0}, /* core2 return_Stack4 bit43 */
			{19050,43,0}, /* core2 return_Stack4 bit44 */
			{19048,43,0}, /* core2 return_Stack4 bit45 */
			{ 7854,43,0}, /* core2 return_Stack4 bit46 */
			{ 7852,43,0}, /* core2 return_Stack4 bit47 */
			{ 3026,43,0}, /* core2 return_Stack4 bit48 */
			{    0, 0,2}, /* core2 return_Stack4 bit49 */
			{    0, 0,2}, /* core2 return_Stack4 bit50 */
			{    0, 0,2}, /* core2 return_Stack4 bit51 */
			{    0, 0,2}, /* core2 return_Stack4 bit52 */
			{    0, 0,2}, /* core2 return_Stack4 bit53 */
			{    0, 0,2}, /* core2 return_Stack4 bit54 */
			{    0, 0,2}, /* core2 return_Stack4 bit55 */
			{    0, 0,2}, /* core2 return_Stack4 bit56 */
			{    0, 0,2}, /* core2 return_Stack4 bit57 */
			{    0, 0,2}, /* core2 return_Stack4 bit58 */
			{    0, 0,2}, /* core2 return_Stack4 bit59 */
			{    0, 0,2}, /* core2 return_Stack4 bit60 */
			{    0, 0,2}, /* core2 return_Stack4 bit61 */
			{    0, 0,2}, /* core2 return_Stack4 bit62 */
			{    0, 0,2}, /* core2 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{18982,43,0}, /* core2 return_Stack5 bit0 */
			{18980,43,0}, /* core2 return_Stack5 bit1 */
			{18978,43,0}, /* core2 return_Stack5 bit2 */
			{18976,43,0}, /* core2 return_Stack5 bit3 */
			{18958,43,0}, /* core2 return_Stack5 bit4 */
			{18942,43,0}, /* core2 return_Stack5 bit5 */
			{18956,43,0}, /* core2 return_Stack5 bit6 */
			{18954,43,0}, /* core2 return_Stack5 bit7 */
			{18952,43,0}, /* core2 return_Stack5 bit8 */
			{18940,43,0}, /* core2 return_Stack5 bit9 */
			{18938,43,0}, /* core2 return_Stack5 bit10 */
			{18936,43,0}, /* core2 return_Stack5 bit11 */
			{18918,43,0}, /* core2 return_Stack5 bit12 */
			{18916,43,0}, /* core2 return_Stack5 bit13 */
			{18914,43,0}, /* core2 return_Stack5 bit14 */
			{18912,43,0}, /* core2 return_Stack5 bit15 */
			{18886,43,0}, /* core2 return_Stack5 bit16 */
			{18884,43,0}, /* core2 return_Stack5 bit17 */
			{18882,43,0}, /* core2 return_Stack5 bit18 */
			{18880,43,0}, /* core2 return_Stack5 bit19 */
			{18838,43,0}, /* core2 return_Stack5 bit20 */
			{18836,43,0}, /* core2 return_Stack5 bit21 */
			{18834,43,0}, /* core2 return_Stack5 bit22 */
			{18832,43,0}, /* core2 return_Stack5 bit23 */
			{18830,43,0}, /* core2 return_Stack5 bit24 */
			{18828,43,0}, /* core2 return_Stack5 bit25 */
			{18826,43,0}, /* core2 return_Stack5 bit26 */
			{18824,43,0}, /* core2 return_Stack5 bit27 */
			{19014,43,0}, /* core2 return_Stack5 bit28 */
			{19012,43,0}, /* core2 return_Stack5 bit29 */
			{19010,43,0}, /* core2 return_Stack5 bit30 */
			{19008,43,0}, /* core2 return_Stack5 bit31 */
			{19022,43,0}, /* core2 return_Stack5 bit32 */
			{ 7894,43,0}, /* core2 return_Stack5 bit33 */
			{19020,43,0}, /* core2 return_Stack5 bit34 */
			{19018,43,0}, /* core2 return_Stack5 bit35 */
			{19016,43,0}, /* core2 return_Stack5 bit36 */
			{ 7892,43,0}, /* core2 return_Stack5 bit37 */
			{19086,43,0}, /* core2 return_Stack5 bit38 */
			{19084,43,0}, /* core2 return_Stack5 bit39 */
			{19082,43,0}, /* core2 return_Stack5 bit40 */
			{19080,43,0}, /* core2 return_Stack5 bit41 */
			{19062,43,0}, /* core2 return_Stack5 bit42 */
			{19060,43,0}, /* core2 return_Stack5 bit43 */
			{19058,43,0}, /* core2 return_Stack5 bit44 */
			{19056,43,0}, /* core2 return_Stack5 bit45 */
			{ 7862,43,0}, /* core2 return_Stack5 bit46 */
			{ 7860,43,0}, /* core2 return_Stack5 bit47 */
			{ 3034,43,0}, /* core2 return_Stack5 bit48 */
			{    0, 0,2}, /* core2 return_Stack5 bit49 */
			{    0, 0,2}, /* core2 return_Stack5 bit50 */
			{    0, 0,2}, /* core2 return_Stack5 bit51 */
			{    0, 0,2}, /* core2 return_Stack5 bit52 */
			{    0, 0,2}, /* core2 return_Stack5 bit53 */
			{    0, 0,2}, /* core2 return_Stack5 bit54 */
			{    0, 0,2}, /* core2 return_Stack5 bit55 */
			{    0, 0,2}, /* core2 return_Stack5 bit56 */
			{    0, 0,2}, /* core2 return_Stack5 bit57 */
			{    0, 0,2}, /* core2 return_Stack5 bit58 */
			{    0, 0,2}, /* core2 return_Stack5 bit59 */
			{    0, 0,2}, /* core2 return_Stack5 bit60 */
			{    0, 0,2}, /* core2 return_Stack5 bit61 */
			{    0, 0,2}, /* core2 return_Stack5 bit62 */
			{    0, 0,2}, /* core2 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{18990,43,0}, /* core2 return_Stack6 bit0 */
			{18988,43,0}, /* core2 return_Stack6 bit1 */
			{18986,43,0}, /* core2 return_Stack6 bit2 */
			{18984,43,0}, /* core2 return_Stack6 bit3 */
			{18950,43,0}, /* core2 return_Stack6 bit4 */
			{18926,43,0}, /* core2 return_Stack6 bit5 */
			{18948,43,0}, /* core2 return_Stack6 bit6 */
			{18946,43,0}, /* core2 return_Stack6 bit7 */
			{18944,43,0}, /* core2 return_Stack6 bit8 */
			{18924,43,0}, /* core2 return_Stack6 bit9 */
			{18922,43,0}, /* core2 return_Stack6 bit10 */
			{18920,43,0}, /* core2 return_Stack6 bit11 */
			{18902,43,0}, /* core2 return_Stack6 bit12 */
			{18900,43,0}, /* core2 return_Stack6 bit13 */
			{18898,43,0}, /* core2 return_Stack6 bit14 */
			{18896,43,0}, /* core2 return_Stack6 bit15 */
			{18894,43,0}, /* core2 return_Stack6 bit16 */
			{18892,43,0}, /* core2 return_Stack6 bit17 */
			{18890,43,0}, /* core2 return_Stack6 bit18 */
			{18888,43,0}, /* core2 return_Stack6 bit19 */
			{18862,43,0}, /* core2 return_Stack6 bit20 */
			{18860,43,0}, /* core2 return_Stack6 bit21 */
			{18858,43,0}, /* core2 return_Stack6 bit22 */
			{18856,43,0}, /* core2 return_Stack6 bit23 */
			{18846,43,0}, /* core2 return_Stack6 bit24 */
			{18844,43,0}, /* core2 return_Stack6 bit25 */
			{18842,43,0}, /* core2 return_Stack6 bit26 */
			{18840,43,0}, /* core2 return_Stack6 bit27 */
			{19006,43,0}, /* core2 return_Stack6 bit28 */
			{19004,43,0}, /* core2 return_Stack6 bit29 */
			{19002,43,0}, /* core2 return_Stack6 bit30 */
			{19000,43,0}, /* core2 return_Stack6 bit31 */
			{19030,43,0}, /* core2 return_Stack6 bit32 */
			{ 7886,43,0}, /* core2 return_Stack6 bit33 */
			{19028,43,0}, /* core2 return_Stack6 bit34 */
			{19026,43,0}, /* core2 return_Stack6 bit35 */
			{19024,43,0}, /* core2 return_Stack6 bit36 */
			{ 7884,43,0}, /* core2 return_Stack6 bit37 */
			{19102,43,0}, /* core2 return_Stack6 bit38 */
			{19100,43,0}, /* core2 return_Stack6 bit39 */
			{19098,43,0}, /* core2 return_Stack6 bit40 */
			{19096,43,0}, /* core2 return_Stack6 bit41 */
			{19070,43,0}, /* core2 return_Stack6 bit42 */
			{19068,43,0}, /* core2 return_Stack6 bit43 */
			{19066,43,0}, /* core2 return_Stack6 bit44 */
			{19064,43,0}, /* core2 return_Stack6 bit45 */
			{ 7866,43,0}, /* core2 return_Stack6 bit46 */
			{ 7864,43,0}, /* core2 return_Stack6 bit47 */
			{ 3036,43,0}, /* core2 return_Stack6 bit48 */
			{    0, 0,2}, /* core2 return_Stack6 bit49 */
			{    0, 0,2}, /* core2 return_Stack6 bit50 */
			{    0, 0,2}, /* core2 return_Stack6 bit51 */
			{    0, 0,2}, /* core2 return_Stack6 bit52 */
			{    0, 0,2}, /* core2 return_Stack6 bit53 */
			{    0, 0,2}, /* core2 return_Stack6 bit54 */
			{    0, 0,2}, /* core2 return_Stack6 bit55 */
			{    0, 0,2}, /* core2 return_Stack6 bit56 */
			{    0, 0,2}, /* core2 return_Stack6 bit57 */
			{    0, 0,2}, /* core2 return_Stack6 bit58 */
			{    0, 0,2}, /* core2 return_Stack6 bit59 */
			{    0, 0,2}, /* core2 return_Stack6 bit60 */
			{    0, 0,2}, /* core2 return_Stack6 bit61 */
			{    0, 0,2}, /* core2 return_Stack6 bit62 */
			{    0, 0,2}, /* core2 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{18974,43,0}, /* core2 return_Stack7 bit0 */
			{18972,43,0}, /* core2 return_Stack7 bit1 */
			{18970,43,0}, /* core2 return_Stack7 bit2 */
			{18968,43,0}, /* core2 return_Stack7 bit3 */
			{18966,43,0}, /* core2 return_Stack7 bit4 */
			{18934,43,0}, /* core2 return_Stack7 bit5 */
			{18964,43,0}, /* core2 return_Stack7 bit6 */
			{18962,43,0}, /* core2 return_Stack7 bit7 */
			{18960,43,0}, /* core2 return_Stack7 bit8 */
			{18932,43,0}, /* core2 return_Stack7 bit9 */
			{18930,43,0}, /* core2 return_Stack7 bit10 */
			{18928,43,0}, /* core2 return_Stack7 bit11 */
			{18910,43,0}, /* core2 return_Stack7 bit12 */
			{18908,43,0}, /* core2 return_Stack7 bit13 */
			{18906,43,0}, /* core2 return_Stack7 bit14 */
			{18904,43,0}, /* core2 return_Stack7 bit15 */
			{18878,43,0}, /* core2 return_Stack7 bit16 */
			{18876,43,0}, /* core2 return_Stack7 bit17 */
			{18874,43,0}, /* core2 return_Stack7 bit18 */
			{18872,43,0}, /* core2 return_Stack7 bit19 */
			{18870,43,0}, /* core2 return_Stack7 bit20 */
			{18868,43,0}, /* core2 return_Stack7 bit21 */
			{18866,43,0}, /* core2 return_Stack7 bit22 */
			{18864,43,0}, /* core2 return_Stack7 bit23 */
			{18854,43,0}, /* core2 return_Stack7 bit24 */
			{18852,43,0}, /* core2 return_Stack7 bit25 */
			{18850,43,0}, /* core2 return_Stack7 bit26 */
			{18848,43,0}, /* core2 return_Stack7 bit27 */
			{18998,43,0}, /* core2 return_Stack7 bit28 */
			{18996,43,0}, /* core2 return_Stack7 bit29 */
			{18994,43,0}, /* core2 return_Stack7 bit30 */
			{18992,43,0}, /* core2 return_Stack7 bit31 */
			{19038,43,0}, /* core2 return_Stack7 bit32 */
			{ 7890,43,0}, /* core2 return_Stack7 bit33 */
			{19036,43,0}, /* core2 return_Stack7 bit34 */
			{19034,43,0}, /* core2 return_Stack7 bit35 */
			{19032,43,0}, /* core2 return_Stack7 bit36 */
			{ 7888,43,0}, /* core2 return_Stack7 bit37 */
			{19094,43,0}, /* core2 return_Stack7 bit38 */
			{19092,43,0}, /* core2 return_Stack7 bit39 */
			{19090,43,0}, /* core2 return_Stack7 bit40 */
			{19088,43,0}, /* core2 return_Stack7 bit41 */
			{19078,43,0}, /* core2 return_Stack7 bit42 */
			{19076,43,0}, /* core2 return_Stack7 bit43 */
			{19074,43,0}, /* core2 return_Stack7 bit44 */
			{19072,43,0}, /* core2 return_Stack7 bit45 */
			{ 7858,43,0}, /* core2 return_Stack7 bit46 */
			{ 7856,43,0}, /* core2 return_Stack7 bit47 */
			{ 3032,43,0}, /* core2 return_Stack7 bit48 */
			{    0, 0,2}, /* core2 return_Stack7 bit49 */
			{    0, 0,2}, /* core2 return_Stack7 bit50 */
			{    0, 0,2}, /* core2 return_Stack7 bit51 */
			{    0, 0,2}, /* core2 return_Stack7 bit52 */
			{    0, 0,2}, /* core2 return_Stack7 bit53 */
			{    0, 0,2}, /* core2 return_Stack7 bit54 */
			{    0, 0,2}, /* core2 return_Stack7 bit55 */
			{    0, 0,2}, /* core2 return_Stack7 bit56 */
			{    0, 0,2}, /* core2 return_Stack7 bit57 */
			{    0, 0,2}, /* core2 return_Stack7 bit58 */
			{    0, 0,2}, /* core2 return_Stack7 bit59 */
			{    0, 0,2}, /* core2 return_Stack7 bit60 */
			{    0, 0,2}, /* core2 return_Stack7 bit61 */
			{    0, 0,2}, /* core2 return_Stack7 bit62 */
			{    0, 0,2}, /* core2 return_Stack7 bit63 */
			}},
	},
	{		/* core 3 */ 
			.pc = {{
			{ 2688,46,1}, /* core3 pc bit0 */
			{ 2686,46,1}, /* core3 pc bit1 */
			{ 2684,46,1}, /* core3 pc bit2 */
			{ 2682,46,1}, /* core3 pc bit3 */
			{ 2592,46,1}, /* core3 pc bit4 */
			{ 2590,46,1}, /* core3 pc bit5 */
			{ 2588,46,1}, /* core3 pc bit6 */
			{ 2586,46,1}, /* core3 pc bit7 */
			{ 2584,46,1}, /* core3 pc bit8 */
			{ 2582,46,1}, /* core3 pc bit9 */
			{ 2580,46,1}, /* core3 pc bit10 */
			{ 2578,46,1}, /* core3 pc bit11 */
			{ 2600,46,1}, /* core3 pc bit12 */
			{ 2598,46,1}, /* core3 pc bit13 */
			{ 2596,46,1}, /* core3 pc bit14 */
			{ 2594,46,1}, /* core3 pc bit15 */
			{ 2448,46,1}, /* core3 pc bit16 */
			{ 2446,46,1}, /* core3 pc bit17 */
			{ 2444,46,1}, /* core3 pc bit18 */
			{ 2442,46,1}, /* core3 pc bit19 */
			{ 2432,46,1}, /* core3 pc bit20 */
			{ 2430,46,1}, /* core3 pc bit21 */
			{ 2428,46,1}, /* core3 pc bit22 */
			{ 2426,46,1}, /* core3 pc bit23 */
			{ 2352,46,1}, /* core3 pc bit24 */
			{ 2350,46,1}, /* core3 pc bit25 */
			{ 2348,46,1}, /* core3 pc bit26 */
			{ 2346,46,1}, /* core3 pc bit27 */
			{ 2344,46,1}, /* core3 pc bit28 */
			{ 2342,46,1}, /* core3 pc bit29 */
			{ 2340,46,1}, /* core3 pc bit30 */
			{ 2338,46,1}, /* core3 pc bit31 */
			{ 2656,46,1}, /* core3 pc bit32 */
			{ 2654,46,1}, /* core3 pc bit33 */
			{ 2652,46,1}, /* core3 pc bit34 */
			{ 2650,46,1}, /* core3 pc bit35 */
			{ 2616,46,1}, /* core3 pc bit36 */
			{ 2614,46,1}, /* core3 pc bit37 */
			{ 2612,46,1}, /* core3 pc bit38 */
			{ 2610,46,1}, /* core3 pc bit39 */
			{ 2632,46,1}, /* core3 pc bit40 */
			{ 2630,46,1}, /* core3 pc bit41 */
			{  676,46,1}, /* core3 pc bit42 */
			{ 2628,46,1}, /* core3 pc bit43 */
			{ 2626,46,1}, /* core3 pc bit44 */
			{ 2608,46,1}, /* core3 pc bit45 */
			{ 2606,46,1}, /* core3 pc bit46 */
			{ 2604,46,1}, /* core3 pc bit47 */
			{ 2602,46,1}, /* core3 pc bit48 */
			{ 2400,46,1}, /* core3 pc bit49 */
			{ 2398,46,1}, /* core3 pc bit50 */
			{ 2396,46,1}, /* core3 pc bit51 */
			{ 2394,46,1}, /* core3 pc bit52 */
			{ 2312,46,1}, /* core3 pc bit53 */
			{ 2310,46,1}, /* core3 pc bit54 */
			{ 2308,46,1}, /* core3 pc bit55 */
			{ 2306,46,1}, /* core3 pc bit56 */
			{ 2164,46,1}, /* core3 pc bit57 */
			{ 2162,46,1}, /* core3 pc bit58 */
			{ 2160,46,1}, /* core3 pc bit59 */
			{ 2158,46,1}, /* core3 pc bit60 */
			{  682,46,1}, /* core3 pc bit61 */
			{  680,46,1}, /* core3 pc bit62 */
			{ 2228,46,1}, /* core3 pc bit63 */
			}},
			.sp32 = {{
			{32298,46,0}, /* core3 sp32 bit0 */
			{40686,46,0}, /* core3 sp32 bit1 */
			{32308,46,0}, /* core3 sp32 bit2 */
			{40522,46,0}, /* core3 sp32 bit3 */
			{40684,46,0}, /* core3 sp32 bit4 */
			{40682,46,0}, /* core3 sp32 bit5 */
			{40680,46,0}, /* core3 sp32 bit6 */
			{40690,46,0}, /* core3 sp32 bit7 */
			{40688,46,0}, /* core3 sp32 bit8 */
			{40654,46,0}, /* core3 sp32 bit9 */
			{40520,46,0}, /* core3 sp32 bit10 */
			{40526,46,0}, /* core3 sp32 bit11 */
			{40524,46,0}, /* core3 sp32 bit12 */
			{40646,46,0}, /* core3 sp32 bit13 */
			{40652,46,0}, /* core3 sp32 bit14 */
			{40644,46,0}, /* core3 sp32 bit15 */
			{40642,46,0}, /* core3 sp32 bit16 */
			{40640,46,0}, /* core3 sp32 bit17 */
			{32264,46,0}, /* core3 sp32 bit18 */
			{40614,46,0}, /* core3 sp32 bit19 */
			{40612,46,0}, /* core3 sp32 bit20 */
			{40510,46,0}, /* core3 sp32 bit21 */
			{32260,46,0}, /* core3 sp32 bit22 */
			{40508,46,0}, /* core3 sp32 bit23 */
			{40490,46,0}, /* core3 sp32 bit24 */
			{40488,46,0}, /* core3 sp32 bit25 */
			{40564,46,0}, /* core3 sp32 bit26 */
			{40562,46,0}, /* core3 sp32 bit27 */
			{40560,46,0}, /* core3 sp32 bit28 */
			{40566,46,0}, /* core3 sp32 bit29 */
			{32258,46,0}, /* core3 sp32 bit30 */
			{32256,46,0}, /* core3 sp32 bit31 */
			{40362,46,0}, /* core3 sp32 bit32 */
			{40360,46,0}, /* core3 sp32 bit33 */
			{40354,46,0}, /* core3 sp32 bit34 */
			{40352,46,0}, /* core3 sp32 bit35 */
			{40358,46,0}, /* core3 sp32 bit36 */
			{40356,46,0}, /* core3 sp32 bit37 */
			{31992,46,0}, /* core3 sp32 bit38 */
			{40350,46,0}, /* core3 sp32 bit39 */
			{40348,46,0}, /* core3 sp32 bit40 */
			{40322,46,0}, /* core3 sp32 bit41 */
			{40320,46,0}, /* core3 sp32 bit42 */
			{32028,46,0}, /* core3 sp32 bit43 */
			{40318,46,0}, /* core3 sp32 bit44 */
			{32030,46,0}, /* core3 sp32 bit45 */
			{40316,46,0}, /* core3 sp32 bit46 */
			{32032,46,0}, /* core3 sp32 bit47 */
			{47404,46,0}, /* core3 sp32 bit48 */
			{47402,46,0}, /* core3 sp32 bit49 */
			{47400,46,0}, /* core3 sp32 bit50 */
			{47398,46,0}, /* core3 sp32 bit51 */
			{47332,46,0}, /* core3 sp32 bit52 */
			{47330,46,0}, /* core3 sp32 bit53 */
			{47328,46,0}, /* core3 sp32 bit54 */
			{47326,46,0}, /* core3 sp32 bit55 */
			{47340,46,0}, /* core3 sp32 bit56 */
			{47338,46,0}, /* core3 sp32 bit57 */
			{47336,46,0}, /* core3 sp32 bit58 */
			{47334,46,0}, /* core3 sp32 bit59 */
			{47348,46,0}, /* core3 sp32 bit60 */
			{47346,46,0}, /* core3 sp32 bit61 */
			{47344,46,0}, /* core3 sp32 bit62 */
			{47342,46,0}, /* core3 sp32 bit63 */
			}},
			.fp32 = {{
			{32654,46,0}, /* core3 fp32 bit0 */
			{32322,46,0}, /* core3 fp32 bit1 */
			{40906,46,0}, /* core3 fp32 bit2 */
			{40900,46,0}, /* core3 fp32 bit3 */
			{40976,46,0}, /* core3 fp32 bit4 */
			{40974,46,0}, /* core3 fp32 bit5 */
			{40972,46,0}, /* core3 fp32 bit6 */
			{32646,46,0}, /* core3 fp32 bit7 */
			{40970,46,0}, /* core3 fp32 bit8 */
			{32320,46,0}, /* core3 fp32 bit9 */
			{40896,46,0}, /* core3 fp32 bit10 */
			{40904,46,0}, /* core3 fp32 bit11 */
			{40898,46,0}, /* core3 fp32 bit12 */
			{32390,46,0}, /* core3 fp32 bit13 */
			{40908,46,0}, /* core3 fp32 bit14 */
			{40902,46,0}, /* core3 fp32 bit15 */
			{40920,46,0}, /* core3 fp32 bit16 */
			{40918,46,0}, /* core3 fp32 bit17 */
			{32418,46,0}, /* core3 fp32 bit18 */
			{32386,46,0}, /* core3 fp32 bit19 */
			{40894,46,0}, /* core3 fp32 bit20 */
			{32348,46,0}, /* core3 fp32 bit21 */
			{32412,46,0}, /* core3 fp32 bit22 */
			{32334,46,0}, /* core3 fp32 bit23 */
			{32336,46,0}, /* core3 fp32 bit24 */
			{32342,46,0}, /* core3 fp32 bit25 */
			{40916,46,0}, /* core3 fp32 bit26 */
			{40914,46,0}, /* core3 fp32 bit27 */
			{32388,46,0}, /* core3 fp32 bit28 */
			{40924,46,0}, /* core3 fp32 bit29 */
			{40922,46,0}, /* core3 fp32 bit30 */
			{32424,46,0}, /* core3 fp32 bit31 */
			{41026,46,0}, /* core3 fp32 bit32 */
			{32578,46,0}, /* core3 fp32 bit33 */
			{41036,46,0}, /* core3 fp32 bit34 */
			{41022,46,0}, /* core3 fp32 bit35 */
			{41024,46,0}, /* core3 fp32 bit36 */
			{41028,46,0}, /* core3 fp32 bit37 */
			{32580,46,0}, /* core3 fp32 bit38 */
			{32582,46,0}, /* core3 fp32 bit39 */
			{41032,46,0}, /* core3 fp32 bit40 */
			{41030,46,0}, /* core3 fp32 bit41 */
			{41040,46,0}, /* core3 fp32 bit42 */
			{32552,46,0}, /* core3 fp32 bit43 */
			{41038,46,0}, /* core3 fp32 bit44 */
			{40992,46,0}, /* core3 fp32 bit45 */
			{41034,46,0}, /* core3 fp32 bit46 */
			{40990,46,0}, /* core3 fp32 bit47 */
			{32614,46,0}, /* core3 fp32 bit48 */
			{41064,46,0}, /* core3 fp32 bit49 */
			{47526,46,0}, /* core3 fp32 bit50 */
			{47524,46,0}, /* core3 fp32 bit51 */
			{47520,46,0}, /* core3 fp32 bit52 */
			{47430,46,0}, /* core3 fp32 bit53 */
			{47428,46,0}, /* core3 fp32 bit54 */
			{47426,46,0}, /* core3 fp32 bit55 */
			{47422,46,0}, /* core3 fp32 bit56 */
			{47424,46,0}, /* core3 fp32 bit57 */
			{47420,46,0}, /* core3 fp32 bit58 */
			{41062,46,0}, /* core3 fp32 bit59 */
			{47418,46,0}, /* core3 fp32 bit60 */
			{47416,46,0}, /* core3 fp32 bit61 */
			{32634,46,0}, /* core3 fp32 bit62 */
			{47518,46,0}, /* core3 fp32 bit63 */
			}},
			.fp64 = {{
			{32172,46,0}, /* core3 fp64 bit0 */
			{31886,46,0}, /* core3 fp64 bit1 */
			{39704,46,0}, /* core3 fp64 bit2 */
			{39782,46,0}, /* core3 fp64 bit3 */
			{32160,46,0}, /* core3 fp64 bit4 */
			{39662,46,0}, /* core3 fp64 bit5 */
			{39650,46,0}, /* core3 fp64 bit6 */
			{39648,46,0}, /* core3 fp64 bit7 */
			{39682,46,0}, /* core3 fp64 bit8 */
			{39660,46,0}, /* core3 fp64 bit9 */
			{31822,46,0}, /* core3 fp64 bit10 */
			{31824,46,0}, /* core3 fp64 bit11 */
			{31818,46,0}, /* core3 fp64 bit12 */
			{32222,46,0}, /* core3 fp64 bit13 */
			{39680,46,0}, /* core3 fp64 bit14 */
			{32224,46,0}, /* core3 fp64 bit15 */
			{39722,46,0}, /* core3 fp64 bit16 */
			{39720,46,0}, /* core3 fp64 bit17 */
			{39778,46,0}, /* core3 fp64 bit18 */
			{39786,46,0}, /* core3 fp64 bit19 */
			{39780,46,0}, /* core3 fp64 bit20 */
			{39784,46,0}, /* core3 fp64 bit21 */
			{39706,46,0}, /* core3 fp64 bit22 */
			{39770,46,0}, /* core3 fp64 bit23 */
			{39768,46,0}, /* core3 fp64 bit24 */
			{39742,46,0}, /* core3 fp64 bit25 */
			{39776,46,0}, /* core3 fp64 bit26 */
			{39740,46,0}, /* core3 fp64 bit27 */
			{31826,46,0}, /* core3 fp64 bit28 */
			{39774,46,0}, /* core3 fp64 bit29 */
			{39772,46,0}, /* core3 fp64 bit30 */
			{31836,46,0}, /* core3 fp64 bit31 */
			{31976,46,0}, /* core3 fp64 bit32 */
			{31974,46,0}, /* core3 fp64 bit33 */
			{31972,46,0}, /* core3 fp64 bit34 */
			{39436,46,0}, /* core3 fp64 bit35 */
			{39438,46,0}, /* core3 fp64 bit36 */
			{39430,46,0}, /* core3 fp64 bit37 */
			{39426,46,0}, /* core3 fp64 bit38 */
			{39428,46,0}, /* core3 fp64 bit39 */
			{39394,46,0}, /* core3 fp64 bit40 */
			{39392,46,0}, /* core3 fp64 bit41 */
			{39424,46,0}, /* core3 fp64 bit42 */
			{39398,46,0}, /* core3 fp64 bit43 */
			{39402,46,0}, /* core3 fp64 bit44 */
			{39410,46,0}, /* core3 fp64 bit45 */
			{39396,46,0}, /* core3 fp64 bit46 */
			{39400,46,0}, /* core3 fp64 bit47 */
			{39408,46,0}, /* core3 fp64 bit48 */
			{46722,46,0}, /* core3 fp64 bit49 */
			{46720,46,0}, /* core3 fp64 bit50 */
			{46718,46,0}, /* core3 fp64 bit51 */
			{46708,46,0}, /* core3 fp64 bit52 */
			{46698,46,0}, /* core3 fp64 bit53 */
			{46696,46,0}, /* core3 fp64 bit54 */
			{46694,46,0}, /* core3 fp64 bit55 */
			{46692,46,0}, /* core3 fp64 bit56 */
			{46706,46,0}, /* core3 fp64 bit57 */
			{46704,46,0}, /* core3 fp64 bit58 */
			{46702,46,0}, /* core3 fp64 bit59 */
			{46700,46,0}, /* core3 fp64 bit60 */
			{32034,46,0}, /* core3 fp64 bit61 */
			{32042,46,0}, /* core3 fp64 bit62 */
			{32040,46,0}, /* core3 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{31878,46,0}, /* core3 sp_EL0 bit0 */
			{31882,46,0}, /* core3 sp_EL0 bit1 */
			{39692,46,0}, /* core3 sp_EL0 bit2 */
			{39816,46,0}, /* core3 sp_EL0 bit3 */
			{39652,46,0}, /* core3 sp_EL0 bit4 */
			{39654,46,0}, /* core3 sp_EL0 bit5 */
			{39658,46,0}, /* core3 sp_EL0 bit6 */
			{39656,46,0}, /* core3 sp_EL0 bit7 */
			{39686,46,0}, /* core3 sp_EL0 bit8 */
			{39684,46,0}, /* core3 sp_EL0 bit9 */
			{39688,46,0}, /* core3 sp_EL0 bit10 */
			{39690,46,0}, /* core3 sp_EL0 bit11 */
			{39822,46,0}, /* core3 sp_EL0 bit12 */
			{31850,46,0}, /* core3 sp_EL0 bit13 */
			{39820,46,0}, /* core3 sp_EL0 bit14 */
			{31848,46,0}, /* core3 sp_EL0 bit15 */
			{39698,46,0}, /* core3 sp_EL0 bit16 */
			{39824,46,0}, /* core3 sp_EL0 bit17 */
			{39830,46,0}, /* core3 sp_EL0 bit18 */
			{39828,46,0}, /* core3 sp_EL0 bit19 */
			{39826,46,0}, /* core3 sp_EL0 bit20 */
			{39696,46,0}, /* core3 sp_EL0 bit21 */
			{39702,46,0}, /* core3 sp_EL0 bit22 */
			{39806,46,0}, /* core3 sp_EL0 bit23 */
			{39804,46,0}, /* core3 sp_EL0 bit24 */
			{39700,46,0}, /* core3 sp_EL0 bit25 */
			{39808,46,0}, /* core3 sp_EL0 bit26 */
			{39810,46,0}, /* core3 sp_EL0 bit27 */
			{39814,46,0}, /* core3 sp_EL0 bit28 */
			{39812,46,0}, /* core3 sp_EL0 bit29 */
			{39694,46,0}, /* core3 sp_EL0 bit30 */
			{39818,46,0}, /* core3 sp_EL0 bit31 */
			{39446,46,0}, /* core3 sp_EL0 bit32 */
			{32134,46,0}, /* core3 sp_EL0 bit33 */
			{39444,46,0}, /* core3 sp_EL0 bit34 */
			{32136,46,0}, /* core3 sp_EL0 bit35 */
			{32132,46,0}, /* core3 sp_EL0 bit36 */
			{32128,46,0}, /* core3 sp_EL0 bit37 */
			{32130,46,0}, /* core3 sp_EL0 bit38 */
			{39390,46,0}, /* core3 sp_EL0 bit39 */
			{39388,46,0}, /* core3 sp_EL0 bit40 */
			{39004,46,0}, /* core3 sp_EL0 bit41 */
			{39002,46,0}, /* core3 sp_EL0 bit42 */
			{38960,46,0}, /* core3 sp_EL0 bit43 */
			{31934,46,0}, /* core3 sp_EL0 bit44 */
			{38958,46,0}, /* core3 sp_EL0 bit45 */
			{46754,46,0}, /* core3 sp_EL0 bit46 */
			{46752,46,0}, /* core3 sp_EL0 bit47 */
			{46750,46,0}, /* core3 sp_EL0 bit48 */
			{38964,46,0}, /* core3 sp_EL0 bit49 */
			{38962,46,0}, /* core3 sp_EL0 bit50 */
			{46748,46,0}, /* core3 sp_EL0 bit51 */
			{46738,46,0}, /* core3 sp_EL0 bit52 */
			{46730,46,0}, /* core3 sp_EL0 bit53 */
			{46736,46,0}, /* core3 sp_EL0 bit54 */
			{46728,46,0}, /* core3 sp_EL0 bit55 */
			{46726,46,0}, /* core3 sp_EL0 bit56 */
			{46724,46,0}, /* core3 sp_EL0 bit57 */
			{46746,46,0}, /* core3 sp_EL0 bit58 */
			{46734,46,0}, /* core3 sp_EL0 bit59 */
			{46732,46,0}, /* core3 sp_EL0 bit60 */
			{46744,46,0}, /* core3 sp_EL0 bit61 */
			{46742,46,0}, /* core3 sp_EL0 bit62 */
			{46740,46,0}, /* core3 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{31874,46,0}, /* core3 sp_EL1 bit0 */
			{39272,46,0}, /* core3 sp_EL1 bit1 */
			{31872,46,0}, /* core3 sp_EL1 bit2 */
			{39270,46,0}, /* core3 sp_EL1 bit3 */
			{39084,46,0}, /* core3 sp_EL1 bit4 */
			{39082,46,0}, /* core3 sp_EL1 bit5 */
			{39086,46,0}, /* core3 sp_EL1 bit6 */
			{39072,46,0}, /* core3 sp_EL1 bit7 */
			{39070,46,0}, /* core3 sp_EL1 bit8 */
			{39088,46,0}, /* core3 sp_EL1 bit9 */
			{39134,46,0}, /* core3 sp_EL1 bit10 */
			{39128,46,0}, /* core3 sp_EL1 bit11 */
			{39238,46,0}, /* core3 sp_EL1 bit12 */
			{39126,46,0}, /* core3 sp_EL1 bit13 */
			{39260,46,0}, /* core3 sp_EL1 bit14 */
			{39262,46,0}, /* core3 sp_EL1 bit15 */
			{39264,46,0}, /* core3 sp_EL1 bit16 */
			{39252,46,0}, /* core3 sp_EL1 bit17 */
			{31854,46,0}, /* core3 sp_EL1 bit18 */
			{39250,46,0}, /* core3 sp_EL1 bit19 */
			{39242,46,0}, /* core3 sp_EL1 bit20 */
			{39240,46,0}, /* core3 sp_EL1 bit21 */
			{39268,46,0}, /* core3 sp_EL1 bit22 */
			{39266,46,0}, /* core3 sp_EL1 bit23 */
			{39132,46,0}, /* core3 sp_EL1 bit24 */
			{39258,46,0}, /* core3 sp_EL1 bit25 */
			{39130,46,0}, /* core3 sp_EL1 bit26 */
			{39138,46,0}, /* core3 sp_EL1 bit27 */
			{39236,46,0}, /* core3 sp_EL1 bit28 */
			{39140,46,0}, /* core3 sp_EL1 bit29 */
			{39136,46,0}, /* core3 sp_EL1 bit30 */
			{31852,46,0}, /* core3 sp_EL1 bit31 */
			{39028,46,0}, /* core3 sp_EL1 bit32 */
			{32108,46,0}, /* core3 sp_EL1 bit33 */
			{39026,46,0}, /* core3 sp_EL1 bit34 */
			{39020,46,0}, /* core3 sp_EL1 bit35 */
			{32104,46,0}, /* core3 sp_EL1 bit36 */
			{39018,46,0}, /* core3 sp_EL1 bit37 */
			{32102,46,0}, /* core3 sp_EL1 bit38 */
			{39008,46,0}, /* core3 sp_EL1 bit39 */
			{39006,46,0}, /* core3 sp_EL1 bit40 */
			{39000,46,0}, /* core3 sp_EL1 bit41 */
			{38998,46,0}, /* core3 sp_EL1 bit42 */
			{38956,46,0}, /* core3 sp_EL1 bit43 */
			{31932,46,0}, /* core3 sp_EL1 bit44 */
			{38954,46,0}, /* core3 sp_EL1 bit45 */
			{38980,46,0}, /* core3 sp_EL1 bit46 */
			{38978,46,0}, /* core3 sp_EL1 bit47 */
			{46778,46,0}, /* core3 sp_EL1 bit48 */
			{46776,46,0}, /* core3 sp_EL1 bit49 */
			{46774,46,0}, /* core3 sp_EL1 bit50 */
			{46772,46,0}, /* core3 sp_EL1 bit51 */
			{46682,46,0}, /* core3 sp_EL1 bit52 */
			{46680,46,0}, /* core3 sp_EL1 bit53 */
			{46678,46,0}, /* core3 sp_EL1 bit54 */
			{46676,46,0}, /* core3 sp_EL1 bit55 */
			{46690,46,0}, /* core3 sp_EL1 bit56 */
			{46688,46,0}, /* core3 sp_EL1 bit57 */
			{46686,46,0}, /* core3 sp_EL1 bit58 */
			{46684,46,0}, /* core3 sp_EL1 bit59 */
			{46634,46,0}, /* core3 sp_EL1 bit60 */
			{46632,46,0}, /* core3 sp_EL1 bit61 */
			{46630,46,0}, /* core3 sp_EL1 bit62 */
			{46628,46,0}, /* core3 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{31870,46,0}, /* core3 sp_EL2 bit0 */
			{39094,46,0}, /* core3 sp_EL2 bit1 */
			{31868,46,0}, /* core3 sp_EL2 bit2 */
			{39234,46,0}, /* core3 sp_EL2 bit3 */
			{39080,46,0}, /* core3 sp_EL2 bit4 */
			{39078,46,0}, /* core3 sp_EL2 bit5 */
			{39076,46,0}, /* core3 sp_EL2 bit6 */
			{39074,46,0}, /* core3 sp_EL2 bit7 */
			{39092,46,0}, /* core3 sp_EL2 bit8 */
			{39090,46,0}, /* core3 sp_EL2 bit9 */
			{39232,46,0}, /* core3 sp_EL2 bit10 */
			{39158,46,0}, /* core3 sp_EL2 bit11 */
			{39146,46,0}, /* core3 sp_EL2 bit12 */
			{39254,46,0}, /* core3 sp_EL2 bit13 */
			{39276,46,0}, /* core3 sp_EL2 bit14 */
			{39256,46,0}, /* core3 sp_EL2 bit15 */
			{39274,46,0}, /* core3 sp_EL2 bit16 */
			{39248,46,0}, /* core3 sp_EL2 bit17 */
			{31858,46,0}, /* core3 sp_EL2 bit18 */
			{39144,46,0}, /* core3 sp_EL2 bit19 */
			{39142,46,0}, /* core3 sp_EL2 bit20 */
			{39166,46,0}, /* core3 sp_EL2 bit21 */
			{39096,46,0}, /* core3 sp_EL2 bit22 */
			{39164,46,0}, /* core3 sp_EL2 bit23 */
			{39162,46,0}, /* core3 sp_EL2 bit24 */
			{39230,46,0}, /* core3 sp_EL2 bit25 */
			{39228,46,0}, /* core3 sp_EL2 bit26 */
			{39156,46,0}, /* core3 sp_EL2 bit27 */
			{39154,46,0}, /* core3 sp_EL2 bit28 */
			{39160,46,0}, /* core3 sp_EL2 bit29 */
			{39152,46,0}, /* core3 sp_EL2 bit30 */
			{31866,46,0}, /* core3 sp_EL2 bit31 */
			{39040,46,0}, /* core3 sp_EL2 bit32 */
			{32148,46,0}, /* core3 sp_EL2 bit33 */
			{39038,46,0}, /* core3 sp_EL2 bit34 */
			{39032,46,0}, /* core3 sp_EL2 bit35 */
			{39030,46,0}, /* core3 sp_EL2 bit36 */
			{32106,46,0}, /* core3 sp_EL2 bit37 */
			{39024,46,0}, /* core3 sp_EL2 bit38 */
			{38988,46,0}, /* core3 sp_EL2 bit39 */
			{39022,46,0}, /* core3 sp_EL2 bit40 */
			{38996,46,0}, /* core3 sp_EL2 bit41 */
			{38994,46,0}, /* core3 sp_EL2 bit42 */
			{38986,46,0}, /* core3 sp_EL2 bit43 */
			{38984,46,0}, /* core3 sp_EL2 bit44 */
			{32074,46,0}, /* core3 sp_EL2 bit45 */
			{38982,46,0}, /* core3 sp_EL2 bit46 */
			{46770,46,0}, /* core3 sp_EL2 bit47 */
			{46762,46,0}, /* core3 sp_EL2 bit48 */
			{46768,46,0}, /* core3 sp_EL2 bit49 */
			{46760,46,0}, /* core3 sp_EL2 bit50 */
			{46758,46,0}, /* core3 sp_EL2 bit51 */
			{46756,46,0}, /* core3 sp_EL2 bit52 */
			{46650,46,0}, /* core3 sp_EL2 bit53 */
			{46648,46,0}, /* core3 sp_EL2 bit54 */
			{46646,46,0}, /* core3 sp_EL2 bit55 */
			{46644,46,0}, /* core3 sp_EL2 bit56 */
			{46642,46,0}, /* core3 sp_EL2 bit57 */
			{46640,46,0}, /* core3 sp_EL2 bit58 */
			{46638,46,0}, /* core3 sp_EL2 bit59 */
			{46636,46,0}, /* core3 sp_EL2 bit60 */
			{46766,46,0}, /* core3 sp_EL2 bit61 */
			{46764,46,0}, /* core3 sp_EL2 bit62 */
			{32070,46,0}, /* core3 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{31844,46,0}, /* core3 sp_EL3 bit0 */
			{31884,46,0}, /* core3 sp_EL3 bit1 */
			{39056,46,0}, /* core3 sp_EL3 bit2 */
			{39220,46,0}, /* core3 sp_EL3 bit3 */
			{39052,46,0}, /* core3 sp_EL3 bit4 */
			{39050,46,0}, /* core3 sp_EL3 bit5 */
			{39054,46,0}, /* core3 sp_EL3 bit6 */
			{39048,46,0}, /* core3 sp_EL3 bit7 */
			{39046,46,0}, /* core3 sp_EL3 bit8 */
			{39102,46,0}, /* core3 sp_EL3 bit9 */
			{39212,46,0}, /* core3 sp_EL3 bit10 */
			{39206,46,0}, /* core3 sp_EL3 bit11 */
			{39204,46,0}, /* core3 sp_EL3 bit12 */
			{39120,46,0}, /* core3 sp_EL3 bit13 */
			{39104,46,0}, /* core3 sp_EL3 bit14 */
			{39118,46,0}, /* core3 sp_EL3 bit15 */
			{39108,46,0}, /* core3 sp_EL3 bit16 */
			{31832,46,0}, /* core3 sp_EL3 bit17 */
			{39218,46,0}, /* core3 sp_EL3 bit18 */
			{39224,46,0}, /* core3 sp_EL3 bit19 */
			{39222,46,0}, /* core3 sp_EL3 bit20 */
			{39196,46,0}, /* core3 sp_EL3 bit21 */
			{39106,46,0}, /* core3 sp_EL3 bit22 */
			{39194,46,0}, /* core3 sp_EL3 bit23 */
			{39200,46,0}, /* core3 sp_EL3 bit24 */
			{39210,46,0}, /* core3 sp_EL3 bit25 */
			{39198,46,0}, /* core3 sp_EL3 bit26 */
			{39216,46,0}, /* core3 sp_EL3 bit27 */
			{39208,46,0}, /* core3 sp_EL3 bit28 */
			{39202,46,0}, /* core3 sp_EL3 bit29 */
			{39214,46,0}, /* core3 sp_EL3 bit30 */
			{31834,46,0}, /* core3 sp_EL3 bit31 */
			{39036,46,0}, /* core3 sp_EL3 bit32 */
			{32140,46,0}, /* core3 sp_EL3 bit33 */
			{39034,46,0}, /* core3 sp_EL3 bit34 */
			{32144,46,0}, /* core3 sp_EL3 bit35 */
			{32142,46,0}, /* core3 sp_EL3 bit36 */
			{32124,46,0}, /* core3 sp_EL3 bit37 */
			{32126,46,0}, /* core3 sp_EL3 bit38 */
			{32092,46,0}, /* core3 sp_EL3 bit39 */
			{32094,46,0}, /* core3 sp_EL3 bit40 */
			{32084,46,0}, /* core3 sp_EL3 bit41 */
			{38992,46,0}, /* core3 sp_EL3 bit42 */
			{31930,46,0}, /* core3 sp_EL3 bit43 */
			{38990,46,0}, /* core3 sp_EL3 bit44 */
			{32076,46,0}, /* core3 sp_EL3 bit45 */
			{38972,46,0}, /* core3 sp_EL3 bit46 */
			{38976,46,0}, /* core3 sp_EL3 bit47 */
			{38974,46,0}, /* core3 sp_EL3 bit48 */
			{46658,46,0}, /* core3 sp_EL3 bit49 */
			{46656,46,0}, /* core3 sp_EL3 bit50 */
			{46654,46,0}, /* core3 sp_EL3 bit51 */
			{46652,46,0}, /* core3 sp_EL3 bit52 */
			{46674,46,0}, /* core3 sp_EL3 bit53 */
			{46672,46,0}, /* core3 sp_EL3 bit54 */
			{46670,46,0}, /* core3 sp_EL3 bit55 */
			{46668,46,0}, /* core3 sp_EL3 bit56 */
			{46666,46,0}, /* core3 sp_EL3 bit57 */
			{46664,46,0}, /* core3 sp_EL3 bit58 */
			{46662,46,0}, /* core3 sp_EL3 bit59 */
			{38970,46,0}, /* core3 sp_EL3 bit60 */
			{46660,46,0}, /* core3 sp_EL3 bit61 */
			{38968,46,0}, /* core3 sp_EL3 bit62 */
			{38966,46,0}, /* core3 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{46886,46,0}, /* core3 elr_EL1 bit0 */
			{46884,46,0}, /* core3 elr_EL1 bit1 */
			{46888,46,0}, /* core3 elr_EL1 bit2 */
			{46954,46,0}, /* core3 elr_EL1 bit3 */
			{46890,46,0}, /* core3 elr_EL1 bit4 */
			{46882,46,0}, /* core3 elr_EL1 bit5 */
			{46880,46,0}, /* core3 elr_EL1 bit6 */
			{46874,46,0}, /* core3 elr_EL1 bit7 */
			{46872,46,0}, /* core3 elr_EL1 bit8 */
			{46870,46,0}, /* core3 elr_EL1 bit9 */
			{46952,46,0}, /* core3 elr_EL1 bit10 */
			{46950,46,0}, /* core3 elr_EL1 bit11 */
			{46914,46,0}, /* core3 elr_EL1 bit12 */
			{46948,46,0}, /* core3 elr_EL1 bit13 */
			{46878,46,0}, /* core3 elr_EL1 bit14 */
			{46904,46,0}, /* core3 elr_EL1 bit15 */
			{46868,46,0}, /* core3 elr_EL1 bit16 */
			{31856,46,0}, /* core3 elr_EL1 bit17 */
			{46958,46,0}, /* core3 elr_EL1 bit18 */
			{46956,46,0}, /* core3 elr_EL1 bit19 */
			{46906,46,0}, /* core3 elr_EL1 bit20 */
			{46946,46,0}, /* core3 elr_EL1 bit21 */
			{46876,46,0}, /* core3 elr_EL1 bit22 */
			{46912,46,0}, /* core3 elr_EL1 bit23 */
			{46910,46,0}, /* core3 elr_EL1 bit24 */
			{46908,46,0}, /* core3 elr_EL1 bit25 */
			{46944,46,0}, /* core3 elr_EL1 bit26 */
			{46942,46,0}, /* core3 elr_EL1 bit27 */
			{46940,46,0}, /* core3 elr_EL1 bit28 */
			{39246,46,0}, /* core3 elr_EL1 bit29 */
			{39244,46,0}, /* core3 elr_EL1 bit30 */
			{31864,46,0}, /* core3 elr_EL1 bit31 */
			{46612,46,0}, /* core3 elr_EL1 bit32 */
			{46850,46,0}, /* core3 elr_EL1 bit33 */
			{46848,46,0}, /* core3 elr_EL1 bit34 */
			{46846,46,0}, /* core3 elr_EL1 bit35 */
			{46844,46,0}, /* core3 elr_EL1 bit36 */
			{46834,46,0}, /* core3 elr_EL1 bit37 */
			{46832,46,0}, /* core3 elr_EL1 bit38 */
			{46830,46,0}, /* core3 elr_EL1 bit39 */
			{46828,46,0}, /* core3 elr_EL1 bit40 */
			{46818,46,0}, /* core3 elr_EL1 bit41 */
			{46816,46,0}, /* core3 elr_EL1 bit42 */
			{46814,46,0}, /* core3 elr_EL1 bit43 */
			{46812,46,0}, /* core3 elr_EL1 bit44 */
			{46802,46,0}, /* core3 elr_EL1 bit45 */
			{46800,46,0}, /* core3 elr_EL1 bit46 */
			{46798,46,0}, /* core3 elr_EL1 bit47 */
			{46796,46,0}, /* core3 elr_EL1 bit48 */
			{46602,46,0}, /* core3 elr_EL1 bit49 */
			{46594,46,0}, /* core3 elr_EL1 bit50 */
			{46600,46,0}, /* core3 elr_EL1 bit51 */
			{46598,46,0}, /* core3 elr_EL1 bit52 */
			{46592,46,0}, /* core3 elr_EL1 bit53 */
			{46590,46,0}, /* core3 elr_EL1 bit54 */
			{46596,46,0}, /* core3 elr_EL1 bit55 */
			{46588,46,0}, /* core3 elr_EL1 bit56 */
			{46618,46,0}, /* core3 elr_EL1 bit57 */
			{46610,46,0}, /* core3 elr_EL1 bit58 */
			{46608,46,0}, /* core3 elr_EL1 bit59 */
			{46606,46,0}, /* core3 elr_EL1 bit60 */
			{46604,46,0}, /* core3 elr_EL1 bit61 */
			{46616,46,0}, /* core3 elr_EL1 bit62 */
			{46614,46,0}, /* core3 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{46866,46,0}, /* core3 elr_EL2 bit0 */
			{46864,46,0}, /* core3 elr_EL2 bit1 */
			{46894,46,0}, /* core3 elr_EL2 bit2 */
			{46930,46,0}, /* core3 elr_EL2 bit3 */
			{46892,46,0}, /* core3 elr_EL2 bit4 */
			{46858,46,0}, /* core3 elr_EL2 bit5 */
			{46856,46,0}, /* core3 elr_EL2 bit6 */
			{46854,46,0}, /* core3 elr_EL2 bit7 */
			{46862,46,0}, /* core3 elr_EL2 bit8 */
			{46860,46,0}, /* core3 elr_EL2 bit9 */
			{46928,46,0}, /* core3 elr_EL2 bit10 */
			{46962,46,0}, /* core3 elr_EL2 bit11 */
			{46960,46,0}, /* core3 elr_EL2 bit12 */
			{46902,46,0}, /* core3 elr_EL2 bit13 */
			{46898,46,0}, /* core3 elr_EL2 bit14 */
			{46900,46,0}, /* core3 elr_EL2 bit15 */
			{46852,46,0}, /* core3 elr_EL2 bit16 */
			{31860,46,0}, /* core3 elr_EL2 bit17 */
			{46922,46,0}, /* core3 elr_EL2 bit18 */
			{46920,46,0}, /* core3 elr_EL2 bit19 */
			{46918,46,0}, /* core3 elr_EL2 bit20 */
			{46916,46,0}, /* core3 elr_EL2 bit21 */
			{46896,46,0}, /* core3 elr_EL2 bit22 */
			{39150,46,0}, /* core3 elr_EL2 bit23 */
			{46926,46,0}, /* core3 elr_EL2 bit24 */
			{46924,46,0}, /* core3 elr_EL2 bit25 */
			{46938,46,0}, /* core3 elr_EL2 bit26 */
			{39148,46,0}, /* core3 elr_EL2 bit27 */
			{46936,46,0}, /* core3 elr_EL2 bit28 */
			{46934,46,0}, /* core3 elr_EL2 bit29 */
			{46932,46,0}, /* core3 elr_EL2 bit30 */
			{31862,46,0}, /* core3 elr_EL2 bit31 */
			{46782,46,0}, /* core3 elr_EL2 bit32 */
			{46780,46,0}, /* core3 elr_EL2 bit33 */
			{46842,46,0}, /* core3 elr_EL2 bit34 */
			{46840,46,0}, /* core3 elr_EL2 bit35 */
			{46838,46,0}, /* core3 elr_EL2 bit36 */
			{46836,46,0}, /* core3 elr_EL2 bit37 */
			{46826,46,0}, /* core3 elr_EL2 bit38 */
			{46824,46,0}, /* core3 elr_EL2 bit39 */
			{46794,46,0}, /* core3 elr_EL2 bit40 */
			{46822,46,0}, /* core3 elr_EL2 bit41 */
			{46820,46,0}, /* core3 elr_EL2 bit42 */
			{46792,46,0}, /* core3 elr_EL2 bit43 */
			{46810,46,0}, /* core3 elr_EL2 bit44 */
			{46808,46,0}, /* core3 elr_EL2 bit45 */
			{46806,46,0}, /* core3 elr_EL2 bit46 */
			{46804,46,0}, /* core3 elr_EL2 bit47 */
			{46626,46,0}, /* core3 elr_EL2 bit48 */
			{46790,46,0}, /* core3 elr_EL2 bit49 */
			{46788,46,0}, /* core3 elr_EL2 bit50 */
			{46578,46,0}, /* core3 elr_EL2 bit51 */
			{46576,46,0}, /* core3 elr_EL2 bit52 */
			{46574,46,0}, /* core3 elr_EL2 bit53 */
			{46572,46,0}, /* core3 elr_EL2 bit54 */
			{46570,46,0}, /* core3 elr_EL2 bit55 */
			{46568,46,0}, /* core3 elr_EL2 bit56 */
			{46624,46,0}, /* core3 elr_EL2 bit57 */
			{46566,46,0}, /* core3 elr_EL2 bit58 */
			{46564,46,0}, /* core3 elr_EL2 bit59 */
			{46622,46,0}, /* core3 elr_EL2 bit60 */
			{46786,46,0}, /* core3 elr_EL2 bit61 */
			{46784,46,0}, /* core3 elr_EL2 bit62 */
			{46620,46,0}, /* core3 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{39064,46,0}, /* core3 elr_EL3 bit0 */
			{39062,46,0}, /* core3 elr_EL3 bit1 */
			{39100,46,0}, /* core3 elr_EL3 bit2 */
			{39188,46,0}, /* core3 elr_EL3 bit3 */
			{39068,46,0}, /* core3 elr_EL3 bit4 */
			{39066,46,0}, /* core3 elr_EL3 bit5 */
			{39098,46,0}, /* core3 elr_EL3 bit6 */
			{31880,46,0}, /* core3 elr_EL3 bit7 */
			{39060,46,0}, /* core3 elr_EL3 bit8 */
			{39058,46,0}, /* core3 elr_EL3 bit9 */
			{39172,46,0}, /* core3 elr_EL3 bit10 */
			{39186,46,0}, /* core3 elr_EL3 bit11 */
			{39168,46,0}, /* core3 elr_EL3 bit12 */
			{39226,46,0}, /* core3 elr_EL3 bit13 */
			{39112,46,0}, /* core3 elr_EL3 bit14 */
			{39124,46,0}, /* core3 elr_EL3 bit15 */
			{39110,46,0}, /* core3 elr_EL3 bit16 */
			{39116,46,0}, /* core3 elr_EL3 bit17 */
			{31830,46,0}, /* core3 elr_EL3 bit18 */
			{39122,46,0}, /* core3 elr_EL3 bit19 */
			{39170,46,0}, /* core3 elr_EL3 bit20 */
			{39192,46,0}, /* core3 elr_EL3 bit21 */
			{39114,46,0}, /* core3 elr_EL3 bit22 */
			{39190,46,0}, /* core3 elr_EL3 bit23 */
			{31828,46,0}, /* core3 elr_EL3 bit24 */
			{39184,46,0}, /* core3 elr_EL3 bit25 */
			{39182,46,0}, /* core3 elr_EL3 bit26 */
			{39176,46,0}, /* core3 elr_EL3 bit27 */
			{39174,46,0}, /* core3 elr_EL3 bit28 */
			{39180,46,0}, /* core3 elr_EL3 bit29 */
			{39178,46,0}, /* core3 elr_EL3 bit30 */
			{31846,46,0}, /* core3 elr_EL3 bit31 */
			{46078,46,0}, /* core3 elr_EL3 bit32 */
			{39044,46,0}, /* core3 elr_EL3 bit33 */
			{39042,46,0}, /* core3 elr_EL3 bit34 */
			{32156,46,0}, /* core3 elr_EL3 bit35 */
			{32154,46,0}, /* core3 elr_EL3 bit36 */
			{39016,46,0}, /* core3 elr_EL3 bit37 */
			{39014,46,0}, /* core3 elr_EL3 bit38 */
			{39012,46,0}, /* core3 elr_EL3 bit39 */
			{31902,46,0}, /* core3 elr_EL3 bit40 */
			{31920,46,0}, /* core3 elr_EL3 bit41 */
			{39010,46,0}, /* core3 elr_EL3 bit42 */
			{38948,46,0}, /* core3 elr_EL3 bit43 */
			{38952,46,0}, /* core3 elr_EL3 bit44 */
			{38950,46,0}, /* core3 elr_EL3 bit45 */
			{38946,46,0}, /* core3 elr_EL3 bit46 */
			{38944,46,0}, /* core3 elr_EL3 bit47 */
			{38942,46,0}, /* core3 elr_EL3 bit48 */
			{46538,46,0}, /* core3 elr_EL3 bit49 */
			{46586,46,0}, /* core3 elr_EL3 bit50 */
			{46584,46,0}, /* core3 elr_EL3 bit51 */
			{46536,46,0}, /* core3 elr_EL3 bit52 */
			{46534,46,0}, /* core3 elr_EL3 bit53 */
			{46532,46,0}, /* core3 elr_EL3 bit54 */
			{46530,46,0}, /* core3 elr_EL3 bit55 */
			{46528,46,0}, /* core3 elr_EL3 bit56 */
			{46582,46,0}, /* core3 elr_EL3 bit57 */
			{46526,46,0}, /* core3 elr_EL3 bit58 */
			{46524,46,0}, /* core3 elr_EL3 bit59 */
			{46084,46,0}, /* core3 elr_EL3 bit60 */
			{46082,46,0}, /* core3 elr_EL3 bit61 */
			{46080,46,0}, /* core3 elr_EL3 bit62 */
			{46580,46,0}, /* core3 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{44712,46,0}, /* core3 raw_pc bit0 */
			{19018,49,0}, /* core3 raw_pc bit1 */
			{19016,49,0}, /* core3 raw_pc bit2 */
			{19012,49,0}, /* core3 raw_pc bit3 */
			{19014,49,0}, /* core3 raw_pc bit4 */
			{44704,46,0}, /* core3 raw_pc bit5 */
			{44702,46,0}, /* core3 raw_pc bit6 */
			{19158,49,0}, /* core3 raw_pc bit7 */
			{19032,49,0}, /* core3 raw_pc bit8 */
			{19030,49,0}, /* core3 raw_pc bit9 */
			{19028,49,0}, /* core3 raw_pc bit10 */
			{19156,49,0}, /* core3 raw_pc bit11 */
			{19154,49,0}, /* core3 raw_pc bit12 */
			{19152,49,0}, /* core3 raw_pc bit13 */
			{19150,49,0}, /* core3 raw_pc bit14 */
			{19148,49,0}, /* core3 raw_pc bit15 */
			{19146,49,0}, /* core3 raw_pc bit16 */
			{19144,49,0}, /* core3 raw_pc bit17 */
			{19142,49,0}, /* core3 raw_pc bit18 */
			{19060,49,0}, /* core3 raw_pc bit19 */
			{19058,49,0}, /* core3 raw_pc bit20 */
			{19056,49,0}, /* core3 raw_pc bit21 */
			{19054,49,0}, /* core3 raw_pc bit22 */
			{19052,49,0}, /* core3 raw_pc bit23 */
			{19050,49,0}, /* core3 raw_pc bit24 */
			{19048,49,0}, /* core3 raw_pc bit25 */
			{19046,49,0}, /* core3 raw_pc bit26 */
			{19044,49,0}, /* core3 raw_pc bit27 */
			{19042,49,0}, /* core3 raw_pc bit28 */
			{19040,49,0}, /* core3 raw_pc bit29 */
			{19038,49,0}, /* core3 raw_pc bit30 */
			{19010,49,0}, /* core3 raw_pc bit31 */
			{19008,49,0}, /* core3 raw_pc bit32 */
			{19006,49,0}, /* core3 raw_pc bit33 */
			{19004,49,0}, /* core3 raw_pc bit34 */
			{19002,49,0}, /* core3 raw_pc bit35 */
			{19000,49,0}, /* core3 raw_pc bit36 */
			{18998,49,0}, /* core3 raw_pc bit37 */
			{18996,49,0}, /* core3 raw_pc bit38 */
			{18994,49,0}, /* core3 raw_pc bit39 */
			{18992,49,0}, /* core3 raw_pc bit40 */
			{18990,49,0}, /* core3 raw_pc bit41 */
			{18988,49,0}, /* core3 raw_pc bit42 */
			{18982,49,0}, /* core3 raw_pc bit43 */
			{18980,49,0}, /* core3 raw_pc bit44 */
			{18986,49,0}, /* core3 raw_pc bit45 */
			{18984,49,0}, /* core3 raw_pc bit46 */
			{44708,46,0}, /* core3 raw_pc bit47 */
			{44706,46,0}, /* core3 raw_pc bit48 */
			{36762,46,0}, /* core3 raw_pc bit49 */
			{    0, 0,2}, /* core3 raw_pc bit50 */
			{    0, 0,2}, /* core3 raw_pc bit51 */
			{    0, 0,2}, /* core3 raw_pc bit52 */
			{    0, 0,2}, /* core3 raw_pc bit53 */
			{    0, 0,2}, /* core3 raw_pc bit54 */
			{    0, 0,2}, /* core3 raw_pc bit55 */
			{    0, 0,2}, /* core3 raw_pc bit56 */
			{    0, 0,2}, /* core3 raw_pc bit57 */
			{    0, 0,2}, /* core3 raw_pc bit58 */
			{    0, 0,2}, /* core3 raw_pc bit59 */
			{    0, 0,2}, /* core3 raw_pc bit60 */
			{    0, 0,2}, /* core3 raw_pc bit61 */
			{    0, 0,2}, /* core3 raw_pc bit62 */
			{    0, 0,2}, /* core3 raw_pc bit63 */
			}},
			.pc_iss = {{
			{44752,46,0}, /* core3 pc_iss bit0 */
			{44760,46,0}, /* core3 pc_iss bit1 */
			{44758,46,0}, /* core3 pc_iss bit2 */
			{44764,46,0}, /* core3 pc_iss bit3 */
			{44762,46,0}, /* core3 pc_iss bit4 */
			{44750,46,0}, /* core3 pc_iss bit5 */
			{44756,46,0}, /* core3 pc_iss bit6 */
			{44754,46,0}, /* core3 pc_iss bit7 */
			{44768,46,0}, /* core3 pc_iss bit8 */
			{44766,46,0}, /* core3 pc_iss bit9 */
			{44746,46,0}, /* core3 pc_iss bit10 */
			{44744,46,0}, /* core3 pc_iss bit11 */
			{45102,46,0}, /* core3 pc_iss bit12 */
			{45100,46,0}, /* core3 pc_iss bit13 */
			{45098,46,0}, /* core3 pc_iss bit14 */
			{44748,46,0}, /* core3 pc_iss bit15 */
			{45096,46,0}, /* core3 pc_iss bit16 */
			{45090,46,0}, /* core3 pc_iss bit17 */
			{45088,46,0}, /* core3 pc_iss bit18 */
			{45082,46,0}, /* core3 pc_iss bit19 */
			{45080,46,0}, /* core3 pc_iss bit20 */
			{45086,46,0}, /* core3 pc_iss bit21 */
			{45084,46,0}, /* core3 pc_iss bit22 */
			{44782,46,0}, /* core3 pc_iss bit23 */
			{44780,46,0}, /* core3 pc_iss bit24 */
			{36740,46,0}, /* core3 pc_iss bit25 */
			{36738,46,0}, /* core3 pc_iss bit26 */
			{45094,46,0}, /* core3 pc_iss bit27 */
			{45092,46,0}, /* core3 pc_iss bit28 */
			{44742,46,0}, /* core3 pc_iss bit29 */
			{44740,46,0}, /* core3 pc_iss bit30 */
			{44778,46,0}, /* core3 pc_iss bit31 */
			{44700,46,0}, /* core3 pc_iss bit32 */
			{44698,46,0}, /* core3 pc_iss bit33 */
			{44696,46,0}, /* core3 pc_iss bit34 */
			{44694,46,0}, /* core3 pc_iss bit35 */
			{44680,46,0}, /* core3 pc_iss bit36 */
			{44678,46,0}, /* core3 pc_iss bit37 */
			{44692,46,0}, /* core3 pc_iss bit38 */
			{44688,46,0}, /* core3 pc_iss bit39 */
			{44686,46,0}, /* core3 pc_iss bit40 */
			{44684,46,0}, /* core3 pc_iss bit41 */
			{44682,46,0}, /* core3 pc_iss bit42 */
			{44690,46,0}, /* core3 pc_iss bit43 */
			{18930,49,0}, /* core3 pc_iss bit44 */
			{18928,49,0}, /* core3 pc_iss bit45 */
			{18926,49,0}, /* core3 pc_iss bit46 */
			{18924,49,0}, /* core3 pc_iss bit47 */
			{18922,49,0}, /* core3 pc_iss bit48 */
			{18920,49,0}, /* core3 pc_iss bit49 */
			{18918,49,0}, /* core3 pc_iss bit50 */
			{18880,49,0}, /* core3 pc_iss bit51 */
			{18904,49,0}, /* core3 pc_iss bit52 */
			{18902,49,0}, /* core3 pc_iss bit53 */
			{18916,49,0}, /* core3 pc_iss bit54 */
			{18914,49,0}, /* core3 pc_iss bit55 */
			{19026,49,0}, /* core3 pc_iss bit56 */
			{19020,49,0}, /* core3 pc_iss bit57 */
			{19036,49,0}, /* core3 pc_iss bit58 */
			{19034,49,0}, /* core3 pc_iss bit59 */
			{18900,49,0}, /* core3 pc_iss bit60 */
			{18898,49,0}, /* core3 pc_iss bit61 */
			{19024,49,0}, /* core3 pc_iss bit62 */
			{19022,49,0}, /* core3 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{44710,46,0}, /* core3 full_pc_wr bit0 */
			{    0, 0,2}, /* core3 full_pc_wr bit1 */
			{    0, 0,2}, /* core3 full_pc_wr bit2 */
			{    0, 0,2}, /* core3 full_pc_wr bit3 */
			{    0, 0,2}, /* core3 full_pc_wr bit4 */
			{    0, 0,2}, /* core3 full_pc_wr bit5 */
			{    0, 0,2}, /* core3 full_pc_wr bit6 */
			{    0, 0,2}, /* core3 full_pc_wr bit7 */
			{    0, 0,2}, /* core3 full_pc_wr bit8 */
			{    0, 0,2}, /* core3 full_pc_wr bit9 */
			{    0, 0,2}, /* core3 full_pc_wr bit10 */
			{    0, 0,2}, /* core3 full_pc_wr bit11 */
			{    0, 0,2}, /* core3 full_pc_wr bit12 */
			{    0, 0,2}, /* core3 full_pc_wr bit13 */
			{    0, 0,2}, /* core3 full_pc_wr bit14 */
			{    0, 0,2}, /* core3 full_pc_wr bit15 */
			{    0, 0,2}, /* core3 full_pc_wr bit16 */
			{    0, 0,2}, /* core3 full_pc_wr bit17 */
			{    0, 0,2}, /* core3 full_pc_wr bit18 */
			{    0, 0,2}, /* core3 full_pc_wr bit19 */
			{    0, 0,2}, /* core3 full_pc_wr bit20 */
			{    0, 0,2}, /* core3 full_pc_wr bit21 */
			{    0, 0,2}, /* core3 full_pc_wr bit22 */
			{    0, 0,2}, /* core3 full_pc_wr bit23 */
			{    0, 0,2}, /* core3 full_pc_wr bit24 */
			{    0, 0,2}, /* core3 full_pc_wr bit25 */
			{    0, 0,2}, /* core3 full_pc_wr bit26 */
			{    0, 0,2}, /* core3 full_pc_wr bit27 */
			{    0, 0,2}, /* core3 full_pc_wr bit28 */
			{    0, 0,2}, /* core3 full_pc_wr bit29 */
			{    0, 0,2}, /* core3 full_pc_wr bit30 */
			{    0, 0,2}, /* core3 full_pc_wr bit31 */
			{    0, 0,2}, /* core3 full_pc_wr bit32 */
			{    0, 0,2}, /* core3 full_pc_wr bit33 */
			{    0, 0,2}, /* core3 full_pc_wr bit34 */
			{    0, 0,2}, /* core3 full_pc_wr bit35 */
			{    0, 0,2}, /* core3 full_pc_wr bit36 */
			{    0, 0,2}, /* core3 full_pc_wr bit37 */
			{    0, 0,2}, /* core3 full_pc_wr bit38 */
			{    0, 0,2}, /* core3 full_pc_wr bit39 */
			{    0, 0,2}, /* core3 full_pc_wr bit40 */
			{    0, 0,2}, /* core3 full_pc_wr bit41 */
			{    0, 0,2}, /* core3 full_pc_wr bit42 */
			{    0, 0,2}, /* core3 full_pc_wr bit43 */
			{    0, 0,2}, /* core3 full_pc_wr bit44 */
			{    0, 0,2}, /* core3 full_pc_wr bit45 */
			{    0, 0,2}, /* core3 full_pc_wr bit46 */
			{    0, 0,2}, /* core3 full_pc_wr bit47 */
			{    0, 0,2}, /* core3 full_pc_wr bit48 */
			{    0, 0,2}, /* core3 full_pc_wr bit49 */
			{    0, 0,2}, /* core3 full_pc_wr bit50 */
			{    0, 0,2}, /* core3 full_pc_wr bit51 */
			{    0, 0,2}, /* core3 full_pc_wr bit52 */
			{    0, 0,2}, /* core3 full_pc_wr bit53 */
			{    0, 0,2}, /* core3 full_pc_wr bit54 */
			{    0, 0,2}, /* core3 full_pc_wr bit55 */
			{    0, 0,2}, /* core3 full_pc_wr bit56 */
			{    0, 0,2}, /* core3 full_pc_wr bit57 */
			{    0, 0,2}, /* core3 full_pc_wr bit58 */
			{    0, 0,2}, /* core3 full_pc_wr bit59 */
			{    0, 0,2}, /* core3 full_pc_wr bit60 */
			{    0, 0,2}, /* core3 full_pc_wr bit61 */
			{    0, 0,2}, /* core3 full_pc_wr bit62 */
			{    0, 0,2}, /* core3 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{37250,46,0}, /* core3 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core3 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{44772,46,0}, /* core3 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core3 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{ 7874,47,0}, /* core3 return_Stack_pointer bit0 */
			{ 7872,47,0}, /* core3 return_Stack_pointer bit1 */
			{ 7878,47,0}, /* core3 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core3 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{19482,47,0}, /* core3 return_Stack0 bit0 */
			{19480,47,0}, /* core3 return_Stack0 bit1 */
			{19478,47,0}, /* core3 return_Stack0 bit2 */
			{19476,47,0}, /* core3 return_Stack0 bit3 */
			{19266,47,0}, /* core3 return_Stack0 bit4 */
			{19264,47,0}, /* core3 return_Stack0 bit5 */
			{19262,47,0}, /* core3 return_Stack0 bit6 */
			{19260,47,0}, /* core3 return_Stack0 bit7 */
			{19274,47,0}, /* core3 return_Stack0 bit8 */
			{19272,47,0}, /* core3 return_Stack0 bit9 */
			{19270,47,0}, /* core3 return_Stack0 bit10 */
			{ 7838,47,0}, /* core3 return_Stack0 bit11 */
			{19268,47,0}, /* core3 return_Stack0 bit12 */
			{19250,47,0}, /* core3 return_Stack0 bit13 */
			{19248,47,0}, /* core3 return_Stack0 bit14 */
			{19246,47,0}, /* core3 return_Stack0 bit15 */
			{19244,47,0}, /* core3 return_Stack0 bit16 */
			{19442,47,0}, /* core3 return_Stack0 bit17 */
			{ 7836,47,0}, /* core3 return_Stack0 bit18 */
			{ 3022,47,0}, /* core3 return_Stack0 bit19 */
			{19440,47,0}, /* core3 return_Stack0 bit20 */
			{19438,47,0}, /* core3 return_Stack0 bit21 */
			{19436,47,0}, /* core3 return_Stack0 bit22 */
			{19426,47,0}, /* core3 return_Stack0 bit23 */
			{19424,47,0}, /* core3 return_Stack0 bit24 */
			{19422,47,0}, /* core3 return_Stack0 bit25 */
			{19420,47,0}, /* core3 return_Stack0 bit26 */
			{19434,47,0}, /* core3 return_Stack0 bit27 */
			{19432,47,0}, /* core3 return_Stack0 bit28 */
			{19430,47,0}, /* core3 return_Stack0 bit29 */
			{19428,47,0}, /* core3 return_Stack0 bit30 */
			{19394,47,0}, /* core3 return_Stack0 bit31 */
			{19392,47,0}, /* core3 return_Stack0 bit32 */
			{19390,47,0}, /* core3 return_Stack0 bit33 */
			{19388,47,0}, /* core3 return_Stack0 bit34 */
			{19378,47,0}, /* core3 return_Stack0 bit35 */
			{19376,47,0}, /* core3 return_Stack0 bit36 */
			{19374,47,0}, /* core3 return_Stack0 bit37 */
			{19372,47,0}, /* core3 return_Stack0 bit38 */
			{19362,47,0}, /* core3 return_Stack0 bit39 */
			{19360,47,0}, /* core3 return_Stack0 bit40 */
			{19358,47,0}, /* core3 return_Stack0 bit41 */
			{19356,47,0}, /* core3 return_Stack0 bit42 */
			{19498,47,0}, /* core3 return_Stack0 bit43 */
			{19496,47,0}, /* core3 return_Stack0 bit44 */
			{19494,47,0}, /* core3 return_Stack0 bit45 */
			{19492,47,0}, /* core3 return_Stack0 bit46 */
			{ 7846,47,0}, /* core3 return_Stack0 bit47 */
			{ 7844,47,0}, /* core3 return_Stack0 bit48 */
			{    0, 0,2}, /* core3 return_Stack0 bit49 */
			{    0, 0,2}, /* core3 return_Stack0 bit50 */
			{    0, 0,2}, /* core3 return_Stack0 bit51 */
			{    0, 0,2}, /* core3 return_Stack0 bit52 */
			{    0, 0,2}, /* core3 return_Stack0 bit53 */
			{    0, 0,2}, /* core3 return_Stack0 bit54 */
			{    0, 0,2}, /* core3 return_Stack0 bit55 */
			{    0, 0,2}, /* core3 return_Stack0 bit56 */
			{    0, 0,2}, /* core3 return_Stack0 bit57 */
			{    0, 0,2}, /* core3 return_Stack0 bit58 */
			{    0, 0,2}, /* core3 return_Stack0 bit59 */
			{    0, 0,2}, /* core3 return_Stack0 bit60 */
			{    0, 0,2}, /* core3 return_Stack0 bit61 */
			{    0, 0,2}, /* core3 return_Stack0 bit62 */
			{    0, 0,2}, /* core3 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{19490,47,0}, /* core3 return_Stack1 bit0 */
			{19488,47,0}, /* core3 return_Stack1 bit1 */
			{19486,47,0}, /* core3 return_Stack1 bit2 */
			{19484,47,0}, /* core3 return_Stack1 bit3 */
			{19242,47,0}, /* core3 return_Stack1 bit4 */
			{19240,47,0}, /* core3 return_Stack1 bit5 */
			{19466,47,0}, /* core3 return_Stack1 bit6 */
			{19238,47,0}, /* core3 return_Stack1 bit7 */
			{19236,47,0}, /* core3 return_Stack1 bit8 */
			{19258,47,0}, /* core3 return_Stack1 bit9 */
			{19256,47,0}, /* core3 return_Stack1 bit10 */
			{19464,47,0}, /* core3 return_Stack1 bit11 */
			{19254,47,0}, /* core3 return_Stack1 bit12 */
			{19252,47,0}, /* core3 return_Stack1 bit13 */
			{19474,47,0}, /* core3 return_Stack1 bit14 */
			{19472,47,0}, /* core3 return_Stack1 bit15 */
			{19470,47,0}, /* core3 return_Stack1 bit16 */
			{19468,47,0}, /* core3 return_Stack1 bit17 */
			{19462,47,0}, /* core3 return_Stack1 bit18 */
			{19460,47,0}, /* core3 return_Stack1 bit19 */
			{19410,47,0}, /* core3 return_Stack1 bit20 */
			{19408,47,0}, /* core3 return_Stack1 bit21 */
			{19406,47,0}, /* core3 return_Stack1 bit22 */
			{19404,47,0}, /* core3 return_Stack1 bit23 */
			{19418,47,0}, /* core3 return_Stack1 bit24 */
			{19416,47,0}, /* core3 return_Stack1 bit25 */
			{19414,47,0}, /* core3 return_Stack1 bit26 */
			{19412,47,0}, /* core3 return_Stack1 bit27 */
			{19402,47,0}, /* core3 return_Stack1 bit28 */
			{19400,47,0}, /* core3 return_Stack1 bit29 */
			{19398,47,0}, /* core3 return_Stack1 bit30 */
			{19396,47,0}, /* core3 return_Stack1 bit31 */
			{19386,47,0}, /* core3 return_Stack1 bit32 */
			{19384,47,0}, /* core3 return_Stack1 bit33 */
			{19382,47,0}, /* core3 return_Stack1 bit34 */
			{19380,47,0}, /* core3 return_Stack1 bit35 */
			{19370,47,0}, /* core3 return_Stack1 bit36 */
			{19368,47,0}, /* core3 return_Stack1 bit37 */
			{19366,47,0}, /* core3 return_Stack1 bit38 */
			{19364,47,0}, /* core3 return_Stack1 bit39 */
			{19354,47,0}, /* core3 return_Stack1 bit40 */
			{19346,47,0}, /* core3 return_Stack1 bit41 */
			{19344,47,0}, /* core3 return_Stack1 bit42 */
			{19352,47,0}, /* core3 return_Stack1 bit43 */
			{19350,47,0}, /* core3 return_Stack1 bit44 */
			{19342,47,0}, /* core3 return_Stack1 bit45 */
			{19348,47,0}, /* core3 return_Stack1 bit46 */
			{19340,47,0}, /* core3 return_Stack1 bit47 */
			{ 3024,47,0}, /* core3 return_Stack1 bit48 */
			{    0, 0,2}, /* core3 return_Stack1 bit49 */
			{    0, 0,2}, /* core3 return_Stack1 bit50 */
			{    0, 0,2}, /* core3 return_Stack1 bit51 */
			{    0, 0,2}, /* core3 return_Stack1 bit52 */
			{    0, 0,2}, /* core3 return_Stack1 bit53 */
			{    0, 0,2}, /* core3 return_Stack1 bit54 */
			{    0, 0,2}, /* core3 return_Stack1 bit55 */
			{    0, 0,2}, /* core3 return_Stack1 bit56 */
			{    0, 0,2}, /* core3 return_Stack1 bit57 */
			{    0, 0,2}, /* core3 return_Stack1 bit58 */
			{    0, 0,2}, /* core3 return_Stack1 bit59 */
			{    0, 0,2}, /* core3 return_Stack1 bit60 */
			{    0, 0,2}, /* core3 return_Stack1 bit61 */
			{    0, 0,2}, /* core3 return_Stack1 bit62 */
			{    0, 0,2}, /* core3 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{ 7850,47,0}, /* core3 return_Stack2 bit0 */
			{19282,47,0}, /* core3 return_Stack2 bit1 */
			{ 7848,47,0}, /* core3 return_Stack2 bit2 */
			{19280,47,0}, /* core3 return_Stack2 bit3 */
			{19278,47,0}, /* core3 return_Stack2 bit4 */
			{19234,47,0}, /* core3 return_Stack2 bit5 */
			{19276,47,0}, /* core3 return_Stack2 bit6 */
			{ 3028,47,0}, /* core3 return_Stack2 bit7 */
			{19232,47,0}, /* core3 return_Stack2 bit8 */
			{19230,47,0}, /* core3 return_Stack2 bit9 */
			{19218,47,0}, /* core3 return_Stack2 bit10 */
			{19228,47,0}, /* core3 return_Stack2 bit11 */
			{19216,47,0}, /* core3 return_Stack2 bit12 */
			{ 7834,47,0}, /* core3 return_Stack2 bit13 */
			{19214,47,0}, /* core3 return_Stack2 bit14 */
			{ 7832,47,0}, /* core3 return_Stack2 bit15 */
			{19212,47,0}, /* core3 return_Stack2 bit16 */
			{19202,47,0}, /* core3 return_Stack2 bit17 */
			{19200,47,0}, /* core3 return_Stack2 bit18 */
			{19198,47,0}, /* core3 return_Stack2 bit19 */
			{19196,47,0}, /* core3 return_Stack2 bit20 */
			{19178,47,0}, /* core3 return_Stack2 bit21 */
			{19176,47,0}, /* core3 return_Stack2 bit22 */
			{19174,47,0}, /* core3 return_Stack2 bit23 */
			{19172,47,0}, /* core3 return_Stack2 bit24 */
			{19170,47,0}, /* core3 return_Stack2 bit25 */
			{19168,47,0}, /* core3 return_Stack2 bit26 */
			{19166,47,0}, /* core3 return_Stack2 bit27 */
			{19164,47,0}, /* core3 return_Stack2 bit28 */
			{19138,47,0}, /* core3 return_Stack2 bit29 */
			{19136,47,0}, /* core3 return_Stack2 bit30 */
			{19134,47,0}, /* core3 return_Stack2 bit31 */
			{19132,47,0}, /* core3 return_Stack2 bit32 */
			{19538,47,0}, /* core3 return_Stack2 bit33 */
			{19536,47,0}, /* core3 return_Stack2 bit34 */
			{19534,47,0}, /* core3 return_Stack2 bit35 */
			{19532,47,0}, /* core3 return_Stack2 bit36 */
			{19522,47,0}, /* core3 return_Stack2 bit37 */
			{19520,47,0}, /* core3 return_Stack2 bit38 */
			{19518,47,0}, /* core3 return_Stack2 bit39 */
			{19516,47,0}, /* core3 return_Stack2 bit40 */
			{19514,47,0}, /* core3 return_Stack2 bit41 */
			{19512,47,0}, /* core3 return_Stack2 bit42 */
			{19510,47,0}, /* core3 return_Stack2 bit43 */
			{19508,47,0}, /* core3 return_Stack2 bit44 */
			{19338,47,0}, /* core3 return_Stack2 bit45 */
			{19336,47,0}, /* core3 return_Stack2 bit46 */
			{19334,47,0}, /* core3 return_Stack2 bit47 */
			{19332,47,0}, /* core3 return_Stack2 bit48 */
			{    0, 0,2}, /* core3 return_Stack2 bit49 */
			{    0, 0,2}, /* core3 return_Stack2 bit50 */
			{    0, 0,2}, /* core3 return_Stack2 bit51 */
			{    0, 0,2}, /* core3 return_Stack2 bit52 */
			{    0, 0,2}, /* core3 return_Stack2 bit53 */
			{    0, 0,2}, /* core3 return_Stack2 bit54 */
			{    0, 0,2}, /* core3 return_Stack2 bit55 */
			{    0, 0,2}, /* core3 return_Stack2 bit56 */
			{    0, 0,2}, /* core3 return_Stack2 bit57 */
			{    0, 0,2}, /* core3 return_Stack2 bit58 */
			{    0, 0,2}, /* core3 return_Stack2 bit59 */
			{    0, 0,2}, /* core3 return_Stack2 bit60 */
			{    0, 0,2}, /* core3 return_Stack2 bit61 */
			{    0, 0,2}, /* core3 return_Stack2 bit62 */
			{    0, 0,2}, /* core3 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{ 3030,47,0}, /* core3 return_Stack3 bit0 */
			{19322,47,0}, /* core3 return_Stack3 bit1 */
			{19320,47,0}, /* core3 return_Stack3 bit2 */
			{19318,47,0}, /* core3 return_Stack3 bit3 */
			{19316,47,0}, /* core3 return_Stack3 bit4 */
			{19290,47,0}, /* core3 return_Stack3 bit5 */
			{19288,47,0}, /* core3 return_Stack3 bit6 */
			{19286,47,0}, /* core3 return_Stack3 bit7 */
			{19284,47,0}, /* core3 return_Stack3 bit8 */
			{19226,47,0}, /* core3 return_Stack3 bit9 */
			{19224,47,0}, /* core3 return_Stack3 bit10 */
			{19222,47,0}, /* core3 return_Stack3 bit11 */
			{19220,47,0}, /* core3 return_Stack3 bit12 */
			{19210,47,0}, /* core3 return_Stack3 bit13 */
			{19208,47,0}, /* core3 return_Stack3 bit14 */
			{19206,47,0}, /* core3 return_Stack3 bit15 */
			{19204,47,0}, /* core3 return_Stack3 bit16 */
			{19194,47,0}, /* core3 return_Stack3 bit17 */
			{19192,47,0}, /* core3 return_Stack3 bit18 */
			{19190,47,0}, /* core3 return_Stack3 bit19 */
			{19188,47,0}, /* core3 return_Stack3 bit20 */
			{19186,47,0}, /* core3 return_Stack3 bit21 */
			{19184,47,0}, /* core3 return_Stack3 bit22 */
			{19182,47,0}, /* core3 return_Stack3 bit23 */
			{19180,47,0}, /* core3 return_Stack3 bit24 */
			{19162,47,0}, /* core3 return_Stack3 bit25 */
			{19160,47,0}, /* core3 return_Stack3 bit26 */
			{19158,47,0}, /* core3 return_Stack3 bit27 */
			{19156,47,0}, /* core3 return_Stack3 bit28 */
			{19130,47,0}, /* core3 return_Stack3 bit29 */
			{19128,47,0}, /* core3 return_Stack3 bit30 */
			{19126,47,0}, /* core3 return_Stack3 bit31 */
			{19124,47,0}, /* core3 return_Stack3 bit32 */
			{19546,47,0}, /* core3 return_Stack3 bit33 */
			{19544,47,0}, /* core3 return_Stack3 bit34 */
			{19542,47,0}, /* core3 return_Stack3 bit35 */
			{19540,47,0}, /* core3 return_Stack3 bit36 */
			{19530,47,0}, /* core3 return_Stack3 bit37 */
			{19528,47,0}, /* core3 return_Stack3 bit38 */
			{19526,47,0}, /* core3 return_Stack3 bit39 */
			{19524,47,0}, /* core3 return_Stack3 bit40 */
			{19506,47,0}, /* core3 return_Stack3 bit41 */
			{19504,47,0}, /* core3 return_Stack3 bit42 */
			{19502,47,0}, /* core3 return_Stack3 bit43 */
			{19500,47,0}, /* core3 return_Stack3 bit44 */
			{19330,47,0}, /* core3 return_Stack3 bit45 */
			{19328,47,0}, /* core3 return_Stack3 bit46 */
			{19326,47,0}, /* core3 return_Stack3 bit47 */
			{19324,47,0}, /* core3 return_Stack3 bit48 */
			{    0, 0,2}, /* core3 return_Stack3 bit49 */
			{    0, 0,2}, /* core3 return_Stack3 bit50 */
			{    0, 0,2}, /* core3 return_Stack3 bit51 */
			{    0, 0,2}, /* core3 return_Stack3 bit52 */
			{    0, 0,2}, /* core3 return_Stack3 bit53 */
			{    0, 0,2}, /* core3 return_Stack3 bit54 */
			{    0, 0,2}, /* core3 return_Stack3 bit55 */
			{    0, 0,2}, /* core3 return_Stack3 bit56 */
			{    0, 0,2}, /* core3 return_Stack3 bit57 */
			{    0, 0,2}, /* core3 return_Stack3 bit58 */
			{    0, 0,2}, /* core3 return_Stack3 bit59 */
			{    0, 0,2}, /* core3 return_Stack3 bit60 */
			{    0, 0,2}, /* core3 return_Stack3 bit61 */
			{    0, 0,2}, /* core3 return_Stack3 bit62 */
			{    0, 0,2}, /* core3 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{19314,47,0}, /* core3 return_Stack4 bit0 */
			{19312,47,0}, /* core3 return_Stack4 bit1 */
			{19310,47,0}, /* core3 return_Stack4 bit2 */
			{19308,47,0}, /* core3 return_Stack4 bit3 */
			{19306,47,0}, /* core3 return_Stack4 bit4 */
			{19304,47,0}, /* core3 return_Stack4 bit5 */
			{19302,47,0}, /* core3 return_Stack4 bit6 */
			{19300,47,0}, /* core3 return_Stack4 bit7 */
			{19298,47,0}, /* core3 return_Stack4 bit8 */
			{19296,47,0}, /* core3 return_Stack4 bit9 */
			{19294,47,0}, /* core3 return_Stack4 bit10 */
			{19292,47,0}, /* core3 return_Stack4 bit11 */
			{19458,47,0}, /* core3 return_Stack4 bit12 */
			{ 7842,47,0}, /* core3 return_Stack4 bit13 */
			{19456,47,0}, /* core3 return_Stack4 bit14 */
			{ 7840,47,0}, /* core3 return_Stack4 bit15 */
			{19454,47,0}, /* core3 return_Stack4 bit16 */
			{19452,47,0}, /* core3 return_Stack4 bit17 */
			{19450,47,0}, /* core3 return_Stack4 bit18 */
			{19448,47,0}, /* core3 return_Stack4 bit19 */
			{19446,47,0}, /* core3 return_Stack4 bit20 */
			{19444,47,0}, /* core3 return_Stack4 bit21 */
			{19146,47,0}, /* core3 return_Stack4 bit22 */
			{19144,47,0}, /* core3 return_Stack4 bit23 */
			{19142,47,0}, /* core3 return_Stack4 bit24 */
			{19140,47,0}, /* core3 return_Stack4 bit25 */
			{19154,47,0}, /* core3 return_Stack4 bit26 */
			{19152,47,0}, /* core3 return_Stack4 bit27 */
			{19150,47,0}, /* core3 return_Stack4 bit28 */
			{19148,47,0}, /* core3 return_Stack4 bit29 */
			{19122,47,0}, /* core3 return_Stack4 bit30 */
			{19120,47,0}, /* core3 return_Stack4 bit31 */
			{19118,47,0}, /* core3 return_Stack4 bit32 */
			{19116,47,0}, /* core3 return_Stack4 bit33 */
			{19114,47,0}, /* core3 return_Stack4 bit34 */
			{19112,47,0}, /* core3 return_Stack4 bit35 */
			{19110,47,0}, /* core3 return_Stack4 bit36 */
			{19108,47,0}, /* core3 return_Stack4 bit37 */
			{19046,47,0}, /* core3 return_Stack4 bit38 */
			{19044,47,0}, /* core3 return_Stack4 bit39 */
			{19042,47,0}, /* core3 return_Stack4 bit40 */
			{19040,47,0}, /* core3 return_Stack4 bit41 */
			{19054,47,0}, /* core3 return_Stack4 bit42 */
			{19052,47,0}, /* core3 return_Stack4 bit43 */
			{19050,47,0}, /* core3 return_Stack4 bit44 */
			{19048,47,0}, /* core3 return_Stack4 bit45 */
			{ 7854,47,0}, /* core3 return_Stack4 bit46 */
			{ 7852,47,0}, /* core3 return_Stack4 bit47 */
			{ 3026,47,0}, /* core3 return_Stack4 bit48 */
			{    0, 0,2}, /* core3 return_Stack4 bit49 */
			{    0, 0,2}, /* core3 return_Stack4 bit50 */
			{    0, 0,2}, /* core3 return_Stack4 bit51 */
			{    0, 0,2}, /* core3 return_Stack4 bit52 */
			{    0, 0,2}, /* core3 return_Stack4 bit53 */
			{    0, 0,2}, /* core3 return_Stack4 bit54 */
			{    0, 0,2}, /* core3 return_Stack4 bit55 */
			{    0, 0,2}, /* core3 return_Stack4 bit56 */
			{    0, 0,2}, /* core3 return_Stack4 bit57 */
			{    0, 0,2}, /* core3 return_Stack4 bit58 */
			{    0, 0,2}, /* core3 return_Stack4 bit59 */
			{    0, 0,2}, /* core3 return_Stack4 bit60 */
			{    0, 0,2}, /* core3 return_Stack4 bit61 */
			{    0, 0,2}, /* core3 return_Stack4 bit62 */
			{    0, 0,2}, /* core3 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{18982,47,0}, /* core3 return_Stack5 bit0 */
			{18980,47,0}, /* core3 return_Stack5 bit1 */
			{18978,47,0}, /* core3 return_Stack5 bit2 */
			{18976,47,0}, /* core3 return_Stack5 bit3 */
			{18958,47,0}, /* core3 return_Stack5 bit4 */
			{18942,47,0}, /* core3 return_Stack5 bit5 */
			{18956,47,0}, /* core3 return_Stack5 bit6 */
			{18954,47,0}, /* core3 return_Stack5 bit7 */
			{18952,47,0}, /* core3 return_Stack5 bit8 */
			{18940,47,0}, /* core3 return_Stack5 bit9 */
			{18938,47,0}, /* core3 return_Stack5 bit10 */
			{18936,47,0}, /* core3 return_Stack5 bit11 */
			{18918,47,0}, /* core3 return_Stack5 bit12 */
			{18916,47,0}, /* core3 return_Stack5 bit13 */
			{18914,47,0}, /* core3 return_Stack5 bit14 */
			{18912,47,0}, /* core3 return_Stack5 bit15 */
			{18886,47,0}, /* core3 return_Stack5 bit16 */
			{18884,47,0}, /* core3 return_Stack5 bit17 */
			{18882,47,0}, /* core3 return_Stack5 bit18 */
			{18880,47,0}, /* core3 return_Stack5 bit19 */
			{18838,47,0}, /* core3 return_Stack5 bit20 */
			{18836,47,0}, /* core3 return_Stack5 bit21 */
			{18834,47,0}, /* core3 return_Stack5 bit22 */
			{18832,47,0}, /* core3 return_Stack5 bit23 */
			{18830,47,0}, /* core3 return_Stack5 bit24 */
			{18828,47,0}, /* core3 return_Stack5 bit25 */
			{18826,47,0}, /* core3 return_Stack5 bit26 */
			{18824,47,0}, /* core3 return_Stack5 bit27 */
			{19014,47,0}, /* core3 return_Stack5 bit28 */
			{19012,47,0}, /* core3 return_Stack5 bit29 */
			{19010,47,0}, /* core3 return_Stack5 bit30 */
			{19008,47,0}, /* core3 return_Stack5 bit31 */
			{19022,47,0}, /* core3 return_Stack5 bit32 */
			{ 7894,47,0}, /* core3 return_Stack5 bit33 */
			{19020,47,0}, /* core3 return_Stack5 bit34 */
			{19018,47,0}, /* core3 return_Stack5 bit35 */
			{19016,47,0}, /* core3 return_Stack5 bit36 */
			{ 7892,47,0}, /* core3 return_Stack5 bit37 */
			{19086,47,0}, /* core3 return_Stack5 bit38 */
			{19084,47,0}, /* core3 return_Stack5 bit39 */
			{19082,47,0}, /* core3 return_Stack5 bit40 */
			{19080,47,0}, /* core3 return_Stack5 bit41 */
			{19062,47,0}, /* core3 return_Stack5 bit42 */
			{19060,47,0}, /* core3 return_Stack5 bit43 */
			{19058,47,0}, /* core3 return_Stack5 bit44 */
			{19056,47,0}, /* core3 return_Stack5 bit45 */
			{ 7862,47,0}, /* core3 return_Stack5 bit46 */
			{ 7860,47,0}, /* core3 return_Stack5 bit47 */
			{ 3034,47,0}, /* core3 return_Stack5 bit48 */
			{    0, 0,2}, /* core3 return_Stack5 bit49 */
			{    0, 0,2}, /* core3 return_Stack5 bit50 */
			{    0, 0,2}, /* core3 return_Stack5 bit51 */
			{    0, 0,2}, /* core3 return_Stack5 bit52 */
			{    0, 0,2}, /* core3 return_Stack5 bit53 */
			{    0, 0,2}, /* core3 return_Stack5 bit54 */
			{    0, 0,2}, /* core3 return_Stack5 bit55 */
			{    0, 0,2}, /* core3 return_Stack5 bit56 */
			{    0, 0,2}, /* core3 return_Stack5 bit57 */
			{    0, 0,2}, /* core3 return_Stack5 bit58 */
			{    0, 0,2}, /* core3 return_Stack5 bit59 */
			{    0, 0,2}, /* core3 return_Stack5 bit60 */
			{    0, 0,2}, /* core3 return_Stack5 bit61 */
			{    0, 0,2}, /* core3 return_Stack5 bit62 */
			{    0, 0,2}, /* core3 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{18990,47,0}, /* core3 return_Stack6 bit0 */
			{18988,47,0}, /* core3 return_Stack6 bit1 */
			{18986,47,0}, /* core3 return_Stack6 bit2 */
			{18984,47,0}, /* core3 return_Stack6 bit3 */
			{18950,47,0}, /* core3 return_Stack6 bit4 */
			{18926,47,0}, /* core3 return_Stack6 bit5 */
			{18948,47,0}, /* core3 return_Stack6 bit6 */
			{18946,47,0}, /* core3 return_Stack6 bit7 */
			{18944,47,0}, /* core3 return_Stack6 bit8 */
			{18924,47,0}, /* core3 return_Stack6 bit9 */
			{18922,47,0}, /* core3 return_Stack6 bit10 */
			{18920,47,0}, /* core3 return_Stack6 bit11 */
			{18902,47,0}, /* core3 return_Stack6 bit12 */
			{18900,47,0}, /* core3 return_Stack6 bit13 */
			{18898,47,0}, /* core3 return_Stack6 bit14 */
			{18896,47,0}, /* core3 return_Stack6 bit15 */
			{18894,47,0}, /* core3 return_Stack6 bit16 */
			{18892,47,0}, /* core3 return_Stack6 bit17 */
			{18890,47,0}, /* core3 return_Stack6 bit18 */
			{18888,47,0}, /* core3 return_Stack6 bit19 */
			{18862,47,0}, /* core3 return_Stack6 bit20 */
			{18860,47,0}, /* core3 return_Stack6 bit21 */
			{18858,47,0}, /* core3 return_Stack6 bit22 */
			{18856,47,0}, /* core3 return_Stack6 bit23 */
			{18846,47,0}, /* core3 return_Stack6 bit24 */
			{18844,47,0}, /* core3 return_Stack6 bit25 */
			{18842,47,0}, /* core3 return_Stack6 bit26 */
			{18840,47,0}, /* core3 return_Stack6 bit27 */
			{19006,47,0}, /* core3 return_Stack6 bit28 */
			{19004,47,0}, /* core3 return_Stack6 bit29 */
			{19002,47,0}, /* core3 return_Stack6 bit30 */
			{19000,47,0}, /* core3 return_Stack6 bit31 */
			{19030,47,0}, /* core3 return_Stack6 bit32 */
			{ 7886,47,0}, /* core3 return_Stack6 bit33 */
			{19028,47,0}, /* core3 return_Stack6 bit34 */
			{19026,47,0}, /* core3 return_Stack6 bit35 */
			{19024,47,0}, /* core3 return_Stack6 bit36 */
			{ 7884,47,0}, /* core3 return_Stack6 bit37 */
			{19102,47,0}, /* core3 return_Stack6 bit38 */
			{19100,47,0}, /* core3 return_Stack6 bit39 */
			{19098,47,0}, /* core3 return_Stack6 bit40 */
			{19096,47,0}, /* core3 return_Stack6 bit41 */
			{19070,47,0}, /* core3 return_Stack6 bit42 */
			{19068,47,0}, /* core3 return_Stack6 bit43 */
			{19066,47,0}, /* core3 return_Stack6 bit44 */
			{19064,47,0}, /* core3 return_Stack6 bit45 */
			{ 7866,47,0}, /* core3 return_Stack6 bit46 */
			{ 7864,47,0}, /* core3 return_Stack6 bit47 */
			{ 3036,47,0}, /* core3 return_Stack6 bit48 */
			{    0, 0,2}, /* core3 return_Stack6 bit49 */
			{    0, 0,2}, /* core3 return_Stack6 bit50 */
			{    0, 0,2}, /* core3 return_Stack6 bit51 */
			{    0, 0,2}, /* core3 return_Stack6 bit52 */
			{    0, 0,2}, /* core3 return_Stack6 bit53 */
			{    0, 0,2}, /* core3 return_Stack6 bit54 */
			{    0, 0,2}, /* core3 return_Stack6 bit55 */
			{    0, 0,2}, /* core3 return_Stack6 bit56 */
			{    0, 0,2}, /* core3 return_Stack6 bit57 */
			{    0, 0,2}, /* core3 return_Stack6 bit58 */
			{    0, 0,2}, /* core3 return_Stack6 bit59 */
			{    0, 0,2}, /* core3 return_Stack6 bit60 */
			{    0, 0,2}, /* core3 return_Stack6 bit61 */
			{    0, 0,2}, /* core3 return_Stack6 bit62 */
			{    0, 0,2}, /* core3 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{18974,47,0}, /* core3 return_Stack7 bit0 */
			{18972,47,0}, /* core3 return_Stack7 bit1 */
			{18970,47,0}, /* core3 return_Stack7 bit2 */
			{18968,47,0}, /* core3 return_Stack7 bit3 */
			{18966,47,0}, /* core3 return_Stack7 bit4 */
			{18934,47,0}, /* core3 return_Stack7 bit5 */
			{18964,47,0}, /* core3 return_Stack7 bit6 */
			{18962,47,0}, /* core3 return_Stack7 bit7 */
			{18960,47,0}, /* core3 return_Stack7 bit8 */
			{18932,47,0}, /* core3 return_Stack7 bit9 */
			{18930,47,0}, /* core3 return_Stack7 bit10 */
			{18928,47,0}, /* core3 return_Stack7 bit11 */
			{18910,47,0}, /* core3 return_Stack7 bit12 */
			{18908,47,0}, /* core3 return_Stack7 bit13 */
			{18906,47,0}, /* core3 return_Stack7 bit14 */
			{18904,47,0}, /* core3 return_Stack7 bit15 */
			{18878,47,0}, /* core3 return_Stack7 bit16 */
			{18876,47,0}, /* core3 return_Stack7 bit17 */
			{18874,47,0}, /* core3 return_Stack7 bit18 */
			{18872,47,0}, /* core3 return_Stack7 bit19 */
			{18870,47,0}, /* core3 return_Stack7 bit20 */
			{18868,47,0}, /* core3 return_Stack7 bit21 */
			{18866,47,0}, /* core3 return_Stack7 bit22 */
			{18864,47,0}, /* core3 return_Stack7 bit23 */
			{18854,47,0}, /* core3 return_Stack7 bit24 */
			{18852,47,0}, /* core3 return_Stack7 bit25 */
			{18850,47,0}, /* core3 return_Stack7 bit26 */
			{18848,47,0}, /* core3 return_Stack7 bit27 */
			{18998,47,0}, /* core3 return_Stack7 bit28 */
			{18996,47,0}, /* core3 return_Stack7 bit29 */
			{18994,47,0}, /* core3 return_Stack7 bit30 */
			{18992,47,0}, /* core3 return_Stack7 bit31 */
			{19038,47,0}, /* core3 return_Stack7 bit32 */
			{ 7890,47,0}, /* core3 return_Stack7 bit33 */
			{19036,47,0}, /* core3 return_Stack7 bit34 */
			{19034,47,0}, /* core3 return_Stack7 bit35 */
			{19032,47,0}, /* core3 return_Stack7 bit36 */
			{ 7888,47,0}, /* core3 return_Stack7 bit37 */
			{19094,47,0}, /* core3 return_Stack7 bit38 */
			{19092,47,0}, /* core3 return_Stack7 bit39 */
			{19090,47,0}, /* core3 return_Stack7 bit40 */
			{19088,47,0}, /* core3 return_Stack7 bit41 */
			{19078,47,0}, /* core3 return_Stack7 bit42 */
			{19076,47,0}, /* core3 return_Stack7 bit43 */
			{19074,47,0}, /* core3 return_Stack7 bit44 */
			{19072,47,0}, /* core3 return_Stack7 bit45 */
			{ 7858,47,0}, /* core3 return_Stack7 bit46 */
			{ 7856,47,0}, /* core3 return_Stack7 bit47 */
			{ 3032,47,0}, /* core3 return_Stack7 bit48 */
			{    0, 0,2}, /* core3 return_Stack7 bit49 */
			{    0, 0,2}, /* core3 return_Stack7 bit50 */
			{    0, 0,2}, /* core3 return_Stack7 bit51 */
			{    0, 0,2}, /* core3 return_Stack7 bit52 */
			{    0, 0,2}, /* core3 return_Stack7 bit53 */
			{    0, 0,2}, /* core3 return_Stack7 bit54 */
			{    0, 0,2}, /* core3 return_Stack7 bit55 */
			{    0, 0,2}, /* core3 return_Stack7 bit56 */
			{    0, 0,2}, /* core3 return_Stack7 bit57 */
			{    0, 0,2}, /* core3 return_Stack7 bit58 */
			{    0, 0,2}, /* core3 return_Stack7 bit59 */
			{    0, 0,2}, /* core3 return_Stack7 bit60 */
			{    0, 0,2}, /* core3 return_Stack7 bit61 */
			{    0, 0,2}, /* core3 return_Stack7 bit62 */
			{    0, 0,2}, /* core3 return_Stack7 bit63 */
			}},
	},
	{		/* core 4 */ 
			.pc = {{
			{ 2688,50,1}, /* core4 pc bit0 */
			{ 2686,50,1}, /* core4 pc bit1 */
			{ 2684,50,1}, /* core4 pc bit2 */
			{ 2682,50,1}, /* core4 pc bit3 */
			{ 2592,50,1}, /* core4 pc bit4 */
			{ 2590,50,1}, /* core4 pc bit5 */
			{ 2588,50,1}, /* core4 pc bit6 */
			{ 2586,50,1}, /* core4 pc bit7 */
			{ 2584,50,1}, /* core4 pc bit8 */
			{ 2582,50,1}, /* core4 pc bit9 */
			{ 2580,50,1}, /* core4 pc bit10 */
			{ 2578,50,1}, /* core4 pc bit11 */
			{ 2600,50,1}, /* core4 pc bit12 */
			{ 2598,50,1}, /* core4 pc bit13 */
			{ 2596,50,1}, /* core4 pc bit14 */
			{ 2594,50,1}, /* core4 pc bit15 */
			{ 2448,50,1}, /* core4 pc bit16 */
			{ 2446,50,1}, /* core4 pc bit17 */
			{ 2444,50,1}, /* core4 pc bit18 */
			{ 2442,50,1}, /* core4 pc bit19 */
			{ 2432,50,1}, /* core4 pc bit20 */
			{ 2430,50,1}, /* core4 pc bit21 */
			{ 2428,50,1}, /* core4 pc bit22 */
			{ 2426,50,1}, /* core4 pc bit23 */
			{ 2352,50,1}, /* core4 pc bit24 */
			{ 2350,50,1}, /* core4 pc bit25 */
			{ 2348,50,1}, /* core4 pc bit26 */
			{ 2346,50,1}, /* core4 pc bit27 */
			{ 2344,50,1}, /* core4 pc bit28 */
			{ 2342,50,1}, /* core4 pc bit29 */
			{ 2340,50,1}, /* core4 pc bit30 */
			{ 2338,50,1}, /* core4 pc bit31 */
			{ 2656,50,1}, /* core4 pc bit32 */
			{ 2654,50,1}, /* core4 pc bit33 */
			{ 2652,50,1}, /* core4 pc bit34 */
			{ 2650,50,1}, /* core4 pc bit35 */
			{ 2616,50,1}, /* core4 pc bit36 */
			{ 2614,50,1}, /* core4 pc bit37 */
			{ 2612,50,1}, /* core4 pc bit38 */
			{ 2610,50,1}, /* core4 pc bit39 */
			{ 2632,50,1}, /* core4 pc bit40 */
			{ 2630,50,1}, /* core4 pc bit41 */
			{  676,50,1}, /* core4 pc bit42 */
			{ 2628,50,1}, /* core4 pc bit43 */
			{ 2626,50,1}, /* core4 pc bit44 */
			{ 2608,50,1}, /* core4 pc bit45 */
			{ 2606,50,1}, /* core4 pc bit46 */
			{ 2604,50,1}, /* core4 pc bit47 */
			{ 2602,50,1}, /* core4 pc bit48 */
			{ 2400,50,1}, /* core4 pc bit49 */
			{ 2398,50,1}, /* core4 pc bit50 */
			{ 2396,50,1}, /* core4 pc bit51 */
			{ 2394,50,1}, /* core4 pc bit52 */
			{ 2312,50,1}, /* core4 pc bit53 */
			{ 2310,50,1}, /* core4 pc bit54 */
			{ 2308,50,1}, /* core4 pc bit55 */
			{ 2306,50,1}, /* core4 pc bit56 */
			{ 2164,50,1}, /* core4 pc bit57 */
			{ 2162,50,1}, /* core4 pc bit58 */
			{ 2160,50,1}, /* core4 pc bit59 */
			{ 2158,50,1}, /* core4 pc bit60 */
			{  682,50,1}, /* core4 pc bit61 */
			{  680,50,1}, /* core4 pc bit62 */
			{ 2228,50,1}, /* core4 pc bit63 */
			}},
			.sp32 = {{
			{32298,50,0}, /* core4 sp32 bit0 */
			{40686,50,0}, /* core4 sp32 bit1 */
			{32308,50,0}, /* core4 sp32 bit2 */
			{40522,50,0}, /* core4 sp32 bit3 */
			{40684,50,0}, /* core4 sp32 bit4 */
			{40682,50,0}, /* core4 sp32 bit5 */
			{40680,50,0}, /* core4 sp32 bit6 */
			{40690,50,0}, /* core4 sp32 bit7 */
			{40688,50,0}, /* core4 sp32 bit8 */
			{40654,50,0}, /* core4 sp32 bit9 */
			{40520,50,0}, /* core4 sp32 bit10 */
			{40526,50,0}, /* core4 sp32 bit11 */
			{40524,50,0}, /* core4 sp32 bit12 */
			{40646,50,0}, /* core4 sp32 bit13 */
			{40652,50,0}, /* core4 sp32 bit14 */
			{40644,50,0}, /* core4 sp32 bit15 */
			{40642,50,0}, /* core4 sp32 bit16 */
			{40640,50,0}, /* core4 sp32 bit17 */
			{32264,50,0}, /* core4 sp32 bit18 */
			{40614,50,0}, /* core4 sp32 bit19 */
			{40612,50,0}, /* core4 sp32 bit20 */
			{40510,50,0}, /* core4 sp32 bit21 */
			{32260,50,0}, /* core4 sp32 bit22 */
			{40508,50,0}, /* core4 sp32 bit23 */
			{40490,50,0}, /* core4 sp32 bit24 */
			{40488,50,0}, /* core4 sp32 bit25 */
			{40564,50,0}, /* core4 sp32 bit26 */
			{40562,50,0}, /* core4 sp32 bit27 */
			{40560,50,0}, /* core4 sp32 bit28 */
			{40566,50,0}, /* core4 sp32 bit29 */
			{32258,50,0}, /* core4 sp32 bit30 */
			{32256,50,0}, /* core4 sp32 bit31 */
			{40362,50,0}, /* core4 sp32 bit32 */
			{40360,50,0}, /* core4 sp32 bit33 */
			{40354,50,0}, /* core4 sp32 bit34 */
			{40352,50,0}, /* core4 sp32 bit35 */
			{40358,50,0}, /* core4 sp32 bit36 */
			{40356,50,0}, /* core4 sp32 bit37 */
			{31992,50,0}, /* core4 sp32 bit38 */
			{40350,50,0}, /* core4 sp32 bit39 */
			{40348,50,0}, /* core4 sp32 bit40 */
			{40322,50,0}, /* core4 sp32 bit41 */
			{40320,50,0}, /* core4 sp32 bit42 */
			{32028,50,0}, /* core4 sp32 bit43 */
			{40318,50,0}, /* core4 sp32 bit44 */
			{32030,50,0}, /* core4 sp32 bit45 */
			{40316,50,0}, /* core4 sp32 bit46 */
			{32032,50,0}, /* core4 sp32 bit47 */
			{47404,50,0}, /* core4 sp32 bit48 */
			{47402,50,0}, /* core4 sp32 bit49 */
			{47400,50,0}, /* core4 sp32 bit50 */
			{47398,50,0}, /* core4 sp32 bit51 */
			{47332,50,0}, /* core4 sp32 bit52 */
			{47330,50,0}, /* core4 sp32 bit53 */
			{47328,50,0}, /* core4 sp32 bit54 */
			{47326,50,0}, /* core4 sp32 bit55 */
			{47340,50,0}, /* core4 sp32 bit56 */
			{47338,50,0}, /* core4 sp32 bit57 */
			{47336,50,0}, /* core4 sp32 bit58 */
			{47334,50,0}, /* core4 sp32 bit59 */
			{47348,50,0}, /* core4 sp32 bit60 */
			{47346,50,0}, /* core4 sp32 bit61 */
			{47344,50,0}, /* core4 sp32 bit62 */
			{47342,50,0}, /* core4 sp32 bit63 */
			}},
			.fp32 = {{
			{32654,50,0}, /* core4 fp32 bit0 */
			{32322,50,0}, /* core4 fp32 bit1 */
			{40906,50,0}, /* core4 fp32 bit2 */
			{40900,50,0}, /* core4 fp32 bit3 */
			{40976,50,0}, /* core4 fp32 bit4 */
			{40974,50,0}, /* core4 fp32 bit5 */
			{40972,50,0}, /* core4 fp32 bit6 */
			{32646,50,0}, /* core4 fp32 bit7 */
			{40970,50,0}, /* core4 fp32 bit8 */
			{32320,50,0}, /* core4 fp32 bit9 */
			{40896,50,0}, /* core4 fp32 bit10 */
			{40904,50,0}, /* core4 fp32 bit11 */
			{40898,50,0}, /* core4 fp32 bit12 */
			{32390,50,0}, /* core4 fp32 bit13 */
			{40908,50,0}, /* core4 fp32 bit14 */
			{40902,50,0}, /* core4 fp32 bit15 */
			{40920,50,0}, /* core4 fp32 bit16 */
			{40918,50,0}, /* core4 fp32 bit17 */
			{32418,50,0}, /* core4 fp32 bit18 */
			{32386,50,0}, /* core4 fp32 bit19 */
			{40894,50,0}, /* core4 fp32 bit20 */
			{32348,50,0}, /* core4 fp32 bit21 */
			{32412,50,0}, /* core4 fp32 bit22 */
			{32334,50,0}, /* core4 fp32 bit23 */
			{32336,50,0}, /* core4 fp32 bit24 */
			{32342,50,0}, /* core4 fp32 bit25 */
			{40916,50,0}, /* core4 fp32 bit26 */
			{40914,50,0}, /* core4 fp32 bit27 */
			{32388,50,0}, /* core4 fp32 bit28 */
			{40924,50,0}, /* core4 fp32 bit29 */
			{40922,50,0}, /* core4 fp32 bit30 */
			{32424,50,0}, /* core4 fp32 bit31 */
			{41026,50,0}, /* core4 fp32 bit32 */
			{32578,50,0}, /* core4 fp32 bit33 */
			{41036,50,0}, /* core4 fp32 bit34 */
			{41022,50,0}, /* core4 fp32 bit35 */
			{41024,50,0}, /* core4 fp32 bit36 */
			{41028,50,0}, /* core4 fp32 bit37 */
			{32580,50,0}, /* core4 fp32 bit38 */
			{32582,50,0}, /* core4 fp32 bit39 */
			{41032,50,0}, /* core4 fp32 bit40 */
			{41030,50,0}, /* core4 fp32 bit41 */
			{41040,50,0}, /* core4 fp32 bit42 */
			{32552,50,0}, /* core4 fp32 bit43 */
			{41038,50,0}, /* core4 fp32 bit44 */
			{40992,50,0}, /* core4 fp32 bit45 */
			{41034,50,0}, /* core4 fp32 bit46 */
			{40990,50,0}, /* core4 fp32 bit47 */
			{32614,50,0}, /* core4 fp32 bit48 */
			{41064,50,0}, /* core4 fp32 bit49 */
			{47526,50,0}, /* core4 fp32 bit50 */
			{47524,50,0}, /* core4 fp32 bit51 */
			{47520,50,0}, /* core4 fp32 bit52 */
			{47430,50,0}, /* core4 fp32 bit53 */
			{47428,50,0}, /* core4 fp32 bit54 */
			{47426,50,0}, /* core4 fp32 bit55 */
			{47422,50,0}, /* core4 fp32 bit56 */
			{47424,50,0}, /* core4 fp32 bit57 */
			{47420,50,0}, /* core4 fp32 bit58 */
			{41062,50,0}, /* core4 fp32 bit59 */
			{47418,50,0}, /* core4 fp32 bit60 */
			{47416,50,0}, /* core4 fp32 bit61 */
			{32634,50,0}, /* core4 fp32 bit62 */
			{47518,50,0}, /* core4 fp32 bit63 */
			}},
			.fp64 = {{
			{32172,50,0}, /* core4 fp64 bit0 */
			{31886,50,0}, /* core4 fp64 bit1 */
			{39704,50,0}, /* core4 fp64 bit2 */
			{39782,50,0}, /* core4 fp64 bit3 */
			{32160,50,0}, /* core4 fp64 bit4 */
			{39662,50,0}, /* core4 fp64 bit5 */
			{39650,50,0}, /* core4 fp64 bit6 */
			{39648,50,0}, /* core4 fp64 bit7 */
			{39682,50,0}, /* core4 fp64 bit8 */
			{39660,50,0}, /* core4 fp64 bit9 */
			{31822,50,0}, /* core4 fp64 bit10 */
			{31824,50,0}, /* core4 fp64 bit11 */
			{31818,50,0}, /* core4 fp64 bit12 */
			{32222,50,0}, /* core4 fp64 bit13 */
			{39680,50,0}, /* core4 fp64 bit14 */
			{32224,50,0}, /* core4 fp64 bit15 */
			{39722,50,0}, /* core4 fp64 bit16 */
			{39720,50,0}, /* core4 fp64 bit17 */
			{39778,50,0}, /* core4 fp64 bit18 */
			{39786,50,0}, /* core4 fp64 bit19 */
			{39780,50,0}, /* core4 fp64 bit20 */
			{39784,50,0}, /* core4 fp64 bit21 */
			{39706,50,0}, /* core4 fp64 bit22 */
			{39770,50,0}, /* core4 fp64 bit23 */
			{39768,50,0}, /* core4 fp64 bit24 */
			{39742,50,0}, /* core4 fp64 bit25 */
			{39776,50,0}, /* core4 fp64 bit26 */
			{39740,50,0}, /* core4 fp64 bit27 */
			{31826,50,0}, /* core4 fp64 bit28 */
			{39774,50,0}, /* core4 fp64 bit29 */
			{39772,50,0}, /* core4 fp64 bit30 */
			{31836,50,0}, /* core4 fp64 bit31 */
			{31976,50,0}, /* core4 fp64 bit32 */
			{31974,50,0}, /* core4 fp64 bit33 */
			{31972,50,0}, /* core4 fp64 bit34 */
			{39436,50,0}, /* core4 fp64 bit35 */
			{39438,50,0}, /* core4 fp64 bit36 */
			{39430,50,0}, /* core4 fp64 bit37 */
			{39426,50,0}, /* core4 fp64 bit38 */
			{39428,50,0}, /* core4 fp64 bit39 */
			{39394,50,0}, /* core4 fp64 bit40 */
			{39392,50,0}, /* core4 fp64 bit41 */
			{39424,50,0}, /* core4 fp64 bit42 */
			{39398,50,0}, /* core4 fp64 bit43 */
			{39402,50,0}, /* core4 fp64 bit44 */
			{39410,50,0}, /* core4 fp64 bit45 */
			{39396,50,0}, /* core4 fp64 bit46 */
			{39400,50,0}, /* core4 fp64 bit47 */
			{39408,50,0}, /* core4 fp64 bit48 */
			{46722,50,0}, /* core4 fp64 bit49 */
			{46720,50,0}, /* core4 fp64 bit50 */
			{46718,50,0}, /* core4 fp64 bit51 */
			{46708,50,0}, /* core4 fp64 bit52 */
			{46698,50,0}, /* core4 fp64 bit53 */
			{46696,50,0}, /* core4 fp64 bit54 */
			{46694,50,0}, /* core4 fp64 bit55 */
			{46692,50,0}, /* core4 fp64 bit56 */
			{46706,50,0}, /* core4 fp64 bit57 */
			{46704,50,0}, /* core4 fp64 bit58 */
			{46702,50,0}, /* core4 fp64 bit59 */
			{46700,50,0}, /* core4 fp64 bit60 */
			{32034,50,0}, /* core4 fp64 bit61 */
			{32042,50,0}, /* core4 fp64 bit62 */
			{32040,50,0}, /* core4 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{31878,50,0}, /* core4 sp_EL0 bit0 */
			{31882,50,0}, /* core4 sp_EL0 bit1 */
			{39692,50,0}, /* core4 sp_EL0 bit2 */
			{39816,50,0}, /* core4 sp_EL0 bit3 */
			{39652,50,0}, /* core4 sp_EL0 bit4 */
			{39654,50,0}, /* core4 sp_EL0 bit5 */
			{39658,50,0}, /* core4 sp_EL0 bit6 */
			{39656,50,0}, /* core4 sp_EL0 bit7 */
			{39686,50,0}, /* core4 sp_EL0 bit8 */
			{39684,50,0}, /* core4 sp_EL0 bit9 */
			{39688,50,0}, /* core4 sp_EL0 bit10 */
			{39690,50,0}, /* core4 sp_EL0 bit11 */
			{39822,50,0}, /* core4 sp_EL0 bit12 */
			{31850,50,0}, /* core4 sp_EL0 bit13 */
			{39820,50,0}, /* core4 sp_EL0 bit14 */
			{31848,50,0}, /* core4 sp_EL0 bit15 */
			{39698,50,0}, /* core4 sp_EL0 bit16 */
			{39824,50,0}, /* core4 sp_EL0 bit17 */
			{39830,50,0}, /* core4 sp_EL0 bit18 */
			{39828,50,0}, /* core4 sp_EL0 bit19 */
			{39826,50,0}, /* core4 sp_EL0 bit20 */
			{39696,50,0}, /* core4 sp_EL0 bit21 */
			{39702,50,0}, /* core4 sp_EL0 bit22 */
			{39806,50,0}, /* core4 sp_EL0 bit23 */
			{39804,50,0}, /* core4 sp_EL0 bit24 */
			{39700,50,0}, /* core4 sp_EL0 bit25 */
			{39808,50,0}, /* core4 sp_EL0 bit26 */
			{39810,50,0}, /* core4 sp_EL0 bit27 */
			{39814,50,0}, /* core4 sp_EL0 bit28 */
			{39812,50,0}, /* core4 sp_EL0 bit29 */
			{39694,50,0}, /* core4 sp_EL0 bit30 */
			{39818,50,0}, /* core4 sp_EL0 bit31 */
			{39446,50,0}, /* core4 sp_EL0 bit32 */
			{32134,50,0}, /* core4 sp_EL0 bit33 */
			{39444,50,0}, /* core4 sp_EL0 bit34 */
			{32136,50,0}, /* core4 sp_EL0 bit35 */
			{32132,50,0}, /* core4 sp_EL0 bit36 */
			{32128,50,0}, /* core4 sp_EL0 bit37 */
			{32130,50,0}, /* core4 sp_EL0 bit38 */
			{39390,50,0}, /* core4 sp_EL0 bit39 */
			{39388,50,0}, /* core4 sp_EL0 bit40 */
			{39004,50,0}, /* core4 sp_EL0 bit41 */
			{39002,50,0}, /* core4 sp_EL0 bit42 */
			{38960,50,0}, /* core4 sp_EL0 bit43 */
			{31934,50,0}, /* core4 sp_EL0 bit44 */
			{38958,50,0}, /* core4 sp_EL0 bit45 */
			{46754,50,0}, /* core4 sp_EL0 bit46 */
			{46752,50,0}, /* core4 sp_EL0 bit47 */
			{46750,50,0}, /* core4 sp_EL0 bit48 */
			{38964,50,0}, /* core4 sp_EL0 bit49 */
			{38962,50,0}, /* core4 sp_EL0 bit50 */
			{46748,50,0}, /* core4 sp_EL0 bit51 */
			{46738,50,0}, /* core4 sp_EL0 bit52 */
			{46730,50,0}, /* core4 sp_EL0 bit53 */
			{46736,50,0}, /* core4 sp_EL0 bit54 */
			{46728,50,0}, /* core4 sp_EL0 bit55 */
			{46726,50,0}, /* core4 sp_EL0 bit56 */
			{46724,50,0}, /* core4 sp_EL0 bit57 */
			{46746,50,0}, /* core4 sp_EL0 bit58 */
			{46734,50,0}, /* core4 sp_EL0 bit59 */
			{46732,50,0}, /* core4 sp_EL0 bit60 */
			{46744,50,0}, /* core4 sp_EL0 bit61 */
			{46742,50,0}, /* core4 sp_EL0 bit62 */
			{46740,50,0}, /* core4 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{31874,50,0}, /* core4 sp_EL1 bit0 */
			{39272,50,0}, /* core4 sp_EL1 bit1 */
			{31872,50,0}, /* core4 sp_EL1 bit2 */
			{39270,50,0}, /* core4 sp_EL1 bit3 */
			{39084,50,0}, /* core4 sp_EL1 bit4 */
			{39082,50,0}, /* core4 sp_EL1 bit5 */
			{39086,50,0}, /* core4 sp_EL1 bit6 */
			{39072,50,0}, /* core4 sp_EL1 bit7 */
			{39070,50,0}, /* core4 sp_EL1 bit8 */
			{39088,50,0}, /* core4 sp_EL1 bit9 */
			{39134,50,0}, /* core4 sp_EL1 bit10 */
			{39128,50,0}, /* core4 sp_EL1 bit11 */
			{39238,50,0}, /* core4 sp_EL1 bit12 */
			{39126,50,0}, /* core4 sp_EL1 bit13 */
			{39260,50,0}, /* core4 sp_EL1 bit14 */
			{39262,50,0}, /* core4 sp_EL1 bit15 */
			{39264,50,0}, /* core4 sp_EL1 bit16 */
			{39252,50,0}, /* core4 sp_EL1 bit17 */
			{31854,50,0}, /* core4 sp_EL1 bit18 */
			{39250,50,0}, /* core4 sp_EL1 bit19 */
			{39242,50,0}, /* core4 sp_EL1 bit20 */
			{39240,50,0}, /* core4 sp_EL1 bit21 */
			{39268,50,0}, /* core4 sp_EL1 bit22 */
			{39266,50,0}, /* core4 sp_EL1 bit23 */
			{39132,50,0}, /* core4 sp_EL1 bit24 */
			{39258,50,0}, /* core4 sp_EL1 bit25 */
			{39130,50,0}, /* core4 sp_EL1 bit26 */
			{39138,50,0}, /* core4 sp_EL1 bit27 */
			{39236,50,0}, /* core4 sp_EL1 bit28 */
			{39140,50,0}, /* core4 sp_EL1 bit29 */
			{39136,50,0}, /* core4 sp_EL1 bit30 */
			{31852,50,0}, /* core4 sp_EL1 bit31 */
			{39028,50,0}, /* core4 sp_EL1 bit32 */
			{32108,50,0}, /* core4 sp_EL1 bit33 */
			{39026,50,0}, /* core4 sp_EL1 bit34 */
			{39020,50,0}, /* core4 sp_EL1 bit35 */
			{32104,50,0}, /* core4 sp_EL1 bit36 */
			{39018,50,0}, /* core4 sp_EL1 bit37 */
			{32102,50,0}, /* core4 sp_EL1 bit38 */
			{39008,50,0}, /* core4 sp_EL1 bit39 */
			{39006,50,0}, /* core4 sp_EL1 bit40 */
			{39000,50,0}, /* core4 sp_EL1 bit41 */
			{38998,50,0}, /* core4 sp_EL1 bit42 */
			{38956,50,0}, /* core4 sp_EL1 bit43 */
			{31932,50,0}, /* core4 sp_EL1 bit44 */
			{38954,50,0}, /* core4 sp_EL1 bit45 */
			{38980,50,0}, /* core4 sp_EL1 bit46 */
			{38978,50,0}, /* core4 sp_EL1 bit47 */
			{46778,50,0}, /* core4 sp_EL1 bit48 */
			{46776,50,0}, /* core4 sp_EL1 bit49 */
			{46774,50,0}, /* core4 sp_EL1 bit50 */
			{46772,50,0}, /* core4 sp_EL1 bit51 */
			{46682,50,0}, /* core4 sp_EL1 bit52 */
			{46680,50,0}, /* core4 sp_EL1 bit53 */
			{46678,50,0}, /* core4 sp_EL1 bit54 */
			{46676,50,0}, /* core4 sp_EL1 bit55 */
			{46690,50,0}, /* core4 sp_EL1 bit56 */
			{46688,50,0}, /* core4 sp_EL1 bit57 */
			{46686,50,0}, /* core4 sp_EL1 bit58 */
			{46684,50,0}, /* core4 sp_EL1 bit59 */
			{46634,50,0}, /* core4 sp_EL1 bit60 */
			{46632,50,0}, /* core4 sp_EL1 bit61 */
			{46630,50,0}, /* core4 sp_EL1 bit62 */
			{46628,50,0}, /* core4 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{31870,50,0}, /* core4 sp_EL2 bit0 */
			{39094,50,0}, /* core4 sp_EL2 bit1 */
			{31868,50,0}, /* core4 sp_EL2 bit2 */
			{39234,50,0}, /* core4 sp_EL2 bit3 */
			{39080,50,0}, /* core4 sp_EL2 bit4 */
			{39078,50,0}, /* core4 sp_EL2 bit5 */
			{39076,50,0}, /* core4 sp_EL2 bit6 */
			{39074,50,0}, /* core4 sp_EL2 bit7 */
			{39092,50,0}, /* core4 sp_EL2 bit8 */
			{39090,50,0}, /* core4 sp_EL2 bit9 */
			{39232,50,0}, /* core4 sp_EL2 bit10 */
			{39158,50,0}, /* core4 sp_EL2 bit11 */
			{39146,50,0}, /* core4 sp_EL2 bit12 */
			{39254,50,0}, /* core4 sp_EL2 bit13 */
			{39276,50,0}, /* core4 sp_EL2 bit14 */
			{39256,50,0}, /* core4 sp_EL2 bit15 */
			{39274,50,0}, /* core4 sp_EL2 bit16 */
			{39248,50,0}, /* core4 sp_EL2 bit17 */
			{31858,50,0}, /* core4 sp_EL2 bit18 */
			{39144,50,0}, /* core4 sp_EL2 bit19 */
			{39142,50,0}, /* core4 sp_EL2 bit20 */
			{39166,50,0}, /* core4 sp_EL2 bit21 */
			{39096,50,0}, /* core4 sp_EL2 bit22 */
			{39164,50,0}, /* core4 sp_EL2 bit23 */
			{39162,50,0}, /* core4 sp_EL2 bit24 */
			{39230,50,0}, /* core4 sp_EL2 bit25 */
			{39228,50,0}, /* core4 sp_EL2 bit26 */
			{39156,50,0}, /* core4 sp_EL2 bit27 */
			{39154,50,0}, /* core4 sp_EL2 bit28 */
			{39160,50,0}, /* core4 sp_EL2 bit29 */
			{39152,50,0}, /* core4 sp_EL2 bit30 */
			{31866,50,0}, /* core4 sp_EL2 bit31 */
			{39040,50,0}, /* core4 sp_EL2 bit32 */
			{32148,50,0}, /* core4 sp_EL2 bit33 */
			{39038,50,0}, /* core4 sp_EL2 bit34 */
			{39032,50,0}, /* core4 sp_EL2 bit35 */
			{39030,50,0}, /* core4 sp_EL2 bit36 */
			{32106,50,0}, /* core4 sp_EL2 bit37 */
			{39024,50,0}, /* core4 sp_EL2 bit38 */
			{38988,50,0}, /* core4 sp_EL2 bit39 */
			{39022,50,0}, /* core4 sp_EL2 bit40 */
			{38996,50,0}, /* core4 sp_EL2 bit41 */
			{38994,50,0}, /* core4 sp_EL2 bit42 */
			{38986,50,0}, /* core4 sp_EL2 bit43 */
			{38984,50,0}, /* core4 sp_EL2 bit44 */
			{32074,50,0}, /* core4 sp_EL2 bit45 */
			{38982,50,0}, /* core4 sp_EL2 bit46 */
			{46770,50,0}, /* core4 sp_EL2 bit47 */
			{46762,50,0}, /* core4 sp_EL2 bit48 */
			{46768,50,0}, /* core4 sp_EL2 bit49 */
			{46760,50,0}, /* core4 sp_EL2 bit50 */
			{46758,50,0}, /* core4 sp_EL2 bit51 */
			{46756,50,0}, /* core4 sp_EL2 bit52 */
			{46650,50,0}, /* core4 sp_EL2 bit53 */
			{46648,50,0}, /* core4 sp_EL2 bit54 */
			{46646,50,0}, /* core4 sp_EL2 bit55 */
			{46644,50,0}, /* core4 sp_EL2 bit56 */
			{46642,50,0}, /* core4 sp_EL2 bit57 */
			{46640,50,0}, /* core4 sp_EL2 bit58 */
			{46638,50,0}, /* core4 sp_EL2 bit59 */
			{46636,50,0}, /* core4 sp_EL2 bit60 */
			{46766,50,0}, /* core4 sp_EL2 bit61 */
			{46764,50,0}, /* core4 sp_EL2 bit62 */
			{32070,50,0}, /* core4 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{31844,50,0}, /* core4 sp_EL3 bit0 */
			{31884,50,0}, /* core4 sp_EL3 bit1 */
			{39056,50,0}, /* core4 sp_EL3 bit2 */
			{39220,50,0}, /* core4 sp_EL3 bit3 */
			{39052,50,0}, /* core4 sp_EL3 bit4 */
			{39050,50,0}, /* core4 sp_EL3 bit5 */
			{39054,50,0}, /* core4 sp_EL3 bit6 */
			{39048,50,0}, /* core4 sp_EL3 bit7 */
			{39046,50,0}, /* core4 sp_EL3 bit8 */
			{39102,50,0}, /* core4 sp_EL3 bit9 */
			{39212,50,0}, /* core4 sp_EL3 bit10 */
			{39206,50,0}, /* core4 sp_EL3 bit11 */
			{39204,50,0}, /* core4 sp_EL3 bit12 */
			{39120,50,0}, /* core4 sp_EL3 bit13 */
			{39104,50,0}, /* core4 sp_EL3 bit14 */
			{39118,50,0}, /* core4 sp_EL3 bit15 */
			{39108,50,0}, /* core4 sp_EL3 bit16 */
			{31832,50,0}, /* core4 sp_EL3 bit17 */
			{39218,50,0}, /* core4 sp_EL3 bit18 */
			{39224,50,0}, /* core4 sp_EL3 bit19 */
			{39222,50,0}, /* core4 sp_EL3 bit20 */
			{39196,50,0}, /* core4 sp_EL3 bit21 */
			{39106,50,0}, /* core4 sp_EL3 bit22 */
			{39194,50,0}, /* core4 sp_EL3 bit23 */
			{39200,50,0}, /* core4 sp_EL3 bit24 */
			{39210,50,0}, /* core4 sp_EL3 bit25 */
			{39198,50,0}, /* core4 sp_EL3 bit26 */
			{39216,50,0}, /* core4 sp_EL3 bit27 */
			{39208,50,0}, /* core4 sp_EL3 bit28 */
			{39202,50,0}, /* core4 sp_EL3 bit29 */
			{39214,50,0}, /* core4 sp_EL3 bit30 */
			{31834,50,0}, /* core4 sp_EL3 bit31 */
			{39036,50,0}, /* core4 sp_EL3 bit32 */
			{32140,50,0}, /* core4 sp_EL3 bit33 */
			{39034,50,0}, /* core4 sp_EL3 bit34 */
			{32144,50,0}, /* core4 sp_EL3 bit35 */
			{32142,50,0}, /* core4 sp_EL3 bit36 */
			{32124,50,0}, /* core4 sp_EL3 bit37 */
			{32126,50,0}, /* core4 sp_EL3 bit38 */
			{32092,50,0}, /* core4 sp_EL3 bit39 */
			{32094,50,0}, /* core4 sp_EL3 bit40 */
			{32084,50,0}, /* core4 sp_EL3 bit41 */
			{38992,50,0}, /* core4 sp_EL3 bit42 */
			{31930,50,0}, /* core4 sp_EL3 bit43 */
			{38990,50,0}, /* core4 sp_EL3 bit44 */
			{32076,50,0}, /* core4 sp_EL3 bit45 */
			{38972,50,0}, /* core4 sp_EL3 bit46 */
			{38976,50,0}, /* core4 sp_EL3 bit47 */
			{38974,50,0}, /* core4 sp_EL3 bit48 */
			{46658,50,0}, /* core4 sp_EL3 bit49 */
			{46656,50,0}, /* core4 sp_EL3 bit50 */
			{46654,50,0}, /* core4 sp_EL3 bit51 */
			{46652,50,0}, /* core4 sp_EL3 bit52 */
			{46674,50,0}, /* core4 sp_EL3 bit53 */
			{46672,50,0}, /* core4 sp_EL3 bit54 */
			{46670,50,0}, /* core4 sp_EL3 bit55 */
			{46668,50,0}, /* core4 sp_EL3 bit56 */
			{46666,50,0}, /* core4 sp_EL3 bit57 */
			{46664,50,0}, /* core4 sp_EL3 bit58 */
			{46662,50,0}, /* core4 sp_EL3 bit59 */
			{38970,50,0}, /* core4 sp_EL3 bit60 */
			{46660,50,0}, /* core4 sp_EL3 bit61 */
			{38968,50,0}, /* core4 sp_EL3 bit62 */
			{38966,50,0}, /* core4 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{46886,50,0}, /* core4 elr_EL1 bit0 */
			{46884,50,0}, /* core4 elr_EL1 bit1 */
			{46888,50,0}, /* core4 elr_EL1 bit2 */
			{46954,50,0}, /* core4 elr_EL1 bit3 */
			{46890,50,0}, /* core4 elr_EL1 bit4 */
			{46882,50,0}, /* core4 elr_EL1 bit5 */
			{46880,50,0}, /* core4 elr_EL1 bit6 */
			{46874,50,0}, /* core4 elr_EL1 bit7 */
			{46872,50,0}, /* core4 elr_EL1 bit8 */
			{46870,50,0}, /* core4 elr_EL1 bit9 */
			{46952,50,0}, /* core4 elr_EL1 bit10 */
			{46950,50,0}, /* core4 elr_EL1 bit11 */
			{46914,50,0}, /* core4 elr_EL1 bit12 */
			{46948,50,0}, /* core4 elr_EL1 bit13 */
			{46878,50,0}, /* core4 elr_EL1 bit14 */
			{46904,50,0}, /* core4 elr_EL1 bit15 */
			{46868,50,0}, /* core4 elr_EL1 bit16 */
			{31856,50,0}, /* core4 elr_EL1 bit17 */
			{46958,50,0}, /* core4 elr_EL1 bit18 */
			{46956,50,0}, /* core4 elr_EL1 bit19 */
			{46906,50,0}, /* core4 elr_EL1 bit20 */
			{46946,50,0}, /* core4 elr_EL1 bit21 */
			{46876,50,0}, /* core4 elr_EL1 bit22 */
			{46912,50,0}, /* core4 elr_EL1 bit23 */
			{46910,50,0}, /* core4 elr_EL1 bit24 */
			{46908,50,0}, /* core4 elr_EL1 bit25 */
			{46944,50,0}, /* core4 elr_EL1 bit26 */
			{46942,50,0}, /* core4 elr_EL1 bit27 */
			{46940,50,0}, /* core4 elr_EL1 bit28 */
			{39246,50,0}, /* core4 elr_EL1 bit29 */
			{39244,50,0}, /* core4 elr_EL1 bit30 */
			{31864,50,0}, /* core4 elr_EL1 bit31 */
			{46612,50,0}, /* core4 elr_EL1 bit32 */
			{46850,50,0}, /* core4 elr_EL1 bit33 */
			{46848,50,0}, /* core4 elr_EL1 bit34 */
			{46846,50,0}, /* core4 elr_EL1 bit35 */
			{46844,50,0}, /* core4 elr_EL1 bit36 */
			{46834,50,0}, /* core4 elr_EL1 bit37 */
			{46832,50,0}, /* core4 elr_EL1 bit38 */
			{46830,50,0}, /* core4 elr_EL1 bit39 */
			{46828,50,0}, /* core4 elr_EL1 bit40 */
			{46818,50,0}, /* core4 elr_EL1 bit41 */
			{46816,50,0}, /* core4 elr_EL1 bit42 */
			{46814,50,0}, /* core4 elr_EL1 bit43 */
			{46812,50,0}, /* core4 elr_EL1 bit44 */
			{46802,50,0}, /* core4 elr_EL1 bit45 */
			{46800,50,0}, /* core4 elr_EL1 bit46 */
			{46798,50,0}, /* core4 elr_EL1 bit47 */
			{46796,50,0}, /* core4 elr_EL1 bit48 */
			{46602,50,0}, /* core4 elr_EL1 bit49 */
			{46594,50,0}, /* core4 elr_EL1 bit50 */
			{46600,50,0}, /* core4 elr_EL1 bit51 */
			{46598,50,0}, /* core4 elr_EL1 bit52 */
			{46592,50,0}, /* core4 elr_EL1 bit53 */
			{46590,50,0}, /* core4 elr_EL1 bit54 */
			{46596,50,0}, /* core4 elr_EL1 bit55 */
			{46588,50,0}, /* core4 elr_EL1 bit56 */
			{46618,50,0}, /* core4 elr_EL1 bit57 */
			{46610,50,0}, /* core4 elr_EL1 bit58 */
			{46608,50,0}, /* core4 elr_EL1 bit59 */
			{46606,50,0}, /* core4 elr_EL1 bit60 */
			{46604,50,0}, /* core4 elr_EL1 bit61 */
			{46616,50,0}, /* core4 elr_EL1 bit62 */
			{46614,50,0}, /* core4 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{46866,50,0}, /* core4 elr_EL2 bit0 */
			{46864,50,0}, /* core4 elr_EL2 bit1 */
			{46894,50,0}, /* core4 elr_EL2 bit2 */
			{46930,50,0}, /* core4 elr_EL2 bit3 */
			{46892,50,0}, /* core4 elr_EL2 bit4 */
			{46858,50,0}, /* core4 elr_EL2 bit5 */
			{46856,50,0}, /* core4 elr_EL2 bit6 */
			{46854,50,0}, /* core4 elr_EL2 bit7 */
			{46862,50,0}, /* core4 elr_EL2 bit8 */
			{46860,50,0}, /* core4 elr_EL2 bit9 */
			{46928,50,0}, /* core4 elr_EL2 bit10 */
			{46962,50,0}, /* core4 elr_EL2 bit11 */
			{46960,50,0}, /* core4 elr_EL2 bit12 */
			{46902,50,0}, /* core4 elr_EL2 bit13 */
			{46898,50,0}, /* core4 elr_EL2 bit14 */
			{46900,50,0}, /* core4 elr_EL2 bit15 */
			{46852,50,0}, /* core4 elr_EL2 bit16 */
			{31860,50,0}, /* core4 elr_EL2 bit17 */
			{46922,50,0}, /* core4 elr_EL2 bit18 */
			{46920,50,0}, /* core4 elr_EL2 bit19 */
			{46918,50,0}, /* core4 elr_EL2 bit20 */
			{46916,50,0}, /* core4 elr_EL2 bit21 */
			{46896,50,0}, /* core4 elr_EL2 bit22 */
			{39150,50,0}, /* core4 elr_EL2 bit23 */
			{46926,50,0}, /* core4 elr_EL2 bit24 */
			{46924,50,0}, /* core4 elr_EL2 bit25 */
			{46938,50,0}, /* core4 elr_EL2 bit26 */
			{39148,50,0}, /* core4 elr_EL2 bit27 */
			{46936,50,0}, /* core4 elr_EL2 bit28 */
			{46934,50,0}, /* core4 elr_EL2 bit29 */
			{46932,50,0}, /* core4 elr_EL2 bit30 */
			{31862,50,0}, /* core4 elr_EL2 bit31 */
			{46782,50,0}, /* core4 elr_EL2 bit32 */
			{46780,50,0}, /* core4 elr_EL2 bit33 */
			{46842,50,0}, /* core4 elr_EL2 bit34 */
			{46840,50,0}, /* core4 elr_EL2 bit35 */
			{46838,50,0}, /* core4 elr_EL2 bit36 */
			{46836,50,0}, /* core4 elr_EL2 bit37 */
			{46826,50,0}, /* core4 elr_EL2 bit38 */
			{46824,50,0}, /* core4 elr_EL2 bit39 */
			{46794,50,0}, /* core4 elr_EL2 bit40 */
			{46822,50,0}, /* core4 elr_EL2 bit41 */
			{46820,50,0}, /* core4 elr_EL2 bit42 */
			{46792,50,0}, /* core4 elr_EL2 bit43 */
			{46810,50,0}, /* core4 elr_EL2 bit44 */
			{46808,50,0}, /* core4 elr_EL2 bit45 */
			{46806,50,0}, /* core4 elr_EL2 bit46 */
			{46804,50,0}, /* core4 elr_EL2 bit47 */
			{46626,50,0}, /* core4 elr_EL2 bit48 */
			{46790,50,0}, /* core4 elr_EL2 bit49 */
			{46788,50,0}, /* core4 elr_EL2 bit50 */
			{46578,50,0}, /* core4 elr_EL2 bit51 */
			{46576,50,0}, /* core4 elr_EL2 bit52 */
			{46574,50,0}, /* core4 elr_EL2 bit53 */
			{46572,50,0}, /* core4 elr_EL2 bit54 */
			{46570,50,0}, /* core4 elr_EL2 bit55 */
			{46568,50,0}, /* core4 elr_EL2 bit56 */
			{46624,50,0}, /* core4 elr_EL2 bit57 */
			{46566,50,0}, /* core4 elr_EL2 bit58 */
			{46564,50,0}, /* core4 elr_EL2 bit59 */
			{46622,50,0}, /* core4 elr_EL2 bit60 */
			{46786,50,0}, /* core4 elr_EL2 bit61 */
			{46784,50,0}, /* core4 elr_EL2 bit62 */
			{46620,50,0}, /* core4 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{39064,50,0}, /* core4 elr_EL3 bit0 */
			{39062,50,0}, /* core4 elr_EL3 bit1 */
			{39100,50,0}, /* core4 elr_EL3 bit2 */
			{39188,50,0}, /* core4 elr_EL3 bit3 */
			{39068,50,0}, /* core4 elr_EL3 bit4 */
			{39066,50,0}, /* core4 elr_EL3 bit5 */
			{39098,50,0}, /* core4 elr_EL3 bit6 */
			{31880,50,0}, /* core4 elr_EL3 bit7 */
			{39060,50,0}, /* core4 elr_EL3 bit8 */
			{39058,50,0}, /* core4 elr_EL3 bit9 */
			{39172,50,0}, /* core4 elr_EL3 bit10 */
			{39186,50,0}, /* core4 elr_EL3 bit11 */
			{39168,50,0}, /* core4 elr_EL3 bit12 */
			{39226,50,0}, /* core4 elr_EL3 bit13 */
			{39112,50,0}, /* core4 elr_EL3 bit14 */
			{39124,50,0}, /* core4 elr_EL3 bit15 */
			{39110,50,0}, /* core4 elr_EL3 bit16 */
			{39116,50,0}, /* core4 elr_EL3 bit17 */
			{31830,50,0}, /* core4 elr_EL3 bit18 */
			{39122,50,0}, /* core4 elr_EL3 bit19 */
			{39170,50,0}, /* core4 elr_EL3 bit20 */
			{39192,50,0}, /* core4 elr_EL3 bit21 */
			{39114,50,0}, /* core4 elr_EL3 bit22 */
			{39190,50,0}, /* core4 elr_EL3 bit23 */
			{31828,50,0}, /* core4 elr_EL3 bit24 */
			{39184,50,0}, /* core4 elr_EL3 bit25 */
			{39182,50,0}, /* core4 elr_EL3 bit26 */
			{39176,50,0}, /* core4 elr_EL3 bit27 */
			{39174,50,0}, /* core4 elr_EL3 bit28 */
			{39180,50,0}, /* core4 elr_EL3 bit29 */
			{39178,50,0}, /* core4 elr_EL3 bit30 */
			{31846,50,0}, /* core4 elr_EL3 bit31 */
			{46078,50,0}, /* core4 elr_EL3 bit32 */
			{39044,50,0}, /* core4 elr_EL3 bit33 */
			{39042,50,0}, /* core4 elr_EL3 bit34 */
			{32156,50,0}, /* core4 elr_EL3 bit35 */
			{32154,50,0}, /* core4 elr_EL3 bit36 */
			{39016,50,0}, /* core4 elr_EL3 bit37 */
			{39014,50,0}, /* core4 elr_EL3 bit38 */
			{39012,50,0}, /* core4 elr_EL3 bit39 */
			{31902,50,0}, /* core4 elr_EL3 bit40 */
			{31920,50,0}, /* core4 elr_EL3 bit41 */
			{39010,50,0}, /* core4 elr_EL3 bit42 */
			{38948,50,0}, /* core4 elr_EL3 bit43 */
			{38952,50,0}, /* core4 elr_EL3 bit44 */
			{38950,50,0}, /* core4 elr_EL3 bit45 */
			{38946,50,0}, /* core4 elr_EL3 bit46 */
			{38944,50,0}, /* core4 elr_EL3 bit47 */
			{38942,50,0}, /* core4 elr_EL3 bit48 */
			{46538,50,0}, /* core4 elr_EL3 bit49 */
			{46586,50,0}, /* core4 elr_EL3 bit50 */
			{46584,50,0}, /* core4 elr_EL3 bit51 */
			{46536,50,0}, /* core4 elr_EL3 bit52 */
			{46534,50,0}, /* core4 elr_EL3 bit53 */
			{46532,50,0}, /* core4 elr_EL3 bit54 */
			{46530,50,0}, /* core4 elr_EL3 bit55 */
			{46528,50,0}, /* core4 elr_EL3 bit56 */
			{46582,50,0}, /* core4 elr_EL3 bit57 */
			{46526,50,0}, /* core4 elr_EL3 bit58 */
			{46524,50,0}, /* core4 elr_EL3 bit59 */
			{46084,50,0}, /* core4 elr_EL3 bit60 */
			{46082,50,0}, /* core4 elr_EL3 bit61 */
			{46080,50,0}, /* core4 elr_EL3 bit62 */
			{46580,50,0}, /* core4 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{44712,50,0}, /* core4 raw_pc bit0 */
			{19018,53,0}, /* core4 raw_pc bit1 */
			{19016,53,0}, /* core4 raw_pc bit2 */
			{19012,53,0}, /* core4 raw_pc bit3 */
			{19014,53,0}, /* core4 raw_pc bit4 */
			{44704,50,0}, /* core4 raw_pc bit5 */
			{44702,50,0}, /* core4 raw_pc bit6 */
			{19158,53,0}, /* core4 raw_pc bit7 */
			{19032,53,0}, /* core4 raw_pc bit8 */
			{19030,53,0}, /* core4 raw_pc bit9 */
			{19028,53,0}, /* core4 raw_pc bit10 */
			{19156,53,0}, /* core4 raw_pc bit11 */
			{19154,53,0}, /* core4 raw_pc bit12 */
			{19152,53,0}, /* core4 raw_pc bit13 */
			{19150,53,0}, /* core4 raw_pc bit14 */
			{19148,53,0}, /* core4 raw_pc bit15 */
			{19146,53,0}, /* core4 raw_pc bit16 */
			{19144,53,0}, /* core4 raw_pc bit17 */
			{19142,53,0}, /* core4 raw_pc bit18 */
			{19060,53,0}, /* core4 raw_pc bit19 */
			{19058,53,0}, /* core4 raw_pc bit20 */
			{19056,53,0}, /* core4 raw_pc bit21 */
			{19054,53,0}, /* core4 raw_pc bit22 */
			{19052,53,0}, /* core4 raw_pc bit23 */
			{19050,53,0}, /* core4 raw_pc bit24 */
			{19048,53,0}, /* core4 raw_pc bit25 */
			{19046,53,0}, /* core4 raw_pc bit26 */
			{19044,53,0}, /* core4 raw_pc bit27 */
			{19042,53,0}, /* core4 raw_pc bit28 */
			{19040,53,0}, /* core4 raw_pc bit29 */
			{19038,53,0}, /* core4 raw_pc bit30 */
			{19010,53,0}, /* core4 raw_pc bit31 */
			{19008,53,0}, /* core4 raw_pc bit32 */
			{19006,53,0}, /* core4 raw_pc bit33 */
			{19004,53,0}, /* core4 raw_pc bit34 */
			{19002,53,0}, /* core4 raw_pc bit35 */
			{19000,53,0}, /* core4 raw_pc bit36 */
			{18998,53,0}, /* core4 raw_pc bit37 */
			{18996,53,0}, /* core4 raw_pc bit38 */
			{18994,53,0}, /* core4 raw_pc bit39 */
			{18992,53,0}, /* core4 raw_pc bit40 */
			{18990,53,0}, /* core4 raw_pc bit41 */
			{18988,53,0}, /* core4 raw_pc bit42 */
			{18982,53,0}, /* core4 raw_pc bit43 */
			{18980,53,0}, /* core4 raw_pc bit44 */
			{18986,53,0}, /* core4 raw_pc bit45 */
			{18984,53,0}, /* core4 raw_pc bit46 */
			{44708,50,0}, /* core4 raw_pc bit47 */
			{44706,50,0}, /* core4 raw_pc bit48 */
			{36762,50,0}, /* core4 raw_pc bit49 */
			{    0, 0,2}, /* core4 raw_pc bit50 */
			{    0, 0,2}, /* core4 raw_pc bit51 */
			{    0, 0,2}, /* core4 raw_pc bit52 */
			{    0, 0,2}, /* core4 raw_pc bit53 */
			{    0, 0,2}, /* core4 raw_pc bit54 */
			{    0, 0,2}, /* core4 raw_pc bit55 */
			{    0, 0,2}, /* core4 raw_pc bit56 */
			{    0, 0,2}, /* core4 raw_pc bit57 */
			{    0, 0,2}, /* core4 raw_pc bit58 */
			{    0, 0,2}, /* core4 raw_pc bit59 */
			{    0, 0,2}, /* core4 raw_pc bit60 */
			{    0, 0,2}, /* core4 raw_pc bit61 */
			{    0, 0,2}, /* core4 raw_pc bit62 */
			{    0, 0,2}, /* core4 raw_pc bit63 */
			}},
			.pc_iss = {{
			{44752,50,0}, /* core4 pc_iss bit0 */
			{44760,50,0}, /* core4 pc_iss bit1 */
			{44758,50,0}, /* core4 pc_iss bit2 */
			{44764,50,0}, /* core4 pc_iss bit3 */
			{44762,50,0}, /* core4 pc_iss bit4 */
			{44750,50,0}, /* core4 pc_iss bit5 */
			{44756,50,0}, /* core4 pc_iss bit6 */
			{44754,50,0}, /* core4 pc_iss bit7 */
			{44768,50,0}, /* core4 pc_iss bit8 */
			{44766,50,0}, /* core4 pc_iss bit9 */
			{44746,50,0}, /* core4 pc_iss bit10 */
			{44744,50,0}, /* core4 pc_iss bit11 */
			{45102,50,0}, /* core4 pc_iss bit12 */
			{45100,50,0}, /* core4 pc_iss bit13 */
			{45098,50,0}, /* core4 pc_iss bit14 */
			{44748,50,0}, /* core4 pc_iss bit15 */
			{45096,50,0}, /* core4 pc_iss bit16 */
			{45090,50,0}, /* core4 pc_iss bit17 */
			{45088,50,0}, /* core4 pc_iss bit18 */
			{45082,50,0}, /* core4 pc_iss bit19 */
			{45080,50,0}, /* core4 pc_iss bit20 */
			{45086,50,0}, /* core4 pc_iss bit21 */
			{45084,50,0}, /* core4 pc_iss bit22 */
			{44782,50,0}, /* core4 pc_iss bit23 */
			{44780,50,0}, /* core4 pc_iss bit24 */
			{36740,50,0}, /* core4 pc_iss bit25 */
			{36738,50,0}, /* core4 pc_iss bit26 */
			{45094,50,0}, /* core4 pc_iss bit27 */
			{45092,50,0}, /* core4 pc_iss bit28 */
			{44742,50,0}, /* core4 pc_iss bit29 */
			{44740,50,0}, /* core4 pc_iss bit30 */
			{44778,50,0}, /* core4 pc_iss bit31 */
			{44700,50,0}, /* core4 pc_iss bit32 */
			{44698,50,0}, /* core4 pc_iss bit33 */
			{44696,50,0}, /* core4 pc_iss bit34 */
			{44694,50,0}, /* core4 pc_iss bit35 */
			{44680,50,0}, /* core4 pc_iss bit36 */
			{44678,50,0}, /* core4 pc_iss bit37 */
			{44692,50,0}, /* core4 pc_iss bit38 */
			{44688,50,0}, /* core4 pc_iss bit39 */
			{44686,50,0}, /* core4 pc_iss bit40 */
			{44684,50,0}, /* core4 pc_iss bit41 */
			{44682,50,0}, /* core4 pc_iss bit42 */
			{44690,50,0}, /* core4 pc_iss bit43 */
			{18930,53,0}, /* core4 pc_iss bit44 */
			{18928,53,0}, /* core4 pc_iss bit45 */
			{18926,53,0}, /* core4 pc_iss bit46 */
			{18924,53,0}, /* core4 pc_iss bit47 */
			{18922,53,0}, /* core4 pc_iss bit48 */
			{18920,53,0}, /* core4 pc_iss bit49 */
			{18918,53,0}, /* core4 pc_iss bit50 */
			{18880,53,0}, /* core4 pc_iss bit51 */
			{18904,53,0}, /* core4 pc_iss bit52 */
			{18902,53,0}, /* core4 pc_iss bit53 */
			{18916,53,0}, /* core4 pc_iss bit54 */
			{18914,53,0}, /* core4 pc_iss bit55 */
			{19026,53,0}, /* core4 pc_iss bit56 */
			{19020,53,0}, /* core4 pc_iss bit57 */
			{19036,53,0}, /* core4 pc_iss bit58 */
			{19034,53,0}, /* core4 pc_iss bit59 */
			{18900,53,0}, /* core4 pc_iss bit60 */
			{18898,53,0}, /* core4 pc_iss bit61 */
			{19024,53,0}, /* core4 pc_iss bit62 */
			{19022,53,0}, /* core4 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{44710,50,0}, /* core4 full_pc_wr bit0 */
			{    0, 0,2}, /* core4 full_pc_wr bit1 */
			{    0, 0,2}, /* core4 full_pc_wr bit2 */
			{    0, 0,2}, /* core4 full_pc_wr bit3 */
			{    0, 0,2}, /* core4 full_pc_wr bit4 */
			{    0, 0,2}, /* core4 full_pc_wr bit5 */
			{    0, 0,2}, /* core4 full_pc_wr bit6 */
			{    0, 0,2}, /* core4 full_pc_wr bit7 */
			{    0, 0,2}, /* core4 full_pc_wr bit8 */
			{    0, 0,2}, /* core4 full_pc_wr bit9 */
			{    0, 0,2}, /* core4 full_pc_wr bit10 */
			{    0, 0,2}, /* core4 full_pc_wr bit11 */
			{    0, 0,2}, /* core4 full_pc_wr bit12 */
			{    0, 0,2}, /* core4 full_pc_wr bit13 */
			{    0, 0,2}, /* core4 full_pc_wr bit14 */
			{    0, 0,2}, /* core4 full_pc_wr bit15 */
			{    0, 0,2}, /* core4 full_pc_wr bit16 */
			{    0, 0,2}, /* core4 full_pc_wr bit17 */
			{    0, 0,2}, /* core4 full_pc_wr bit18 */
			{    0, 0,2}, /* core4 full_pc_wr bit19 */
			{    0, 0,2}, /* core4 full_pc_wr bit20 */
			{    0, 0,2}, /* core4 full_pc_wr bit21 */
			{    0, 0,2}, /* core4 full_pc_wr bit22 */
			{    0, 0,2}, /* core4 full_pc_wr bit23 */
			{    0, 0,2}, /* core4 full_pc_wr bit24 */
			{    0, 0,2}, /* core4 full_pc_wr bit25 */
			{    0, 0,2}, /* core4 full_pc_wr bit26 */
			{    0, 0,2}, /* core4 full_pc_wr bit27 */
			{    0, 0,2}, /* core4 full_pc_wr bit28 */
			{    0, 0,2}, /* core4 full_pc_wr bit29 */
			{    0, 0,2}, /* core4 full_pc_wr bit30 */
			{    0, 0,2}, /* core4 full_pc_wr bit31 */
			{    0, 0,2}, /* core4 full_pc_wr bit32 */
			{    0, 0,2}, /* core4 full_pc_wr bit33 */
			{    0, 0,2}, /* core4 full_pc_wr bit34 */
			{    0, 0,2}, /* core4 full_pc_wr bit35 */
			{    0, 0,2}, /* core4 full_pc_wr bit36 */
			{    0, 0,2}, /* core4 full_pc_wr bit37 */
			{    0, 0,2}, /* core4 full_pc_wr bit38 */
			{    0, 0,2}, /* core4 full_pc_wr bit39 */
			{    0, 0,2}, /* core4 full_pc_wr bit40 */
			{    0, 0,2}, /* core4 full_pc_wr bit41 */
			{    0, 0,2}, /* core4 full_pc_wr bit42 */
			{    0, 0,2}, /* core4 full_pc_wr bit43 */
			{    0, 0,2}, /* core4 full_pc_wr bit44 */
			{    0, 0,2}, /* core4 full_pc_wr bit45 */
			{    0, 0,2}, /* core4 full_pc_wr bit46 */
			{    0, 0,2}, /* core4 full_pc_wr bit47 */
			{    0, 0,2}, /* core4 full_pc_wr bit48 */
			{    0, 0,2}, /* core4 full_pc_wr bit49 */
			{    0, 0,2}, /* core4 full_pc_wr bit50 */
			{    0, 0,2}, /* core4 full_pc_wr bit51 */
			{    0, 0,2}, /* core4 full_pc_wr bit52 */
			{    0, 0,2}, /* core4 full_pc_wr bit53 */
			{    0, 0,2}, /* core4 full_pc_wr bit54 */
			{    0, 0,2}, /* core4 full_pc_wr bit55 */
			{    0, 0,2}, /* core4 full_pc_wr bit56 */
			{    0, 0,2}, /* core4 full_pc_wr bit57 */
			{    0, 0,2}, /* core4 full_pc_wr bit58 */
			{    0, 0,2}, /* core4 full_pc_wr bit59 */
			{    0, 0,2}, /* core4 full_pc_wr bit60 */
			{    0, 0,2}, /* core4 full_pc_wr bit61 */
			{    0, 0,2}, /* core4 full_pc_wr bit62 */
			{    0, 0,2}, /* core4 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{37250,50,0}, /* core4 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core4 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{44772,50,0}, /* core4 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core4 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{ 7874,51,0}, /* core4 return_Stack_pointer bit0 */
			{ 7872,51,0}, /* core4 return_Stack_pointer bit1 */
			{ 7878,51,0}, /* core4 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core4 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{19482,51,0}, /* core4 return_Stack0 bit0 */
			{19480,51,0}, /* core4 return_Stack0 bit1 */
			{19478,51,0}, /* core4 return_Stack0 bit2 */
			{19476,51,0}, /* core4 return_Stack0 bit3 */
			{19266,51,0}, /* core4 return_Stack0 bit4 */
			{19264,51,0}, /* core4 return_Stack0 bit5 */
			{19262,51,0}, /* core4 return_Stack0 bit6 */
			{19260,51,0}, /* core4 return_Stack0 bit7 */
			{19274,51,0}, /* core4 return_Stack0 bit8 */
			{19272,51,0}, /* core4 return_Stack0 bit9 */
			{19270,51,0}, /* core4 return_Stack0 bit10 */
			{ 7838,51,0}, /* core4 return_Stack0 bit11 */
			{19268,51,0}, /* core4 return_Stack0 bit12 */
			{19250,51,0}, /* core4 return_Stack0 bit13 */
			{19248,51,0}, /* core4 return_Stack0 bit14 */
			{19246,51,0}, /* core4 return_Stack0 bit15 */
			{19244,51,0}, /* core4 return_Stack0 bit16 */
			{19442,51,0}, /* core4 return_Stack0 bit17 */
			{ 7836,51,0}, /* core4 return_Stack0 bit18 */
			{ 3022,51,0}, /* core4 return_Stack0 bit19 */
			{19440,51,0}, /* core4 return_Stack0 bit20 */
			{19438,51,0}, /* core4 return_Stack0 bit21 */
			{19436,51,0}, /* core4 return_Stack0 bit22 */
			{19426,51,0}, /* core4 return_Stack0 bit23 */
			{19424,51,0}, /* core4 return_Stack0 bit24 */
			{19422,51,0}, /* core4 return_Stack0 bit25 */
			{19420,51,0}, /* core4 return_Stack0 bit26 */
			{19434,51,0}, /* core4 return_Stack0 bit27 */
			{19432,51,0}, /* core4 return_Stack0 bit28 */
			{19430,51,0}, /* core4 return_Stack0 bit29 */
			{19428,51,0}, /* core4 return_Stack0 bit30 */
			{19394,51,0}, /* core4 return_Stack0 bit31 */
			{19392,51,0}, /* core4 return_Stack0 bit32 */
			{19390,51,0}, /* core4 return_Stack0 bit33 */
			{19388,51,0}, /* core4 return_Stack0 bit34 */
			{19378,51,0}, /* core4 return_Stack0 bit35 */
			{19376,51,0}, /* core4 return_Stack0 bit36 */
			{19374,51,0}, /* core4 return_Stack0 bit37 */
			{19372,51,0}, /* core4 return_Stack0 bit38 */
			{19362,51,0}, /* core4 return_Stack0 bit39 */
			{19360,51,0}, /* core4 return_Stack0 bit40 */
			{19358,51,0}, /* core4 return_Stack0 bit41 */
			{19356,51,0}, /* core4 return_Stack0 bit42 */
			{19498,51,0}, /* core4 return_Stack0 bit43 */
			{19496,51,0}, /* core4 return_Stack0 bit44 */
			{19494,51,0}, /* core4 return_Stack0 bit45 */
			{19492,51,0}, /* core4 return_Stack0 bit46 */
			{ 7846,51,0}, /* core4 return_Stack0 bit47 */
			{ 7844,51,0}, /* core4 return_Stack0 bit48 */
			{    0, 0,2}, /* core4 return_Stack0 bit49 */
			{    0, 0,2}, /* core4 return_Stack0 bit50 */
			{    0, 0,2}, /* core4 return_Stack0 bit51 */
			{    0, 0,2}, /* core4 return_Stack0 bit52 */
			{    0, 0,2}, /* core4 return_Stack0 bit53 */
			{    0, 0,2}, /* core4 return_Stack0 bit54 */
			{    0, 0,2}, /* core4 return_Stack0 bit55 */
			{    0, 0,2}, /* core4 return_Stack0 bit56 */
			{    0, 0,2}, /* core4 return_Stack0 bit57 */
			{    0, 0,2}, /* core4 return_Stack0 bit58 */
			{    0, 0,2}, /* core4 return_Stack0 bit59 */
			{    0, 0,2}, /* core4 return_Stack0 bit60 */
			{    0, 0,2}, /* core4 return_Stack0 bit61 */
			{    0, 0,2}, /* core4 return_Stack0 bit62 */
			{    0, 0,2}, /* core4 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{19490,51,0}, /* core4 return_Stack1 bit0 */
			{19488,51,0}, /* core4 return_Stack1 bit1 */
			{19486,51,0}, /* core4 return_Stack1 bit2 */
			{19484,51,0}, /* core4 return_Stack1 bit3 */
			{19242,51,0}, /* core4 return_Stack1 bit4 */
			{19240,51,0}, /* core4 return_Stack1 bit5 */
			{19466,51,0}, /* core4 return_Stack1 bit6 */
			{19238,51,0}, /* core4 return_Stack1 bit7 */
			{19236,51,0}, /* core4 return_Stack1 bit8 */
			{19258,51,0}, /* core4 return_Stack1 bit9 */
			{19256,51,0}, /* core4 return_Stack1 bit10 */
			{19464,51,0}, /* core4 return_Stack1 bit11 */
			{19254,51,0}, /* core4 return_Stack1 bit12 */
			{19252,51,0}, /* core4 return_Stack1 bit13 */
			{19474,51,0}, /* core4 return_Stack1 bit14 */
			{19472,51,0}, /* core4 return_Stack1 bit15 */
			{19470,51,0}, /* core4 return_Stack1 bit16 */
			{19468,51,0}, /* core4 return_Stack1 bit17 */
			{19462,51,0}, /* core4 return_Stack1 bit18 */
			{19460,51,0}, /* core4 return_Stack1 bit19 */
			{19410,51,0}, /* core4 return_Stack1 bit20 */
			{19408,51,0}, /* core4 return_Stack1 bit21 */
			{19406,51,0}, /* core4 return_Stack1 bit22 */
			{19404,51,0}, /* core4 return_Stack1 bit23 */
			{19418,51,0}, /* core4 return_Stack1 bit24 */
			{19416,51,0}, /* core4 return_Stack1 bit25 */
			{19414,51,0}, /* core4 return_Stack1 bit26 */
			{19412,51,0}, /* core4 return_Stack1 bit27 */
			{19402,51,0}, /* core4 return_Stack1 bit28 */
			{19400,51,0}, /* core4 return_Stack1 bit29 */
			{19398,51,0}, /* core4 return_Stack1 bit30 */
			{19396,51,0}, /* core4 return_Stack1 bit31 */
			{19386,51,0}, /* core4 return_Stack1 bit32 */
			{19384,51,0}, /* core4 return_Stack1 bit33 */
			{19382,51,0}, /* core4 return_Stack1 bit34 */
			{19380,51,0}, /* core4 return_Stack1 bit35 */
			{19370,51,0}, /* core4 return_Stack1 bit36 */
			{19368,51,0}, /* core4 return_Stack1 bit37 */
			{19366,51,0}, /* core4 return_Stack1 bit38 */
			{19364,51,0}, /* core4 return_Stack1 bit39 */
			{19354,51,0}, /* core4 return_Stack1 bit40 */
			{19346,51,0}, /* core4 return_Stack1 bit41 */
			{19344,51,0}, /* core4 return_Stack1 bit42 */
			{19352,51,0}, /* core4 return_Stack1 bit43 */
			{19350,51,0}, /* core4 return_Stack1 bit44 */
			{19342,51,0}, /* core4 return_Stack1 bit45 */
			{19348,51,0}, /* core4 return_Stack1 bit46 */
			{19340,51,0}, /* core4 return_Stack1 bit47 */
			{ 3024,51,0}, /* core4 return_Stack1 bit48 */
			{    0, 0,2}, /* core4 return_Stack1 bit49 */
			{    0, 0,2}, /* core4 return_Stack1 bit50 */
			{    0, 0,2}, /* core4 return_Stack1 bit51 */
			{    0, 0,2}, /* core4 return_Stack1 bit52 */
			{    0, 0,2}, /* core4 return_Stack1 bit53 */
			{    0, 0,2}, /* core4 return_Stack1 bit54 */
			{    0, 0,2}, /* core4 return_Stack1 bit55 */
			{    0, 0,2}, /* core4 return_Stack1 bit56 */
			{    0, 0,2}, /* core4 return_Stack1 bit57 */
			{    0, 0,2}, /* core4 return_Stack1 bit58 */
			{    0, 0,2}, /* core4 return_Stack1 bit59 */
			{    0, 0,2}, /* core4 return_Stack1 bit60 */
			{    0, 0,2}, /* core4 return_Stack1 bit61 */
			{    0, 0,2}, /* core4 return_Stack1 bit62 */
			{    0, 0,2}, /* core4 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{ 7850,51,0}, /* core4 return_Stack2 bit0 */
			{19282,51,0}, /* core4 return_Stack2 bit1 */
			{ 7848,51,0}, /* core4 return_Stack2 bit2 */
			{19280,51,0}, /* core4 return_Stack2 bit3 */
			{19278,51,0}, /* core4 return_Stack2 bit4 */
			{19234,51,0}, /* core4 return_Stack2 bit5 */
			{19276,51,0}, /* core4 return_Stack2 bit6 */
			{ 3028,51,0}, /* core4 return_Stack2 bit7 */
			{19232,51,0}, /* core4 return_Stack2 bit8 */
			{19230,51,0}, /* core4 return_Stack2 bit9 */
			{19218,51,0}, /* core4 return_Stack2 bit10 */
			{19228,51,0}, /* core4 return_Stack2 bit11 */
			{19216,51,0}, /* core4 return_Stack2 bit12 */
			{ 7834,51,0}, /* core4 return_Stack2 bit13 */
			{19214,51,0}, /* core4 return_Stack2 bit14 */
			{ 7832,51,0}, /* core4 return_Stack2 bit15 */
			{19212,51,0}, /* core4 return_Stack2 bit16 */
			{19202,51,0}, /* core4 return_Stack2 bit17 */
			{19200,51,0}, /* core4 return_Stack2 bit18 */
			{19198,51,0}, /* core4 return_Stack2 bit19 */
			{19196,51,0}, /* core4 return_Stack2 bit20 */
			{19178,51,0}, /* core4 return_Stack2 bit21 */
			{19176,51,0}, /* core4 return_Stack2 bit22 */
			{19174,51,0}, /* core4 return_Stack2 bit23 */
			{19172,51,0}, /* core4 return_Stack2 bit24 */
			{19170,51,0}, /* core4 return_Stack2 bit25 */
			{19168,51,0}, /* core4 return_Stack2 bit26 */
			{19166,51,0}, /* core4 return_Stack2 bit27 */
			{19164,51,0}, /* core4 return_Stack2 bit28 */
			{19138,51,0}, /* core4 return_Stack2 bit29 */
			{19136,51,0}, /* core4 return_Stack2 bit30 */
			{19134,51,0}, /* core4 return_Stack2 bit31 */
			{19132,51,0}, /* core4 return_Stack2 bit32 */
			{19538,51,0}, /* core4 return_Stack2 bit33 */
			{19536,51,0}, /* core4 return_Stack2 bit34 */
			{19534,51,0}, /* core4 return_Stack2 bit35 */
			{19532,51,0}, /* core4 return_Stack2 bit36 */
			{19522,51,0}, /* core4 return_Stack2 bit37 */
			{19520,51,0}, /* core4 return_Stack2 bit38 */
			{19518,51,0}, /* core4 return_Stack2 bit39 */
			{19516,51,0}, /* core4 return_Stack2 bit40 */
			{19514,51,0}, /* core4 return_Stack2 bit41 */
			{19512,51,0}, /* core4 return_Stack2 bit42 */
			{19510,51,0}, /* core4 return_Stack2 bit43 */
			{19508,51,0}, /* core4 return_Stack2 bit44 */
			{19338,51,0}, /* core4 return_Stack2 bit45 */
			{19336,51,0}, /* core4 return_Stack2 bit46 */
			{19334,51,0}, /* core4 return_Stack2 bit47 */
			{19332,51,0}, /* core4 return_Stack2 bit48 */
			{    0, 0,2}, /* core4 return_Stack2 bit49 */
			{    0, 0,2}, /* core4 return_Stack2 bit50 */
			{    0, 0,2}, /* core4 return_Stack2 bit51 */
			{    0, 0,2}, /* core4 return_Stack2 bit52 */
			{    0, 0,2}, /* core4 return_Stack2 bit53 */
			{    0, 0,2}, /* core4 return_Stack2 bit54 */
			{    0, 0,2}, /* core4 return_Stack2 bit55 */
			{    0, 0,2}, /* core4 return_Stack2 bit56 */
			{    0, 0,2}, /* core4 return_Stack2 bit57 */
			{    0, 0,2}, /* core4 return_Stack2 bit58 */
			{    0, 0,2}, /* core4 return_Stack2 bit59 */
			{    0, 0,2}, /* core4 return_Stack2 bit60 */
			{    0, 0,2}, /* core4 return_Stack2 bit61 */
			{    0, 0,2}, /* core4 return_Stack2 bit62 */
			{    0, 0,2}, /* core4 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{ 3030,51,0}, /* core4 return_Stack3 bit0 */
			{19322,51,0}, /* core4 return_Stack3 bit1 */
			{19320,51,0}, /* core4 return_Stack3 bit2 */
			{19318,51,0}, /* core4 return_Stack3 bit3 */
			{19316,51,0}, /* core4 return_Stack3 bit4 */
			{19290,51,0}, /* core4 return_Stack3 bit5 */
			{19288,51,0}, /* core4 return_Stack3 bit6 */
			{19286,51,0}, /* core4 return_Stack3 bit7 */
			{19284,51,0}, /* core4 return_Stack3 bit8 */
			{19226,51,0}, /* core4 return_Stack3 bit9 */
			{19224,51,0}, /* core4 return_Stack3 bit10 */
			{19222,51,0}, /* core4 return_Stack3 bit11 */
			{19220,51,0}, /* core4 return_Stack3 bit12 */
			{19210,51,0}, /* core4 return_Stack3 bit13 */
			{19208,51,0}, /* core4 return_Stack3 bit14 */
			{19206,51,0}, /* core4 return_Stack3 bit15 */
			{19204,51,0}, /* core4 return_Stack3 bit16 */
			{19194,51,0}, /* core4 return_Stack3 bit17 */
			{19192,51,0}, /* core4 return_Stack3 bit18 */
			{19190,51,0}, /* core4 return_Stack3 bit19 */
			{19188,51,0}, /* core4 return_Stack3 bit20 */
			{19186,51,0}, /* core4 return_Stack3 bit21 */
			{19184,51,0}, /* core4 return_Stack3 bit22 */
			{19182,51,0}, /* core4 return_Stack3 bit23 */
			{19180,51,0}, /* core4 return_Stack3 bit24 */
			{19162,51,0}, /* core4 return_Stack3 bit25 */
			{19160,51,0}, /* core4 return_Stack3 bit26 */
			{19158,51,0}, /* core4 return_Stack3 bit27 */
			{19156,51,0}, /* core4 return_Stack3 bit28 */
			{19130,51,0}, /* core4 return_Stack3 bit29 */
			{19128,51,0}, /* core4 return_Stack3 bit30 */
			{19126,51,0}, /* core4 return_Stack3 bit31 */
			{19124,51,0}, /* core4 return_Stack3 bit32 */
			{19546,51,0}, /* core4 return_Stack3 bit33 */
			{19544,51,0}, /* core4 return_Stack3 bit34 */
			{19542,51,0}, /* core4 return_Stack3 bit35 */
			{19540,51,0}, /* core4 return_Stack3 bit36 */
			{19530,51,0}, /* core4 return_Stack3 bit37 */
			{19528,51,0}, /* core4 return_Stack3 bit38 */
			{19526,51,0}, /* core4 return_Stack3 bit39 */
			{19524,51,0}, /* core4 return_Stack3 bit40 */
			{19506,51,0}, /* core4 return_Stack3 bit41 */
			{19504,51,0}, /* core4 return_Stack3 bit42 */
			{19502,51,0}, /* core4 return_Stack3 bit43 */
			{19500,51,0}, /* core4 return_Stack3 bit44 */
			{19330,51,0}, /* core4 return_Stack3 bit45 */
			{19328,51,0}, /* core4 return_Stack3 bit46 */
			{19326,51,0}, /* core4 return_Stack3 bit47 */
			{19324,51,0}, /* core4 return_Stack3 bit48 */
			{    0, 0,2}, /* core4 return_Stack3 bit49 */
			{    0, 0,2}, /* core4 return_Stack3 bit50 */
			{    0, 0,2}, /* core4 return_Stack3 bit51 */
			{    0, 0,2}, /* core4 return_Stack3 bit52 */
			{    0, 0,2}, /* core4 return_Stack3 bit53 */
			{    0, 0,2}, /* core4 return_Stack3 bit54 */
			{    0, 0,2}, /* core4 return_Stack3 bit55 */
			{    0, 0,2}, /* core4 return_Stack3 bit56 */
			{    0, 0,2}, /* core4 return_Stack3 bit57 */
			{    0, 0,2}, /* core4 return_Stack3 bit58 */
			{    0, 0,2}, /* core4 return_Stack3 bit59 */
			{    0, 0,2}, /* core4 return_Stack3 bit60 */
			{    0, 0,2}, /* core4 return_Stack3 bit61 */
			{    0, 0,2}, /* core4 return_Stack3 bit62 */
			{    0, 0,2}, /* core4 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{19314,51,0}, /* core4 return_Stack4 bit0 */
			{19312,51,0}, /* core4 return_Stack4 bit1 */
			{19310,51,0}, /* core4 return_Stack4 bit2 */
			{19308,51,0}, /* core4 return_Stack4 bit3 */
			{19306,51,0}, /* core4 return_Stack4 bit4 */
			{19304,51,0}, /* core4 return_Stack4 bit5 */
			{19302,51,0}, /* core4 return_Stack4 bit6 */
			{19300,51,0}, /* core4 return_Stack4 bit7 */
			{19298,51,0}, /* core4 return_Stack4 bit8 */
			{19296,51,0}, /* core4 return_Stack4 bit9 */
			{19294,51,0}, /* core4 return_Stack4 bit10 */
			{19292,51,0}, /* core4 return_Stack4 bit11 */
			{19458,51,0}, /* core4 return_Stack4 bit12 */
			{ 7842,51,0}, /* core4 return_Stack4 bit13 */
			{19456,51,0}, /* core4 return_Stack4 bit14 */
			{ 7840,51,0}, /* core4 return_Stack4 bit15 */
			{19454,51,0}, /* core4 return_Stack4 bit16 */
			{19452,51,0}, /* core4 return_Stack4 bit17 */
			{19450,51,0}, /* core4 return_Stack4 bit18 */
			{19448,51,0}, /* core4 return_Stack4 bit19 */
			{19446,51,0}, /* core4 return_Stack4 bit20 */
			{19444,51,0}, /* core4 return_Stack4 bit21 */
			{19146,51,0}, /* core4 return_Stack4 bit22 */
			{19144,51,0}, /* core4 return_Stack4 bit23 */
			{19142,51,0}, /* core4 return_Stack4 bit24 */
			{19140,51,0}, /* core4 return_Stack4 bit25 */
			{19154,51,0}, /* core4 return_Stack4 bit26 */
			{19152,51,0}, /* core4 return_Stack4 bit27 */
			{19150,51,0}, /* core4 return_Stack4 bit28 */
			{19148,51,0}, /* core4 return_Stack4 bit29 */
			{19122,51,0}, /* core4 return_Stack4 bit30 */
			{19120,51,0}, /* core4 return_Stack4 bit31 */
			{19118,51,0}, /* core4 return_Stack4 bit32 */
			{19116,51,0}, /* core4 return_Stack4 bit33 */
			{19114,51,0}, /* core4 return_Stack4 bit34 */
			{19112,51,0}, /* core4 return_Stack4 bit35 */
			{19110,51,0}, /* core4 return_Stack4 bit36 */
			{19108,51,0}, /* core4 return_Stack4 bit37 */
			{19046,51,0}, /* core4 return_Stack4 bit38 */
			{19044,51,0}, /* core4 return_Stack4 bit39 */
			{19042,51,0}, /* core4 return_Stack4 bit40 */
			{19040,51,0}, /* core4 return_Stack4 bit41 */
			{19054,51,0}, /* core4 return_Stack4 bit42 */
			{19052,51,0}, /* core4 return_Stack4 bit43 */
			{19050,51,0}, /* core4 return_Stack4 bit44 */
			{19048,51,0}, /* core4 return_Stack4 bit45 */
			{ 7854,51,0}, /* core4 return_Stack4 bit46 */
			{ 7852,51,0}, /* core4 return_Stack4 bit47 */
			{ 3026,51,0}, /* core4 return_Stack4 bit48 */
			{    0, 0,2}, /* core4 return_Stack4 bit49 */
			{    0, 0,2}, /* core4 return_Stack4 bit50 */
			{    0, 0,2}, /* core4 return_Stack4 bit51 */
			{    0, 0,2}, /* core4 return_Stack4 bit52 */
			{    0, 0,2}, /* core4 return_Stack4 bit53 */
			{    0, 0,2}, /* core4 return_Stack4 bit54 */
			{    0, 0,2}, /* core4 return_Stack4 bit55 */
			{    0, 0,2}, /* core4 return_Stack4 bit56 */
			{    0, 0,2}, /* core4 return_Stack4 bit57 */
			{    0, 0,2}, /* core4 return_Stack4 bit58 */
			{    0, 0,2}, /* core4 return_Stack4 bit59 */
			{    0, 0,2}, /* core4 return_Stack4 bit60 */
			{    0, 0,2}, /* core4 return_Stack4 bit61 */
			{    0, 0,2}, /* core4 return_Stack4 bit62 */
			{    0, 0,2}, /* core4 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{18982,51,0}, /* core4 return_Stack5 bit0 */
			{18980,51,0}, /* core4 return_Stack5 bit1 */
			{18978,51,0}, /* core4 return_Stack5 bit2 */
			{18976,51,0}, /* core4 return_Stack5 bit3 */
			{18958,51,0}, /* core4 return_Stack5 bit4 */
			{18942,51,0}, /* core4 return_Stack5 bit5 */
			{18956,51,0}, /* core4 return_Stack5 bit6 */
			{18954,51,0}, /* core4 return_Stack5 bit7 */
			{18952,51,0}, /* core4 return_Stack5 bit8 */
			{18940,51,0}, /* core4 return_Stack5 bit9 */
			{18938,51,0}, /* core4 return_Stack5 bit10 */
			{18936,51,0}, /* core4 return_Stack5 bit11 */
			{18918,51,0}, /* core4 return_Stack5 bit12 */
			{18916,51,0}, /* core4 return_Stack5 bit13 */
			{18914,51,0}, /* core4 return_Stack5 bit14 */
			{18912,51,0}, /* core4 return_Stack5 bit15 */
			{18886,51,0}, /* core4 return_Stack5 bit16 */
			{18884,51,0}, /* core4 return_Stack5 bit17 */
			{18882,51,0}, /* core4 return_Stack5 bit18 */
			{18880,51,0}, /* core4 return_Stack5 bit19 */
			{18838,51,0}, /* core4 return_Stack5 bit20 */
			{18836,51,0}, /* core4 return_Stack5 bit21 */
			{18834,51,0}, /* core4 return_Stack5 bit22 */
			{18832,51,0}, /* core4 return_Stack5 bit23 */
			{18830,51,0}, /* core4 return_Stack5 bit24 */
			{18828,51,0}, /* core4 return_Stack5 bit25 */
			{18826,51,0}, /* core4 return_Stack5 bit26 */
			{18824,51,0}, /* core4 return_Stack5 bit27 */
			{19014,51,0}, /* core4 return_Stack5 bit28 */
			{19012,51,0}, /* core4 return_Stack5 bit29 */
			{19010,51,0}, /* core4 return_Stack5 bit30 */
			{19008,51,0}, /* core4 return_Stack5 bit31 */
			{19022,51,0}, /* core4 return_Stack5 bit32 */
			{ 7894,51,0}, /* core4 return_Stack5 bit33 */
			{19020,51,0}, /* core4 return_Stack5 bit34 */
			{19018,51,0}, /* core4 return_Stack5 bit35 */
			{19016,51,0}, /* core4 return_Stack5 bit36 */
			{ 7892,51,0}, /* core4 return_Stack5 bit37 */
			{19086,51,0}, /* core4 return_Stack5 bit38 */
			{19084,51,0}, /* core4 return_Stack5 bit39 */
			{19082,51,0}, /* core4 return_Stack5 bit40 */
			{19080,51,0}, /* core4 return_Stack5 bit41 */
			{19062,51,0}, /* core4 return_Stack5 bit42 */
			{19060,51,0}, /* core4 return_Stack5 bit43 */
			{19058,51,0}, /* core4 return_Stack5 bit44 */
			{19056,51,0}, /* core4 return_Stack5 bit45 */
			{ 7862,51,0}, /* core4 return_Stack5 bit46 */
			{ 7860,51,0}, /* core4 return_Stack5 bit47 */
			{ 3034,51,0}, /* core4 return_Stack5 bit48 */
			{    0, 0,2}, /* core4 return_Stack5 bit49 */
			{    0, 0,2}, /* core4 return_Stack5 bit50 */
			{    0, 0,2}, /* core4 return_Stack5 bit51 */
			{    0, 0,2}, /* core4 return_Stack5 bit52 */
			{    0, 0,2}, /* core4 return_Stack5 bit53 */
			{    0, 0,2}, /* core4 return_Stack5 bit54 */
			{    0, 0,2}, /* core4 return_Stack5 bit55 */
			{    0, 0,2}, /* core4 return_Stack5 bit56 */
			{    0, 0,2}, /* core4 return_Stack5 bit57 */
			{    0, 0,2}, /* core4 return_Stack5 bit58 */
			{    0, 0,2}, /* core4 return_Stack5 bit59 */
			{    0, 0,2}, /* core4 return_Stack5 bit60 */
			{    0, 0,2}, /* core4 return_Stack5 bit61 */
			{    0, 0,2}, /* core4 return_Stack5 bit62 */
			{    0, 0,2}, /* core4 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{18990,51,0}, /* core4 return_Stack6 bit0 */
			{18988,51,0}, /* core4 return_Stack6 bit1 */
			{18986,51,0}, /* core4 return_Stack6 bit2 */
			{18984,51,0}, /* core4 return_Stack6 bit3 */
			{18950,51,0}, /* core4 return_Stack6 bit4 */
			{18926,51,0}, /* core4 return_Stack6 bit5 */
			{18948,51,0}, /* core4 return_Stack6 bit6 */
			{18946,51,0}, /* core4 return_Stack6 bit7 */
			{18944,51,0}, /* core4 return_Stack6 bit8 */
			{18924,51,0}, /* core4 return_Stack6 bit9 */
			{18922,51,0}, /* core4 return_Stack6 bit10 */
			{18920,51,0}, /* core4 return_Stack6 bit11 */
			{18902,51,0}, /* core4 return_Stack6 bit12 */
			{18900,51,0}, /* core4 return_Stack6 bit13 */
			{18898,51,0}, /* core4 return_Stack6 bit14 */
			{18896,51,0}, /* core4 return_Stack6 bit15 */
			{18894,51,0}, /* core4 return_Stack6 bit16 */
			{18892,51,0}, /* core4 return_Stack6 bit17 */
			{18890,51,0}, /* core4 return_Stack6 bit18 */
			{18888,51,0}, /* core4 return_Stack6 bit19 */
			{18862,51,0}, /* core4 return_Stack6 bit20 */
			{18860,51,0}, /* core4 return_Stack6 bit21 */
			{18858,51,0}, /* core4 return_Stack6 bit22 */
			{18856,51,0}, /* core4 return_Stack6 bit23 */
			{18846,51,0}, /* core4 return_Stack6 bit24 */
			{18844,51,0}, /* core4 return_Stack6 bit25 */
			{18842,51,0}, /* core4 return_Stack6 bit26 */
			{18840,51,0}, /* core4 return_Stack6 bit27 */
			{19006,51,0}, /* core4 return_Stack6 bit28 */
			{19004,51,0}, /* core4 return_Stack6 bit29 */
			{19002,51,0}, /* core4 return_Stack6 bit30 */
			{19000,51,0}, /* core4 return_Stack6 bit31 */
			{19030,51,0}, /* core4 return_Stack6 bit32 */
			{ 7886,51,0}, /* core4 return_Stack6 bit33 */
			{19028,51,0}, /* core4 return_Stack6 bit34 */
			{19026,51,0}, /* core4 return_Stack6 bit35 */
			{19024,51,0}, /* core4 return_Stack6 bit36 */
			{ 7884,51,0}, /* core4 return_Stack6 bit37 */
			{19102,51,0}, /* core4 return_Stack6 bit38 */
			{19100,51,0}, /* core4 return_Stack6 bit39 */
			{19098,51,0}, /* core4 return_Stack6 bit40 */
			{19096,51,0}, /* core4 return_Stack6 bit41 */
			{19070,51,0}, /* core4 return_Stack6 bit42 */
			{19068,51,0}, /* core4 return_Stack6 bit43 */
			{19066,51,0}, /* core4 return_Stack6 bit44 */
			{19064,51,0}, /* core4 return_Stack6 bit45 */
			{ 7866,51,0}, /* core4 return_Stack6 bit46 */
			{ 7864,51,0}, /* core4 return_Stack6 bit47 */
			{ 3036,51,0}, /* core4 return_Stack6 bit48 */
			{    0, 0,2}, /* core4 return_Stack6 bit49 */
			{    0, 0,2}, /* core4 return_Stack6 bit50 */
			{    0, 0,2}, /* core4 return_Stack6 bit51 */
			{    0, 0,2}, /* core4 return_Stack6 bit52 */
			{    0, 0,2}, /* core4 return_Stack6 bit53 */
			{    0, 0,2}, /* core4 return_Stack6 bit54 */
			{    0, 0,2}, /* core4 return_Stack6 bit55 */
			{    0, 0,2}, /* core4 return_Stack6 bit56 */
			{    0, 0,2}, /* core4 return_Stack6 bit57 */
			{    0, 0,2}, /* core4 return_Stack6 bit58 */
			{    0, 0,2}, /* core4 return_Stack6 bit59 */
			{    0, 0,2}, /* core4 return_Stack6 bit60 */
			{    0, 0,2}, /* core4 return_Stack6 bit61 */
			{    0, 0,2}, /* core4 return_Stack6 bit62 */
			{    0, 0,2}, /* core4 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{18974,51,0}, /* core4 return_Stack7 bit0 */
			{18972,51,0}, /* core4 return_Stack7 bit1 */
			{18970,51,0}, /* core4 return_Stack7 bit2 */
			{18968,51,0}, /* core4 return_Stack7 bit3 */
			{18966,51,0}, /* core4 return_Stack7 bit4 */
			{18934,51,0}, /* core4 return_Stack7 bit5 */
			{18964,51,0}, /* core4 return_Stack7 bit6 */
			{18962,51,0}, /* core4 return_Stack7 bit7 */
			{18960,51,0}, /* core4 return_Stack7 bit8 */
			{18932,51,0}, /* core4 return_Stack7 bit9 */
			{18930,51,0}, /* core4 return_Stack7 bit10 */
			{18928,51,0}, /* core4 return_Stack7 bit11 */
			{18910,51,0}, /* core4 return_Stack7 bit12 */
			{18908,51,0}, /* core4 return_Stack7 bit13 */
			{18906,51,0}, /* core4 return_Stack7 bit14 */
			{18904,51,0}, /* core4 return_Stack7 bit15 */
			{18878,51,0}, /* core4 return_Stack7 bit16 */
			{18876,51,0}, /* core4 return_Stack7 bit17 */
			{18874,51,0}, /* core4 return_Stack7 bit18 */
			{18872,51,0}, /* core4 return_Stack7 bit19 */
			{18870,51,0}, /* core4 return_Stack7 bit20 */
			{18868,51,0}, /* core4 return_Stack7 bit21 */
			{18866,51,0}, /* core4 return_Stack7 bit22 */
			{18864,51,0}, /* core4 return_Stack7 bit23 */
			{18854,51,0}, /* core4 return_Stack7 bit24 */
			{18852,51,0}, /* core4 return_Stack7 bit25 */
			{18850,51,0}, /* core4 return_Stack7 bit26 */
			{18848,51,0}, /* core4 return_Stack7 bit27 */
			{18998,51,0}, /* core4 return_Stack7 bit28 */
			{18996,51,0}, /* core4 return_Stack7 bit29 */
			{18994,51,0}, /* core4 return_Stack7 bit30 */
			{18992,51,0}, /* core4 return_Stack7 bit31 */
			{19038,51,0}, /* core4 return_Stack7 bit32 */
			{ 7890,51,0}, /* core4 return_Stack7 bit33 */
			{19036,51,0}, /* core4 return_Stack7 bit34 */
			{19034,51,0}, /* core4 return_Stack7 bit35 */
			{19032,51,0}, /* core4 return_Stack7 bit36 */
			{ 7888,51,0}, /* core4 return_Stack7 bit37 */
			{19094,51,0}, /* core4 return_Stack7 bit38 */
			{19092,51,0}, /* core4 return_Stack7 bit39 */
			{19090,51,0}, /* core4 return_Stack7 bit40 */
			{19088,51,0}, /* core4 return_Stack7 bit41 */
			{19078,51,0}, /* core4 return_Stack7 bit42 */
			{19076,51,0}, /* core4 return_Stack7 bit43 */
			{19074,51,0}, /* core4 return_Stack7 bit44 */
			{19072,51,0}, /* core4 return_Stack7 bit45 */
			{ 7858,51,0}, /* core4 return_Stack7 bit46 */
			{ 7856,51,0}, /* core4 return_Stack7 bit47 */
			{ 3032,51,0}, /* core4 return_Stack7 bit48 */
			{    0, 0,2}, /* core4 return_Stack7 bit49 */
			{    0, 0,2}, /* core4 return_Stack7 bit50 */
			{    0, 0,2}, /* core4 return_Stack7 bit51 */
			{    0, 0,2}, /* core4 return_Stack7 bit52 */
			{    0, 0,2}, /* core4 return_Stack7 bit53 */
			{    0, 0,2}, /* core4 return_Stack7 bit54 */
			{    0, 0,2}, /* core4 return_Stack7 bit55 */
			{    0, 0,2}, /* core4 return_Stack7 bit56 */
			{    0, 0,2}, /* core4 return_Stack7 bit57 */
			{    0, 0,2}, /* core4 return_Stack7 bit58 */
			{    0, 0,2}, /* core4 return_Stack7 bit59 */
			{    0, 0,2}, /* core4 return_Stack7 bit60 */
			{    0, 0,2}, /* core4 return_Stack7 bit61 */
			{    0, 0,2}, /* core4 return_Stack7 bit62 */
			{    0, 0,2}, /* core4 return_Stack7 bit63 */
			}},
	},
	{		/* core 5 */ 
			.pc = {{
			{ 2688,54,1}, /* core5 pc bit0 */
			{ 2686,54,1}, /* core5 pc bit1 */
			{ 2684,54,1}, /* core5 pc bit2 */
			{ 2682,54,1}, /* core5 pc bit3 */
			{ 2592,54,1}, /* core5 pc bit4 */
			{ 2590,54,1}, /* core5 pc bit5 */
			{ 2588,54,1}, /* core5 pc bit6 */
			{ 2586,54,1}, /* core5 pc bit7 */
			{ 2584,54,1}, /* core5 pc bit8 */
			{ 2582,54,1}, /* core5 pc bit9 */
			{ 2580,54,1}, /* core5 pc bit10 */
			{ 2578,54,1}, /* core5 pc bit11 */
			{ 2600,54,1}, /* core5 pc bit12 */
			{ 2598,54,1}, /* core5 pc bit13 */
			{ 2596,54,1}, /* core5 pc bit14 */
			{ 2594,54,1}, /* core5 pc bit15 */
			{ 2448,54,1}, /* core5 pc bit16 */
			{ 2446,54,1}, /* core5 pc bit17 */
			{ 2444,54,1}, /* core5 pc bit18 */
			{ 2442,54,1}, /* core5 pc bit19 */
			{ 2432,54,1}, /* core5 pc bit20 */
			{ 2430,54,1}, /* core5 pc bit21 */
			{ 2428,54,1}, /* core5 pc bit22 */
			{ 2426,54,1}, /* core5 pc bit23 */
			{ 2352,54,1}, /* core5 pc bit24 */
			{ 2350,54,1}, /* core5 pc bit25 */
			{ 2348,54,1}, /* core5 pc bit26 */
			{ 2346,54,1}, /* core5 pc bit27 */
			{ 2344,54,1}, /* core5 pc bit28 */
			{ 2342,54,1}, /* core5 pc bit29 */
			{ 2340,54,1}, /* core5 pc bit30 */
			{ 2338,54,1}, /* core5 pc bit31 */
			{ 2656,54,1}, /* core5 pc bit32 */
			{ 2654,54,1}, /* core5 pc bit33 */
			{ 2652,54,1}, /* core5 pc bit34 */
			{ 2650,54,1}, /* core5 pc bit35 */
			{ 2616,54,1}, /* core5 pc bit36 */
			{ 2614,54,1}, /* core5 pc bit37 */
			{ 2612,54,1}, /* core5 pc bit38 */
			{ 2610,54,1}, /* core5 pc bit39 */
			{ 2632,54,1}, /* core5 pc bit40 */
			{ 2630,54,1}, /* core5 pc bit41 */
			{  676,54,1}, /* core5 pc bit42 */
			{ 2628,54,1}, /* core5 pc bit43 */
			{ 2626,54,1}, /* core5 pc bit44 */
			{ 2608,54,1}, /* core5 pc bit45 */
			{ 2606,54,1}, /* core5 pc bit46 */
			{ 2604,54,1}, /* core5 pc bit47 */
			{ 2602,54,1}, /* core5 pc bit48 */
			{ 2400,54,1}, /* core5 pc bit49 */
			{ 2398,54,1}, /* core5 pc bit50 */
			{ 2396,54,1}, /* core5 pc bit51 */
			{ 2394,54,1}, /* core5 pc bit52 */
			{ 2312,54,1}, /* core5 pc bit53 */
			{ 2310,54,1}, /* core5 pc bit54 */
			{ 2308,54,1}, /* core5 pc bit55 */
			{ 2306,54,1}, /* core5 pc bit56 */
			{ 2164,54,1}, /* core5 pc bit57 */
			{ 2162,54,1}, /* core5 pc bit58 */
			{ 2160,54,1}, /* core5 pc bit59 */
			{ 2158,54,1}, /* core5 pc bit60 */
			{  682,54,1}, /* core5 pc bit61 */
			{  680,54,1}, /* core5 pc bit62 */
			{ 2228,54,1}, /* core5 pc bit63 */
			}},
			.sp32 = {{
			{32298,54,0}, /* core5 sp32 bit0 */
			{40686,54,0}, /* core5 sp32 bit1 */
			{32308,54,0}, /* core5 sp32 bit2 */
			{40522,54,0}, /* core5 sp32 bit3 */
			{40684,54,0}, /* core5 sp32 bit4 */
			{40682,54,0}, /* core5 sp32 bit5 */
			{40680,54,0}, /* core5 sp32 bit6 */
			{40690,54,0}, /* core5 sp32 bit7 */
			{40688,54,0}, /* core5 sp32 bit8 */
			{40654,54,0}, /* core5 sp32 bit9 */
			{40520,54,0}, /* core5 sp32 bit10 */
			{40526,54,0}, /* core5 sp32 bit11 */
			{40524,54,0}, /* core5 sp32 bit12 */
			{40646,54,0}, /* core5 sp32 bit13 */
			{40652,54,0}, /* core5 sp32 bit14 */
			{40644,54,0}, /* core5 sp32 bit15 */
			{40642,54,0}, /* core5 sp32 bit16 */
			{40640,54,0}, /* core5 sp32 bit17 */
			{32264,54,0}, /* core5 sp32 bit18 */
			{40614,54,0}, /* core5 sp32 bit19 */
			{40612,54,0}, /* core5 sp32 bit20 */
			{40510,54,0}, /* core5 sp32 bit21 */
			{32260,54,0}, /* core5 sp32 bit22 */
			{40508,54,0}, /* core5 sp32 bit23 */
			{40490,54,0}, /* core5 sp32 bit24 */
			{40488,54,0}, /* core5 sp32 bit25 */
			{40564,54,0}, /* core5 sp32 bit26 */
			{40562,54,0}, /* core5 sp32 bit27 */
			{40560,54,0}, /* core5 sp32 bit28 */
			{40566,54,0}, /* core5 sp32 bit29 */
			{32258,54,0}, /* core5 sp32 bit30 */
			{32256,54,0}, /* core5 sp32 bit31 */
			{40362,54,0}, /* core5 sp32 bit32 */
			{40360,54,0}, /* core5 sp32 bit33 */
			{40354,54,0}, /* core5 sp32 bit34 */
			{40352,54,0}, /* core5 sp32 bit35 */
			{40358,54,0}, /* core5 sp32 bit36 */
			{40356,54,0}, /* core5 sp32 bit37 */
			{31992,54,0}, /* core5 sp32 bit38 */
			{40350,54,0}, /* core5 sp32 bit39 */
			{40348,54,0}, /* core5 sp32 bit40 */
			{40322,54,0}, /* core5 sp32 bit41 */
			{40320,54,0}, /* core5 sp32 bit42 */
			{32028,54,0}, /* core5 sp32 bit43 */
			{40318,54,0}, /* core5 sp32 bit44 */
			{32030,54,0}, /* core5 sp32 bit45 */
			{40316,54,0}, /* core5 sp32 bit46 */
			{32032,54,0}, /* core5 sp32 bit47 */
			{47404,54,0}, /* core5 sp32 bit48 */
			{47402,54,0}, /* core5 sp32 bit49 */
			{47400,54,0}, /* core5 sp32 bit50 */
			{47398,54,0}, /* core5 sp32 bit51 */
			{47332,54,0}, /* core5 sp32 bit52 */
			{47330,54,0}, /* core5 sp32 bit53 */
			{47328,54,0}, /* core5 sp32 bit54 */
			{47326,54,0}, /* core5 sp32 bit55 */
			{47340,54,0}, /* core5 sp32 bit56 */
			{47338,54,0}, /* core5 sp32 bit57 */
			{47336,54,0}, /* core5 sp32 bit58 */
			{47334,54,0}, /* core5 sp32 bit59 */
			{47348,54,0}, /* core5 sp32 bit60 */
			{47346,54,0}, /* core5 sp32 bit61 */
			{47344,54,0}, /* core5 sp32 bit62 */
			{47342,54,0}, /* core5 sp32 bit63 */
			}},
			.fp32 = {{
			{32654,54,0}, /* core5 fp32 bit0 */
			{32322,54,0}, /* core5 fp32 bit1 */
			{40906,54,0}, /* core5 fp32 bit2 */
			{40900,54,0}, /* core5 fp32 bit3 */
			{40976,54,0}, /* core5 fp32 bit4 */
			{40974,54,0}, /* core5 fp32 bit5 */
			{40972,54,0}, /* core5 fp32 bit6 */
			{32646,54,0}, /* core5 fp32 bit7 */
			{40970,54,0}, /* core5 fp32 bit8 */
			{32320,54,0}, /* core5 fp32 bit9 */
			{40896,54,0}, /* core5 fp32 bit10 */
			{40904,54,0}, /* core5 fp32 bit11 */
			{40898,54,0}, /* core5 fp32 bit12 */
			{32390,54,0}, /* core5 fp32 bit13 */
			{40908,54,0}, /* core5 fp32 bit14 */
			{40902,54,0}, /* core5 fp32 bit15 */
			{40920,54,0}, /* core5 fp32 bit16 */
			{40918,54,0}, /* core5 fp32 bit17 */
			{32418,54,0}, /* core5 fp32 bit18 */
			{32386,54,0}, /* core5 fp32 bit19 */
			{40894,54,0}, /* core5 fp32 bit20 */
			{32348,54,0}, /* core5 fp32 bit21 */
			{32412,54,0}, /* core5 fp32 bit22 */
			{32334,54,0}, /* core5 fp32 bit23 */
			{32336,54,0}, /* core5 fp32 bit24 */
			{32342,54,0}, /* core5 fp32 bit25 */
			{40916,54,0}, /* core5 fp32 bit26 */
			{40914,54,0}, /* core5 fp32 bit27 */
			{32388,54,0}, /* core5 fp32 bit28 */
			{40924,54,0}, /* core5 fp32 bit29 */
			{40922,54,0}, /* core5 fp32 bit30 */
			{32424,54,0}, /* core5 fp32 bit31 */
			{41026,54,0}, /* core5 fp32 bit32 */
			{32578,54,0}, /* core5 fp32 bit33 */
			{41036,54,0}, /* core5 fp32 bit34 */
			{41022,54,0}, /* core5 fp32 bit35 */
			{41024,54,0}, /* core5 fp32 bit36 */
			{41028,54,0}, /* core5 fp32 bit37 */
			{32580,54,0}, /* core5 fp32 bit38 */
			{32582,54,0}, /* core5 fp32 bit39 */
			{41032,54,0}, /* core5 fp32 bit40 */
			{41030,54,0}, /* core5 fp32 bit41 */
			{41040,54,0}, /* core5 fp32 bit42 */
			{32552,54,0}, /* core5 fp32 bit43 */
			{41038,54,0}, /* core5 fp32 bit44 */
			{40992,54,0}, /* core5 fp32 bit45 */
			{41034,54,0}, /* core5 fp32 bit46 */
			{40990,54,0}, /* core5 fp32 bit47 */
			{32614,54,0}, /* core5 fp32 bit48 */
			{41064,54,0}, /* core5 fp32 bit49 */
			{47526,54,0}, /* core5 fp32 bit50 */
			{47524,54,0}, /* core5 fp32 bit51 */
			{47520,54,0}, /* core5 fp32 bit52 */
			{47430,54,0}, /* core5 fp32 bit53 */
			{47428,54,0}, /* core5 fp32 bit54 */
			{47426,54,0}, /* core5 fp32 bit55 */
			{47422,54,0}, /* core5 fp32 bit56 */
			{47424,54,0}, /* core5 fp32 bit57 */
			{47420,54,0}, /* core5 fp32 bit58 */
			{41062,54,0}, /* core5 fp32 bit59 */
			{47418,54,0}, /* core5 fp32 bit60 */
			{47416,54,0}, /* core5 fp32 bit61 */
			{32634,54,0}, /* core5 fp32 bit62 */
			{47518,54,0}, /* core5 fp32 bit63 */
			}},
			.fp64 = {{
			{32172,54,0}, /* core5 fp64 bit0 */
			{31886,54,0}, /* core5 fp64 bit1 */
			{39704,54,0}, /* core5 fp64 bit2 */
			{39782,54,0}, /* core5 fp64 bit3 */
			{32160,54,0}, /* core5 fp64 bit4 */
			{39662,54,0}, /* core5 fp64 bit5 */
			{39650,54,0}, /* core5 fp64 bit6 */
			{39648,54,0}, /* core5 fp64 bit7 */
			{39682,54,0}, /* core5 fp64 bit8 */
			{39660,54,0}, /* core5 fp64 bit9 */
			{31822,54,0}, /* core5 fp64 bit10 */
			{31824,54,0}, /* core5 fp64 bit11 */
			{31818,54,0}, /* core5 fp64 bit12 */
			{32222,54,0}, /* core5 fp64 bit13 */
			{39680,54,0}, /* core5 fp64 bit14 */
			{32224,54,0}, /* core5 fp64 bit15 */
			{39722,54,0}, /* core5 fp64 bit16 */
			{39720,54,0}, /* core5 fp64 bit17 */
			{39778,54,0}, /* core5 fp64 bit18 */
			{39786,54,0}, /* core5 fp64 bit19 */
			{39780,54,0}, /* core5 fp64 bit20 */
			{39784,54,0}, /* core5 fp64 bit21 */
			{39706,54,0}, /* core5 fp64 bit22 */
			{39770,54,0}, /* core5 fp64 bit23 */
			{39768,54,0}, /* core5 fp64 bit24 */
			{39742,54,0}, /* core5 fp64 bit25 */
			{39776,54,0}, /* core5 fp64 bit26 */
			{39740,54,0}, /* core5 fp64 bit27 */
			{31826,54,0}, /* core5 fp64 bit28 */
			{39774,54,0}, /* core5 fp64 bit29 */
			{39772,54,0}, /* core5 fp64 bit30 */
			{31836,54,0}, /* core5 fp64 bit31 */
			{31976,54,0}, /* core5 fp64 bit32 */
			{31974,54,0}, /* core5 fp64 bit33 */
			{31972,54,0}, /* core5 fp64 bit34 */
			{39436,54,0}, /* core5 fp64 bit35 */
			{39438,54,0}, /* core5 fp64 bit36 */
			{39430,54,0}, /* core5 fp64 bit37 */
			{39426,54,0}, /* core5 fp64 bit38 */
			{39428,54,0}, /* core5 fp64 bit39 */
			{39394,54,0}, /* core5 fp64 bit40 */
			{39392,54,0}, /* core5 fp64 bit41 */
			{39424,54,0}, /* core5 fp64 bit42 */
			{39398,54,0}, /* core5 fp64 bit43 */
			{39402,54,0}, /* core5 fp64 bit44 */
			{39410,54,0}, /* core5 fp64 bit45 */
			{39396,54,0}, /* core5 fp64 bit46 */
			{39400,54,0}, /* core5 fp64 bit47 */
			{39408,54,0}, /* core5 fp64 bit48 */
			{46722,54,0}, /* core5 fp64 bit49 */
			{46720,54,0}, /* core5 fp64 bit50 */
			{46718,54,0}, /* core5 fp64 bit51 */
			{46708,54,0}, /* core5 fp64 bit52 */
			{46698,54,0}, /* core5 fp64 bit53 */
			{46696,54,0}, /* core5 fp64 bit54 */
			{46694,54,0}, /* core5 fp64 bit55 */
			{46692,54,0}, /* core5 fp64 bit56 */
			{46706,54,0}, /* core5 fp64 bit57 */
			{46704,54,0}, /* core5 fp64 bit58 */
			{46702,54,0}, /* core5 fp64 bit59 */
			{46700,54,0}, /* core5 fp64 bit60 */
			{32034,54,0}, /* core5 fp64 bit61 */
			{32042,54,0}, /* core5 fp64 bit62 */
			{32040,54,0}, /* core5 fp64 bit63 */
			}},
			.sp_EL0 = {{
			{31878,54,0}, /* core5 sp_EL0 bit0 */
			{31882,54,0}, /* core5 sp_EL0 bit1 */
			{39692,54,0}, /* core5 sp_EL0 bit2 */
			{39816,54,0}, /* core5 sp_EL0 bit3 */
			{39652,54,0}, /* core5 sp_EL0 bit4 */
			{39654,54,0}, /* core5 sp_EL0 bit5 */
			{39658,54,0}, /* core5 sp_EL0 bit6 */
			{39656,54,0}, /* core5 sp_EL0 bit7 */
			{39686,54,0}, /* core5 sp_EL0 bit8 */
			{39684,54,0}, /* core5 sp_EL0 bit9 */
			{39688,54,0}, /* core5 sp_EL0 bit10 */
			{39690,54,0}, /* core5 sp_EL0 bit11 */
			{39822,54,0}, /* core5 sp_EL0 bit12 */
			{31850,54,0}, /* core5 sp_EL0 bit13 */
			{39820,54,0}, /* core5 sp_EL0 bit14 */
			{31848,54,0}, /* core5 sp_EL0 bit15 */
			{39698,54,0}, /* core5 sp_EL0 bit16 */
			{39824,54,0}, /* core5 sp_EL0 bit17 */
			{39830,54,0}, /* core5 sp_EL0 bit18 */
			{39828,54,0}, /* core5 sp_EL0 bit19 */
			{39826,54,0}, /* core5 sp_EL0 bit20 */
			{39696,54,0}, /* core5 sp_EL0 bit21 */
			{39702,54,0}, /* core5 sp_EL0 bit22 */
			{39806,54,0}, /* core5 sp_EL0 bit23 */
			{39804,54,0}, /* core5 sp_EL0 bit24 */
			{39700,54,0}, /* core5 sp_EL0 bit25 */
			{39808,54,0}, /* core5 sp_EL0 bit26 */
			{39810,54,0}, /* core5 sp_EL0 bit27 */
			{39814,54,0}, /* core5 sp_EL0 bit28 */
			{39812,54,0}, /* core5 sp_EL0 bit29 */
			{39694,54,0}, /* core5 sp_EL0 bit30 */
			{39818,54,0}, /* core5 sp_EL0 bit31 */
			{39446,54,0}, /* core5 sp_EL0 bit32 */
			{32134,54,0}, /* core5 sp_EL0 bit33 */
			{39444,54,0}, /* core5 sp_EL0 bit34 */
			{32136,54,0}, /* core5 sp_EL0 bit35 */
			{32132,54,0}, /* core5 sp_EL0 bit36 */
			{32128,54,0}, /* core5 sp_EL0 bit37 */
			{32130,54,0}, /* core5 sp_EL0 bit38 */
			{39390,54,0}, /* core5 sp_EL0 bit39 */
			{39388,54,0}, /* core5 sp_EL0 bit40 */
			{39004,54,0}, /* core5 sp_EL0 bit41 */
			{39002,54,0}, /* core5 sp_EL0 bit42 */
			{38960,54,0}, /* core5 sp_EL0 bit43 */
			{31934,54,0}, /* core5 sp_EL0 bit44 */
			{38958,54,0}, /* core5 sp_EL0 bit45 */
			{46754,54,0}, /* core5 sp_EL0 bit46 */
			{46752,54,0}, /* core5 sp_EL0 bit47 */
			{46750,54,0}, /* core5 sp_EL0 bit48 */
			{38964,54,0}, /* core5 sp_EL0 bit49 */
			{38962,54,0}, /* core5 sp_EL0 bit50 */
			{46748,54,0}, /* core5 sp_EL0 bit51 */
			{46738,54,0}, /* core5 sp_EL0 bit52 */
			{46730,54,0}, /* core5 sp_EL0 bit53 */
			{46736,54,0}, /* core5 sp_EL0 bit54 */
			{46728,54,0}, /* core5 sp_EL0 bit55 */
			{46726,54,0}, /* core5 sp_EL0 bit56 */
			{46724,54,0}, /* core5 sp_EL0 bit57 */
			{46746,54,0}, /* core5 sp_EL0 bit58 */
			{46734,54,0}, /* core5 sp_EL0 bit59 */
			{46732,54,0}, /* core5 sp_EL0 bit60 */
			{46744,54,0}, /* core5 sp_EL0 bit61 */
			{46742,54,0}, /* core5 sp_EL0 bit62 */
			{46740,54,0}, /* core5 sp_EL0 bit63 */
			}},
			.sp_EL1 = {{
			{31874,54,0}, /* core5 sp_EL1 bit0 */
			{39272,54,0}, /* core5 sp_EL1 bit1 */
			{31872,54,0}, /* core5 sp_EL1 bit2 */
			{39270,54,0}, /* core5 sp_EL1 bit3 */
			{39084,54,0}, /* core5 sp_EL1 bit4 */
			{39082,54,0}, /* core5 sp_EL1 bit5 */
			{39086,54,0}, /* core5 sp_EL1 bit6 */
			{39072,54,0}, /* core5 sp_EL1 bit7 */
			{39070,54,0}, /* core5 sp_EL1 bit8 */
			{39088,54,0}, /* core5 sp_EL1 bit9 */
			{39134,54,0}, /* core5 sp_EL1 bit10 */
			{39128,54,0}, /* core5 sp_EL1 bit11 */
			{39238,54,0}, /* core5 sp_EL1 bit12 */
			{39126,54,0}, /* core5 sp_EL1 bit13 */
			{39260,54,0}, /* core5 sp_EL1 bit14 */
			{39262,54,0}, /* core5 sp_EL1 bit15 */
			{39264,54,0}, /* core5 sp_EL1 bit16 */
			{39252,54,0}, /* core5 sp_EL1 bit17 */
			{31854,54,0}, /* core5 sp_EL1 bit18 */
			{39250,54,0}, /* core5 sp_EL1 bit19 */
			{39242,54,0}, /* core5 sp_EL1 bit20 */
			{39240,54,0}, /* core5 sp_EL1 bit21 */
			{39268,54,0}, /* core5 sp_EL1 bit22 */
			{39266,54,0}, /* core5 sp_EL1 bit23 */
			{39132,54,0}, /* core5 sp_EL1 bit24 */
			{39258,54,0}, /* core5 sp_EL1 bit25 */
			{39130,54,0}, /* core5 sp_EL1 bit26 */
			{39138,54,0}, /* core5 sp_EL1 bit27 */
			{39236,54,0}, /* core5 sp_EL1 bit28 */
			{39140,54,0}, /* core5 sp_EL1 bit29 */
			{39136,54,0}, /* core5 sp_EL1 bit30 */
			{31852,54,0}, /* core5 sp_EL1 bit31 */
			{39028,54,0}, /* core5 sp_EL1 bit32 */
			{32108,54,0}, /* core5 sp_EL1 bit33 */
			{39026,54,0}, /* core5 sp_EL1 bit34 */
			{39020,54,0}, /* core5 sp_EL1 bit35 */
			{32104,54,0}, /* core5 sp_EL1 bit36 */
			{39018,54,0}, /* core5 sp_EL1 bit37 */
			{32102,54,0}, /* core5 sp_EL1 bit38 */
			{39008,54,0}, /* core5 sp_EL1 bit39 */
			{39006,54,0}, /* core5 sp_EL1 bit40 */
			{39000,54,0}, /* core5 sp_EL1 bit41 */
			{38998,54,0}, /* core5 sp_EL1 bit42 */
			{38956,54,0}, /* core5 sp_EL1 bit43 */
			{31932,54,0}, /* core5 sp_EL1 bit44 */
			{38954,54,0}, /* core5 sp_EL1 bit45 */
			{38980,54,0}, /* core5 sp_EL1 bit46 */
			{38978,54,0}, /* core5 sp_EL1 bit47 */
			{46778,54,0}, /* core5 sp_EL1 bit48 */
			{46776,54,0}, /* core5 sp_EL1 bit49 */
			{46774,54,0}, /* core5 sp_EL1 bit50 */
			{46772,54,0}, /* core5 sp_EL1 bit51 */
			{46682,54,0}, /* core5 sp_EL1 bit52 */
			{46680,54,0}, /* core5 sp_EL1 bit53 */
			{46678,54,0}, /* core5 sp_EL1 bit54 */
			{46676,54,0}, /* core5 sp_EL1 bit55 */
			{46690,54,0}, /* core5 sp_EL1 bit56 */
			{46688,54,0}, /* core5 sp_EL1 bit57 */
			{46686,54,0}, /* core5 sp_EL1 bit58 */
			{46684,54,0}, /* core5 sp_EL1 bit59 */
			{46634,54,0}, /* core5 sp_EL1 bit60 */
			{46632,54,0}, /* core5 sp_EL1 bit61 */
			{46630,54,0}, /* core5 sp_EL1 bit62 */
			{46628,54,0}, /* core5 sp_EL1 bit63 */
			}},
			.sp_EL2 = {{
			{31870,54,0}, /* core5 sp_EL2 bit0 */
			{39094,54,0}, /* core5 sp_EL2 bit1 */
			{31868,54,0}, /* core5 sp_EL2 bit2 */
			{39234,54,0}, /* core5 sp_EL2 bit3 */
			{39080,54,0}, /* core5 sp_EL2 bit4 */
			{39078,54,0}, /* core5 sp_EL2 bit5 */
			{39076,54,0}, /* core5 sp_EL2 bit6 */
			{39074,54,0}, /* core5 sp_EL2 bit7 */
			{39092,54,0}, /* core5 sp_EL2 bit8 */
			{39090,54,0}, /* core5 sp_EL2 bit9 */
			{39232,54,0}, /* core5 sp_EL2 bit10 */
			{39158,54,0}, /* core5 sp_EL2 bit11 */
			{39146,54,0}, /* core5 sp_EL2 bit12 */
			{39254,54,0}, /* core5 sp_EL2 bit13 */
			{39276,54,0}, /* core5 sp_EL2 bit14 */
			{39256,54,0}, /* core5 sp_EL2 bit15 */
			{39274,54,0}, /* core5 sp_EL2 bit16 */
			{39248,54,0}, /* core5 sp_EL2 bit17 */
			{31858,54,0}, /* core5 sp_EL2 bit18 */
			{39144,54,0}, /* core5 sp_EL2 bit19 */
			{39142,54,0}, /* core5 sp_EL2 bit20 */
			{39166,54,0}, /* core5 sp_EL2 bit21 */
			{39096,54,0}, /* core5 sp_EL2 bit22 */
			{39164,54,0}, /* core5 sp_EL2 bit23 */
			{39162,54,0}, /* core5 sp_EL2 bit24 */
			{39230,54,0}, /* core5 sp_EL2 bit25 */
			{39228,54,0}, /* core5 sp_EL2 bit26 */
			{39156,54,0}, /* core5 sp_EL2 bit27 */
			{39154,54,0}, /* core5 sp_EL2 bit28 */
			{39160,54,0}, /* core5 sp_EL2 bit29 */
			{39152,54,0}, /* core5 sp_EL2 bit30 */
			{31866,54,0}, /* core5 sp_EL2 bit31 */
			{39040,54,0}, /* core5 sp_EL2 bit32 */
			{32148,54,0}, /* core5 sp_EL2 bit33 */
			{39038,54,0}, /* core5 sp_EL2 bit34 */
			{39032,54,0}, /* core5 sp_EL2 bit35 */
			{39030,54,0}, /* core5 sp_EL2 bit36 */
			{32106,54,0}, /* core5 sp_EL2 bit37 */
			{39024,54,0}, /* core5 sp_EL2 bit38 */
			{38988,54,0}, /* core5 sp_EL2 bit39 */
			{39022,54,0}, /* core5 sp_EL2 bit40 */
			{38996,54,0}, /* core5 sp_EL2 bit41 */
			{38994,54,0}, /* core5 sp_EL2 bit42 */
			{38986,54,0}, /* core5 sp_EL2 bit43 */
			{38984,54,0}, /* core5 sp_EL2 bit44 */
			{32074,54,0}, /* core5 sp_EL2 bit45 */
			{38982,54,0}, /* core5 sp_EL2 bit46 */
			{46770,54,0}, /* core5 sp_EL2 bit47 */
			{46762,54,0}, /* core5 sp_EL2 bit48 */
			{46768,54,0}, /* core5 sp_EL2 bit49 */
			{46760,54,0}, /* core5 sp_EL2 bit50 */
			{46758,54,0}, /* core5 sp_EL2 bit51 */
			{46756,54,0}, /* core5 sp_EL2 bit52 */
			{46650,54,0}, /* core5 sp_EL2 bit53 */
			{46648,54,0}, /* core5 sp_EL2 bit54 */
			{46646,54,0}, /* core5 sp_EL2 bit55 */
			{46644,54,0}, /* core5 sp_EL2 bit56 */
			{46642,54,0}, /* core5 sp_EL2 bit57 */
			{46640,54,0}, /* core5 sp_EL2 bit58 */
			{46638,54,0}, /* core5 sp_EL2 bit59 */
			{46636,54,0}, /* core5 sp_EL2 bit60 */
			{46766,54,0}, /* core5 sp_EL2 bit61 */
			{46764,54,0}, /* core5 sp_EL2 bit62 */
			{32070,54,0}, /* core5 sp_EL2 bit63 */
			}},
			.sp_EL3 = {{
			{31844,54,0}, /* core5 sp_EL3 bit0 */
			{31884,54,0}, /* core5 sp_EL3 bit1 */
			{39056,54,0}, /* core5 sp_EL3 bit2 */
			{39220,54,0}, /* core5 sp_EL3 bit3 */
			{39052,54,0}, /* core5 sp_EL3 bit4 */
			{39050,54,0}, /* core5 sp_EL3 bit5 */
			{39054,54,0}, /* core5 sp_EL3 bit6 */
			{39048,54,0}, /* core5 sp_EL3 bit7 */
			{39046,54,0}, /* core5 sp_EL3 bit8 */
			{39102,54,0}, /* core5 sp_EL3 bit9 */
			{39212,54,0}, /* core5 sp_EL3 bit10 */
			{39206,54,0}, /* core5 sp_EL3 bit11 */
			{39204,54,0}, /* core5 sp_EL3 bit12 */
			{39120,54,0}, /* core5 sp_EL3 bit13 */
			{39104,54,0}, /* core5 sp_EL3 bit14 */
			{39118,54,0}, /* core5 sp_EL3 bit15 */
			{39108,54,0}, /* core5 sp_EL3 bit16 */
			{31832,54,0}, /* core5 sp_EL3 bit17 */
			{39218,54,0}, /* core5 sp_EL3 bit18 */
			{39224,54,0}, /* core5 sp_EL3 bit19 */
			{39222,54,0}, /* core5 sp_EL3 bit20 */
			{39196,54,0}, /* core5 sp_EL3 bit21 */
			{39106,54,0}, /* core5 sp_EL3 bit22 */
			{39194,54,0}, /* core5 sp_EL3 bit23 */
			{39200,54,0}, /* core5 sp_EL3 bit24 */
			{39210,54,0}, /* core5 sp_EL3 bit25 */
			{39198,54,0}, /* core5 sp_EL3 bit26 */
			{39216,54,0}, /* core5 sp_EL3 bit27 */
			{39208,54,0}, /* core5 sp_EL3 bit28 */
			{39202,54,0}, /* core5 sp_EL3 bit29 */
			{39214,54,0}, /* core5 sp_EL3 bit30 */
			{31834,54,0}, /* core5 sp_EL3 bit31 */
			{39036,54,0}, /* core5 sp_EL3 bit32 */
			{32140,54,0}, /* core5 sp_EL3 bit33 */
			{39034,54,0}, /* core5 sp_EL3 bit34 */
			{32144,54,0}, /* core5 sp_EL3 bit35 */
			{32142,54,0}, /* core5 sp_EL3 bit36 */
			{32124,54,0}, /* core5 sp_EL3 bit37 */
			{32126,54,0}, /* core5 sp_EL3 bit38 */
			{32092,54,0}, /* core5 sp_EL3 bit39 */
			{32094,54,0}, /* core5 sp_EL3 bit40 */
			{32084,54,0}, /* core5 sp_EL3 bit41 */
			{38992,54,0}, /* core5 sp_EL3 bit42 */
			{31930,54,0}, /* core5 sp_EL3 bit43 */
			{38990,54,0}, /* core5 sp_EL3 bit44 */
			{32076,54,0}, /* core5 sp_EL3 bit45 */
			{38972,54,0}, /* core5 sp_EL3 bit46 */
			{38976,54,0}, /* core5 sp_EL3 bit47 */
			{38974,54,0}, /* core5 sp_EL3 bit48 */
			{46658,54,0}, /* core5 sp_EL3 bit49 */
			{46656,54,0}, /* core5 sp_EL3 bit50 */
			{46654,54,0}, /* core5 sp_EL3 bit51 */
			{46652,54,0}, /* core5 sp_EL3 bit52 */
			{46674,54,0}, /* core5 sp_EL3 bit53 */
			{46672,54,0}, /* core5 sp_EL3 bit54 */
			{46670,54,0}, /* core5 sp_EL3 bit55 */
			{46668,54,0}, /* core5 sp_EL3 bit56 */
			{46666,54,0}, /* core5 sp_EL3 bit57 */
			{46664,54,0}, /* core5 sp_EL3 bit58 */
			{46662,54,0}, /* core5 sp_EL3 bit59 */
			{38970,54,0}, /* core5 sp_EL3 bit60 */
			{46660,54,0}, /* core5 sp_EL3 bit61 */
			{38968,54,0}, /* core5 sp_EL3 bit62 */
			{38966,54,0}, /* core5 sp_EL3 bit63 */
			}},
			.elr_EL1 = {{
			{46886,54,0}, /* core5 elr_EL1 bit0 */
			{46884,54,0}, /* core5 elr_EL1 bit1 */
			{46888,54,0}, /* core5 elr_EL1 bit2 */
			{46954,54,0}, /* core5 elr_EL1 bit3 */
			{46890,54,0}, /* core5 elr_EL1 bit4 */
			{46882,54,0}, /* core5 elr_EL1 bit5 */
			{46880,54,0}, /* core5 elr_EL1 bit6 */
			{46874,54,0}, /* core5 elr_EL1 bit7 */
			{46872,54,0}, /* core5 elr_EL1 bit8 */
			{46870,54,0}, /* core5 elr_EL1 bit9 */
			{46952,54,0}, /* core5 elr_EL1 bit10 */
			{46950,54,0}, /* core5 elr_EL1 bit11 */
			{46914,54,0}, /* core5 elr_EL1 bit12 */
			{46948,54,0}, /* core5 elr_EL1 bit13 */
			{46878,54,0}, /* core5 elr_EL1 bit14 */
			{46904,54,0}, /* core5 elr_EL1 bit15 */
			{46868,54,0}, /* core5 elr_EL1 bit16 */
			{31856,54,0}, /* core5 elr_EL1 bit17 */
			{46958,54,0}, /* core5 elr_EL1 bit18 */
			{46956,54,0}, /* core5 elr_EL1 bit19 */
			{46906,54,0}, /* core5 elr_EL1 bit20 */
			{46946,54,0}, /* core5 elr_EL1 bit21 */
			{46876,54,0}, /* core5 elr_EL1 bit22 */
			{46912,54,0}, /* core5 elr_EL1 bit23 */
			{46910,54,0}, /* core5 elr_EL1 bit24 */
			{46908,54,0}, /* core5 elr_EL1 bit25 */
			{46944,54,0}, /* core5 elr_EL1 bit26 */
			{46942,54,0}, /* core5 elr_EL1 bit27 */
			{46940,54,0}, /* core5 elr_EL1 bit28 */
			{39246,54,0}, /* core5 elr_EL1 bit29 */
			{39244,54,0}, /* core5 elr_EL1 bit30 */
			{31864,54,0}, /* core5 elr_EL1 bit31 */
			{46612,54,0}, /* core5 elr_EL1 bit32 */
			{46850,54,0}, /* core5 elr_EL1 bit33 */
			{46848,54,0}, /* core5 elr_EL1 bit34 */
			{46846,54,0}, /* core5 elr_EL1 bit35 */
			{46844,54,0}, /* core5 elr_EL1 bit36 */
			{46834,54,0}, /* core5 elr_EL1 bit37 */
			{46832,54,0}, /* core5 elr_EL1 bit38 */
			{46830,54,0}, /* core5 elr_EL1 bit39 */
			{46828,54,0}, /* core5 elr_EL1 bit40 */
			{46818,54,0}, /* core5 elr_EL1 bit41 */
			{46816,54,0}, /* core5 elr_EL1 bit42 */
			{46814,54,0}, /* core5 elr_EL1 bit43 */
			{46812,54,0}, /* core5 elr_EL1 bit44 */
			{46802,54,0}, /* core5 elr_EL1 bit45 */
			{46800,54,0}, /* core5 elr_EL1 bit46 */
			{46798,54,0}, /* core5 elr_EL1 bit47 */
			{46796,54,0}, /* core5 elr_EL1 bit48 */
			{46602,54,0}, /* core5 elr_EL1 bit49 */
			{46594,54,0}, /* core5 elr_EL1 bit50 */
			{46600,54,0}, /* core5 elr_EL1 bit51 */
			{46598,54,0}, /* core5 elr_EL1 bit52 */
			{46592,54,0}, /* core5 elr_EL1 bit53 */
			{46590,54,0}, /* core5 elr_EL1 bit54 */
			{46596,54,0}, /* core5 elr_EL1 bit55 */
			{46588,54,0}, /* core5 elr_EL1 bit56 */
			{46618,54,0}, /* core5 elr_EL1 bit57 */
			{46610,54,0}, /* core5 elr_EL1 bit58 */
			{46608,54,0}, /* core5 elr_EL1 bit59 */
			{46606,54,0}, /* core5 elr_EL1 bit60 */
			{46604,54,0}, /* core5 elr_EL1 bit61 */
			{46616,54,0}, /* core5 elr_EL1 bit62 */
			{46614,54,0}, /* core5 elr_EL1 bit63 */
			}},
			.elr_EL2 = {{
			{46866,54,0}, /* core5 elr_EL2 bit0 */
			{46864,54,0}, /* core5 elr_EL2 bit1 */
			{46894,54,0}, /* core5 elr_EL2 bit2 */
			{46930,54,0}, /* core5 elr_EL2 bit3 */
			{46892,54,0}, /* core5 elr_EL2 bit4 */
			{46858,54,0}, /* core5 elr_EL2 bit5 */
			{46856,54,0}, /* core5 elr_EL2 bit6 */
			{46854,54,0}, /* core5 elr_EL2 bit7 */
			{46862,54,0}, /* core5 elr_EL2 bit8 */
			{46860,54,0}, /* core5 elr_EL2 bit9 */
			{46928,54,0}, /* core5 elr_EL2 bit10 */
			{46962,54,0}, /* core5 elr_EL2 bit11 */
			{46960,54,0}, /* core5 elr_EL2 bit12 */
			{46902,54,0}, /* core5 elr_EL2 bit13 */
			{46898,54,0}, /* core5 elr_EL2 bit14 */
			{46900,54,0}, /* core5 elr_EL2 bit15 */
			{46852,54,0}, /* core5 elr_EL2 bit16 */
			{31860,54,0}, /* core5 elr_EL2 bit17 */
			{46922,54,0}, /* core5 elr_EL2 bit18 */
			{46920,54,0}, /* core5 elr_EL2 bit19 */
			{46918,54,0}, /* core5 elr_EL2 bit20 */
			{46916,54,0}, /* core5 elr_EL2 bit21 */
			{46896,54,0}, /* core5 elr_EL2 bit22 */
			{39150,54,0}, /* core5 elr_EL2 bit23 */
			{46926,54,0}, /* core5 elr_EL2 bit24 */
			{46924,54,0}, /* core5 elr_EL2 bit25 */
			{46938,54,0}, /* core5 elr_EL2 bit26 */
			{39148,54,0}, /* core5 elr_EL2 bit27 */
			{46936,54,0}, /* core5 elr_EL2 bit28 */
			{46934,54,0}, /* core5 elr_EL2 bit29 */
			{46932,54,0}, /* core5 elr_EL2 bit30 */
			{31862,54,0}, /* core5 elr_EL2 bit31 */
			{46782,54,0}, /* core5 elr_EL2 bit32 */
			{46780,54,0}, /* core5 elr_EL2 bit33 */
			{46842,54,0}, /* core5 elr_EL2 bit34 */
			{46840,54,0}, /* core5 elr_EL2 bit35 */
			{46838,54,0}, /* core5 elr_EL2 bit36 */
			{46836,54,0}, /* core5 elr_EL2 bit37 */
			{46826,54,0}, /* core5 elr_EL2 bit38 */
			{46824,54,0}, /* core5 elr_EL2 bit39 */
			{46794,54,0}, /* core5 elr_EL2 bit40 */
			{46822,54,0}, /* core5 elr_EL2 bit41 */
			{46820,54,0}, /* core5 elr_EL2 bit42 */
			{46792,54,0}, /* core5 elr_EL2 bit43 */
			{46810,54,0}, /* core5 elr_EL2 bit44 */
			{46808,54,0}, /* core5 elr_EL2 bit45 */
			{46806,54,0}, /* core5 elr_EL2 bit46 */
			{46804,54,0}, /* core5 elr_EL2 bit47 */
			{46626,54,0}, /* core5 elr_EL2 bit48 */
			{46790,54,0}, /* core5 elr_EL2 bit49 */
			{46788,54,0}, /* core5 elr_EL2 bit50 */
			{46578,54,0}, /* core5 elr_EL2 bit51 */
			{46576,54,0}, /* core5 elr_EL2 bit52 */
			{46574,54,0}, /* core5 elr_EL2 bit53 */
			{46572,54,0}, /* core5 elr_EL2 bit54 */
			{46570,54,0}, /* core5 elr_EL2 bit55 */
			{46568,54,0}, /* core5 elr_EL2 bit56 */
			{46624,54,0}, /* core5 elr_EL2 bit57 */
			{46566,54,0}, /* core5 elr_EL2 bit58 */
			{46564,54,0}, /* core5 elr_EL2 bit59 */
			{46622,54,0}, /* core5 elr_EL2 bit60 */
			{46786,54,0}, /* core5 elr_EL2 bit61 */
			{46784,54,0}, /* core5 elr_EL2 bit62 */
			{46620,54,0}, /* core5 elr_EL2 bit63 */
			}},
			.elr_EL3 = {{
			{39064,54,0}, /* core5 elr_EL3 bit0 */
			{39062,54,0}, /* core5 elr_EL3 bit1 */
			{39100,54,0}, /* core5 elr_EL3 bit2 */
			{39188,54,0}, /* core5 elr_EL3 bit3 */
			{39068,54,0}, /* core5 elr_EL3 bit4 */
			{39066,54,0}, /* core5 elr_EL3 bit5 */
			{39098,54,0}, /* core5 elr_EL3 bit6 */
			{31880,54,0}, /* core5 elr_EL3 bit7 */
			{39060,54,0}, /* core5 elr_EL3 bit8 */
			{39058,54,0}, /* core5 elr_EL3 bit9 */
			{39172,54,0}, /* core5 elr_EL3 bit10 */
			{39186,54,0}, /* core5 elr_EL3 bit11 */
			{39168,54,0}, /* core5 elr_EL3 bit12 */
			{39226,54,0}, /* core5 elr_EL3 bit13 */
			{39112,54,0}, /* core5 elr_EL3 bit14 */
			{39124,54,0}, /* core5 elr_EL3 bit15 */
			{39110,54,0}, /* core5 elr_EL3 bit16 */
			{39116,54,0}, /* core5 elr_EL3 bit17 */
			{31830,54,0}, /* core5 elr_EL3 bit18 */
			{39122,54,0}, /* core5 elr_EL3 bit19 */
			{39170,54,0}, /* core5 elr_EL3 bit20 */
			{39192,54,0}, /* core5 elr_EL3 bit21 */
			{39114,54,0}, /* core5 elr_EL3 bit22 */
			{39190,54,0}, /* core5 elr_EL3 bit23 */
			{31828,54,0}, /* core5 elr_EL3 bit24 */
			{39184,54,0}, /* core5 elr_EL3 bit25 */
			{39182,54,0}, /* core5 elr_EL3 bit26 */
			{39176,54,0}, /* core5 elr_EL3 bit27 */
			{39174,54,0}, /* core5 elr_EL3 bit28 */
			{39180,54,0}, /* core5 elr_EL3 bit29 */
			{39178,54,0}, /* core5 elr_EL3 bit30 */
			{31846,54,0}, /* core5 elr_EL3 bit31 */
			{46078,54,0}, /* core5 elr_EL3 bit32 */
			{39044,54,0}, /* core5 elr_EL3 bit33 */
			{39042,54,0}, /* core5 elr_EL3 bit34 */
			{32156,54,0}, /* core5 elr_EL3 bit35 */
			{32154,54,0}, /* core5 elr_EL3 bit36 */
			{39016,54,0}, /* core5 elr_EL3 bit37 */
			{39014,54,0}, /* core5 elr_EL3 bit38 */
			{39012,54,0}, /* core5 elr_EL3 bit39 */
			{31902,54,0}, /* core5 elr_EL3 bit40 */
			{31920,54,0}, /* core5 elr_EL3 bit41 */
			{39010,54,0}, /* core5 elr_EL3 bit42 */
			{38948,54,0}, /* core5 elr_EL3 bit43 */
			{38952,54,0}, /* core5 elr_EL3 bit44 */
			{38950,54,0}, /* core5 elr_EL3 bit45 */
			{38946,54,0}, /* core5 elr_EL3 bit46 */
			{38944,54,0}, /* core5 elr_EL3 bit47 */
			{38942,54,0}, /* core5 elr_EL3 bit48 */
			{46538,54,0}, /* core5 elr_EL3 bit49 */
			{46586,54,0}, /* core5 elr_EL3 bit50 */
			{46584,54,0}, /* core5 elr_EL3 bit51 */
			{46536,54,0}, /* core5 elr_EL3 bit52 */
			{46534,54,0}, /* core5 elr_EL3 bit53 */
			{46532,54,0}, /* core5 elr_EL3 bit54 */
			{46530,54,0}, /* core5 elr_EL3 bit55 */
			{46528,54,0}, /* core5 elr_EL3 bit56 */
			{46582,54,0}, /* core5 elr_EL3 bit57 */
			{46526,54,0}, /* core5 elr_EL3 bit58 */
			{46524,54,0}, /* core5 elr_EL3 bit59 */
			{46084,54,0}, /* core5 elr_EL3 bit60 */
			{46082,54,0}, /* core5 elr_EL3 bit61 */
			{46080,54,0}, /* core5 elr_EL3 bit62 */
			{46580,54,0}, /* core5 elr_EL3 bit63 */
			}},
			.raw_pc = {{
			{44712,54,0}, /* core5 raw_pc bit0 */
			{19018,57,0}, /* core5 raw_pc bit1 */
			{19016,57,0}, /* core5 raw_pc bit2 */
			{19012,57,0}, /* core5 raw_pc bit3 */
			{19014,57,0}, /* core5 raw_pc bit4 */
			{44704,54,0}, /* core5 raw_pc bit5 */
			{44702,54,0}, /* core5 raw_pc bit6 */
			{19158,57,0}, /* core5 raw_pc bit7 */
			{19032,57,0}, /* core5 raw_pc bit8 */
			{19030,57,0}, /* core5 raw_pc bit9 */
			{19028,57,0}, /* core5 raw_pc bit10 */
			{19156,57,0}, /* core5 raw_pc bit11 */
			{19154,57,0}, /* core5 raw_pc bit12 */
			{19152,57,0}, /* core5 raw_pc bit13 */
			{19150,57,0}, /* core5 raw_pc bit14 */
			{19148,57,0}, /* core5 raw_pc bit15 */
			{19146,57,0}, /* core5 raw_pc bit16 */
			{19144,57,0}, /* core5 raw_pc bit17 */
			{19142,57,0}, /* core5 raw_pc bit18 */
			{19060,57,0}, /* core5 raw_pc bit19 */
			{19058,57,0}, /* core5 raw_pc bit20 */
			{19056,57,0}, /* core5 raw_pc bit21 */
			{19054,57,0}, /* core5 raw_pc bit22 */
			{19052,57,0}, /* core5 raw_pc bit23 */
			{19050,57,0}, /* core5 raw_pc bit24 */
			{19048,57,0}, /* core5 raw_pc bit25 */
			{19046,57,0}, /* core5 raw_pc bit26 */
			{19044,57,0}, /* core5 raw_pc bit27 */
			{19042,57,0}, /* core5 raw_pc bit28 */
			{19040,57,0}, /* core5 raw_pc bit29 */
			{19038,57,0}, /* core5 raw_pc bit30 */
			{19010,57,0}, /* core5 raw_pc bit31 */
			{19008,57,0}, /* core5 raw_pc bit32 */
			{19006,57,0}, /* core5 raw_pc bit33 */
			{19004,57,0}, /* core5 raw_pc bit34 */
			{19002,57,0}, /* core5 raw_pc bit35 */
			{19000,57,0}, /* core5 raw_pc bit36 */
			{18998,57,0}, /* core5 raw_pc bit37 */
			{18996,57,0}, /* core5 raw_pc bit38 */
			{18994,57,0}, /* core5 raw_pc bit39 */
			{18992,57,0}, /* core5 raw_pc bit40 */
			{18990,57,0}, /* core5 raw_pc bit41 */
			{18988,57,0}, /* core5 raw_pc bit42 */
			{18982,57,0}, /* core5 raw_pc bit43 */
			{18980,57,0}, /* core5 raw_pc bit44 */
			{18986,57,0}, /* core5 raw_pc bit45 */
			{18984,57,0}, /* core5 raw_pc bit46 */
			{44708,54,0}, /* core5 raw_pc bit47 */
			{44706,54,0}, /* core5 raw_pc bit48 */
			{36762,54,0}, /* core5 raw_pc bit49 */
			{    0, 0,2}, /* core5 raw_pc bit50 */
			{    0, 0,2}, /* core5 raw_pc bit51 */
			{    0, 0,2}, /* core5 raw_pc bit52 */
			{    0, 0,2}, /* core5 raw_pc bit53 */
			{    0, 0,2}, /* core5 raw_pc bit54 */
			{    0, 0,2}, /* core5 raw_pc bit55 */
			{    0, 0,2}, /* core5 raw_pc bit56 */
			{    0, 0,2}, /* core5 raw_pc bit57 */
			{    0, 0,2}, /* core5 raw_pc bit58 */
			{    0, 0,2}, /* core5 raw_pc bit59 */
			{    0, 0,2}, /* core5 raw_pc bit60 */
			{    0, 0,2}, /* core5 raw_pc bit61 */
			{    0, 0,2}, /* core5 raw_pc bit62 */
			{    0, 0,2}, /* core5 raw_pc bit63 */
			}},
			.pc_iss = {{
			{44752,54,0}, /* core5 pc_iss bit0 */
			{44760,54,0}, /* core5 pc_iss bit1 */
			{44758,54,0}, /* core5 pc_iss bit2 */
			{44764,54,0}, /* core5 pc_iss bit3 */
			{44762,54,0}, /* core5 pc_iss bit4 */
			{44750,54,0}, /* core5 pc_iss bit5 */
			{44756,54,0}, /* core5 pc_iss bit6 */
			{44754,54,0}, /* core5 pc_iss bit7 */
			{44768,54,0}, /* core5 pc_iss bit8 */
			{44766,54,0}, /* core5 pc_iss bit9 */
			{44746,54,0}, /* core5 pc_iss bit10 */
			{44744,54,0}, /* core5 pc_iss bit11 */
			{45102,54,0}, /* core5 pc_iss bit12 */
			{45100,54,0}, /* core5 pc_iss bit13 */
			{45098,54,0}, /* core5 pc_iss bit14 */
			{44748,54,0}, /* core5 pc_iss bit15 */
			{45096,54,0}, /* core5 pc_iss bit16 */
			{45090,54,0}, /* core5 pc_iss bit17 */
			{45088,54,0}, /* core5 pc_iss bit18 */
			{45082,54,0}, /* core5 pc_iss bit19 */
			{45080,54,0}, /* core5 pc_iss bit20 */
			{45086,54,0}, /* core5 pc_iss bit21 */
			{45084,54,0}, /* core5 pc_iss bit22 */
			{44782,54,0}, /* core5 pc_iss bit23 */
			{44780,54,0}, /* core5 pc_iss bit24 */
			{36740,54,0}, /* core5 pc_iss bit25 */
			{36738,54,0}, /* core5 pc_iss bit26 */
			{45094,54,0}, /* core5 pc_iss bit27 */
			{45092,54,0}, /* core5 pc_iss bit28 */
			{44742,54,0}, /* core5 pc_iss bit29 */
			{44740,54,0}, /* core5 pc_iss bit30 */
			{44778,54,0}, /* core5 pc_iss bit31 */
			{44700,54,0}, /* core5 pc_iss bit32 */
			{44698,54,0}, /* core5 pc_iss bit33 */
			{44696,54,0}, /* core5 pc_iss bit34 */
			{44694,54,0}, /* core5 pc_iss bit35 */
			{44680,54,0}, /* core5 pc_iss bit36 */
			{44678,54,0}, /* core5 pc_iss bit37 */
			{44692,54,0}, /* core5 pc_iss bit38 */
			{44688,54,0}, /* core5 pc_iss bit39 */
			{44686,54,0}, /* core5 pc_iss bit40 */
			{44684,54,0}, /* core5 pc_iss bit41 */
			{44682,54,0}, /* core5 pc_iss bit42 */
			{44690,54,0}, /* core5 pc_iss bit43 */
			{18930,57,0}, /* core5 pc_iss bit44 */
			{18928,57,0}, /* core5 pc_iss bit45 */
			{18926,57,0}, /* core5 pc_iss bit46 */
			{18924,57,0}, /* core5 pc_iss bit47 */
			{18922,57,0}, /* core5 pc_iss bit48 */
			{18920,57,0}, /* core5 pc_iss bit49 */
			{18918,57,0}, /* core5 pc_iss bit50 */
			{18880,57,0}, /* core5 pc_iss bit51 */
			{18904,57,0}, /* core5 pc_iss bit52 */
			{18902,57,0}, /* core5 pc_iss bit53 */
			{18916,57,0}, /* core5 pc_iss bit54 */
			{18914,57,0}, /* core5 pc_iss bit55 */
			{19026,57,0}, /* core5 pc_iss bit56 */
			{19020,57,0}, /* core5 pc_iss bit57 */
			{19036,57,0}, /* core5 pc_iss bit58 */
			{19034,57,0}, /* core5 pc_iss bit59 */
			{18900,57,0}, /* core5 pc_iss bit60 */
			{18898,57,0}, /* core5 pc_iss bit61 */
			{19024,57,0}, /* core5 pc_iss bit62 */
			{19022,57,0}, /* core5 pc_iss bit63 */
			}},
			.full_pc_wr = {{
			{44710,54,0}, /* core5 full_pc_wr bit0 */
			{    0, 0,2}, /* core5 full_pc_wr bit1 */
			{    0, 0,2}, /* core5 full_pc_wr bit2 */
			{    0, 0,2}, /* core5 full_pc_wr bit3 */
			{    0, 0,2}, /* core5 full_pc_wr bit4 */
			{    0, 0,2}, /* core5 full_pc_wr bit5 */
			{    0, 0,2}, /* core5 full_pc_wr bit6 */
			{    0, 0,2}, /* core5 full_pc_wr bit7 */
			{    0, 0,2}, /* core5 full_pc_wr bit8 */
			{    0, 0,2}, /* core5 full_pc_wr bit9 */
			{    0, 0,2}, /* core5 full_pc_wr bit10 */
			{    0, 0,2}, /* core5 full_pc_wr bit11 */
			{    0, 0,2}, /* core5 full_pc_wr bit12 */
			{    0, 0,2}, /* core5 full_pc_wr bit13 */
			{    0, 0,2}, /* core5 full_pc_wr bit14 */
			{    0, 0,2}, /* core5 full_pc_wr bit15 */
			{    0, 0,2}, /* core5 full_pc_wr bit16 */
			{    0, 0,2}, /* core5 full_pc_wr bit17 */
			{    0, 0,2}, /* core5 full_pc_wr bit18 */
			{    0, 0,2}, /* core5 full_pc_wr bit19 */
			{    0, 0,2}, /* core5 full_pc_wr bit20 */
			{    0, 0,2}, /* core5 full_pc_wr bit21 */
			{    0, 0,2}, /* core5 full_pc_wr bit22 */
			{    0, 0,2}, /* core5 full_pc_wr bit23 */
			{    0, 0,2}, /* core5 full_pc_wr bit24 */
			{    0, 0,2}, /* core5 full_pc_wr bit25 */
			{    0, 0,2}, /* core5 full_pc_wr bit26 */
			{    0, 0,2}, /* core5 full_pc_wr bit27 */
			{    0, 0,2}, /* core5 full_pc_wr bit28 */
			{    0, 0,2}, /* core5 full_pc_wr bit29 */
			{    0, 0,2}, /* core5 full_pc_wr bit30 */
			{    0, 0,2}, /* core5 full_pc_wr bit31 */
			{    0, 0,2}, /* core5 full_pc_wr bit32 */
			{    0, 0,2}, /* core5 full_pc_wr bit33 */
			{    0, 0,2}, /* core5 full_pc_wr bit34 */
			{    0, 0,2}, /* core5 full_pc_wr bit35 */
			{    0, 0,2}, /* core5 full_pc_wr bit36 */
			{    0, 0,2}, /* core5 full_pc_wr bit37 */
			{    0, 0,2}, /* core5 full_pc_wr bit38 */
			{    0, 0,2}, /* core5 full_pc_wr bit39 */
			{    0, 0,2}, /* core5 full_pc_wr bit40 */
			{    0, 0,2}, /* core5 full_pc_wr bit41 */
			{    0, 0,2}, /* core5 full_pc_wr bit42 */
			{    0, 0,2}, /* core5 full_pc_wr bit43 */
			{    0, 0,2}, /* core5 full_pc_wr bit44 */
			{    0, 0,2}, /* core5 full_pc_wr bit45 */
			{    0, 0,2}, /* core5 full_pc_wr bit46 */
			{    0, 0,2}, /* core5 full_pc_wr bit47 */
			{    0, 0,2}, /* core5 full_pc_wr bit48 */
			{    0, 0,2}, /* core5 full_pc_wr bit49 */
			{    0, 0,2}, /* core5 full_pc_wr bit50 */
			{    0, 0,2}, /* core5 full_pc_wr bit51 */
			{    0, 0,2}, /* core5 full_pc_wr bit52 */
			{    0, 0,2}, /* core5 full_pc_wr bit53 */
			{    0, 0,2}, /* core5 full_pc_wr bit54 */
			{    0, 0,2}, /* core5 full_pc_wr bit55 */
			{    0, 0,2}, /* core5 full_pc_wr bit56 */
			{    0, 0,2}, /* core5 full_pc_wr bit57 */
			{    0, 0,2}, /* core5 full_pc_wr bit58 */
			{    0, 0,2}, /* core5 full_pc_wr bit59 */
			{    0, 0,2}, /* core5 full_pc_wr bit60 */
			{    0, 0,2}, /* core5 full_pc_wr bit61 */
			{    0, 0,2}, /* core5 full_pc_wr bit62 */
			{    0, 0,2}, /* core5 full_pc_wr bit63 */
			}},
			.full_pc_ex1 = {{
			{37250,54,0}, /* core5 full_pc_ex1 bit0 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit1 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit2 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit3 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit4 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit5 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit6 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit7 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit8 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit9 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit10 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit11 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit12 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit13 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit14 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit15 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit16 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit17 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit18 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit19 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit20 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit21 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit22 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit23 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit24 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit25 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit26 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit27 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit28 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit29 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit30 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit31 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit32 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit33 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit34 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit35 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit36 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit37 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit38 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit39 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit40 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit41 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit42 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit43 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit44 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit45 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit46 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit47 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit48 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit49 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit50 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit51 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit52 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit53 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit54 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit55 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit56 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit57 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit58 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit59 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit60 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit61 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit62 */
			{    0, 0,2}, /* core5 full_pc_ex1 bit63 */
			}},
			.full_pc_ex2 = {{
			{44772,54,0}, /* core5 full_pc_ex2 bit0 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit1 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit2 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit3 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit4 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit5 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit6 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit7 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit8 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit9 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit10 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit11 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit12 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit13 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit14 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit15 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit16 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit17 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit18 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit19 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit20 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit21 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit22 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit23 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit24 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit25 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit26 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit27 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit28 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit29 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit30 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit31 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit32 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit33 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit34 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit35 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit36 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit37 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit38 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit39 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit40 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit41 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit42 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit43 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit44 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit45 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit46 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit47 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit48 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit49 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit50 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit51 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit52 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit53 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit54 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit55 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit56 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit57 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit58 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit59 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit60 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit61 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit62 */
			{    0, 0,2}, /* core5 full_pc_ex2 bit63 */
			}},
			.return_Stack_pointer = {{
			{ 7874,55,0}, /* core5 return_Stack_pointer bit0 */
			{ 7872,55,0}, /* core5 return_Stack_pointer bit1 */
			{ 7878,55,0}, /* core5 return_Stack_pointer bit2 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit3 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit4 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit5 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit6 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit7 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit8 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit9 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit10 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit11 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit12 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit13 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit14 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit15 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit16 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit17 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit18 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit19 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit20 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit21 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit22 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit23 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit24 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit25 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit26 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit27 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit28 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit29 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit30 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit31 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit32 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit33 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit34 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit35 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit36 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit37 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit38 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit39 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit40 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit41 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit42 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit43 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit44 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit45 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit46 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit47 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit48 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit49 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit50 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit51 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit52 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit53 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit54 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit55 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit56 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit57 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit58 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit59 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit60 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit61 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit62 */
			{    0, 0,2}, /* core5 return_Stack_pointer bit63 */
			}},
			.return_Stack0 = {{
			{19482,55,0}, /* core5 return_Stack0 bit0 */
			{19480,55,0}, /* core5 return_Stack0 bit1 */
			{19478,55,0}, /* core5 return_Stack0 bit2 */
			{19476,55,0}, /* core5 return_Stack0 bit3 */
			{19266,55,0}, /* core5 return_Stack0 bit4 */
			{19264,55,0}, /* core5 return_Stack0 bit5 */
			{19262,55,0}, /* core5 return_Stack0 bit6 */
			{19260,55,0}, /* core5 return_Stack0 bit7 */
			{19274,55,0}, /* core5 return_Stack0 bit8 */
			{19272,55,0}, /* core5 return_Stack0 bit9 */
			{19270,55,0}, /* core5 return_Stack0 bit10 */
			{ 7838,55,0}, /* core5 return_Stack0 bit11 */
			{19268,55,0}, /* core5 return_Stack0 bit12 */
			{19250,55,0}, /* core5 return_Stack0 bit13 */
			{19248,55,0}, /* core5 return_Stack0 bit14 */
			{19246,55,0}, /* core5 return_Stack0 bit15 */
			{19244,55,0}, /* core5 return_Stack0 bit16 */
			{19442,55,0}, /* core5 return_Stack0 bit17 */
			{ 7836,55,0}, /* core5 return_Stack0 bit18 */
			{ 3022,55,0}, /* core5 return_Stack0 bit19 */
			{19440,55,0}, /* core5 return_Stack0 bit20 */
			{19438,55,0}, /* core5 return_Stack0 bit21 */
			{19436,55,0}, /* core5 return_Stack0 bit22 */
			{19426,55,0}, /* core5 return_Stack0 bit23 */
			{19424,55,0}, /* core5 return_Stack0 bit24 */
			{19422,55,0}, /* core5 return_Stack0 bit25 */
			{19420,55,0}, /* core5 return_Stack0 bit26 */
			{19434,55,0}, /* core5 return_Stack0 bit27 */
			{19432,55,0}, /* core5 return_Stack0 bit28 */
			{19430,55,0}, /* core5 return_Stack0 bit29 */
			{19428,55,0}, /* core5 return_Stack0 bit30 */
			{19394,55,0}, /* core5 return_Stack0 bit31 */
			{19392,55,0}, /* core5 return_Stack0 bit32 */
			{19390,55,0}, /* core5 return_Stack0 bit33 */
			{19388,55,0}, /* core5 return_Stack0 bit34 */
			{19378,55,0}, /* core5 return_Stack0 bit35 */
			{19376,55,0}, /* core5 return_Stack0 bit36 */
			{19374,55,0}, /* core5 return_Stack0 bit37 */
			{19372,55,0}, /* core5 return_Stack0 bit38 */
			{19362,55,0}, /* core5 return_Stack0 bit39 */
			{19360,55,0}, /* core5 return_Stack0 bit40 */
			{19358,55,0}, /* core5 return_Stack0 bit41 */
			{19356,55,0}, /* core5 return_Stack0 bit42 */
			{19498,55,0}, /* core5 return_Stack0 bit43 */
			{19496,55,0}, /* core5 return_Stack0 bit44 */
			{19494,55,0}, /* core5 return_Stack0 bit45 */
			{19492,55,0}, /* core5 return_Stack0 bit46 */
			{ 7846,55,0}, /* core5 return_Stack0 bit47 */
			{ 7844,55,0}, /* core5 return_Stack0 bit48 */
			{    0, 0,2}, /* core5 return_Stack0 bit49 */
			{    0, 0,2}, /* core5 return_Stack0 bit50 */
			{    0, 0,2}, /* core5 return_Stack0 bit51 */
			{    0, 0,2}, /* core5 return_Stack0 bit52 */
			{    0, 0,2}, /* core5 return_Stack0 bit53 */
			{    0, 0,2}, /* core5 return_Stack0 bit54 */
			{    0, 0,2}, /* core5 return_Stack0 bit55 */
			{    0, 0,2}, /* core5 return_Stack0 bit56 */
			{    0, 0,2}, /* core5 return_Stack0 bit57 */
			{    0, 0,2}, /* core5 return_Stack0 bit58 */
			{    0, 0,2}, /* core5 return_Stack0 bit59 */
			{    0, 0,2}, /* core5 return_Stack0 bit60 */
			{    0, 0,2}, /* core5 return_Stack0 bit61 */
			{    0, 0,2}, /* core5 return_Stack0 bit62 */
			{    0, 0,2}, /* core5 return_Stack0 bit63 */
			}},
			.return_Stack1 = {{
			{19490,55,0}, /* core5 return_Stack1 bit0 */
			{19488,55,0}, /* core5 return_Stack1 bit1 */
			{19486,55,0}, /* core5 return_Stack1 bit2 */
			{19484,55,0}, /* core5 return_Stack1 bit3 */
			{19242,55,0}, /* core5 return_Stack1 bit4 */
			{19240,55,0}, /* core5 return_Stack1 bit5 */
			{19466,55,0}, /* core5 return_Stack1 bit6 */
			{19238,55,0}, /* core5 return_Stack1 bit7 */
			{19236,55,0}, /* core5 return_Stack1 bit8 */
			{19258,55,0}, /* core5 return_Stack1 bit9 */
			{19256,55,0}, /* core5 return_Stack1 bit10 */
			{19464,55,0}, /* core5 return_Stack1 bit11 */
			{19254,55,0}, /* core5 return_Stack1 bit12 */
			{19252,55,0}, /* core5 return_Stack1 bit13 */
			{19474,55,0}, /* core5 return_Stack1 bit14 */
			{19472,55,0}, /* core5 return_Stack1 bit15 */
			{19470,55,0}, /* core5 return_Stack1 bit16 */
			{19468,55,0}, /* core5 return_Stack1 bit17 */
			{19462,55,0}, /* core5 return_Stack1 bit18 */
			{19460,55,0}, /* core5 return_Stack1 bit19 */
			{19410,55,0}, /* core5 return_Stack1 bit20 */
			{19408,55,0}, /* core5 return_Stack1 bit21 */
			{19406,55,0}, /* core5 return_Stack1 bit22 */
			{19404,55,0}, /* core5 return_Stack1 bit23 */
			{19418,55,0}, /* core5 return_Stack1 bit24 */
			{19416,55,0}, /* core5 return_Stack1 bit25 */
			{19414,55,0}, /* core5 return_Stack1 bit26 */
			{19412,55,0}, /* core5 return_Stack1 bit27 */
			{19402,55,0}, /* core5 return_Stack1 bit28 */
			{19400,55,0}, /* core5 return_Stack1 bit29 */
			{19398,55,0}, /* core5 return_Stack1 bit30 */
			{19396,55,0}, /* core5 return_Stack1 bit31 */
			{19386,55,0}, /* core5 return_Stack1 bit32 */
			{19384,55,0}, /* core5 return_Stack1 bit33 */
			{19382,55,0}, /* core5 return_Stack1 bit34 */
			{19380,55,0}, /* core5 return_Stack1 bit35 */
			{19370,55,0}, /* core5 return_Stack1 bit36 */
			{19368,55,0}, /* core5 return_Stack1 bit37 */
			{19366,55,0}, /* core5 return_Stack1 bit38 */
			{19364,55,0}, /* core5 return_Stack1 bit39 */
			{19354,55,0}, /* core5 return_Stack1 bit40 */
			{19346,55,0}, /* core5 return_Stack1 bit41 */
			{19344,55,0}, /* core5 return_Stack1 bit42 */
			{19352,55,0}, /* core5 return_Stack1 bit43 */
			{19350,55,0}, /* core5 return_Stack1 bit44 */
			{19342,55,0}, /* core5 return_Stack1 bit45 */
			{19348,55,0}, /* core5 return_Stack1 bit46 */
			{19340,55,0}, /* core5 return_Stack1 bit47 */
			{ 3024,55,0}, /* core5 return_Stack1 bit48 */
			{    0, 0,2}, /* core5 return_Stack1 bit49 */
			{    0, 0,2}, /* core5 return_Stack1 bit50 */
			{    0, 0,2}, /* core5 return_Stack1 bit51 */
			{    0, 0,2}, /* core5 return_Stack1 bit52 */
			{    0, 0,2}, /* core5 return_Stack1 bit53 */
			{    0, 0,2}, /* core5 return_Stack1 bit54 */
			{    0, 0,2}, /* core5 return_Stack1 bit55 */
			{    0, 0,2}, /* core5 return_Stack1 bit56 */
			{    0, 0,2}, /* core5 return_Stack1 bit57 */
			{    0, 0,2}, /* core5 return_Stack1 bit58 */
			{    0, 0,2}, /* core5 return_Stack1 bit59 */
			{    0, 0,2}, /* core5 return_Stack1 bit60 */
			{    0, 0,2}, /* core5 return_Stack1 bit61 */
			{    0, 0,2}, /* core5 return_Stack1 bit62 */
			{    0, 0,2}, /* core5 return_Stack1 bit63 */
			}},
			.return_Stack2 = {{
			{ 7850,55,0}, /* core5 return_Stack2 bit0 */
			{19282,55,0}, /* core5 return_Stack2 bit1 */
			{ 7848,55,0}, /* core5 return_Stack2 bit2 */
			{19280,55,0}, /* core5 return_Stack2 bit3 */
			{19278,55,0}, /* core5 return_Stack2 bit4 */
			{19234,55,0}, /* core5 return_Stack2 bit5 */
			{19276,55,0}, /* core5 return_Stack2 bit6 */
			{ 3028,55,0}, /* core5 return_Stack2 bit7 */
			{19232,55,0}, /* core5 return_Stack2 bit8 */
			{19230,55,0}, /* core5 return_Stack2 bit9 */
			{19218,55,0}, /* core5 return_Stack2 bit10 */
			{19228,55,0}, /* core5 return_Stack2 bit11 */
			{19216,55,0}, /* core5 return_Stack2 bit12 */
			{ 7834,55,0}, /* core5 return_Stack2 bit13 */
			{19214,55,0}, /* core5 return_Stack2 bit14 */
			{ 7832,55,0}, /* core5 return_Stack2 bit15 */
			{19212,55,0}, /* core5 return_Stack2 bit16 */
			{19202,55,0}, /* core5 return_Stack2 bit17 */
			{19200,55,0}, /* core5 return_Stack2 bit18 */
			{19198,55,0}, /* core5 return_Stack2 bit19 */
			{19196,55,0}, /* core5 return_Stack2 bit20 */
			{19178,55,0}, /* core5 return_Stack2 bit21 */
			{19176,55,0}, /* core5 return_Stack2 bit22 */
			{19174,55,0}, /* core5 return_Stack2 bit23 */
			{19172,55,0}, /* core5 return_Stack2 bit24 */
			{19170,55,0}, /* core5 return_Stack2 bit25 */
			{19168,55,0}, /* core5 return_Stack2 bit26 */
			{19166,55,0}, /* core5 return_Stack2 bit27 */
			{19164,55,0}, /* core5 return_Stack2 bit28 */
			{19138,55,0}, /* core5 return_Stack2 bit29 */
			{19136,55,0}, /* core5 return_Stack2 bit30 */
			{19134,55,0}, /* core5 return_Stack2 bit31 */
			{19132,55,0}, /* core5 return_Stack2 bit32 */
			{19538,55,0}, /* core5 return_Stack2 bit33 */
			{19536,55,0}, /* core5 return_Stack2 bit34 */
			{19534,55,0}, /* core5 return_Stack2 bit35 */
			{19532,55,0}, /* core5 return_Stack2 bit36 */
			{19522,55,0}, /* core5 return_Stack2 bit37 */
			{19520,55,0}, /* core5 return_Stack2 bit38 */
			{19518,55,0}, /* core5 return_Stack2 bit39 */
			{19516,55,0}, /* core5 return_Stack2 bit40 */
			{19514,55,0}, /* core5 return_Stack2 bit41 */
			{19512,55,0}, /* core5 return_Stack2 bit42 */
			{19510,55,0}, /* core5 return_Stack2 bit43 */
			{19508,55,0}, /* core5 return_Stack2 bit44 */
			{19338,55,0}, /* core5 return_Stack2 bit45 */
			{19336,55,0}, /* core5 return_Stack2 bit46 */
			{19334,55,0}, /* core5 return_Stack2 bit47 */
			{19332,55,0}, /* core5 return_Stack2 bit48 */
			{    0, 0,2}, /* core5 return_Stack2 bit49 */
			{    0, 0,2}, /* core5 return_Stack2 bit50 */
			{    0, 0,2}, /* core5 return_Stack2 bit51 */
			{    0, 0,2}, /* core5 return_Stack2 bit52 */
			{    0, 0,2}, /* core5 return_Stack2 bit53 */
			{    0, 0,2}, /* core5 return_Stack2 bit54 */
			{    0, 0,2}, /* core5 return_Stack2 bit55 */
			{    0, 0,2}, /* core5 return_Stack2 bit56 */
			{    0, 0,2}, /* core5 return_Stack2 bit57 */
			{    0, 0,2}, /* core5 return_Stack2 bit58 */
			{    0, 0,2}, /* core5 return_Stack2 bit59 */
			{    0, 0,2}, /* core5 return_Stack2 bit60 */
			{    0, 0,2}, /* core5 return_Stack2 bit61 */
			{    0, 0,2}, /* core5 return_Stack2 bit62 */
			{    0, 0,2}, /* core5 return_Stack2 bit63 */
			}},
			.return_Stack3 = {{
			{ 3030,55,0}, /* core5 return_Stack3 bit0 */
			{19322,55,0}, /* core5 return_Stack3 bit1 */
			{19320,55,0}, /* core5 return_Stack3 bit2 */
			{19318,55,0}, /* core5 return_Stack3 bit3 */
			{19316,55,0}, /* core5 return_Stack3 bit4 */
			{19290,55,0}, /* core5 return_Stack3 bit5 */
			{19288,55,0}, /* core5 return_Stack3 bit6 */
			{19286,55,0}, /* core5 return_Stack3 bit7 */
			{19284,55,0}, /* core5 return_Stack3 bit8 */
			{19226,55,0}, /* core5 return_Stack3 bit9 */
			{19224,55,0}, /* core5 return_Stack3 bit10 */
			{19222,55,0}, /* core5 return_Stack3 bit11 */
			{19220,55,0}, /* core5 return_Stack3 bit12 */
			{19210,55,0}, /* core5 return_Stack3 bit13 */
			{19208,55,0}, /* core5 return_Stack3 bit14 */
			{19206,55,0}, /* core5 return_Stack3 bit15 */
			{19204,55,0}, /* core5 return_Stack3 bit16 */
			{19194,55,0}, /* core5 return_Stack3 bit17 */
			{19192,55,0}, /* core5 return_Stack3 bit18 */
			{19190,55,0}, /* core5 return_Stack3 bit19 */
			{19188,55,0}, /* core5 return_Stack3 bit20 */
			{19186,55,0}, /* core5 return_Stack3 bit21 */
			{19184,55,0}, /* core5 return_Stack3 bit22 */
			{19182,55,0}, /* core5 return_Stack3 bit23 */
			{19180,55,0}, /* core5 return_Stack3 bit24 */
			{19162,55,0}, /* core5 return_Stack3 bit25 */
			{19160,55,0}, /* core5 return_Stack3 bit26 */
			{19158,55,0}, /* core5 return_Stack3 bit27 */
			{19156,55,0}, /* core5 return_Stack3 bit28 */
			{19130,55,0}, /* core5 return_Stack3 bit29 */
			{19128,55,0}, /* core5 return_Stack3 bit30 */
			{19126,55,0}, /* core5 return_Stack3 bit31 */
			{19124,55,0}, /* core5 return_Stack3 bit32 */
			{19546,55,0}, /* core5 return_Stack3 bit33 */
			{19544,55,0}, /* core5 return_Stack3 bit34 */
			{19542,55,0}, /* core5 return_Stack3 bit35 */
			{19540,55,0}, /* core5 return_Stack3 bit36 */
			{19530,55,0}, /* core5 return_Stack3 bit37 */
			{19528,55,0}, /* core5 return_Stack3 bit38 */
			{19526,55,0}, /* core5 return_Stack3 bit39 */
			{19524,55,0}, /* core5 return_Stack3 bit40 */
			{19506,55,0}, /* core5 return_Stack3 bit41 */
			{19504,55,0}, /* core5 return_Stack3 bit42 */
			{19502,55,0}, /* core5 return_Stack3 bit43 */
			{19500,55,0}, /* core5 return_Stack3 bit44 */
			{19330,55,0}, /* core5 return_Stack3 bit45 */
			{19328,55,0}, /* core5 return_Stack3 bit46 */
			{19326,55,0}, /* core5 return_Stack3 bit47 */
			{19324,55,0}, /* core5 return_Stack3 bit48 */
			{    0, 0,2}, /* core5 return_Stack3 bit49 */
			{    0, 0,2}, /* core5 return_Stack3 bit50 */
			{    0, 0,2}, /* core5 return_Stack3 bit51 */
			{    0, 0,2}, /* core5 return_Stack3 bit52 */
			{    0, 0,2}, /* core5 return_Stack3 bit53 */
			{    0, 0,2}, /* core5 return_Stack3 bit54 */
			{    0, 0,2}, /* core5 return_Stack3 bit55 */
			{    0, 0,2}, /* core5 return_Stack3 bit56 */
			{    0, 0,2}, /* core5 return_Stack3 bit57 */
			{    0, 0,2}, /* core5 return_Stack3 bit58 */
			{    0, 0,2}, /* core5 return_Stack3 bit59 */
			{    0, 0,2}, /* core5 return_Stack3 bit60 */
			{    0, 0,2}, /* core5 return_Stack3 bit61 */
			{    0, 0,2}, /* core5 return_Stack3 bit62 */
			{    0, 0,2}, /* core5 return_Stack3 bit63 */
			}},
			.return_Stack4 = {{
			{19314,55,0}, /* core5 return_Stack4 bit0 */
			{19312,55,0}, /* core5 return_Stack4 bit1 */
			{19310,55,0}, /* core5 return_Stack4 bit2 */
			{19308,55,0}, /* core5 return_Stack4 bit3 */
			{19306,55,0}, /* core5 return_Stack4 bit4 */
			{19304,55,0}, /* core5 return_Stack4 bit5 */
			{19302,55,0}, /* core5 return_Stack4 bit6 */
			{19300,55,0}, /* core5 return_Stack4 bit7 */
			{19298,55,0}, /* core5 return_Stack4 bit8 */
			{19296,55,0}, /* core5 return_Stack4 bit9 */
			{19294,55,0}, /* core5 return_Stack4 bit10 */
			{19292,55,0}, /* core5 return_Stack4 bit11 */
			{19458,55,0}, /* core5 return_Stack4 bit12 */
			{ 7842,55,0}, /* core5 return_Stack4 bit13 */
			{19456,55,0}, /* core5 return_Stack4 bit14 */
			{ 7840,55,0}, /* core5 return_Stack4 bit15 */
			{19454,55,0}, /* core5 return_Stack4 bit16 */
			{19452,55,0}, /* core5 return_Stack4 bit17 */
			{19450,55,0}, /* core5 return_Stack4 bit18 */
			{19448,55,0}, /* core5 return_Stack4 bit19 */
			{19446,55,0}, /* core5 return_Stack4 bit20 */
			{19444,55,0}, /* core5 return_Stack4 bit21 */
			{19146,55,0}, /* core5 return_Stack4 bit22 */
			{19144,55,0}, /* core5 return_Stack4 bit23 */
			{19142,55,0}, /* core5 return_Stack4 bit24 */
			{19140,55,0}, /* core5 return_Stack4 bit25 */
			{19154,55,0}, /* core5 return_Stack4 bit26 */
			{19152,55,0}, /* core5 return_Stack4 bit27 */
			{19150,55,0}, /* core5 return_Stack4 bit28 */
			{19148,55,0}, /* core5 return_Stack4 bit29 */
			{19122,55,0}, /* core5 return_Stack4 bit30 */
			{19120,55,0}, /* core5 return_Stack4 bit31 */
			{19118,55,0}, /* core5 return_Stack4 bit32 */
			{19116,55,0}, /* core5 return_Stack4 bit33 */
			{19114,55,0}, /* core5 return_Stack4 bit34 */
			{19112,55,0}, /* core5 return_Stack4 bit35 */
			{19110,55,0}, /* core5 return_Stack4 bit36 */
			{19108,55,0}, /* core5 return_Stack4 bit37 */
			{19046,55,0}, /* core5 return_Stack4 bit38 */
			{19044,55,0}, /* core5 return_Stack4 bit39 */
			{19042,55,0}, /* core5 return_Stack4 bit40 */
			{19040,55,0}, /* core5 return_Stack4 bit41 */
			{19054,55,0}, /* core5 return_Stack4 bit42 */
			{19052,55,0}, /* core5 return_Stack4 bit43 */
			{19050,55,0}, /* core5 return_Stack4 bit44 */
			{19048,55,0}, /* core5 return_Stack4 bit45 */
			{ 7854,55,0}, /* core5 return_Stack4 bit46 */
			{ 7852,55,0}, /* core5 return_Stack4 bit47 */
			{ 3026,55,0}, /* core5 return_Stack4 bit48 */
			{    0, 0,2}, /* core5 return_Stack4 bit49 */
			{    0, 0,2}, /* core5 return_Stack4 bit50 */
			{    0, 0,2}, /* core5 return_Stack4 bit51 */
			{    0, 0,2}, /* core5 return_Stack4 bit52 */
			{    0, 0,2}, /* core5 return_Stack4 bit53 */
			{    0, 0,2}, /* core5 return_Stack4 bit54 */
			{    0, 0,2}, /* core5 return_Stack4 bit55 */
			{    0, 0,2}, /* core5 return_Stack4 bit56 */
			{    0, 0,2}, /* core5 return_Stack4 bit57 */
			{    0, 0,2}, /* core5 return_Stack4 bit58 */
			{    0, 0,2}, /* core5 return_Stack4 bit59 */
			{    0, 0,2}, /* core5 return_Stack4 bit60 */
			{    0, 0,2}, /* core5 return_Stack4 bit61 */
			{    0, 0,2}, /* core5 return_Stack4 bit62 */
			{    0, 0,2}, /* core5 return_Stack4 bit63 */
			}},
			.return_Stack5 = {{
			{18982,55,0}, /* core5 return_Stack5 bit0 */
			{18980,55,0}, /* core5 return_Stack5 bit1 */
			{18978,55,0}, /* core5 return_Stack5 bit2 */
			{18976,55,0}, /* core5 return_Stack5 bit3 */
			{18958,55,0}, /* core5 return_Stack5 bit4 */
			{18942,55,0}, /* core5 return_Stack5 bit5 */
			{18956,55,0}, /* core5 return_Stack5 bit6 */
			{18954,55,0}, /* core5 return_Stack5 bit7 */
			{18952,55,0}, /* core5 return_Stack5 bit8 */
			{18940,55,0}, /* core5 return_Stack5 bit9 */
			{18938,55,0}, /* core5 return_Stack5 bit10 */
			{18936,55,0}, /* core5 return_Stack5 bit11 */
			{18918,55,0}, /* core5 return_Stack5 bit12 */
			{18916,55,0}, /* core5 return_Stack5 bit13 */
			{18914,55,0}, /* core5 return_Stack5 bit14 */
			{18912,55,0}, /* core5 return_Stack5 bit15 */
			{18886,55,0}, /* core5 return_Stack5 bit16 */
			{18884,55,0}, /* core5 return_Stack5 bit17 */
			{18882,55,0}, /* core5 return_Stack5 bit18 */
			{18880,55,0}, /* core5 return_Stack5 bit19 */
			{18838,55,0}, /* core5 return_Stack5 bit20 */
			{18836,55,0}, /* core5 return_Stack5 bit21 */
			{18834,55,0}, /* core5 return_Stack5 bit22 */
			{18832,55,0}, /* core5 return_Stack5 bit23 */
			{18830,55,0}, /* core5 return_Stack5 bit24 */
			{18828,55,0}, /* core5 return_Stack5 bit25 */
			{18826,55,0}, /* core5 return_Stack5 bit26 */
			{18824,55,0}, /* core5 return_Stack5 bit27 */
			{19014,55,0}, /* core5 return_Stack5 bit28 */
			{19012,55,0}, /* core5 return_Stack5 bit29 */
			{19010,55,0}, /* core5 return_Stack5 bit30 */
			{19008,55,0}, /* core5 return_Stack5 bit31 */
			{19022,55,0}, /* core5 return_Stack5 bit32 */
			{ 7894,55,0}, /* core5 return_Stack5 bit33 */
			{19020,55,0}, /* core5 return_Stack5 bit34 */
			{19018,55,0}, /* core5 return_Stack5 bit35 */
			{19016,55,0}, /* core5 return_Stack5 bit36 */
			{ 7892,55,0}, /* core5 return_Stack5 bit37 */
			{19086,55,0}, /* core5 return_Stack5 bit38 */
			{19084,55,0}, /* core5 return_Stack5 bit39 */
			{19082,55,0}, /* core5 return_Stack5 bit40 */
			{19080,55,0}, /* core5 return_Stack5 bit41 */
			{19062,55,0}, /* core5 return_Stack5 bit42 */
			{19060,55,0}, /* core5 return_Stack5 bit43 */
			{19058,55,0}, /* core5 return_Stack5 bit44 */
			{19056,55,0}, /* core5 return_Stack5 bit45 */
			{ 7862,55,0}, /* core5 return_Stack5 bit46 */
			{ 7860,55,0}, /* core5 return_Stack5 bit47 */
			{ 3034,55,0}, /* core5 return_Stack5 bit48 */
			{    0, 0,2}, /* core5 return_Stack5 bit49 */
			{    0, 0,2}, /* core5 return_Stack5 bit50 */
			{    0, 0,2}, /* core5 return_Stack5 bit51 */
			{    0, 0,2}, /* core5 return_Stack5 bit52 */
			{    0, 0,2}, /* core5 return_Stack5 bit53 */
			{    0, 0,2}, /* core5 return_Stack5 bit54 */
			{    0, 0,2}, /* core5 return_Stack5 bit55 */
			{    0, 0,2}, /* core5 return_Stack5 bit56 */
			{    0, 0,2}, /* core5 return_Stack5 bit57 */
			{    0, 0,2}, /* core5 return_Stack5 bit58 */
			{    0, 0,2}, /* core5 return_Stack5 bit59 */
			{    0, 0,2}, /* core5 return_Stack5 bit60 */
			{    0, 0,2}, /* core5 return_Stack5 bit61 */
			{    0, 0,2}, /* core5 return_Stack5 bit62 */
			{    0, 0,2}, /* core5 return_Stack5 bit63 */
			}},
			.return_Stack6 = {{
			{18990,55,0}, /* core5 return_Stack6 bit0 */
			{18988,55,0}, /* core5 return_Stack6 bit1 */
			{18986,55,0}, /* core5 return_Stack6 bit2 */
			{18984,55,0}, /* core5 return_Stack6 bit3 */
			{18950,55,0}, /* core5 return_Stack6 bit4 */
			{18926,55,0}, /* core5 return_Stack6 bit5 */
			{18948,55,0}, /* core5 return_Stack6 bit6 */
			{18946,55,0}, /* core5 return_Stack6 bit7 */
			{18944,55,0}, /* core5 return_Stack6 bit8 */
			{18924,55,0}, /* core5 return_Stack6 bit9 */
			{18922,55,0}, /* core5 return_Stack6 bit10 */
			{18920,55,0}, /* core5 return_Stack6 bit11 */
			{18902,55,0}, /* core5 return_Stack6 bit12 */
			{18900,55,0}, /* core5 return_Stack6 bit13 */
			{18898,55,0}, /* core5 return_Stack6 bit14 */
			{18896,55,0}, /* core5 return_Stack6 bit15 */
			{18894,55,0}, /* core5 return_Stack6 bit16 */
			{18892,55,0}, /* core5 return_Stack6 bit17 */
			{18890,55,0}, /* core5 return_Stack6 bit18 */
			{18888,55,0}, /* core5 return_Stack6 bit19 */
			{18862,55,0}, /* core5 return_Stack6 bit20 */
			{18860,55,0}, /* core5 return_Stack6 bit21 */
			{18858,55,0}, /* core5 return_Stack6 bit22 */
			{18856,55,0}, /* core5 return_Stack6 bit23 */
			{18846,55,0}, /* core5 return_Stack6 bit24 */
			{18844,55,0}, /* core5 return_Stack6 bit25 */
			{18842,55,0}, /* core5 return_Stack6 bit26 */
			{18840,55,0}, /* core5 return_Stack6 bit27 */
			{19006,55,0}, /* core5 return_Stack6 bit28 */
			{19004,55,0}, /* core5 return_Stack6 bit29 */
			{19002,55,0}, /* core5 return_Stack6 bit30 */
			{19000,55,0}, /* core5 return_Stack6 bit31 */
			{19030,55,0}, /* core5 return_Stack6 bit32 */
			{ 7886,55,0}, /* core5 return_Stack6 bit33 */
			{19028,55,0}, /* core5 return_Stack6 bit34 */
			{19026,55,0}, /* core5 return_Stack6 bit35 */
			{19024,55,0}, /* core5 return_Stack6 bit36 */
			{ 7884,55,0}, /* core5 return_Stack6 bit37 */
			{19102,55,0}, /* core5 return_Stack6 bit38 */
			{19100,55,0}, /* core5 return_Stack6 bit39 */
			{19098,55,0}, /* core5 return_Stack6 bit40 */
			{19096,55,0}, /* core5 return_Stack6 bit41 */
			{19070,55,0}, /* core5 return_Stack6 bit42 */
			{19068,55,0}, /* core5 return_Stack6 bit43 */
			{19066,55,0}, /* core5 return_Stack6 bit44 */
			{19064,55,0}, /* core5 return_Stack6 bit45 */
			{ 7866,55,0}, /* core5 return_Stack6 bit46 */
			{ 7864,55,0}, /* core5 return_Stack6 bit47 */
			{ 3036,55,0}, /* core5 return_Stack6 bit48 */
			{    0, 0,2}, /* core5 return_Stack6 bit49 */
			{    0, 0,2}, /* core5 return_Stack6 bit50 */
			{    0, 0,2}, /* core5 return_Stack6 bit51 */
			{    0, 0,2}, /* core5 return_Stack6 bit52 */
			{    0, 0,2}, /* core5 return_Stack6 bit53 */
			{    0, 0,2}, /* core5 return_Stack6 bit54 */
			{    0, 0,2}, /* core5 return_Stack6 bit55 */
			{    0, 0,2}, /* core5 return_Stack6 bit56 */
			{    0, 0,2}, /* core5 return_Stack6 bit57 */
			{    0, 0,2}, /* core5 return_Stack6 bit58 */
			{    0, 0,2}, /* core5 return_Stack6 bit59 */
			{    0, 0,2}, /* core5 return_Stack6 bit60 */
			{    0, 0,2}, /* core5 return_Stack6 bit61 */
			{    0, 0,2}, /* core5 return_Stack6 bit62 */
			{    0, 0,2}, /* core5 return_Stack6 bit63 */
			}},
			.return_Stack7 = {{
			{18974,55,0}, /* core5 return_Stack7 bit0 */
			{18972,55,0}, /* core5 return_Stack7 bit1 */
			{18970,55,0}, /* core5 return_Stack7 bit2 */
			{18968,55,0}, /* core5 return_Stack7 bit3 */
			{18966,55,0}, /* core5 return_Stack7 bit4 */
			{18934,55,0}, /* core5 return_Stack7 bit5 */
			{18964,55,0}, /* core5 return_Stack7 bit6 */
			{18962,55,0}, /* core5 return_Stack7 bit7 */
			{18960,55,0}, /* core5 return_Stack7 bit8 */
			{18932,55,0}, /* core5 return_Stack7 bit9 */
			{18930,55,0}, /* core5 return_Stack7 bit10 */
			{18928,55,0}, /* core5 return_Stack7 bit11 */
			{18910,55,0}, /* core5 return_Stack7 bit12 */
			{18908,55,0}, /* core5 return_Stack7 bit13 */
			{18906,55,0}, /* core5 return_Stack7 bit14 */
			{18904,55,0}, /* core5 return_Stack7 bit15 */
			{18878,55,0}, /* core5 return_Stack7 bit16 */
			{18876,55,0}, /* core5 return_Stack7 bit17 */
			{18874,55,0}, /* core5 return_Stack7 bit18 */
			{18872,55,0}, /* core5 return_Stack7 bit19 */
			{18870,55,0}, /* core5 return_Stack7 bit20 */
			{18868,55,0}, /* core5 return_Stack7 bit21 */
			{18866,55,0}, /* core5 return_Stack7 bit22 */
			{18864,55,0}, /* core5 return_Stack7 bit23 */
			{18854,55,0}, /* core5 return_Stack7 bit24 */
			{18852,55,0}, /* core5 return_Stack7 bit25 */
			{18850,55,0}, /* core5 return_Stack7 bit26 */
			{18848,55,0}, /* core5 return_Stack7 bit27 */
			{18998,55,0}, /* core5 return_Stack7 bit28 */
			{18996,55,0}, /* core5 return_Stack7 bit29 */
			{18994,55,0}, /* core5 return_Stack7 bit30 */
			{18992,55,0}, /* core5 return_Stack7 bit31 */
			{19038,55,0}, /* core5 return_Stack7 bit32 */
			{ 7890,55,0}, /* core5 return_Stack7 bit33 */
			{19036,55,0}, /* core5 return_Stack7 bit34 */
			{19034,55,0}, /* core5 return_Stack7 bit35 */
			{19032,55,0}, /* core5 return_Stack7 bit36 */
			{ 7888,55,0}, /* core5 return_Stack7 bit37 */
			{19094,55,0}, /* core5 return_Stack7 bit38 */
			{19092,55,0}, /* core5 return_Stack7 bit39 */
			{19090,55,0}, /* core5 return_Stack7 bit40 */
			{19088,55,0}, /* core5 return_Stack7 bit41 */
			{19078,55,0}, /* core5 return_Stack7 bit42 */
			{19076,55,0}, /* core5 return_Stack7 bit43 */
			{19074,55,0}, /* core5 return_Stack7 bit44 */
			{19072,55,0}, /* core5 return_Stack7 bit45 */
			{ 7858,55,0}, /* core5 return_Stack7 bit46 */
			{ 7856,55,0}, /* core5 return_Stack7 bit47 */
			{ 3032,55,0}, /* core5 return_Stack7 bit48 */
			{    0, 0,2}, /* core5 return_Stack7 bit49 */
			{    0, 0,2}, /* core5 return_Stack7 bit50 */
			{    0, 0,2}, /* core5 return_Stack7 bit51 */
			{    0, 0,2}, /* core5 return_Stack7 bit52 */
			{    0, 0,2}, /* core5 return_Stack7 bit53 */
			{    0, 0,2}, /* core5 return_Stack7 bit54 */
			{    0, 0,2}, /* core5 return_Stack7 bit55 */
			{    0, 0,2}, /* core5 return_Stack7 bit56 */
			{    0, 0,2}, /* core5 return_Stack7 bit57 */
			{    0, 0,2}, /* core5 return_Stack7 bit58 */
			{    0, 0,2}, /* core5 return_Stack7 bit59 */
			{    0, 0,2}, /* core5 return_Stack7 bit60 */
			{    0, 0,2}, /* core5 return_Stack7 bit61 */
			{    0, 0,2}, /* core5 return_Stack7 bit62 */
			{    0, 0,2}, /* core5 return_Stack7 bit63 */
			}},
	},
}; 

struct big_core_spec big_core[] = {
	
	{		/* core 6 */ 
	},
	{		/* core 7 */ 
	},
}; 
