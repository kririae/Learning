#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read() {
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 20005, M = 20005;
int n, m, k, a[N];
struct BIT {
  ll t[N];
  inline ll query(int x) {
    ll ans = 0;
    for (; x; x -= x & -x) ans += t[x];
    return ans;
  }
  inline void modify(ll p, ll x) {
    ll v = x - (query(p) - query(p - 1));
    for (; p <= n; p += p & -p) t[p] += v;
  }
} b;
namespace P50 {
int L[M], R[M];
inline void solve() {
  for (int i = 1; i <= m; ++i)
    L[i] = read(), R[i] = read();
  k = read();
  for (int i = 1; i <= n; ++i)
    b.modify(i, a[i]);
  for (int i = 1, typ, u, v; i <= k; ++i) {
    typ = read(), u = read(), v = read();
    if (typ == 1)
      b.modify(u, v);
    else {
      ll ans = 0;
      for (int j = u; j <= v; ++j)
        ans += b.query(R[j]) - b.query(L[j] - 1);
      printf("%lld\n", ans);
    }
  }
}
}  // namespace P50
int main() {
  freopen("nobb.in", "r", stdin);
  freopen("nobb.out", "w", stdout);
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  P50::solve();
}
