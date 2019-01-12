title: 「TEST」2018 - 8 - 8
author: kririae
date: 2018-08-09 07:39:54
tags:
---
# 「TEST」Wuke

莫队算法 + 卡常即可

<!--more-->

问题如下：
给出$n$个点联通树，每次询问$[l, r]$的点构成的图中，联通块的个数。

首先，给出$[l, r]$的时候，已经知道了点的数量，我们只要快速知道$[l, r]$之间边的数量即可知道$[l, r]$之间联通块的数量。用莫队维护，每次加入一个点的时候枚举这个点所有的出边，看是否在$[l, r]$之间。出边总个数是$n - 1$。复杂度也保证了。
然而，在仔细思考之后，会发现，这莫队略微妙啊???
明明我在建图的加入的是双向边，为啥统计的时候用的单向边？为什么不需要$\frac{cnt}{2}$？
还有一个问题？加入$i$的时候区间限制是$[l, r]$，但是当拓展到$[l - n, r + m]$的时候，$i$和它们的边会不会少统计了？
不会。假如说$[l - n, l]$中有和$i$相连的边，一定会在某一次拓展中被加入，而$i$暂时不会再次被更新，所以在加入的时候都是单向边，也就是$[l, r, l]$中的某一个$\rightarrow i$。


```cpp
// by kririae
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 1e5 + 5;
int n, q, siz, head[N], ver[N << 1], nxt[N << 1], tot;
int l = 1, r = 0, cnt = 0, ans[N];
struct req {
  int l, r, pos, id;
  bool operator < (const req &a) const {
    if(pos == a.pos) {
      if(pos & 1) return r < a.r;
      else return r > a.r;
    } else return pos < a.pos;
  }
} a[N];
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
} // 探讨联通块的性质，以此入手。
inline void add(int x) {
  for (int i = head[x]; ~i; i = nxt[i])
    if(ver[i] >= l && ver[i] <= r) ++cnt;
}
inline void del(int x) {
  for (int i = head[x]; ~i; i = nxt[i])
    if(ver[i] >= l && ver[i] <= r) --cnt;
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &q);
  siz = sqrt(n) + 1;
  for (int i = 1, a, b; i < n; ++i) {
    scanf("%d%d", &a, &b);
    addedge(a, b);
    addedge(b, a);
  } 
  for (int i = 1, l, r; i <= q; ++i) {
    scanf("%d%d", &l, &r);
    a[i].l = l, a[i].r = r;
    a[i].pos = (l / siz) + 1, a[i].id = i;
  }
  sort(a + 1, a + 1 + q);
  for (int i = 1; i <= q; ++i) {
    req &c = a[i];
    while(r > c.r) del(r), --r;
    while(r < c.r) ++r, add(r);
    while(l < c.l) del(l), ++l;
    while(l > c.l) --l, add(l);
    ans[c.id] = (r - l + 1) - cnt;
  }
  for (int i = 1; i <= q; ++i)
    printf("%d\n", ans[i]);
}
```

2018-9-22
补充树状数组解法

顺着扫描$i \in [1, n]$，对于$i$，首先加入所有$i$所连的，$\leq i$的点到树状数组里，这样就可以维护$[1, i]$的所有边的个数。然后扫描以$i$为右端点的询问，查询$[l, r]$中每个点的权值。因为对于树状数组维护的某个点的权值，其实是以这个点为端点的边的个数，而边不会重复。

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, q, head[N], ver[N << 1], 
nxt[N << 1], tot, res[N];
ll t[N];
vector< pair<int, int> > to[N];
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void Add(int p, int x) {
  for (; p <= n; p += p & -p) t[p] += x;
}
inline int Query(int p, int ans = 0) {
  for (; p; p -= p & -p) ans += t[p];
  return ans;
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d", &n, &q);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  for (int i = 1, l, r; i <= q; ++i) {
    scanf("%d%d", &l, &r);
    if (l > r) swap(l, r);
    to[r].push_back(make_pair(l, i));
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = head[i]; ~j; j = nxt[j])
      if (ver[j] <= i) Add(ver[j], 1);
    for (int j = 0; j < to[i].size(); ++j) {
      int l = to[i][j].first, id = to[i][j].second;
      res[id] = (i - l + 1) - (Query(i) - Query(l - 1));
    }
  }
  for (int i = 1; i <= q; ++i) 
    printf("%d\n", res[i]);
}
```