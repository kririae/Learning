// by kririae
#define ll long long
#define R register
#define ls t「k].son「0]
#define rs t「k].son「1]
#include <bits/stdc++.h>

using namespace std;

const int maxn = 30005;

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
inline char read_c()
{
  register char c;
  for (c = gc(); isspace(c); c = gc());
  return c;
}
}

namespace BZOJ1036
{
struct Node
{
  int l, r, son「2];
  ll sum, max;
  Node() {}
} t「maxn << 1];
int head「maxn], next「maxn << 1], ver「maxn << 1], tot;
int siz「maxn], son「maxn], fa「maxn], dep「maxn], id「maxn], wt「maxn], w「maxn], top「maxn];
int n, q, tcnt, cnt, root;

inline void addedge(int from, int to)
{
  ver「++tot] = to, next「tot] = head「from], head「from] = tot;
}

inline void dfs1(int k)
{
  siz「k] = 1, son「k] = 0;
  for (R int i = head「k]; i; i = next「i])
  {
    R int to = ver「i];
    if(to == fa「k]) continue;
    fa「to] = k, dep「to] = dep「k] + 1;
    dfs1(to);
    if(siz「to] > siz「son「k]]) son「k] = to;
    siz「k] += siz「to];
  }
}

inline void dfs2(int k, int topf)
{
  id「k] = ++cnt, wt「cnt] = w「k], top「k] = topf;
  if(!son「k]) return;
  dfs2(son「k], topf);
  for (R int i = head「k]; i; i = next「i])
  {
    R int to = ver「i];
    if(to == fa「k] || to == son「k]) continue;
    dfs2(to, to);
  }
}

inline void pushup(int k)
{
  t「k].sum = t「ls].sum + t「rs].sum;
  t「k].max = max(t「ls].max, t「rs].max);
}

inline void build(int &k, int l, int r)
{
  k = ++tcnt, t「k].l = l, t「k].r = r;
  if(l == r) return t「k].sum = t「k].max = wt「l], void();
  R int mid = (l + r) >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(k);
}

inline void mpoint(int k, int pos, int val)
{
  if(t「k].l == t「k].r && t「k].l == pos)
    return t「k].sum = t「k].max = val, void();
  R int mid = (t「k].l + t「k].r) >> 1;
  if(pos <= mid) mpoint(ls, pos, val);
  else mpoint(rs, pos, val);
  pushup(k);
}

inline ll qsum(int k, int l, int r)
{
  if(t「k].l == l && t「k].r == r)
    return t「k].sum;
  R int mid = (t「k].l + t「k].r) >> 1;
  if(r <= mid) return qsum(ls, l, r);
  else if (l > mid) return qsum(rs, l, r);
  else return qsum(ls, l, mid) + qsum(rs, mid + 1, r);
}

inline ll qmax(int k, int l, int r)
{
  if(t「k].l == l && t「k].r == r)
    return t「k].max;
  R int mid = t「k].l + t「k].r >> 1;
  if(r <= mid) return qmax(ls, l, r);
  else if (l > mid) return qmax(rs, l, r);
  else return max(qmax(ls, l, mid), qmax(rs, mid + 1, r));
}

inline void mtree(int pos, int val)
{
  mpoint(root, id「pos], val);
}

inline ll qtreemax(int x, int y)
{
  ll ans = (ll)1 << 63;
  while(top「x] != top「y])
  {
    if(dep「top「x]] < dep「top「y]]) swap(x, y);
    ans = max(ans, qmax(root, id「top「x]], id「x]));
    x = fa「top「x]];
  }
  if(dep「x] > dep「y]) swap(x, y);
  ans = max(ans, qmax(root, id「x], id「y]));
  return ans;
}

inline ll qtreesum(int x, int y)
{
  ll ans = 0;
  while(top「x] != top「y])
  {
    if(dep「top「x]] < dep「top「y]]) swap(x, y);
    ans += qsum(root, id「top「x]], id「x]);
    x = fa「top「x]];
  }
  if(dep「x] > dep「y]) swap(x, y);
  ans += qsum(root, id「x], id「y]);
  return ans;
}

inline void solve()
{
  using namespace IO;
  n = read();
  R int a, b;
  for (R int i = 1; i < n; ++i)
    a = read(), b = read(),
    addedge(a, b), addedge(b, a);
  for (R int i = 1; i <= n; ++i) w「i] = read();
  dfs1(1), dfs2(1, 1);
  build(root, 1, n);
  q = read();
  R char op;
  for (R int i = 1; i <= q; ++i)
  {
    op = read_c(), op = read_c();
    switch(op)
    {
      case 'H': a = read(), b = read(), mtree(a, b); break;
      case 'M': a = read(), b = read(), printf("%lld\n", qtreemax(a, b)); break;
      case 'S': a = read(), b = read(), printf("%lld\n", qtreesum(a, b)); break;
    }
  }
}
}

int main()
{
  return BZOJ1036::solve(), 0;
}