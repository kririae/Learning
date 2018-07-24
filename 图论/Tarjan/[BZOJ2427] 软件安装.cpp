// by kririae
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

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

namespace BZOJ2427
{
vector<int> edges[maxn], DAG[maxn];
stack<int> s;
int n, m, w[maxn], v[maxn], d[maxn], f[maxn][505];
int dfn[maxn], low[maxn], vis[maxn], cnt;
int belong[maxn], ws[maxn], vs[maxn], in[maxn], tot;

inline void tarjan(int x)
{
  dfn[x] = low[x] = ++cnt;
  vis[x] = 1, s.push(x);
  for (R int i = 0; i < edges[x].size(); ++i)
  {
    int to = edges[x][i];
    if(!dfn[to])
      tarjan(to), low[x] = min(low[x], low[to]);
    else if(vis[to]) 
      low[x] = min(low[x], dfn[to]);
  }
  if(low[x] == dfn[x])
  {
    int curr; ++tot;
    do {
      curr = s.top(), s.pop(), vis[curr] = 0;
      belong[curr] = tot, ws[tot] += w[curr], vs[tot] += v[curr];
    } while(curr != x);
  }
}

inline void dp(int x)
{
  for (R int i = ws[x]; i <= m; ++i) f[x][i] = vs[x];
  for (R int i = 0; i < DAG[x].size(); ++i)
  {
    int to = DAG[x][i];
    dp(to);
    for (R int j = m - ws[x]; j >= 0; --j) // 树形背包的板子...用就对了...
      for (R int k = 0; k <= j; ++k)
        f[x][j + ws[x]] = max(f[x][j + ws[x]], f[x][j + ws[x] - k] + f[to][k]);
  }
}

inline void solve()
{
  using namespace IO;
  n = read(), m = read();
  for (R int i = 1; i <= n; ++i) w[i] = read();
  for (R int i = 1; i <= n; ++i) v[i] = read();
  for (R int i = 1; i <= n; ++i) if(d[i] = read()) edges[d[i]].push_back(i);
  for (R int i = 1; i <= n; ++i)
    if(!dfn[i]) tarjan(i);
  for (R int i = 1; i <= n; ++i)
    for (R int j = 0; j < edges[i].size(); ++j)
    {
      int to = edges[i][j];
      if(belong[i] != belong[to]) ++in[belong[to]], DAG[belong[i]].push_back(belong[to]);
    }
  // for (R int i = 1; i <= tot; ++i) cout << ws[i] << " " << vs[i] << endl;
  for (R int i = 1; i <= tot; ++i)
    if(in[i] == 0) DAG[tot + 1].push_back(i); // 建虚拟节点统一森林，方便树形dp...
  dp(tot + 1);
  // cout << ws[tot + 1] << endl;
  printf("%d", f[tot + 1][m]);
}
}

int main()
{
  return BZOJ2427::solve(), 0;
}