// by kririae
#define R register
#define ll long long
#define ls t「k].son「0]
#define rs t「k].son「1]
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

namespace SHOI2012
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
inline char read_c()
{
  register char c;
  for (c = gc(); isspace(c); c = gc());
  return c;
}
struct Node
{
	int l, r, son「2];
	ll sum, add;
} t「maxn << 2];
int root, n, a, b, q, u, v, d, cnt;
int head「maxn], next「maxn << 1], ver「maxn << 1], tot;
int siz「maxn], son「maxn], fa「maxn], dep「maxn];
int id「maxn], wt「maxn], top「maxn], tcnt;

inline void addedge(int u, int v)
{
	ver「++tot] = v, next「tot] = head「u], head「u] = tot;
}
inline void pushup(int k)
{
	t「k].sum = t「ls].sum + t「rs].sum;
}
inline void pushdown(int k)
{
	if(!t「k].add) return;
	t「ls].add += t「k].add, t「rs].add += t「k].add;
	t「ls].sum += t「k].add * (t「ls].r - t「ls].l + 1), t「rs].sum += t「k].add * (t「rs].r - t「rs].l + 1);
	t「k].add = 0;
}
inline void build(int &k, int l, int r)
{
	k = ++cnt, t「k].l = l, t「k].r = r;
	if(l == r) return t「k].sum = wt「l], void();
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pushup(k);
}
inline void add(int k, int l, int r, int v)
{
	if(t「k].l == l && t「k].r == r) return t「k].sum += (r - l + 1) * v, t「k].add += v, void();
	int mid = t「k].l + t「k].r >> 1;
	pushdown(k);
	if(r <= mid) add(ls, l, r, v);
	else if(l > mid) add(rs, l, r, v);
	else add(ls, l, mid, v), add(rs, mid + 1, r, v);
	pushup(k);
}
inline ll query(int k, int l, int r)
{
	if(t「k].l == l && t「k].r == r) return t「k].sum;
	int mid = t「k].l + t「k].r >> 1;
	pushdown(k);
	if(r <= mid) return query(ls, l, r);
	else if(l > mid) return query(rs, l, r);
	else return query(ls, l, mid) + query(rs, mid + 1, r);
}

inline void dfs1(int k)
{
	siz「k] = 1, son「k] = 0;
	for (R int i = head「k]; i; i = next「i])
	{
		R int to = ver「i];
		if(to == fa「k]) continue;
		fa「to] = k, dep「to] = dep「k] + 1;
		dfs1(to);
		if(siz「to] > siz「son「k]]) son「k] = to;
		siz「k] += siz「to];
	}
}
inline void dfs2(int k, int topf)
{
	id「k] = ++tcnt, wt「tcnt] = 0, top「k] = topf;
	if(!son「k]) return;
	dfs2(son「k], topf);
	for (R int i = head「k]; i; i = next「i])
	{
		R int to = ver「i];
		if(to == fa「k] || to == son「k]) continue;
		dfs2(to, to);
	}
}
inline void atree(int x, int y, ll val)
{
	while(top「x] != top「y])
	{
		if(dep「top「x]] < dep「top「y]]) swap(x, y);
		add(root, id「top「x]], id「x], val);
		x = fa「top「x]];
	}
	if(dep「x] > dep「y]) swap(x, y);
	add(root, id「x], id「y], val);
}
inline ll qsubtree(int x)
{
	return query(root, id「x], id「x] + siz「x] - 1);
}

inline void solve()
{
	freopen("qaq.txt", "r", stdin);
	n = read();
	for (R int i = 1; i < n; ++i) a = read(), b = read(), addedge(a, b), addedge(b, a);
	dfs1(1), dfs2(1, 1), build(root, 1, n);
	R char op;
	for (R int i = read(); i >= 1; --i)
	{
		op = read_c();
		switch(op)
		{
			case 'A': u = read(), v = read(), d = read(), atree(u, v, d); break;
			case 'Q': u = read(), printf("%lld\n", qsubtree(u)); break;
		}
	}
}
}

int main()
{
	return SHOI2012::solve(), 0;
}
