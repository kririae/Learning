#include <bits/stdc++.h>
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

struct IO
{
  char ibuf[1 << 18], *s, *t, obuf[1 << 18], *o, vbuf[65];
  IO() : s(ibuf), t(ibuf), o(obuf) {}
  ~IO() { fwrite(obuf, 1, o - obuf, stdout); }
  inline char gc()
  {
    (s == t) && (t = (s = ibuf) + fread(ibuf, 1, 1 << 18, stdin));
    return s == t ? 0 : *s++;
  }
  inline void pc(char c)
  {
    (o == obuf + (1 << 18)) && (fwrite(obuf, 1, 1 << 18, stdout), o = obuf);
    *o++ = c;
  }
  template <typename T>
  inline IO &operator>>(T &x)
  {
    register T f = 1;
    register char c = gc();
    for (x = 0; !isdigit(c); c = gc())
      f = c == '-' ? -1 : 1;
    for (; isdigit(c); c = gc())
      x = (((x << 2) + x) << 1) + (c - '0');
    if (f == -1)
      x = -x;
    return *this;
  }
  inline IO &operator<<(char x)
  {
    pc(x);
    return *this;
  }
  inline IO &operator<<(const char *x)
  {
    register int u = 0;
    while (x[u])
      pc(x[u++]);
    return *this;
  }
  template <typename T>
  inline IO &operator<<(T x)
  {
    register int u = 0;
    if (x == 0)
      return pc('0'), *this;
    if (x < 0)
      x = -x, pc('-');
    while (x)
      vbuf[++u] = x % 10 + 48, x /= 10;
    while (u)
      pc(vbuf[u--]);
    return *this;
  }
} io;
const int N = 100005;
int n, m, sz, a[N], b[N], head[N], ver[N << 1], nxt[N << 1], tot, f[N][31];
int rt[N], dep[N], v[N * 30], son[N * 30][2], cnt;
inline void addedge(int u, int v)
{
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline int build(int l, int r)
{
  int k = ++cnt,
      mid = (l + r) / 2;
  if (l < r)
    ls = build(l, mid),
    rs = build(mid + 1, r);
  return k;
}
inline int modify(int u, int l, int r, int x)
{
  int k = ++cnt,
      mid = (l + r) >> 1;
  ls = son[u][0], rs = son[u][1];
  v[k] = v[u] + 1;
  if (l < r)
    if (x <= mid)
      ls = modify(son[u][0], l, mid, x);
    else
      rs = modify(son[u][1], mid + 1, r, x);
  return k;
}
inline void dfs1(int x)
{
  rt[x] = modify(rt[f[x][0]], 1, sz, a[x]);
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != f[x][0])
    {
      f[to][0] = x;
      dep[to] = dep[x] + 1;
      dfs1(to);
    }
}
inline int lca(int x, int y)
{
  if (dep[x] > dep[y])
    swap(x, y);
  for (int i = 30; i >= 0; --i)
    if (dep[f[y][i]] >= dep[x])
      y = f[y][i];
  if (x == y)
    return x;
  for (int i = 30; i >= 0; --i)
    if (f[x][i] != f[y][i])
      x = f[x][i], y = f[y][i];
  return f[x][0];
}
inline int query(int lf, int lc, int x, int y, int l, int r, int val)
{
  if (l >= r)
    return l;
  int t = v[son[x][0]] + v[son[y][0]] - v[son[lc][0]] - v[son[lf][0]],
      mid = (l + r) >> 1;
  if (t >= val)
    return query(son[lf][0], son[lc][0], son[x][0], son[y][0], l, mid, val);
  else
    return query(son[lf][1], son[lc][1], son[x][1], son[y][1], mid + 1, r, val - t);
}
inline int work(int x, int y, int k)
{
  // x -> y上第k大
  int l = lca(x, y);
  return b[query(rt[f[l][0]], rt[l], rt[x], rt[y], 1, sz, k)];
}
int main()
{
  memset(head, -1, sizeof head);
  io >> n >> m;
  for (int i = 1; i <= n; ++i)
    io >> a[i], b[i] = a[i];
  sort(b + 1, b + 1 + n);
  sz = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
  // rt[0] = build(1, sz);
  for (int i = 1, u, v; i < n; ++i)
  {
    io >> u >> v;
    addedge(u, v);
    addedge(v, u);
  }
  dep[1] = 1;
  dfs1(1);
  for (int t = 1; t <= 30; ++t)
    for (int i = 1; i <= n; ++i)
      f[i][t] = f[f[i][t - 1]][t - 1];
  int lastans = 0;
  for (int i = 1, u, v, k; i <= m; ++i)
  {
    io >> u >> v >> k;
    u ^= lastans;
    io << (lastans = work(u, v, k)) << '\n';
  }
}