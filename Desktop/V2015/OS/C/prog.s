	.section	__TEXT,__text,regular,pure_instructions
	.globl	_writeloop
	.align	4, 0x90
_writeloop:                             ## @writeloop
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp2:
	.cfi_def_cfa_offset 16
Ltmp3:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp4:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -16(%rbp)
	movq	$0, -24(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$30, _g_ant(%rip)
	jge	LBB0_5
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movabsq	$1000000, %rax          ## imm = 0xF4240
	movq	-24(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -24(%rbp)
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	movq	%rcx, %rax
	cqto
	movq	-32(%rbp), %rcx         ## 8-byte Reload
	idivq	%rcx
	cmpq	$0, %rdx
	jne	LBB0_4
## BB#3:                                ##   in Loop: Header=BB0_1 Depth=1
	leaq	L_.str(%rip), %rdi
	movq	-16(%rbp), %rsi
	movl	_g_ant(%rip), %eax
	addl	$1, %eax
	movl	%eax, _g_ant(%rip)
	movl	%eax, %edx
	movb	$0, %al
	callq	_printf
	movl	%eax, -36(%rbp)         ## 4-byte Spill
LBB0_4:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_1
LBB0_5:
	movl	$0, %edi
	callq	_exit
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp7:
	.cfi_def_cfa_offset 16
Ltmp8:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp9:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	leaq	-16(%rbp), %rdi
	movabsq	$0, %rsi
	leaq	_writeloop(%rip), %rdx
	leaq	L_.str1(%rip), %rcx
	movl	$0, -4(%rbp)
	callq	_pthread_create
	leaq	L_.str2(%rip), %rdi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	callq	_writeloop
	movabsq	$0, %rsi
	movq	-16(%rbp), %rdi
	movq	%rax, -32(%rbp)         ## 8-byte Spill
	callq	_pthread_join
	movl	$0, %r8d
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	movl	%r8d, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_g_ant                  ## @g_ant
.zerofill __DATA,__common,_g_ant,4,2
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%s: %d\n"

L_.str1:                                ## @.str1
	.asciz	"2nd thread"

L_.str2:                                ## @.str2
	.asciz	"1st thread"


.subsections_via_symbols
