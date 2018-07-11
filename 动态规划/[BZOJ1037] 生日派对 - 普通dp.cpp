/*
已经放了i个男孩，j个女孩，男孩最多比女孩多k，女孩最多比男孩多l的方案数
我们考虑放i + 1个男孩...j + 1个女孩，如果是i + 1个男孩的话，
f[i + 1][j][k + 1][l - 1] += f[i][j][k][l];
f[i][j + 1][k - 1][l + 1] += f[i][j][k][l];
 */
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 150 + 5, mod = 12345678;

int n, m, k, f[maxn][maxn][25][25], ans;

inline void inc(int &a, int val)
{
  a = (ll)(a + val) % mod;
}

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  f[0][0][0][0] = 1;
  R int i, j, qwq, pwp;
  for (i = 0; i <= n; ++i)
    for (j = 0; j <= m; ++j)
      for (qwq = 0; qwq <= k; ++qwq)
        for (pwp = 0; pwp <= k; ++pwp)
          inc(f[i + 1][j][qwq + 1][pwp ? pwp - 1 : 0], f[i][j][qwq][pwp]),
          inc(f[i][j + 1][qwq ? qwq - 1 : 0][pwp + 1], f[i][j][qwq][pwp]);
  for (qwq = 0; qwq <= k; ++qwq)
    for (pwp = 0; pwp <= k; ++pwp)
      inc(ans, f[n][m][qwq][pwp]);
  printf("%d", ans);
}