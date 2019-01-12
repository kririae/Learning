title: 「题解」「HNOI2011 」数学作业
author: kririae
tags:
  - 数论
  - 矩阵快速幂
categories:
  - oi
date: 2018-07-10 07:59:00
---
# 「HNOI2011 」数学作业

> (默默放下了手中的数学作业，因为基本一下子就想到了这道题辣qwq

## 说明
解决时间：$1:47:58h$

我们首先看递推式
$f[n] = f[n - 1] \cdot 10^{len(n)} + n$
注意...写在代码里的时候需要$+1$..坑了我好一会儿
然后，我们发现，这玩意儿根本没法快速幂啊！！！
然后呢，于是呢，就想到了分段求解
我们把要求解的分成$[0, 9], [10, 99], [100, 999], [1000, 9999]...$
然后算矩阵递推式

$$
\begin{bmatrix}
10^{len(n)} & 1 & 1\\
0 & 1 & 1\\
0 & 0 & 1 \\
\end{bmatrix}
\times
\begin{bmatrix}
f_n \\
n \\
1
\end{bmatrix}=
\begin{bmatrix}
f_{n +1} \\
n + 1 \\
1
\end{bmatrix}
$$

## 错误
1. 矩阵乘法写错 * n...这回写成`ans[i][j] +=(a[i][k] * val[k][j] % MOD)` 莫名没过...然后改成`ll ans = 0;`才过的
2. `unsigned long long`? 虽然只卡了一会儿
3. 还有`trans`的时候，如果`_r` $<$ `_l`的时候回炸掉？

## 代码如下
```cpp
#define ull unsigned long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int siz = 5;

namespace BZOJ2326
{
ull n, l, MOD;

struct Matrix
{
ull n, m, a[siz][siz];

Matrix()
{
  memset(a, 0, sizeof(a));
  for (R int i = 0; i < siz; ++i) a[i][i] = 1;
}
Matrix(int _n, int _m) : n(_n), m(_m) 
{
  memset(a, 0, sizeof(a));
  for (R int i = 0; i < siz; ++i) a[i][i] = 1;
}

ull* operator [] (int x) 
{
  return a[x];
}

inline Matrix operator * (Matrix val)
{
  Matrix ans(this->n, val.m);
  R int i, j, k;
  for (i = 1; i <= this->n; ++i)
    for (j = 1; j <= val.m; ++j)
    {
      ull res = 0;
      for (k = 1; k <= this->n; ++k)
        res += (a[i][k] * val[k][j] % MOD);
      ans[i][j] = res;
    }
  return ans;
}
inline Matrix pow(ull p)
{
  if(n != m) return Matrix(this->n, this->n);
  Matrix ans(this->n, this->n), t = *this;
  for (; p; p >>= 1)
  {
    if(p & 1) ans = t * ans;
    t = t * t;
  }
  return ans;
}
} qwq(3, 1), tmp(3, 3);

inline ull pow(ull a, ull p)
{
  ull ans = 1; a %= MOD;
  for (; p; p >>= 1)
  {
    if(p & 1) ans = (a * ans) % MOD;
    a = (a * a) % MOD;
  }
  return ans;
}

inline int len(ull val)
{
  int cnt = 0;
  while(val) ++cnt, val /= 10;
  return cnt;
}

inline void trans(Matrix &val, ull _l, ull _r)
{
  _r = (_l % 10 ? _r : _r + 1);
  tmp[1][1] = pow(10, len(_l));
  val = tmp.pow(_r - _l) * val;
}

inline void solve()
{
  scanf("%lld%lld", &n, &MOD);
  qwq[1][1] = qwq[2][1] = qwq[3][1] = 1;
  tmp[1][2] = tmp[1][3] = tmp[2][2] = tmp[2][3] = tmp[3][3] = 1;
  R ull l = 1, r = 9;
  for (; r <= n; l *= 10, r = l * 10 - 1) trans(qwq, l, r);
    trans(qwq, l, n);
  printf("%lld", qwq[1][1] % MOD);
}
}

int main()
{
  return BZOJ2326::solve(), 0;
}
```
