#define ll long long
#define R register
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

namespace BZOJ2330
{
struct Edge
{
  int to, val;
  Edge() {}
  Edge(int _t, int _v) : to(_t), val(_v) {}
};
vector<Edge> edges[maxn];
bitset<maxn> vis;
queue<int> q;
int n, k, x, a, b;
ll dis[maxn], ans;

inline void addedge(int from, int to, int val)
{
  edges[from].push_back(Edge(to, val));
}

inline bool SPFA()
{
  while(!q.empty())
  {
    int curr = q.front(); q.pop(); vis[curr] = 0;
    if(dis[curr] > n) return 0;
    for (R int i = 0; i < edges[curr].size(); ++i)
    {
      Edge *e = &edges[curr][i];
      if(dis[e->to] < dis[curr] + e->val)
      {
        dis[e->to] = dis[curr] + e->val;
        if(!vis[e->to]) vis[e->to] = 1, q.push(e->to);
      }
    }
  }
  return 1;
}

inline void solve()
{
  using namespace IO;
  n = read(), k = read();
  for (R int i = 1; i <= k; ++i)
  {
    x = read(), a = read(), b = read();
    // a -> b b - a = 1, 嘛要像向量吧
    if(x == 1) addedge(a, b, 0), addedge(b, a, 0);
    if(x == 2) 
      if(a == b) return puts("-1"), void();
      else addedge(a, b, 1);
    if(x == 3) addedge(b, a, 0);
    if(x == 4) 
      if(a == b) return puts("-1"), void();
      else addedge(b, a, 1);
    if(x == 5) addedge(a, b, 0);
  }
  for (R int i = 1; i <= n; ++i) dis[i] = 1;
  for (R int i = 1; i <= n; ++i) q.push(i), vis[i] = 1;
  if(!SPFA()) return puts("-1"), void();
  for (R int i = 1; i <= n; ++i)
    ans += dis[i];
  printf("%lld", ans);
}
}

int main()
{
  return BZOJ2330::solve(), 0;
}