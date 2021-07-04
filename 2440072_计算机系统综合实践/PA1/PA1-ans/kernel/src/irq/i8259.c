#include "x86.h"

#define PORT_PIC_MASTER 0x20
#define PORT_PIC_SLAVE  0xA0
#define IRQ_SLAVE       2

void init_i8259(void) {
	/* mask all interrupts */
	out_byte(PORT_PIC_MASTER + 1, 0xFF);
	out_byte(PORT_PIC_SLAVE + 1 , 0xFF);
	
	/* start initialization */
	out_byte(PORT_PIC_MASTER, 0x11);
	out_byte(PORT_PIC_MASTER + 1, 32);
	out_byte(PORT_PIC_MASTER + 1, 1 << 2);
	out_byte(PORT_PIC_MASTER + 1, 0x3);
	out_byte(PORT_PIC_SLAVE, 0x11);
	out_byte(PORT_PIC_SLAVE + 1, 32 + 8);
	out_byte(PORT_PIC_SLAVE + 1, 2);
	out_byte(PORT_PIC_SLAVE + 1, 0x3);
	out_byte(PORT_PIC_MASTER, 0x68);
	out_byte(PORT_PIC_MASTER, 0x0A);
	out_byte(PORT_PIC_SLAVE, 0x68);
	out_byte(PORT_PIC_SLAVE, 0x0A);
}
