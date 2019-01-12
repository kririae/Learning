#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 55;
int t; ll a, b, n, ans, cnt, p[N], c[N];;
inline ll work(ll x, ll n) {
  static ll ans, cnt, p[N], c[N];
  cnt = 0, ans = 0;
  memset(p, 0, sizeof(p));
  memset(c, 0, sizeof(c));
  for (ll i = 2; i * i <= n; ++i)
    if(n % i == 0) {
      p[++cnt] = i, c[cnt] = 0;
      while(n % i == 0) n /= i, ++c[cnt];
    }
  if(n > 1) p[++cnt] = n, c[cnt] = 1;
  // cout << cnt << endl;
  for (int i = 0; i < (1 << cnt); ++i) {
    ll tot = 1, c1 = 0;
    for (int j = 0; j < cnt; ++j)
      if(i >> j & 1) ++c1, tot *= p[j + 1];
    if(c1 % 2) ans -= x / tot;
    else ans += x / tot;
  }
  return ans;
}
int main() {
  scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    scanf("%lld%lld%lld", &a, &b, &n);
    printf("Case #%d: %lld\n", i, work(b, n) - work(a - 1, n));
  }
}