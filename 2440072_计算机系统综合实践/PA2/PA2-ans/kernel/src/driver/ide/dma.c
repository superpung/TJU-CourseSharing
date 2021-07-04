#include "common.h"
#include "memory.h"
#include "x86.h"

#define BMR_PORT 0xc040

/* TODO: define the PRDT here */



void
dma_prepare(void *buf) {
	/* TODO:
	 * 1. Prepare a Physical Region Descriptor Table(PRDT)
	 *		with single entry.
	 * 2. Fill the PRD entry as following
	 *		address: the address of `buf'
	 *		byte_cnt: 512
	 *		eot: 1
	 * 3. Load the address of PRDT to the Descriptor Table
	 *		Pointer Register(port = BMR_PORT + 4):
	 *
	 *			out_long(BMR_PORT + 4, PRDT_addr);
	 * 
	 *
	 * NOTE: All addresses seen by devices are physical.
	 */

	panic("please implement me");
}

void
dma_issue_read(void) {
	out_byte(BMR_PORT, in_byte(BMR_PORT) | 0x1 | 0x8);
}
