#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll k, m;
inline ll fpow(ll a, ll p, ll mod) {
  ll ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) (ans *= a) %= mod;
    (a *= a) %= mod;
  }
  return ans;
}
inline ll BSGS(ll a, ll b, ll p) {
  // a^n \equiv b \pmod{p}
  static map<ll, ll> mp;
  mp.clear();
  b %= p;
  ll t = sqrt(p) + 1;
  for (int i = 0; i < t; ++i)
    mp[b * fpow(a, i, p) % p] = i;
  for (int i = 0; i <= t; ++i) {
    ll x = fpow(a, i * t, p);
    int j = mp.find(x) == mp.end() ? -1 : mp[x];
    if (j >= 0 && i * t - j >= 0) 
      return i * t - j;
  }
  return -1;
}
int main() {
  scanf("%lld%lld", &k, &m);
  printf("%lld", BSGS(10, 9 * k + 1, m));
}