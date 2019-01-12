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
const int N = 2e5 + 5;
int n, s, m, c[N];
int head[N], ver[N << 1], nxt[N << 1], edge[N << 1], tot;
int vis[N], from[N], fa[N];
ll dis[N];
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
namespace MST {
struct Edge {
  int u, v, w;
  bool operator<(const Edge &e) const { return w < e.w; }
} a[N << 1];
int head[N], ver[N << 1], nxt[N << 1], edge[N << 1], tot, cnt, fa[N];
int vis[N], f[N][30], g[N][30], dep[N];
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs(int x) {
  vis[x] = 1;
  for (int i = head[x], to; ~i; i = nxt[i])
    if (!vis[to = ver[i]]) {
      dep[to] = dep[x] + 1;
      f[to][0] = x;
      g[to][0] = edge[i];
      dfs(to);
    }
}
inline void init() {
  for (int i = 1; i <= n; ++i) fa[i] = i;
  memset(head, -1, sizeof head);
  tot = 0;
  for (int i = 1; i <= cnt; ++i) {
    int x = find(a[i].u), y = find(a[i].v);
    if (x != y) {
      fa[x] = y;
      addedge(a[i].u, a[i].v, a[i].w);
      addedge(a[i].v, a[i].u, a[i].w);
      // cout << "Add: " << a[i].u << " " << a[i].v << " " << a[i].w << endl;
    }
  }
  for (int i = 1; i <= s; ++i)
    if (!vis[c[i]]) dfs(c[i]);
  for (int t = 1; t <= 25; ++t)
    for (int i = 1, x; i <= s; ++i) {
      f[x = c[i]][t] = f[f[x][t - 1]][t - 1];
      g[x][t] = max(g[x][t - 1], g[f[x][t - 1]][t - 1]);
    }
}
inline int query(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int ans = 0;
  for (int t = 25; t >= 0; --t)
    if (dep[f[x][t]] >= dep[y])
      ans = max(ans, g[x][t]), x = f[x][t];
  if (x == y) return ans;
  for (int t = 25; t >= 0; --t)
    if (f[x][t] != f[y][t]) {
      ans = max(ans, g[x][t]);
      ans = max(ans, g[y][t]);
      x = f[x][t], y = f[y][t];
    }
  ans = max(ans, g[x][0]);
  ans = max(ans, g[y][0]);
  return ans;
}
}  // namespace MST
inline void init() {
  static queue<int> q;
  while (!q.empty()) q.pop();
  memset(dis, 0x3f, sizeof dis);
  for (int i = 1; i <= s; ++i) {
    from[c[i]] = c[i];
    dis[c[i]] = 0;
    vis[c[i]] = 1;
    q.push(c[i]);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u], to; ~i; i = nxt[i])
      if (dis[to = ver[i]] > dis[u] + edge[i]) {
        dis[to] = dis[u] + edge[i];
        from[to] = from[u];
        if (!vis[to]) vis[to] = 1, q.push(to);
      }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = head[i], to; ~j; j = nxt[j])
      if (from[i] != from[to = ver[j]]) {
        MST::a[++MST::cnt].u = from[i];
        MST::a[MST::cnt].v = from[to];
        MST::a[MST::cnt].w = dis[i] + dis[to] + edge[j];
      }
}
int main() {
  memset(head, -1, sizeof head);
  n = read(), s = read(), m = read();
  for (int i = 1; i <= s; ++i) c[i] = read();
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1, u, v, w; i <= m; ++i) {
    u = read(), v = read(), w = read();
    addedge(u, v, w);
    addedge(v, u, w);
    int x = find(u), y = find(v);
    if (x != y) fa[x] = y;
  }
  init();
  MST::init();
  int x, y, b, q;
  q = read();
  while (q--) {
    x = read(), y = read(), b = read();
    if (find(x) == find(y)) {
      if (MST::query(x, y) > b)
        puts("NIE");
      else
        puts("TAK");
    } else
      puts("NIE");
  }
}