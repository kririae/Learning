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
const int N = 1e5 + 5;
struct Q {
  int l, r, x;
} a[N];
int n, m, b[N], s[N], c[N];
namespace Sgt {
int L[N << 2], R[N << 2], son[N << 2][2], cnt, rt, sum[N << 2];
inline void pushup(int k) {
  sum[k] = sum[ls] | sum[rs];
}
inline void build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l;
  R[k] = r;
  if (l == r) {
    sum[k] = c[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
inline int query(int k, int l, int r) {
  if (L[k] == l && R[k] == r)
    return sum[k];
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    return query(ls, l, r);
  else if (l > mid)
    return query(rs, l, r);
  else
    return query(ls, l, mid) | query(rs, mid + 1, r);
}
}  // namespace Sgt
int main() {
  n = io, m = io;
  for (int i = 1; i <= m; ++i)
    a[i].l = io, a[i].r = io, a[i].x = io;
  for (int i = 30; i >= 0; --i) {
    memset(s, 0, sizeof s);
    for (int j = 1; j <= m; ++j) {
      if (((a[j].x >> i) & 1) == 0)
        ++s[a[j].l], --s[a[j].r + 1];
    }
    for (int j = 1; j <= n; ++j) {
      s[j] += s[j - 1];
      if (s[j] == 0)
        c[j] |= (1ll << i);
    }
  }
  Sgt::build(Sgt::rt, 1, n);
  for (int i = 1; i <= m; ++i) {
    int ans = Sgt::query(Sgt::rt, a[i].l, a[i].r);
    if (ans != a[i].x) {
      io = "No";
      return 0;
    }
  }
  io = "Yes\n";
  for (int i = 1; i <= n; ++i)
    io = c[i], io = ' ';
}