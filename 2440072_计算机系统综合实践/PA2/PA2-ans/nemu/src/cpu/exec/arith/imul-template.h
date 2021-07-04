#include "cpu/exec/template-start.h"

#if DATA_BYTE == 1
#define RET_DATA_TYPE int16_t
#elif DATA_BYTE == 2
#define RET_DATA_TYPE int32_t
#elif DATA_BYTE == 4
#define RET_DATA_TYPE int64_t
#endif

#define instr imul

#if DATA_BYTE == 2 || DATA_BYTE == 4
static void do_execute() {
	RET_DATA_TYPE result = (RET_DATA_TYPE)op_src->val * (RET_DATA_TYPE)op_src2->val;
	OPERAND_W(op_dest, result);

	/* There is no need to update EFLAGS, since no other instructions 
	 * in PA will test the flags updated by this instruction.
	 */

	print_asm_template3();
}

make_helper(concat(imul_rm2r_, SUFFIX)) {
	int len = concat(decode_rm2r_, SUFFIX)(eip + 1);
	ops_decoded.src2 = ops_decoded.dest;
	do_execute();
	return len + 1;
}

make_instr_helper(si_rm2r)
make_instr_helper(i_rm2r)
#endif

make_helper(concat(imul_rm2a_, SUFFIX)) {
	int len = concat(decode_rm_, SUFFIX)(eip + 1);
	int64_t src = (DATA_TYPE_S)op_src->val;
	int64_t result = (DATA_TYPE_S)REG(R_EAX) * src;
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
	return len + 1;
}

#undef RET_DATA_TYPE

#include "cpu/exec/template-end.h"
