// by kririae
#define R register
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char gc()
{
	static char buf[1 << 18], *fs, *ft;
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

namespace BZOJ1034
{
const int maxn = 100005;

int n, a[maxn], b[maxn];

inline int calc(int a[], int b[])
{
	int h1 = 1, t1 = n, h2 = 1, t2 = n, ans = 0;
	while(h1 <= t1 && h2 <= t2)
	{
		if(a[h1] > b[h2]) ++h1, ++h2, ans += 2;
		else if(a[t1] > b[t2]) --t1, --t2, ans += 2;
		else if(a[h1++] == b[t2--]) ++ans;
	}
	return ans;
}

inline void solve()
{
	using namespace IO;
	n = read();
	for (R int i = 1; i <= n; ++i) a[i] = read();
	for (R int i = 1; i <= n; ++i) b[i] = read();
	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
	printf("%d %d\n", calc(a, b), (n << 1) - calc(b, a));
}
}

int main()
{
	BZOJ1034::solve();
	return 0;
}