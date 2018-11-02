#include <bits/stdc++.h>
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

const int N = 1e5 + 5;
struct Range {
  int l, r, w;
  bool operator<(const Range &q) const { return r == q.r ? l < q.l : r < q.r; }
} a[N], b[N];
int n, rt, tot;
namespace Sgt {
int L[N << 1], R[N << 1], son[N << 1][2], cnt, mx[N << 1];
inline void pushup(int k) { mx[k] = max(mx[ls], mx[rs]); }
inline void build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l, R[k] = r;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
inline void modify(int k, int p, int x) {
  if (L[k] == R[k])
    return (void)(mx[k] = x);
  int mid = (L[k] + R[k]) >> 1;
  if (p <= mid)
    modify(ls, p, x);
  else
    modify(rs, p, x);
  pushup(k);
}
inline int query(int k, int l, int r) {
  // cout << l << " " << r << endl;
  if (L[k] == l && R[k] == r)
    return mx[k];
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    return query(ls, l, r);
  else if (l > mid)
    return query(rs, l, r);
  else
    return max(query(ls, l, mid), query(rs, mid + 1, r));
}
}  // namespace Sgt
int main() {
  scanf("%d", &n);
  for (int i = 1, _a, _b; i <= n; ++i) {
    scanf("%d%d", &_a, &_b);
    if (_a + _b >= n) continue;
    a[i].l = _b + 1, a[i].r = n - _a;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) {
  }
  Sgt::build(rt, 0, n);
  for (int i = 1; i <= tot; ++i) {
    Sgt::modify(rt, a[i].r, (Sgt::query(rt, 0, a[i].l - 1) + a[i].w);
  }
  cout << n - Sgt::query(rt, 0, n);
}