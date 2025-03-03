	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 2
	.globl	_create_philo                   ; -- Begin function create_philo
	.p2align	2
_create_philo:                          ; @create_philo
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	stur	w1, [x29, #-20]
	str	x2, [sp, #16]
	str	x3, [sp, #8]
	mov	x0, #48                         ; =0x30
	bl	_malloc
	str	x0, [sp]
	ldr	x9, [sp]
	mov	x8, #0                          ; =0x0
	subs	x8, x8, x9
	cset	w8, ne
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
	ldur	x9, [x29, #-16]
	mov	w8, #1                          ; =0x1
	str	w8, [x9, #24]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB0_5
LBB0_2:
	ldr	x8, [sp]
	add	x0, x8, #8
	ldur	x3, [x29, #-16]
	mov	x1, #0                          ; =0x0
	adrp	x2, _routine@GOTPAGE
	ldr	x2, [x2, _routine@GOTPAGEOFF]
	bl	_pthread_create
	mov	w8, #0                          ; =0x0
	subs	w8, w8, w0
	cset	w8, eq
	tbnz	w8, #0, LBB0_4
	b	LBB0_3
LBB0_3:
	ldur	x9, [x29, #-16]
	mov	w8, #1                          ; =0x1
	str	w8, [x9, #24]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB0_5
LBB0_4:
	ldur	w8, [x29, #-20]
	ldr	x9, [sp]
	str	w8, [x9]
	ldr	x8, [sp, #16]
	ldr	x9, [sp]
	str	x8, [x9, #16]
	ldr	x8, [sp, #8]
	ldr	x9, [sp]
	str	x8, [x9, #24]
	ldr	x8, [sp]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #32]
	ldr	x8, [sp]
	str	xzr, [x8, #40]
	ldr	x8, [sp]
	stur	x8, [x29, #-8]
	b	LBB0_5
LBB0_5:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_create_fork                    ; -- Begin function create_fork
	.p2align	2
_create_fork:                           ; @create_fork
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	str	x1, [sp, #24]
	str	x2, [sp, #16]
	mov	x0, #88                         ; =0x58
	bl	_malloc
	str	x0, [sp, #8]
	ldr	x9, [sp, #8]
	mov	x8, #0                          ; =0x0
	subs	x8, x8, x9
	cset	w8, ne
	tbnz	w8, #0, LBB1_2
	b	LBB1_1
LBB1_1:
	ldur	x9, [x29, #-16]
	mov	w8, #1                          ; =0x1
	str	w8, [x9, #24]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB1_5
LBB1_2:
	ldr	x8, [sp, #8]
	add	x0, x8, #16
	mov	x1, #0                          ; =0x0
	bl	_pthread_mutex_init
	mov	w8, #0                          ; =0x0
	subs	w8, w8, w0
	cset	w8, eq
	tbnz	w8, #0, LBB1_4
	b	LBB1_3
LBB1_3:
	ldur	x9, [x29, #-16]
	mov	w8, #1                          ; =0x1
	str	w8, [x9, #24]
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB1_5
LBB1_4:
	ldr	x8, [sp, #24]
	ldr	x9, [sp, #8]
	str	x8, [x9]
	ldr	x8, [sp, #16]
	ldr	x9, [sp, #8]
	str	x8, [x9, #8]
	ldr	x8, [sp, #8]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #80]
	ldr	x8, [sp, #8]
	ldr	x9, [sp, #24]
	str	x8, [x9, #40]
	ldr	x8, [sp, #8]
	ldr	x9, [sp, #16]
	str	x8, [x9, #32]
	ldr	x8, [sp, #8]
	stur	x8, [x29, #-8]
	b	LBB1_5
LBB1_5:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_create_table                   ; -- Begin function create_table
	.p2align	2
_create_table:                          ; @create_table
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-16]
	ldur	x0, [x29, #-16]
	mov	w1, #1                          ; =0x1
	mov	x3, #0                          ; =0x0
	str	x3, [sp, #16]                   ; 8-byte Folded Spill
	mov	x2, x3
	bl	_create_philo
	ldr	x8, [sp, #16]                   ; 8-byte Folded Reload
	stur	x0, [x29, #-24]
	ldur	x9, [x29, #-24]
	subs	x8, x8, x9
	cset	w8, ne
	tbnz	w8, #0, LBB2_2
	b	LBB2_1
LBB2_1:
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-8]
	b	LBB2_6
LBB2_2:
	ldur	x9, [x29, #-16]
	sub	x8, x29, #24
	str	x8, [x9, #32]
                                        ; kill: def $x8 killed $xzr
	str	xzr, [sp, #32]
	ldur	x8, [x29, #-16]
	ldr	x8, [x8, #32]
	ldr	x8, [x8]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	mov	w8, #1                          ; =0x1
	str	w8, [sp, #28]
	b	LBB2_3
LBB2_3:
	ldr	w8, [sp, #28]
	add	w8, w8, #1
	str	w8, [sp, #28]
	ldur	x9, [x29, #-16]
	ldr	w9, [x9]
	subs	w8, w8, w9
	cset	w8, hi
	tbnz	w8, #0, LBB2_5
	b	LBB2_4
LBB2_4:
	ldur	x0, [x29, #-16]
	ldr	w1, [sp, #28]
	ldur	x2, [x29, #-24]
	mov	x3, #0                          ; =0x0
	bl	_create_philo
	str	x0, [sp, #32]
	stur	xzr, [x29, #-8]
	b	LBB2_6
LBB2_5:
	ldur	x8, [x29, #-16]
	ldr	x8, [x8, #32]
	ldr	x8, [x8]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-16]
	ldr	x8, [x8, #32]
	stur	x8, [x29, #-8]
	b	LBB2_6
LBB2_6:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"\033[31mError.\n  Memory allocation failed.\n\033[0m"

l_.str.1:                               ; @.str.1
	.asciz	"\033[31mError.\n  Thread (on philosopher) creation failed.\n\033[0m"

l_.str.2:                               ; @.str.2
	.asciz	"\033[31mError.\n  Mutex (on fork) creation failed.\n\033[0m"

l_.str.3:                               ; @.str.3
	.asciz	"%p\n"

.subsections_via_symbols
