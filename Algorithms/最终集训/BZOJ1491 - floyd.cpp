#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 105;
ll n, m, a[N][N], e[N][N];
double ans[N];
int main() {
  scanf("%lld%lld", &n, &m);
  memset(a, 0x3f, sizeof a);
  for (int i = 1; i <= m; ++i) {
    ll u, v, w;
    scanf("%lld%lld%lld", &u, &v, &w);
    a[u][v] = a[v][u] = w;
    e[u][v] = e[v][u] = 1;
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      if (a[i][k] != 0x3f3f3f3f)
        for (int j = 1; j <= n; ++j)
          if (a[i][k] + a[k][j] < a[i][j])
            a[i][j] = a[i][k] + a[k][j],
            e[i][j] = e[i][k] * e[k][j];
          else if(a[i][k] + a[k][j] == a[i][j])
            e[i][j] += e[i][k] * e[k][j];
  for (int i = 1; i <= n; ++i) e[i][i] = 0;
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (a[i][k] + a[k][j] == a[i][j] && e[i][j])
          ans[k] += 1.0 * e[i][k] * e[k][j] / e[i][j];
  for (int i = 1; i <= n; ++i)
    printf("%.3lf\n", ans[i]);
}