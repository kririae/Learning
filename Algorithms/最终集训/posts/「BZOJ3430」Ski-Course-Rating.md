title: 「BZOJ3430」Ski Course Rating
author: kririae
tags:
  - 图论
categories:
  - oi
date: 2018-08-22 07:44:00
---
# 「BZOJ3430」Ski Course Rating

最小生成树（伪）

<!--more-->

严格来说不能是最小生成树，只是我觉得思路很类似。
大意如下：   
对于一个$n \times m$的矩阵，每个位置有唯一对应的值。定义一个位置$(i, j)$的权值的$d$，满足条件：若从$(i, j)$开始$bfs$，相邻两个点的初始权值之差的绝对值小于$d$。切能够遍历到的点的个数大于最开始给出的$k$。给定需要求的点，最小化这些点的权值之和。   
遇到这类的求和，通常有一个套路：枚举某一个值，然后统计这个值出现的个数。对于整个图，从每个需要求值的点出发，$d_2 > d_1$，则图中被便利到的点的个数，在$d = d_2$时一定大于等于$d = d_1$。   
前面都是铺垫，下面才是正文！   
对于$n \times m$矩阵中每一个点到相邻的点，我们连接一条边，边权是点权之差的绝对值。我们对所有的边进行排序，依次加入。对于每一次加入，维护并查集，并查集信息表示哪些点被合并，顺带维护每个并查集的大小。对于某一次加入，最多合并两个并查集。对于这两个并查集的合并，假如说合并后的并查集大小$>= k$，那么这个并查集内的点可以互相到达，并且集合内的最大边最小。满足条件。我们维护并查集中需要计算的点的个数，集合内最大的边权$\times$点的个数就是这集合中的点的最小的$d$值。对于某一次合并，合并$S_1, S_2$，且$s[S_1] >= k, s[S_2] < k$，所以$S_1$中的每个点都已经被计算过了。我们只用计算$S_2$，避免了所有的重复计算。
代码如下：

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 505;
struct Edge {
  int u, v, w;
  Edge() {}
  Edge(int _u, int _v, int _w) :
  u(_u), v(_v), w(_w) {}
  bool operator < (const Edge &a) const {
    return w < a.w;
  }
} edges[N * N * 2];
int n, m, k, tot, fa[N * N], s[N * N], 
a[N][N], b[N * N]; ll ans;
inline int calc(int x, int y) {
  return (x - 1) * m + y;
}
inline void addedge1(int u, int v, int w) {
  edges[++tot].u = u;
  edges[tot].v = v;
  edges[tot].w = w;
}
inline int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &b[calc(i, j)]);
  for (int i = 1; i <= n; ++i) 
    for (int j = 1; j <= m; ++j) {
      if (i != n) 
        addedge1(calc(i, j), calc(i + 1, j), abs(a[i][j] - a[i + 1][j]));
      if (j != m)
        addedge1(calc(i, j), calc(i, j + 1), abs(a[i][j] - a[i][j + 1]));
    }
  sort(edges + 1, edges + 1 + tot);
  for (int i = 1; i <= n * m; ++i)
    fa[i] = i, s[i] = 1;
  for (int i = 1; i <= tot; ++i) {
    Edge &e = edges[i];
    int x = find(e.u);
    int y = find(e.v);
    if(x == y) continue;
    if(s[x] + s[y] >= k) {
      if(s[x] < k) ans += 1ll * b[x] * e.w;
      if(s[y] < k) ans += 1ll * b[y] * e.w;
    }
    fa[x] = y, s[y] += s[x], b[y] += b[x];
  }
  cout << ans << endl;
}
```