#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 50005;
int l, n, m; ll d[N];
inline bool judge(ll x) {
  int cnt = 0, last = 0;
  for (int i = 1; i <= n; ++i)
    if (d[i] - last < x) ++cnt;
    else last = d[i];
  return cnt <= m;
}
int main() {
  scanf("%lld%d%d", &l, &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%lld", &d[i]);
  d[++n] = l;
  ll L = 0, R = l + 1, ans = 0;
  while (L <= R) {
    ll mid = L + R >> 1;
    if (judge(mid)) ans = mid, L = mid + 1;
    else R = mid - 1;
  }
  printf("%lld", ans);
}