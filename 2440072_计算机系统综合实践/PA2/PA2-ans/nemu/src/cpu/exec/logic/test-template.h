#include "cpu/exec/template-start.h"

#define instr test

static void do_execute () {
	DATA_TYPE result = op_dest->val & op_src->val;

	update_eflags_pf_zf_sf((DATA_TYPE_S)result);
	cpu.eflags.CF = cpu.eflags.OF = 0;

	print_asm_template2();
}

make_instr_helper(i2rm)
make_instr_helper(r2rm)

#include "cpu/exec/template-end.h"
