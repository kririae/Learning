// by kririae
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char gc()
{
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read()
{
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
}

namespace BZOJ2054
{
const int maxn = 1e7 + 5;

int n, m, p, q, tot, a[maxn], fa[maxn];

inline int find(int x)
{
  return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}

inline void solve()
{
  using namespace IO;
  n = read(), m = read(), p = read(), q = read();
  for (R int i = 1; i <= n + 1; ++i) fa[i] = i;
  for (R int i = m; i >= 1; --i)
  {
    int l = (i * p % n + q) % n + 1, r =(i * q % n + p) % n + 1;
    if(l > r) swap(l, r);
    for (int j = find(l); j <= r; j = find(j))
      a[j] = i, fa[j] = j + 1, ++tot;
    if(tot == n) break;
  }
  for (R int i = 1; i <= n; ++i)
    printf("%d\n", a[i]);
}
}

int main()
{
  BZOJ2054::solve();
  return 0;
}