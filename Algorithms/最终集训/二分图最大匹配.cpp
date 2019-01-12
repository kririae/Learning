// rqy ver
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, e, ans, cnt = 1, a[N][N], to[N], vis[N];
inline bool dfs(int x) {
  for (int i = 1; i <= m; ++i)
    if (a[x][i] && vis[i] != cnt) {
      vis[i] = cnt;
      if (!to[i] || dfs(to[i]))
        return to[i] = x, true;
    } 
  return false;
}
int main() {
  scanf("%d%d%d", &n, &m, &e);
  for (int i = 1, u, v; i <= e; ++i) {
    scanf("%d%d", &u, &v);
    if (u <= n && v <= n) a[u][v] = 1;
  }
  for (int i = 1; i <= n; ++cnt, ++i)
    ans += dfs(i);
  cout << ans << endl;
}