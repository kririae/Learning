title: '「LG1937」Barn Allocation '
author: kririae
tags:
  - 线段树
  - 贪心
categories:
  - oi
date: 2018-08-21 08:44:00
---
# Barn Allocation 

贪心 + 线段树维护即可。

<!--more-->

刚看题，大概就知道是一个贪心加线段树维护，与NOI的区间一题类似。不过这道题不涉及尺取法。  
所以，如何证明贪心的正确性？其实是一个区间覆盖的思路。
很大一部分贪心的正确性证明都基于想出贪心策略，所以我们先瞎蒙几个贪心策略:   
按照$l$排序，按照$r$排序，按照$r - l + 1$排序（即“区间”一题的策略。   
首先，排除最显然的，按照$l$排序：$[1, 2], [3, 4], [5, 6], [1, 6]$。
然后，然后。。。让我们发现我们贪心，是要干什么:  
让这一次决策影响前面最小。   
显然，是按照右端点排序。感性理解一下，上一次覆盖了一些位置，这一次就要尽量像右靠。然而，只要按照$r$排序了，剩下的都好说。LG上左端点怎么排都能$A$，但窝觉得左端点要从小到大。毕竟区间越短影响越小。

```cpp
#include <bits/stdc++.h>
#define ll long long
#define ls t[k].son[0]
#define rs t[k].son[1]
using namespace std;

const int N = 100005;
struct Node {
  int l, r, son[2];
  ll add, sum, min;
  // min -> 剩余容量最小值
} t[N << 2];
struct Q {
  int l, r;
  bool operator < (const Q &a) const {
    return r == a.r ? l < a.l : r < a.r;
  }
} a[N];
int n, m, c[N], cnt, rt, ans;
inline void pushup(int k) {
  t[k].sum = t[ls].sum + t[rs].sum;
  t[k].min = min(t[ls].min, t[rs].min);
}
inline void pushdown(int k) {
  t[ls].add += t[k].add;
  t[rs].add += t[k].add;
  t[ls].sum += (t[ls].r - t[ls].l + 1) * t[k].add;
  t[rs].sum += (t[rs].r - t[rs].l + 1) * t[k].add;
  t[ls].min -= t[k].add;
  t[rs].min -= t[k].add;
  t[k].add = 0;
}
inline void build(int &k, int l, int r) {
  k = ++cnt;
  t[k].l = l;
  t[k].r = r;
  if (l == r) 
    return (void) (t[k].min = c[l]);
  int mid = l + r >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  pushup(k);
}
inline void add(int k, int l, int r, int x) {
  if (t[k].l == l && t[k].r == r) {
    t[k].add += x;
    t[k].sum += 1ll * (r - l + 1) * x;
    t[k].min -= x;
    return;
  }
  pushdown(k);
  int mid = t[k].l + t[k].r >> 1;
  if (r <= mid)
    add(ls, l, r, x);
  else if (l > mid)
    add(rs, l, r, x);
  else add(ls, l, mid, x), add(rs, mid + 1, r, x);
  pushup(k);
}
inline ll query(int k, int l, int r) {
  if (t[k].l == l && t[k].r == r)
    return t[k].min;
  pushdown(k);
  int mid = t[k].l + t[k].r >> 1;
  if (r <= mid)
    return query(ls, l, r);
  else if (l > mid)
    return query(rs, l, r);
  else return min(query(ls, l, mid), query(rs, mid + 1, r));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) 
    scanf("%d", &c[i]);
  build(rt, 1, n);
  for (int i = 1; i <= m; ++i) 
    scanf("%d%d", &a[i].l, &a[i].r);
  sort(a + 1, a + 1 + m);
  for (int i = 1; i <= m; ++i)
    if (query(rt, a[i].l, a[i].r) > 0) {
      ++ans;
      add(rt, a[i].l, a[i].r, 1);
    }
  printf("%d", ans);
}
```