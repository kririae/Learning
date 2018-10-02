#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5, MOD = 998244353;
ll t, n, m, k, f[N << 1], inv[N << 1], ans;
inline ll fpow(ll a, ll p, ll mod) {
  ll ans = 1;
  for (; p; p >>= 1) {
    if(p & 1) (ans *= a) %= mod;
    (a *= a) %= mod;
  } return ans;
}
inline ll C(ll n, ll m) {
  return ((f[n] * fpow(f[m], MOD - 2, MOD) % MOD) * fpow(f[n - m], MOD - 2, MOD)) % MOD; 
}
int main() {
  inv[0] = 1, f[0] = 1;
  for (int i = 1; i <= ((int)1e5 << 1); ++i)
    f[i] = (f[i - 1] * i) % MOD;
  scanf("%lld", &t);
  while(t--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    ans = 0;
    for (int i = 0; i <= m; ++i) {
      ll res = (C(m, i) * C(m + k - 1 - i * n, m - 1)) % MOD;
      if(i % 2) ans = (ans - res + MOD) % MOD;
      else (ans += res) %= MOD;
    }
    printf("%lld\n", ans);
  }
}