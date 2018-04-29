#include <bits/stdc++.h>

using namespace std;

namespace Blue
{
const int maxn = 1000005;
int t, n, m, d, l, a[maxn], f[maxn];
bitset<maxn> vis;
int head, tail;
pair<int, int> queue[maxn];
inline void solve()
{
	freopen("blue.in", "r", stdin);
	freopen("blue.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> d >> l;
		for (int i = 1; i <= n; ++i) 
			cin >> a[i];

		a[++n] = l;
		
		if(m == 1)
		{
			for (int i = 1; i <= n; ++i)
			{
				if(a[i] - a[i - 1] > d) 
				{
					cout << 0 << endl;
					return;
				}
			}

			cout << 1 << endl;
			return;
		}

		if(d == l)
		{
			cout << m << endl;
			return;
		}
		
		for (int i = 0; i <= n; ++i)
		{
			for (int j = i - 1; j > 0; --j)
			{
				if(a[i] - a[j] >= d) j = -1;
				else f[i] = max(f[i], f[j] + 1);
			}
		}

		if(f[n] == 0) cout << 0 << endl;
		else if (f[n] - 1 >= m) cout << "Excited" << endl;
		else cout << f[n] - 1 << endl;
		memset(a, 0, sizeof(a));
		memset(f, 0, sizeof(f));
		vis.reset();
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	Blue::solve();
	return 0;
}

