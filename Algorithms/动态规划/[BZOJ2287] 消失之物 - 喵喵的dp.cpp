#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2050, mod = 10;

int n, m, w[maxn], f[maxn], g[maxn];

int main()
{
  scanf("%d%d", &n, &m);
  for (R int i = 1; i <= n; ++i) scanf("%d", &w[i]);
  f[0] = 1;
  for (R int i = 1; i <= n; ++i)
    for (R int j = m; j >= w[i]; --j)
      f[j] = (f[j] + f[j - w[i]]) % 10;
  for (R int i = 1; i <= n; ++i)
  {
    // 假设i物品没有
    memcpy(g, f, sizeof(f));
    for (R int j = w[i]; j <= m; ++j)
      g[j] = (g[j] - g[j - w[i]] + 10) % 10;
    for (R int j = 1; j <= m; ++j)
      printf("%d", g[j]);
    puts("");
  }
}