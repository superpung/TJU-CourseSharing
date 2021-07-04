#include "common.h"
#include "x86.h"

/* some ports */
#define VGA_DAC_READ_INDEX 0x3C7
#define VGA_DAC_WRITE_INDEX 0x3C8
#define VGA_DAC_DATA 0x3C9

/* The number of entries in the palette. */
#define NR_PALETTE_ENTRY 256

/* Load the palette into VGA. */
void write_palette(void *colors, int nr_color) {
	int i;
	uint8_t (*palette)[4] = colors;
	out_byte(VGA_DAC_WRITE_INDEX, 0);
	for(i = 0; i < nr_color; i ++) {
		out_byte(VGA_DAC_DATA, palette[i][0] >> 2);	// red
		out_byte(VGA_DAC_DATA, palette[i][1] >> 2);	// green
		out_byte(VGA_DAC_DATA, palette[i][2] >> 2);	// blue
	}
}

/* Print the palette in use. */
void read_palette() {
	int i;
	uint8_t r,g,b;
	out_byte(VGA_DAC_READ_INDEX, 0);
	for(i = 0; i < NR_PALETTE_ENTRY; i ++) {
		r = in_byte(VGA_DAC_DATA);
		g = in_byte(VGA_DAC_DATA);
		b = in_byte(VGA_DAC_DATA);
		printf("r = %x, g = %x, b = %x\n", r, g, b);
	}
}
