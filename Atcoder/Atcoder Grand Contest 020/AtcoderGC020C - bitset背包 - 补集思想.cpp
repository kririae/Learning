/*
证明稍微有点蒙蔽
首先bitset跑背包基本都没问题
但是，问题在于，如何快速取出中位数
这道题这个思路很值得总结
关于中位数，现在我还只有查rank和二分，对顶堆的姿势
但是，这道题，涉及一个补集的骚操作
对于一个子集的和为i，必定存在一个补集的和为S - i
于是，可以得到性质
对于和为$sum / 2$的子集，有2^{n - 1} - 1个集合比它小
于是...
 */
#define R register
#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 2e6 + 5;
 
int n, val, sum;
bitset<maxn> f;
 
int main()
{
  scanf("%d", &n);
  f[0] = 1;
  for (R int i = 1; i <= n; ++i) scanf("%d", &val), f |= (f << val), sum += val;
  if(n == 1) return printf("%d", sum), 0;
  for (R int i = (sum >> 1); i; --i) if(f[i]) return printf("%d", sum - i), 0;
}