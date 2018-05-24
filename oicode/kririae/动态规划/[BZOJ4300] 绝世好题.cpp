// by kririae
// 参考题解...这个"按位dp"还真是前所未有
#include <bits/stdc++.h>

using namespace std;

namespace BZOJ4300
{
int n, val, ans, tmp, f[35];
inline void solve()
{
	cin >> n;
	while(n --> 0)
	{
		cin >> val; tmp = 1;
		for (int i = 0; i <= 30; ++i)
			if(val & (1 << i)) tmp = max(f[i] + 1, tmp);
		for (int i = 0; i <= 30; ++i)
			if(val & (1 << i)) f[i] = max(f[i], tmp);
		ans = max(ans, tmp);
	}
	cout << ans << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	BZOJ4300::solve();
	return 0;
}