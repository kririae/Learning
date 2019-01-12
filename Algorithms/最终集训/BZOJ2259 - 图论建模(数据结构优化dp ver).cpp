#include <bits/stdc++.h>
#define ll long long
#define oo 0x3f3f3f3f
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read() {
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 1000005;
int n, a[N], f[N];
struct Sgt {
int rt, L[N << 2], R[N << 2], son[N << 2][2], cnt;
ll _min1[N << 2], _min2[N << 2];
inline void pushup(int k) {
  _min1[k] = min(_min1[ls], _min1[rs]);
  _min2[k] = min(_min2[ls], _min2[rs]);
}
inline void Build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l;
  R[k] = r;
  int mid = l + r >> 1;
  if (l == r) {
    _min1[l] = _min2[l] = oo;
    return;
  }
  Build(ls, l, mid),
  Build(rs, mid + 1, r);
  pushup(k);
}
inline void Modify(int k, int p, int x1, int x2) {
  if (L[k] == R[k])
    return (void) (_min1[k] = x1, _min2[k] = x2);
  int mid = L[k] + R[k] >> 1;
  if (p <= mid)
    Modify(ls, p, x1, x2);
  else 
    Modify(rs, p, x1, x2);
  pushup(k);
}
inline int Query01(int k, int l, int r) {
  if (l > r) return oo;
  if (L[k] == l && R[k] == r)
    return _min1[k];
  int mid = L[k] + R[k] >> 1;
  if (r <= mid)
    return Query01(ls, l, r);
  else if (l > mid)
    return Query01(rs, l, r);
  else 
    return min(Query01(ls, l, mid), Query01(rs, mid + 1, r));
}
inline int Query02(int k, int l, int r) {
  if (l > r) return oo;
  if (L[k] == l && R[k] == r)
    return _min2[k];
  int mid = L[k] + R[k] >> 1;
  if (r <= mid)
    return Query02(ls, l, r);
  else if (l > mid)
    return Query02(rs, l, r);
  else 
    return min(Query02(ls, l, mid), Query02(rs, mid + 1, r));
}
} t;
int main() {
  n = read();
  for (int i = 1; i <= n; ++i)
    a[i] = read();
  t.Build(t.rt, 1, n);
  for (int i = n; i >= 1; --i) {
    f[i] = abs(a[i] - (n - i));
    if (i + 1 <= i + a[i] + 1)
      f[i] = min(f[i], t.Query02(t.rt, i + 1, min(i + a[i] + 1, n)) + (i + a[i] + 1));
    if (i + a[i] + 1 <= n)
      f[i] = min(f[i], t.Query01(t.rt, i + a[i] + 1, n) - (i + a[i] + 1));
    t.Modify(t.rt, i, f[i] + i, f[i] - i);
    // for (int j = i + 1; j <= n; ++j)
    //   f[i] = min(f[i], f[j] + abs(j - (i + a[i] + 1)));
  }
  printf("%d", f[1]);
}