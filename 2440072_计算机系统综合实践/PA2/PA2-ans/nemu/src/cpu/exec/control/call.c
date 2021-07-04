#include "cpu/exec/helper.h"

make_helper(call_si) {
	int len = decode_si_l(eip + 1);
	swaddr_t ret_addr = cpu.eip + len + 1;
	swaddr_write(cpu.esp - 4, 4, ret_addr);
	cpu.esp -= 4;

	cpu.eip += op_src->val;
	print_asm("call %x", cpu.eip + 1 + len);

	return len + 1;
}

make_helper(call_rm) {
	int len = decode_rm_l(eip + 1);
	swaddr_t ret_addr = cpu.eip + len + 1;
	swaddr_write(cpu.esp - 4, 4, ret_addr);
	cpu.esp -= 4;

	cpu.eip = op_src->val - (len + 1);
	print_asm("call *%s", op_src->str);

	return len + 1;
}

