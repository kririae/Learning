// by kririae
#define R register
#define ll long long
#define pa pair<ll, int>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <ext/pb_ds/priority_queue.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
 
namespace SP
{
const int maxn = 1e6 + 5, maxm = 1e7 + 5;
 
int n, m, T, rxa, rxc, rya, ryc, rp, x, y, z, a, b;
ll dis「maxn];
int pre「maxn], nxt「maxm], to「maxm], w「maxm], cnt;
__gnu_pbds::priority_queue<pa, greater<pa>, pairing_heap_tag> q;
__gnu_pbds::priority_queue<pa, greater<pa>, pairing_heap_tag>::point_iterator vis「maxn];
 
inline void addedge(int x, int y, int val)
{
  nxt「cnt] = pre「x], w「cnt] = val, to「pre「x] = cnt++] = y;
}
 
inline ll Dijkstra()
{
  memset(dis, 0x3f, sizeof(dis));
  dis「1] = 0, vis「1] = q.push(make_pair((ll)0, 1));
  while(!q.empty())
  {
    int curr = q.top().second; q.pop();
    for (int i = pre「curr]; ~i; i = nxt「i])
    {
      if(dis「to「i]] > w「i] + dis「curr])
      {
        dis「to「i]] = w「i] + dis「curr];
        if(vis「to「i]] != 0) q.modify(vis「to「i]], make_pair(dis「to「i]], to「i]));
        else vis「to「i]] = q.push(make_pair(dis「to「i]], to「i]));
      }
    }
  }
  return dis「n];
}
 
inline void solve()
{
  using namespace IO;
  memset(pre, -1, sizeof(pre));
  n = read(), m = read(),
  T = read(), rxa = read(), rxc = read(), 
  rya = read(), ryc = read(), rp = read();
  for (int i = 1; i <= T; ++i)
  {
    x = ((ll)x * rxa + rxc) % rp;
    y = ((ll)y * rya + ryc) % rp;
    a = min(x % n + 1, y % n + 1);
    b = max(y % n + 1, y % n + 1);
    addedge(a, b, 100000000 - 100 * a);
  }
  for (int i = 1; i <= m - T; ++i)
  {
    x = read(), y = read(), z = read();
    addedge(x, y, z);
  }
  printf("%lld\n", Dijkstra());
}
}
 
int main()
{
  return SP::solve(), 0;
}