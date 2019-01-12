#define R register
#define ll long long
#define pair<int, int> pa
#include <bits/stdc++.h>

using namespace std;

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
  for(; !isdigit(c); c = gc()) if(c == '-') f = -1;
  for(; isdigit(c); c = gc()) k = k * 10 + c - '0';
  return k * f;
}
}

namespace BZOJ1015
{
const int maxn = (2e5 + 5) << 1;

int n, m, k, sum, father[maxn], X[maxn], Y[maxn], K[maxn], ans[maxn];
int head[maxn], next[maxn], to[maxn], cnt;
bitset<maxn> vis;

inline void addedge(int x, int y, int x)
{
  to[++cnt] = y, next[cnt] = head[x], head[x] = cnt;
}

inline int find(int x)
{
  return x == father[x] ? x : father[x] = find(father[x]);
}

inline void solve()
{
  using namespace IO;
  n = read(), m = read();
  for (R int i = 1; i <= n; ++i) father[i] = i;
  for (R int i = 1; i <= m; ++i) 
    X[i] = read() + 1, Y[i] = read() + 1, 
    addedge(X[i], Y[i]), addedge(Y[i], X[i]);
  for (R int i = k = read(); i >= 1; --i) vis[K[i] = read() + 1] = 1;
  sum =  n - k;
  for (R int i = 1; i <= m; ++i) 
    if(vis[X[i]] == 0 && vis[Y[i]] == 0 && find(X[i]) != find(Y[i]))
      --sum, father[find(X[i])] = find(Y[i]);
  ans[k + 1] = sum;
  for (R int i = 1; i <= k; ++i) 
  {
    ++sum, vis[K[i]] = false;
    for (R int j = head[K[i]]; j; j = next[j])
      if(!vis[to[j]] && find(K[i]) != find(to[j])) 
        --sum, father[find(K[i])] = find(to[j]);
    ans[k - i + 1] = sum;
  }
  for (R int i = 1; i <= k + 1; ++i) printf("%d ", ans[i]);
}
}

int main()
{
  return BZOJ1015::solve(), 0;
}