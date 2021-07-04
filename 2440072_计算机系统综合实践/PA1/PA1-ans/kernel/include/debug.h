#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "common.h"
#include "x86.h"

#define KERNEL_LABEL " {kernel} "

void printk(const char *, ...);

#define Log(format, ...) \
	printk("\33[1;35m[%s,%d,%s]" KERNEL_LABEL format "\33[0m\n", \
			__FILE__, __LINE__, __func__, ## __VA_ARGS__)

#define panic(format, ...) \
do { \
	Log("\33[1;31msystem panic: " format, ## __VA_ARGS__); \
	HIT_BAD_TRAP; \
} while(0)

#define assert(cond) \
do { \
	if(!(cond)) { \
		panic("Assertion failed: %s", #cond); \
	} \
} while(0)
		

#endif
