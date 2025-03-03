	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 2
	.globl	_ft_atoui                       ; -- Begin function ft_atoui
	.p2align	2
_ft_atoui:                              ; @ft_atoui
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #24]
	str	x1, [sp, #16]
	str	wzr, [sp, #12]
	b	LBB0_1
LBB0_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #24]
	ldrsb	w8, [x8]
	subs	w8, w8, #0
	cset	w8, eq
	mov	w9, #0                          ; =0x0
	str	w9, [sp, #8]                    ; 4-byte Folded Spill
	tbnz	w8, #0, LBB0_3
	b	LBB0_2
LBB0_2:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	x8, [sp, #24]
	ldrsb	w8, [x8]
	subs	w8, w8, #32
	cset	w8, lt
	str	w8, [sp, #8]                    ; 4-byte Folded Spill
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	w8, [sp, #8]                    ; 4-byte Folded Reload
	tbz	w8, #0, LBB0_5
	b	LBB0_4
LBB0_4:                                 ;   in Loop: Header=BB0_1 Depth=1
	ldr	x8, [sp, #24]
	add	x8, x8, #1
	str	x8, [sp, #24]
	b	LBB0_1
LBB0_5:
	b	LBB0_6
LBB0_6:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #24]
	ldrb	w8, [x8]
	subs	w8, w8, #0
	cset	w8, eq
	tbnz	w8, #0, LBB0_13
	b	LBB0_7
LBB0_7:                                 ;   in Loop: Header=BB0_6 Depth=1
	ldr	x8, [sp, #24]
	ldrsb	w8, [x8]
	subs	w8, w8, #48
	cset	w8, le
	tbnz	w8, #0, LBB0_9
	b	LBB0_8
LBB0_8:                                 ;   in Loop: Header=BB0_6 Depth=1
	ldr	x8, [sp, #24]
	ldrsb	w8, [x8]
	subs	w8, w8, #57
	cset	w8, lt
	tbnz	w8, #0, LBB0_10
	b	LBB0_9
LBB0_9:
	ldr	x9, [sp, #16]
	mov	w8, #1                          ; =0x1
	str	w8, [x9]
	b	LBB0_13
LBB0_10:                                ;   in Loop: Header=BB0_6 Depth=1
	ldr	w8, [sp, #12]
	mov	w9, #10                         ; =0xa
	mul	w8, w8, w9
	ldr	x10, [sp, #24]
	ldrsb	w10, [x10]
	add	w8, w8, w10
	subs	w8, w8, #48
	sdiv	w8, w8, w9
	ldr	w9, [sp, #12]
	subs	w8, w8, w9
	cset	w8, eq
	tbnz	w8, #0, LBB0_12
	b	LBB0_11
LBB0_11:
	ldr	x9, [sp, #16]
	mov	w8, #1                          ; =0x1
	str	w8, [x9]
	b	LBB0_13
LBB0_12:                                ;   in Loop: Header=BB0_6 Depth=1
	ldr	w8, [sp, #12]
	mov	w9, #10                         ; =0xa
	mul	w8, w8, w9
	ldr	x9, [sp, #24]
	ldrsb	w9, [x9]
	add	w8, w8, w9
	subs	w8, w8, #48
	str	w8, [sp, #12]
	ldr	x8, [sp, #24]
	add	x8, x8, #1
	str	x8, [sp, #24]
	b	LBB0_6
LBB0_13:
	ldr	w0, [sp, #12]
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
