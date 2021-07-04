#ifndef __COMMON_H__
#define __COMMON_H__

/* Uncomment these macros to enable corresponding functionality. */
//#define IA32_SEG
//#define IA32_PAGE
//#define IA32_INTR
//#define HAS_DEVICE

#ifndef __ASSEMBLER__
/* The following code will be included if the source file is a "*.c" file. */

#include "trap.h"

#include <stdint.h>
#include <sys/types.h>

typedef uint8_t bool;

#define true 1
#define false 0

#define NULL ((void *)0)

#include "debug.h"

#endif

#endif
