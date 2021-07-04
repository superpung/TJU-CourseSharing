#ifndef __EFLAGS_H__
#define __EFLAGS_H__

#include "common.h"

void update_eflags_pf_zf_sf(uint32_t);


static inline bool check_cc_b() {
	return cpu.eflags.CF;
}


static inline bool check_cc_e() {
	return cpu.eflags.ZF;
}

static inline bool check_cc_ne() {
	return !cpu.eflags.ZF;
}

static inline bool check_cc_be() {
	return cpu.eflags.CF | cpu.eflags.ZF;
}

static inline bool check_cc_a() {
	return !(cpu.eflags.CF | cpu.eflags.ZF);
}

static inline bool check_cc_s() {
	return cpu.eflags.SF;
}

static inline bool check_cc_ns() {
	return !cpu.eflags.SF;
}


static inline bool check_cc_l() {
	return cpu.eflags.SF ^ cpu.eflags.OF;
}

static inline bool check_cc_ge() {
	return !(cpu.eflags.SF ^ cpu.eflags.OF);
}

static inline bool check_cc_le() {
	return (cpu.eflags.SF ^ cpu.eflags.OF) | cpu.eflags.ZF;
}

static inline bool check_cc_g() {
	return !((cpu.eflags.SF ^ cpu.eflags.OF) | cpu.eflags.ZF);
}

#endif
