	.file	"factorial_recursion_with_O3.cpp"
	.text
	.p2align 4
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2386:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.p2align 4
	.globl	_Z6factTRjj
	.def	_Z6factTRjj;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6factTRjj
_Z6factTRjj:
.LFB1860:
	.seh_endprologue
	movl	%edx, %eax
	cmpl	$1, %ecx
	je	.L7
	.p2align 4,,10
	.p2align 3
.L4:
	imull	%ecx, %eax
	subl	$1, %ecx
	cmpl	$1, %ecx
	jne	.L4
.L7:
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1861:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$6, %edx
	call	_ZNSo9_M_insertImEERSoT_
	xorl	%eax, %eax
	addq	$40, %rsp
	ret
	.seh_endproc
	.p2align 4
	.def	_GLOBAL__sub_I__Z6factTRjj;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z6factTRjj
_GLOBAL__sub_I__Z6factTRjj:
.LFB2387:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	addq	$40, %rsp
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__Z6factTRjj
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders) 12.0.0 20211205 (experimental)"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSo9_M_insertImEERSoT_;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
