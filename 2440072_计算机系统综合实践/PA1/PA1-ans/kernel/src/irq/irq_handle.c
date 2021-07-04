#include "irq.h"

#define NR_IRQ_HANDLE 32

/* There are no more than 16(actually, 3) kinds of hardward interrupts. */
#define NR_HARD_INTR 16

struct IRQ_t {
	void (*routine)(void);
	struct IRQ_t *next;
};

static struct IRQ_t handle_pool[NR_IRQ_HANDLE];
static struct IRQ_t *handles[NR_HARD_INTR];
static int handle_count = 0;

void do_syscall(TrapFrame *);

void
add_irq_handle(int irq, void (*func)(void) ) {
	assert(irq < NR_HARD_INTR);
	assert(handle_count <= NR_IRQ_HANDLE);

	struct IRQ_t *ptr;
	ptr = &handle_pool[handle_count ++]; /* get a free handler */
	ptr->routine = func;
	ptr->next = handles[irq]; /* insert into the linked list */
	handles[irq] = ptr;
}

void irq_handle(TrapFrame *tf) {
	/* TODO: Re-organize the `TrapFrame' structure in `include/irq.h'
	 * to match the trap frame built during `do_irq.S'. Remove the
	 * following line after you are done.
	 */
	panic("Have you re-organized the `TrapFrame' structure?");

	int irq = tf->irq;

	if (irq < 0) {
		panic("Unhandled exception!");
	} else if (irq == 0x80) {
		do_syscall(tf);
	} else if (irq < 1000) {
		panic("Unexpected exception #%d at eip = %x", irq, tf->eip);
	} else if (irq >= 1000) {
		int irq_id = irq - 1000;
		assert(irq_id < NR_HARD_INTR);
		struct IRQ_t *f = handles[irq_id];

		while (f != NULL) { /* call handlers one by one */
			f->routine(); 
			f = f->next;
		}
	}
}

