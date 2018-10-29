# $\text{Contest 2018 10 29}$

# $\text{T1}$

给出数列$A$，你需要自行选定$q$个长度为$k$的区间,每次删除区间内的最小值(当最小值有多个时任选一个),使得删除的$q$个数中最小值和最大值的差尽量小。$n \le 100000$。

毒瘤...
$\text{ARC098E}$，还带加强的。

原题数据范围是$O(n^2\log{n})$的，我的解法是这样的。
枚举删除数字的最小值，我们需要确定一个最小的最大值，从“限制”入手，枚举了最小值，代表所有比最小值小的都不能选了。确定最小的最大值有两种写法，比较类似。

可以二分最小的最大值，比最小值小的数字标记为$0$，最小值最大值之间的值标记为$1$，大于最大值的标记为$2$。所有含有$0$的区间都不能选，只能选仅含$1, 2$的区间。一个包含$1, 2$的区间中，又只有$1$才能对答案造成贡献，假如$1, 2$区间长度为$len$，我们只能从中选$len - k + 1$个$1$。贪心选择即可。

第二种写法不再介绍，相当类似，只是从区间中抽出最小的$len - k + 1$个数，放入新的数组排序，然后取第$q$个。

考虑$O(n\alpha(n))$的做法，考虑$\text{two pointers}$，对原数组排序，将$tpt$的左右指针放在排序后的数组上，我们向右移动指针的时候，顺带维护原数组的$0, 1, 2$性质。这样，每个数都会从$2 \rightarrow 1 \rightarrow 0$，当一个数从$1 \rightarrow 0$的时候，会将左右两个区间分开，我们会发现分开区间并不好处理，考虑合并区间。我们$tpt$倒过来扫，每个数字都会$0 \rightarrow 1 \rightarrow 2$，这样，就从分裂变成了合并。每当一个数字从$0 \rightarrow 1$的时候，就会合并其左右的区间，并且用并查集维护区间$1, 2$的个数。

$AC$代码懒得写了，给$70$的吧。
```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2005;
int n, q, k;
ll a[N], b[N], c[N], cnt, tot;
int main() {
  scanf("%d%d%d", &n, &k, &q);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &a[i]);
  ll ans = 1ll << 60;
  for (int i = 1; i <= n; ++i) {
    tot = 0;
    a[n + 1] = -(1ll << 60);
    for (int j = 1; j <= n + 1; ++j)
      if (a[j] >= a[i])
        b[++cnt] = a[j];
      else {
        sort(b + 1, b + 1 + cnt);
        for (int i = 1; i <= cnt - k + 1; ++i)
          c[++tot] = b[i];
        cnt = 0;
      }
    sort(c + 1, c + 1 + tot);
    if (tot >= q)
      ans = min(ans, c[q] - a[i]);
  }
  cout << ans;
}
```

# $\text{T2}$

$n$点$m$边无向带权图。$s$个加油站，有$q$次询问，给出起点，终点，起点终点都是加油站，给出一辆车，车有油量上限$k_i$，油量满的情况下能行驶$k_i$的距离，问能否从$s \rightarrow t$。$n, s, q \le 100000$。

$\text{BZOJ4144}$
考场想到$50pts$，结果$4k$的代码写炸了...
图上查询问题，离不了树上问题的处理。
观察到，如果能安全从$s \rightarrow t$，必定会经过一些加油站。而且，对于经过的加油站，两两之间的距离必须$\le k$。暴力的话，考虑$s$两两之间的最短路建成完全图。在完全图上跑最小生成树，就能$s \rightarrow t$全部经过$\le k$的边。如果$s \rightarrow t$的最大边权$> k$，就不能从$s$到$t$。

然后我写炸了，然后爆零了。
瓶颈出来了，$s$的完全图的最小生成树怎么处理。
考虑图中的这种路径，$s, k, t$都是加油站，并且存在$s \rightarrow k$，$k \rightarrow t$，那么$s \rightarrow t$一定没有存在的必要。

<!--stackedit_data:
eyJoaXN0b3J5IjpbMzUxMDQwNzA5LC0xMDA5MzY2MTA4XX0=
-->