#include "common.h"
#include "x86.h"

#define INTERRUPT_GATE_32   0xE
#define TRAP_GATE_32        0xF

/* Each entry of the IDT is either an interrupt gate, or a trap gate */
static GateDesc idt[NR_IRQ];

/* Setup a interrupt gate for interrupt handler. */
static void set_intr(GateDesc *ptr, uint32_t selector, uint32_t offset, uint32_t dpl) {
	ptr->offset_15_0 = offset & 0xFFFF;
	ptr->segment = selector;
	ptr->pad0 = 0;
	ptr->type = INTERRUPT_GATE_32;
	ptr->system = 0;
	ptr->privilege_level = dpl;
	ptr->present = 1;
	ptr->offset_31_16 = (offset >> 16) & 0xFFFF;
}

/* Setup a trap gate for cpu exception. */
static void set_trap(GateDesc *ptr, uint32_t selector, uint32_t offset, uint32_t dpl) {
	ptr->offset_15_0 = offset & 0xFFFF;
	ptr->segment = selector;
	ptr->pad0 = 0;
	ptr->type = TRAP_GATE_32;
	ptr->system = 0;
	ptr->privilege_level = dpl;
	ptr->present = 1;
	ptr->offset_31_16 = (offset >> 16) & 0xFFFF;
}

void irq0();
void irq1();
void irq14();
void vec0();
void vec1();
void vec2();
void vec3();
void vec4();
void vec5();
void vec6();
void vec7();
void vec8();
void vec9();
void vec10();
void vec11();
void vec12();
void vec13();
void vec14();
void vecsys();

void irq_empty();

void init_idt() {
	int i;
	for (i = 0; i < NR_IRQ; i ++) {
		set_trap(idt + i, SEG_KERNEL_CODE << 3, (uint32_t)irq_empty, DPL_KERNEL);
	}
	set_trap(idt + 0, SEG_KERNEL_CODE << 3, (uint32_t)vec0, DPL_KERNEL);
	set_trap(idt + 1, SEG_KERNEL_CODE << 3, (uint32_t)vec1, DPL_KERNEL);
	set_trap(idt + 2, SEG_KERNEL_CODE << 3, (uint32_t)vec2, DPL_KERNEL);
	set_trap(idt + 3, SEG_KERNEL_CODE << 3, (uint32_t)vec3, DPL_KERNEL);
	set_trap(idt + 4, SEG_KERNEL_CODE << 3, (uint32_t)vec4, DPL_KERNEL);
	set_trap(idt + 5, SEG_KERNEL_CODE << 3, (uint32_t)vec5, DPL_KERNEL);
	set_trap(idt + 6, SEG_KERNEL_CODE << 3, (uint32_t)vec6, DPL_KERNEL);
	set_trap(idt + 7, SEG_KERNEL_CODE << 3, (uint32_t)vec7, DPL_KERNEL);
	set_trap(idt + 8, SEG_KERNEL_CODE << 3, (uint32_t)vec8, DPL_KERNEL);
	set_trap(idt + 9, SEG_KERNEL_CODE << 3, (uint32_t)vec9, DPL_KERNEL);
	set_trap(idt + 10, SEG_KERNEL_CODE << 3, (uint32_t)vec10, DPL_KERNEL);
	set_trap(idt + 11, SEG_KERNEL_CODE << 3, (uint32_t)vec11, DPL_KERNEL);
	set_trap(idt + 12, SEG_KERNEL_CODE << 3, (uint32_t)vec12, DPL_KERNEL);
	set_trap(idt + 13, SEG_KERNEL_CODE << 3, (uint32_t)vec13, DPL_KERNEL);
	set_trap(idt + 14, SEG_KERNEL_CODE << 3, (uint32_t)vec14, DPL_KERNEL);

	/* the system call 0x80 */
	set_trap(idt + 0x80, SEG_KERNEL_CODE << 3, (uint32_t)vecsys, DPL_USER);

	set_intr(idt+32 + 0, SEG_KERNEL_CODE << 3, (uint32_t)irq0, DPL_KERNEL);
	set_intr(idt+32 + 14, SEG_KERNEL_CODE << 3, (uint32_t)irq14, DPL_KERNEL);

	/* the `idt' is its virtual address */
	write_idtr(idt, sizeof(idt));
}
