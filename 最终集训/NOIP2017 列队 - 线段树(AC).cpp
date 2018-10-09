#include <bits/stdc++.h>
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read() {
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 3e5 + 5, M = (3e5 + 5) * 20;
int n, m, q;
struct Sgt {
int son[M][2], cnt, rt[N];
ll sum[M];
vector<ll> v[N];
inline void Erase(int &k, int l, int r, int x) {
  // 权值线段树中$k$位置。并非实际位置。
  if (!k)
    k = ++cnt;
  ++sum[k]; // 表示这个区间被删掉了多少个节点。
  if (l < r) {
    int mid = l + r >> 1;
    if (x <= mid) 
      Erase(ls, l, mid, x);
    else
      Erase(rs, mid + 1, r, x);
  }
}
inline int Find(int &k, int l, int r, int x) {
  // 找到第$x$个数
  if (!k) 
    k = ++cnt;
  if (l == r)
    return l; // 返回的线段树中实际的位置
  int mid = l + r >> 1,
      sz = (mid - l + 1) - sum[ls]; // 表示左区间剩余的节点数（原本的大小减去删除的数的个数
  if (sz >= x)
    Find(ls, l, mid, x);
  else
    Find(rs, mid + 1, r, x - sz);
}
inline ll Work01(int k) {
  // y == m时的列操作
  int pos = Find(rt[0], 1, n + q, k);
  Erase(rt[0], 1, n + q, pos);
  ll ans = 0;
  if (pos <= n)
    ans = 1ll * pos * m;
  else 
    ans = v[0][pos - n - 1]; // 从0开始
  v[0].push_back(ans);
  return ans;
}
inline ll Insert01(int k, ll x) {
  // 查询列中的k位置顺便加入x
  int pos = Find(rt[0], 1, n + q, k);
  Erase(rt[0], 1, n + q, pos);
  ll ans = 0;
  if (pos <= n)
    ans = 1ll * pos * m;
  else 
    ans = v[0][pos - n - 1];
  v[0].push_back(x);
  return ans;
}
inline ll Work02(int k, int x) {
  int pos = Find(rt[k], 1, m + q - 1, x);
  Erase(rt[k], 1, m + q - 1, pos);
  ll ans = 0;
  if (pos < m)
    ans = 1ll * (k - 1) * m + pos; // 这里的pos是实际位置，因为有< m的前提在
  else 
    ans = v[k][pos - m]; // pos - m + 1 - 1
  v[k].push_back(Insert01(k, ans));
  return ans;
}
} a;
int main() {
  n = read(), m = read(), q = read();
  for (int i = 1, x, y; i <= q; ++i) {
    x = read(), y = read();
    if (y == m)
      printf("%lld\n", a.Work01(x));
    else
      printf("%lld\n", a.Work02(x, y));
  }
}