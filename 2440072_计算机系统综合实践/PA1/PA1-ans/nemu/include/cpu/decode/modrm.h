#ifndef __MODRM_H__
#define __MODRM_H__

#include "common.h"
#include "cpu/decode/operand.h"

/* See i386 manual for more details about instruction format. */

typedef union {
	struct {
		uint8_t R_M		:3;
		uint8_t reg		:3;
		uint8_t mod		:2;
	};
	struct {
		uint8_t dont_care	:3;
		uint8_t opcode		:3;
	};
	uint8_t val;
} ModR_M;

typedef union {
	struct {
		uint8_t base	:3;
		uint8_t index	:3;
		uint8_t ss		:2;
	};
	uint8_t val;
} SIB;

int load_addr(swaddr_t, ModR_M *, Operand *);
int read_ModR_M(swaddr_t, Operand *, Operand *);

#define MODRM_ASM_BUF_SIZE 32
extern char ModR_M_asm[];

#endif
