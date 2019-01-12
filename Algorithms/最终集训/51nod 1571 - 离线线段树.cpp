#include <bits/stdc++.h>
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
#define oo 0x3f3f3f3f
using namespace std;

struct IO {
  char ibuf[1 << 18], *s, *t, obuf[1 << 18], *o, vbuf[65];
  IO() : s(ibuf), t(ibuf), o(obuf) {}
  ~IO() { fwrite(obuf, 1, o - obuf, stdout); }
  inline char gc() {
    (s == t) &&
        (t = (s = ibuf) + fread(ibuf, 1, 1 << 18, stdin));
    return s == t ? 0 : *s++;
  }
  inline void pc(char c) {
    (o == obuf + (1 << 18)) &&
        (fwrite(obuf, 1, 1 << 18, stdout), o = obuf);
    *o++ = c;
  }
  template <typename T>
  operator T() {
    register T r = 0, f = 1;
    register char c = gc();
    for (; !isdigit(c); c = gc())
      f = c == '-' ? -1 : 1;
    for (; isdigit(c); c = gc())
      r = (((r << 2) + r) << 1) + (c - '0');
    return f == 1 ? r : -r;
  }
  void operator=(char x) { pc(x); }
  void operator=(const char *x) {
    register int u = 0;
    while (x[u]) pc(x[u++]);
  }
  template <typename T>
  void operator=(T x) {
    register int u = 0;
    if (x == 0) return pc('0'), void();
    if (x < 0) x = -x, pc('-');
    while (x) vbuf[++u] = x % 10 + 48, x /= 10;
    while (u) pc(vbuf[u--]);
  }
} io;
const int N = 5e5 + 5;
int n, m, a[N], b[N], pos[N], pre[N], ans[N];
vector<pair<int, int> > q[N];
namespace Sgt {
int L[N << 2], R[N << 2], son[N << 2][2];
int mi[N << 2], rt, cnt;
inline void pushup(int k) {
  mi[k] = min(mi[ls], mi[rs]);
}
inline void build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l;
  R[k] = r;
  if (l == r) {
    mi[k] = oo;
    return;
  }
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
inline void update(int k, int p, int x) {
  if (L[k] == R[k]) {
    mi[k] = min(mi[k], x);
    return;
  }
  int mid = (L[k] + R[k]) >> 1;
  if (p <= mid)
    update(ls, p, x);
  else
    update(rs, p, x);
  pushup(k);
}
inline int query(int k, int l, int r) {
  if (L[k] == l && R[k] == r)
    return mi[k];
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    return query(ls, l, r);
  else if (l > mid)
    return query(rs, l, r);
  else
    return min(query(ls, l, mid), query(rs, mid + 1, r));
}
}  // namespace Sgt
int main() {
  n = io, m = io;
  for (int i = 1; i <= n; ++i) b[i] = a[i] = io;
  sort(b + 1, b + 1 + n);
  int sz = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
  for (int i = 1, l, r; i <= m; ++i) {
    l = io, r = io;
    if (l > r) swap(l, r);
    q[r].push_back(make_pair(l, i));
  }
  using Sgt::rt;
  Sgt::build(rt, 1, n);
  memset(pos, -1, sizeof pos);
  for (int i = 1; i <= n; ++i) {
    if (~pos[a[i]])
      pre[i] = pos[a[i]];
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    // 顺着扫描~
    if (pre[i])
      Sgt::update(rt, pre[i], i - pre[i]);
    for (int j = 0; j < q[i].size(); ++j)
      ans[q[i][j].second] = Sgt::query(rt, q[i][j].first, i);
  }
  for (int i = 1; i <= m; ++i)
    io = (ans[i] == oo ? -1 : ans[i]), io = '\n';
}