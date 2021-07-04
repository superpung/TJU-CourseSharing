#include "common.h"
#include "memory/memory.h"
#include "device/port-io.h"
#include "device/i8259.h"

#define IDE_CTRL_PORT 0x3F6
#define IDE_PORT 0x1F0
#define BMR_PORT 0xc040

#define IDE_IRQ 14

static uint8_t *ide_port_base;
static uint8_t *bmr_base;	/* bus master registers */

static uint32_t sector, disk_idx;
static uint32_t byte_cnt;
static bool ide_write;
static FILE *disk_fp;

void ide_io_handler(ioaddr_t addr, size_t len, bool is_write) {
	assert(byte_cnt <= 512);
	int ret;
	if(is_write) {
		if(addr - IDE_PORT == 0 && len == 4) {
			/* write 4 bytes data to disk */
			assert(ide_write);
			ret = fwrite(ide_port_base, 4, 1, disk_fp);
			assert(ret == 1);

			byte_cnt += 4;
			if(byte_cnt == 512) {
				/* finish */
				ide_port_base[7] = 0x40;
			}
		}
		else if(addr - IDE_PORT == 7) {
			if(ide_port_base[7] == 0x20 || ide_port_base[7] == 0x30) {
				/* command: read/write */
				sector = (ide_port_base[6] & 0x1f) << 24 | ide_port_base[5] << 16
					| ide_port_base[4] << 8 | ide_port_base[3];
				disk_idx = sector << 9;
				fseek(disk_fp, disk_idx, SEEK_SET);

				byte_cnt = 0;

				if(ide_port_base[7] == 0x20) {
					/* command: read from disk */
					ide_write = false;
					ide_port_base[7] = 0x40;
					i8259_raise_intr(IDE_IRQ);
				}
				else {
					/* command: write to disk */
					ide_write = true;
				}
			}
			else if (ide_port_base[7] == 0xc8) {
				/* command: DMA read */

				/* Nothing to do here. The actual read operation is
				 * issued by write commands to the bus master register. */
			}
			else {
				/* not implemented command */
				assert(0);
			}
		}
	}
	else {
		if(addr - IDE_PORT == 0 && len == 4) {
			/* read 4 bytes data from disk */
			assert(!ide_write);
			ret = fread(ide_port_base, 4, 1, disk_fp);
			assert(ret == 1 || feof(disk_fp));

			byte_cnt += 4;
			if(byte_cnt == 512) {
				/* finish */
				ide_port_base[7] = 0x40;
			}
		}
	}
}

void bmr_io_handler(ioaddr_t addr, size_t len, bool is_write) {
	int ret;
	if(is_write) {
		if(addr - BMR_PORT == 0) {
			if(bmr_base[0] & 0x1) {
				/* DMA start command */
				if(bmr_base[0] & 0x8) {
					/* DMA read */

					/* the address of Physical Region Descriptor Table */
					hwaddr_t prdt_addr = *(uint32_t *)(bmr_base + 4);

					hwaddr_t addr = hwaddr_read(prdt_addr, 4);
					uint32_t hi_entry = hwaddr_read(prdt_addr + 4, 4);
					uint16_t byte_cnt = hi_entry & 0xffff;

					sector = (ide_port_base[6] & 0x1f) << 24 | ide_port_base[5] << 16
						| ide_port_base[4] << 8 | ide_port_base[3];
					disk_idx = sector << 9;
					fseek(disk_fp, disk_idx, SEEK_SET);

					ret = fread((void *)hwa_to_va(addr), byte_cnt, 1, disk_fp);
					assert(ret == 1 || feof(disk_fp));

					/* We only implement PRDT of single entry. */
					assert(hi_entry & 0x80000000);

					/* finish */
					ide_port_base[7] = 0x40;
					i8259_raise_intr(IDE_IRQ);
				}
				else {
					/* DMA write is not implemented */
					assert(0);
				}
			}
		}
	}
}

void init_ide() {
	ide_port_base = add_pio_map(IDE_PORT, 8, ide_io_handler);
	ide_port_base[7] = 0x40;

	bmr_base = add_pio_map(BMR_PORT, 8, bmr_io_handler);
	bmr_base[0] = 0;

	extern char *exec_file;
	disk_fp = fopen(exec_file, "r+");
	Assert(disk_fp, "Can not open '%s'", exec_file);
}
