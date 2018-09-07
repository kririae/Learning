#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 50005;
int n, k, a[N];
inline bool judge(ll x) {
  ll sum = 0, cnt = k;
  for (int i = 1; i <= n; ++i) {
    if (sum + a[i] <= x) 
      sum += a[i];
    else {
      sum = a[i];
      --cnt;
    }
  }
  return cnt > 0;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  ll l = 0, r = (ll)n * (int)1e9, ans = 0;
  while (l <= r) {
    ll mid = l + r >> 1;
    if (judge(mid)) 
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans << endl;
}