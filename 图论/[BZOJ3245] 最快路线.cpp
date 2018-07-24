// by kririae
#define R register
#define ll long long
#define db double
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

namespace BZOJ3245
{
const int maxn = 150 + 5;

struct Edge
{
  int from, to, v, l;
  Edge (int f, int t, int val, int lim) : from(f), to(t), v(val), l(lim){}
};
vector<Edge> edges「maxn];
int n, m, d, ans;
pii f「maxn]「505];
db dis「maxn]「505], mi = 1e9;
bitset<maxn> vis「505];
queue<pii> q;

inline void addedge(int from, int to, int val, int lim)
{
    cout << from << " " << to << endl;
  edges「from].push_back(Edge(from, to, val, lim));
}

inline void SPFA()
{
  vis「0]「70] = 1, dis「0]「70] = 0, q.push(make_pair(0, 70));
  while(!q.empty())
  {
    pii curr = q.front(); q.pop();
    vis「curr.first]「curr.second] = 0;
    for (R int i = 0; i < edges「curr.first].size(); ++i)
    {
      Edge &e = edges「curr.first]「i];
      int dist, sd;
      if(e.v == 0) dist = dis「e.from]「curr.second] + (double)e.l / curr.second, sd = curr.second;
      else dist = dis「e.from]「curr.second] + (double)e.l / e.v, sd = e.v;
      if(dist < dis「e.to]「sd])
      {
        dis「e.to]「sd] = dist, f「e.to]「sd] = curr;
        if(!vis「e.to]「sd]) vis「e.to]「sd] = 1, q.push(make_pair(e.to, sd));
      }
    }
  }
}

inline void print(int d, int b)
{
  if(d != 0) print(f「d]「b].first, f「d]「b].second);
  printf("%d ", d);
}

inline void solve()
{
  using namespace IO;
  for (R int i = 0; i < maxn; ++i)
    for (R int j = 0; j < 505; ++j)
      dis「i]「j] = 1e9;
  n = read(), m = read(), d = read();
  for (R int i = 1; i <= m; ++i) 
  {
    int a, b, c, d;
    a = read(), b = read(), c = read(), d = read();
    addedge(a, b, c, d);
  }
  SPFA();
  for (R int i = 0; i <= 500; ++i)
    if(dis「d]「i] < mi) ans = i, mi = dis「d]「i];
  print(d, ans);
}
}

int main()
{
  return BZOJ3245::solve(), 0;
}

/*
6 15 1
0 1 25 68
0 2 30 50
0 5 0 101
1 2 70 77
1 3 35 42
2 0 0 22
2 1 40 86
2 3 0 23
2 4 45 40
3 1 64 14
3 5 0 23
4 1 95 8
5 1 0 84
5 2 90 64
5 3 36 40
*/