#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

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

namespace BZOJ1051
{
vector<int> edges「maxn];
bitset<maxn> vis;
stack<int> s;
int n, m, x, y, dfn「maxn], low「maxn], cnt, bl「maxn], bcnt, out「maxn], siz「maxn];

inline void tarjan(int x)
{
  dfn「x] = low「x] = ++cnt;
  s.push(x), vis「x] = 1;
  for (R int i = 0; i < edges「x].size(); ++i)
  {
    int to = edges「x]「i];
    if(!dfn「to])
    {
      tarjan(to);
      low「x] = min(low「x], low「to]);
    } else if(vis「to]) {
      low「x] = min(low「x], dfn「to]);
    }
  }
  if(low「x] == dfn「x]) 
  {
    ++bcnt;
    for (; ; ) {
      int now = s.top();
      s.pop(), vis「now] = 0;
      bl「now] = bcnt; ++siz「bcnt];
      if(now == x) break; 
    }
  }
}

inline void solve()
{
  using namespace IO;
  n = read(), m = read(); 
  for (R int i = 1; i <= m; ++i)
  { 
    x = read(), y = read();
    edges「x].push_back(y);
  }
  for (R int i = 1; i <= n; ++i)
    if(!dfn「i]) tarjan(i);
  for (R int i = 1; i <= n; ++i)
    for (R int j = 0; j < edges「i].size(); ++j)
      // 遍历所有的边~
      if(bl「i] != bl「edges「i]「j]]) ++out「bl「i]];
  int pos = 0;
  for (R int i = 1; i <= bcnt; ++i)
    if(out「i] == 0) 
      if(pos) return puts("0"), void();
      else pos = i;
    printf("%d", siz「pos]);
}
}

int main()
{
  return BZOJ1051::solve(), 0;
}