// by kririae
#define R register
#define ll long long
#define pa pair<int, int>
#define ls t[k].son[0]
#define rs t[k].son[1]
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char gc()
{
  static const int LEN = 1e7;
  static char buf[LEN];
  static int s = 0, t = 0;
  s == t ? s = 0, t = fread(buf, 1, LEN, stdin) : 0;
  return s == t ? -1 : buf[s++];
}

inline char read_c()
{
  R char c = gc();
  for (; isspace(c); c = gc()) ;
  return c;
}

template<class T>
inline void read(T &val)
{
  int m, c;
  for (m = 1, c = gc(); !isdigit(c); c = gc())
    m = c == '-' ? -1 : 1;
  if(c == -1) return;
  for (val = 0; isdigit(c); c = gc())
    val = (val << 3) + (val << 1) + (c - '0');
  val = m == -1 ? -val : val;
}
}

namespace BZOJ1012  
{
const int maxn = 2e5 + 5;

struct Node
{
  int l, r, son[2];
  ll sum, max;
} t[maxn << 2];
int root, cnt;
int m, cnt1, curr;
ll d, T;
pa a[maxn];

inline void pushup(int k)
{
  t[k].max = max(t[ls].max, t[rs].max),
  t[k].sum = t[ls].sum + t[rs].sum;
}
inline void buildTree(int &k, int l, int r)
{
  k = ++cnt, t[k].l = l, t[k].r = r;
  if(l == r) return;
  int mid = (l + r) >> 1;
  buildTree(ls, l, mid);
  buildTree(rs, mid + 1, r);
  pushup(k);
}
inline void modify(int k, int pos, ll val)
{
  if(t[k].l == t[k].r && t[k].l == pos)
    return t[k].sum = val, t[k].max = val, void();
  int mid = (t[k].l + t[k].r) >> 1;
  if(pos <= mid) modify(ls, pos, val);
  else modify(rs, pos, val);
  pushup(k);
}
inline void insert(int val)
{
  modify(root, ++curr, val);
}
inline ll query(int k, int l, int r)
{
  if(t[k].l == l && t[k].r == r)
    return t[k].max;
  int mid = (t[k].l + t[k].r) >> 1;
  if(r <= mid) return query(ls, l, r);
  else if(l > mid) return query(rs, l, r);
  else return max(query(ls, l, mid), query(rs, mid + 1, r));
}

inline void solve()
{
  using namespace IO;
  read(m), read(d);
  for (R int i = 1; i <= m; ++i)
    if(read_c() == 'A') a[i].first = 1, read(a[i].second), ++cnt1;
    else a[i].first = 2, read(a[i].second);
  buildTree(root, 1, cnt1);
  for (R int i = 1; i <= m; ++i)
    if(a[i].first == 1)  insert((a[i].second + T) % d);
    else printf("%lld\n", T = query(root, curr - a[i].second + 1, curr));
}
}
int main()
{
  return BZOJ1012::solve(), 0;
}