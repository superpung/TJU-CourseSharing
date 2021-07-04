#ifndef __I8259_H__
#define __I8259_H__

#include "common.h"

void i8259_raise_intr(int);
uint8_t i8259_query_intr();
void i8259_ack_intr();
void do_i8259();

#endif
