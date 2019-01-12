// by kririae
#include <bits/stdc++.h>
#define ll long long
#define ls t[k].son[0]
#define rs t[k].son[1]
using namespace std;

struct IO
{
char ibuf[1 << 18], *s, *t;
IO() : s(ibuf), t(ibuf) {}
inline char gc() 
{
  (s == t) && 
  (t = (s = ibuf) + fread(ibuf, 1, 1 << 18, stdin));
  return s == t ? 0 : *s++;
}
template<typename T>
operator T()
{
  register T ret = 0, f = 1; 
  register char c = gc();
  for (; !isdigit(c); c = gc())
  f = c == '-' ? -1 : 1;
  for (; isdigit(c); c = gc())
  ret = (((ret << 2) + ret) << 1) + (c - '0');
  return f == 1 ? ret : -ret;
}
} io;
const int N = 500005;
struct Node
{
  int l, r, son[2];
  ll add, sum, max;
} t[N << 2];
struct Rg
{
  int l, r, siz;
  bool operator < (const Rg &a) const 
  { return siz < a.siz; }
} r[N];
int n, m, rt, cnt, all[N << 1], tot, last, ans = (1 << 30);
inline void pushup(int k)
{
  t[k].sum = t[ls].sum + t[rs].sum;
  t[k].max = max(t[ls].max, t[rs].max);
}
inline void pushdown(int k)
{
  if(!t[k].add) return;
  t[ls].add += t[k].add, t[rs].add += t[k].add;
  t[ls].max += t[k].add, t[rs].max += t[k].add;
  t[ls].sum += (t[ls].r - t[ls].l + 1) * t[k].add;
  t[rs].sum += (t[rs].r - t[rs].l + 1) * t[k].add;
  t[k].add = 0;
}
inline void build(int &k, int l, int r)
{
  k = ++cnt, t[k].l = l, t[k].r = r;
  if(l == r) return;
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(k);
}
inline void add(int k, int l, int r, int x)
{
  if(t[k].l == l && t[k].r == r)
    return t[k].add += x, t[k].sum += (r - l + 1) * x, t[k].max += x, void();
  pushdown(k);
  int mid = t[k].l + t[k].r >> 1;
  if(r <= mid) add(ls, l, r, x);
  else if(l > mid) add(rs, l, r, x);
  else add(ls, l, mid, x), add(rs, mid + 1, r, x);
  pushup(k);
}
int main()
{
  n = io, m = io;
  for (int i = 1; i <= n; ++i)
    all[++tot] = r[i].l = io, all[++tot] = r[i].r = io, 
    r[i].siz = r[i].r - r[i].l + 1;
  sort(all + 1, all + 1 + tot);
  int siz = unique(all + 1, all + 1 + tot) - all - 1;
  for (int i = 1; i <= n; ++i)
    r[i].l = lower_bound(all + 1, all + 1 + siz, r[i].l) - all,
    r[i].r = lower_bound(all + 1, all + 1 + siz, r[i].r) - all;
  sort(r + 1, r + 1 + n);
  build(rt, 1, siz); last = 1;
  for (int i = 1; i <= n; ++i) {
    add(rt, r[i].l, r[i].r, 1);
    while(t[rt].max == m)
      add(rt, r[last].l, r[last].r, -1), 
      ans = min(ans, r[i].siz - r[last].siz), ++last;
  } ans = ans == (1 << 30) ? -1 : ans;
  printf("%d", ans);
}