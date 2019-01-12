#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2005;
int n, q, k;
ll a[N], b[N], c[N], cnt, tot;
int main() {
  freopen("struggle.in", "r", stdin);
  freopen("struggle.out", "w", stdout);
  scanf("%d%d%d", &n, &k, &q);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &a[i]);
  ll ans = 1ll << 60;
  for (int i = 1; i <= n; ++i) {
    tot = 0;
    a[n + 1] = -(1ll << 60);
    for (int j = 1; j <= n + 1; ++j)
      if (a[j] >= a[i])
        b[++cnt] = a[j];
      else {
        sort(b + 1, b + 1 + cnt);
        for (int i = 1; i <= cnt - k + 1; ++i)
          c[++tot] = b[i];
        cnt = 0;
      }
    sort(c + 1, c + 1 + tot);
    if (tot >= q)
      ans = min(ans, c[q] - a[i]);
  }
  cout << ans;
}