// by kririae
#include <bits/stdc++.h>

using namespace std;

namespace luogu1156
{
const int maxn = 100 + 5;

struct Obj
{
	int t, f, h;
	Obj() {}
	Obj(int tt, int ff, int hh) : t(tt), f(ff), h(hh) {}

	bool operator < (const Obj &a) const 
	{ return t < a.t; }
};

int D, G, f[maxn][maxn];
Obj a[maxn];

inline void solve()
{
	cin >> D >> G;

	for (int i = 1; i <= G; ++i)
		cin >> a[i].t >> a[i].f >> a[i].h;
		
	sort(a + 1, a + 1 + G);

	for (int i = 1; i <= G; ++i)
	{
		for (int j = D; j >= 0; --j)
		{
			// 如果上一个的时间不足以到达当前状态 continue
			if(f[i - 1][j] < a[i].t - a[i - 1].t) continue;

			if(j + a[i].h < d)
			{
				f[i][j + a[i].h] = max(f[i][j + a[i].h], f[i - 1][j] - (a[i].t - a[i - 1].t));
				f[i][j] = max(f[i][j], f[i - 1][j] + a[i].f - (a[i].t - a[i - 1].t));
			} else {
				cout << a[i].t << endl;
				return;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= G; ++i)
		ans = max(f[i][0] + a[i].t, ans);

	cout << ans << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	luogu1156::solve();
	return 0;
}