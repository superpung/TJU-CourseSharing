#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "shl-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "shl-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "shl-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */
make_helper_v(shl_rm_1)
make_helper_v(shl_rm_cl)
make_helper_v(shl_rm_imm)
