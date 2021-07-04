#include "cpu/exec/template-start.h"

#define instr push

static void do_execute() {
	swaddr_write(cpu.esp - 4, 4, op_src->val);
	cpu.esp -= 4;
	print_asm_template1();
}

#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(r)
make_instr_helper(rm)
#endif

#if DATA_BYTE == 1
make_instr_helper(si)
#endif

#include "cpu/exec/template-end.h"
