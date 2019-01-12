{}
date: 2018-07-13 03:48:35
---
# 「学习笔记」Tarjan算法

## Tarjan算法简介
咕咕咕~
2018 - 7 - 13
尊从不咕咕咕的信念，我来补一点

## 「NOIP2009」信息传递

统计强连通分量里的最大size

```cpp
#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

vector<int> edges[maxn];
int n, dfn[maxn], low[maxn], cnt, ans = maxn, x;
bitset<maxn> vis;
stack<int> s;

inline void tarjan(int x)
{
  // 再打一次~
  low[x] = dfn[x] = ++cnt;
  s.push(x), vis[x] = 1;
  for (R int i = 0; i < edges[x].size(); ++i)
  {
    int to = edges[x][i];
    if(!dfn[to])
    {
      // 如果to在dfs树上
      tarjan(to);
      low[x] = min(low[x], low[to]);
    } else if(vis[to]) {
      // 如果to不在dfs树上，用dfn更新low[x]
      low[x] = min(low[x], dfn[to]);
    }
  }
  if(low[x] == dfn[x]) 
  {
    // 又到了pop的季节
    int cnt = 0;
    for (; ;)
    {
      int curr = s.top();
      s.pop(), ++cnt, vis[curr] = 0;
      if(curr == x) break;
    } // 把需要pop的都pop出来
    if(cnt > 1) ans = min(ans, cnt); // 如果不光是这条边的话
  }
}

int main()
{
  scanf("%d", &n);
  for (R int i = 1; i <= n; ++i)
  { 
    scanf("%d", &x);
    edges[i].push_back(x);
  }
  for (R int i = 1; i <= n; ++i)
    if(!dfn[i]) tarjan(i);
  printf("%d", ans);
}
```

## 「BZOJ1051」受欢迎的牛

缩点后统计出度为0的个数，然后输出连通图的size

```cpp
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

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

namespace BZOJ1051
{
vector<int> edges[maxn];
bitset<maxn> vis;
stack<int> s;
int n, m, x, y, dfn[maxn], low[maxn], cnt, bl[maxn], bcnt, out[maxn], siz[maxn];

inline void tarjan(int x)
{
  dfn[x] = low[x] = ++cnt;
  s.push(x), vis[x] = 1;
  for (R int i = 0; i < edges[x].size(); ++i)
  {
    int to = edges[x][i];
    if(!dfn[to])
    {
      tarjan(to);
      low[x] = min(low[x], low[to]);
    } else if(vis[to]) {
      low[x] = min(low[x], dfn[to]);
    }
  }
  if(low[x] == dfn[x]) 
  {
    ++bcnt;
    for (; ; ) {
      int now = s.top();
      s.pop(), vis[now] = 0;
      bl[now] = bcnt; ++siz[bcnt];
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
    edges[x].push_back(y);
  }
  for (R int i = 1; i <= n; ++i)
    if(!dfn[i]) tarjan(i);
  for (R int i = 1; i <= n; ++i)
    for (R int j = 0; j < edges[i].size(); ++j)
      // 遍历所有的边~
      if(bl[i] != bl[edges[i][j]]) ++out[bl[i]];
  int pos = 0;
  for (R int i = 1; i <= bcnt; ++i)
    if(out[i] == 0) 
      if(pos) return puts("0"), void();
      else pos = i;
    printf("%d", siz[pos]);
}
}

int main()
{
  return BZOJ1051::solve(), 0;
}
```

## 「BZOJ1179」Atm

缩点，记录块的权值和，然后在缩点上跑DAG最长路

```cpp
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

namespace BZOJ1179
{
vector<int> edges[maxn], dag[maxn];
stack<int> S;
bitset<maxn> vis;
queue<int> q;
int n, m, x, y, s, p, cnt, tot;
int a[maxn], b[maxn], dfn[maxn], low[maxn], belong[maxn], sum[maxn], f[maxn];

inline void tarjan(int x)
{
  dfn[x] = low[x] = ++cnt;
  S.push(x), vis[x] = 1;
  for (R int i = 0; i < edges[x].size(); ++i)
  {
    int to = edges[x][i];
    if(!dfn[to])
      tarjan(to), low[x] = min(low[x], low[to]);
    else if(vis[to]) low[x] = min(low[x], dfn[to]);
  }
  if(low[x] == dfn[x])
  {
    int curr; ++tot;
    do {
      curr = S.top(); S.pop(), vis[curr] = 0;
      belong[curr] = tot, sum[tot] += a[curr];
    } while(curr != x);
  }
}

inline void BFS(int s)
{
  // DAG拓扑序转移，SPFA有点大材小用了...
  vis.reset(), vis[s] = 1;
  q.push(s), f[s] = sum[s];
  while(!q.empty())
  {
    int curr = q.front(); q.pop(); vis[curr] = 0;
    for (R int i = 0; i < dag[curr].size(); ++i)
    {
      int to = dag[curr][i];
      if(f[curr] + sum[to] > f[to])
      {
        f[to] = f[curr] + sum[to];
        if(!vis[to]) vis[to], q.push(to);
      }
    }
  }
}

inline void solve()
{
  using namespace IO;
  n = read(), m = read();
  for (R int i = 1; i <= m; ++i)
    x = read(), y = read(), edges[x].push_back(y);
  for (R int i = 1; i <= n; ++i)
    a[i] = read();
  s = read(), p = read();
  for (R int i = 1; i <= p; ++i)
    b[i] = read();
  // init
  // 其他的都不管了，我们先把点缩好~
  for (R int i = 1; i <= n; ++i)
    if(!dfn[i]) tarjan(i);
  // 缩好之后建DAG...跑dp
  for (R int i = 1; i <= n; ++i)
    for (R int j = 0; j < edges[i].size(); ++j)
    {
      int to = edges[i][j];
      if(belong[i] != belong[to]) 
        dag[belong[i]].push_back(belong[to]);
    }
  BFS(belong[s]);
  int ans = 0;
  for (R int i = 1; i <= p; ++i)
    ans = max(ans, f[belong[b[i]]]);
  printf("%d", ans);
}
}

int main()
{
  return BZOJ1179::solve(), 0;
}
```

## 「BZOJ2427」软件安装

tarjan缩点成森林，建虚点连边，然后进行背包树形dp

```cpp
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
```