#include <bits/stdc++.h>
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
  operator T() {
    register T r = 0, f = 1;
    register char c = gc();
    for (; !isdigit(c); c = gc()) f = c == '-' ? -1 : 1;
    for (; isdigit(c); c = gc()) r = (((r << 2) + r) << 1) + (c - '0');
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
int id, t, n, m, fa[N], f[N], g[N], l[N];
int main() {
  id = io, t = io;
  while (t--) {
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    memset(l, 0, sizeof l);
    n = io, m = io;
    for (int i = 2; i <= n; ++i) fa[i] = io;
    for (int i = n; i >= 1; --i) {
      if (f[i] + 1 >= f[fa[i]])
        g[fa[i]] = f[fa[i]], f[fa[i]] = f[i] + 1;
      else if (f[i] + 1 > g[fa[i]])
        g[fa[i]] = f[i] + 1;
    }
    for (int i = 2; i <= n; ++i)
      l[i] =
          max(l[fa[i]] + 1, f[i] + 1 == f[fa[i]] ? g[fa[i]] + 1 : f[fa[i]] + 1);
    for (int i = 1, x; i <= m; ++i) {
      x = io, io = l[x] + f[x];
      if (i != m) io = ' ';
    }
    if (m) io = '\n';
  }
}