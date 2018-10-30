#include <bits/stdc++.h>
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline ll read() {
  register ll k = 0, f = 1;
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
const int N = 3e5 + 5;
int n, head[N], from[N], tox[N], ver[N << 1], nxt[N << 1], tot, rev[N];
int siz[N], fa[N], dep[N], son[N], id[N], top[N], rt, cnt;
ll w[N], edge[N << 1];
inline void addedge(int u, int v, ll w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs1(int x) {
  siz[x] = 1;
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != fa[x]) {
      fa[to] = x;
      w[to] = edge[i];
      // from[(i >> 1) + 1] = x, tox[(i >> 1) + 1] = to;
      dep[to] = dep[x] + 1;
      dfs1(to);
      if (siz[to] > siz[son[x]]) son[x] = to;
      siz[x] += siz[to];
    }
}
inline void dfs2(int x, int topf) {
  id[x] = ++cnt, rev[cnt] = x, top[x] = topf;
  if (!son[x]) return;
  dfs2(son[x], topf);
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != fa[x] && to != son[x])
      dfs2(to, to);
}
namespace Sgt {
int L[N << 1], R[N << 1], son[N << 1][2], tcnt;
ll mx[N << 1];
inline void pushup(int k) { mx[k] = max(mx[ls], mx[rs]); }
inline void build(int &k, int l, int r) {
  k = ++tcnt;
  L[k] = l;
  R[k] = r;
  if (l == r) {
    mx[k] = w[rev[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
inline void modify(int k, int p, int x) {
  if (L[k] == R[k]) {
    mx[k] = x;
    return;
  }
  int mid = (L[k] + R[k]) >> 1;
  if (p <= mid)
    modify(ls, p, x);
  else
    modify(rs, p, x);
  pushup(k);
}
inline ll query(int k, int l, int r) {
  // cout << l << " " << r << endl;
  if (L[k] == l && R[k] == r) {
    return mx[k];
  }
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    return query(ls, l, r);
  else if (l > mid)
    return query(rs, l, r);
  else
    return max(query(ls, l, mid), query(rs, mid + 1, r));
}
}  // namespace Sgt
inline ll Query(int x, int y) {
  ll ans = -(1ll << 60);
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ans = max(ans, Sgt::query(rt, id[top[x]], id[x]));
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  if (x != y)
    ans = max(ans, Sgt::query(rt, id[x] + 1, id[y]));
  return ans;
}
int main() {
  memset(head, -1, sizeof head);
  n = read();
  for (int i = 1, u, v; i < n; ++i) {
    ll w;
    u = read(), v = read(), w = read();
    addedge(u, v, w);
    addedge(v, u, w);
    from[i] = u, tox[i] = v;
  }
  dfs1(1);
  dfs2(1, 1);
  Sgt::build(rt, 1, n);
  for (;;) {
    char c = read_c();
    if (c == 'D') break;
    if (c == 'C') {
      ll x = read(), y = read();
      Sgt::modify(rt, id[tox[x]], y);
    } else {
      ll x = read(), y = read();
      if (x == y)
        printf("%lld\n", 0);
      else
        printf("%lld\n", Query(x, y));
    }
  }
}