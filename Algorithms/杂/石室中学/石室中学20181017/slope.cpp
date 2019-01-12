#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
struct Point {
  int x, y;
  bool operator<(const Point &p) const { return x < p.x; }
} a[N];
int n;
inline double calc(int i, int j) {
  return 1.0 * (a[j].y - a[i].y) / (a[j].x - a[i].x);
}
int main() {
  freopen("slope.in", "r", stdin);
  freopen("slope.out", "w", stdout);
  double ans = -1e9;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &a[i].x, &a[i].y);
  sort(a + 1, a + 1 + n);
  if (n <= 1000) {
    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j)
        ans = max(ans, calc(i, j));
    printf("%.3lf", ans);
    return 0;
  } else {
    for (int i = 2; i <= n; ++i)
      ans = max(ans, calc(i - 1, i));
    printf("%.3lf", ans);
    return 0;
  }
}
