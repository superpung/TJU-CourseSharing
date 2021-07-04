#include "trap.h"

#define N 100

struct dummy {
	int pad1[N];
	char pad2[N];
} d;

struct dummy fun(struct dummy a) {
	return a;
}

int main() {
	int i;
	for(i = 0; i < N; i ++) {
		d.pad1[i] = i + 128;
		d.pad2[i] = i;
	}

	struct dummy t = fun(d);

	for(i = 0; i < N; i ++) {
		nemu_assert(t.pad1[i] == i + 128);
		nemu_assert(t.pad2[i] == i);
	}

	nemu_assert(i == N);

	return 0;
}
