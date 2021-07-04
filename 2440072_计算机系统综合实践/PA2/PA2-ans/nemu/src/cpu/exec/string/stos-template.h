#include "cpu/exec/template-start.h"

#define instr stos

make_helper(concat(stos_, SUFFIX)) {
	MEM_W(cpu.edi, REG(R_EAX));
	cpu.edi += (cpu.eflags.DF ? -DATA_BYTE : DATA_BYTE);

	print_asm("stos" str(SUFFIX) " %%%s,%%es:(%%edi)", REG_NAME(R_EAX));
	return 1;
}

#include "cpu/exec/template-end.h"
