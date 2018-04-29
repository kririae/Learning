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

namespace luogu1005
{
const int maxn = 80 + 5;
__int128 f[maxn][maxn], a[maxn][maxn], ans;
int n, m;

inline void put(__int128 val)
{
	if(val <= 0) return;
	put(val / 10);
	putchar(val % 10 + '0');
}

inline void solve()
{
	using namespace IO;
	// f[i][j] 从行头取i个，从行尾取j个的最大值
	read(n); read(m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			read(a[i][j]);
	
	for (int l = 1; l <= n; ++l) 
	{
		memset(f, 0, sizeof(f));
		for (int k = 0; k <= m; ++k)
			for (int i = 1; i <= m - k; ++i) 
				f[i][i + k] = max((__int128)(f[i + 1][i + k] + a[l][i]) << 1, (__int128)(f[i][i + k - 1] + a[l][i + k]) << 1);
		ans += f[1][m];
	}
	
	if(ans == 0) putchar('0');
	else put(ans);
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	luogu1005::solve();
	return 0;	
}