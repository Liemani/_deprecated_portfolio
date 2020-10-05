	.file	"03_ifTest2.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -8(%rbp)
	jmp	.L2
.L5:
	cmpl	$32, -4(%rbp)
	jne	.L3
	cmpl	$32, -8(%rbp)
	je	.L4
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	putchar
.L4:
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
.L2:
	call	getchar
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L5
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
