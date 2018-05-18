#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#define R register
#define IN inline
#define gc getchar()
#define W while
#define MX 500005
#define ls tree[k << 1]
#define rs tree[k << 1 | 1] 
using namespace std;
template <typename T>
IN void in (T &x)
{
	x = 0; R char c =gc;
	W (!isdigit(c))c = gc;
	W (isdigit(c))
	{x = (x << 1) + (x << 3), x += c - 48, c = gc;}
}

struct Edge
{
	int nex, to;
}edge[MX];
struct Node
{
	int lef, rig, del, val, siz;
}tree[MX]; 
int dep[MX], top[MX], son[MX], head[MX], father[MX], size[MX], idx[MX];
int pre[MX], deal[MX];
int cnt/*to arrange the edge*/, id/*to arrange the tree node*/, MOD, dot, q, root;
IN void addedge(const int &from, const int &to)
{
	edge[++cnt] = (Edge){head[from], to};
	head[from] = cnt;
}
int dfs1(int k, int fa, int deep)
{
	dep[k] = deep;
	father[k] = fa;
	size[k] = 1;
	int ms = -1;
	for (int i  = head[k]; i; i = edge[i].nex)
	{
		if(edge[i].to == fa) continue;
		size[k] += dfs1(edge[i].to, k, deep + 1);
		if (size[edge[i].to] > ms) ms = size[edge[i].to], son[k] = edge[i].to;
	}
	return size[k];
}
void dfs2(int k, int topf)
{
	idx[k] = ++id;
	deal[idx[k]] = pre[k];
	top[k] = topf;
	if(!son[k]) return;
	dfs2(son[k], topf);
	for (R int i = head[k]; i; i = edge[i].nex)
	{
		if(!idx[edge[i].to]) 
		dfs2(edge[i].to, edge[i].to);
	}
}
IN void pushup(const int &k)
{
	tree[k].val = (ls.val + rs.val + MOD) % MOD;
}
void build(int k, int l, int r)
{
	tree[k].lef = l, tree[k].rig = r, tree[k].siz = r - l + 1;
	if(l == r) {tree[k].val = deal[l];return;}
	int mid = (l + r) >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
IN void pushdown(const int &k)
{
	if (!tree[k].del) return;
	ls.val += tree[k].del * ls.siz; ls.val %= MOD;
	rs.val += tree[k].del * rs.siz; rs.val %= MOD;
	ls.del += tree[k].del; ls.del %= MOD;
	rs.del += tree[k].del; rs.del %= MOD;
	tree[k].del = 0;
}
void add(const int &k, const int &lb, const int &rb, const int &delta)
{
	if(tree[k].lef >= lb && tree[k].rig <= rb)
	{
		tree[k].del += delta;
		tree[k].val += tree[k].siz * delta;
		return;
	}
	pushdown(k);
	int mid = (tree[k].lef + tree[k].rig) >> 1;
	if(lb <= mid) add(k << 1, lb, rb, delta);
	if(rb > mid) add(k << 1 | 1, lb, rb, delta);
	pushup(k);
}
int query(const int &k, const int &lb, const int &rb)
{
	int ans = 0;
	if(tree[k].lef >= lb && tree[k].rig <= rb) return tree[k].val;
	pushdown(k);
	int mid = (tree[k].lef + tree[k].rig) >> 1;
	if(lb <= mid) ans += query(k << 1, lb, rb) % MOD;
	ans %= MOD;
	if(rb > mid) ans += query(k << 1 | 1, lb, rb) % MOD;
	ans %= MOD;
	return ans;
}
IN void tree_add(int x, int y, const int &delta)
{
	W (top[x] != top[y])
	{
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		add(1, idx[top[x]], idx[x], delta);
		x = father[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	add(1, idx[x], idx[y], delta);
}
IN int tree_sum(int x, int y)
{
	R int rt = 0;
	W (top[x] != top[y])
	{
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		rt = (rt + query(1, idx[top[x]], idx[x])) % MOD;
		x = father[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	rt = (rt + query(1, idx[x], idx[y])) % MOD;
	return rt;
}
int main()
{
	int a, b, c, command;
	in(dot), in(q), in(root), in(MOD);
	for (R int i = 1; i <= dot; ++i) in(pre[i]);  
	for (R int i = 1; i < dot; ++i)
	{
		in(a), in(b);
		addedge(a, b), addedge(b, a);
	}
	dfs1(root, 0, 1);
	dfs2(root, root);
	build(1, 1, dot);
	W (q--)
	{
		in(command);
		switch (command)
		{
			case 1:
			{
				in(a), in(b), in(c);
				tree_add(a, b, c % MOD);
				break;
			}
			case 2:
			{
				in(a), in(b);
				printf("%d\n", tree_sum(a, b) % MOD);
				break;
			}
			case 3:
			{
				in(a), in(b);
				add(1, idx[a], idx[a] + size[a] - 1, b % MOD);
				break;
			}
			case 4:
			{
				in(a);
				printf("%d\n", query(1, idx[a], idx[a] + size[a] - 1) % MOD);
			}
		}
	}
	return 0;
}