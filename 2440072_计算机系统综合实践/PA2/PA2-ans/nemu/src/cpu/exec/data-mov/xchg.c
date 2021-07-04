#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "xchg-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "xchg-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "xchg-template.h"
#undef DATA_BYTE


/* for instruction encoding overloading */

make_helper_v(xchg_a2r)
make_helper_v(xchg_r2rm)
