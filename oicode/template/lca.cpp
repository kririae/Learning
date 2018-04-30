#pragma GCC optimize("Ofast")
// by kririae
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

namespace lca
{
const int maxn = 500005;

struct Edge
{
	int to, val;
	Edge() {}
	Edge(int t, int v) : to(t), val(v) {}
};

int n, m, s, x, y, a, b, t, d[maxn], dist[maxn], f[maxn][20];
int ver[maxn << 1], Next[maxn << 1], head[maxn << 1], tot;
queue<int> q;

inline void addedge(int from, int to)
{
	ver[++tot] = to, Next[tot] = head[from], head[from] = tot;
}

inline void bfs(int k)
{
	q.push(k), d[k] = 1;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int i = head[i]; i; i = Next[i])
		{
			to = ver[i];
			if (d[to]) continue;
			d[to] = d[curr] + 1;
			dist[to] = dist[curr] + e.val;
			f[to][0] = curr;
			for (int j = 1; j <= t; ++j)
				f[to][j] = f[f[to][j - 1]][j - 1];
			q.push(to);
		}
	}
}

inline int lca(int x, int y)
{
	if (d[x] > d[y]) swap(x, y);
	// adjust depth
	for (int i = t; i >= 0; --i)
		if(d[f[y][i]] >= d[x]) y = f[y][i];
	if(x == y) return x;
	for (int i = t; i >= 0; --i)
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

inline void solve()
{
	using namespace IO;
	read(n); read(m); read(s);
	t = log(n) / log(2) + 1;
	for (int i = 1; i < n; ++i)
	{
		read(x); read(y);
		addedge(x, y);
		addedge(y, x);
	}

	bfs(s);

	for (int i = 1; i <= m; ++i)
	{
		read(a); read(b);
		cout << lca(a, b) << endl;
	}
}
}

int main()
{
	lca::solve();
	return 0;
}