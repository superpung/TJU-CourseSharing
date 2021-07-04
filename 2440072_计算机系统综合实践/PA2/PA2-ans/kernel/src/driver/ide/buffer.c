#include "common.h"
#define NR_SEC_BUF    128   /* sector buffer is a direct address hash */

void disk_do_read(void *, uint32_t);
void disk_do_write(void *, uint32_t);

struct SectorBuf {
	uint32_t sector;
	bool used, dirty;
	uint8_t content[512];
};
static struct SectorBuf buf[NR_SEC_BUF];

void
buf_init(void) {
	int i;
	for (i = 0; i < NR_SEC_BUF; i ++) {
		buf[i].used = false;
	}
}

void
buf_writeback(void) {
	int i;
	for (i = 0; i < NR_SEC_BUF; i ++) {
		if (buf[i].dirty == true) {
			disk_do_write(&buf[i].content, buf[i].sector);
			buf[i].dirty = false;
		}
	}
}

static struct SectorBuf *
buf_fetch(uint32_t sector) {
	struct SectorBuf *ptr = &buf[sector % NR_SEC_BUF];
	
	if (ptr->used == true && ptr->sector == sector) {
		/* buf hit, do nothing */
	} else {
		if (ptr->used == true && ptr->dirty == true) {
			/* write back */
			disk_do_write(&ptr->content, ptr->sector);
		}
		/* issue a read command */
		disk_do_read(&ptr->content, sector);

		ptr->used = true;
		ptr->sector = sector;
		ptr->dirty = false;
	}
	return ptr;
}

uint8_t
read_byte(uint32_t offset) {
	uint32_t sector = offset >> 9;
	struct SectorBuf *ptr = buf_fetch(sector);
	return ptr->content[offset & 511];
}

void
write_byte(uint32_t offset, uint8_t data) {
	uint32_t sector = offset >> 9;
	struct SectorBuf *ptr = buf_fetch(sector);
	ptr->content[offset & 511] = data;
	ptr->dirty = true;
}

