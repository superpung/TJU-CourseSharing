#include "nemu.h"
#include <stdlib.h>
#include <time.h>

CPU_state cpu;

const char *regsl[] = {"eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"};
const char *regsw[] = {"ax", "cx", "dx", "bx", "sp", "bp", "si", "di"};
const char *regsb[] = {"al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"};

void reg_test() {
	srand(time(0));
	uint32_t sample[8];
	uint32_t eip_sample = rand();
	cpu.eip = eip_sample;

	int i;
	for(i = R_EAX; i <= R_EDI; i ++) {
		sample[i] = rand();
		reg_l(i) = sample[i];
		assert(reg_w(i) == (sample[i] & 0xffff));
	}

	assert(reg_b(R_AL) == (sample[R_EAX] & 0xff));
	assert(reg_b(R_AH) == ((sample[R_EAX] >> 8) & 0xff));
	assert(reg_b(R_BL) == (sample[R_EBX] & 0xff));
	assert(reg_b(R_BH) == ((sample[R_EBX] >> 8) & 0xff));
	assert(reg_b(R_CL) == (sample[R_ECX] & 0xff));
	assert(reg_b(R_CH) == ((sample[R_ECX] >> 8) & 0xff));
	assert(reg_b(R_DL) == (sample[R_EDX] & 0xff));
	assert(reg_b(R_DH) == ((sample[R_EDX] >> 8) & 0xff));

	assert(sample[R_EAX] == cpu.eax);
	assert(sample[R_ECX] == cpu.ecx);
	assert(sample[R_EDX] == cpu.edx);
	assert(sample[R_EBX] == cpu.ebx);
	assert(sample[R_ESP] == cpu.esp);
	assert(sample[R_EBP] == cpu.ebp);
	assert(sample[R_ESI] == cpu.esi);
	assert(sample[R_EDI] == cpu.edi);

	assert(eip_sample == cpu.eip);
}

/*TODO: Show register files*/
void display_reg() {
	int i;
	for(i = 0; i < 8; i ++) {
		printf("%s\t\t0x%08x\t\t%d\n", regsl[i], cpu.gpr[i]._32, cpu.gpr[i]._32);
	}

	printf("%s\t\t0x%08x\t\t%d\n", "eip", cpu.eip, cpu.eip);
}

/* TODO: Get the value of register */
uint32_t get_reg_val(const char *s, bool *success) {
	int i;
	*success = true;
	for(i = 0; i < 8; i ++) {
		if(strcmp(regsl[i], s) == 0) {
			return reg_l(i);
		}
	}

	for(i = 0; i < 8; i ++) {
		if(strcmp(regsw[i], s) == 0) {
			return reg_w(i);
		}
	}

	for(i = 0; i < 8; i ++) {
		if(strcmp(regsb[i], s) == 0) {
			return reg_b(i);
		}
	}

	if(strcmp("eip", s) == 0) {
		return cpu.eip;
	}

	*success = false;
	return 0;
}

