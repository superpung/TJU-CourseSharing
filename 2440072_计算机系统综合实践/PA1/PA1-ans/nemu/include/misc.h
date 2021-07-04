#ifndef __LIB_MISC_H__
#define __LIB_MISC_H__

#include "common.h"

inline static void memcpy_with_mask(void *dest, const void *src, size_t len, uint8_t *mask) {
	int i;
	for(i = 0; i < len; i ++) {
		if(mask[i]) {
			((uint8_t *)dest)[i] = ((uint8_t *)src)[i];
		}
	}
}

#endif
