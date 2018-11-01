#include <bits/stdc++.h>
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline ll read() {
  register ll k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 5e5 + 5;
int L[N << 1], R[N << 1], son[N << 1][2], cnt;
ll sum[N << 1], mx[N << 1], lastans;
int n, c, rt, u, tot, pos[N];
inline void pushup(int k) {
  sum[k] = sum[ls] + sum[rs];
  mx[k] = max(mx[ls], mx[rs]);
}
inline void build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l, R[k] = r;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
inline void insert(int k, int p, ll len, ll h) {
  if (L[k] == R[k])
    return sum[k] = len, mx[k] = h, void();
  int mid = (L[k] + R[k]) >> 1;
  if (p <= mid)
    insert(ls, p, len, h);
  else
    insert(rs, p, len, h);
  pushup(k);
}
inline void remove(int k, int p) {
  if (L[k] == R[k])
    return sum[k] = 0, mx[k] = 0, void();
  int mid = (L[k] + R[k]) >> 1;
  if (p <= mid)
    remove(ls, p);
  else
    remove(rs, p);
  pushup(k);
}
inline ll query(int k, int l, int r) {
  if (L[k] == l && R[k] == r) return mx[k];
  int mid = (L[k] + R[k]) >> 1;
  if (r <= mid)
    return query(ls, l, r);
  else if (l > mid)
    return query(rs, l, r);
  else
    return max(query(ls, l, mid), query(rs, mid + 1, r));
}
inline int findl(int k, ll p) {
  if (L[k] == R[k]) return L[k];
  if (sum[ls] >= p)
    return findl(ls, p);
  else
    return findl(rs, p - sum[ls]);
}
inline int findr(int k, ll p) {
  if (L[k] == R[k]) return L[k];
  if (sum[ls] > p)
    return findr(ls, p);
  else
    return findr(rs, p - sum[ls]);
}
int main() {
  n = read(), c = read();
  // scanf("%d%d", &n, &c);
  build(rt, 1, n);
  for (int i = 1, t; i <= n; ++i) {
    t = read();
    // scanf("%d", &t);
    if (t == 1) {
      ll len = read(), h = read();
      if (c == 0) {
        insert(rt, ++u, len, h);
        pos[++tot] = u;
      } else {
        len = ((len * 2333 + lastans * 666) % 100000007) + 1;
        h = ((h * 2333 + lastans * 666) % 100000007) + 1;
        insert(rt, ++u, len, h);
        pos[++tot] = u;
      }
    } else if (t == 2) {
      ll x = read();
      remove(rt, pos[x]);
    } else if (t == 3) {
      ll l = read(), r = read();
      if (l > r) swap(l, r);
      l = findl(rt, l), r = findr(rt, r);
      printf("%lld\n", lastans = query(rt, l, r));
    }
  }
}
