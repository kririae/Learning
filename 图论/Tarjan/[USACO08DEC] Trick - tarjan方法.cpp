// QwQ
// by kririae~
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

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

namespace USACO08Trick
{
int n, nxt[maxn], dfn[maxn], low[maxn], times;
int tot, siz[maxn], bel[maxn];
vector<int> edges[maxn];
stack<int> s;
bitset<maxn> vis;

inline void addedge(int from, int to)
{
  edges[from].push_back(to);
}

inline void tarjan(R int x)
{
  low[x] = dfn[x] = ++times;
  s.push(x), vis[x] = 1;
  for (R int i = 0; i < edges[x].size(); ++i)
  {
    R int to = edges[x][i];
    if(!dfn[to])
      tarjan(to), low[x] = min(low[x], low[to]);
    else if(vis[to]) low[x] = min(low[x], dfn[to]);
  }
  if(low[x] == dfn[x])
  {
    R int curr; ++tot;
    do {
      curr = s.top(), s.pop(), vis[curr] = 0;
      bel[curr] = tot, ++siz[tot];
    } while(curr != x);
  }
}

inline int dp(R int x)
{
  if(siz[bel[x]] == -1) return 1;
  if(siz[bel[x]] > 1) return siz[bel[x]];
  else return dp(edges[x][0]) + 1;
}
inline void solve()
{
  using namespace IO;
  n = read();
  for (R int i = 1; i <= n; ++i) addedge(i, read());
  for (R int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);
  for (R int i = 1; i <= n; ++i) siz[bel[i]] = (edges[i][0] == i ? -1 : siz[bel[i]]);
  for (R int i = 1; i <= n; ++i) if(siz[bel[i]] == 1) siz[bel[i]] = dp(i);
  for (R int i = 1; i <= n; ++i) printf("%d\n", siz[bel[i]] == -1 ? 1 : siz[bel[i]]);
}
}

int main()
{
  return USACO08Trick::solve(), 0;
}