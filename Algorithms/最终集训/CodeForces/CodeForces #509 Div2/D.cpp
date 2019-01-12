#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
struct R {
  int l, r;
  bool operator<(const R &w) const { return r < w.r; }
} a[N];
int n, h, s[N];
int main() {
  scanf("%d%d", &n, &h);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &a[i].l, &a[i].r);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i)
    s[i] = s[i - 1] + a[i].l - a[i - 1].r;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int p = lower_bound(s + 1, s + 1 + n, s[i] + h) - s;
    ans = max(ans, a[p - 1].r - a[i].l - s[p - 1] + s[i] + h);
  }
  cout << ans;
}