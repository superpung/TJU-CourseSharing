#include "game-common.h"
#include "x86.h"
#include "FLOAT.h"

#include <unistd.h>

void init_timer();
void main_loop();

void add_irq_handle(int irq, void *handler) {
	syscall(0, irq, handler);
}

int
main(void) {
	init_timer();

	add_irq_handle(0, timer_event);

	init_FLOAT_vfprintf();

	Log("game start!");

	main_loop();

	assert(0); /* main_loop是死循环，永远无法返回这里 */

	return 0;
}
