#ifndef __FLOAT_H__
#define __FLOAT_H__

#include "trap.h"

typedef int FLOAT;

static inline int F2int(FLOAT a) {
	nemu_assert(0);
	return 0;
}

static inline FLOAT int2F(int a) {
	nemu_assert(0);
	return 0;
}

static inline FLOAT F_mul_int(FLOAT a, int b) {
	nemu_assert(0);
	return 0;
}

static inline FLOAT F_div_int(FLOAT a, int b) {
	nemu_assert(0);
	return 0;
}

FLOAT f2F(float);
FLOAT F_mul_F(FLOAT, FLOAT);
FLOAT F_div_F(FLOAT, FLOAT);
FLOAT Fabs(FLOAT);
FLOAT sqrt(FLOAT);
FLOAT pow(FLOAT, FLOAT);

// used when calling printf/sprintf to format a FLOAT argument
#define FLOAT_ARG(f) (long long)f

void init_FLOAT_vfprintf(void);

#endif
