#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, m, head[N], ver[N << 1], nxt[N << 1], tot;
ll w[N], f[N], g[N];
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs(int x, int fa) {
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if ((to = ver[i]) == fa) continue;
    dfs(to, x);
    f[x] = max(f[x], f[to]);
    g[x] = max(g[x], g[to]);
  }
  w[x] += (f[x] - g[x]);
  if (w[x] > 0)
    g[x] += w[x];
  else
    f[x] -= w[x];
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &w[i]);
    if (w[i] > 0)
      g[i] = w[i];
    else
      f[i] = abs(w[i]);
  }
  dfs(1, 1);
  printf("%lld", f[1] + g[1]);
}