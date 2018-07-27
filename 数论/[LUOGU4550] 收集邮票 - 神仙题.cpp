/*
# 收集邮票
神仙题
设$f[i]$为买了$i$张，买完剩下的期望张数。
对于买的$i + 1$张，有$\frac{n - i}{n}$的期望买到已经买到了的，有$\frac{i}{n}$的买到没有买过的，$f[i] = \frac{i}{n}f[i] + \frac{n - i}{n}f[i + 1] + 1$。
设$g[i]$为买了$i$张，买完剩下的张数，还要花的钱。
对于买的$i +1$张，得出$g[i] = \frac{i}{n}g[i] + \frac{n - i}{n}g[i +1] + x$。$x$为买这张期望所花的钱。问题来了，怎么计算买这张所花费的钱？我们采用一个借的思想。我们可以假设每次买的价格都增加$1$，所以总共需要买的是一个底面长度为$f[n]$的类梯形。第一次我把后面所有的期望需要买的都垫付了，然后付自己的$1$元，这样，下次买的时候，依然是这样的。所以$g[i] = \frac{i}{n}g[i] + \frac{n - i}{n}g[i +1] + f[i + 1] + 1$。
转换$f$和$g$的转移方程如下：咕咕咕
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;
int n;
double f[maxn], g[maxn];
int main()
{
  scanf("%d", &n);
  f[n] = g[n] = 0;
  for (int i = n - 1; i >= 0; --i)
    f[i] = f[i + 1] + 1.0 * n / (1.0 * n - i);
  for (int i = n - 1; i >= 0; --i)
    g[i] = g[i + 1] + 1 + f[i + 1] + (f[i] + 1) * (1.0 * i / (n - i));
  printf("%.2lf", g[0]);
}