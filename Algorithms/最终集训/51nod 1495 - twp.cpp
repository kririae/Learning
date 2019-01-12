#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e7 + 5;
int n, k, t, b, c, p, s[N];
ll a[N];
int main() {
  scanf("%d%d%d%lld%d%d%d", &n, &k, &t, &a[0], &b, &c, &p);
  for (int i = 1; i <= n; ++i) {
    a[i] = (1ll * a[i - 1] * b + c) % p;
    if (a[i] >= t)
      s[i] = s[i - 1] + 1;
    else
      s[i] = s[i - 1];
  }
  int l = 1, r = 1, cnt = 0;
  ll ans = 0;
  for (; l <= n; ++l) {
    while (r <= n && s[r] - s[l - 1] < k) ++r;
    if (r > n) break;
    ans += (n - r + 1);
  }
  cout << ans;
}