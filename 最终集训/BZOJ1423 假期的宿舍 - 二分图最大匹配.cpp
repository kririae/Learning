#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int t, n, a[N], b[N], cnt, tot, 
f[N][N], g[N][N], to[N], vis[N];
inline bool dfs(int x) {
  for (int i = 1; i <= n; ++i)
    if (g[x][i] && vis[i] != cnt) {
      vis[i] = cnt;
      if (!to[i] || dfs(to[i]))
        return to[i] = x, true;
    } 
  return false;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    cnt = 1, tot = 0;
    memset(g, 0, sizeof(g));
    memset(f, 0, sizeof(f));
    memset(to, 0, sizeof(to));
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
      scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      if ((a[i] && !b[i]) || !a[i]) ++tot; 
      if (a[i] == 1 && b[i] == 0) g[i][i] = 1;
    } 
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        scanf("%d", &f[i][j]);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (f[i][j] == 1 && a[j] == 1) g[i][j] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i, ++cnt)
      if (!a[i] || (a[i] && !b[i])) ans += dfs(i);
    cout << (ans == tot ? "^_^" : "T_T") << endl;
  }
}