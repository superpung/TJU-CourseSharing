#include "device/i8259.h"
#include "monitor/monitor.h"

#define TIMER_IRQ 0

void timer_intr() {
	if(nemu_state == RUNNING) {
		i8259_raise_intr(TIMER_IRQ);
	}
}

void init_timer() {
}
