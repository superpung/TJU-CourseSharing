#include "common.h"
#include "memory.h"
#include <string.h>

static PDE updir[NR_PDE] align_to_page;
static CR3 ucr3;

PDE* get_updir() { return updir; }
uint32_t get_ucr3() { return ucr3.val; }

PDE* get_kpdir();

uint32_t cur_brk = 0;
// we do not free memory, so use `max_brk' to determine whether to call mm_malloc()
uint32_t max_brk = 0;

/* The brk() system call handler. */
uint32_t mm_brk(uint32_t new_brk) {
	if(new_brk != 0) {
		if(new_brk > max_brk) {
#ifdef IA32_PAGE
			mm_malloc(max_brk, new_brk - max_brk);
#endif
			max_brk = new_brk;
		}

		cur_brk = new_brk;
	}

	// If new_brk == 0, the brk() syscall should fail and return
	// the current break. See the NOTE of `man 2 brk' for details.

	return cur_brk;
}

void init_mm() {
	PDE *kpdir = get_kpdir();

	/* make all PDE invalid */
	memset(updir, 0, NR_PDE * sizeof(PDE));

	/* create the same mapping above 0xc0000000 as the kernel mapping does */
	memcpy(&updir[KOFFSET / PT_SIZE], &kpdir[KOFFSET / PT_SIZE], 
			(PHY_MEM / PT_SIZE) * sizeof(PDE));

	ucr3.val = (uint32_t)va_to_pa((uint32_t)updir) & ~0xfff;
}

