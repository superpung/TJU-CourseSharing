#include "common.h"
#ifdef HAS_DEVICE

void init_serial();
void init_timer();
void init_vga();
void init_i8042();
void init_ide();

void init_device() {
	init_serial();
	init_timer();
	init_vga();
	init_i8042();
	init_ide();
}

#endif
