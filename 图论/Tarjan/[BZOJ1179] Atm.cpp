// by kririae
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 500005;
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

namespace BZOJ1179
{
vector<int> edges「maxn], dag「maxn];
stack<int> S;
bitset<maxn> vis;
queue<int> q;
int n, m, x, y, s, p, cnt, tot;
int a「maxn], b「maxn], dfn「maxn], low「maxn], belong「maxn], sum「maxn], f「maxn];

inline void tarjan(int x)
{
  dfn「x] = low「x] = ++cnt;
  S.push(x), vis「x] = 1;
  for (R int i = 0; i < edges「x].size(); ++i)
  {
    int to = edges「x]「i];
    if(!dfn「to])
      tarjan(to), low「x] = min(low「x], low「to]);
    else if(vis「to]) low「x] = min(low「x], dfn「to]);
  }
  if(low「x] == dfn「x])
  {
    int curr; ++tot;
    do {
      curr = S.top(); S.pop(), vis「curr] = 0;
      belong「curr] = tot, sum「tot] += a「curr];
    } while(curr != x);
  }
}

inline void BFS(int s)
{
  // DAG拓扑序转移，SPFA有点大材小用了...
  vis.reset(), vis「s] = 1;
  q.push(s), f「s] = sum「s];
  while(!q.empty())
  {
    int curr = q.front(); q.pop(); vis「curr] = 0;
    for (R int i = 0; i < dag「curr].size(); ++i)
    {
      int to = dag「curr]「i];
      if(f「curr] + sum「to] > f「to])
      {
        f「to] = f「curr] + sum「to];
        if(!vis「to]) vis「to], q.push(to);
      }
    }
  }
}

inline void solve()
{
  using namespace IO;
  n = read(), m = read();
  for (R int i = 1; i <= m; ++i)
    x = read(), y = read(), edges「x].push_back(y);
  for (R int i = 1; i <= n; ++i)
    a「i] = read();
  s = read(), p = read();
  for (R int i = 1; i <= p; ++i)
    b「i] = read();
  // init
  // 其他的都不管了，我们先把点缩好~
  for (R int i = 1; i <= n; ++i)
    if(!dfn「i]) tarjan(i);
  // 缩好之后建DAG...跑dp
  for (R int i = 1; i <= n; ++i)
    for (R int j = 0; j < edges「i].size(); ++j)
    {
      int to = edges「i]「j];
      if(belong「i] != belong「to]) 
        dag「belong「i]].push_back(belong「to]);
    }
  BFS(belong「s]);
  int ans = 0;
  for (R int i = 1; i <= p; ++i)
    ans = max(ans, f「belong「b「i]]]);
  printf("%d", ans);
}
}

int main()
{
  return BZOJ1179::solve(), 0;
}