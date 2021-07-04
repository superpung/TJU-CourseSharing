#ifndef __MMIO_H__
#define __MMIO_H__

#include "common.h"

typedef void(*mmio_callback_t)(hwaddr_t, size_t, bool);

void* add_mmio_map(hwaddr_t, size_t, mmio_callback_t);
int is_mmio(hwaddr_t);

uint32_t mmio_read(hwaddr_t, size_t, int);
void mmio_write(hwaddr_t, size_t, uint32_t, int);

#endif
