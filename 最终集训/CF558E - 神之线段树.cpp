#include <bits/stdc++.h>
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

const int N = 1e5 + 5;
int n, m, t[30];
char a[N];
namespace Sgt {
int L[N << 2], R[N << 2], son[N << 2][2], cnt, rt;
int sum[N << 2][30], set[N << 2][30];
inline void merge(int a[], int b[], int c[]) {
  for (int i = 0; i <= 25; ++i)
    a[i] = b[i] + c[i];
}
inline void pushdown(int k) {
  for (int i = 0; i <= 25; ++i)
    if (~set[k][i]) {
      sum[ls][i] = (R[ls] - L[ls] + 1) * set[k][i];
      sum[rs][i] = (R[rs] - L[rs] + 1) * set[k][i];
      set[ls][i] = set[rs][i] = set[k][i];
      set[k][i] = -1;
    }
}
inline void build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l;
  R[k] = r;
  if (l == r) {
    sum[k][a[l] - 'a'] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  merge(sum[k], sum[ls], sum[rs]);
}
inline void query(int k, int l, int r) {
  if (L[k] == l && R[k] == r) {
    for (int i = 0; i <= 25; ++i)
      t[i] += sum[k][i];
    return;
  }
  pushdown(k);
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    query(ls, l, r);
  else if (l > mid)
    query(rs, l, r);
  else
    query(ls, l, mid), query(rs, mid + 1, r);
}
inline void clear(int k, int l, int r) {
  // t中有值的就clear掉。
  if (L[k] == l && R[k] == r) {
    for (int i = 0; i <= 25; ++i)
      if (t[i]) {
        sum[k][i] = 0;
        set[k][i] = 0;
      }
    return;
  }
  pushdown(k);
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    clear(ls, l, r);
  else if (l > mid)
    clear(rs, l, r);
  else
    clear(ls, l, mid), clear(rs, mid + 1, r);
  merge(sum[k], sum[ls], sum[rs]);
}
inline void Set(int k, int l, int r, int c) {
  if (L[k] == l && R[k] == r) {
    sum[k][c] = r - l + 1;
    set[k][c] = 1;
    return;
  }
  pushdown(k);
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    Set(ls, l, r, c);
  else if (l > mid)
    Set(rs, l, r, c);
  else
    Set(ls, l, mid, c), Set(rs, mid + 1, r, c);
  sum[k][c] = sum[ls][c] + sum[rs][c];
}
inline void sort(int l, int r, int typ) {
  memset(t, 0, sizeof t);
  query(rt, l, r);  // 预处理t
  clear(rt, l, r);  // 按照t对[l, r]
  int u = l;
  if (typ == 1)
    for (int i = 0; i <= 25; ++i)
      if (t[i]) {
        Set(rt, u, u + t[i] - 1, i);
        u += t[i];
      }
  if (typ == 0)
    for (int i = 25; i >= 0; --i)
      if (t[i]) {
        Set(rt, u, u + t[i] - 1, i);
        u += t[i];
      }
}
inline void output() {
  for (int i = 1; i <= n; ++i) {
    memset(t, 0, sizeof t);
    query(rt, i, i);
    for (int i = 0; i <= 25; ++i)
      if (t[i]) putchar(i + 'a');
  }
}
}  // namespace Sgt
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", a + 1);
  using Sgt::rt;
  memset(Sgt::set, -1, sizeof Sgt::set);
  Sgt::build(rt, 1, n);
  for (int i = 1, l, r, x; i <= m; ++i) {
    scanf("%d%d%d", &l, &r, &x);
    Sgt::sort(l, r, x);
  }
  Sgt::output();
}