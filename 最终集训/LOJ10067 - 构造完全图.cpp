#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct IO {
char ibuf[1 << 18], *s, *t, obuf[1 << 18], *o, vbuf[65];
IO() : s(ibuf), t(ibuf), o(obuf) {}
~IO() { fwrite(obuf, 1, o - obuf, stdout); }
inline char gc() {
  (s == t) && 
  (t = (s = ibuf) + fread(ibuf, 1, 1 << 18, stdin));
  return s == t ? 0 : *s++;
}
inline void pc(char c) {
  (o == obuf + (1 << 18)) &&
  (fwrite(obuf, 1, 1 << 18, stdout), o = obuf);
  *o++ = c;
}
template<typename T>
operator T() {
  register T r = 0, f = 1; 
  register char c = gc();
  for (; !isdigit(c); c = gc())
    f = c == '-' ? -1 : 1;
  for (; isdigit(c); c = gc())
    r = (((r << 2) + r) << 1) + (c - '0');
  return f == 1 ? r : -r;
}
void operator = (char x) { pc(x); }
void operator = (const char *x) {
  register int u = 0;
  while(x[u]) pc(x[u++]);
}
template<typename T>
void operator = (T x) {
  register int u = 0;
  if(x == 0) return pc('0'), void();
  if(x < 0) x = -x, pc('-');
  while(x) vbuf[++u] = x % 10 + 48, x /= 10;
  while(u) pc(vbuf[u--]);
}
} io;
const int N = 1e5 + 5;
struct Edge {
  int u, v, w;
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
} a[N];
int n, fa[N], s[N];
inline int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
  n = io;
  for (int i = 1; i <= n; ++i)
    fa[i] = i, s[i] = 1;
  for (int i = 1; i < n; ++i)
    a[i].u = io,
    a[i].v = io,
    a[i].w = io;
  sort(a + 1, a + n);
  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    int x = find(a[i].u),
        y = find(a[i].v);
    if (x != y) {
      ans += 1ll * (a[i].w + 1) * (s[x] * s[y] - 1);
      ans += a[i].w;
      s[y] += s[x];
      fa[x] = y;
    }
  }
  printf("%lld", ans);
}