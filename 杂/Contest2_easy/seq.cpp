#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace Seq
{
const int maxn = 105;
const int mod = 1e9 + 7;

// 吃亏...不会矩阵快速幂...

int n, q「maxn], a「20000007]; // 懒得了

inline void solve()
{
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	cin >> n;
	for (R int i = 1; i <= n; ++i) cin >> q「i], q「0] = max(q「0], q「i]);

	a「1] = a「2] = a「3] = 1;
	for (R int i = 4; i <= q「0]; ++i)
		a「i] = (a「i - 3] + a「i - 1]) % mod;

	for (R int i = 1; i <= n; ++i)
		cout << a「q「i]] << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	Seq::solve();
}