// by kririae
// 我咋感觉和DP没啥关系
#include <bits/stdc++.h>

using namespace std;

namespace QCKNZHZ
{
const int maxn = 1e5 + 5;

struct Door
{
	int t;
	char op「4];
	Door() {}
};

int n, m, ans;
Door a「maxn];

inline void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a「i].op >> a「i].t;
	
	for (int j = 30; j >= 0; --j)
	{
		int c1 = (1 << j), c0 = 0;
		for (int i = 1; i <= n; ++i)
		{
			int qwq = (a「i].t & (1 << j));
			if(a「i].op「0] == 'A') 
				c1 &= qwq, c0 &= qwq;
			if(a「i].op「0] == 'O') 
				c1 |= qwq, c0 |= qwq;
			if(a「i].op「0] == 'X') 
				c1 ^= qwq, c0 ^= qwq;
		}
		c1 >>= j, c0 >>= j;
		if(c0) ans += (1 << j);
		else if(c1 && (1 << j) <= m) ans += (1 << j), m -= (1 << j);
	}

	cout << ans << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	QCKNZHZ::solve();
}