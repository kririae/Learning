// by kririae
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

namespace Qtree3
{
// 线个头，爷爷我要分块。
int head[maxn], ver[maxn << 1], next[maxn << 1], tot;
int siz[maxn], son[maxn], fa[maxn], dep[maxn], id[maxn], top[maxn], col[maxn], rev[maxn], cnt;
int bs, sc, L[maxn], R[maxn], MIN[maxn], belong[maxn]; // block_size, size_count
int n, q, op, val;

inline void addedge(register int from, register int to)
{
  ver[++tot] = to, next[tot] = head[from], head[from] = tot;
}
inline void dfs1(int k)
{
  siz[k] = 1, son[k] = 0;
  for (register int i = head[k]; i; i = next[i])
  {
    int to = ver[i];
    if(to == fa[k]) continue;
    fa[to] = k, dep[to] = dep[k] + 1;
    dfs1(to);
    if(siz[to] > siz[son[k]]) son[k] = to;
    siz[k] += siz[to];
  }
}
inline void dfs2(int k, int topf)
{
  id[k] = ++cnt, rev[cnt] = k, col[cnt] = 0, top[k] = topf;
  if(!son[k]) return;
  dfs2(son[k], topf);
  for (register int i = head[k]; i; i = next[i])
  {
    int to = ver[i];
    if(to == fa[k] || to == son[k]) continue;
    dfs2(to, to);
  }
}
inline void init()
{
  dfs1(1), dfs2(1, 1);
  bs = sqrt(n);
  sc = n % bs == 0 ? n / bs : n / bs + 1;
  for (register int i = 1; i <= sc; ++i)
    L[i] = R[i - 1] + 1, R[i] = L[i] + bs - 1, MIN[i] = 1e9;
  R[sc] = n;
  for (register int i = 1; i <= sc; ++i)
    for (register int j = L[i]; j <= R[i]; ++j)
      belong[j] = i;
}
inline void modify(register int pos)
{
  // 将id[pos]转化为相反的颜色，然后重置当前块的信息
  int bl = belong[pos];
  col[pos] = 1 - col[pos];
  if(col[pos] == 1) return MIN[bl] = min(MIN[bl], pos);
  else { 
    for (register int i = L[bl]; i <= R[bl]; ++i)
      if(col[i] == 1) return MIN[bl] = i, void(); // 求出最浅的块
  }
}
inline int query(register int l, register int r)
{
  // 分成三部分处理...
  if(l > r) swap(l, r);
  if(belong[l] == belong[r]) 
  {
    for (int i = l; i <= r; ++i) if(col[i]) return i;
    return 1e9;
  }
  for (register int i = l; i < L[belong[l] + 1]; ++i) if(col[i]) return i;
  for (register int i = belong[l] + 1; i <= belong[r] - 1; ++i) if(MIN[i] != 1e9) return MIN[i];
  for (register int i = L[belong[r]]; i <= r; ++i) if(col[i]) return i;
  return 1e9;
  // 已经尽力返回最小的了啊QAQ
}
inline int qtree(int x)
{
  int ans = 1e9;
  while(top[x] != top[1])
  {
    ans = min(ans, query(id[top[x]], id[x]));
    x = fa[top[x]];
  }
  ans = min(ans, query(id[1], id[x]));
  return ans >= 1e9 ? -1 : rev[ans];
}
inline void mtree(int pos)
{
  modify(id[pos]);
}
inline void solve()
{
  using namespace IO;
  n = read(), q = read();
  register int x, y;
  for (register int i = 1; i < n; ++i)
    x = read(), y = read(), addedge(x, y), addedge(y, x);
  init();
  while(q--)
  {
    op = read();
    switch(op)
    {
      case 0: x = read(), mtree(x); break;
      case 1: x = read(), printf("%d\n", qtree(x)); break;
    }
  }
}
}

int main()
{
  return Qtree3::solve(), 0;
}