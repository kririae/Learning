/*
简单环的定义是啥？
或者说，“简单环”能够造成什么限制？
——只算环上的边，每个点的出度和入度都为1
题目转化为以下形式，从G = (V, E)中选取n条边，使得每个点的出度和入度都是1
dp方式如下 f[i][S]表示前i个点都有出边，S的点有了入边，的情况的个数
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m, a[N + 1][N + 1], f[N + 1][(1 << N) + 5];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    a[x][y] = 1;
  }
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) 
    for (int S = 0; S < (1 << n); ++S)
      if (__builtin_popcount(S) + 1 == i)
        for (int j = 1; j <= n; ++j)
          if (a[i][j] && !(S & (1 << (j - 1))))
            f[i][S | (1 << (j - 1))] = (1ll * f[i][S | (1 << (j - 1))] + f[i - 1][S]) % 998244353;
  cout << f[n][(1 << n) - 1];
}