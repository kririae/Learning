#include <bits/stdc++.h>
#define ll long long
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
const int N = 105;
int n, m, k, e, d, g[N][N];
namespace SP {
int head[N], ver[N * N * 2], nxt[N * N * 2], edge[N * N * 2], tot;
int vis[105][105], s[105][105];
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void add_limit(int x, int l, int r) {
  for (int i = l; i <= r; ++i) vis[x][i] = 1;
}
inline int ava(int x, int l, int r) { return s[x][r] - s[x][l - 1]; }
inline ll SPFA(int l, int r) {
  static int dis[N], vis[N];
  static queue<int> q;
  while (!q.empty()) q.pop();
  memset(dis, 0x3f, sizeof dis);
  memset(vis, 0, sizeof vis);
  dis[1] = 0;
  vis[1] = 1;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; ~i; i = nxt[i]) {
      int to = ver[i];
      if (ava(to, l, r) == 0 && dis[u] + edge[i] <= dis[to]) {
        dis[to] = dis[u] + edge[i];
        if (!vis[to])
          vis[to] = 1,
          q.push(to);
      }
    }
  }
  if (dis[m] == 0x3f3f3f3f)
    return 0x3f3f3f3f;
  else
    return 1ll * (r - l + 1) * dis[m];
}
inline void init() {
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j)
      s[i][j] = s[i][j - 1] + vis[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j)
      g[i][j] = SPFA(i, j);
}
}  // namespace SP
int main() {
  memset(SP::head, -1, sizeof SP::head);
  n = read(), m = read(), k = read(), e = read();
  for (int i = 1, u, v, w; i <= e; ++i) {
    u = read(), v = read(), w = read();
    SP::addedge(u, v, w);
    SP::addedge(v, u, w);
  }
  d = read();
  while (d--) {
    int x, y, z;
    x = read(), y = read(), z = read();
    SP::add_limit(x, y, z);
  }
  SP::init();
  for (int len = 2; len <= n; ++len)
    for (int l = 1; l + len - 1 <= n; ++l) {
      int r = l + len - 1;
      for (int p = l; p < r; ++p)
        g[l][r] = min(g[l][r], g[l][p] + k + g[p + 1][r]);
    }
  cout << g[1][n];
}