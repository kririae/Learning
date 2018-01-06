#include<bits/stdc++.h>
#define N ((1<<18)+3)
#define LL long long
using namespace std;
const int mod = 998244353;
int wn[N + N], a[N], b[N];
int rv[N];
int n, m;
int fastpow(int w, int x) {
	if(x == 1) return w;

	int t = fastpow(w, x >> 1);
	t = (LL)t * t % mod;
	return x & 1 ? (LL)t * w % mod : t;
}
void NTT(int *x, int len, int f) {
	for(int i = 0; i < len; i++) if(i < rv[i]) swap(x[i], x[rv[i]]);

	for(int i = 2, d = (len >> 1) * f; i <= len; i <<= 1, d /= 2) {
		for(int j = 0; j < len; j += i) {
			int *x1 = x + j, *x2 = x + j + (i >> 1), *w = wn + N, t1;

			for(int p = 0, t = i >> 1; p < t; p++, w += d) {
				x2[p] = ((LL)x1[p] - (t1 = ((LL)x2[p] * (*w)) % mod) + mod) % mod;
				x1[p] = (x1[p] + t1) % mod;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	int len = 1;

	while((1 << len) < n + m + 1) len++;

	for(int i = 1; i < (1 << len); i++) rv[i] = (rv[i >> 1] >> 1) | ((i & 1) << (len - 1));

	wn[N] = 1;
	int w = fastpow(3, (mod - 1) >> len);
	len = 1 << len;
	int rv = fastpow(w, mod - 2);

	for(int i = 1; i < len; i++) wn[N + i] = ((LL)wn[N + i - 1] * w) % mod;

	for(int i = N - 1; i >= N - len; i--) wn[i] = ((LL)wn[i + 1] * rv) % mod;

	for(int i = 0; i <= n; i++) scanf("%d", &a[i]);

	for(int i = 0; i <= m; i++) scanf("%d", &b[i]);

	NTT(a, len, 1);
	NTT(b, len, 1);

	for(int i = 0; i < len; i++) a[i] = ((LL)a[i] * b[i]) % mod;

	NTT(a, len, -1);

	int rl = fastpow(len, mod - 2);

	for(int i = 0; i <= n + m; i++) printf("%d ", ((LL)a[i]*rl) % mod);

	return 0;
}