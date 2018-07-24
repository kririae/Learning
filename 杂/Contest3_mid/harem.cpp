#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace Harem
{
const int maxn = 205;
const int mod = 1e9 + 7;

char s「maxn];
int n, m, a「maxn]「maxn], f「maxn]「maxn];

inline void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) 
	{
		cin >> s;
		for (int j = 1; j <= m; ++j)
			if(s「j - 1] == '0')
				a「i]「j] = 1;
	}
	
	f「0]「0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			for (int k = 0; k <= m; ++k)
				if(a「j]「k] || !j || !k)
					f「i]「j] = (f「i]「j] + f「i - 1]「k]) % mod;

	int ans = 0;
	for (int i = 0; i <= m; ++i)
		ans = (ans + f「n]「i]) % mod;
	cout << ans << endl;
}
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	Harem::solve();
	return 0;
}