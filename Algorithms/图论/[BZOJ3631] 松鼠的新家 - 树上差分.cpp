#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e5 + 5;
int n, a[N], head[N], ver[N << 1], nxt[N << 1], tot, cnt;
int siz[N], son[N], fa[N], dep[N], id[N], top[N], c[N], ans[N]; // 差分
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs1(int x) {
  siz[x] = 1, son[x] = 0;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if((to = ver[i]) == fa[x]) continue;
    dep[to] = dep[x] + 1, fa[to] = x;
    dfs1(to);
    if(siz[to] > siz[son[x]]) son[x] = to;
    siz[x] += siz[to];
  }
}
inline void dfs2(int x, int topf) {
  id[x] = ++cnt, top[x] = topf;
  if(!son[x]) return;
  dfs2(son[x], topf);
  for (int i = head[x], to; ~i; i = nxt[i])
    if((to = ver[i]) != fa[x] && to != son[x]) dfs2(to, to);
}
inline int lca(int x, int y) {
  while(top[x] != top[y]) {
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  } return dep[x] > dep[y] ? y : x;
}
inline void dfs(int x) {
  ans[x] = c[x];
  for (int i = head[x], to; ~i; i = nxt[i])
    if((to = ver[i]) != fa[x]) dfs(to), ans[x] += ans[to];
}
inline void add(int x, int y, int z, int f = 0) {
  c[x] += z, c[y] += z, c[f = lca(x, y)] -= z, c[fa[f]] -= z;
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1, x, y; i < n; ++i) {
    scanf("%d%d", &x, &y);
    addedge(x, y), addedge(y, x);
  } dfs1(1), dfs2(1, 1);
  for (int i = 1; i < n; ++i) {
    int x = a[i], y = a[i + 1], f = lca(x, y);
    add(x, y, 1), add(y, y, -1);
  } dfs(1);
  for (int i = 1; i <= n; ++i)
    printf("%d\n", ans[i]);
}