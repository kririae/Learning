#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;

const int N = 2005, V = 305;
int n, m, v, e, c[N], d[N], g[V][V];
double k[N], f[N][2][N];
int main() {
  memset(g, 0x3f, sizeof g);
  memset(f, 0x3f, sizeof f);
  scanf("%d%d%d%d", &n, &m, &v, &e);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
  for (int i = 1; i <= n; ++i) scanf("%lf", &k[i]);
  for (int i = 1; i <= v; ++i) g[i][i] = 0;
  for (int i = 1, a, b, w; i <= e; ++i) {
    scanf("%d%d%d", &a, &b, &w);
    g[a][b] = g[b][a] = min(g[a][b], w);
  }
  register int i, j, s;
  for (s = 1; s <= v; ++s) for (i = 1; i <= v; ++i)
    if (g[i][s] != inf) for (j = 1; j <= v; ++j) 
      g[i][j] = min(g[i][j], g[i][s] + g[s][j]);
  f[1][0][0] = f[1][1][1] = 0;
  for (int i = 2; i <= n; ++i)
    for (int j = 0; j <= m; ++j) {
      f[i][0][j] = min(f[i - 1][1][j] + 
        k[i - 1] * g[d[i - 1]][c[i]] + 
        (1 - k[i - 1]) * g[c[i - 1]][c[i]], 
        f[i - 1][0][j] + g[c[i - 1]][c[i]]);
      if (j)
        f[i][1][j] = min(f[i - 1][1][j - 1] + 
        k[i - 1] * k[i] * g[d[i - 1]][d[i]] +
        k[i - 1] * (1 - k[i]) * g[d[i - 1]][c[i]] +
        (1 - k[i - 1]) * k[i] * g[c[i - 1]][d[i]] +
        (1 - k[i - 1]) * (1 - k[i]) * g[c[i - 1]][c[i]],
        f[i - 1][0][j - 1] +
        k[i] * g[c[i - 1]][d[i]] +
        (1 - k[i]) * g[c[i - 1]][c[i]]);
    }
  double ans = inf;
  for (int i = 0; i <= m; ++i) {
    cout << ans << endl;
    ans = min(ans, min(f[n][0][i], f[n][1][i]));
  }
  printf("%.2lf", ans);
}