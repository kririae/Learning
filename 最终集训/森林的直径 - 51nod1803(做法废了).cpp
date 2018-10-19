#include <bits/stdc++.h>
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
#define oo 0x3f3f3f3f
using namespace std;

/*
傻逼的报废的做法，我想 + 写这个花了四个小时
51nod 1803
\rightarrow
$51nod \ 1803$

给出随机的一棵树，保证父亲节点编号小于子节点，导出编号$[l, r]$的点，求这个导出子图的森林的直径。$n, q \le 10^5$。

直径这玩意儿，不能像之前某道题那样说维护就维护了啊...
这样吧。
我们考虑对所有询问的$r$排序。
然后从左到右依次加入边。
获取树的直径如何获取呢？
$f[x][2]$表示以$x$为根的子树中离$x$最远的点和次远的点。
由于的树随机，所以树的深度约为$\log{n}$。
我们现在需要快速获取$[l, r]$，抛开$[1, l - 1]$的影响，的最大$f[i][0] + f[i][1]$。

编号小的点不会影响编号大的点的f[x] \ g[x]...
问题就出在"导出编号[l, r]"的点...
死了，以后做题的前几步一定不能错...
 */
struct IO {
#define nline '\n'
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
int n, Q, fa[N], f[N], g[N], h[N], l[N];
vector<int> q[N];
namespace Sgt {
int L[N << 1], R[N << 1], son[N << 1][2];
int mi[N << 1], rt, cnt;
inline void pushup(int k) {
  mi[k] = max(mi[ls], mi[rs]);
}
inline void build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l;
  R[k] = r;
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
inline void update(int k, int p, int x) {
  if (L[k] == R[k]) {
    mi[k] = x;
    return;
  }
  int mid = (L[k] + R[k]) >> 1;
  if (p <= mid)
    update(ls, p, x);
  else
    update(rs, p, x);
  pushup(k);
}
inline int query(int &k, int l, int r) {
  if (L[k] == l && R[k] == r)
    return mi[k];
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    return query(ls, l, r);
  else if (l > mid)
    return query(rs, l, r);
  else
    return max(query(ls, l, mid), query(rs, mid + 1, r));
}
}  // namespace Sgt
inline void insert(int x) {
  using namespace Sgt;
  f[x] = 0, g[x] = 0;
  while (fa[x]) {
    int t = fa[x];
    if (h[t] == x) {
      if (f[x] + 1 >= f[t])
        f[t] = f[x] + 1,
        update(rt, t, f[t] + g[t]);
    } else {
      if (f[x] + 1 >= f[t]) {
        g[t] = f[t];
        f[t] = f[x] + 1;
        h[t] = x;
        update(rt, t, f[t] + g[t]);
      } else if (f[x] + 1 > g[t])
        g[t] = f[x] + 1,
        update(rt, t, f[t] + g[t]);
    }
    x = t;
  }
  for (int i = 1; i <= n; ++i)
    io << "insert: " << x << " -> " << f[i] << " " << g[i] << " " << query(rt, i, i) << nline;
}
int main() {
  // freopen("test.txt", "r", stdin);
  using Sgt::rt;
  io >> n;
  for (int i = 1, u, v; i < n; ++i) {
    io >> u >> v;
    fa[v] = u;
  }
  io >> Q;
  for (int i = 1, l, r; i <= Q; ++i) {
    io >> l >> r;
    q[r + 1].push_back(l + 1);
  }
  Sgt::build(rt, 1, n);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    insert(i);
    for (int j = 0; j < q[i].size(); ++j) {
      int v = Sgt::query(rt, q[i][j], i);
      ans += v;
    }
  }
  for (int i = 1; i <= n; ++i)
    io << f[i] << " " << g[i] << nline;
  io << f[1] << " " << g[1] << nline;
  io << ans;
}