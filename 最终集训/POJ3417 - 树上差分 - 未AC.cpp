#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, cnt, tot, head[N], nxt[N << 1], ver[N << 1],
    siz[N], son[N], fa[N], dep[N], id[N], top[N], w[N], a[N];
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs1(int x) {
  siz[x] = 1, son[x] = 0;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if ((to = ver[i]) == fa[x]) continue;
    fa[to] = x, dep[to] = dep[x] + 1;
    dfs1(to);
    if (siz[to] > siz[son[x]]) son[x] = to;
    siz[x] += siz[to];
  }
}
inline void dfs2(int x, int topf) {
  id[x] = ++cnt, top[x] = topf;
  if (!son[x]) return;
  dfs2(son[x], topf);
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != fa[x] && to != son[x]) dfs2(to, to);
}
inline void dfs3(int x) {
  a[x] = w[x];
  for (int i = head[x], to; ~i; i = nxt[i]) 
    if ((to = ver[i]) != fa[x]) dfs3(to), a[x] += w[to];
}
inline int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] > dep[y] ? y : x;
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  dfs1(1), dfs2(1, 1);
  for (int i = 1, x, y; i <= m; ++i)
    scanf("%d%d", &x, &y),
    ++w[x], ++w[y], w[lca(x, y)] -= 2;
  dfs3(1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0) ++ans;
    if (a[i] == 1) ++ans;
  }
  cout << ans << endl;
}