#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int t, n, a[N << 1][N << 1], vis[N << 1],
    to[N << 1], cnt, ans;
inline bool dfs(int x) {
  for (int i = 1; i <= n; ++i)
    if (a[x][i] && vis[i] != cnt) {
      vis[i] = cnt;
      if (!to[i] || dfs(to[i]))
        return to[i] = x, true;
    }
  return false;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    ans = 0, cnt = 1;
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    memset(to, 0, sizeof(to));
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i)
      for (int j = 1; j <= n; ++j) {
        scanf("%d", &x);
        if (x) a[i][j] = 1;
      }
    for (int i = 1; i <= n; ++i, ++cnt)
      ans += dfs(i);
    cout << (ans == n ? "Yes" : "No") << endl;
  }
}