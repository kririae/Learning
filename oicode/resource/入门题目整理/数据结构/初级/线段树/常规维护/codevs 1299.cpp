#include<cstdio>
#include<iostream>
#define N 1<<20
using namespace std;
inline int read() {
	char c = getchar();
	int ret = 0;

	while(c < '0' || c > '9') c = getchar();

	while(c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();

	return ret;
}
int mem[N], num[N];
int n, m, nn;
void update(int k) {
	if(k >= nn) return;

	num[k] = num[k << 1] + num[(k << 1) | 1];

	if(mem[k]) num[k] = 0;
}
int clear(int fr, int to) {
	int lans = 0, rans = 0;

	for(int l = fr + nn - 1, r = to + nn + 1; l != 0; l >>= 1, r >>= 1) {
		if(mem[l]) lans = 0;

		if(mem[r]) rans = 0;

		if((l ^ r) == 1 || l == r) {
		} else {
			if((l & 1) == 0)	lans += num[l + 1], mem[l + 1] = 1, num[l + 1] = 0;

			if((r & 1) == 1)	rans += num[r - 1], mem[r - 1] = 1, num[r - 1] = 0;
		}

		update(l);
		update(r);
	}

	int ret = lans + rans;
	return ret;
}

int main() {
	n = read();
	m = read();
	int ans = n;

	for(nn = 1; nn < n; nn <<= 1) {}

	for(int i = nn + 1; i <= nn + n; i++) num[i] = 1;

	for(int i = nn - 1; i > 0; i--) update(i);

	for(int i = 1; i <= m; i++) {
		int a = read(), b = read();
		ans -= clear(a, b);
		printf("%d\n", ans);
	}

	return 0;
}
