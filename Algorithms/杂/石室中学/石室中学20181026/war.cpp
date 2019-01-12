#include <bits/stdc++.h>
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
const int N = 2e5 + 5;
int n, m, sz, a[N], b[N], cnt[N];
namespace Pts50 {
inline int work(int l, int r) {
  memset(cnt, 0, sizeof cnt);
  for (int i = l; i <= r; ++i)
    if (++cnt[a[i]] >= 2) return 0;
  int p = -1, u = -1;
  for (int i = 1; i <= sz; ++i)
    if (cnt[i] >= 1) {
      u = p = i;
      break;
    }
  int ans = (1 << 30);
  for (;;) {
    ++u;
    while (u <= sz && cnt[u] == 0) ++u;
    if (cnt[u] == 0) break;
    ans = min(ans, abs(b[u] - b[p]));
    p = u;
  }
  return ans;
}
inline void solve() {
  for (int i = 1, l, r; i <= m; ++i) {
    l = read(), r = read();
    printf("%d\n", work(l, r));
  }
}
}  // namespace Pts50
int main() {
  freopen("war.in", "r", stdin);
  freopen("war.out", "w", stdout);
  n = read(), m = read();
  for (int i = 1; i <= n; ++i)
    a[i] = read(), b[i] = a[i];
  sort(b + 1, b + 1 + n);
  sz = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
  Pts50::solve();
}