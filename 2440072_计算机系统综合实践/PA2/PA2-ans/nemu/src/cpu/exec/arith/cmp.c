#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "cmp-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "cmp-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "cmp-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */

make_helper_v(cmp_i2a)
make_helper_v(cmp_i2rm)
make_helper_v(cmp_si2rm)
make_helper_v(cmp_r2rm)
make_helper_v(cmp_rm2r)
