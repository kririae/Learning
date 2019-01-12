#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define ls t[k].son[0]
#define rs t[k].son[1]
using namespace std;

namespace BZOJ4568 {
inline char gc()
{
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline ll read()
{
  register ll k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 20005;
ll g[N], f[N][21][62];
int n, q, head[N], ver[N << 1], nxt[N << 1], tot;
int fa[N][21], dep[N];
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs(int x) {
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if((to = ver[i]) == fa[x][0]) continue;
    dep[to] = dep[x] + 1, fa[to][0] = x;
    dfs(to);
  }
}
inline void insert(ll x, ll *a) {
  for (int j = 60; j >= 0; --j)
    if(x & (1ll << j)) {
      if(a[j] == 0) return a[j] = x, void();
      x ^= a[j];
    }
}
inline void merge(ll *a, ll *b) {
  for (int i = 0; i <= 60; ++i) if(b[i]) insert(b[i], a);
}
inline ll gmax(ll *a, ll ans = 0) {
  for (int i = 60; i >= 0; --i) ans = max(ans, ans ^ a[i]);
  return ans;
}
inline ll lca(int x, int y) {
  static ll ans[65];
  memset(ans, 0, sizeof(ans));
  if(dep[x] < dep[y]) swap(x, y);
  for (int i = 20; i >= 0; --i) 
    if(dep[fa[x][i]] >= dep[y])
      merge(ans, f[x][i]), x = fa[x][i];
  if(x == y) return merge(ans, f[x][0]), gmax(ans);
  for (int i = 20; i >= 0; --i)
    if(fa[x][i] != fa[y][i]) {
      merge(ans, f[x][i]), merge(ans, f[y][i]);
      x = fa[x][i], y = fa[y][i];
    }
  merge(ans, f[x][0]), merge(ans, f[y][0]), merge(ans, f[fa[x][0]][0]);
  return gmax(ans);
}
inline void solve() {
  memset(head, -1, sizeof(head));
  n = read(), q = read();
  for (int i = 1; i <= n; ++i) insert(g[i] = read(), f[i][0]);
  for (int i = 1, x, y; i < n; ++i) {
    x = read(), y = read();
    addedge(x, y);
    addedge(y, x);
  }
  dfs(1);
  for (int t = 1; t <= 20; ++t)
    for (int i = 1; i <= n; ++i)
      fa[i][t] = fa[fa[i][t - 1]][t - 1],
      memcpy(f[i][t], f[i][t - 1], sizeof(f[i][t])),
      merge(f[i][t], f[fa[i][t - 1]][t - 1]);
  for (int i = 1, x, y; i <= q; ++i) {
    x = read(), y = read();
    printf("%lld\n", lca(x, y));
  }
}
}

int main() {
  return BZOJ4568::solve(), 0;
}