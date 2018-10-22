// 我大概被Cf题克...
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, a[N];
ll t, s[N], b[N];
struct BIT {
  ll t[N];
  inline void add(ll p, ll x) {
    for (++p; p <= n + 1; p += p & -p) t[p] += x;
  }
  inline ll query(ll p) {
    ll ans = 0;
    for (++p; p; p -= p & -p) ans += t[p];
    return ans;
  }
} c;
int main() {
  scanf("%d%lld", &n, &t);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    s[i] = s[i - 1] + a[i];
    b[i] = s[i];
  }
  b[n + 1] = 0;
  sort(b + 1, b + 2 + n);
  int sz = unique(b + 1, b + 2 + n) - b - 1;
  for (int i = 0; i <= n; ++i)
    s[i] = lower_bound(b + 1, b + 1 + sz, s[i]) - b;
  // 树状数组右移,
  // for (int i = 1; i <= n + 1; ++i)
  //   cout << b[i] << " ";
  // cout << endl;
  // for (int i = 0; i <= n; ++i)
  //   cout << s[i] << " ";
  // cout << endl;
  c.add(lower_bound(b + 1, b + 1 + sz, b[s[0]]) - b, 1);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    int p = lower_bound(b + 1, b + 1 + sz, b[s[i]] - t + 1) - b;
    ans += c.query(n) - c.query(p);
    c.add(s[i], 1);
  }
  cout << ans;
}