#include "common.h"
#include <string.h>

#define RAMDISK_START ((void *)0)
#define RAMDISK_SIZE 0xa0000

/* The kernel is monolithic, therefore we do not need to
 * translate the address `buf' from the user process to
 * a physical one, which is necessary for a microkernel.
 */

/* read `len' bytes starting from `offset' of ramdisk into `buf' */
void ramdisk_read(uint8_t *buf, uint32_t offset, uint32_t len) {
	nemu_assert(offset + len < RAMDISK_SIZE);
	memcpy(buf, RAMDISK_START + offset, len);
}

/* write `len' bytes starting from `buf' into the `offset' of ramdisk */
void ramdisk_write(uint8_t *buf, uint32_t offset, uint32_t len) {
	nemu_assert(offset + len < RAMDISK_SIZE);
	memcpy(RAMDISK_START + offset, buf, len);
}

