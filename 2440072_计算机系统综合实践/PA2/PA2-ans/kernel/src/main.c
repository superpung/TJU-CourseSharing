#include "common.h"
#include "memory.h"

void init_page();
void init_serial();
void init_ide();
void init_i8259();
void init_segment();
void init_idt();
void init_mm();
uint32_t loader();

void video_mapping_write_test();
void video_mapping_read_test();
void video_mapping_clear();

void init_cond();

/* Initialization phase 1
 * The assembly code in start.S will finally jump here.
 */
void init() {
#ifdef IA32_PAGE
	/* We must set up kernel virtual memory first because our kernel thinks it 
	 * is located at 0xc0100000, which is set by the linking options in Makefile.
	 * Before setting up correct paging, no global variable can be used. */
	init_page();

	/* After paging is enabled, transform %esp to virtual address. */
	asm volatile("addl %0, %%esp" : : "i"(KOFFSET));
#endif

	/* Jump to init_cond() to continue initialization. */
	asm volatile("jmp *%0" : : "r"(init_cond));

	panic("should not reach here");
}

/* Initialization phase 2 */
void init_cond() {
#ifdef IA32_INTR
	/* Reset the GDT, since the old GDT in start.S cannot be used in the future. */
	init_segment();

	/* Set the IDT by setting up interrupt and exception handlers.
	 * Note that system call is the only exception implemented in NEMU.
	 */
	init_idt();
#endif

#ifdef HAS_DEVICE
	/* Initialize the intel 8259 PIC (Programmable interrupt controller). */
	init_i8259();

	/* Initialize the serial port. After that, you can use printk() to output messages. */
	init_serial();

	/* Initialize the IDE driver. */
	init_ide();

	/* Enable interrupts. */
	sti();
#endif

#ifdef IA32_PAGE
	/* Initialize the memory manager. */
	init_mm();
#endif

	/* Output a welcome message.
	 * Note that the output is actually performed only when
	 * the serial port is available in NEMU.
	 */
	Log("Hello, NEMU world!");

#if defined(IA32_PAGE) && defined(HAS_DEVICE)
	/* Write some test data to the video memory. */
	video_mapping_write_test();
#endif

	/* Load the program. */
	uint32_t eip = loader();
	
#if defined(IA32_PAGE) && defined(HAS_DEVICE)
	/* Read data in the video memory to check whether 
	 * the test data is written sucessfully.
	 */
	video_mapping_read_test();

	/* Clear the test data we just written in the video memory. */
	video_mapping_clear();
#endif

#ifdef IA32_PAGE
	/* Set the %esp for user program, which is one of the
	 * convention of the "advanced" runtime environment. */
	asm volatile("movl %0, %%esp" : : "i"(KOFFSET));
#endif

	/* Keep the `bt' command happy. */
	asm volatile("movl $0, %ebp");
	asm volatile("subl $16, %esp");

	/* Here we go! */
	((void(*)(void))eip)();

	HIT_GOOD_TRAP;

	panic("should not reach here");
}

