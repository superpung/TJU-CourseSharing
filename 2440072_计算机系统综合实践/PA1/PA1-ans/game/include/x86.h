#ifndef __X86_H__
#define __X86_H__

#include "common.h"

/* 读I/O端口 */
static inline uint8_t
in_byte(uint16_t port) {
	uint8_t data;
	asm volatile("in %1, %0" : "=a"(data) : "d"(port));
	return data;
}

/* 写I/O端口 */
static inline void
out_byte(uint16_t port, int8_t data) {
	asm volatile("out %%al, %%dx" : : "a"(data), "d"(port));
}

/* 打开外部中断 */
static inline void
sti(void) {
	asm volatile("sti");
}

/* 关闭外部中断 */
static inline void
cli(void) {
	asm volatile("cli");
}

/* 将CPU置入休眠状态直到下次中断到来 */
static inline void
wait_intr() {
	asm volatile("hlt");
}

#endif
