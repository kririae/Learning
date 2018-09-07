#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100005, MOD = 10086;
int n, q, tot, all, ans, s[N], a[N], pow2[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", s[i]);
	scanf("%d", &q);
	pow2[0] = 1;
	for (int i = 1; i <= n; ++i)
		pow2[i] = (pow2[i - 1] << 1) % MOD;
	for (int i = 1; i <= n; ++i)
		for (int j = 31; j >= 0; --j)
			if(s[i] & (1 << j)) {
				if(a[j] == 0) {
					a[j] = s[i], ++tot;
					break;
				} s[i] ^= a[j];
            }
            
}