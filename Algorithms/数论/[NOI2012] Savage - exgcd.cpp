// by kririae
#include <bits/stdc++.h>

using namespace std;

inline void exgcd(int &x, int &y, int a, int b)
{
  if(b) exgcd(y, x, b, a % b), y -= (a / b) * x;
  else x = 1, y = 0;
}

inline int gcd(int a, int b)
{
  return b ? gcd(b, a % b) : a;
}

int n, c[20], p[20], l[20];

inline bool judge(int M)
{
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
    {
      int a = p[i] - p[j], b = c[j] - c[i];
      a = (a % M + M) % M;
      int g = gcd(a, M);
      if(b % g == 0)
      {
        // 有解
        int x = 0, y = 0;
        exgcd(x, y, a, M);
        x = ((x * (b / g)) % (M / g) + (M / g)) % (M / g);
        if(x <= min(l[i], l[j])) return false;
      }
    }
  return true;
}

int main()
{
  scanf("%d", &n);
  int mx = 0;
  for (int i = 1; i <= n; ++i) scanf("%d%d%d", &c[i], &p[i], &l[i]), mx = max(mx, c[i]);
  for (int M = mx; M <= 1e6; ++M)
    if(judge(M)) return printf("%d", M), 0;
}