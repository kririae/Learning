// by kririae
// GIVE UP...这个链表结构式的题面太蛋疼啦！
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace Function
{
const int maxn = 100005;
const int MOD = 1e9 + 7;

struct Q
{
	int p, q, x;
} q[maxn];
int n, m, ans, a[maxn], b[maxn], c[maxn], res[maxn];

inline void exc(int i, int j)
{
	if(c[i] >= j)
	{
		exc(c[i], j);
		b[i] = (ll)(a[i] * b[c[i]] + b[i]) % MOD;
		a[i] = a[i] * a[c[i]] % MOD;
		c[i] = c[c[i]];
	}
}

inline void solve()
{
	cin >> n >> m;
	for (R int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i];
	for (R int i = 1; i <= m; ++i) cin >> q[i].p >> q[i].q >> q[i].x;

	while(n --> 0)
	{

	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	Function::solve();
	return 0;
}