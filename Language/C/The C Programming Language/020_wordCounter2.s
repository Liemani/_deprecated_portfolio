	.file	"020_wordCounter2.c"
	.section	.rodata
.LC0:
	.string	"Word Count: %d \n"
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
	movb	$0, -9(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L2
.L5:
	cmpl	$32, -4(%rbp)
	je	.L3
	cmpl	$10, -4(%rbp)
	je	.L3
	cmpl	$9, -4(%rbp)
	jne	.L4
.L3:
	movb	$0, -9(%rbp)
	jmp	.L2
.L4:
	cmpb	$0, -9(%rbp)
	jne	.L2
	movb	$1, -9(%rbp)
	addl	$1, -8(%rbp)
.L2:
	call	getchar
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L5
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
