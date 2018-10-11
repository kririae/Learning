#include <bits/stdc++.h>
#define ll long long
using namespace std;

int id, t, c, m;
ll n;
inline ll fpow(ll a, ll p, ll mod) {
  ll ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) ans = (1ll * a * ans) % mod;
    a = (a * a) % mod;
  }
  return ans;
}
inline ll calc(ll n, ll m) {
  ll cnt = 0;
  for (int i = 1; i <= n; ++i) {
    ll t = fpow(i, m, n);
    if ((t - i + n) % n == 0) ++cnt;
  }
  return cnt;
}
int main() {
  scanf("%d%d", &id, &t);
  while (t--) {
    scanf("%d%d", &c, &m);
    n = 1;
    ll ans = 1;
    for (int i = 1, x; i <= c; ++i) {
      scanf("%d", &x);
      (ans *= calc(x, m)) %= 998244353;
    }
    printf("%lld\n", ans);
  }
}