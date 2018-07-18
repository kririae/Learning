// #define DEBUG
#define ll long long
#define R register
#define ls t[k].son[0]
#define rs t[k].son[1]
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

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

namespace Template
{
struct Node
{
  int l, r, son[2];
  ll sum, add;
  Node() {}
} t[maxn << 1];
int head[maxn], ver[maxn << 1], next[maxn << 1], tot;
int siz[maxn], top[maxn], fa[maxn], son[maxn], dep[maxn], id[maxn], wt[maxn], w[maxn], cnt, tcnt;
int n, m, r, p, root;

template<typename T>
inline void inc(T &a, T b)
{
  a = (1ll * a + b) % p;
}

inline void addedge(R int from, R int to)
{
  ver[++tot] = to, next[tot] = head[from], head[from] = tot;
}

inline void dfs1(R int k)
{
  siz[k] = 1, son[k] = 0;
  for (R int i = head[k]; i; i = next[i])
  {
    R int to = ver[i];
    if(to == fa[k]) continue;
    fa[to] = k, dep[to] = dep[k] + 1;
    dfs1(to);
    if(siz[to] > siz[son[k]]) son[k] = to;
    siz[k] += siz[to];
  }
}

inline void dfs2(R int k, R int topf)
{
  id[k] = ++tcnt, wt[tcnt] = w[k], top[k] = topf;
  if(!son[k]) return;
  dfs2(son[k], topf);
  for (R int i = head[k]; i; i = next[i])
  {
    R int to = ver[i];
    if(to == fa[k] || to == son[k]) continue;
    dfs2(to, to);
  }
}

inline void pushup(R int k)
{
  t[k].sum = (t[ls].sum + t[rs].sum) % p;;
}

inline void pushdown(R int k)
{
  if(t[k].add)
  {
    inc(t[ls].add, t[k].add), inc(t[rs].add, t[k].add);
    inc(t[ls].sum, t[k].add * (t[ls].r - t[ls].l + 1));
    inc(t[rs].sum, t[k].add * (t[rs].r - t[rs].l + 1));
    t[k].add = 0;
  }
}

inline void build(int &k, R int l, R int r)
{
  k = ++cnt, t[k].l = l, t[k].r = r;
  if(l == r) return t[k].sum = wt[l], void();
  R int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}

inline void addrange(R int k, R int l, R int r, R int val)
{
  if(t[k].l == l && t[k].r == r)
    return inc(t[k].add, (ll)val), inc(t[k].sum, 1ll * val * (r - l + 1)), void();
  pushdown(k);
  R int mid = (t[k].l + t[k].r) >> 1;
  if (r <= mid) addrange(ls, l, r, val);
  else if (l > mid) addrange(rs, l, r, val);
  else addrange(ls, l, mid, val), addrange(rs, mid + 1, r, val);
  pushup(k);
}

inline ll queryrange(R int k, R int l, R int r)
{
  if(t[k].l == l && t[k].r == r)
    return t[k].sum;
  pushdown(k);
  R int mid = (t[k].l + t[k].r) >> 1;
  if(r <= mid) return queryrange(ls, l, r) % p;
  else if (l > mid) return queryrange(rs, l, r) % p;
  else return (queryrange(ls, l, mid) % p + queryrange(rs, mid + 1, r) % p) % p;
}

inline ll querytree(int x, int y)
{
  R ll ans = 0, tmp = 0;
  while(top[x] != top[y])
  {
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    tmp = queryrange(root, id[top[x]], id[x]);
    inc(ans, tmp);
    x = fa[top[x]];
  }
  if(dep[x] > dep[y]) swap(x, y);
  inc(ans, queryrange(root, id[x], id[y]));
  return ans;
}

inline void modifytree(int x, int y, int val)
{
  val %= p;
  while(top[x] != top[y])
  {
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    addrange(root, id[top[x]], id[x], val);
    x = fa[top[x]];
  }
  if(dep[x] > dep[y]) swap(x, y);
  addrange(root, id[x], id[y], val);
}

inline ll querysubtree(int x)
{
  return queryrange(root, id[x], id[x] + siz[x] - 1);
}

inline void modifysubtree(int x, int val)
{
  addrange(root, id[x], id[x] + siz[x] - 1, val % p);
}

inline void solve()
{
  // freopen("QAQ.txt", "r", stdin);
  using namespace IO;
  n = read(), m = read(), r = read(), p = read();
  for (R int i = 1; i <= n; ++i) w[i] = read();
  R int x, y, z, op;
  for (R int i = 1; i < n; ++i)
    x = read(), y = read(), addedge(x, y), addedge(y, x);
  dfs1(r), dfs2(r, r);
  build(root, 1, n);
  for (R int i = 1; i <= m; ++i)
  {
    op = read();
    switch(op)
    {
      case 1: x = read(), y = read(), z = read(), modifytree(x, y, z); break;
      case 2: x = read(), y = read(), printf("%lld\n", querytree(x, y)); break;
      case 3: x = read(), z = read(), modifysubtree(x, z); break;
      case 4: x = read(), printf("%lld\n", querysubtree(x)); break;
    }
  }
#ifdef DEBUG
  for (R int i = 1; i <= n; ++i)
    printf("id: %d -> son: %d\n", i, top[i]);
  for (R int i = 1; i <= n; ++i) 
    printf("node_id: %d -> node.sum: %d\n", i, t[i].sum);
#endif
}
}

int main()
{
  return Template::solve(), 0;
}

/*
6 1 1 1000000
1 10 100 1000 10000 100000
1 2
1 3
2 4
2 5
2 6
2 1 6
 */