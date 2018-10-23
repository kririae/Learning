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
  for (; isdigit(c); c = gc()) k = k * 10 + c - '0';
  return k * f;
}
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, m, fa[N], u[N], v[N], vis[N], res[N];
ll w[N];
vector<int> q[N], g[N];
inline int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline void addedge(int x, int y) {
  g[x].push_back(y);
  g[y].push_back(x);
}
int main() {
  freopen("war.in", "r", stdin);
  freopen("war.out", "w", stdout);
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) w[i] = fa[i] = i;
  for (int i = 2; i <= n; ++i)
    u[i] = i, v[i] = read(),
    addedge(u[i], v[i]);
  for (int i = 1, k; i <= m; ++i) {
    k = read();
    for (int j = 1, x; j <= k; ++j) {
      x = read();
      q[i].push_back(x);
      vis[x] = 1;
    }
  }
  ll ans = 0;
  for (int i = 2; i <= n; ++i) {
    int x = find(u[i]),
        y = find(v[i]);
    if (vis[u[i]] == 0 && vis[v[i]] == 0 && x != y) {
      fa[x] = y;
      ans = (ans + 1ll * w[x] * w[y]) % MOD;
      (w[y] += w[x]) %= MOD;
    }
  }
  for (int i = m; i >= 1; --i) {
    res[i] = ans % MOD;
    for (int j = 0; j < q[i].size(); ++j)
      for (int k = 0, to; k < g[q[i][j]].size(); ++k) {
        vis[q[i][j]] = 0;
        if (!vis[to = g[q[i][j]][k]]) {
          int x = find(q[i][j]),
              y = find(to);
          if (x != y) {
            fa[x] = y;
            ans = (ans + w[x] * w[y]) % MOD;
            (w[y] += w[x]) %= MOD;
          }
        }
      }
  }
  res[0] = ans % MOD;
  for (int i = 0; i <= m; ++i)
    printf("%d\n", res[i]);
}
