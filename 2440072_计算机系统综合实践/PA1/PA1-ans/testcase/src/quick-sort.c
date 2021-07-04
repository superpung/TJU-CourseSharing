#include "trap.h"

#define N 100

int a[N] = {81, 37, 64, 23, 38, 65, 56, 15, 8, 33, 85, 39, 71, 12, 77, 6, 82, 89, 80, 35, 0, 59, 73, 4, 61, 30, 74, 69, 13, 42, 68, 63, 9, 29, 47, 36, 99, 25, 21, 14, 60, 3, 2, 18, 26, 83, 53, 5, 43, 67, 88, 70, 76, 92, 94, 48, 34, 49, 66, 95, 78, 62, 32, 52, 16, 72, 27, 28, 22, 40, 84, 91, 96, 57, 87, 51, 98, 1, 10, 11, 24, 20, 19, 31, 7, 97, 50, 86, 79, 17, 75, 55, 93, 44, 58, 54, 45, 41, 90, 46};

int partition(int *a, int p, int q) {
	int pivot = a[p];
	int i = p, j = q;
	while(i < j) {
		while(i < j && a[j] > pivot) j --;
		a[i] = a[j];

		while(i < j && a[i] <= pivot) i ++;
		a[j] = a[i];
	}

	a[i] = pivot;
	return i;
}

void quick_sort(int *a, int p, int q) {
	if(p >= q) return;

	int m = partition(a, p, q);
	quick_sort(a, p, m - 1);
	quick_sort(a, m + 1, q);
}

int main() {
	quick_sort(a, 0, N - 1);

	int i;
	for(i = 0; i < N; i ++) {
		nemu_assert(a[i] == i);
	}

	nemu_assert(i == N);

	quick_sort(a, 0, N - 1);

	for(i = 0; i < N; i ++) {
		nemu_assert(a[i] == i);
	}

	nemu_assert(i == N);

	return 0;
}
