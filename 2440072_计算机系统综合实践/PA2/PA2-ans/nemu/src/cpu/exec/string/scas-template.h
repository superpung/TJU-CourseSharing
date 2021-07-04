#include "cpu/exec/template-start.h"

#define instr scas

make_helper(concat(scas_, SUFFIX)) {
	DATA_TYPE dest = REG(R_EAX);
	DATA_TYPE src = MEM_R(cpu.edi);;
	DATA_TYPE result = dest - src;

	update_eflags_pf_zf_sf((DATA_TYPE_S)result);
	cpu.eflags.CF = result > dest;
	cpu.eflags.OF = MSB((dest ^ src) & (dest ^ result));

	cpu.edi += (cpu.eflags.DF ? -DATA_BYTE : DATA_BYTE);

	print_asm("scas" str(SUFFIX) " %%es:(%%edi),%%%s", REG_NAME(R_EAX));
	return 1;
}

#include "cpu/exec/template-end.h"
