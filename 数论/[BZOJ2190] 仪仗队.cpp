/*
lyd太水了啊！！！
我们这么考虑
对于一个点(x, y)
他的爸爸(kx, ky)一定不能被看到。
那么对于一个点(x, y), gcd(x, y) == 1
gcd(kx, ky) = k，肯定不行啦~
对于一个点，gcd(x, y) = b
那么一定存在点(x / b, y / b)可以被看到
所以，被看到的一定是坐标互质的~
所以，就是要统计x \in (1..n), y \in (1..n)且gcd(x, y) == 1的个数
然后，forforfor肯定不行啦~这么吧，用phi啊！互质的个数嘛~
然后结果是3 + \sum_{i = 2}^{n}{phi[i]}
 */
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 40005;

ll n, prm[maxn], cnt, phi[maxn], ans;
bitset<maxn> vis;

int main()
{
  scanf("%lld", &n);
  phi[1] = 1;
  for (R int i = 2; i <= n; ++i)
  {
    if(!vis[i])
      prm[++cnt] = i, phi[i] = i - 1;
    for (R int j = 1; j <= cnt; ++j)
    {
      if(i * prm[j] > n) break;
      vis[i * prm[j]] = 1;
      if(i % prm[j] == 0)
      {
        phi[i * prm[j]] = phi[i] * prm[j];
        break;
      } else phi[i * prm[j]] = phi[i] * phi[prm[j]];
    }
  }
  for (R int i = 2; i < n; ++i)
    ans += (phi[i] << 1);
  printf("%lld", ans == 0 ? ans : ans + 3);
}