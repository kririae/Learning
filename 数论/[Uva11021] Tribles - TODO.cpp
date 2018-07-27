// by kririae
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

int t, n, k, m;
double p[maxn], f[maxn];

inline double fpow(R double a, R int p)
{
  double ans = 1;
  for (; p; p >>= 1)
  {
    if(p & 1) ans = a * ans;
    a = a * a;
  }
  return ans;
}

int main()
{
  scanf("%d", &t);
  for (int qwq = 1; qwq <= t; ++qwq)
  {
    memset(f, 0, sizeof(f));
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; ++i) scanf("%lf", &p[i]);
    f[1] = p[0];
    for (R int i = 2; i <= m; ++i)
      for (R int j = 0; j < n; ++j)
        f[i] += p[j] * fpow(f[i - 1], j);
    printf("Case #%d: %.7lf\n", qwq, fpow(f[m], k));
  }
}