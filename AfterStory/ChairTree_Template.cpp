#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

const int N = 2e5 + 5;
int n, m, sz, a[N], b[N], rt[N];
int L[N * 20], R[N * 20], son[N * 20][2], s[N * 20], cnt;
inline int build(int l, int r) {
  int k = ++cnt,
      mid = (l + r) / 2;
  if (l < r)
    ls = build(l, mid),
    rs = build(mid + 1, r);
  return k;
}
inline int modify(int p, int l, int r, int v) {
  int k = ++cnt,
      mid = (l + r) / 2;
  ls = son[p][0], 
  rs = son[p][1],
  s[k] = s[p] + 1;
  if (l < r)
    if (v <= mid)
      ls = modify(son[p][0], l, mid, v);
    else 
      rs = modify(son[p][1], mid + 1, r, v);
  return k;
}
inline int query(int p, int k, int l, int r, int v) {
  if (l == r) return l;
  int b = s[son[k][0]] - s[son[p][0]],
      mid = (l + r) / 2;
  if (b >= v)
    return query(son[p][0], son[k][0], l, mid, v);
  else
    return query(son[p][1], son[k][1], mid + 1, r, v - b);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]), b[i] = a[i];
  sort(b + 1, b + 1 + n);
  sz = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
  rt[0] = build(1, sz);
  for (int i = 1; i <= n; ++i)
    rt[i] = modify(rt[i - 1], 1, sz, a[i]);
  // for (int i = 1; i <= n; ++i) cout << rt[i] << " ";
  for (int i = 1, l, r, k; i <= m; ++i) {
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", b[query(rt[l - 1], rt[r], 1, sz, k)]);
  }
}