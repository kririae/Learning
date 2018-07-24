#define ll unsigned long long
#define R register
#include <bits/stdc++.h>

using namespace std;

namespace BZOJ2875
{
ll m, a, c, f_0, n, g;

inline ll mul(ll a, ll b)
{
  ll ans = 0, q = 1;
  for (ans = 0; a; a >>= 1)
  {
    if(a & 1) ans = (ans + b) % m;
    b = (b + b) % m;
    
  }
  return ans;
}

struct Martrix
{
ll a, b, ma「5]「5];

Martrix operator * (const Martrix &val) {
  Martrix ret;
  ret.a = a, ret.b = val.b;
  for (int i = 1; i <= ret.a; ++i)
    for (int j = 1; j <= ret.b; ++j)
    {
      ll ans = 0;
      for (int k = 1; k <= a; ++k)
        ans = (ans + mul(ma「i]「k], val.ma「k]「j])) % m;
        // ans = ans + (ma「i]「k] * val.ma「k]「j]) % m;
      ret.ma「i]「j] = ans;
    }
  return ret;
}

Martrix pow(ll val) {
  Martrix b = *this, ans;
  ans.a = 2, ans.b = 2, ans.ma「1]「1] = 1, ans.ma「2]「2] = 1;
  for (; val; val >>= 1)
  {
    if(val & 1) ans = b * ans;
    b = b * b;
  }
  return ans;
}

Martrix() { memset(ma, 0, sizeof(ma)); }
Martrix(int x, int y) : a(x), b(y) {}
};

Martrix x, y, z;

inline void solve()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> m >> a >> c >> f_0 >> n >> g;
  x.a = 2, x.b = 2, x.ma「1]「1] = a, x.ma「1]「2] = 1, x.ma「2]「1] = 0, x.ma「2]「2] = 1;
  y.a = 1, y.b = 2, y.ma「1]「1] = f_0, y.ma「2]「1] = c;
  x = x.pow(n);
  cout << (x * y).ma「1]「1] % g << endl;
}
}

int main()
{
  return BZOJ2875::solve(), 0;
}