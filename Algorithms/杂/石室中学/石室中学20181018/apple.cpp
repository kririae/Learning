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

const int N = 1e6 + 5;
int n, m, head[N], ver[N << 1], nxt[N << 1], tot;
int vis[N];
ll a[N];
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline ll dfs(int x, int rt) {
  vis[x] = 1;
  ll ret = 0;
  for (int i = head[x], to; ~i; i = nxt[i])
    if (!vis[to = ver[i]]) {
      ret = max(ret, dfs(to, rt));
      a[x] += a[to];
    }
  return x == rt ? ret : max(ret, a[x]);
}
int main() {
  freopen("apple.in", "r", stdin);
  freopen("apple.out", "w", stdout);
  memset(head, -1, sizeof head);
  n = io, m = io;
  for (int i = 1; i <= n; ++i)
    a[i] = io;
  for (int i = 1, u, v; i <= m; ++i) {
    u = io, v = io;
    addedge(u, v);
    addedge(v, u);
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i)
    if (!vis[i])
      ans += dfs(i, i);
  io = ans;
}
