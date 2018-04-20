#include <bits/stdc++.h>

using namespace std;

namespace tyvj1051
{
const int maxn = 305;

int n, m, a[maxn], k, s, f[maxn][maxn];
vector<int> edges[maxn];

inline void dp(int k)
{
	f[k][0] = 0;
	for (int i = 0; i < edges[k].size(); ++i)
	{
		int s = edges[k][i];
		dp(s);
		for (int j = m; j >= 0; --j)
			for (int rp = j; rp >= 0; --rp)
				if(j - rp >= 0)
					f[k][j] = max(f[k][j], f[k][j - rp] + f[s][rp]);
	}
	
	for (int j = m; k && j > 0; --j) 
		f[k][j] = f[k][j - 1] + a[k];
}

inline void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> k >> a[i], edges[k].push_back(i);
	
	dp(0);
	
	cout << f[0][m] << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	tyvj1051::solve();
	return 0;
}