#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, m, cnt, tot, head[N], nxt[N << 1], ver[N << 1],
    siz[N], son[N], fa[N], dep[N], id[N], top[N];
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
  for (int i = 1, x, y, z; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    int a = lca(x, y), b = lca(y, z), c = lca(x, z), ans;
    if (a == b) ans = c;
    else if (b == c) ans = a;
    else if (a == c) ans = b;
    printf("%d %d\n", ans, dep[x] + dep[y] + dep[z] - dep[a] - dep[b] - dep[c]);
  }
}