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
ll n, m, c[N];
int main() {
  freopen("mission.in", "r", stdin);
  freopen("mission.out", "w", stdout);
  scanf("%lld%lld", &n, &m);
  c[0] = 1;
  for (int i = 1; i <= m; ++i)
    c[i] = ((c[i - 1] * (n - i + 1) % MOD) * inv(i)) % MOD;
  ll ans = 0;
  for (int i = 0; i < m; ++i)
    (ans += c[i]) %= MOD;
  cout << ((fpow(2, n, MOD) - ans) % MOD + MOD) % MOD;
}
