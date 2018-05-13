// by kririae
#define ls t[k].son[0]
#define rs t[k].son[1]
#define pls t[pre].son[0]
#define prs t[pre].son[1]
#define mid ((l + r) >> 1)
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

namespace Count_on_a_tree
{
const int maxn = 100005;

struct Node
{
	int son[2];
	long long sum;
};

Node t[maxn * 20];
int root, cnt, t[maxn];
int n, m, x, y, sz, lastans;
int a[maxn], b[maxn], dep[maxn], fa[maxn], siz[maxn], id[maxn], id2[maxn];
vector<int> edges[maxn];

inline void addedge(int from, int to)
{
	edges[from].push_back(to);
	edges[to].push_back(from);
}

inline int build(int l, int r)
{
	int k = ++cnt;
	if(l < r)
		ls = build(l, mid),
		rs = build(mid + 1, r);
	return k;
}

inline int update(int pre, int l, int r, int val)
{
	int k = ++cnt;
	ls = pls, rs = prs, t[k].sum = t[pre].sum + 1;
	if(l < r)
	{
		if(val <= mid) ls = update(pls, l, mid, val);
		else rs = update(prs, mid + 1, r, val);
	}
	return k;
}

inline void dfs1(int k)
{
		dep[k] = dep[fa[k]] + 1, id[++tot] = k, id2[k] = tot;
		for (int i = 0; i < edges[k].size(); ++i)
			dfs1(edges[k][i]);
}

inline void dfs2(int k)
{
	root[k] = update(fa[k], 1, sz, lower_bound(b + 1, b + 1 + sz, a[k]) - b);
	for (int i = 0; i < edges[k].size(); ++i) if(edges[k][i] != fa[k])
		dfs2(edges[k][i]);
}

inline void solve()
{
	using namespace IO;
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		read(a[i]), b[i] = a[i];

	sort(b + 1, b + 1 + n);
	sz = unique(b + 1, b + 1 + n) - b - 1;

	root[0] = build(1, sz);

	for (int i = 1; i < n; ++i)
		read(x), read(y), addedge(x, y), fa[y] = x;

	dfs1(1), dfs2(1);

}
}