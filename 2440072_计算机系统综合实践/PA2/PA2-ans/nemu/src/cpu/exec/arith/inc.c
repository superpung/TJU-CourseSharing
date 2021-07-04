#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "inc-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "inc-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "inc-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */

make_helper_v(inc_rm)
make_helper_v(inc_r)
