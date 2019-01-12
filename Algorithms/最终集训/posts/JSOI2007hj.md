title: 「JSOI2007」合金
author: kririae
tags:
  - 计算几何
  - 图论
categories:
  - oi
date: 2018-03-09 13:13:00
---
# JSOI2007合金

---

<!--more-->

终于ac了...
方法是在看题解之后一脸懵逼，然后在学校上课期间研究半天然后回来写了   
WA无数次，然后spj一发过了   
常数很小的一份代码（我难得常数小一次） 

> 思路：  
利用图论和计算几何的建模   
这道题本质上是求点最少的凸包   
有三个数据。而且存在“配置”的特性：
如果有两个原料要合成一个产品，抽象在坐标系里，这个产品的点一定在原料的线段上。    
三个点的话，产品一定在三个点构成的三角形中   
从而抽象为一个凸包问题   
三个点看似是三维凸包，但是由于和为1的，可以只管a, b两项，从而为
点最少可以想到floyd最小环（图论建模）   
枚举所有的线段，判断所有点是不是在其右边/左边。如果是，这个线段可能是凸包上的一个边，然后把这个线段作为边放进图里。
由于可能有“所有产品都是一样的”的情况...写了个spj...

```cpp
// by kririae
// 2018/3/9

#include <bits/stdc++.h>
using namespace std;
namespace solve
{
const double eps = 1e-8;
struct Point
{
    double a, b, c;
    Point()
    {}
    Point(double x, double y):
        a(x), b(y) {}
    Point(double x, double y, double z):
        a(x), b(y), c(z) {}
    Point operator- (const Point& x)
    {
        return Point(a - x.a, b - x.b, c - x.c);
    }
    bool operator== (const Point& x)
    {
        return fabs(a - x.a) < eps && fabs(b - x.b) < eps;
    }
    double operator^ (const Point& x)
    {
        return a * x.b - x.a * b;
    }
    double operator* (const Point& x)
    {
        return a * x.a + b * x.b;
    }
};

const int maxn = 505;
int m, n;
Point t[maxn], u[maxn];
int f[maxn][maxn];

inline void init()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        cin >> t[i].a >> t[i].b >> t[i].c;
    for (int i = 1; i <= n; ++i)
        cin >> u[i].a >> u[i].b >> u[i].c;
}

inline bool spj()
{
    Point sample = u[1];
    for (int i = 1; i <= n; ++i) 
        if(!(u[i] == u[1])) return false;
    return true;
}

inline void solve()
{
    init();
    register int k, i, j;
    for (i = 1; i <= m; ++i)
    for (j = 1; j <= m; ++j) 
        f[i][j] = 1e9;

    if(spj()) for (i = 1; i <= m; ++i) if(t[i] == u[1]) {
        cout << 1 << endl;
        exit(0);
    } // 强行ac.jpg

    for (i = 1; i <= m; ++i)
        for (j = 1; j <= m; ++j)
        {
            if(i == j) continue;
            if(t[i] == t[j]) continue;
            bool fl = false;
            for (k = 1; k <= n; ++k) {
                double cr = (t[i] - t[j]) ^ (t[i] - u[k]);
                if(cr < -eps) { fl = true; break; }
                if(fabs(cr) < eps && (t[i] - u[k]) * (t[j] - u[k]) > eps)  
                { fl = true; break; }
            }
            if (!fl) { f[i][j] = 1; }
        }
    for (k = 1; k <= m; ++k)
        for (i = 1; i <= m; ++i)
            for (j = 1; j <= m; ++j) 
            {
            	if (f[i][k] == 1e9) continue;  
                if (f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k] + f[k][j];
            }
    int minn = 1e9;
    for (i = 1; i <= m; ++i) minn = min(f[i][i], minn);
    // for (int i = 1; i <= m; ++i) cout << f[i][i] << " ";
    if(minn == 1e9) cout << -1 << endl;
    else cout << minn << endl;
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve::solve();
    return 0;
}
```