// 日常被q234rty救活
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 50005, M = 100005;
int n, m, k, x = 0, fa[N], cnt, ans;
struct Edge {
  int u, v, w, t;
  bool operator < (const Edge &e) const {
    int a = w + t * x,
        b = e.w + e.t * x;
    return a == b ? t > e.t : a < b;
  }
} a[M];
inline int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline bool judge() {
  ans = cnt = 0;
  sort(a + 1, a + 1 + m);
  for (int i = 0; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= m; ++i) {
    int x = find(a[i].u),
        y = find(a[i].v);
    if (x != y) {
      cnt += a[i].t;
      ans += a[i].w;
      fa[x] = y;
    }
  }
  return cnt >= k;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &a[i].u, &a[i].v, &a[i].w, &a[i].t);
    ++a[i].u, ++a[i].v, a[i].t ^= 1; // 调整
  }
  int l = -100, r = 100;
  while (l < r) {
    x = (l + r + 1) >> 1;
    if (judge()) l = x;
    else r = x - 1;
  }
  x = l;
  judge();
  printf("%d", ans + cnt * x - k * x);
}