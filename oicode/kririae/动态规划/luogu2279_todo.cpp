// by kririae
#include <bits/stdc++.h>

using namespace std;

namespace HNOI2003
{
const int maxn = 1000 + 5;

vector<int> edges[maxn];

inline void addedge(int from, int to)
{
	edges[from].push_back(to);
	edges[to].push_back(from);
}

int n, ai, f[maxn][2][2][2][2][2], fa[maxn];
// f[i][1/0][1/0] 后面二维的数据压缩前两个父节点的信息

inline void dp(int k)
{
	

	for (int i = 0; i < edges[k].size(); ++i)
		dp(edges[k][i]);
}

inline void solve()
{
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		cin >> ai;
		addedge(i, ai);
		fa[ai] = i;
		fa[i] = ai;
	}
	
	int rt = 1;
    f[rt][0][1] = 1;
    f[rt][1][0] = 1;
    f[rt][1][1] = 1;
    f[rt][0][0] = 1;
	dp(rt);
	
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	HNOI2003::solve();
	return 0;
}