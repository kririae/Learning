// 其实是BIT
// by kririae
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

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

namespace BZOJ1588
{
const int maxn = 32767 + 5;

int n, a「maxn], b「maxn];
ll ans, t「maxn];

inline void add(int x, int val)
{
  for (; x <= n; t「x] += val, x += x & -x) ;
}

inline ll query(int l, int r)
{
  ll ans = 0;
  for (; r; ans += t「r], r -= r & -r) ;
  for (--l; l; ans -= t「l], l -= l & -l) ;
  return ans;
}

inline void solve()
{
  using namespace IO;
  n = read();
  for (R int i = 1; i <= n; ++i) b「i] = a「i] = read();
  sort(b + 1, b + 1 + n);
  for (R int i = 1; i <= n; ++i) a「i] = lower_bound(b + 1, b + 1 + n, a「i]) - b;
  for (R int i = 1; i <= n; ++i) 
  {
    add(a「i], 1);
    int x = a「i] - 1, y = a「i] + 1, mid;
    while(x >= 1 && x < a「i] - 1) 
        if(query(mid = (x + a「i] - 1) >> 1, a「i] - 1) > 0) x = mid + 1;
        else x = mid;
    for (; x >= 1 && query(x, a「i] - 1) == 0; --x) ;
    while(y <= n && y > a「i] + 1) 
        if(query(a「i] - 1, mid = (x + a「i] - 1) >> 1) > 0) y = mid + 1;
        else y = mid;
    for (; y <= n && query(a「i] + 1, y) == 0; ++y) ;
    ans += min(abs(b「x] - b「a「i]]), abs(b「y] - b「a「i]]));
  }
  printf("%lld\n", ans);
}
}

int main()
{
  return BZOJ1588::solve(), 0;
}