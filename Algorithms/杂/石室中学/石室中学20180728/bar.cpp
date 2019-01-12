// by kririae
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

namespace bar
{
inline ll gcd(ll a, ll b)
{
  return b ? gcd(b, a % b) : a;
}
inline ll fpow(ll a, ll p)
{
  ll ans = 1;
  for (; p; p >>= 1)
  {
    if(p & 1) ans = (a * ans) % mod;
    a = (a * a) % mod;
  }
  return ans;
}
struct frac
{
ll a, b;
frac() {}
frac(ll x, ll y) : a(x), b(y) {}
inline void reduct()
{
  ll g = gcd(a, b);
  a /= g, b /= g;
}
inline ll gmod()
{
  return (a * fpow(b, mod - 2)) % mod;
}
frac operator + (frac x)
{
  this->reduct(), x.reduct(); // 防止爆炸...
  frac ret = frac(a * x.b + x.a * b, b * x.b);
  ret.reduct();
  return ret;
}
frac operator * (frac x)
{
  this->reduct(), x.reduct();
  frac ret = frac(a * x.a, b * x.b);
  ret.reduct();
  return ret;
}
frac operator * (ll x)
{
  this->reduct();
  frac ret = frac(a * x, b);
  ret.reduct();
  return ret;
}
};

int n, m, c, l, r, k;
frac a[105];

inline void operate(int l, int r, int k)
{
  // 期望operate
  for (int i = l; i <= r; ++i)
  {
    // frac tmp = new frac(0, 1);
    // for (int j = 0; j < c; ++j)
    //   tmp = tmp + frac(k, r - l + 1) * ((j * a) % c);
    // a[i] = tmp;
  }
}

inline void solve()
{
  freopen("bar.in", "r", stdin);
  freopen("bar.out", "w", stdout);
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m >> c;
  for (int i = 1; i <= 105; ++i) a[i] = frac(1, 1);
  for (int i = 1; i <= m; ++i)
  {
    cin >> l >> r >> k;
  }
  puts("QAQ!!!");
}
}

int main()
{
  return bar::solve(), 0;
}