#include "cpu/exec/helper.h"

#define make_setcc_helper(cc) \
	make_helper(concat(set, cc)) { \
		int len = decode_rm_b(eip + 1); \
		write_operand_b(op_src, concat(check_cc_, cc)()); \
		print_asm(str(concat(set, cc)) " %s", op_src->str); \
		return len + 1; \
	}

make_setcc_helper(ne)
