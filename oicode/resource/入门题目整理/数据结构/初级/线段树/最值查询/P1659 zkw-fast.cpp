#include<cstdio>
#define N 1<<18
#define INF 1<<28
#include<iostream>
using namespace std;
inline int read()
{
	int ret = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9' ) {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * f;
}
int maxn[N], a[N]; //a-标记
int n, m, nn;
inline void add(int k, int &c) //区间k+标记c
{
	a[k] += c;
	maxn[k] += c;
}
inline void update(int &k)
{
	if(k < nn) maxn[k] = max(maxn[k << 1], maxn[(k << 1) + 1]) + a[k];
}
int main()
{
	n = read();
	for(nn = 1; nn < n + 2; nn <<= 1) {}
	for(int i = nn + 1; i <= nn + n; i++) {
		maxn[i] = read();
	}
	for(int i = nn - 1; i > 0; i--)	maxn[i] = max(maxn[i << 1], maxn[(i << 1) + 1]);
	m = read();
	for(int i = 1; i <= m; i++) {
		int k, l, r, c, ans;
		k = read();
		l = read();
		r = read();
		if(k == 1) {
			c = read();
			for(int L = l + nn - 1, R = r + nn + 1; L != 0; L >>= 1, R >>= 1) {
				update(L), update(R);
				if(L < R - 1) {
					if((L & 1) == 0) add(L + 1, c);
					if((R & 1) == 1) add(R - 1, c);
				}
			}
		} else {
			int lret = -INF, rret = -INF;
			bool fl = false, fr = false;
			for(int L = l + nn - 1, R = r + nn + 1; L != 0; L >>= 1, R >>= 1) {
				if(fl) lret += a[L];
				if(fr) rret += a[R];
				if(L < R - 1) {
					if((L & 1) == 0) lret = max(lret, maxn[L + 1]), fl = true;
					if((R & 1) == 1) rret = max(rret, maxn[R - 1]), fr = true;
				}

			}
			ans = max(lret, rret);
			printf("%d\n", ans);
		}
	}
	return 0;
}
