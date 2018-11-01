#include <bits/stdc++.h>
using namespace std;

const int M = 50005, N = 50005;
struct Edge {
  int u, v, w;
  bool operator<(const Edge &e) const { return w < e.w; }
} a[M];
int n, m, f[N], g[N], t[N << 1], cnt;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y, z; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    ++x, ++y;
    a[i].u = x, a[i].v = y, a[i].w = z;
    if (a[i].u > a[i].v) swap(a[i].u, a[i].v);
  }
  sort(a + 1, a + 1 + m);
  a[m + 1].w = -1;
  for (int i = 1; i <= m + 1; ++i) {
    Edge &e = a[i];
    if (e.w == a[i - 1].w) {
      g[e.u] = max(g[e.u], f[e.v] + 1);
      g[e.v] = max(g[e.v], f[e.u] + 1);
      t[++cnt] = i;
    } else {
      for (int j = 1; j <= cnt; ++j)
        f[a[t[j]].u] = g[a[t[j]].u],
        f[a[t[j]].v] = g[a[t[j]].v];
      t[cnt = 1] = i;
      g[e.u] = max(g[e.u], f[e.v] + 1);
      g[e.v] = max(g[e.v], f[e.u] + 1);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans = max(ans, f[i]);
  cout << ans;
}