#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 10005, mod = 1e9 + 7;
int n, a[N], f[N][2]; ll t[N];
// 到第i个点，长度为j的最长上升子序列的个数
inline void add(int x, int v)
{
  for (; x <= n; x += x & -x) (t[x] += v) %= mod;
}
inline ll get(int x)
{
  ll ans = 0;
  for (; x; x -= x & -x) (ans += t[x]) %= mod;
  return ans;
}
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int pre = 0, curr = 1;
  for (int i = 1; i <= n; ++i) add(a[i], 1);
  for (int i = 1; i <= n; ++i) f[i][pre] = 1;
  for (int k = 2; k <= n + 1; swap(pre, curr), ++k) {
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; ++i) 
      f[i][curr] = get(a[i] - 1), add(a[i], f[i][pre]);
    ll ans = get(n);
    if(ans == 0) {
      for (int i = k; i <= n + 1; ++i)
        cout << 0 << " ";
      return 0;
    } else cout << ans << " ";
  }
}