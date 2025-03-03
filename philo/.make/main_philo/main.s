	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 2
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #80
	stp	x29, x30, [sp, #64]             ; 16-byte Folded Spill
	add	x29, sp, #64
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	stur	w0, [x29, #-8]
	stur	x1, [x29, #-16]
	ldur	w9, [x29, #-8]
	mov	w8, #5                          ; =0x5
	subs	w8, w8, w9
	cset	w8, eq
	tbnz	w8, #0, LBB0_3
	b	LBB0_1
LBB0_1:
	ldur	w9, [x29, #-8]
	mov	w8, #6                          ; =0x6
	subs	w8, w8, w9
	cset	w8, eq
	tbnz	w8, #0, LBB0_3
	b	LBB0_2
LBB0_2:
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	mov	w8, #1                          ; =0x1
	stur	w8, [x29, #-4]
	b	LBB0_6
LBB0_3:
	ldur	w0, [x29, #-8]
	ldur	x1, [x29, #-16]
	add	x2, sp, #8
	bl	__init_philo
	ldr	w9, [sp, #32]
	mov	w8, #1                          ; =0x1
	subs	w8, w8, w9
	cset	w8, ne
	tbnz	w8, #0, LBB0_5
	b	LBB0_4
LBB0_4:
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	mov	w8, #1                          ; =0x1
	stur	w8, [x29, #-4]
	b	LBB0_6
LBB0_5:
	ldr	w8, [sp, #32]
	stur	w8, [x29, #-4]
	b	LBB0_6
LBB0_6:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #64]             ; 16-byte Folded Reload
	add	sp, sp, #80
	ret
	.cfi_endproc
                                        ; -- End function
	.p2align	2                               ; -- Begin function _init_philo
__init_philo:                           ; @_init_philo
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	w0, [x29, #-4]
	str	x1, [sp, #16]
	str	x2, [sp, #8]
	ldr	x8, [sp, #8]
	str	wzr, [x8, #24]
	ldr	x8, [sp, #16]
	ldr	x0, [x8, #8]
	ldr	x8, [sp, #8]
	add	x1, x8, #24
	bl	_ft_atoui
	ldr	x8, [sp, #8]
	str	w0, [x8]
	ldr	x8, [sp, #16]
	ldr	x0, [x8, #16]
	ldr	x8, [sp, #8]
	add	x1, x8, #24
	bl	_ft_atoui
	ldr	x8, [sp, #8]
	str	w0, [x8, #4]
	ldr	x8, [sp, #16]
	ldr	x0, [x8, #24]
	ldr	x8, [sp, #8]
	add	x1, x8, #24
	bl	_ft_atoui
	ldr	x8, [sp, #8]
	str	w0, [x8, #8]
	ldr	x8, [sp, #16]
	ldr	x0, [x8, #32]
	ldr	x8, [sp, #8]
	add	x1, x8, #24
	bl	_ft_atoui
	ldr	x8, [sp, #8]
	str	w0, [x8, #12]
	ldr	x9, [sp, #8]
	mov	w8, #1                          ; =0x1
	strb	w8, [x9, #20]
	ldr	x8, [sp, #8]
	str	wzr, [x8, #16]
	ldr	x8, [sp, #8]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #32]
	ldur	w8, [x29, #-4]
	subs	w8, w8, #6
	cset	w8, ne
	tbnz	w8, #0, LBB1_2
	b	LBB1_1
LBB1_1:
	ldr	x8, [sp, #8]
	strb	wzr, [x8, #20]
	b	LBB1_2
LBB1_2:
	ldur	w8, [x29, #-4]
	subs	w8, w8, #6
	cset	w8, ne
	tbnz	w8, #0, LBB1_4
	b	LBB1_3
LBB1_3:
	ldr	x8, [sp, #16]
	ldr	x0, [x8, #40]
	ldr	x8, [sp, #8]
	add	x1, x8, #24
	bl	_ft_atoui
	ldr	x8, [sp, #8]
	str	w0, [x8, #16]
	b	LBB1_4
LBB1_4:
	ldr	x0, [sp, #8]
	bl	_create_table
	mov	x8, #0                          ; =0x0
	subs	x8, x8, x0
	cset	w8, ne
	tbnz	w8, #0, LBB1_6
	b	LBB1_5
LBB1_5:
	b	LBB1_6
LBB1_6:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_terminate                      ; -- Begin function terminate
	.p2align	2
_terminate:                             ; @terminate
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	x0, [sp, #8]
	str	w1, [sp, #4]
	ldr	w8, [sp, #4]
	ldr	x9, [sp, #8]
	str	w8, [x9]
	ldr	x8, [sp, #8]
	ldr	w0, [x8]
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"\033[31mError.\n  4 or 5 arguments are expected:\n"

l_.str.1:                               ; @.str.1
	.asciz	"  ./philo nb_philo t_die t_eat t_sleep [nb_meals]\n\033[0m"

l_.str.2:                               ; @.str.2
	.asciz	"\033[31mError.\n  Unsigned int are expected.\n\033[0m"

.subsections_via_symbols
