#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "and-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "and-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "and-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */

make_helper_v(and_i2a)
make_helper_v(and_i2rm)
make_helper_v(and_si2rm)
make_helper_v(and_r2rm)
make_helper_v(and_rm2r)
