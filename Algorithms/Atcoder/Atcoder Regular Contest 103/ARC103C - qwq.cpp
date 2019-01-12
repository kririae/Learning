#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], cnt[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  int x = 0, y = 0, z = 0, ans = 0;
  for (int i = 1; i <= n; i += 2)
    if (++cnt[a[i]] > x)
      x = cnt[a[i]], z = a[i];
  memset(cnt, 0, sizeof cnt);
  for (int i = 2; i <= n; i += 2)
    if (a[i] != z) y = max(y, ++cnt[a[i]]);
  ans = n - x - y;
  memset(cnt, 0, sizeof cnt);
  x = 0, y = 0, z = 0;
  for (int i = 2; i <= n; i += 2)
    if (++cnt[a[i]] > y)
      y = cnt[a[i]], z = a[i];
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; i += 2)
    if (a[i] != z) x = max(x, ++cnt[a[i]]);
  cout << min(ans, n - x - y);
}