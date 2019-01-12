#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

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
const int N = 1e6 + 5;
int L[N << 2], R[N << 2], son[N << 2][2];
int mi[N << 2], add[N << 2], rt, cnt;
int n, m, a[N];
inline void pushup(int k) {
  mi[k] = min(mi[ls], mi[rs]);
}
inline void pushdown(int k) {
  if (add[k]) {
    add[ls] += add[k];
    add[rs] += add[k];
    mi[ls] += add[k];
    mi[rs] += add[k];
    add[k] = 0;
  }
}
inline void build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l;
  R[k] = r;
  if (l == r) {
    mi[k] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
inline void Add(int k, int l, int r, int x) {
  if (L[k] == l && R[k] == r) {
    add[k] += x;
    mi[k] += x;
    return;
  }
  pushdown(k);
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    Add(ls, l, r, x);
  else if (l > mid)
    Add(rs, l, r, x);
  else
    Add(ls, l, mid, x), Add(rs, mid + 1, r, x);
  pushup(k);
}
inline int query() {
  pushdown(1);
  return mi[1];
}
int main() {
  io >> n >> m;
  for (int i = 1; i <= n; ++i) io >> a[i];
  build(rt, 1, n);
  for (int i = 1; i <= m; ++i) {
    int d, s, t;
    io >> d >> s >> t;
    Add(rt, s, t, -d);
    if (query() < 0) {
      puts("-1");
      printf("%d\n", i);
      goto fail;
    }
  }
  puts("0");
fail:
  return 0;
}