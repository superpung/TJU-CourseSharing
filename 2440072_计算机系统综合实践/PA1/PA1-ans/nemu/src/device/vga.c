#include "common.h"

#ifdef HAS_DEVICE

#include "vga.h"
#include "device/port-io.h"
#include "device/mmio.h"
#include "device/i8259.h"

enum {Horizontal_Total_Register, End_Horizontal_Display_Register, 
	Start_Horizontal_Blanking_Register, End_Horizontal_Blanking_Register,
   	Start_Horizontal_Retrace_Register, End_Horizontal_Retrace_Register,
   	Vertical_Total_Register, Overflow_Register, Preset_Row_Scan_Register,
   	Maximum_Scan_Line_Register, Cursor_Start_Register, Cursor_End_Register,
   	Start_Address_High_Register, Start_Address_Low_Register, Cursor_Location_High_Register,
   	Cursor_Location_Low_Register, Vertical_Retrace_Start_Register,
   	Vertical_Retrace_End_Register, Vertical_Display_End_Register, Offset_Register,
   	Underline_Location_Register, Start_Vertical_Blanking_Register, End_Vertical_Blanking,
   	CRTC_Mode_Control_Register, Line_Compare_Register
};

static uint8_t *vga_dac_port_base;
static uint8_t *vga_crtc_port_base;
static uint8_t vga_crtc_regs[19];

#define VGA_DAC_READ_INDEX 0x3C7
#define VGA_DAC_WRITE_INDEX 0x3C8
#define VGA_DAC_DATA 0x3C9

#define VGA_CRTC_INDEX		0x3D4
#define VGA_CRTC_DATA		0x3D5

#define CTR_ROW 200
#define CTR_COL 320

static void *vmem_base;
bool vmem_dirty = false;
bool line_dirty[CTR_ROW];

void vga_vmem_io_handler(hwaddr_t addr, size_t len, bool is_write) {
	if(is_write) {
		int line = (addr - 0xa0000) / CTR_COL;
		if(line < CTR_ROW) {
			line_dirty[line] = true;
			vmem_dirty = true;
		}
	}
}

void do_update_screen_graphic_mode() {
	int i, j;
	uint8_t (*vmem) [CTR_COL] = vmem_base;
	SDL_Rect rect;
	rect.x = 0;
	rect.w = CTR_COL * 2;
	rect.h = 2;

	for(i = 0; i < CTR_ROW; i ++) {
		if(line_dirty[i]) {
			for(j = 0; j < CTR_COL; j ++) {
				uint8_t color_idx = vmem[i][j];
				draw_pixel(2 * j, 2 * i, color_idx);
				draw_pixel(2 * j, 2 * i + 1, color_idx);
				draw_pixel(2 * j + 1, 2 * i, color_idx);
				draw_pixel(2 * j + 1, 2 * i + 1, color_idx);
			}
			rect.y = i * 2;
			SDL_BlitSurface(screen, &rect, real_screen, &rect);
		}
	}
	SDL_Flip(real_screen);
}

void update_screen() {
	if(vmem_dirty) {
		do_update_screen_graphic_mode();
		vmem_dirty = false;
		memset(line_dirty, false, CTR_ROW);
	}
}

void vga_dac_io_handler(ioaddr_t addr, size_t len, bool is_write) {
	static uint8_t *color_ptr; 
	if(addr == VGA_DAC_WRITE_INDEX && is_write) {
		color_ptr = (void *)&palette[ vga_dac_port_base[0] ];
	}
	else if(addr == VGA_DAC_DATA && is_write) {
		*color_ptr++ = vga_dac_port_base[1] << 2;
		if( (((void *)color_ptr - (void *)&screen->format->palette->colors) & 0x3) == 3) {
			color_ptr ++;
			if((void *)color_ptr == (void *)&palette[256]) {
				SDL_SetPalette(real_screen, SDL_LOGPAL | SDL_PHYSPAL, (void *)&palette, 0, 256);
				SDL_SetPalette(screen, SDL_LOGPAL, (void *)&palette, 0, 256);
			}
		}
	}
}

void vga_crtc_io_handler(ioaddr_t addr, size_t len, bool is_write) {
	if(addr == VGA_CRTC_INDEX && is_write) {
		vga_crtc_port_base[1] = vga_crtc_regs[ vga_crtc_port_base[0] ];
	}
	else if(addr == VGA_CRTC_DATA && is_write) {
		vga_crtc_regs[ vga_crtc_port_base[0] ] = vga_crtc_port_base[1] ;
	}
}

void init_vga() {
	vga_dac_port_base = add_pio_map(VGA_DAC_WRITE_INDEX, 2, vga_dac_io_handler);
	vga_crtc_port_base = add_pio_map(VGA_CRTC_INDEX, 2, vga_crtc_io_handler);
	vmem_base = add_mmio_map(0xa0000, 0x20000, vga_vmem_io_handler);
}
#endif	/* HAS_DEVICE */
