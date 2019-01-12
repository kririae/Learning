title: 「BZOJ4293」Siano
author: kririae
tags:
  - 线段树
categories:
  - oi
date: 2018-10-01 03:18:00
---
# 「BZOJ4293」Siano

线段树维护即可。

<!--more-->

首先我们对$a[i]$进行排序，假定当前每个草的高度是$d[i]$，我们割掉的高度是$x$。对于$d[i] \leq x$，不会被割。在第二天会变成$d[i] + a[i]$。对于$d[j] > x$，会$d[j] = x$，然后下一天会变成$x + a[j]$。因为排序过，$j > i$，则有$a[j] > a[i]$，显然，$x + a[j] > d[i] + a[i]$。同时，也保证了操作的是一个完整的区间。

这题的区间加略特殊，加的是时间戳。
涉及的代码如下：
前缀和。
```cpp
for  (int i =  1; i <= n;  ++i)
  s[i]  = s[i -  1]  + a[i];
```
区间加。
```cpp
inline void pushdown(int k) {
  if (~set[k]) {
    sum[ls] = (R[ls] - L[ls] + 1) * set[k];
    sum[rs] = (R[rs] - L[rs] + 1) * set[k];
    add[ls] = add[rs] = 0;
    mx[ls] = mx[rs] = set[k];
    set[ls] = set[rs] = set[k];
    set[k] = -1;
  }
  if (add[k]) {
    sum[ls] += (s[R[ls]] - s[L[ls] - 1]) * add[k];
    sum[rs] += (s[R[rs]] - s[L[rs] - 1]) * add[k];
    add[ls] += add[k];
    add[rs] += add[k];
    mx[ls] += a[R[ls]] * add[k];
    mx[rs] += a[R[rs]] * add[k];
    add[k] = 0;
  }
}
```
区间赋值还是套路。

然后我们需要找到$\ge b[i]$的第一个位置，以便修改$[pos, n]$的所有信息。

```cpp
inline int QueryPos(int k, ll x) {
  if (L[k] == R[k])
    return L[k];
  pushdown(k);
  if (mx[ls] >= x)
    return QueryPos(ls, x);
  else 
    return QueryPos(rs, x);
}
```

对于$[pos, n]$的所有值，都是$\ge b[i]$的。所以$sum(pos, n)$减去$b[i] * (n - pos + 1)$就是答案。

具体代码如下：

```cpp
#define ll long long
#define ls son[k][0]
#define rs son[k][1]
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline ll read() {
  register ll k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 500005;
int n, m, a[N]; ll s[N];
struct Sgt {
int L[N << 2], R[N << 2], son[N << 2][2], rt, cnt;
ll sum[N << 2], add[N << 2], set[N << 2], mx[N << 2];
// sum, set, mx maintain specfic value, while add maintains timestamp.
inline void pushup(int k) {
  sum[k] = sum[ls] + sum[rs];
  mx[k] = max(mx[ls], mx[rs]);
}
inline void pushdown(int k) {
  if (~set[k]) {
    sum[ls] = (R[ls] - L[ls] + 1) * set[k];
    sum[rs] = (R[rs] - L[rs] + 1) * set[k];
    add[ls] = add[rs] = 0;
    mx[ls] = mx[rs] = set[k];
    set[ls] = set[rs] = set[k];
    set[k] = -1;
  }
  if (add[k]) {
    sum[ls] += (s[R[ls]] - s[L[ls] - 1]) * add[k];
    sum[rs] += (s[R[rs]] - s[L[rs] - 1]) * add[k];
    add[ls] += add[k];
    add[rs] += add[k];
    mx[ls] += a[R[ls]] * add[k];
    mx[rs] += a[R[rs]] * add[k];
    add[k] = 0;
  }
}
inline void Build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l;
  R[k] = r;
  if (l == r)
    return;
  int mid = l + r >> 1;
  Build(ls, l, mid);
  Build(rs, mid + 1, r);
}
inline void Add(ll x) {
  add[rt] += x;
  sum[rt] += s[n] * x;
  mx[rt] += a[n] * x;
}
inline int QueryPos(int k, ll x) {
  if (L[k] == R[k])
    return L[k];
  pushdown(k);
  if (mx[ls] >= x)
    return QueryPos(ls, x);
  else 
    return QueryPos(rs, x);
}
inline ll Query(int k, int l, int r) {
  if (L[k] == l && R[k] == r)
    return sum[k];
  pushdown(k);
  int mid = L[k] + R[k] >> 1;
  if (r <= mid)
    return Query(ls, l, r);
  else if (l > mid)
    return Query(rs, l, r);
  else 
    return Query(ls, l, mid) + Query(rs, mid + 1, r);
  pushup(k);
}
inline void Set(int k, int l, int r, ll x) {
  if (L[k] == l && R[k] == r) {
    set[k] = mx[k] = x;
    sum[k] = 1ll * (r - l + 1) * x;
    add[k] = 0;
    return;
  }
  pushdown(k);
  int mid = L[k] + R[k] >> 1;
  if (r <= mid)
    Set(ls, l, r, x);
  else if (l > mid)
    Set(rs, l, r, x);
  else
    Set(ls, l, mid, x), Set(rs, mid + 1, r, x);
  pushup(k);
}
inline ll operator [] (int x) {
  return Query(rt, x, x);
}
} t;
inline ll Work(ll d, ll x) {
  static ll pre = 0;
  ll tp = d - pre, ans = 0;
  t.Add(tp);
  if (x >= t.mx[t.rt]) {
    pre = d;
    return 0;
  }
  int pos = t.QueryPos(t.rt, x);
  ans = t.Query(t.rt, pos, n) - x * (n - pos + 1);
  t.Set(t.rt, pos, n, x);
  pre = d;
  return ans;
}
int main() {
  memset(t.set, -1, sizeof t.set);
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) 
    a[i] = read();
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i)
    s[i] = s[i - 1] + a[i];
  t.Build(t.rt, 1, n);
  for (int i = 1; i <= m; ++i) {
    ll d, x;
    d = read(), x = read();
    printf("%lld\n", Work(d, x));
  }
}
```

注意，，，$set$初始化为$-1$，因为有$set \ 0$的情况。