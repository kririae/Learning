// by kririae
#define ll long long
#define R register
#define ls t[k].son[0]
#define rs t[k].son[1]
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

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

namespace NOIP2013
{
struct Node
{
  int l, r, son[2], min;
  ll sum;
} t[maxn << 2];
struct Edge
{
  int from, to, val;
  Edge() {}
  Edge(int _f, int _t, int _v) : 
  from(_f), to(_t), val(_v) {}
  bool operator < (const Edge &e) const 
  {
    return val > e.val;
  }
} edges[maxn];
int head[maxn], vert[maxn << 1], verf[maxn << 1], next[maxn << 1], val[maxn << 1], tot;
int siz[maxn], son[maxn], fa[maxn], w[maxn], wt[maxn], dep[maxn], id[maxn], top[maxn], tcnt;
int n, m, x, y, z, q, root, cnt, father[maxn], seq[maxn];
bitset<maxn> vis;

inline void pushup(int k)
{
  t[k].sum = t[ls].sum + t[rs].sum;
  t[k].min = min(t[ls].min, t[rs].min);
}
inline void build(int &k, int l, int r)
{
  k = ++cnt, t[k].l = l, t[k].r = r;
  if(l == r) return t[k].min = t[k].sum = wt[l], void();
  R int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(k);
}
inline int query(int k, int l, int r)
{
  if(l > r) return swap(l, r), 1e9;
  if(t[k].l == l && t[k].r == r)
    return t[k].min;
  R int mid = t[k].l + t[k].r >> 1;
  if(r <= mid) return query(ls, l, r);
  else if(l > mid) return query(rs, l, r);
  else return min(query(ls, l, mid), query(rs, mid + 1, r));
}
inline void addedge(int u, int v, int w)
{
  vert[++tot] = v, verf[tot] = u, val[tot] = w;
  next[tot] = head[u], head[u] = tot;
}
inline int find(int x)
{
  // cout << x << endl;
  return x == father[x] ? x : father[x] = find(father[x]);
}
inline void kruskal()
{
  memset(father, 0, sizeof(father));
  for (R int i = 0; i <= n; ++i) father[i] = i;
  sort(edges + 1, edges + 1 + m);
  for (R int i = 1; i <= m; ++i)
  {
    int a = find(edges[i].from), b = find(edges[i].to);
    if(a != b)
    {
      father[a] = b;
      addedge(edges[i].from, edges[i].to, edges[i].val);
      addedge(edges[i].to, edges[i].from, edges[i].val);
    }
  }
}
inline void dfs1(int k)
{
  siz[k] = 1, son[k] = 0, vis[k] = 1;
  for (R int i = head[k]; i; i = next[i])
  {
    R int to = vert[i];
    if(to == fa[k]) continue;
    fa[to] = k, dep[to] = dep[k] + 1, w[to] = val[i]; 
    // 边和点的对应处理可能会WA
    dfs1(to);
    if(siz[to] > siz[son[k]]) son[k] = to;
    siz[k] += siz[to];
  }
}
inline void dfs2(int k, int topf)
{
  id[k] = ++tcnt, wt[tcnt] = w[k], top[k] = topf;
  if(!son[k]) return; 
  dfs2(son[k], topf);
  for (R int i = head[k]; i; i = next[i])
  {
    R int to = vert[i];
    if(to == fa[k] || to == son[k]) continue;
    dfs2(to, to);
  }
}
inline int qtree(int x, int y)
{
  R int ans = 1e9;
  while(top[x] != top[y])
  {
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    ans = min(ans, query(root, id[top[x]], id[x]));
    x = fa[top[x]];
  }
  if(dep[x] > dep[y]) swap(x, y);
  // cout << query(root, id[x] + 1, id[y]) << endl;1
  ans = min(ans, query(root, id[x] + 1, id[y]));
  return ans;
}
inline void init()
{
  using namespace IO;
  memset(wt, 0x3f, sizeof(wt));
  memset(w, 0x3f, sizeof(w));
  n = read(), m = read();
  for (R int i = 1; i <= m; ++i)
    edges[i].from = read(), edges[i].to = read(), edges[i].val = read();
  kruskal();
  for (R int i = 1; i <= n; ++i) if(!vis[i]) dfs1(i), dfs2(i, i);
  build(root, 1, n);
}
inline void solve()
{
  using namespace IO;
  init();
  q = read();
  for (R int i = 1; i <= q; ++i)
  {
    x = read(), y = read();
    if(find(x) != find(y)) puts("-1");
    else printf("%d\n", qtree(x, y));
  }
}
}

int main()
{
  return NOIP2013::solve(), 0;
}