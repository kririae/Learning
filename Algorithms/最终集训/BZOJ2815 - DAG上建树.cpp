#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 65550;
int n, f[N][25], dep[N], siz[N], in[N];
vector<int> g[N], rg[N], t[N];
queue<int> q;
inline int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = 20; i >= 0; --i)
    if (dep[f[x][i]] >= dep[y]) x = f[x][i];
  if (x == y) return x;
  for (int i = 20; i >= 0; --i)
    if (f[x][i] != f[y][i])
      x = f[x][i], y = f[y][i];
  return f[x][0];
}
inline void work(int x) {
  // 找到$x$的所有到达点的$lca$，然后连到新图的下面~
  int l = rg[x][0];
  for (int i = 1; i < rg[x].size(); ++i)
    l = lca(l, rg[x][i]);
  dep[x] = dep[l] + 1;
  f[x][0] = l;
  for (int t = 1; t <= 20; ++t)
    f[x][t] = f[f[x][t - 1]][t - 1];
  t[l].push_back(x);
}
inline int dfs(int x) {
  siz[x] = 1;
  for (int i = 0; i < t[x].size(); ++i)
    siz[x] += dfs(t[x][i]);
  return siz[x];
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; ++i)
    while (scanf("%d", &x) && x) {
      g[x].push_back(i);
      ++in[i];
      rg[i].push_back(x);
    }
  for (int i = 1; i <= n; ++i)
    if (!in[i]) {
      g[0].push_back(i);
      ++in[i];
      rg[i].push_back(0);
    }  // ???
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0, to; i < g[u].size(); ++i)
      if (!(--in[to = g[u][i]])) {
        work(to);
        q.push(to);
      }
  }
  for (int i = 1; i <= n; ++i)
    if (!siz[i]) dfs(i);
  for (int i = 1; i <= n; ++i)
    printf("%d\n", siz[i] - 1);
}