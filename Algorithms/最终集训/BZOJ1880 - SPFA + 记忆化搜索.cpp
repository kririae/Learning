#include <bits/stdc++.h>
using namespace std;

const int N = 1505, M = 500005 * 2;
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
int n, m, X1, Y1, X2, Y2, dis[5][N];
namespace DP {
int head[N], ver[M], nxt[M], edge[M], tot, f[N];
inline void init() {
  memset(head, -1, sizeof head);
  tot = 0;
}
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline int dfs(int x) {
  if (x == X1) return 0;
  if (f[x]) return f[x];
  for (int i = head[x]; ~i; i = nxt[i])
    f[x] = max(f[x], dfs(ver[i]) + edge[i]);
  return f[x];
}
}  // namespace DP
namespace SP {
int head[N], ver[M], nxt[M], edge[M], tot;
int vis[N];
inline void init() {
  memset(head, -1, sizeof head);
  tot = 0;
}
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void SPFA(int idx, int st) {
  static queue<int> q;
  while (!q.empty()) q.pop();
  memset(dis[idx], 0x3f, sizeof dis[idx]);
  dis[idx][st] = 0;
  vis[st] = 1;
  q.push(st);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; ~i; i = nxt[i]) {
      int to = ver[i];
      if (dis[idx][to] > dis[idx][u] + edge[i]) {
        dis[idx][to] = dis[idx][u] + edge[i];
        if (!vis[to]) vis[to] = 1, q.push(to);
      }
    }
  }
}
inline void solve() {
  SPFA(1, X1);
  SPFA(2, Y1);
  SPFA(3, X2);
  SPFA(4, Y2);
  for (int i = 1; i <= n; ++i)
    for (int j = head[i]; ~j; j = nxt[j]) {
      int to = ver[j];
      if (dis[1][i] + edge[j] + dis[2][to] == dis[1][Y1]) {
        if (dis[3][i] + edge[j] + dis[4][to] == dis[3][Y2] ||
            dis[4][i] + edge[j] + dis[3][to] == dis[3][Y2])
          DP::addedge(to, i, edge[j]);
        else
          DP::addedge(to, i, 0);
      }
    }
}
}  // namespace SP
int main() {
  n = io, m = io;
  X1 = io, Y1 = io, X2 = io, Y2 = io;
  DP::init();
  SP::init();
  for (int i = 1, u, v, w; i <= m; ++i) {
    u = io, v = io, w = io;
    SP::addedge(u, v, w);
    SP::addedge(v, u, w);
  }
  SP::solve();
  io = DP::dfs(Y1);
}