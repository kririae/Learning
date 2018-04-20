#include <bits/stdc++.h>

using namespace std;

namespace YSRC
{
const int maxn = 550;
const int g1[4] {-1, 0, 1, 0}, g2[4] {0, 1, 0, -1};

int n, m, a[maxn][maxn], f[maxn][maxn];
pair<int, int> r[maxn];

inline bitset<maxn> bfs(int k)
{
	static deque<pair<int, int>> q;
	static bitset<maxn> vis[maxn];

	for (int i = 0; i < maxn; ++i)
		vis[i].reset();

	q.push_back(make_pair(1, k));
	vis[1][k] = 1;

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop_front();
		vis[p.first][p.second] = 1;

		for (int j = 0; j < 4; ++j)
		{
			int x = p.first + g1[j], y = p.second + g2[j];

			if (x < 1 || x > n || y < 1 || y > m)
				continue;

			if (a[x][y] >= a[p.first][p.second] || vis[x][y])
				continue;

			q.push_back(make_pair(x, y));
		}
	}

	q.clear();
	return vis[n];
}

inline pair<int, int> range(bitset<maxn> k)
{
	pair<int, int> ans;

	for (int i = 1; i <= m; ++i)
		if (k[i]) ans.first = i, i = m + 1;

	for (int i = m; i >= 1; --i)
		if (k[i]) ans.second = i, i = 0;

	return ans;
}

inline pair<int, int> solve1()
{
	int cnt = 0;
	bitset<maxn> ret;

	for (int i = 1; i <= m; ++i)
	{
		bitset<maxn> tmp = bfs(i);
		ret |= tmp;
		pair<int, int> curr = range(tmp);

		if (curr.first != 0 && curr.second != 0) r[++cnt] = curr;
	}

	if (ret.count() != m) return make_pair(0, m - ret.count());

	sort(r + 1, r + 1 + cnt);

	int all = 0;
	for (int i = 1; i <= cnt; ++i)
	{
		int tmp = i;
		++all;

		for (int j = i + 1; j <= cnt; ++j)
			if (r[j].first <= r[i].second) tmp = j;

		i = tmp;
	}

	return make_pair(1, all + 1);
}

inline void solve()
{
	memset(a, 0x3f, sizeof(a));

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];

	pair<int, int> ans = solve1();
	cout << ans.first << endl << ans.second << endl;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	YSRC::solve();
	return 0;
}