// by kririae
#include <bits/stdc++.h>

using namespace std;

namespace AHOI2009
{
const int maxn = 105;
const int mod = 9999973;

int n, m;
long long f[maxn][maxn][maxn];
// f[i][j][k]表示放到了第$i$行，有$j$列是一个旗子，有$k$列是两个棋子

template<typename T>
inline void inc(T &a, T b)
{
	a = (long long)(a + b) % mod;
}

inline long long C(int val)
{
    return val * (val - 1) / 2;
}

inline void solve()
{
	cin >> n >> m;
	
	f[0][0][0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= m; ++j)
			for (int k = 0; j + k <= m; ++k)
			{
				long long last = m - j - k;
				// 一个都不放
				inc(f[i + 1][j][k], f[i][j][k]);
				// 放一个在空列
				if(last > 0) inc(f[i + 1][j + 1][k], f[i][j][k] * last);
				// 放一个在有一个棋子的列
				if(j > 0) inc(f[i + 1][j - 1][k + 1], f[i][j][k] * j);
				// 放两个在空列
				if(last > 1) inc(f[i + 1][j + 2][k], f[i][j][k] * C(last));
				// 放一个在有一个棋子的列，放一个在没有棋子的列
				if(j > 0 && last > 1) inc(f[i + 1][j][k + 1], f[i][j][k] * last * j);
				// 放两个在有一个妻子的列
				if(j > 1) inc(f[i + 1][j - 2][k + 2], f[i][j][k] * C(j)); 
			}

	long long ans = 0;
	for (int j = 0; j <= m; ++j)
		for (int k = 0; j + k <= m; ++k)
				ans = (ans + f[n][j][k]) % mod;

	cout << ans << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	AHOI2009::solve();
	return 0;
}