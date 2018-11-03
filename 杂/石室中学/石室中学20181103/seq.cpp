#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, a[N], s1[N], s2[N];
inline int rev(int l, int r) {
  memset(s1, 0, sizeof s1);
  memset(s2, 0, sizeof s2);
  for (int i = 0; i < (r - l + 1) >> 1; ++i)
    swap(a[l + i], a[r - i]);
  for (int i = 1; i <= n; ++i) {
    s1[i] += s1[i - 1] + (a[i] == 1);
    s2[i] += s2[i - 1] + (a[i] == 2);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans = max(ans, s1[i] + s2[n] - s2[i - 1]);
  for (int i = 0; i < (r - l + 1) >> 1; ++i)
    swap(a[l + i], a[r - i]);
  return ans;
}
int main() {
  freopen("seq.in", "r", stdin);
  freopen("seq.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j)
      ans = max(ans, rev(i, j));
   cout << ans;
}
