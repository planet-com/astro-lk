/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */

/* MediaTek Inc. (C) 2020. All rights reserved.
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
#include <printf.h>
#include <stdlib.h>


#define SANI_SHOW(fmt, ...)	dprintf(CRITICAL, fmt, ##__VA_ARGS__)
#define SANI_ABORT()		panic("sanitizer")

typedef struct _type_desc
{
#define UB_SIGNED(type)		((type)->info&1)
#define UB_BITS(type)		(1U << ((type)->info >> 1))
#define UB_VAL(type, val)	(sizeof(long) * 8 >= UB_BITS(type) ? (unsigned long)(val) : *(unsigned long long *)(val))
	unsigned short kind, info;
	char name[1];
} type_desc;

typedef struct _src_loc
{
	const char *file;
	unsigned line, col;
} src_loc;

static bool ub_skip(src_loc *loc)
{
#define UB_SKIP_VAL			(1U << 31)

	if ((loc->line&UB_SKIP_VAL)
		|| !strncmp(loc->file, "lib/", sizeof("lib/") - 1)
		|| !strncmp(loc->file, "kernel/", sizeof("kernel/") - 1)
		|| !strncmp(loc->file, "arch/", sizeof("arch/") - 1)
		|| !strncmp(loc->file, "platform/common/avb/libavb/", sizeof("platform/common/avb/libavb/") - 1))
		return true;
	SANI_SHOW("UBSAN detect at <%s:%u:%u>\n", loc->file, loc->line, loc->col);
	loc->line |= UB_SKIP_VAL;
	return false;
}

static void ub_val2str(char *str, unsigned size, type_desc *type, void *val)
{
	unsigned long long x;
	int extra_bits;
	long long ll_x;

	if (size < 2)
		return;
	str[0] = '\0';
	if (type->kind)
		return;
	if (UB_SIGNED(type)) {
		extra_bits = sizeof(long) * 8 - UB_BITS(type);
		ll_x = (extra_bits >= 0 ? ((long)((unsigned long)val << extra_bits)) >> extra_bits : *(long long *)val);
		snprintf(str, size, "%lld", ll_x);
	} else {
		x = UB_VAL(type, val);
		snprintf(str, size, "%llu", x);
	}
}

static void ub_handle_type_mismatch(src_loc *loc, type_desc *type, unsigned long align, unsigned kind, void *ptr)
{
	static const char * const kinds[] =
	{
		"load of","store to","reference binding to","member access within",
		"member call on","constructor call on","downcast of","downcast of",
	};

	if (ub_skip(loc))
		return;
	if (!ptr)
		SANI_SHOW("%s null ptr(type: %s)\n", kinds[kind], type->name);
	else if (align && ((unsigned long)ptr&(align - 1)))
		SANI_SHOW("%s misaligned address %p(type: %s, align: %luB)\n", kinds[kind], ptr, type->name, align);
	else
		SANI_SHOW("%s address %p(type: %s) with insufficient space\n", kinds[kind], ptr, type->name);
	SANI_ABORT();
}

static void ub_handle_int_overflow(void *data, void *lval, void *rval, char op)
{
	struct
	{
		src_loc loc;
		type_desc *type;
	} *inf = data;
	char lstr[24], rstr[24];

	if (ub_skip(&inf->loc))
		return;
	ub_val2str(lstr, sizeof(lstr), inf->type, lval);
	ub_val2str(rstr, sizeof(rstr), inf->type, rval);
	SANI_SHOW("int overflow: %s %c %s can't be represented in type %s\n", lstr, op, rstr, inf->type->name);
	SANI_ABORT();
}

/*  === compiler interface === */

void __ubsan_handle_add_overflow(void *data, void *lval, void *rval)
{
	ub_handle_int_overflow(data, lval, rval, '+');
}

void __ubsan_handle_sub_overflow(void *data, void *lval, void *rval)
{
	ub_handle_int_overflow(data, lval, rval, '-');
}

void __ubsan_handle_mul_overflow(void *data, void *lval, void *rval)
{
	ub_handle_int_overflow(data, lval, rval, '*');
}

void __ubsan_handle_divrem_overflow(void *data, void *lval, void *rval)
{
	ub_handle_int_overflow(data, lval, rval, '/');
}

void __ubsan_handle_negate_overflow(void *data, void *val)
{
	struct
	{
		src_loc loc;
		type_desc *type;
	} *inf = data;
	char str[24];

	if (ub_skip(&inf->loc))
		return;
	ub_val2str(str, sizeof(str), inf->type, val);
	SANI_SHOW("neg of %s can't be represented in type %s\n", str, inf->type->name);
	SANI_ABORT();
}

void __ubsan_handle_type_mismatch_v1(void *data, void *ptr)
{
	struct
	{
		src_loc loc;
		type_desc *type;
		unsigned char log_align, kind;
	} *inf = data;

	ub_handle_type_mismatch(&inf->loc, inf->type, 1UL << inf->log_align, inf->kind, ptr);
}

void __ubsan_handle_type_mismatch(void *data, void *ptr)
{
	struct
	{
		src_loc loc;
		type_desc *type;
		unsigned long align;
		unsigned char kind;
	} *inf = data;

	ub_handle_type_mismatch(&inf->loc, inf->type, inf->align, inf->kind, ptr);
}

void __ubsan_handle_nonnull_return(void *data)
{
	struct
	{
		src_loc loc, attr_loc;
	} *inf = data;

	if (ub_skip(&inf->loc))
		return;
	SANI_SHOW("func return null ptr\n");
	if (inf->attr_loc.file)
		SANI_SHOW("returns_nonnull attribute specified in <%s:%u:%u>\n", inf->attr_loc.file
			, inf->attr_loc.line&0x7FFFFFFF, inf->attr_loc.col);
	SANI_ABORT();
}

void __ubsan_handle_shift_out_of_bounds(void *data, void *lval, void *rval)
{
	struct
	{
		src_loc loc;
		type_desc *ltype, *rtype;
	} *inf = data;
	const unsigned lbits = UB_BITS(inf->ltype);
	char lstr[24], rstr[24];

	if (ub_skip(&inf->loc))
		return;
	ub_val2str(lstr, sizeof(lstr), inf->ltype, lval);
	ub_val2str(rstr, sizeof(rstr), inf->rtype, rval);
	if (rstr[0] == '-')
		SANI_SHOW("shift exponent %s is neg\n", rstr);
	else if (UB_VAL(inf->rtype, rval) >= lbits)
		SANI_SHOW("shift exponent %s is too large for %ubit type %s\n", rstr, lbits, inf->ltype->name);
	else if (lstr[0] == '-')
		SANI_SHOW("left shift of neg value %s\n", lstr);
	else
		SANI_SHOW("left shift of %s by %s places can't be represented in type %s\n", lstr, rstr, inf->ltype->name);
	SANI_ABORT();
}

void __ubsan_handle_out_of_bounds(void *data, void *index)
{
	struct
	{
		src_loc loc;
		type_desc *type, *idx_type;
	} *inf = data;
	char str[24];

	if (ub_skip(&inf->loc))
		return;
	ub_val2str(str, sizeof(str), inf->idx_type, index);
	SANI_SHOW("index %s(type: %s) is out of range\n", str, inf->type->name);
	SANI_ABORT();
}

void __ubsan_handle_builtin_unreachable(src_loc *loc)
{
	if (ub_skip(loc))
		return;
	SANI_SHOW("calling __builtin_unreachable()\n");
	SANI_ABORT();
}

void __ubsan_handle_load_invalid_value(void *data, void *val)
{
	struct
	{
		src_loc loc;
		type_desc *type;
	} *inf = data;
	char str[24];

	if (ub_skip(&inf->loc))
		return;
	ub_val2str(str, sizeof(str), inf->type, val);
	SANI_SHOW("%s(type: %s) is not a valid load value\n", str, inf->type->name);
	SANI_ABORT();
}
