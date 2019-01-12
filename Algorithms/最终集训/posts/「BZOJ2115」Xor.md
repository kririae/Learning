title: 「BZOJ2115」Xor
author: kririae
date: 2018-09-18 15:00:13
tags:
---
# 「BZOJ2115」Xor

线性基即可

<!--more-->

---

给定无向图，求$1, n$路径的异或和最大值。

这题妙啊。。。
首先，我们考虑把图看成环 + 链。
解法如下：对于任意一条$1 \rightarrow n$的路径，我们求出其`xor`和，然后找出图中所有的环，因为对于路径上任意一个点到环然后返回，路径与环之间的边都被经过了两次，所以不用计入答案。我们求出环的`xor`和，加入线性基。对于$dis[n]$，求$dis[n]$与所有的环的异或最大值。
首先，为什么可以选取任意一条路径。假如说$1 \rightarrow n$只有一条路径，不必说。假如说$1 \rightarrow n$有两条路径，其必定有$x$作为其交汇点，而$1 \rightarrow x$可以形成一条环。在与$dis[n]$求$xor$的时候，这条环会被切成两条链。一条是一开始选择的，另一条是环上除去被选择的那一部分的剩余部分。所以我们选取这剩余部分的效果是一样的。也就是说，选取两条是等效的。所以我们可以选取任意一条$1 \rightarrow n$的路径求异或最大值。

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 50005;
int n, m, head[N], ver[N << 2], nxt[N << 2], tot, vis[N];
ll a[65], edge[N << 2], dis[N];
inline void Addedge(int u, int v, ll w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void Insert(ll x) {
  for (int i = 60; i >= 0; --i)
    if ((x >> i) & 1) {
      if (a[i] == 0) {
        a[i] = x;
        break;
      }
      x ^= a[i];
    }
}
inline ll Query(ll x) {
  for (int i = 60; i >= 0; --i)
    x = max(x, x ^ a[i]);
  return x;
}
inline void Dfs(int x) {
  vis[x] = 1;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    to = ver[i];
    if (vis[to]) Insert(dis[x] ^ dis[to] ^ edge[i]);
    else dis[to] = dis[x] ^ edge[i], Dfs(to);
  }
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d", &n, &m);
  int s, t; ll d;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%lld", &s, &t, &d);
    Addedge(s, t, d);
    Addedge(t, s, d);
  }
  Dfs(1);
  printf("%lld", Query(dis[n]));
}
```