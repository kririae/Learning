#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m, head[N], ver[N << 1], 
nxt[N << 1], edge[N << 1], tot, ans[N],
fa[N], f[N][35], g[N][35], dep[N]; 
bitset<N> vis;
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
struct Edge {
  int u, v, w, id;
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
} a[N];
inline int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline void dfs(int x) {
  for (int i = head[x]; ~i; i = nxt[i]) {
    int to = ver[i];
    if (to == f[x][0]) continue;
    f[to][0] = x;
    g[to][0] = edge[i];
    dep[to] = dep[x] + 1;
    dfs(to);
  }
}
inline int Query(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int ans = 0;
  for (int t = 30; t >= 0; --t)
    if (dep[f[x][t]] >= dep[y])
      ans = max(ans, g[x][t]),
      x = f[x][t];
  if (x == y)  
    return ans;
  for (int t = 30; t >= 0; --t)
    if (f[x][t] != f[y][t])
      ans = max(ans, g[x][t]),
      ans = max(ans, g[y][t]),
      x = f[x][t], 
      y = f[y][t];
  return ans;
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i)
    scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w), a[i].id = i;
  sort(a + 1, a + 1 + m);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  ll ws = 0; // WeightSum
  for (int i = 1; i <= m; ++i) {
    int x = find(a[i].u),
        y = find(a[i].v);
    if (x != y) {
      vis[i] = 1;
      fa[x] = y;
      ws += a[i].w;
      addedge(a[i].u, a[i].v, a[i].w);
      addedge(a[i].v, a[i].u, a[i].w);
      // printf("%d -> %d : %d\n", a[i].u, a[i].v, a[i].w);
    }
  }
  dfs(1);
  for (int t = 1; t <= 30; ++t)
    for (int i = 1; i <= n; ++i)
      f[i][t] = f[f[i][t - 1]][t - 1],
      g[i][t] = max(g[i][t - 1], g[f[i][t - 1]][t - 1]);
  for (int i = 1; i <= m; ++i)
    if (vis[i]) 
      ans[a[i].id] = ws;
    else
      ans[a[i].id] = ws - Query(a[i].u, a[i].v) + a[i].w;
  for (int i = 1; i <= m; ++i)
    printf("%d\n", ans[i]);
}