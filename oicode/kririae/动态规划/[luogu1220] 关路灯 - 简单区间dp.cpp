// by kririae
#include <bits/stdc++.h>

using namespace std;

namespace luogu1220
{
const int maxn = 80 + 5;

int n, from, f[maxn][maxn][2], p[maxn], c[maxn], s[maxn];

inline void solve()
{
	memset(f, 0x3f, sizeof(f));
	
	cin >> n >> from;
	for (int i = 1; i <= n; ++i)
		cin >> p[i] >> c[i], s[i] = s[i - 1] + c[i];
		
	f[from][from][0] = f[from][from][1] = 0;
	
	for (int k = 2; k <= n; ++k)
	{
		for (int i = 1; i <= n - k + 1; ++i)
		{
			int j = i + k - 1;
			f[i][j][0] = min(f[i + 1][j][1] + (p[j] - p[i]) * (s[i] + s[n] - s[j]), f[i + 1][j][0] + (p[i + 1] - p[i]) * (s[i] + s[n] - s[j]));
			f[i][j][1] = min(f[i][j - 1][1] + (p[j] - p[j - 1]) * (s[i - 1] + s[n] - s[j - 1]), f[i][j - 1][0] + (p[j] - p[i]) * (s[i - 1] + s[n] - s[j - 1]));
		}
	}

	cout << min(f[1][n][0], f[1][n][1]) << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	luogu1220::solve();
	return 0;
}