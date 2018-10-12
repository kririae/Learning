#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read() {
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
inline char read_c() {
  register char c;
  for (c = gc(); isspace(c); c = gc())
    ;
  return c;
}
const int N = 1e5 + 5;
int n, m, head[N], ver[N << 1],
    nxt[N << 1], edge[N << 1], tot;
int siz[N], son[N], dep[N], fa[N], top[N], id[N], mp[N], w[N], tw[N], d, qwq[N];
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs1(int x) {
  siz[x] = 1;
  son[x] = 0;
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != fa[x]) {
      dep[to] = dep[x] + 1;
      fa[to] = x;
      w[to] = edge[i];
      tw[(i >> 1) + 1] = to;
      dfs1(to);
      if (siz[to] > siz[son[x]])
        son[x] = to;
      siz[x] += siz[to];
    }
}
inline void dfs2(int x, int topf) {
  top[x] = topf;
  id[x] = ++d;
  mp[d] = x;
  if (!son[x]) return;
  dfs2(son[x], topf);
  for (int i = head[x]; ~i; i = nxt[i])
    if (ver[i] != fa[x] && ver[i] != son[x])
      dfs2(ver[i], ver[i]);
}
namespace Sgt {
int L[N << 2], R[N << 2], son[N << 2][2], cnt, rt, rev[N << 2];
ll mx[N << 2], mi[N << 2], sum[N << 2];
inline void pushup(int k) {
  sum[k] = sum[ls] + sum[rs];
  mx[k] = max(mx[ls], mx[rs]);
  mi[k] = min(mi[ls], mi[rs]);
}
inline void pushdown(int k) {
  if (rev[k]) {
    swap(mx[ls], mi[ls]);
    swap(mx[rs], mi[rs]);
    mx[ls] *= -1, mx[rs] *= -1;
    mi[ls] *= -1, mi[rs] *= -1;
    sum[ls] *= -1, sum[rs] *= -1;
    rev[ls] ^= 1, rev[rs] ^= 1;
    rev[k] = 0;
  }
}
inline void build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l;
  R[k] = r;
  if (l == r) {
    sum[k] = mi[k] = mx[k] = w[mp[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
inline void Set(int k, int p, int x) {
  if (L[k] == R[k]) {
    sum[k] = x, mi[k] = x, mx[k] = x;
    return;
  }
  pushdown(k);
  int mid = (L[k] + R[k]) >> 1;
  if (p <= mid)
    Set(ls, p, x);
  else
    Set(rs, p, x);
  pushup(k);
}
inline void Rev(int k, int l, int r) {
  if (L[k] == l && R[k] == r) {
    rev[k] ^= 1;
    swap(mx[k], mi[k]);
    mx[k] *= -1, mi[k] *= -1;
    sum[k] *= -1;
    return;
  }
  pushdown(k);
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    Rev(ls, l, r);
  else if (l > mid)
    Rev(rs, l, r);
  else
    Rev(ls, l, mid), Rev(rs, mid + 1, r);
  pushup(k);
}
inline ll Q1(int k, int l, int r) {
  if (L[k] == l && R[k] == r)
    return sum[k];
  pushdown(k);
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    return Q1(ls, l, r);
  else if (l > mid)
    return Q1(rs, l, r);
  else
    return Q1(ls, l, mid) + Q1(rs, mid + 1, r);
}
inline ll Q2(int k, int l, int r) {
  if (L[k] == l && R[k] == r)
    return mi[k];
  pushdown(k);
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    return Q2(ls, l, r);
  else if (l > mid)
    return Q2(rs, l, r);
  else
    return min(Q2(ls, l, mid), Q2(rs, mid + 1, r));
}
inline ll Q3(int k, int l, int r) {
  if (L[k] == l && R[k] == r)
    return mx[k];
  pushdown(k);
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    return Q3(ls, l, r);
  else if (l > mid)
    return Q3(rs, l, r);
  else
    return max(Q3(ls, l, mid), Q3(rs, mid + 1, r));
}
inline void init() {
  build(rt, 1, n);
}
}  // namespace Sgt
inline ll QT1(int x, int y) {
  using Sgt::rt;
  ll ans = 0;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans += Sgt::Q1(rt, id[top[x]], id[x]);
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  if (x != y)
    ans += Sgt::Q1(rt, id[x] + 1, id[y]);
  return ans;
}
inline ll QT2(int x, int y) {
  using Sgt::rt;
  ll ans = -(1ll << 60);
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans = max(ans, Sgt::Q3(rt, id[top[x]], id[x]));
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  if (x != y)
    ans = max(ans, Sgt::Q3(rt, id[x] + 1, id[y]));
  return ans;
}
inline ll QT3(int x, int y) {
  using Sgt::rt;
  ll ans = 1ll << 60;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans = min(ans, Sgt::Q2(rt, id[top[x]], id[x]));
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  if (x != y)
    ans = min(ans, Sgt::Q2(rt, id[x] + 1, id[y]));
  return ans;
}
inline void MT1(int x, int y) {
  using Sgt::rt;
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    Sgt::Rev(rt, id[top[x]], id[x]);
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  if (x != y)
    Sgt::Rev(rt, id[x] + 1, id[y]);
}
int main() {
  using Sgt::rt;
  memset(head, -1, sizeof head);
  n = read();
  for (int i = 1, u, v, w; i < n; ++i) {
    u = read(), v = read(), w = read();
    addedge(u + 1, v + 1, w);
    addedge(v + 1, u + 1, w);
  }
  dfs1(1);
  dfs2(1, 1);
  Sgt::init();
  m = read();
  for (int i = 1, x, y; i <= m; ++i) {
    char op = read_c();
    if (op == 'C') {
      x = read();
      y = read();
      Sgt::Set(rt, id[++x], y);
    }
    if (op == 'M') {
      char op2 = read_c();
      x = read() + 1;
      y = read() + 1;
      if (op2 == 'A')
        printf("%lld\n", QT2(x, y));
      else
        printf("%lld\n", QT3(x, y));
    }
    if (op == 'S') {
      x = read() + 1;
      y = read() + 1;
      printf("%lld\n", QT1(x, y));
    }
    if (op == 'N') {
      x = read() + 1;
      y = read() + 1;
      MT1(x, y);
    }
  }
}