#include "cpu/exec/helper.h"


#define DATA_BYTE 2
#include "adc-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "adc-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */


make_helper_v(adc_r2rm)
