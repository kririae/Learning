#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100005;
int n, a[N]; ll ans = 0;
inline void dfs(int l, int r) {
	if (l > r) return;
	if (l == r)
		return (void) (ans += a[l]);
	int mv = 1e9;
	for (int i = l; i <= r; ++i)
		if (a[i] && a[i] < mv) mv = a[i];
	for (int i = l; i <= r; ++i) a[i] -= mv;
	ans += mv;
	int pre = l;
	for (int i = l; i <= r; ++i)
		if (a[i] == 0)
			dfs(pre, i - 1), pre = i + 1;
	dfs(pre, r);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int pre = 1;
	for (int i = 1; i <= n; ++i)
		if (a[i] == 0) 
			dfs(pre, i - 1), pre = i + 1;
	dfs(pre, n);
	cout << ans;
	return 0;
}
