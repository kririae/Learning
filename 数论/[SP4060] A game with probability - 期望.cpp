// $f[n] = p \cdot g[n - 1] + (1 - p) \cdot g[n]$
// $g[n] = q \cdot f[n] + (1 - q) \cdot f[n - 1]$
#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

int n, t;
double p, q, f[maxn], g[maxn];

int main()
{
  cin >> t;
  while(t--)
  {
    cin >> n >> p >> q;
    n = min(n, 10000), g[0] = 1.0;
    for (int i = 1; i <= n; ++i)
    {
      if(f[i - 1] > g[i - 1]) p = 1 - p, q = 1 - q;
      g[i] = (p * q * g[i - 1] + (1 - q) * f[i - 1]) / (1 - (q * (1 - p)));
      f[i] = (p * g[i - 1] + (1 - p) * (1 - q) * f[i - 1]) / (1 - (1 - p) * q);
    }
    printf("%.6lf\n", f[n]);
  } 
}