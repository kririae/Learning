#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

namespace AngryBird
{
const int maxn = 18;
const double eps = 1e-7;

int t, n, m;
double ta, tb;
int d[1 << maxn], shoot[18 * 18 + 5];
bitset<1 << maxn> vis;
vector<pair<double, double>> pigs, birds;
deque<int> q;

inline bool eql(double a, double b)
{
	return fabs(a - b) < eps;
}

inline pair<double, double> equation(double x1, double y1, double x2, double y2)
{
	double a = (x1 * y2 - x2 * y1) / (x2 * x2 * x1 - x1 * x1 * x2);
	double b = (-a * x1 * x1 + y1) / x1;
	return make_pair(a, b);
}

inline bool on(pair<double, double> p, pair<double, double> b)
{
	return eql(b.first * p.first * p.first + b.second * p.first, p.second);
}

inline void init()
{
	memset(d, 0x3f, sizeof(d));
	q.clear();
	pigs.clear();
	birds.clear();
	memset(shoot, 0, sizeof(shoot));
}

inline void solve()
{
	cin >> t;
	while (t--)
	{
		init();
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			cin >> ta >> tb;
			pigs.push_back(make_pair(ta, tb));
		}

		for (int i = 0; i < pigs.size(); ++i)
			for (int j = i + 1; j < pigs.size(); ++j)
			{
				pair<double, double> res = equation(pigs[i].first, pigs[i].second, pigs[j].first, pigs[j].second);
				if (res.first > 0)
					continue;
				birds.push_back(res);
			}

		int all = 0;
		q.push_back(0);
		d[0] = 0;

		for (int i = 0; i < birds.size(); ++i)
			for (int j = 0; j < pigs.size(); ++j)
				if (on(pigs[j], birds[i]))
					shoot[i] |= (1 << j);

		vis[0] = 1;
		while (!q.empty())
		{
			int curr = q.front();
			q.pop_front();
			vis[curr] = 0;
			for (int i = 0; i < birds.size(); ++i)
			{
				int to = curr | shoot[i];
				all = max(all, to);
				if (d[curr] + 1 <= d[to])
				{
					d[to] = d[curr] + 1;
					if (!vis[to])
					{
						vis[to] = 1;
						q.push_back(to);
					}
				}
			}
		}

		cout << ((d[(1 << n) - 1] == 0x3f3f3f3f) ? d[all] + n - __builtin_popcount(all) : d[(1 << n) - 1]) << endl;
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	AngryBird::solve();
	return 0;
}