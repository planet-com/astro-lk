/* Copyright Statement:
*
* This software/firmware and related documentation ("MediaTek Software") are
* protected under relevant copyright laws. The information contained herein
* is confidential and proprietary to MediaTek Inc. and/or its licensors.
* Without the prior written permission of MediaTek inc. and/or its licensors,
* any reproduction, modification, use or disclosure of MediaTek Software,
* and information contained herein, in whole or in part, shall be strictly prohibited.
*/
/* MediaTek Inc. (C) 2017. All rights reserved.
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
*
* The following software/firmware and/or related documentation ("MediaTek Software")
* have been modified by MediaTek Inc. All revisions are subject to any receiver\'s
* applicable license agreements with MediaTek Inc.
*/
#include <sys/types.h>
#define LOCAL_REG_SET_DECLARE \
	register size_t reg0 __asm__("r0") = function_id; \
	register size_t reg1 __asm__("r1") = arg0; \
	register size_t reg2 __asm__("r2") = arg1; \
	register size_t reg3 __asm__("r3") = arg2; \
	register size_t reg4 __asm__("r4") = arg3; \
	size_t ret

#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)
#define ___asm_opcode_identity16(x) ((x) & 0xFFFF)

#define ___asm_opcode_thumb32_first(x) (___asm_opcode_identity16((x) >> 16))
#define ___asm_opcode_thumb32_second(x) (___asm_opcode_identity16(x))
#define ___asm_opcode_to_mem_thumb16(x) ___asm_opcode_identity16(x)


#define ___inst_thumb32(first, second) \
	".short " __stringify(first) ", " __stringify(second) "\n"

#define __inst_thumb32(x) ___inst_thumb32(				\
	___asm_opcode_to_mem_thumb16(___asm_opcode_thumb32_first(x)),	\
	___asm_opcode_to_mem_thumb16(___asm_opcode_thumb32_second(x))	\
)
#define __HVC(imm16) __inst_thumb32(0xF7E08000 | (((imm16) & 0xF000) << 4) | ((imm16) & 0x0FFF))

size_t mt_hvc_call(size_t function_id,
	size_t arg0, size_t arg1, size_t arg2,
	size_t arg3, size_t *r1, size_t *r2, size_t *r3)
{
	LOCAL_REG_SET_DECLARE;
#ifdef SUPPORT_ARMV7VE
	__asm__ volatile ("hvc #0x0\n" : "+r"(reg0),
		"+r"(reg1), "+r"(reg2), "+r"(reg3), "+r"(reg4));
#else
	__asm__ volatile (__HVC(0) : "+r"(reg0),
		"+r"(reg1), "+r"(reg2), "+r"(reg3), "+r"(reg4));
#endif
	ret = reg0;
	if (r1 != NULL)
		*r1 = reg1;
	if (r2 != NULL)
		*r2 = reg2;
	if (r3 != NULL)
		*r3 = reg3;
	return ret;
}
