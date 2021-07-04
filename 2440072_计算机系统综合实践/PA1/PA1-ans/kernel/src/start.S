#include "common.h"

#ifndef IA32_SEG

	.globl start
	start:
	# Set up a stack for C code.
		movl $0, %ebp
		movl $(128 << 20), %esp
		jmp init				# never return

#else

	# To understand macros here, see i386 manual.
	#define GDT_ENTRY(n) ((n) << 3)

	#define MAKE_NULL_SEG_DESC   \
		.word 0, 0;              \
		.byte 0, 0, 0, 0

	# The 0xC0 means the limit is in 4096-byte units
	# and (for executable segments) 32-bit mode.
	#define MAKE_SEG_DESC(type,base,lim)                        \
		.word (((lim) >> 12) & 0xffff), ((base) & 0xffff);      \
		.byte (((base) >> 16) & 0xff), (0x90 | (type)),         \
		(0xC0 | (((lim) >> 28) & 0xf)), (((base) >> 24) & 0xff)

	#ifdef IA32_PAGE
	#	define KOFFSET 0xc0000000
	#	define va_to_pa(x) (x - KOFFSET)
	#else
	#	define va_to_pa(x) (x)
	#endif

	.globl start
	start:
		lgdt    va_to_pa(gdtdesc) # See i386 manual for more information
		movl    %cr0, %eax        # %CR0 |= PROTECT_ENABLE_BIT
		orl     $0x1, %eax
		movl    %eax, %cr0

	# Complete transition to 32-bit protected mode by using long jmp
	# to reload %CS and %EIP.  The segment descriptors are set up with no
	# translation, so that the mapping is still the identity mapping.
		ljmp    $GDT_ENTRY(1), $va_to_pa(start_cond)

	start_cond:
	# Set up the protected-mode data segment registers
		movw    $GDT_ENTRY(2), %ax
		movw    %ax, %ds          # %DS = %AX
		movw    %ax, %es          # %ES = %AX
		movw    %ax, %ss          # %SS = %AX

	# Set up a stack for C code.
		movl $0, %ebp
		movl $(128 << 20), %esp
		jmp init				# never return

	# GDT
	.p2align 2                    # force 4 byte alignment
	gdt:
		MAKE_NULL_SEG_DESC                   # empty segment
		MAKE_SEG_DESC(0xA, 0x0, 0xffffffff)  # code
		MAKE_SEG_DESC(0x2, 0x0, 0xffffffff)  # data

	gdtdesc:                      # descriptor
		.word   (gdtdesc - gdt - 1)    # limit = sizeof(gdt) - 1
		.long   va_to_pa(gdt)          # address of GDT

# end of IA32_SEG
#endif
