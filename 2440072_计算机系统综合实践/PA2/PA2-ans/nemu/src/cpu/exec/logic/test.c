#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "test-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "test-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "test-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */

make_helper_v(test_i2rm)
make_helper_v(test_r2rm)
