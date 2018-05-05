// by kririae
// 树形dp（模板题？）
#include <bits/stdc++.h>

using namespace std;

namespace luogu1273
{
const int maxn = 3005;

struct Edge
{
	int from, to, val;
	Edge() {}
	Edge(int f, int t, int v) : from(f), to(t), val(v) {}
};

int n, m, k, ai, c, a[maxn], f[maxn][maxn], siz[maxn];
vector<Edge> edges[maxn];

inline void addedge(int from, int to, int val)
{
	edges[from].push_back(Edge(from, to, val));
// 	edges[to].push_back(Edge(to, from, val));
}

inline void dp(int k)
{
	f[k][0] = 0;
	if(!edges[k].size()) 
			return f[k][1] = a[k], siz[k] = 1, void();
	
	for (int i = 0; i < edges[k].size(); ++i)
	{
		Edge &e = edges[k][i];
				dp(e.to);
		for (int j = siz[k]; j >= 0; --j)
			for (int l = siz[e.to]; l >= 0; --l)
					f[k][j + l] = max(f[k][j + l], f[k][j] + f[e.to][l] - e.val); 
		siz[k] += siz[e.to];
	}
}

inline void solve()
{
		memset(f, ~0x3f, sizeof(f));
		
	cin >> n >> m;
	for (int i = 1; i <= (n - m); ++i)
	{
		cin >> k;
		for (int j = 1; j <= k; ++j)
		{
			cin >> ai >> c;
			addedge(i, ai, c);
		}
	}

		// for (int i = 1; i <= n; ++i)
		// cin >> a[i];
		
		for (int i = (n - m + 1); i <= n; ++i)
				cin >> a[i];
				
	dp(1);

	for (int i = m; i > 0; --i)
		if(f[1][i] >= 0)
			return cout << i << endl, void();
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	luogu1273::solve();
	return 0;
}