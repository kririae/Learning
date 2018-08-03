// by kririae
#include <bits/stdc++.h>
#define ll long long
using namespace std;

namespace Aya
{
/*
f[i][j]处理到第i位，当前位放j，且满足队列的情况数量
f[i][4] += f[j][4]
f[i][4] += f[j][7]
f[i][7] += f[j][4]
f[i][7] += f[j][7]
 */
const int mod = 1e9 + 7, N = 1005;
int t, f[N][15], k, a[N], l, r;
inline int dp(int pos, int curr, bool limit, bool lead)
{
	if(pos <= 0) return 1;
	if(!limit && !lead && f[pos][curr]) return f[pos][curr];
	int up = limit ? a[pos] : 9;
	ll ans = 0;
	for (int i = 0; i <= up; ++i)
		for (int j = pos - 1; j >= pos - k + 1; --j)
			(ans += dp(j, 4, limit && i == a[pos], lead && i == 0)) %= mod,
			(ans += dp(j, 7, limit && i == a[pos], lead && i == 0)) %= mod;
	if(!limit && !lead) f[pos][curr] = ans;
	return ans;
}
inline ll work(int x)
{
	memset(f, 0, sizeof(f));
	if(x == 0) return 0;
	int curr = 0;
	while(x) a[++curr] = x % 10, x /= 10;
	return (dp(curr, 7, 1, 1) + dp(curr, 4, 1, 1)) % mod;
}
inline void solve()
{
	freopen("aya.in", "r", stdin);
	freopen("aya.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> t >> k;
	while(t--) {
		cin >> l >> r;
		cout << work(r) - work(l - 1) << endl;
	}
}
}

int main()
{
	return Aya::solve(), 0;
}