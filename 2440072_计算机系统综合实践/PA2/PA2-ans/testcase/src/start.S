#include "trap.h"

.globl _start
_start:
# Set up a stack for C code. After the kernel is 
# introduced, the following code will never be executed.
	movl $0, %ebp
	movl $((128 << 20) - 16), %esp		# keep the `bt' command happy
	call main

	HIT_GOOD_TRAP
