#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int id, t, n, m, fa[N], f[N], g[N], dep[N], dis[N], del[N], vis[N];
int head[N], ver[N << 1], nxt[N << 1], tot;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
int main() {
  freopen("olefin.in", "r", stdin);
  freopen("olefin.out", "w", stdout);
  scanf("%d%d", &id, &t);
  while (t--) {
    memset(head, -1, sizeof head);
    memset(ver, 0, sizeof ver);
    memset(nxt, 0, sizeof nxt);
    tot = 0;
    memset(fa, 0, sizeof fa);
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; ++i) {
      scanf("%d", &fa[i]);
      addedge(fa[i], i);
      addedge(i, fa[i]);
    }
    for (int i = 1; i <= n; ++i) dep[i] = dep[fa[i]] + 1;
    for (int i = n; i >= 1; --i) f[fa[i]] = max(f[fa[i]], f[i] + 1);
    for (int i = 2; i <= n; ++i)
      for (int j = head[i]; ~j; j = nxt[j]) {
        int to1 = ver[j];
        if (dep[to1] < dep[i]) continue;
        for (int k = head[i]; ~k; k = nxt[k]) {
          int to2 = ver[k];
          if (to1 == to2) continue;
          g[to1] = max(g[to1], f[to2] + 1);
        }
        g[to1] = max(g[to1], g[i]);
      }
    for (int i = 1, x; i <= m; ++i) {
      scanf("%d", &x);
      cout << f[x] + g[x] << endl;
    }
  }
}