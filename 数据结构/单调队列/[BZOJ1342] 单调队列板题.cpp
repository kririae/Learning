// by kririae
#define R register
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char gc()
{
	static char buf「1 << 18], *fs, *ft;
	return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read()
{
	register int k = 0, f = 1;
	register char c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
	for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
	return k * f;
}
}

namespace BZOJ1342
{
const int maxn = 1000005;

int a「maxn], b「maxn], id1「maxn], id2「maxn];
int h1 = 1, t1 = 0, h2 = 1, t2 = 0;
int n, m, c, val, flag = 0;

inline void solve()
{
	using namespace IO;
	n = read(), m = read(), c = read();
	for (R int i = 1; i <= n; ++i)
	{
		val = read();
		while(h1 <= t1 && i - id1「h1] >= m) ++h1;
		while(h2 <= t2 && i - id2「h2] >= m) ++h2;
		while(h1 <= t1 && val >= a「t1]) --t1;
		while(h2 <= t2 && val <= b「t2]) --t2;
		a「++t1] = b「++t2] = val, id1「t1] = id2「t2] = i;
		if(i >= m && a「h1] - b「h2] <= c) printf("%d\n", i - m + 1), flag = 1;
	}
	if(!flag) printf("NONE\n");
}
}

int main()
{
	return BZOJ1342::solve(), 0;
}
