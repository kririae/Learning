#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 25;
ll n, m, a[N][N], mid, vis[N][N];
map<ll, ll> cnt[N];
ll ans = 0, k = 0;
inline void dfs1(int x, int y, ll u) {
  if (vis[x][y]) {
    ++cnt[x][u];
    return;
  }
  if (a[x + 1][y]) dfs1(x + 1, y, u ^ a[x + 1][y]);
  if (a[x][y + 1]) dfs1(x, y + 1, u ^ a[x][y + 1]);
}
inline void dfs2(int x, int y, ll u) {
  if (vis[x - 1][y])
    ans += cnt[x - 1][k ^ u];
  if (vis[x][y - 1])
  	ans += cnt[x][k ^ u];
  if (!vis[x - 1][y] && a[x - 1][y]) dfs2(x - 1, y, u ^ a[x - 1][y]);
  if (!vis[x][y - 1] && a[x][y - 1]) dfs2(x, y - 1, u ^ a[x][y - 1]);
}
int main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  scanf("%lld%lld%lld", &n, &m, &k);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%lld", &a[i][j]);
  for (int i = 1; i <= n; ++i) {
  	if (i > m) break;
  	vis[i][m - i + 1] = 1;
  }
  if (a[1][1] == 0 || a[n][m] == 0) {
    puts("0");
    return 0;
  }
  dfs1(1, 1, a[1][1]);
  dfs2(n, m, a[n][m]);
  cout << ans;
}
