// by kririae
// [NOI2009] 诗人小G
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace Bf
{
const int maxn = 100005, maxl = 35;

int n, l, p, sum[maxn];
char s[maxn][maxl];

inline void solve()
{
	cin >> t;
	while(t --> 0)
	{
		cin >> n >> l >> p;
		for (int i = 1; i <= n; ++i)
			cin >> s[i], sum[i] = sum[i - 1] + strlen(s[i]);
		
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	Bf::solve();
	return 0;
}