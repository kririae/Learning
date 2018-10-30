#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
struct Range {
  int l, r;
  bool operator<(const Range &c) const { return r == c.r ? l < c.l : r < c.r; }
} b[N];
int n, k, m, a[N];
ll s[N];
multiset<int, greater<int> > L;
multiset<int> R;
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= m; ++i)
    scanf("%d%d", &b[i].l, &b[i].r);
  sort(b + 1, b + 1 + m);
  for (int i = 1; i <= k; ++i)
    L.insert(b[i].l), R.insert(b[i].r);
  for (int l = 1; l <= m - k + 1; ++l) {
    if (*L.begin() <= *R.begin())
      ans = max(ans, s[*R.begin() - s[*L.begin() - 1]]);
    L.erase(b[l].l), R.erase(b[l].r);
    L.insert(b[l + k].l), R.insert(b[l + k].r);
  }
  cout << ans;
}