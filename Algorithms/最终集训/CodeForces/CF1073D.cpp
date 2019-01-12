#include <bits/stdc++.h>
using namespace std;

const int tx[10] = {2, 2, 1, 1, -1, -1, -2, -2},
          ty[10] = {1, -1, 2, -2, 2, -2, 1, -1};
const int N = 30;
int n, m, head[N * N], ver[N * N * N], nxt[N * N * N];
int vis[N * N], to[N * N], cnt = 1, tot;
inline int calc(int x, int y) {
  return (x - 1) * m + y;
}
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline bool dfs(int x) {
  for (int i = head[x], tq; ~i; i = nxt[i])
    if (vis[tq = ver[i]] != cnt) {
      vis[tq] = cnt;
      if (!to[tq] || dfs(to[tq]))
        return to[tq] = x, true;
    }
  return false;
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d", &n, &m);
  if (n <= 20 && m <= 20) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        for (int k = 0; k < 8; ++k) {
          int to_x = i + tx[k],
              to_y = j + ty[k];
          if (to_x >= 1 && to_x <= n && to_y >= 1 && to_y <= m)
            addedge(calc(i, j), calc(to_x, to_y));
        }
      }
    int ans = 0;
    for (int i = 1; i <= calc(n, m); ++i, ++cnt)
      ans += dfs(i);
    cout << ans;
  } else {
    if (n % 2 == 1 && m % 2 == 1)
      printf("%lld", 1ll * n * m - 1);
    else
      printf("%lld", 1ll * n * m);
  }
}