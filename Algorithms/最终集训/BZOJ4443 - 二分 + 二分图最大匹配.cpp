#include <bits/stdc++.h>
using namespace std;

const int N = 255;
int n, m, k, a[N][N], to[N], vis[N], cnt, mid;
inline bool dfs(int x) {
  for (int i = 1; i <= m; ++i)
    if (a[x][i] <= mid && vis[i] != cnt) {
      vis[i] = cnt;
      if (!to[i] || dfs(to[i]))
        return to[i] = x, true;
    }
  return false;
}
inline int judge(/* mid */) {
  cnt = 1;
  memset(to, 0, sizeof to);
  memset(vis, 0, sizeof vis);
  int ans = 0;
  for (int i = 1; i <= n; ++i, ++cnt)
    ans += dfs(i);
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  k = n - k + 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &a[i][j]);
  int l = 0, r = 1e9;
  while (l < r) {
    mid = (l + r) >> 1;
    if (judge() >= k)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l;
}