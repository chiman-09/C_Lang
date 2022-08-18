	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	$10, -8(%rbp)
	movl	$19, -12(%rbp)
	movl	$2, -16(%rbp)
	movl	$4, -20(%rbp)
	cvtsi2ssl	-16(%rbp), %xmm0
	cvtsi2ssl	-20(%rbp), %xmm1
	divss	%xmm1, %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	L_.str(%rip), %rdi
	movb	$1, %al
	callq	_printf
	movl	-16(%rbp), %eax
	shll	$2, %eax
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %esi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-16(%rbp), %eax
	xorl	$-1, %eax
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %esi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_f1                             ## -- Begin function f1
	.p2align	4, 0x90
_f1:                                    ## @f1
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	$200, -4(%rbp)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_f2                             ## -- Begin function f2
	.p2align	4, 0x90
_f2:                                    ## @f2
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	$200, -12(%rbp)
	leaq	-12(%rbp), %rax
	movq	%rax, -8(%rbp)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_f3                             ## -- Begin function f3
	.p2align	4, 0x90
_f3:                                    ## @f3
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	$200, -12(%rbp)
	movl	-12(%rbp), %ecx
	movq	-8(%rbp), %rax
	movl	%ecx, (%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%f"

L_.str.1:                               ## @.str.1
	.asciz	"\n%d"

.subsections_via_symbols
