#include "cpu/exec/helper.h"

#define DATA_BYTE 2
#include "cltd-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "cltd-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */

make_helper_v(cltd)
make_helper_v(cwtl)
