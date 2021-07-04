#include "trap.h"

int ans[] = {101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

int main() {
	int m, i, n = 0;
	int prime;
	for(m = 101; m <= 200; m += 2) {
		prime = 1;
		for(i = 2; i < m; i ++) {
			if(m % i == 0) {
				prime = 0;
				break;
			}
		}
		if(prime) {
			nemu_assert(i == ans[n]);
			n ++;
		}
	}

	nemu_assert(m == 201);
	nemu_assert(n == 21);

	return 0;
}
