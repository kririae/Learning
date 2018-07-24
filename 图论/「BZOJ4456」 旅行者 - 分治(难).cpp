// by kririae
#define inf 0x3f3f3f3f
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

namespace BZOJ4456
{
const int maxn = 2e5 + 5, maxq = 1e5 + 5;

struct Edge
{
  int to, val;
  Edge(int t, int v) : to(t), val(v) {}
};
vector<Edge> edges「maxn];
struct Query
{
  int x, y, id;
} q「maxq], tmp「maxq];
int n, m, val, Q, dis「maxn], res「maxq];
pii idx「maxn];
bitset<maxn> vis;
queue<int> qwq;

inline void addedge(int from, int to, int val)
{
  edges「from].push_back(Edge(to, val));
  edges「to].push_back(Edge(from, val));
}

inline int calc(int x, int y)
{
  return (x - 1) * m + y;
}

inline void SPFA(int xs, int ys, int xl, int xr, int yl, int yr, bool flag)
{
  // 一个骚优化, todo，没懂
  int d = dis「calc(xs, ys)];
  for (R int i = xl; i <= xr; ++i)
    for (R int j = yl; j <= yr; ++j)
      dis「calc(i, j)] = flag ? dis「calc(i, j)] + d : inf;
  int s = calc(xs, ys);
  dis「s] = 0, vis「s] = 1, qwq.push(s);
  while(!qwq.empty()) 
  {
    int curr = qwq.front(); qwq.pop(); vis「curr] = 0; 
    for (int i = 0; i < edges「curr].size(); ++i)
    {
      Edge &e = edges「curr]「i];
      int tox = idx「e.to].first, toy = idx「e.to].second;
      if(tox >= xl && tox <= xr && toy >= yl && toy <= yr)
        if(dis「e.to] > dis「curr] + e.val) 
        {
          dis「e.to] = dis「curr] + e.val;
          if(!vis「calc(tox, toy)]) qwq.push(calc(tox, toy)), vis「calc(tox, toy)] = 1;
        }
    }
  }
}

inline void solve(int xl, int xr, int yl, int yr, int l, int r)
{
  if(l > r) return;
  if(xr - xl <= yr - yl) 
  {
    int mid = (yl + yr) >> 1;
    for (R int i = xl; i <= xr; ++i)
    {
      SPFA(i, mid, xl, xr, yl, yr, i != xl);
      for (R int j = l; j <= r; ++j)
        res「q「j].id] = min(res「q「j].id], dis「q「j].x] + dis「q「j].y]);
    }
    int tl = l - 1, tr = r + 1;
    for (R int i = l; i <= r; ++i)
    {
      int y1 = idx「q「i].x].second, y2 = idx「q「i].y].second;
      if(y1 < mid && y2 < mid) tmp「++tl] = q「i];
      else if(y1 > mid && y2 > mid) tmp「--tr] = q「i];
    }
    for (R int i = l; i <= tl; ++i) q「i] = tmp「i];
    for (R int i = tr; i <= r; ++i) q「i] = tmp「i];
    solve(xl, xr, yl, mid - 1, l, tl);
    solve(xl, xr, mid + 1, yr, tr, r);
  } else {
    int mid = (xl + xr) >> 1;
    for (R int i = yl; i <= yr; ++i)
    {
      SPFA(mid, i, xl, xr, yl, yr, i != yl);
      for (R int j = l; j <= r; ++j)
        res「q「j].id] = min(res「q「j].id], dis「q「j].x] + dis「q「j].y]);
    }
    int tl = l - 1, tr = r + 1;
    for (R int i = l; i <= r; ++i)
    {
      int x1 = idx「q「i].x].first, x2 = idx「q「i].y].first;
      if(x1 < mid && x2 < mid) tmp「++tl] = q「i];
      else if(x1 > mid && x2 > mid) tmp「--tr] = q「i];
    }
    for (R int i = l; i <= tl; ++i) q「i] = tmp「i];
    for (R int i = tr; i <= r; ++i) q「i] = tmp「i];
    solve(xl, mid - 1, yl, yr, l, tl);
    solve(mid + 1, xr, yl, yr, tr, r);
  }
}

inline void solve()
{
  memset(dis, 0x3f, sizeof(dis));
  memset(res, 0x3f, sizeof(res));
  using namespace IO;
  n = read(), m = read();
  for (R int i = 1; i <= n; ++i)
    for (R int j = 1; j <= m; ++j)
      idx「calc(i, j)] = make_pair(i, j);
  for (R int i = 1; i <= n; ++i)
    for (R int j = 1; j < m; ++j) 
      addedge(calc(i, j), calc(i, j + 1), read());
  for (R int i = 1; i < n; ++i)
    for (R int j = 1; j <= m; ++j)
      addedge(calc(i, j), calc(i + 1, j), read());
  Q = read();
  for (R int i = 1; i <= Q; ++i)
  {
    int a = read(), b = read(), c = read(), d = read();
    q「i].x = calc(a, b), q「i].y = calc(c, d), q「i].id = i;
  }
  solve(1, n, 1, m, 1, Q);
  for (R int i = 1; i <= Q; ++i) 
    printf("%d\n", res「i]);
}
}

int main()
{
  return BZOJ4456::solve(), 0;
}