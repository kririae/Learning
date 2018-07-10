#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

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

namespace BZOJ1131
{
int n;
ll f[maxn], siz[maxn], dep[maxn];
vector<int> edges[maxn];

inline void addedge(int a, int b)
{
  edges[a].push_back(b), edges[b].push_back(a);
}

inline int dfs1(int k, int fa)
{
  siz[k] = 1, dep[k] = dep[fa] + 1;
  for (R int i = 0; i < edges[k].size(); ++i) 
    if(edges[k][i] != fa) siz[k] += dfs1(edges[k][i], k);
  return siz[k];
}

inline void dfs2(int k, int fa)
{
  for (R int i = 0; i < edges[k].size(); ++i)
    if(edges[k][i] != fa) 
      f[edges[k][i]] = f[k] - (siz[edges[k][i]] << 1) + n, dfs2(edges[k][i], k);
}

inline void solve()
{
  using namespace IO;
  n = read();
  for (R int i = 1; i < n; ++i) addedge(read(), read());
  dfs1(1, 1);
  for (R int i = 1; i <= n; ++i) f[1] += dep[i];
  dfs2(1, 1);
  ll pos = 1, maxv = 0;
  for (R int i = 1; i <= n; ++i) if(f[i] > maxv) maxv = f[i], pos = i;
  printf("%d", pos);
}
}

int main()
{
    return BZOJ1131::solve(), 0;
}