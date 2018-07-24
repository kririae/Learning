#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
int n, k, v「maxn], r「maxn];
double ans「maxn];

inline bool cmp(double a, double b)
{
  return a > b;
}

inline double calc(double val)
{
  double res = 0;
  memset(ans, 0, sizeof(ans));
  for (R int i = 1; i <= n; ++i)
    ans「i] = (1.0 * r「i] - val * v「i]);
  sort(ans + 1, ans + 1 + n, cmp);
  for (R int i = 1; i <= k; ++i)
    res += ans「i];
  return res;
}

int main()
{
  freopen("draw.in", "r", stdin);
  freopen("draw.out", "w", stdout);
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (R int i = 1; i <= n; ++i)
    cin >> v「i] >> r「i];
  double l = 0, r = 1e9;
  while(r - l > 0.000001)
  {
    double mid = (l + r) / 2;
    if(calc(mid) >= 0) l = mid;
    else r = mid;
  }
  printf("%.2lf", l);
}
