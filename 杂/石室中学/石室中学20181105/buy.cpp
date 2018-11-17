#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, K, c[N], f[2][N][N];
vector<int> ans;
int main() {
  freopen("buy.in", "r", stdin);
  freopen("buy.out", "w", stdout);
  scanf("%d%d", &n, &K);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &c[i]);
  f[0][0][0] = 1;
  int x = 0, y = 1;
  for (int i = 1; i <= n; ++i, swap(x, y)) {
    for (int j = 0; j <= K; ++j)
      for (int k = 0; k <= K; ++k)
        f[y][j][k] = f[x][j][k];
    for (int j = 0; j <= K; ++j)
      for (int k = 0; k <= K; ++k)
        if (j - c[i] >= 0) {
          if (k - c[i] >= 0)
            f[y][j][k] |= f[x][j - c[i]][k - c[i]];
          f[y][j][k] |= f[x][j - c[i]][k];
        }
  }
  for (int i = 0; i <= K; ++i)
    if (f[n & 1][K][i])
      ans.push_back(i);
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%d ", ans[i]);
}
