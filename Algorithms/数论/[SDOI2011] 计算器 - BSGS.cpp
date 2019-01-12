// by kririae
#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline void exgcd(ll &x, ll &y, ll &g, ll a, ll b)
{
  if(b) exgcd(y, x, g, b, a % b), y -= (a / b) * x;
  else x = 1, y = 0, g = a;
}
inline ll fpow(ll a, ll p, ll mod)
{
  ll ans = 1;
  for (; p; p >>= 1) {
    if(p & 1) (ans *= a) %= mod;
    (a *= a) %= mod;
  } return ans;
}
inline ll BSGS(ll a, ll b, ll p)
{
  static map<ll, ll> fd;
  fd.clear(); int t = sqrt(p) + 1; b %= p;
  for (int j = 0; j < t; ++j)
    fd[(b * fpow(a, j, p)) % p] = j;
  if((a = fpow(a, t, p)) == 0) return b == 0 ? 1 : -1;
  for (int i = 0; i <= t; ++i) {
    ll val = fpow(a, i, p);
    int j = fd.find(val) == fd.end() ? -1 : fd[val];
    if(j >= 0 & i * t - j >= 0) return i * t - j;
  } return -1;
}
ll t, k, a, b, p, g, x, y;
int main()
{
  scanf("%lld%lld", &t, &k);
  switch(k) {
    case 1: 
      while(t--) {
        scanf("%lld%lld%lld", &a, &b, &p);
        printf("%lld\n", fpow(a, b, p));
      } break;
    case 2:
      while(t--) {
        scanf("%lld%lld%lld", &a, &b, &p);
        exgcd(x, y, g, a, p);
        if(b % g) puts("Orz, I cannot find x!");
        else printf("%lld\n", ((x * (b / g)) % p + p) % p);
      } break;
    case 3:
      while(t--) {
        scanf("%lld%lld%lld", &a, &b, &p);
        ll ans = BSGS(a, b, p);
        if(ans == -1) puts("Orz, I cannot find x!");
        else printf("%lld\n", ans);
      } break;
  }
}