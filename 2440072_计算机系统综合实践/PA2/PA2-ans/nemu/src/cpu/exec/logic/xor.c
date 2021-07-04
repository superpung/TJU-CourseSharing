#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "xor-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "xor-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "xor-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */

make_helper_v(xor_i2a)
make_helper_v(xor_i2rm)
make_helper_v(xor_si2rm)
make_helper_v(xor_r2rm)
make_helper_v(xor_rm2r)
