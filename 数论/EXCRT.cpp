// by kririae
// 题解ver
#define ll long long
#include <bits/stdc++.h>

using namespace std;

inline ll mul(ll a, ll b, ll mod)
{
  ll ans = 0, x = 1;
  for (; b; b >>= 1)
  {
    ans = ans + (x * a) % mod;
    x <<= 1; x %= mod;
  }
  return ans;
}

inline void exgcd(ll &x, ll &y, ll &g, ll a, ll b)
{
  if(b) exgcd(y, x, g, b, a % b), y -= (a / b) * x;
  else x = 1, y = 0, g = a;
}

inline ll EXCRT(ll *_a, ll *_m, ll n)
{
  ll a = _a[1], m = _m[1], g, x, y;
  for (int i = 2; i <= n; ++i)
  {
    exgcd(x, y, g, m, _m[i]);
    // if((_a[i] - a) % g) return -1;
    x = mul(x, (_a[i] - a) / g, _m[i] / g);
    a = m * x + a, m = m / g * _m[i], a %= m;
  }
  return (a % m + m) % m;
}

const int maxn = 1e5 + 5;
ll n, m[maxn], a[maxn];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> m[i] >> a[i];
  cout << EXCRT(a, m, n) << endl;
}