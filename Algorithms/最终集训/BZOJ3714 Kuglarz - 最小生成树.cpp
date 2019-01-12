#include <bits/stdc++.h>
#define ll long long
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
const int N = 2005;
struct Edge {
  int u, v, w;
  bool operator<(const Edge &e) const { return w < e.w; }
} b[N * N];
int n, a[N][N], cnt, fa[N];
inline int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
  n = io;
  for (int i = 0; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j) {
      b[++cnt].u = i - 1;
      b[cnt].v = j;
      b[cnt].w = io;
    }
  sort(b + 1, b + 1 + cnt);
  ll ans = 0, tot = 0;
  for (int i = 1; i <= cnt; ++i) {
    int x = find(b[i].u),
        y = find(b[i].v);
    if (x != y) {
      fa[x] = y;
      ans += b[i].w;
      if (tot++ == n)
        goto output;
    }
  }
output:
  io = ans;
}