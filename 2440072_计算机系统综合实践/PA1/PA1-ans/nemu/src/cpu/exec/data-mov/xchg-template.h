#include "cpu/exec/template-start.h"

#define instr xchg

static void do_execute () {
	DATA_TYPE temp = op_src->val;
	OPERAND_W(op_src, op_dest->val);
	OPERAND_W(op_dest, temp);
	print_asm_template2();
}

#if DATA_BYTE == 2 || DATA_BYTE == 4
make_helper(concat(xchg_a2r_, SUFFIX)) {
	concat(decode_r_, SUFFIX)(eip);
	op_dest->type = OP_TYPE_REG;
	op_dest->reg = R_EAX;
	op_dest->val = REG(R_EAX);
	snprintf(op_dest->str, OP_STR_SIZE, "%s", REG_NAME(R_EAX));
	do_execute();
	return 1;
}
#endif

make_instr_helper(r2rm);

#include "cpu/exec/template-end.h"
