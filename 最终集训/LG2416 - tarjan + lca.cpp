#include <bits/stdc++.h>
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read() {
  int k = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 3e5 + 5;
int n, m, q, head[N], ver[N << 1], 
nxt[N << 1], edge[N << 1], e[N], tot, 
siz[N], son[N], dis[N], fa[N], dep[N], top[N];
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
struct Tarjan {
int head[N], ver[N << 1], 
nxt[N << 1], edge[N << 1], tot, dfn[N], 
low[N], cp, belong[N], cnt, vis[N];
stack<int> s;
Tarjan() { memset(this->head, -1, sizeof this->head); }
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void tarjan(int x, int f) {
  dfn[x] = low[x] = ++cnt;
  s.push(x);
  vis[x] = 1;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if ((to = ver[i]) == f) continue;
    if (!dfn[to]) 
      tarjan(to, x),
      low[x] = min(low[x], low[to]);
    else if (vis[to])
      low[x] = min(low[x], dfn[to]);
  }
  if (dfn[x] == low[x]) {
    int u;
    ++cp;
    do {
      vis[u = s.top()] = 0;
      s.pop();
      belong[u] = cp;
    } while (u != x);
  }
}
} DCC;
inline void init() {
  for (int i = 1; i <= n; ++i)
    if (!DCC.dfn[i])
      DCC.tarjan(i, 0);
  memset(head, -1, sizeof head);
  for (int i = 1; i <= n; ++i) {
    for (int j = DCC.head[i]; ~j; j = DCC.nxt[j]) {
      int to = DCC.ver[j];
      if (DCC.belong[i] == DCC.belong[to])
        e[DCC.belong[i]] += DCC.edge[j];
      else 
        ::addedge(DCC.belong[i], DCC.belong[to], DCC.edge[j]);
    }
  }
}
inline void dfs1(int x) {
  siz[x] = 1, son[x] = 0;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if ((to = ver[i]) == fa[x]) continue;
    fa[to] = x, 
    dis[to] = dis[x] + edge[i],
    dep[to] = dep[x] + 1;
    dfs1(to);
    if (siz[to] > siz[son[x]])
      son[x] = to;
    siz[x] += siz[to];
  }
}
inline void dfs2(int x, int topf) {
  top[x] = topf;
  if (!son[x]) return ;
  dfs2(son[x], topf);
  for (int i = head[x], to; ~i; i = nxt[i]) {
    to = ver[i];
    if (to == son[x]) continue;
    if (to == fa[x])  continue;
    dfs2(to, to);
  }
}
inline int Lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] > dep[y] ? y : x;
}
int main() {
  n = read(), m = read();
  for (int i = 1, x, y, z; i <= m; ++i) {
    x = read(), y = read(), z = read();
    DCC.addedge(x, y, z);
    DCC.addedge(y, x, z);
  }
  dis[1] = e[1];
  init();
  dfs1(1);
  dfs2(1, 1);
  q = read();
  for (int i = 1, s, t; i <= q; ++i) {
    s = DCC.belong[read()];
    t = DCC.belong[read()];
    int l = Lca(s, t);
    int dx = dis[s] + dis[t] - (dis[l] << 1) + e[l];
    printf(dx >= 1 ? "YES\n" : "NO\n");
  }
  return 0;
}