#include <bits/stdc++.h>
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

const int N = 100005 * 20;
int n, m, rt[N], a[N], b[N], 
son[N << 2][2], s[N << 2], cnt;
inline int Build(int l, int r) {
  int k = ++cnt;
  int mid = l + r >> 1;
  if (l < r) 
    ls = Build(l, mid),
    rs = Build(mid + 1, r);
  return k;
}
inline int Update(int u, int l, int r, int x) {
  // 将x位置上的数设置为1。
  int k = ++cnt;
  int mid = l + r >> 1;
  ls = son[u][0];
  rs = son[u][1];
  s[k] = s[u] + 1;
  if (l < r)
    if (x <= mid)
      ls = Update(son[u][0], l, mid, x);
    else 
      rs = Update(son[u][1], mid + 1, r, x);
  return k;
}
inline int Query(int u, int v, int l, int r, int x) {
  // l -> r中比位置x小的数有多少个。
  if (l == r) return s[v] - s[u];
  int mid = l + r >> 1;
  if (x <= mid)
    return Query(son[u][0], son[v][0], l, mid, x);
  else 
    return s[son[v][0]] - s[son[u][0]] + Query(son[u][1], son[v][1], mid + 1, r, x);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  int sz = unique(b + 1, b + 1 + n) - b - 1;
  rt[0] = Build(1, sz);
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
  for (int i = 1; i <= n; ++i)
    rt[i] = Update(rt[i - 1], 1, sz, a[i]);
  for (int i = 1, x, y, z; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    int p = upper_bound(b + 1, b + 1 + sz, z) - b;
    cout << Query(rt[x - 1], rt[y], 1, sz, p) << endl;
  }
}