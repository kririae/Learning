// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e7 + 5, MOD = 1e9 + 7;
inline ll fpow(ll a, ll p, ll mod) {
  ll ans = 1;
  a %= mod;
  for (; p; p >>= 1) {
    if (p & 1) (ans *= a) %= mod;
    (a *= a) %= mod;
  }
  return ans;
}
ll n, l, r, cnt, fac[N], inv[N];
bitset<N> vis;
int main() {
  scanf("%lld%lld", &l, &r);
  for (int i = l; i <= r; ++i)
    if (!vis[i]) {
      ++cnt;
      for (int j = i << 1; j <= r; j += i)
        vis[j] = 1;
    }
  fac[0] = 1;
  for (int i = 1; i <= r; ++i)
    fac[i] = (fac[i - 1] * i) % MOD;
  inv[0] = 1, inv[1] = 1;
  inv[r] = fpow(fac[r], MOD - 2, MOD);
  for (int i = r - 1; i >= 0; --i)
    inv[i] = inv[i + 1] * (i + 1) % MOD;
  n = r - l + 1;
  ll ans = 0;
  for (int i = cnt; i <= n; ++i)
    ans = (ans + ((inv[i - cnt] * fac[n - cnt] % MOD) * cnt % MOD) * fac[i]) % MOD;
  cout << ans << endl;
}