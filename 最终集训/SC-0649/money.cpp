#include <bits/stdc++.h>
using namespace std;

const int N = 205, M = 25005 * 105;
int t, n, a[N], mx = 0, g[M], f[M];
inline bool judge(int st) {
	memset(f, -1, sizeof f);
	f[0] = 1;
	for (int i = 0; i < n; ++i)
		if ((st >> i) & 1) {
			for (int j = 0; j <= mx * n; ++j)
				if (~f[j] && j + a[i] <= mx * n)
					f[j + a[i]] = 1;
		}
	for (int i = 0; i <= mx * n; ++i)
		if (f[i] ^ g[i]) return false;
	return true;
}
inline int cnt(int x) {
	int ans = 0;
	for (; x; x >>= 1)
		if (x & 1) ++ans;
	return ans;
}
inline void work50() {
	memset(f, -1, sizeof f);
	memset(g, -1, sizeof g);
	memset(a, 0, sizeof a);
	mx = 0;
	// scanf("%d", &n);
	int ans = n;
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), mx = max(a[i], mx);
	g[0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= mx * n; ++j)
			if (~g[j] && j + a[i] <= mx * n)
				g[j + a[i]] = 1;
	for (int i = 0; i < (1 << n); ++i)
		if (judge(i))	ans = min(ans, cnt(i));
	cout << ans << endl;
}
inline void work100() {
	memset(f, -1, sizeof f);
	memset(g, -1, sizeof g);
	memset(a, 0, sizeof a);
	mx = 0;
	// scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), mx = max(a[i], mx);
	sort(a, a + n);
	f[0] = 1;
	for (int i = 0; i < n; ++i) {
		int fg = 0;
		for (int j = 0; j <= mx * n; ++j) {
			if (~f[j] && j + a[i] <= mx * n && f[j + a[i]] == -1)
				fg = 1;
			if (~f[j] && j + a[i] <= mx * n)
				f[j + a[i]] = 1;
		}
		if (fg == 1) ++ans;
	}
	cout << ans << endl;
}
int main() {
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n <= 5) work50();
		else work100();
	}
} 
