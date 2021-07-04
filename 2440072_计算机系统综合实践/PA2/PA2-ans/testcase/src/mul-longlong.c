#include "trap.h"

long long mul(long long a,long long b) {
	long long ans = a*b;
	return ans;
}

int test_data[] = { -1364082006, 1157693227, -2022600529, 301212728};
long long ans[] = { 1860719719092984036LL, -1579188499418773362LL, 2758992986934981174LL, -410878862242972368LL, 1340253607841673529LL, -2341550933349917083LL, 348711935091793256LL, 4090912899911079841LL, -609233022994333112LL, 90729107509201984LL};

#define NR_DATA (sizeof(test_data) / sizeof(test_data[0]))

int main() {
	int i,j,ans_idx = 0;
	int loop = 0;
	for (i = 0;i < NR_DATA;i++) {
		for (j = i;j < NR_DATA;j++) { 
			nemu_assert(ans[ans_idx++] == mul(test_data[i],test_data[j]));
			loop ++;
		}
	}

	nemu_assert(loop == NR_DATA * (NR_DATA + 1) / 2);

	return 0;
}
			
