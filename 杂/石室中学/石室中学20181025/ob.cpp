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
const int N = 2e5 + 10;
int n, head[N], ver[N << 1], nxt[N << 1], tot, d;
int siz[N], son[N], fa[N], dep[N], top[N], id[N];
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs1(int x) {
  siz[x] = 1;
  son[x] = 0;
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != fa[x]) {
      dep[to] = dep[x] + 1;
      fa[to] = x;
      dfs1(to);
      if (siz[to] > siz[son[x]])
        son[x] = to;
      siz[x] += siz[to];
    }
}
inline void dfs2(int x, int topf) {
  top[x] = topf;
  id[x] = ++d;
  if (!son[x]) return;
  dfs2(son[x], topf);
  for (int i = head[x]; ~i; i = nxt[i])
    if (ver[i] != fa[x] && ver[i] != son[x])
      dfs2(ver[i], ver[i]);
}
inline int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] > dep[y] ? y : x;
}
inline ll dis(int x, int y) {
  int l = lca(x, y);
  return dep[x] + dep[y] - dep[l] * 2;
}
int main() {
  freopen("ob.in", "r", stdin);
  freopen("ob.out", "w", stdout);
  memset(head, -1, sizeof head);
  n = read();
  for (int i = 1, x, y; i < n; ++i) {
    x = read(), y = read();
    addedge(x, y);
    addedge(y, x);
  }
  dfs1(1);
  dfs2(1, 1);
  ll ans = (1ll << 60);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      ll tmp = 0;
      for (int k = 1; k <= n; ++k)
        tmp = max(tmp, min(dis(i, k), dis(j, k)));
      ans = min(ans, tmp);
    }
  printf("%lld\n", ans);
}
