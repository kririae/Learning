// 该优化的都优化了...为啥还是很慢...
#define ll long long
#define R register
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

namespace QwQ
{
struct Node
{
  int siz, son, fa, dep, id, top;
} t[maxn];
int n, m, s, cnt;
int head[maxn], next[maxn << 1], ver[maxn << 1], tot;

inline void addedge(R int from, R int to)
{
  ver[++tot] = to, next[tot] = head[from], head[from] = tot;
}

inline void dfs1(R int k)
{
  t[k].siz = 1, t[k].son = 0; // fuck
  for (R int i = head[k]; i; i = next[i])
  {
    R int to = ver[i];
    if(to == t[k].fa) continue;
    // 这样初始化的成本貌似低一些，先这么写吧。
    t[to].fa = k, t[to].dep = t[k].dep + 1;
    dfs1(to);
    if(t[to].siz > t[t[k].son].siz) t[k].son = to;
    t[k].siz += t[to].siz;
  }
}

inline void dfs2(R int k, R int topf)
{
  t[k].id = ++cnt, t[k].top = topf;
  if(!t[k].son) return;
  dfs2(t[k].son, topf);
  for (R int i = head[k]; i; i = next[i])
  {
    R int to = ver[i];
    if(to == t[k].fa || to == t[k].son) continue;
    dfs2(to, to); // 对于每一个轻儿子，都是从自己开始的
  }
}

inline int lca(R int x, R int y)
{
  while(t[x].top != t[y].top)
  {
    if(t[t[x].top].dep >= t[t[y].top].dep) x = t[t[x].top].fa;
    else y = t[t[y].top].fa;
  }
  return t[x].dep > t[y].dep ? y : x;
}

inline void solve()
{
  using namespace IO;
  n = read(), m = read(), s = read();
  R int x, y;
  for (R int i = 1; i < n; ++i)
    x = read(), y = read(), addedge(x, y), addedge(y, x);
  dfs1(s); dfs2(s, s);
  for (R int i = 1; i <= m; ++i)
  {
    x = read(), y = read();
    printf("%d\n", lca(x, y));
  }
}
}

int main()
{
  return QwQ::solve(), 0;
}