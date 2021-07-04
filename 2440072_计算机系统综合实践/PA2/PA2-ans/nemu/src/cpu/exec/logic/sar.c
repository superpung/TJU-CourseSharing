#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "sar-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "sar-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "sar-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */
make_helper_v(sar_rm_1)
make_helper_v(sar_rm_cl)
make_helper_v(sar_rm_imm)
