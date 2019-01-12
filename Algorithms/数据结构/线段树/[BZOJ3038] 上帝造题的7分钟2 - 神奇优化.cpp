#define ll long long
#define R register
#define ls t[k].son[0]
#define rs t[k].son[1]
#include <bits/stdc++.h>

using namespace std;

namespace IO
{
inline char gc()
{
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline ll read()
{
  register ll k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
}

namespace BZOJ3038
{
const int maxn = 1e5 + 5;

struct Node
{
  int l, r, son[2];
  ll sum, max;
} t[maxn << 2];
int root, cnt, n, m, s[maxn];

inline void pushup(int k)
{
  t[k].sum = t[ls].sum + t[rs].sum, t[k].max = max(t[ls].max, t[rs].max);
}

inline void build(int &k, int l, int r)
{
  k = ++cnt, t[k].l = l, t[k].r = r;
  if(l == r) return t[k].max = t[k].sum = s[l], void();
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}

inline void modify(int k, int l, int r)
{
  if(t[k].max <= 1) return;
  if(t[k].l == t[k].r) return t[k].sum = sqrt(t[k].sum), t[k].max = sqrt(t[k].max), void();
  int mid = (t[k].l + t[k].r) >> 1;
  if(r <= mid) modify(ls, l, r);
  else if(l > mid) modify(rs, l, r);
  else modify(ls, l, mid), modify(rs, mid + 1, r);
  pushup(k);
}

inline ll query(int k, int l, int r)
{
  if(t[k].l == l && t[k].r == r) return t[k].sum;
  int mid = (t[k].l + t[k].r) >> 1;
  if(r <= mid) return query(ls, l, r);
  else if(l > mid) return query(rs, l, r);
  else return query(ls, l, mid) + query(rs, mid + 1, r);
}

inline void solve()
{
  using namespace IO;
  n = read();
  for (R int i = 1; i <= n; ++i) s[i] = read();
  build(root, 1, n);
  m = read();
  for (R int i = 1; i <= m; ++i)
  {
    int k = read(), a = read(), b = read();
    if(a > b) swap(a, b);
    if(k == 0) modify(root, a, b);
    else printf("%lld\n", query(root, a, b));
  }
}
}

int main()
{
  return BZOJ3038::solve(), 0;
}