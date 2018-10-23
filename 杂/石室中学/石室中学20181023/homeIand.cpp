#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read() {
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 5e5 + 5;
int n, E, q, cnt, S[N], T[N], W[N];
namespace Solve01 {
int head[30005], ver[30005], nxt[30005], edge[30005], tot;
int dis[30005], vis[30005];
queue<int> q;
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline ll dij(int st, int ed) {
  memset(dis, 0x3f, sizeof dis);
  dis[st] = 0;
  q.push(st);
  vis[st] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; ~i; i = nxt[i]) {
      int to = ver[i];
      if (dis[to] > dis[u] + edge[i]) {
        dis[to] = dis[u] + edge[i];
        if (!vis[to])
          vis[to] = 1, q.push(to);
      }
    }
  }
  return dis[ed];
}
inline void solve() {
  memset(head, -1, sizeof head);
  tot = 0;
  for (int i = 1, x, y, w; i <= E; ++i) {
    x = read(), y = read(), w = read();
    addedge(x, y, w);
    addedge(y, x, w);
  }
  int x = read(), y = read();
  printf("%lld\n", dij(x, y));
}
}  // namespace Solve01
namespace Solve02 {
int g[505][505];
inline void solve() {
  memset(g, 0x3f, sizeof g);
  for (int i = 1, x, y, w; i <= E; ++i) {
    x = read(), y = read(), w = read();
    g[x][y] = w;
    g[y][x] = w;
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      if (g[i][k] != inf)
        for (int j = 1; j <= n; ++j)
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  for (int i = 1, x, y; i <= q; ++i) {
    x = read(), y = read();
    printf("%d\n", g[x][y]);
  }
}
}  // namespace Solve02
int main() {
  freopen("homeIand.in", "r", stdin);
  freopen("homeIand.out", "w", stdout);
  n = read(), E = read(), q = read();
  if (q == 1) {
    Solve01::solve();
    return 0;
  } else if (n <= 500) {
    Solve02::solve();
    return 0;
  }
  else cout << 0;
  return 0;
}
