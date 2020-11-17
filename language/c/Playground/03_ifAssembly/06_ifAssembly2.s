	.file	"06_ifAssembly2.c"
	.text
	.globl	isSpace
	.type	isSpace, @function
isSpace:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %eax
	movb	%al, -4(%rbp)
	cmpb	$32, -4(%rbp)
	je	.L2
	cmpb	$9, -4(%rbp)
	je	.L2
	cmpb	$10, -4(%rbp)
	jne	.L3
.L2:
	movl	$1, %eax
	jmp	.L4
.L3:
	movl	$0, %eax
.L4:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	isSpace, .-isSpace
	.section	.rodata
.LC0:
	.string	"Word Count: %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movb	$0, -9(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L7
.L9:
	cmpb	$0, -9(%rbp)
	jne	.L8
	movl	-4(%rbp), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	isSpace
	testb	%al, %al
	jne	.L8
	movb	$1, -9(%rbp)
	jmp	.L7
.L8:
	cmpb	$0, -9(%rbp)
	je	.L7
	movl	-4(%rbp), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	isSpace
	testb	%al, %al
	je	.L7
	addl	$1, -8(%rbp)
	movb	$0, -9(%rbp)
.L7:
	call	getchar
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L9
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
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
