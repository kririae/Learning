title: 「题解」POJ1179 Polygon
author: kririae
tags:
  - 动态规划
categories:
  - oi
date: 2018-03-30 13:25:00
---
# POJ1179 POLYGON

---

<!--more-->

其实这道题写的我蛮爽的   
由于两个最大的数相乘不一定是最大的(一正一负比两负乘积小)   
考虑同时转移最大值和最小值，总有一个最大的
对于有环形的题目的处理方法，通常都是复制一份放在后面   
```cpp
// by kririae
#include <iostream>

using namespace std;

namespace IOI1998
{
const int maxn = 55;
int n;
int a[maxn << 2];
char op[maxn << 2];
int f[maxn << 2][maxn << 2][2];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) 
    {
        cin >> op[i] >> a[i]; 
        op[i + n] = op[i];
        a[i + n] = a[i];
    }
    
    // for (int i = 1; i <= n << 1; ++i) cout << a[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n << 1; ++i) cout << op[i] << " ";
    
    for (int i = 1; i <= n << 1; ++i)
        for (int j = 1; j <= n << 1; ++j)
            f[i][j][0] = (1 << 31), f[i][j][1] = ~(1 << 31);
    for (int i = 1; i <= n << 1; ++i) f[i][i][0] = f[i][i][1] = a[i];
    
    for (int len = 2; len <= n << 1; ++len)
        for (int l = 1; l <= (n << 1) - len + 1; ++l)
        {
            int r = l + len - 1;
            for (int k = l; k < r; ++k)
            {
                if(op[k + 1] == 't')
                {
                    f[l][r][0] = max(f[l][r][0], f[l][k][0] + f[k + 1][r][0]);
                    f[l][r][1] = min(f[l][r][1], f[l][k][1] + f[k + 1][r][1]);
                }
                
                if(op[k + 1] == 'x')
                {
                    f[l][r][0] = max(f[l][r][0], max(f[l][k][0] * f[k + 1][r][0], f[l][k][1] * f[k + 1][r][1]));
                    f[l][r][1] = min(f[l][r][1], min(f[l][k][1] * f[k + 1][r][1],min(f[l][k][1] * f[k + 1][r][0], f[l][k][0] * f[k + 1][r][1])));
                }
            }
        }

    int res = (1 << 31);
    for (int i = 1; i <= n; ++i)
        res = max(res, f[i][i + n - 1][0]);
        
    cout << res << endl;
    
    for (int i = 1; i <= n; ++i)
        if(f[i][i + n - 1][0] == res) cout << i << " "; 
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    IOI1998::solve();
    return 0;
}
```