#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 505;
struct D {
  int x, p;
  bool operator<(const D &d) const { return x < d.x; }
} a[N];
int n, m, v[N];
ll f[N][N], ans[N][N];
int main() {
  memset(f, 0x3f, sizeof f);
  memset(ans, 0x3f, sizeof f);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i].x), a[i].p = i, v[i] = a[i].x;
  for (int i = 1, u, v, w; i <= m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    f[u][v] = f[v][u] = w;
    ans[u][v] = ans[v][u] = min(ans[u][v], 1ll * w * max(a[u].x, a[v].x));
  }
  sort(a + 1, a + 1 + n);
  for (int k = 1; k <= n; ++k) {
    int u = a[k].p;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) {
        if (f[i][j] > max(f[i][u], f[u][j])) {
          f[i][j] = max(f[i][u], f[u][j]);
          ans[i][j] = min(ans[i][j], 1ll * max(a[k].x, max(v[i], v[j])) * f[i][j]);
        }
      }
  }
  for (int i = 1; i <= n; ++i)
    ans[i][i] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      if (ans[i][j] == ans[0][0])
        cout << -1 << " ";
      else
        cout << ans[i][j] << " ";
    cout << endl;
  }
}