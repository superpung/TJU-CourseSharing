#include "cpu/exec/template-start.h"

#define instr shrd

#if DATA_BYTE == 2 || DATA_BYTE == 4
static void do_execute () {
	DATA_TYPE in = op_dest->val;
	DATA_TYPE out = op_src2->val;

	uint8_t count = op_src->val;
	count &= 0x1f;
	while(count != 0) {
		out >>= 1;
		out |= (in & 1) << ((DATA_BYTE << 3) - 1);
		in >>= 1;
		count --;
	}

	OPERAND_W(op_src2, out);

	print_asm("shrd" str(SUFFIX) " %s,%s,%s", op_src->str, op_dest->str, op_src2->str);
}

make_helper(concat(shrdi_, SUFFIX)) {
	int len = concat(decode_si_rm2r_, SUFFIX) (eip + 1);  /* use decode_si_rm2r to read 1 byte immediate */
	op_dest->val = REG(op_dest->reg);
	do_execute();
	return len + 1;
}
#endif

#include "cpu/exec/template-end.h"
