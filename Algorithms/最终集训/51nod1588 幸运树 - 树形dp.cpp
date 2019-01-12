#include <bits/stdc++.h>
#define ll long long
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
int n, fa[N], head[N], ver[N << 1], nxt[N << 1], edge[N << 1], tot, siz[N],
    f[N], g[N];
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline bool check(int x) {
  while (x) {
    int u = x % 10;
    if (u != 4 && u != 7) return false;
    x /= 10;
  }
  return true;
}
inline void dfs1(int x) {
  siz[x] = 1;
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != fa[x]) {
      fa[to] = x;
      dfs1(to);
      siz[x] += siz[to];
    }
}
inline void dp1(int x) {
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != fa[x]) {
      dp1(to);
      f[x] += edge[i] ? siz[to] : f[to];
    }
}
inline void dp2(int x) {
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != fa[x]) {
      g[to] = edge[i] ? siz[1] - siz[to] : g[x] + f[x] - f[to];
      dp2(to);
    }
}
int main() {
  memset(head, -1, sizeof head);
  n = io;
  for (int i = 1, u, v, w; i < n; ++i) {
    u = io, v = io, w = io;
    w = check(w);
    addedge(u, v, w);
    addedge(v, u, w);
  }
  dfs1(1);
  dp1(1);
  dp2(1);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) ans += 1ll * (f[i] + g[i]) * (f[i] + g[i] - 1);
  io = ans;
}