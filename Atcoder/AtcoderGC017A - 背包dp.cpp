#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

ll n, p, a[55], f[55][2];
// 选到第i个，总和%2 = j的个数是f[i][j]。
int main()
{
  scanf("%lld%lld", &n, &p);
  for (R int i = 1; i <= n; ++i)
    scanf("%lld", &a[i]);
  f[0][0] = 1;
  for (R int i = 0; i <= n; ++i)
  {
    // 选 or 不选
    f[i + 1][a[i + 1] % 2] += f[i][0];
    f[i + 1][(1 + a[i + 1]) % 2] += f[i][1];
    f[i + 1][0] += f[i][0];
    f[i + 1][1] += f[i][1];
  }
  printf("%lld\n", f[n][p]);
}