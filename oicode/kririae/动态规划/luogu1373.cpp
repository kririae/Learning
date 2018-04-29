// by kririae
// dp
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char read()
{
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
	return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
	static char c;
	static bool iosig;

	for (c = read(), iosig = false; !isdigit(c); c = read())
	{
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}

	for (x = 0; isdigit(c); c = read()) 
		x = (x + (x << 2) << 1) + (c ^ '0');

	iosig ? x = -x : 0;
}
}

namespace luogu1373
{
const int maxn = 800 + 3;
const int maxk = 15 + 3;

int n, m, mod, f[maxn][maxn][maxk][2], a[maxn][maxn];

template<typename T>
inline void add(T &a, T &b)
{
	a = (a + b) % 1000000007;
}

inline void solve()
{
	using namespace IO;
	read(n); read(m); read(mod);
	++mod;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			read(a[i][j]);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			for (int k = 0; k <= mod; ++k)
				f[i][j][a[i][j] % mod][1] = 1;

	// f[i][j][k][1] -> 到达第(i, j)个点，两人魔瓶的差值是k，小a先走的方法
	// 同理 f[i][j][k][0]是uim先走的
	register int i, j, k;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			for (k = 0; k <= mod; ++k)
			{
				if(i + 1 <= m) 
				{
					add(f[i + 1][j][(k - a[i + 1][j] + mod) % mod][0], f[i][j][k][1]);
					add(f[i + 1][j][(k + a[i + 1][j]) % mod][1], f[i][j][k][0]);
				}

				if(j + 1 <= n)
				{
					add(f[i][j + 1][(k - a[i][j + 1] + mod) % mod][0], f[i][j][k][1]);
					add(f[i][j + 1][(k + a[i][j + 1]) % mod][1], f[i][j][k][0]);
				}
			}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			add(ans, f[i][j][0][0]);

	cout << ans % 1000000007<< endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	luogu1373::solve();
	return 0;	
}