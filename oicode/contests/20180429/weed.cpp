#define ls t[k].son[0]
#define rs t[k].son[1]
#include <bits/stdc++.h>

using namespace std;

namespace Weed
{
const int maxn = 200005;

vector<pair<int, int> > a;
int m, q, k, vi, ci;
long long tot;

inline void work()
{
	tot = 0;
	stack<long long> s;
	for (int i = 0; i < a.size(); ++i)
	{
		if(a[i].first == 0)
		{
			s.push(a[i].second);
			tot += a[i].second;
		}

		if(a[i].first == 1)
		{
			for (int j = 1; j <= a[i].second && s.size() > 0; ++j)
			{
				tot -= s.top();
				s.pop();
			}
		}
	}
}

inline void solve()
{
	freopen("weed.in", "r", stdin);
	freopen("weed.out", "w", stdout);
	cin >> m >> q;
	for (int i = 1; i <= m; ++i)
	{
		cin >> k >> vi;
		a.push_back(make_pair(k, vi));
	}
	
	for (int i = 1; i <= q; ++i)
	{
		cin >> ci >> k >> vi;
		a[ci - 1].first = k, a[ci - 1].second = vi;
		work();
		cout << tot << endl;
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	Weed::solve();
	return 0;
}
