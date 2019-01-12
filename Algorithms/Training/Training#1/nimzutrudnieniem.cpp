// by kririae
// 题意：选取数列中的(n - k*d)个数，(k \in N^*)，使得剩下的数的xor值 == 0
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char gc()
{
	static const int LEN = 1e7;
	static char buf[LEN];
	static int s = 0, t = 0;
	s == t ? s = 0, t = fread(buf, 1, LEN, stdin) : 0;
	return s == t ? -1 : buf[s++];
}

template<class T>
inline void read(T &val)
{
	int m, c;
	for (m = 1, c = gc(); !isdigit(c); c = gc())
		m = c == '-' ? -1 : 1;
	if(c == -1) return;
	for (val = 0; isdigit(c); c = gc())
		val = (val << 3) + (val << 1) + (c - '0');
	val = m == -1 ? -val : val;
}
}

namespace Nimzutrudnieniem
{
const int maxn = 5e5 + 5;

int n, d, MOD, a[maxn], f[10][maxn];

inline void solve()
{
	read(n), read(d), MOD = d;
	for (R int i = 1; i <= n; ++i) read(a[i]);
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= 10; ++j)
		{
			for (int k = 0; k <= )
		}
	}
}
}

int main()
{
	Nimzutrudnieniem::solve();
	return 0;
}