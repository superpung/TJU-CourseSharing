#include "cpu/exec/helper.h"

make_helper(exec);

make_helper(operand_size) {
	ops_decoded.is_operand_size_16 = true;
	int instr_len = exec(eip + 1);
	ops_decoded.is_operand_size_16 = false;
	return instr_len + 1;
}
