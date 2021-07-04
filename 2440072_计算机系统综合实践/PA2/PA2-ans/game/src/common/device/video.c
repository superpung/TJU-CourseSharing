#include "common.h"
#include "device/video.h"

#include <string.h>

extern char font8x8_basic[128][8];

static uint8_t vbuf[SCR_SIZE];
uint8_t *vmem = vbuf;

void
prepare_buffer(void) {
	memset(vmem, 0, SCR_SIZE);
}

void
display_buffer(void) {
	asm volatile ("cld; rep movsl" : : "c"(SCR_SIZE / 4), "S"(vmem), "D"(VMEM_ADDR));
}

static inline void
draw_character(char ch, int x, int y, int color) {
	int i, j;
	assert((ch & 0x80) == 0);
	char *p = font8x8_basic[(int)ch];
	for (i = 0; i < 8; i ++) 
		for (j = 0; j < 8; j ++) 
			if ((p[i] >> j) & 1)
				draw_pixel(x + i, y + j, color);
}

void
draw_string(const char *str, int x, int y, int color) {
	while (*str) {
		draw_character(*str ++, x, y, color);
		if (y + 8 >= SCR_WIDTH) {
			x += 8; y = 0;
		} else {
			y += 8;
		}
	}
}
