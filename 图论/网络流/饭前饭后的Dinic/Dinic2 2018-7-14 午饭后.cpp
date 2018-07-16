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

namespace Dinic
{
struct Edge
{
  int from, to, cap, flow;
  Edge(int _from, int _to, int _cap, int _flow) : 
  from(_from), to(_to), cap(_cap), flow(_flow) {}
};
vector<Edge> edges;
vector<int> G[maxn];
queue<int> q;
bitset<maxn> vis;
int n, m, s, t, cnt, d[maxn], cur[maxn];

inline void addedge(R int from, R int to, R int cap)
{
  cnt += 2;
  edges.push_back(Edge(from, to, cap, 0));
  edges.push_back(Edge(to, from, 0, 0));
  G[from].push_back(cnt - 2);
  G[to].push_back(cnt - 1);
}

inline bool BFS()
{
    memset(d, 0, sizeof(d));
  vis.reset(), q.push(s), vis[s] = 1;
  while(!q.empty())
  {
    R int curr = q.front(); q.pop();
    for (R int i = 0; i < G[curr].size(); ++i)
    {
      Edge* e = &edges[G[curr][i]];
      if(e->cap > e->flow && !vis[e->to])
        d[e->to] = d[e->from] + 1, vis[e->to] = 1, q.push(e->to);
    }
  }
  return vis[t];
}

inline int dfs(R int x, R int a)
{
  if(x == t || a == 0) return a;
  R int flow = 0, f;
  for (R int* i = &cur[x]; *i < G[x].size(); ++(*i))
  {
    Edge* e = &edges[G[x][*i]];
    if(d[e->to] == d[e->from] + 1 && (f = dfs(e->to, min(e->cap - e->flow, a))) > 0)
    {
      e->flow += f, edges[G[x][*i] ^ 1].flow -= f, flow += f, a -= f;
      if(a == 0) break;
    }
  }
  return flow;
}

inline int maxFlow()
{
  R int flow = 0;
  while(BFS())
  {
    memset(cur, 0, sizeof(cur));
    flow += dfs(s, 1e9);
  }
  return flow;
}
inline void solve()
{
  using namespace IO;
  n = read(), m = read(), s = read(), t = read();
  for (int i = 1; i <= m; ++i)
  {
    R int u, v, w;
    u = read(), v = read(), w = read();
    addedge(u, v, w);
  }
  printf("%d", maxFlow());
}
}

int main()
{
  return Dinic::solve(), 0;
}