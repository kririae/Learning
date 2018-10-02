#include <bits/stdc++.h>
#define ll long long
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
const int N = 300005;
int n, m, head[N], ver[N << 1], 
nxt[N << 1], edge[N << 1], tot, 
siz[N], son[N], fa[N], dep[N], id[N],
top[N], w[N], s[N], t[N], d[N], cnt, _max = 0, 
wb[N], wv[N], l[N]; ll dis[N];
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs1(int x) {
  siz[x] = 1, son[x] = 0;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if ((to = ver[i]) == fa[x]) continue;
    fa[to] = x, dep[to] = dep[x] + 1;
    dis[to] = dis[x] + (w[to] = edge[i]);
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
    if ((to = ver[i]) != fa[x] && to != son[x])
      dfs2(to, to);
}
inline void dfs3(int x) {
  wv[x] = wb[x];
  for (int i = head[x], to; ~i; i = nxt[i]) 
    if ((to = ver[i]) != fa[x]) 
      dfs3(to), wv[x] += wv[to];
}
inline int Lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) 
      swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] > dep[y] ? y : x;
}
inline ll Dis(int x, int y) {
  int r = Lca(x, y);
  return dis[x] + dis[y] - (dis[r] << 1);
}
inline bool judge(ll x) {
  int _cnt = 0, _e = 0;
  memset(wb, 0, sizeof wb);
  memset(wv, 0, sizeof wv);
  for (int i = 1; i <= m; ++i) {
    if (d[i] <= x) continue;
    ++_cnt;
    // d[i] > x, 需要删除一条边。
    ++wb[s[i]], 
    ++wb[t[i]],
    wb[Lca(s[i], t[i])] -= 2;
  }
  dfs3(1);
  for (int i = 1; i <= n; ++i)
    if (wv[i] == _cnt)
      _e = max(_e, w[i]);
  return _max - _e <= x;
}
int main() {
  memset(head, -1, sizeof head);
  n = read(), m = read();
  for (int i = 1, ai, bi, ti; i < n; ++i) {
    ai = read(), 
    bi = read(), 
    ti = read();
    addedge(ai, bi, ti);
    addedge(bi, ai, ti);
  }
  dfs1(1), dfs2(1, 1);
  for (int i = 1; i <= m; ++i) {
    s[i] = read(), 
    t[i] = read();
    d[i] = Dis(s[i], t[i]);
    _max = max(_max, d[i]);
  }
  ll l = 0, r = _max, ans = -1;
  while (l <= r) {
    ll mid = l + r >> 1;
    if (judge(mid)) ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  printf("%lld", ans);
}