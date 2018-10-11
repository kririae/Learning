#include <bits/stdc++.h>
#define ll long long
using namespace std;

int id, t, c, m;
ll n;
inline ll fpow(ll a, ll p) {
  ll ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) ans = (1ll * a * ans) % n;
    a = (a * a) % n;
  }
  return ans;
}
int main() {
  freopen("division.in", "r", stdin);
  freopen("division.out", "w", stdout);
  scanf("%d%d", &id, &t);
  while (t--) {
    scanf("%d%d", &c, &m);
    n = 1;
    for (int i = 1, x; i <= c; ++i) {
      scanf("%d", &x);
      n *= x;
    }
    if (m == 1) {
      cout << n << endl;
      continue;
  	}
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
      ll t = fpow(i, m);
      if ((t - i + n) % n == 0)
        ++cnt;
    }
    cout << cnt % 998244353 << endl;
  }
}
/*
0
1
2 5
743 857
 */
