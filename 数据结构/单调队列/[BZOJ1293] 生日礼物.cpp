#define R register
#define ll long long
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
	for(; !isdigit(c); c = gc()) if(c == '-') f = -1;
	for(; isdigit(c); c = gc()) k = k * 10 + c - '0';
	return k * f;
}
}

namespace BZOJ1293
{
const int maxn = 1e6 + 5;

struct N
{
	int val, pos;
	bool operator < (const N &a) const 
	{ return pos < a.pos; }
} a[maxn], q[maxn];

int n, k, t, val, ans = 1e9, cnt[65], sum, all, l = 1, r = 0;

inline void solve()
{
    using namespace IO;
	n = read(), k = read();
	for (R int i = 1; i <= k; ++i) 
		for (R int j = read(); j >= 1; --j)
			a[++all].val = i, a[all].pos = read();	
	sort(a + 1, a + 1 + n);	
	for (R int i = 1; i <= n; ++i)
	{
		sum += (cnt[a[i].val] == 0 ? 1 : 0);
		++cnt[a[i].val], q[++r] = a[i];
		while(sum == k) 
			ans = min(ans, q[r].pos - q[l].pos),
			sum -= (--cnt[q[l++].val] == 0 ? 1 : 0);
	}
	printf("%d\n", ans);
}
}

int main()
{
	return BZOJ1293::solve(), 0;
}