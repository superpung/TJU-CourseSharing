#include "cpu/exec/template-start.h"

#if DATA_BYTE == 2 || DATA_BYTE == 4
make_helper(concat(cltd_, SUFFIX)) {
	REG(R_EDX) = -(MSB(REG(R_EAX)));

	print_asm("cltd" str(SUFFIX));
	return 1;
}

make_helper(concat(cwtl_, SUFFIX)) {
#if DATA_BYTE == 2
	reg_w(R_AX) = (int8_t)reg_b(R_AL);
#else
	reg_l(R_EAX) = (int16_t)reg_w(R_AX);
#endif

	print_asm("cwtl" str(SUFFIX));
	return 1;
}
#endif

#include "cpu/exec/template-end.h"
