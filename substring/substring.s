	.file	"substring.cpp"
	.text
	.globl	_Z18substring_positionPKcS0_
	.type	_Z18substring_positionPKcS0_, @function
_Z18substring_positionPKcS0_:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -24(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L2
.L8:
	movq	-48(%rbp), %rax
	movzbl	(%rax), %edx
	movq	-40(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jne	.L3
	movq	-48(%rbp), %rax
	movq	%rax, -16(%rbp)
	addq	$1, -48(%rbp)
	addq	$1, -40(%rbp)
	addl	$1, -24(%rbp)
	jmp	.L4
.L3:
	movq	$0, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movzbl	(%rax), %edx
	movq	-48(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jne	.L5
	movq	-48(%rbp), %rax
	movq	%rax, -16(%rbp)
	addq	$1, -40(%rbp)
	movl	$1, -24(%rbp)
	jmp	.L6
.L5:
	movl	$0, -24(%rbp)
.L6:
	addq	$1, -48(%rbp)
.L4:
	addl	$1, -20(%rbp)
.L2:
	movq	-48(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L7
	movq	-40(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L8
.L7:
	movq	-40(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L9
	cmpq	$0, -16(%rbp)
	je	.L9
	movl	-20(%rbp), %eax
	subl	-24(%rbp), %eax
	jmp	.L10
.L9:
	movl	$-1, %eax
.L10:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	_Z18substring_positionPKcS0_, .-_Z18substring_positionPKcS0_
	.globl	_Z19substring_position2PKcS0_
	.type	_Z19substring_position2PKcS0_, @function
_Z19substring_position2PKcS0_:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strstr@PLT
	testq	%rax, %rax
	je	.L12
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strstr@PLT
	subq	-16(%rbp), %rax
	jmp	.L14
.L12:
	movl	$-1, %eax
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_Z19substring_position2PKcS0_, .-_Z19substring_position2PKcS0_
	.ident	"GCC: (Ubuntu 15.2.0-16ubuntu1) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
