#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char read()
{
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
	return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
	static char c;
	static bool iosig;
	for (c = read(), iosig = false; !isdigit(c); c = read())
	{
		if (c == -1) return;
		c == '-' ? iosig = true : 0;
	}
	for (x = 0; isdigit(c); c = read())
		x = (x + (x << 2) << 1) + (c ^ '0');
	iosig ? x = -x : 0;
}
}

namespace Struck
{
const int maxn = 10005;

struct Edge
{
	int from, to, val;
	Edge() {}
	Edge(int f, int t, int v) : from(f), to(t), val(v) {}
	bool operator < (const Edge &e) const 
	{ return val > e.val; }
};

vector<Edge> edges[maxn], graph;
int n, m, x, y, z, t, qi;
int father[maxn], d[maxn], dist[maxn][20], f[maxn][20];
queue<int> q;

inline int find(int val)
{
	return father[val] == val ? father[val] : father[val] = find(father[val]);
}

inline void addedge(int from, int to, int val)
{
	edges[from].push_back(Edge(from, to, val));
	edges[to].push_back(Edge(to, from, val));
}

inline void Kruskal()
{
	for (int i = 0; i <= n; ++i)
		father[i] = i;
	sort(graph.begin(), graph.end());
	for (int i = 0; i < graph.size(); ++i)
	{
		Edge &e = graph[i];
		int a = find(e.from), b = find(e.to);
		if(a == b) continue;
		father[a] = b, addedge(e.from, e.to, e.val);
	}
}

inline void bfs(int k)
{
	d[k] = 1; q.push(k);
	while(!q.empty())
	{
		int curr = q.front(); q.pop();
		for (int i = 0; i < edges[curr].size(); ++i)
		{
			Edge &e = edges[curr][i];
			if(d[e.to]) continue;
			d[e.to] = d[e.from] + 1;
			dist[e.to][0] = e.val;
			f[e.to][0] = e.from;
			q.push(e.to);
		}
	}
	
	for (int j = 1; (1 << j) <= n; ++j)
		for (int i = 1; i <= n; ++i)
			f[i][j] = f[f[i][j - 1]][j - 1],
			dist[i][j] = min(dist[i][j - 1], dist[f[i][j - 1]][j - 1]);
}

inline int lca(int a, int b)
{
	int ans = 1e9;
	if(find(a) != find(b)) return -1;
	if(d[a] > d[b]) swap(a, b);
	for (int i = t; i >= 0; --i)
		if(d[f[b][i]] >= d[a]) b = f[b][i], ans = min(ans, dist[b][i]);
	if(a == b) return ans;
	for (int i = t; i >= 0; --i)
		if(f[a][i] != f[b][i]) a = f[a][i], b = f[b][i], ans = min(ans, dist[a][i]), ans = min(ans, dist[b][i]);
	return min(ans, min(dist[a][0], dist[b][0]));
}

inline void solve()
{
	freopen("struck.txt", "r", stdin);
	memset(dist, 0x3f, sizeof(dist));
	using namespace IO;
	read(n); read(m);
	t = log(n) / log(2) + 1;
	for (int i = 1; i <= m; ++i)
	{
		read(x); read(y); read(z);
		graph.push_back(Edge(x, y, z));
	}

	Kruskal();
	
	for (int i = 1; i <= n; ++i) 
		if(find(i) != i)
			bfs(i);

	read(qi);
	for (int i = 1; i <= qi; ++i)
	{
		read(x); read(y);
		cout << lca(x, y) << endl;
	}
}
}

int main(int argc, char const *argv[])
{
	Struck::solve();
	return 0;
}