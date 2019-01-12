// by kririae
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace Dissipation
{
struct Matrix
{
ll n, m;
double a[105][105];
Matrix() { memset(a, 0, sizeof(a)); }
Matrix(int _n, int _m) : n(_n), m(_m) { memset(a, 0, sizeof(a)); }
double* operator [] (int x) { return a[x]; }
Matrix operator * (Matrix x) 
{
  Matrix ret(n, x.m);
  register int i, j, k;
  for (i = 0; i < n; ++i)
    for (j = 0; j < x.m; ++j) {
      double ans = 0;
      for (k = 0; k < n; ++k) 
        ans += a[i][k] * x[k][j];
      ret[i][j] = ans;
    }
  return ret;
}
Matrix pow(ll p)
{
  Matrix ret(n, n), b = *this;
  for (int i = 0; i < 105; ++i) ret[i][i] = 1;
  for (; p; p >>= 1) {
    if(p & 1) ret = b * ret;
    b = b * b;
  } return ret;
}
};
int n, k;
double p;
inline void solve()
{
  cin >> n >> k >> p;
  Matrix trans(k, k), init(k, 1);
  for (int i = 0; i < k; ++i) {
    trans[i][(i << 1) % k] += p;
    trans[i][((i << 1) + 1) % k] += (1 - p);
  }
  init[0][0] = 1;
  init = trans.pow(n) * init;
  double ans = 1;
  for (int i = 0; i < k; ++i) ans = min(ans, init[i][0]);
  printf("%.3lf", ans);
}
}

int main()
{
  return Dissipation::solve(), 0;
}