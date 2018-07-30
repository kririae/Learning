// by kririae
// BZOJ3928 、 4048
/*
讲题的时候想到一点这道题的解法...
其实还是蛮有意思的
首先，我以为这道题是个xjb贪心...
结果发现有问题
但是，贪心给了我策略上的启发
因为对于某个外星人，越晚打一发一定没有错
而对于所有的外星人，最大的那一个一定会被打一发
顺带带走所有次时间的外星人
我们枚举跨越这个点的，所以左区间右区间里的线段一定不跨越这个点
然后递归记忆化搜索
 */
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 305;

namespace BZOJ4048_3928 // 双倍经验，但是我没有权限QAQ
{
int t, n, l[maxn], r[maxn], d[maxn], all[maxn << 1], cnt, f[maxn << 1][maxn << 1];
inline void solve()
{
  scanf("%d", &t);
  while(t--) {
    cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d%d", &l[i], &r[i], &d[i]);
      all[++cnt] = l[i], all[++cnt] = r[i];
    }
    sort(all + 1, all + 1 + cnt);
    cnt = unique(all + 1, all + 1 + cnt) - all - 1;
    for (int i = 1; i <= n; ++i) 
      l[i] = lower_bound(all + 1, all + 1 + cnt, l[i]) - all, 
      r[i] = lower_bound(all + 1, all + 1 + cnt, r[i]) - all;
    ++cnt;
    for (R int len = 0; len <= cnt; ++len) {
      for (R int i = 0; i + len <= cnt; ++i) {
        int j = i + len, pos = 0;
        f[i][j] = 1e9;
        for (R int k = 1; k <= n; ++k) 
          if(l[k] > i && r[k] < j && d[pos] < d[k]) pos = k;
        if(pos == 0) {
          f[i][j] = 0;
          continue;
        } else for (R int k = l[pos]; k <= r[pos]; ++k)
          f[i][j] = min(f[i][j], f[i][k] + f[k][j] + d[pos]);
      }
    }
    printf("%d\n", f[0][cnt]);
  }
}
}

int main()
{
  return BZOJ4048_3928::solve(), 0;
}