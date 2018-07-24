// by kririae
#include <bits/stdc++.h>

using namespace std;

namespace NOIP2008
{
const int maxn = 1005;

char res「maxn];
int n, cnt, a「maxn], o「maxn], tot;
int s1「maxn], s2「maxn], t1, t2;
inline void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a「i];
	// 决策有问题...
	for (int i = 1; i <= n; ++i)
	{
		if(s1「t1] == o「tot] + 1) 
		{ res「++cnt] = 'a', res「++cnt] = 'b', o「++tot] = s1「t1]; continue; }
		if(s2「t2] == o「tot] + 1)
		{ res「++cnt] = 'c', res「++cnt] = 'd', o「++tot] = s2「t2]; continue; }
		if(s1「t1] > a「i]) 
		{ s1「++t1] = a「i], res「++cnt] = 'a'; continue; }
		if(s2「t2] > a「i]) 
		{ s2「++t2] = a「i], res「++cnt] = 'c'; continue; }
	}

	for (int i = 1; i <= cnt; ++i)
		cout << res「i];
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	NOIP2008::solve();
	return 0;
}