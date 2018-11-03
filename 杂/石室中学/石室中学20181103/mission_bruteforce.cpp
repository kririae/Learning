#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100005, MOD = 1e9 + 7;
inline ll fpow(ll a, ll p, ll mod) {
  ll ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) ans = (a * ans) % MOD;
    a = (a * a) % MOD;
  }
  return ans;
}
inline ll inv(ll a, ll p = MOD) {
  return fpow(a, p - 2, p);
}
ll n, m, p[N << 1];
inline ll C(ll n, ll m) {
  return ((p[n] * inv(p[m])) % MOD * (inv(p[n - m]) % MOD)) % MOD;
}
int main() {
  // freopen("mission.in", "r", stdin);
  // freopen("mission.out", "w", stdout);
  scanf("%lld%lld", &n, &m);
  p[0] = 0, p[1] = 1;
  for (int i = 2; i <= n + m; ++i)
    p[i] = (p[i - 1] * i) % MOD;
  ll ans = 0;
  for (int i = m; i < n; ++i)
    (ans += C(n, i)) %= MOD;
  for (int i = 1; i <= m; ++i)
  	cout << C(n, i) << " ";
  printf("%lld\n", ans + 1);
}
