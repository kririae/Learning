#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int size = 2 + 5;
const int mod = 1000000007;

struct Martrix
{
  ll a, b, ma[size][size];
  // a -> 行数 b -> 列数
  Martrix operator * (const Martrix &val) {
    Martrix ret;
    ret.a = a, ret.b = val.b;
    for (int i = 1; i <= ret.a; ++i)
      for (int j = 1; j <= ret.b; ++j)
      {
        ll ans = 0;
        for (int k = 1; k <= a; ++k)
          ans += (ma[i][k] * val.ma[k][j] % mod);
        ret.ma[i][j] = ans;
      }
    return ret;
  }
  
  Martrix pow(ll val)
  {
    Martrix ans, b = *this;
    ans.a = 2, ans.b = 2;
    ans.ma[1][1] = 1, ans.ma[2][2] = 1;
    for (int i = 0; i <= 62; ++i)
    {
      if((val >> i) & 1)
         ans = b * ans;
      b = b * b;
    }
    return ans;
  }
  Martrix() {
    memset(ma, 0, sizeof(ma));
  }
};

ll n, m;
Martrix a, b, c;

int main()
{
  cin >> n;
  a.a = 2, a.b = 2, b.a = 2, b.b = 2;
  a.ma[1][1] = 1, a.ma[1][2] = 1;
  a.ma[2][1] = 1, a.ma[2][2] = 0;
  b = a.pow(n - 1);
  c.a = 1, c.b = 2;
  c.ma[1][1] = 1, c.ma[1][2] = 1;
  c = b * c;
  cout << c.ma[1][2] << endl;
}