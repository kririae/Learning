#define ull unsigned long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int siz = 5;

namespace BZOJ2326
{
ull n, l, MOD;

struct Matrix
{
ull n, m, a[siz][siz];

Matrix()
{
  memset(a, 0, sizeof(a));
  for (R int i = 0; i < siz; ++i) a[i][i] = 1;
}
Matrix(int _n, int _m) : n(_n), m(_m) 
{
  memset(a, 0, sizeof(a));
  for (R int i = 0; i < siz; ++i) a[i][i] = 1;
}

ull* operator [] (int x) 
{
  return a[x];
}

inline Matrix operator * (Matrix val)
{
  Matrix ans(this->n, val.m);
  R int i, j, k;
  for (i = 1; i <= this->n; ++i)
    for (j = 1; j <= val.m; ++j)
    {
      ull res = 0;
      for (k = 1; k <= this->n; ++k)
        res += (a[i][k] * val[k][j] % MOD);
      ans[i][j] = res;
    }
  return ans;
}
inline Matrix pow(ull p)
{
  if(n != m) return Matrix(this->n, this->n);
  Matrix ans(this->n, this->n), t = *this;
  for (; p; p >>= 1)
  {
    if(p & 1) ans = t * ans;
    t = t * t;
  }
  return ans;
}
} qwq(3, 1), tmp(3, 3);

inline ull pow(ull a, ull p)
{
  ull ans = 1; a %= MOD;
  for (; p; p >>= 1)
  {
    if(p & 1) ans = (a * ans) % MOD;
    a = (a * a) % MOD;
  }
  return ans;
}

inline int len(ull val)
{
  int cnt = 0;
  while(val) ++cnt, val /= 10;
  return cnt;
}

inline void trans(Matrix &val, ull _l, ull _r)
{
  _r = (_l % 10 ? _r : _r + 1);
  tmp[1][1] = pow(10, len(_l));
  val = tmp.pow(_r - _l) * val;
}

inline void solve()
{
  scanf("%lld%lld", &n, &MOD);
  qwq[1][1] = qwq[2][1] = qwq[3][1] = 1;
  tmp[1][2] = tmp[1][3] = tmp[2][2] = tmp[2][3] = tmp[3][3] = 1;
  R ull l = 1, r = 9;
  for (; r <= n; l *= 10, r = l * 10 - 1) trans(qwq, l, r);
    trans(qwq, l, n);
  printf("%lld", qwq[1][1] % MOD);
}
}

int main()
{
  return BZOJ2326::solve(), 0;
}