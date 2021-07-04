#ifndef __X86_CPU_H__
#define __X86_CPU_H__

#include <stdint.h>
#include "x86-inc/cpu.h"

/* read CR0 */
static inline uint32_t
read_cr0() {
	uint32_t val;
	asm volatile("movl %%cr0, %0" : "=r"(val));
	return val;
}

/* write CR0 */
static inline void
write_cr0(uint32_t cr0) {
	asm volatile("movl %0, %%cr0" : : "r"(cr0));
}

/* write CR3, notice that CR3 is never read */
static inline void
write_cr3(uint32_t cr3) {
	asm volatile("movl %0, %%cr3" : : "r"(cr3));
}

/* modify the value of GDTR */
static inline void
write_gdtr(void *addr, uint32_t size) {
	static volatile uint16_t data[3];
	data[0] = size - 1;
	data[1] = (uint32_t)addr;
	data[2] = ((uint32_t)addr) >> 16;
	asm volatile("lgdt (%0)" : : "r"(data));
}

/* modify the value of IDTR */
static inline void
write_idtr(void *addr, uint32_t size) {
	static volatile uint16_t data[3];
	data[0] = size - 1;
	data[1] = (uint32_t)addr;
	data[2] = ((uint32_t)addr) >> 16;
	asm volatile("lidt (%0)" : : "r"(data));
}

/* enable interrupt */
static inline void
sti(void) {
	asm volatile("sti");
}

/* disable interrupt */
static inline void
cli(void) {
	asm volatile("cli");
}

/* put the CPU into idle, waiting for the next interrupt */
static inline void
wait_intr() {
	asm volatile("hlt");
}

#define NR_IRQ    256

#endif
