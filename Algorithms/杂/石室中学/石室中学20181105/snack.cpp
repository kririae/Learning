#include <bits/stdc++.h>
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

struct IO {
  char ibuf[1 << 18], *s, *t, obuf[1 << 18], *o, vbuf[65];
  IO() : s(ibuf), t(ibuf), o(obuf) {}
  ~IO() { fwrite(obuf, 1, o - obuf, stdout); }
  inline char gc() {
    (s == t) && (t = (s = ibuf) + fread(ibuf, 1, 1 << 18, stdin));
    return s == t ? 0 : *s++;
  }
  inline void pc(char c) {
    (o == obuf + (1 << 18)) && (fwrite(obuf, 1, 1 << 18, stdout), o = obuf);
    *o++ = c;
  }
  template <typename T>
  inline IO &operator>>(T &x) {
    register T f = 1;
    register char c = gc();
    for (x = 0; !isdigit(c); c = gc())
      f = c == '-' ? -1 : 1;
    for (; isdigit(c); c = gc())
      x = (((x << 2) + x) << 1) + (c - '0');
    if (f == -1) x = -x;
    return *this;
  }
  inline IO &operator<<(char x) {
    pc(x);
    return *this;
  }
  inline IO &operator<<(const char *x) {
    register int u = 0;
    while (x[u]) pc(x[u++]);
    return *this;
  }
  template <typename T>
  inline IO &operator<<(T x) {
    register int u = 0;
    if (x == 0) return pc('0'), *this;
    if (x < 0) x = -x, pc('-');
    while (x) vbuf[++u] = x % 10 + 48, x /= 10;
    while (u) pc(vbuf[u--]);
    return *this;
  }
} io;
const int N = 5e5 + 5;
int n, q, head[N], ver[N << 1], nxt[N << 1], tot, rt;
int siz[N], fa[N], dep[N], son[N], id[N], cnt, top[N];
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs1(int x) {
  siz[x] = 1;
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != fa[x]) {
      fa[to] = x;
      dep[to] = dep[x] + 1;
      dfs1(to);
      if (siz[to] > siz[son[x]])
        son[x] = to;
      siz[x] += siz[to];
    }
}
inline void dfs2(int x, int topf) {
  id[x] = ++cnt;
  top[x] = topf;
  if (!son[x]) return;
  dfs2(son[x], topf);
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != fa[x] && to != son[x])
      dfs2(to, to);
}
namespace Sgt {
int L[N << 1], R[N << 1], son[N << 1][2], cnt;
int set[N << 1], sum[N << 1];
inline void pushdown(int k) {
  if (~set[k]) {
    set[ls] = set[k];
    set[rs] = set[k];
    sum[ls] = (R[ls] - L[ls] + 1) * set[k];
    sum[rs] = (R[rs] - L[rs] + 1) * set[k];
    set[k] = -1;
  }
}
inline void build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l;
  R[k] = r;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
}
inline void Set(int k, int l, int r, int x) {
  if (L[k] == l && R[k] == r) {
    set[k] = x;
    sum[k] = (r - l + 1) * x;
    return;
  }
  int mid = (L[k] + R[k]) >> 1;
  pushdown(k);
  if (r <= mid)
    Set(ls, l, r, x);
  else if (l > mid)
    Set(rs, l, r, x);
  else
    Set(ls, l, mid, x), Set(rs, mid + 1, r, x);
}
inline int query(int &k, int p) {
  if (L[k] == R[k])
    return sum[k];
  int mid = (L[k] + R[k]) >> 1;
  pushdown(k);
  if (p <= mid)
    return query(ls, p);
  else
    return query(rs, p);
}
}  // namespace Sgt
inline void modifySubtree(int x) {
  Sgt::Set(rt, id[x], id[x] + siz[x] - 1, 1);
}
inline void modifyChain(int x) {
  Sgt::Set(rt, id[1], id[x], 0);
}
inline int query(int x) {
  return Sgt::query(rt, id[x]);
}
int main() {
  freopen("snack.in", "r", stdin);
  freopen("snack.out", "w", stdout);
  memset(head, -1, sizeof head);
  io >> n;
  for (int i = 1, u, v; i < n; ++i) {
    io >> u >> v;
    addedge(u, v);
    addedge(v, u);
  }
  dfs1(1);
  dfs2(1, 1);
  Sgt::build(rt, 1, n);
  memset(Sgt::set, -1, sizeof Sgt::set);
  io >> q;
  while (q--) {
    int op, x;
    io >> op >> x;
    if (op == 1)
      modifySubtree(x);
    else if (op == 2)
      modifyChain(x);
    else
      io << query(x) << '\n';
  }
}
