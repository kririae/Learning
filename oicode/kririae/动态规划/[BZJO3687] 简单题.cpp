// 只能说..骚...
#include <bits/stdc++.h>

using namespace std;

namespace BZOJ3687
{
const int maxn = 2000005;

bitset<maxn> a;
int n, val, sum, ans;
inline void solve()
{
	cin >> n;
	a[0] = 1;
	while(n --> 0)
		cin >> val, sum += val, a ^= (a << val);
	for (int i = 1; i <= sum; ++i)
		if(a[i]) ans ^= i;
	cout << ans << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	BZOJ3687::solve();
	return 0;
}