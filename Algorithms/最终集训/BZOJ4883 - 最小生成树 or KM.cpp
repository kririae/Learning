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
const int N = 200005;
struct Edge {
  int u, v, w;
  bool operator<(const Edge &e) const { return w < e.w; }
} a[N];
int n, m, fa[N], r[N];
inline int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n + m; ++i) fa[i] = i;
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      a[++cnt].u = i;
      a[cnt].v = j + n;
      a[cnt].w = read();
    }
  sort(a + 1, a + 1 + cnt);
  ll ans = 0;
  for (int i = 1; i <= cnt; ++i) {
    int x = find(a[i].u),
        y = find(a[i].v);
    if (r[x] && r[y]) continue;
    if (x != y) {
      fa[x] = y;
      r[y] |= r[x];
      ans += a[i].w;
    } else if (!r[x])
      r[x] = 1, ans += a[i].w;
  }
  cout << ans;
}