#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "imul-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "imul-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "imul-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */

make_helper_v(imul_rm2a)
make_helper_v(imul_rm2r)
make_helper_v(imul_si_rm2r)
make_helper_v(imul_i_rm2r)
