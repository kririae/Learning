// by kririae
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 105;
int n, a[N], b[N], f[N][N];
inline int dp(int l, int r) {
	if(l >= r) return 0;
	if(f[l][r]) return f[l][r];
	if(l + a[l] <= r)
		f[l][r] = max(f[l][r], b[l] + dp(l + a[l], r));
	for (int k = l; k < r; ++k)
		f[l][r] = max(f[l][r], dp(l, k) + dp(k + 1, r));
	return f[l][r];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i], &b[i]);
	for (int i = n + 1; i <= (n << 1); ++i)
		a[i] = a[i - n], b[i] = b[i - n];
	// f[l][r]表示删除[l -> r]的卡牌数目的最大伤害。
	dp(1, n << 1);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = max(ans, f[i][i + n]);
	cout << ans << endl;
}