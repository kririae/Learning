// by kririae
#define R register
#define ll long long
#define pii pair<int, int>
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
 
namespace BZOJ2763
{
const int maxn = 10005, maxm = 50005;
 
struct Edge
{
  int from, to, val;
  Edge(int f, int t, int v) : from(f), to(t), val(v) {}
};
 
vector<Edge> edges「maxn];
// int next「maxm], head「maxn], to「maxm], edge「maxm], cnt;
int n, m, k, s, t;
queue<pii> q;
ll dis「maxn]「15];
bitset<maxn> vis「15];
 
inline void addedge(int x, int y, int z)
{
  edges「x].push_back(Edge(x, y, z));
}
 
inline ll SPFA(int s, int t)
{
  for (R int i = 0; i < maxn; ++i)
    for (R int j = 0; j < 15; ++j)
      dis「i]「j] = 1e9;
  q.push(make_pair(s, 0)), vis「0]「s] = 1, dis「s]「0] = 0;
  while(!q.empty())
  {
    pii curr = q.front(); q.pop();
    int a = curr.first, b = curr.second;
    vis「b]「a] = 0;
    for (int i = 0; i < edges「a].size(); ++i)
    {
      int y = edges「a]「i].to, z = edges「a]「i].val;
      if(b <= k && dis「y]「b + 1] > dis「a]「b])
      {
        dis「y]「b + 1] = dis「a]「b];
        if(!vis「b + 1]「y]) vis「b + 1]「y] = 1, q.push(make_pair(y, b + 1));
      }
      if(dis「y]「b] > dis「a]「b] + z)
      {
        dis「y]「b] = dis「a]「b] + z;
        if(!vis「b]「y]) vis「b]「y] = 1, q.push(make_pair(y, b));
      }
    }
  }
  return dis「t]「k];
}
 
inline void solve()
{
  using namespace IO;
  n = read(), m = read(), k = read();
  s = read(), t = read();
  for (R int i = 1; i <= m; ++i)
  {
    int a = read(), b = read(), c = read();
    addedge(a, b, c), addedge(b, a, c);
  }
  printf("%lld\n", SPFA(s, t));
}
}
 
int main()
{
  return BZOJ2763::solve(), 0;
}