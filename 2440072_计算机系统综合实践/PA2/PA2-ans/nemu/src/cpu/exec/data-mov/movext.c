#include "cpu/exec/helper.h"

#define DATA_BYTE 2
#include "movext-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "movext-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */

make_helper_v(movzb)
make_helper_v(movsb)
