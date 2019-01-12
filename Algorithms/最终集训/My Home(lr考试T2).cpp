#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline ll read() {
  register ll k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 1e5 + 5;
struct Q {
  int l, r, pos, id;
  bool operator < (const Q &a) const {
    if (pos == a.pos) {
      if (pos & 1) return r < a.r;
      else return r > a.r;
    } return pos < a.pos;
  }
} a[N];
int n, q, l = 1, r = 0; 
ll s[N], v, c, res[N], p;
inline ll smul(ll x, ll y) {
  if (x < y) swap(x, y);
  ll ans = 0, b = 1;
  for (; x; x >>= 1, b <<= 1)
    if (x & 1) (ans += y * b) %= p;
  return ans;
}
inline void Add(ll x) {
  c = c % p + smul(v, x);
  v = (v + x) % p;
  c = (c + p) % p;
}
inline void Delete(ll x) {
  v = (v - x) % p;
  c = c % p - smul(v, x);
  c = (c + p) % p;
}
int main() {
  scanf("%d%d%lld", &n, &q, &p);
  n = read(), q = read(), p = read();
  for (int i = 1; i <= n; ++i) s[i] = read();
  int sz = sqrt(n) + 1;
  for (int i = 1, l, r; i <= q; ++i) {
    l = read(), r = read();
    a[i].l = l, a[i].r = r;
    a[i].pos = (l / sz) + 1, a[i].id = i;
  }
  sort(a + 1, a + 1 + q);
  for (int i = 1; i <= q; ++i) {
    Q t = a[i];
    while (r > t.r) Delete(s[r]), --r;
    while (r < t.r) ++r, Add(s[r]);
    while (l < t.l) Delete(s[l]), l++;
    while (l > t.l) --l, Add(s[l]); 
    res[t.id] = c;
  }
  for (int i = 1; i <= q; ++i)
    printf("%d\n", res[i]);
}