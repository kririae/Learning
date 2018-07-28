// 50pts
#define ll unsigned long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int mod = 19260817;

struct Matrix
{
ll n, m, a[205][205];
Matrix()
{
  memset(a, 0, sizeof(a));
}
Matrix(int _n, int _m) : n(_n), m(_m)
{
  memset(a, 0, sizeof(a));
}
ll* operator [] (ll x)
{
  return a[x];
}
inline bool check()
{
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if(a[i][j] == 0) return false;
  return true;
}
inline Matrix operator * (Matrix val)
{
  Matrix ans(this->n, val.m);
  R int i, j, k;
  for (i = 1; i <= this->n; ++i)
    for (j = 1; j <= val.m; ++j)
    {
      ll res = 0;
      for (k = 1; k <= this->n; ++k)
        res += (a[i][k] * val[k][j] % 19260817);
      ans[i][j] = res;
    }
  return ans;
}
inline Matrix pow(ll p)
{
  if(n != m) return Matrix(this->n, this->n);
  Matrix ans(this->n, this->n), t = *this;
  for (int i = 0; i <= n + 1; ++i) ans[i][i] = 1;
  for (; p; p >>= 1)
  {
    if(p & 1) ans = t * ans;
    t = t * t;
  }
  return ans;
}
};

int n, t;
int main()
{
    freopen("life.in", "r", stdin);
    freopen("life.out", "w", stdout);
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> t;
  while(t--)
  {
    cin >> n;
    Matrix qwq(n, n);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        cin >> qwq[i][j];
    qwq = qwq.pow(200);
    if(qwq.check()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}