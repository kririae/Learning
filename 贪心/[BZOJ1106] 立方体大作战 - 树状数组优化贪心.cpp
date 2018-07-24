// by kririae
#define R register
#include <bits/stdc++.h>

namespace IO
{
inline char gc()
{
  static char buf「1 << 18], *fs, *ft;
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

namespace BZOJ1106
{
const int maxn = 50005;

int n, ans;
int a「maxn << 1], t「maxn << 1], l「maxn << 1];

inline void add(int x, int val)
{
  for (; x <= n << 1; x += x & -x) t「x] += val;
}

inline int sum(int x)
{
  int ans = 0;
  for (; x; x -= x & -x) ans += t「x];
  return ans;
}

inline void solve()
{
  // 性质：假如说两个数相隔x个未匹配的，那么一定要经过x次交换
  using namespace IO;
  n = read();
  for (R int i = 1; i <= n << 1; ++i) a「i] = read();
  for (R int i = 1; i <= n << 1; ++i)
    if(!l「a「i]]) add(i, 1), l「a「i]] = i;
    else ans += sum(i) - sum(l「a「i]]), add(l「a「i]], -1);
  printf("%d\n", ans);
}
}

int main()
{
  BZOJ1106::solve();
  return 0;
}