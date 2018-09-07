#include <iostream>
#include <cstdio>
#include <algorithm>
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

const int N = 100005 * 20;
int n, m, a[N], b[N], rt[N], son[N][2], s[N], cnt;
inline int build(int l, int r) {
  int k = ++cnt;
  int mid = l + r >> 1;
  if (l < r)
    ls = build(l, mid),
    rs = build(mid + 1, r);
  return k;
}
inline int update(int u, int l, int r, int x) {
  int k = ++cnt;
  int mid = l + r >> 1;
  s[k] = s[u] + 1;
  ls = son[u][0];
  rs = son[u][1];
  if (l < r)
    if (x <= mid) 
      ls = update(son[u][0], l, mid , x);
    else 
      rs = update(son[u][1], mid + 1, r, x);
  return k;
}
inline int query(int u, int v, int l, int r, int x) {
  // 查询u -> v中的l -> r有多少个比x小的。
  if (l >= r) return 1;
  int mid = l + r >> 1;
  int y = s[son[v][0]] - s[son[u][0]];
  if(y >= x)
    return query(son[u][0], son[v][0], l, mid, x);
  else 
    return (mid - l + 1) + query(son[u][1], son[v][1], mid + 1, r, x - y);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]), b[i] = a[i];
  sort(a + 1, a + 1 + n);
  int sz = unique(a + 1, a + 1 + n) - a - 1;
  for (int i = 1; i <= n; ++i)
    b[i] = lower_bound(a + 1, a + 1 + n, b[i]) - a;
  rt[0] = build(1, sz);
  for (int i = 1; i <= n; ++i)
    rt[i] = update(rt[i - 1], 1, sz, b[i]);
  for (int i = 1, x, y, z; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    cout << query(rt[x - 1], rt[y], 1, sz, z) << endl;
  }
}