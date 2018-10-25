#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 205, M = 1e5 + 5;
struct Q {
  int x, y, t, id;
  ll d;
} b[M];
int n, m;
ll a[N][N], g[N][N], ans[M], cnt[N][N];
int main() {
  freopen("journey.in", "r", stdin);
  freopen("journey.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      scanf("%d", &a[i][j]), g[i][j] = a[i][j];
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &b[i].t, &b[i].x, &b[i].y);
    b[i].id = i;
    if (b[i].t == 1)
      ++cnt[b[i].x][b[i].y],
          b[i].d = g[b[i].x][b[i].y],
          g[b[i].x][b[i].y] = 0x3f3f3f3f;
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  for (int i = m; i >= 1; --i) {
    if (b[i].t == 2) {
      ans[b[i].id] = g[b[i].x][b[i].y] == 0x3f3f3f3f ? -1 : g[b[i].x][b[i].y];
      continue;
    }
    if (--cnt[b[i].x][b[i].y] == 0) {
      g[b[i].x][b[i].y] = min(g[b[i].x][b[i].y], b[i].d);
      for (int j = 1; j <= n; ++j)
        for (int k = 1; k <= n; ++k)
          g[j][k] = min(g[j][k], g[j][b[i].x] + g[b[i].x][k]);
      for (int j = 1; j <= n; ++j)
        for (int k = 1; k <= n; ++k)
          g[j][k] = min(g[j][k], g[j][b[i].y] + g[b[i].y][k]);
    }
  }
  for (int i = 1; i <= m; ++i)
    if (b[i].t == 2)
      printf("%lld\n", ans[i]);
}
