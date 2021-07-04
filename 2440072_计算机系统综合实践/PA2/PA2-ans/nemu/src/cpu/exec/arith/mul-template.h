#include "cpu/exec/template-start.h"

#define instr mul

static void do_execute() {
	uint64_t src = op_src->val;
	uint64_t result = REG(R_EAX) * src;
#if DATA_BYTE == 1
	reg_w(R_AX) = result;
#elif DATA_BYTE == 2
	REG(R_EAX) = result & 0xffff;
	REG(R_EDX) = result >> 16;
#else
	REG(R_EAX) = result & 0xffffffff;
	REG(R_EDX) = result >> 32;
#endif

	/* There is no need to update EFLAGS, since no other instructions 
	 * in PA will test the flags updated by this instruction.
	 */

	print_asm_template1();
}

make_instr_helper(rm)

#include "cpu/exec/template-end.h"
