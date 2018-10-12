#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1005;
struct T {
  ll pos, speed;
} a[N];
ll n, m, d, rest[N], b[N][N];
int vis[N];
int main() {
  freopen("catch.in", "r", stdin);
  freopen("catch.out", "w", stdout);
  scanf("%lld%lld%lld", &n, &m, &d);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &rest[i]);
  sort(rest + 1, rest + 1 + n);
  for (int i = 1; i <= m; ++i)
    scanf("%lld%lld", &a[i].pos, &a[i].speed);
  // ll cnt = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (a[j].pos <= d)
        b[i][j] = 1;
      a[j].pos += rest[i] * a[j].speed;
    }
  // ll tmp = 0;
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j)
  //     if ((double)(d - a[j].pos) / a[j].speed <= tmp)
  //       b[i][j] = 1;
  //   tmp += rest[i];
  // }
  int ans = 0;
  for (int i = n; i >= 1; --i)
    for (int j = 1; j <= m; ++j)
      if (!vis[j] && b[i][j]) {
        vis[j] = 1, ++ans;
        break;
      }
  cout << ans;
}