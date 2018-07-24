/*
太妙啦！！！
求助q234rty神犇后…
太妙啦！！！我再感叹一次！！！
本来是LR安利的题，但是当时以为是图论建模，一直没做。
但是这道题的确从图论建模好像要好思考一些。
这样吧，首先拆分题目。
我们知道了，$2^k$一定有鬼qwq，肯定要贪。
然后，这里有一个值得总结的，“处理任意多个数”。
这道题的处理方式是$f「i]「j]$表示在“处理结束后”，数$i$能否到达$j$。这样，就可以巧妙地绕开“处理仍以多个数”，而是一次性对数列中所有的某一个数值进行处理，喵喵喵~
然后是一个我半天没理解到的地方，如何贪心呢。
这道题的贪心策略如下，从高到低位枚举二进制位。
每一个对于表示$2^i$的第$i$个二进制位，我们用这一位表示对原数组进行一次$\%i$的操作之后的$f$数组。考虑这一位，因为二进制的性质，如果其所有后面的位都为1，依然不能满足$a$数组能够转化为$b$数组，那么当前位一定需要，那么我们就从高到底枚举位，假如说满足需要该位的条件，那么就$ans += (1ll << i)$。
 */
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

namespace ARC022C
{
int n, a「55], b「55];
ll f「55], ans;

inline void solve()
{
  scanf("%d", &n);
  for (int j = 0; j <= 50; ++j)
  {
    f「j] = 0, f「j] |= (1ll << j);
    for (int k = 1; k <= j; ++k)
      if(((1ll << 51) - 1) & (1ll << k)) f「j] |= f「j % k];
  }
  for (R int i = 1; i <= n; ++i) scanf("%d", &a「i]);
  for (R int i = 1; i <= n; ++i) scanf("%d", &b「i]);
  int flag = 1;
  for (R int j = 1; j <= n; ++j)
    if((f「a「j]] & (1ll << b「j])) == 0) flag = 0;
  if(flag == 0) return printf("%lld\n", -1ll), void();
  for (int i = 50; i; --i)
  {
    for (int j = 0; j <= 50; ++j)
    {
      f「j] = 0, f「j] |= (1ll << j);
      for (int k = 1; k <= j; ++k)
        if((ans + (1ll << i) - 1) & (1ll << k)) f「j] |= f「j % k];
    }
    int flag = 1;
    for (R int j = 1; j <= n; ++j)
      if((f「a「j]] & (1ll << b「j])) == 0) flag = 0;
    if(!flag) ans += (1ll << i);
  }
  printf("%lld\n", ans);
}
}

int main()
{
  return ARC022C::solve(), 0;
}