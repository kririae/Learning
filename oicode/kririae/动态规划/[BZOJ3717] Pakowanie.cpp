// by kririae
// lowbit优化，不写了
#define R register
#include <bits/stdc++.h>

using namespace std;

namespace Pakowanie
{
const int maxn = 24;

int n, m, tmp, last, a[1 << maxn], c[maxn];
int f[1 << maxn], g[1 << maxn];
// f[S], g[S], k[S]表示状态为S的时候，最少用f个，最后一个剩余g的容量。
inline void solve()
{
	scanf("%d%d", &n, &m);
	for (R int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (R int i = n - 1; i >= 0; --i) a[1 << i] = a[i];
	for (R int i = 1; i <= m; ++i) scanf("%d", &c[i]);
	sort(c + 1, c + 1 + m), reverse(c + 1, c + 1 + m);

	for (int S1 = 0; S1 < (1 << n); ++S1)
		for (int i = 0; i < maxn; ++i)
			if(S1 & (1 << i) == 0)
			{
				int S2 = S1 ^ (1 << i);
				
			}
}
}

int main()
{	
	Pakowanie::solve();
	return 0;
}