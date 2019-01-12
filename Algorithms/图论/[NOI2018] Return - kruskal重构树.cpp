/*
概括一下的话。
一个无向连通图中，每个边有两个值：$a, b$。
有$Q$和询问，给出$v, p$。表示从$v$开始， 经过$b >= p$的边后，到$1$的距离最小值。
详见$BZOJ3551$，强制在线$ver$的$BZOJ3545$。
这道题，从$BZOJ3551$转化一下，从$1$，建反向图，跑出到每个点的最短路。记为$f_i$。作为$BZOJ3551$中的$h_i$使用，只是这里是“最小值”。
概括一下，就变成了这样：
无向连通图中，每个边有权值$a$。每个点有权值$d$。有$Q$组询问，给出$v$和$p$。求从$v$开始，只经过边权$>= p$的边，到达的点权$d$的最小值是多少。
首先考虑离线的$65$分。我们对所有询问用$a$排序，然后按照最小生成树的思维加入。每次加入的时候，维护联通块中的$d$的最小值。然后获取$v$所在的联通块的$d$的最小值作为答案。
接下来我们考虑`kruskal重构树`的思想。强制在线没法排序啊，我们就先对边进行排序，然后进行合并。合并的时候加上一步操作，加上一个新的点，然后把新的点作为下面的联通块的总结。并且，新加入的点的点权是加入的边的边权。在并查集重构出来的树上，我们预处理出倍增数组$f[i][j]$。倍增向上跳到$>= p$的最小值。然后，可以发现，对于任意一个点，其子树是当前状态下能够走到的点，然后进行$dfs$序上的查询$d$的最小值就好。
 */
/*
代码留坑~
 */
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

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

namespace Return
{
int head[maxn], next[maxn << 1], ver[maxn << 1], l[maxn << 1], a[maxn << 1], tot;
int n, m, q, k, s, fa[maxn];

inline void addedge(int _u, int _v, int _l, int _a)
{
	ver[++tot] = _v, l[tot] = _l, a[tot] = _a, next[tot] = head[_u], head[_u] = tot;
}

inline int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void solve()
{
	using namespace IO;
	n = read(), m = read();
	R int u, v, l, a, v0, p0;
	for (R int i = 1; i <= m; ++i)
		u = read(), v = read(), l = read(), a = read(),
		addedge(u, v, l, a), addedge(v, u, l, a);
	q = read(), k = read(), s = read();
	for (R int i = 1; i <= q; ++i)
	{
		v0 = read(), p0 = read();
		v0 = (v0 + k * lastans - 1) % n + 1;
		p0 = (p0 + k * lastans) % (s + 1);
		printf("%d\n", query(v0, p0));
	}
}
}

int main()
{
	return Return::solve(), 0;
}