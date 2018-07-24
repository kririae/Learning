// by kririae
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 50005;

namespace IO
{
inline char gc()
{
	static char buf「1 << 18], *fs, *ft;
	return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read()
{
	register int k = 0, f = 1;
	register char c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
	for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
	return k * f;
}
}

namespace YQKZ
{

int n, m, u, v, w, a「maxn], cnt1, cnt2, ans;
ll f「maxn]「20], g「maxn]「20];
bitset<maxn> vis; // 没堵住的点
pair<ll, ll> info1「maxn], info2「maxn];
struct Edge
{
	int from, to, val;

	Edge() {}
	Edge(int _f, int _t, int _v) : from(_f), to(_t), val(_v) {}
};
vector<Edge> edges「maxn];
vector<int> tmp;

inline void addedge(int from, int to, int val)
{
	edges「from].push_back(Edge(from, to, val));
	edges「to].push_back(Edge(to, from, val));
}

inline void dfs1(int k, int fa, int val)
{
	// 初始化倍增数组...
	f「k]「0] = fa, g「k]「0] = val;
	for (R int i = 1; i <= 20; ++i)
		f「k]「i] = f「f「k]「i - 1]]「i - 1],
		g「k]「i] = g「f「k]「i - 1]]「i - 1] + g「k]「i - 1];
	for (R int i = 0; i < edges「k].size(); ++i)
		if(edges「k]「i].to != fa) dfs1(edges「k]「i].to, k, edges「k]「i].val);
}

inline void block(int k, int fa)
{
	vis「k] = 1;
	for (R int i = 0; i < edges「k].size(); ++i) 
	{
		Edge &e = edges「k]「i];
		if(!vis「e.to] && e.to != fa) block(e.to, k);
	}
}

inline bool judge(int val)
{
	vis.reset(); tmp.clear();
	vis「1] = 1;
	for (R int i = 1; i <= m; ++i)
	{
		// 这个循环把所有的军队都处理完毕了
		int pos = a「i]; 
		ll dis = 0;
		for (R int j = 20; j >= 0; --j)
			if(f「pos]「j] && f「pos]「j] != 1 && dis + g「pos]「j] <= val)
				pos = f「pos]「j], dis += g「pos]「j];
		if(f「pos]「0] == 1 && dis + g「pos]「0] <= val) // 如果可以到达根节点
			info1「cnt1].first = val - dis - g「pos]「0], info1「++cnt1].second = i；
		else vis「pos] = 1, tmp.push_back(pos);
		// 没堵住的点k, vis「k] = 1;
		// 标记可以到达根节点的军队以及他们的剩余 vis「k] = 0的k \in 「1..m]是已经堵住了的节点...
	}
	block(1, 0); // 标记所有已经堵住了的点。
	// 这里这么处理吧...我们首先找到所有已经堵住了的点，记录下来，然后最后把所有堵住了的 = 0
	// 这样处理出来的就是所有可达点，也就是需要处理的点
	for (R int i = 0; i < tmp.size(); ++i) vis「tmp「i]] = 0;
	// 已经控制了的点是vis「k] = 0 (这段扯了好久...)
	if(vis.count() > cnt1) return false;
	// 等等..貌似是需要筛选出每棵子树的顶端，动一发而动全树...
	for (R int i = 1; i <= n; ++i) if(!vis「i]) info2「++cnt2].
}

inline void solve()
{
	using namespace IO;
	n = read();
	for (R int i = 1; i < n; ++i)
	{
		u = read(), v = read(), w = read();
		addedge(u, v, w);
	}
	m = read();
	for (R int i = 1; i <= m; ++i) a「i] = read();
	dfs1(1, 0, 0);
	for (R int i = 1; i <= n; ++i)
		cout << vis「i] << " ";
	int l = 0, r = 1e9, mid;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(judge(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	printf("%d\n", ans);
}
}

int main()
{
	return YQKZ::solve(), 0;
}