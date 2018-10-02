// 51nod 1463
#include <bits/stdc++.h>
#define oo ((int)1e9)
using namespace std;

const int N = 500005;
int n, m, l[N], r[N];
inline bool judge(int x) {
  int l1 = -oo, r1 = oo, l2 = -oo, r2 = oo;
  // 四边形的四条边。
  for (int i = 1; i <= m; ++i) {
    if (r[i] - l[i] <= x) continue;
    l1 = max(l1, l[i] + r[i] - x);
    r1 = min(r1, l[i] + r[i] + x);
    l2 = max(l2, l[i] - r[i] - x);
    r2 = min(r2, l[i] - r[i] + x);
    if (r1 < l1 || r2 < l2) return 0;
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &l[i], &r[i]);
    if (l[i] > r[i])
      swap(l[i], r[i]);
  }
  int l = 0, r = n, ans, mid;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if (judge(mid)) ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  cout << ans << endl;
}