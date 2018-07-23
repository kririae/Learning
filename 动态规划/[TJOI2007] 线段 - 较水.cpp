#include <bits/stdc++.h>

using namespace std;

const int maxn = 20005;

int n, ans, L[maxn], R[maxn], f[maxn][2]; // f[i][0], f[i][1]表示在左边右边

int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &L[i], &R[i]);
  f[1][0] = (R[1] - 1) + R[1] - L[1], f[1][1] = R[1] - 1;
  for (int i = 1; i < n; ++i)
  {
    f[i + 1][0] = min(f[i][0] + abs(R[i + 1] - L[i]), f[i][1] + abs(R[i + 1] - R[i])) + R[i + 1] - L[i + 1] + 1;
    f[i + 1][1] = min(f[i][0] + abs(L[i + 1] - L[i]), f[i][1] + abs(L[i + 1] - R[i])) + R[i + 1] - L[i + 1] + 1;
  }
  ans = min(f[n][0] + n - L[n], f[n][1] + n - R[n]);
  printf("%d", ans);
}