#include "cpu/exec/template-start.h"

#if DATA_BYTE == 2 || DATA_BYTE  == 4
make_helper(concat(movzb_, SUFFIX)) {
	int len = decode_rm2r_b(eip + 1);
	REG(op_dest->reg) = op_src->val;

	print_asm("movzb" str(SUFFIX) " %s,%%%s", op_src->str, REG_NAME(op_dest->reg));
	return len + 1;
}

make_helper(concat(movsb_, SUFFIX)) {
	int len = decode_rm2r_b(eip + 1);
	REG(op_dest->reg) = (int8_t)op_src->val;

	print_asm("movsb" str(SUFFIX) " %s,%%%s", op_src->str, REG_NAME(op_dest->reg));
	return len + 1;
}
#endif

#if DATA_BYTE  == 4
make_helper(concat(movzw_, SUFFIX)) {
	int len = decode_rm2r_w(eip + 1);
	REG(op_dest->reg) = op_src->val;

	print_asm("movzw" str(SUFFIX) " %s,%%%s", op_src->str, REG_NAME(op_dest->reg));
	return len + 1;
}

make_helper(concat(movsw_, SUFFIX)) {
	int len = decode_rm2r_w(eip + 1);
	REG(op_dest->reg) = (int16_t)op_src->val;

	print_asm("movsw" str(SUFFIX) " %s,%%%s", op_src->str, REG_NAME(op_dest->reg));
	return len + 1;
}
#endif

#include "cpu/exec/template-end.h"
