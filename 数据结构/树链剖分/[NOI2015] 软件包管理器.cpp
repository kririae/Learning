// 手一滑，重链剖错了
// by kririae
// NOI2015
/*
今天上午摸了一上午调服务器，发现啥都没搞出来
做一道应景的题补偿补偿
这么处理，首先建树，然后对于安装包的情况
查询到根节点的0点和
对于删除的，查询子树的1点和
 */
#define ll long long
#define R register
#define ls t[k].son[0]
#define rs t[k].son[1]
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
inline char read_c()
{
  register char c;
  for (c = gc(); isspace(c); c = gc());
  return c;
}
}

namespace Manager
{
struct Node
{
  // 理论上，线段树需要维护俩信息：
  // 路径上为0的点的个数，路径上为1的点的个数
  // 虽然可以只维护一个，我怕我写翻车了
  int l, r, son[2], set;
  ll s[2];
  Node() : set(-1) {}
} t[maxn << 2];
int head[maxn], ver[maxn << 1], next[maxn << 1], tot;
int siz[maxn], son[maxn], fa[maxn], dep[maxn], id[maxn],  top[maxn], cnt;
int root, tcnt, n, q;
inline void addedge(int u, int v)
{
  ver[++tot] = v, next[tot] = head[u], head[u] = tot;
}
inline void dfs1(int k)
{
  siz[k] = 1, son[k] = 0;
  for (int i = head[k]; i; i = next[i])
  {
    R int to = ver[i];
    if(to == fa[k]) continue;
    fa[to] = k, dep[to] = dep[k] + 1;
    dfs1(to);
    if(siz[to] > siz[son[k]]) son[k] = to;
    siz[k] += siz[to];
  }
}
inline void dfs2(int k, int topf)
{
  id[k] = ++cnt, top[k] = topf;
  if(!son[k]) return;
  dfs2(son[k], topf);
  for (int i = head[k]; i; i = next[i])
  {
    R int to = ver[i];
    if(to == fa[k] || to == son[k]) continue;
    dfs2(to, to);
  }
}
inline void pushdown(int k)
{
  if(t[k].set == -1) return;
  int &st = t[k].set;
  t[ls].set = st, t[rs].set = st;
  t[ls].s[st] = t[ls].r - t[ls].l + 1, t[ls].s[1 - st] = 0;
  t[rs].s[st] = t[rs].r - t[rs].l + 1, t[rs].s[1 - st] = 0;
  st = -1;
}
inline void pushup(int k)
{
  for (int i = 0; i <= 1; ++i)
    t[k].s[i] = t[ls].s[i] + t[rs].s[i];
}
inline void build(int &k, int l, int r)
{
  k = ++tcnt, t[k].l = l, t[k].r = r;
  if(l == r) return t[k].s[0] = 1, void(); // TODO
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(k);
}
inline void set(int k, int l, int r, int col)
{
  if(t[k].l == l && t[k].r == r)
    return t[k].s[col] = r - l + 1, t[k].s[1 - col] = 0, t[k].set = col, void();
  pushdown(k);
  int mid = t[k].l + t[k].r >> 1;
  if(r <= mid) set(ls, l, r, col);
  else if(l > mid) set(rs, l, r, col);
  else set(ls, l, mid, col), set(rs, mid + 1, r, col);
  pushup(k);
}
inline ll query(int k, int l, int r, int col)
{
  if(t[k].l == l && t[k].r == r)
    return t[k].s[col];
  pushdown(k);
  int mid = t[k].l + t[k].r >> 1;
  if(r <= mid) return query(ls, l, r, col);
  else if(l > mid) return query(rs, l, r, col);
  else return query(ls, l, mid, col) + query(rs, mid + 1, r, col);
}
inline ll install(int x)
{
  // 查询到根节点上0的个数，并且全都变成1
  ll ans = 0;
  while(top[x] != 1)
  {
    ans += query(root, id[top[x]], id[x], 0);
    set(root, id[top[x]], id[x], 1);
    x = fa[top[x]];
  }
  ans += query(root, id[1], id[x], 0);
  set(root, id[1], id[x], 1);
  return ans;
}
inline ll uninstall(int x)
{
  ll ans = query(root, id[x], id[x] + siz[x] - 1, 1);
  set(root, id[x], id[x] + siz[x] - 1, 0);
  return ans;
}
inline void solve()
{
  using namespace IO;
  n = read();
  R int x; R char op;
  for (R int i = 2; i <= n; ++i)
    x = read(), ++x, addedge(x, i);
  dfs1(1), dfs2(1, 1);
  build(root, 1, n);
  q = read();
  while(q--)
  {
    op = read_c();
    switch(op)
    {
      case 'i': printf("%lld\n", install(read() + 1)); break;
      case 'u': printf("%lld\n", uninstall(read() + 1)); break;
    }
  }
}
}

int main()
{
  return Manager::solve(), 0;
}