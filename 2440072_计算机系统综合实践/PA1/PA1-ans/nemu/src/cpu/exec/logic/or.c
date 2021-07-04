#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "or-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "or-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "or-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */

make_helper_v(or_i2a)
make_helper_v(or_i2rm)
make_helper_v(or_si2rm)
make_helper_v(or_r2rm)
make_helper_v(or_rm2r)
