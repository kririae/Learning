#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int MOD = 1e9 + 7; 
int n, m;
inline ll fpow(ll a, ll p) {
	ll ans = 1;
	for (; p; p >>= 1) {
		if (p & 1) ans = (a * ans) % MOD;
		a = (a * a) % MOD; 
	}
	return ans; 
}
namespace Work20 {
int b[7][7], a[100], path[100], cnt = 0, c[105][20], d[105][20];
inline void dfs(int x, int y, int tot) {
	a[tot] = b[x][y];
	if (x == n && y == m) {
		++cnt;
		memcpy(c[cnt], a, sizeof a);
		memcpy(d[cnt], path, sizeof path);
	}
	if (x + 1 <= n) path[tot] = 1, dfs(x + 1, y, tot + 1);
	if (y + 1 <= m) path[tot] = 2, dfs(x, y + 1, tot + 1);
}
inline int cmp(int *x, int *y, int len) {
	for (int i = 1; i <= len; ++i) {
		if (x[i] > y[i]) return 0;
		if (x[i] < y[i]) return 1;
	}
	return -1;
}
inline bool check(int s) {
	memset(a, 0, sizeof a);
	memset(path, 0, sizeof path);
	memset(c, 0, sizeof c);
	memset(d, 0, sizeof d);
	cnt = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			b[i][j] = (s >> ((i - 1) * n + j - 1)) & 1;
		}
	dfs(1, 1, 1);
	for (int i = 1; i <= cnt; ++i)
		for (int j = i + 1; j <= cnt; ++j)
			if (cmp(d[i], d[j], n + m - 2) == 1 && cmp(c[i], c[j], n + m - 1) > 0)
				return false;
	return true;
}
inline void solve() {
	int ans = 0;
	for (int i = 0; i < (1 << (n * m)); ++i)
		ans += check(i);
	cout << ans << endl;
}
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if (n == 1) {
		cout << fpow(2, m) << endl;
		return 0; 
	}
	if (n == 2) {
		cout << fpow(2, m - 1) * (4 + 2 * (m - 1) % MOD) % MOD << endl;
		return 0;
	}
	if (n <= 3 && m <= 3) {
		Work20::solve();
		return 0;
	}
}
