#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "common.h"
#include "x86.h"

#define GAME_LABEL " {game} "

#define Log(format, ...) \
	printf("\33[1;35m[%s,%d,%s]" GAME_LABEL format "\33[0m\n", \
			__FILE__, __LINE__, __func__, ## __VA_ARGS__)

#define panic(format, ...) \
do { \
	cli(); \
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
