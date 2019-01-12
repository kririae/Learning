#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N = 100005, M = 15;
int n, m, a[M][N], pos[M][N];  // p[i][j]表示$j$在$i$数列中出现的位置
ull b[M][N], pw[N], p = 19260817;
inline bool insert(int p, int len) {
  if (p + len - 1 >= n) return false;
  ull v = b[1][p + len - 1] - b[1][p - 1] * pw[len];
  for (int i = 2; i <= m; ++i) {
    if (pos[i][a[1][p]] + len - 1 >= n) return false;
    int r = pos[i][a[1][p]] + len - 1, l = pos[i][a[1][p]];
    if (b[i][r] - b[i][l - 1] * pw[len] != v) return false;
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &a[i][j]);
      pos[i][a[i][j]] = j;
    }
  pw[0] = 1;
  for (int i = 1; i <= n; ++i)
    pw[i] = pw[i - 1] * p;
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j)
      b[i][j] = b[i][j - 1] * p + a[i][j];
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (check(i, mid))
        l = mid;
      else
        r = mid - 1;
    }
    ans += l;
  }
  cout << ans;
}