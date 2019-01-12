#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100005;
int n, a[N], b[N], cnt[N]; ll k;
inline ll judge(ll x) {
  memset(cnt, 0, sizeof cnt);
  ll ans = 0;
  int l = 1, r = 1;
  for (; r <= n; ++r) {
    ++cnt[a[r]];
    if (cnt[a[r]] <= x) continue;
    while (l < r) {
      --cnt[a[l]];
      if (cnt[a[r]] > x) ++l;
      else { 
        ++cnt[a[l]];
        break; 
      }
    }
    ans += l;
  }
  return ans;
}
int main() {
  scanf("%d%lld", &n, &k);
  k = 1ll * n * (n - 1) / 2 - k + 1;
  for (int i = 1; i <= n; ++i) 
    scanf("%d", &a[i]), b[i] = a[i];
  sort(b + 1, b + 1 + n);
  int sz = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
  // 离散化
  int l = 1, r = n, ans = 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (judge(mid) <= k) ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  cout << ans << endl;
}

/*
10 38
78539228 35927435 482577948 131542206 301537411 254302661 283470177 106922762 526138122 293714725 
 */