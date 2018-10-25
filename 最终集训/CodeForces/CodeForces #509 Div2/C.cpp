#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
struct Q {
  int x, id;
  bool operator<(const Q &q) const { return x < q.x; }
} a[N];
int n, m, d, ans[N];
int main() {
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i].x), a[i].id = i;
  sort(a + 1, a + 1 + n);
  int l = 1, r = 1, cnt = 0;
  for (; l <= n; ++l) {
    if (!ans[a[l].id]) ans[a[l].id] = ++cnt;
    while (r <= n && (a[r].x - a[l].x < d + 1 || ans[a[r].id])) ++r;
    ans[a[r].id] = ans[a[l].id];
  }
  cout << cnt << endl;
  for (int i = 1; i <= n; ++i)
    cout << ans[i] << " ";
}