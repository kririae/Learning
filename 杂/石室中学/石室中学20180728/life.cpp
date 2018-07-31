// 贼棒的图论建模
// by kririae
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

namespace Life
{
const int maxn = 1005;

int n, t, a[maxn][maxn], dfn[maxn], low[maxn], cnt, tot;
stack<int> s;
bitset<maxn> vis;

inline void tarjan(int x)
{
  dfn[x] = low[x] = ++cnt;
  s.push(x), vis[x] = 1;
  for (int i = 1; i <= n; ++i)
  {
    if(!a[x][i]) continue;
    if(!dfn[i])
    {
      tarjan(i);
      low[x] = min(low[x], low[i]);
    } else if(vis[i]) low[x] = min(low[x], dfn[i]);
  }
  if(low[x] == dfn[x])
  {
    int curr; ++tot;
    do {
      curr = s.top(); s.pop(); vis[curr] = 0;
    } while(curr != x);
  }
}
inline void solve()
{
  using namespace IO;
  t = read();
  while(t--)
  {
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(a, 0, sizeof(a));
    while(!s.empty()) s.pop();
    vis.reset(); cnt = 0; tot = 0;
    n = read();
    int flag = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        a[i][j] = read();
    for (int i = 1; i <= n; ++i)
          if(!dfn[i]) tarjan(i);
    if(tot == 1) puts("YES");
    else puts("NO");
  }
}
}

int main()
{
  return Life::solve(), 0;
}