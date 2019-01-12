title: 「TEST」Storm
author: kririae
date: 2018-08-06 09:27:48
tags:
---
# 「TEST」Storm

树状数组维护dp数组即可

---

随机给出长度为$n$的数列，输出数列中每种长度的最长上升子序列的个数。$n \leq 10000$。

30分暴力可以略过么。
70分的写出来了，100也不难了。
这道题骚就骚在那个“随机”。随机给出的数列，最长上升子序列的期望是$\sqrt{n}$。所以复杂度就变成了$O(n\log{n}\sqrt{n})$。
然后稍微具体提一提70分的怎么写。其实是普通的树状数组维护最长上升子序列，只是平时不常用.本来的方程转移是这样的，$f[i][len] += f[j][len - 1]$。$j \leq i, a[j] < a[i]$。我们以$a[i]$建立树状数组，每次$a[i]$的前缀，也就是所有的$j \leq i, a[j] < a[i]$。这样就做到了$O(logn)$的转移。剩下的就是看代码了：
```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 10005, mod = 1e9 + 7;
int n, a[N], f[N][2]; ll t[N];
// 到第i个点，长度为j的最长上升子序列的个数
inline void add(int x, int v)
{
  for (; x <= n; x += x & -x) (t[x] += v) %= mod;
}
inline ll get(int x)
{
  ll ans = 0;
  for (; x; x -= x & -x) (ans += t[x]) %= mod;
  return ans;
}
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int pre = 0, curr = 1;
  for (int i = 1; i <= n; ++i) add(a[i], 1);
  for (int i = 1; i <= n; ++i) f[i][pre] = 1;
  for (int k = 2; k <= n + 1; swap(pre, curr), ++k) {
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; ++i) 
      f[i][curr] = get(a[i] - 1), add(a[i], f[i][pre]);
    ll ans = get(n);
    if(ans == 0) {
      for (int i = k; i <= n + 1; ++i)
        cout << 0 << " ";
      return 0;
    } else cout << ans << " ";
  }
}
```