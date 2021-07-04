#include "common.h"
#include <stdio.h>

void serial_printc(char);

/* __attribute__((__noinline__))  here is to disable inlining for this function to avoid some optimization problems for gcc 4.7 */
void __attribute__((__noinline__)) 
printk(const char *ctl, ...) {
#ifndef HAS_DEVICE
	return;
#endif
	static char buf[256];
	void *args = (void **)&ctl + 1;
	int len = vsnprintf(buf, 256, ctl, args);
	int i;
	for(i = 0; i < len; i ++) {
		serial_printc(buf[i]);
	}
}
