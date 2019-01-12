#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char gc()
{
	static char buf[1 << 18], *fs, *ft;
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

namespace BZOJ1922
{
struct Edge
{
	int from, to, val;

	Edge() {}
	Edge(int _f, int _t, int _v) : from(_f), to(_t), val(_v) {}
};
vector<Edge> edges[maxn];
vector<int> mt[maxn];
queue<int> q;
bitset<maxn> vis;
int n, m, _u, _v, _w, li, dis[maxn];

inline void addedge(int from, int to, int val)
{
	edges[from].push_back(Edge(from, to, val));
}

inline void SPFA()
{
	memset(dis, 0x3f, sizeof(dis)), vis.reset();
	dis[1] = 0, vis[1] = 1, q.push(1);
	while(!q.empty())
	{
		int curr = q.front(); q.pop(), vis[curr] = 0;
		for (R int i = 0; i < edges[curr].size(); ++i)
		{
			Edge &e = edges[curr][i];
			if(dis[e.to] > dis[curr] + e.val)
			{
				nxt[curr] = e.to, dis[e.to] = dis[curr] + e.val;
				if(!vis[e.to]) vis[e.to] = 1, q.push(e.to);
			}
		}
	}
}

inline void solve()
{
	n = read(), m = read();
	for (R int i = 1; i <= m; ++i)
		_u = read(), _v = read(), _w = read(), addedge(_u, _v, _w);
	for (R int i = 1; i <= n; ++i)
		for (R int j = read(); j >= 1; --j)
			mt.push_back(read());
	SPFA();

}
}

int main()
{

}