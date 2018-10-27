#include <bits/stdc++.h>
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
const int N = 25;
int n, m, k, e;
namespace SP {
int head[N], ver[N * N * 2], nxt[N * N * 2], edge[N * N * 2], tot;
int vis[25][105], s[25][105];
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void init() {
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j)
      s[i][j] = s[i][j - 1] + vis[i][j];
}
inline void add_limit(int x, int l, int r) {
  for (int i = l; i <= r; ++i) vis[x][i] = 1;
}
inline void ava(int x, int l, int r) { return s[x][r] - s[x][l - 1]; }
}  // namespace SP
int main() {
  n = read(), m = read(), k = read(), e = read();
  for (int i = 1, u, v, w; i <= e; ++i) {
    u = read(), v = read(), w = read();
    addedge(u, v, w);
    addedge(v, u, w);
  }
}