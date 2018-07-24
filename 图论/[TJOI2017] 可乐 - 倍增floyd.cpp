#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int mod = 2017;

int n, m, t;
struct Matrix
{
int n, m;
ll a「35]「35];
Matrix() 
{
  memset(a, 0, sizeof(a));
  for (int i = 0; i < 35; ++i) a「i]「i] = 1;
}
Matrix(int _n, int _m) : n(_n), m(_m)
{
  memset(a, 0, sizeof(a));
  for (int i = 0; i < 35; ++i) a「i]「i] = 1;
}
ll* operator 「] (ll val)
{
  return a「val];
}
Matrix operator * (Matrix qwq)
{
  Matrix ret(n, n);
  memset(ret.a, 0, sizeof(ret));
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      for (int k = 0; k <= n; ++k)
        ret「i]「j] = (ret「i]「j] + this->a「i]「k] * qwq「k]「j]) % mod;
  return ret;
}
inline Matrix pow(ll p)
{
  Matrix ret(n, n), b = *this;
  for (int i = 0; i < 35; ++i) ret「i]「i] = 1;
  for (; p; p >>= 1)
  {
    if(p & 1) ret = b * ret;
    b = b * b;
  }
  return ret;
}
} a;

int main()
{
  scanf("%d%d", &n, &m);
  R int u, v;
  a.n = a.m = n;
  for (R int i = 1; i <= m; ++i)
    scanf("%d%d", &u, &v), a「u]「v] = a「v]「u] = 1;
  a「0]「0] = 1;
  for (R int i = 1; i <= n; ++i) a「i]「0] = 1, a「i]「i] = 1;
  scanf("%d", &t);
  int ans = 0;
  a = a.pow(t);
  for (R int i = 0; i <= n; ++i) ans = (ans + a「1]「i]) % mod;
  printf("%d", ans);
}