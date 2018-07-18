#define ll long long
#define R register
#define ls t[k].son[0]
#define rs t[k].son[1]
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

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
inline char read_c()
{
  register char c;
  for (c = gc(); isspace(c); c = gc());
  return c;
}
}

namespace BZOJ2243
{
struct Node
{
  int l, r, set, son[2];
  ll cols, lc, rc;
  Node() {}
} t[maxn << 1];
struct TNode
{
  int siz, son, fa, dep, id, col, top;
} q[maxn];
// int siz[maxn], son[maxn], fa[maxn], dep[maxn], id[maxn], 
// tcol[maxn], col[maxn], top[maxn];
int head[maxn], next[maxn << 1], ver[maxn << 1], tot;
int n, m, root, cnt, tcnt, tcol[maxn];

inline void addedge(int from, int to)
{
  ver[++tot] = to, next[tot] = head[from], head[from] = tot;
}

inline void dfs1(int k)
{
  q[k].siz = 1, q[k].son = 0;
  for (R int i = head[k]; i; i = next[i])
  {
    R int to = ver[i];
    if (to == q[k].fa) continue;
    q[to].fa = k, q[to].dep = q[k].dep + 1;
    dfs1(to);
    if (q[to].siz > q[q[k].son].siz) q[k].son = to;
    q[k].siz += q[to].siz;
  }
}

inline void dfs2(int k, int topf)
{
  q[k].id = ++cnt, tcol[cnt] = q[k].col, q[k].top = topf;
  if (!q[k].son) return;
  dfs2(q[k].son, topf);
  for (R int i = head[k]; i; i = next[i])
  {
    R int to = ver[i];
    if (to == q[k].fa || to == q[k].son) continue;
    dfs2(to, to);
  }
}

inline void pushup(int k)
{
  // 如果中间相同，那么就 - 1， 否则就是两边的块数相加~
  t[k].cols = t[ls].cols + t[rs].cols - (t[ls].rc == t[rs].lc);
  t[k].lc = t[ls].lc, t[k].rc = t[rs].rc;
}

inline void pushdown(int k)
{
  if (t[k].set)
  {
    t[ls].set = t[rs].set = t[k].set;
    t[ls].lc = t[ls].rc = t[rs].lc = t[rs].rc = t[k].set;
    t[ls].cols = t[rs].cols = 1;
    t[k].set = 0;
  }
}

inline void build(int &k, int l, int r)
{
  k = ++tcnt; t[k].l = l, t[k].r = r;
  if (l == r) return t[k].lc = t[k].rc = tcol[l], t[k].cols = 1, void();
  R int mid = (l + r) >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(k);
}

// TODO: mrange, qpoint, qrange

inline void mrange(int k, int l, int r, int c)
{
  if (t[k].l == l && t[k].r == r)
    return t[k].lc = t[k].rc = c, t[k].cols = 1, t[k].set = c, void();
  pushdown(k);
  R int mid = (t[k].l + t[k].r) >> 1;
  if (r <= mid) mrange(ls, l, r, c);
  else if (l > mid) mrange(rs, l, r, c);
  else mrange(ls, l, mid, c), mrange(rs, mid + 1, r, c);
  pushup(k);
}

inline int qpoint(int k, int pos)
{
  if (t[k].l == t[k].r && t[k].l == pos)
    return t[k].lc;
  pushdown(k);
  R int mid = (t[k].l + t[k].r) >> 1;
  if (pos <= mid) return qpoint(ls, pos);
  else return qpoint(rs, pos);
}

inline int qrange(int k, int l, int r)
{
  if (t[k].l == l && t[k].r == r)
    return t[k].cols;
  pushdown(k);
  R int mid = (t[k].l + t[k].r) >> 1;
  if (r <= mid) return qrange(ls, l, r);
  else if (l > mid) return qrange(rs, l, r);
  else {
    int tmp = qrange(ls, l, mid) + qrange(rs, mid + 1, r);
    tmp -= (t[ls].rc == t[rs].lc);
    return tmp;
  }
}

inline int qtree(R int x, R int y)
{
  R int ans = 0;
  while (q[x].top != q[y].top)
  {
    if (q[q[x].top].dep < q[q[y].top].dep) swap(x, y);
    ans += qrange(root, q[q[x].top].id, q[x].id);
    ans -= (qpoint(root, q[q[x].top].id) == qpoint(root, q[q[q[x].top].fa].id));
    x = q[q[x].top].fa;
  }
  if (q[x].dep > q[y].dep) swap(x, y);
  ans += qrange(root, q[x].id, q[y].id);
  return ans;
}

inline void mtree(R int x, R int y, R int c)
{
  while (q[x].top != q[y].top)
  {
    if (q[q[x].top].dep < q[q[y].top].dep) swap(x, y);
    mrange(root, q[q[x].top].id, q[x].id, c);
    x = q[q[x].top].fa;
  }
  if (q[x].dep > q[y].dep) swap(x, y);
  mrange(root, q[x].id, q[y].id, c);
}

inline void solve()
{
  using namespace IO;
  n = read(), m = read();
  for (R int i = 1; i <= n; ++i) q[i].col = read();
  R int x, y, z;
  for (R int i = 1; i < n; ++i)
    x = read(), y = read(),
    addedge(x, y), addedge(y, x);
  dfs1(1), dfs2(1, 1);
  build(root, 1, n);
  R char op;
  for (R int i = 1; i <= m; ++i)
  {
    op = read_c();
    switch(op)
    {
      case 'C': x = read(), y = read(), z = read(), mtree(x, y, z); break;
      case 'Q': x = read(), y = read(), printf("%d\n", qtree(x, y)); break;
    }
  }
}
}

int main()
{
  return BZOJ2243::solve(), 0;
}