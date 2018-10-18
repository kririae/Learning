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
const int N = 10005, M = 50005;
int n, m, head[N], ver[M << 1], nxt[M << 1], vis[N], tot;
ll b, f[N], edge[M << 1], mid, dis[N];
inline void addedge(int u, int v, ll w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline ll SPFA() {
  static queue<int> q;
  while (!q.empty()) q.pop();
  memset(dis, 0x3f, sizeof dis);
  memset(vis, 0, sizeof vis);
  vis[1] = 1;
  dis[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u], to; ~i; i = nxt[i])
      if (f[to = ver[i]] <= mid && dis[to] > dis[u] + edge[i]) {
        dis[to] = dis[u] + edge[i];
        if (!vis[to])
          vis[to] = 1,
          q.push(to);
      }
  }
  return dis[n];
}
int main() {
  memset(head, -1, sizeof head);
  n = io, m = io, b = io;
  for (int i = 1; i <= n; ++i) f[i] = io;
  for (int i = 1, u, v, w; i <= m; ++i) {
    u = io, v = io, w = io;
    addedge(u, v, w);
    addedge(v, u, w);
  }
  ll l = 0, r = 1e10, ans = 0;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (SPFA() <= b)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  if (ans)
    io = ans;
  else
    io = "AFK";
}