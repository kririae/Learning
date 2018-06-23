// by kririae
// 细节很少，但是思路相当复杂...
#define R register 
#define ll long long
#include <iostream>
#include <cstring>

using namespace std;

namespace Blocks
{
const int maxn = 205;

int t, n, m, cnt, a[maxn], c[maxn], num[maxn], f[maxn][maxn][maxn];

inline int dp(int l, int r, int k)
{
	if(f[l][r][k]) return f[l][r][k];
	if(l == r) return (num[l] + k) * (num[l] + k);
	f[l][r][k] = dp(l, r - 1, 0) + (num[r] + k) * (num[r] + k);
	for (int i = l; i < r; ++i)
		if(c[i] == c[r])
			f[l][r][k] = max(f[l][r][k], dp(l, i, num[r] + k) + dp(i + 1, r - 1, 0));
	return f[l][r][k];
}

inline void solve()
{
	cin >> t;
	while(t --> 0)
	{
		cin >> n;
		for (R int i = 1; i <= n; ++i)
			cin >> a[i];
			
		for (R int i = 1; i <= n; ++i)
		{
			if(a[i] != a[i - 1]) c[++m] = a[i], num[m] = 1;
			else ++num[m];
		}

		cout << "Case " << ++cnt << ": " << dp(1, m, 0) << endl;
		memset(f, 0, sizeof(f));
		memset(a, 0, sizeof(a));
		m = 0;
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	Blocks::solve();
	return 0;
}