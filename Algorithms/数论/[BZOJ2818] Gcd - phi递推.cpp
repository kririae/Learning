// by kririae
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 1e7 + 5;
int n, prm[N], cnt; ll phi[N], ans = 0;
bitset<N> vis;
int main()
{
  scanf("%d", &n);
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if(!vis[i]) prm[++cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= cnt; ++j) {
      if(i * prm[j] > n) break;
      vis[i * prm[j]] = 1;
      if(i % prm[j] == 0) {
        phi[i * prm[j]] = phi[i] * prm[j];
        break;
      } phi[i * prm[j]] = phi[i] * (prm[j] - 1);
    }}
  for (int i = 1; i <= n; ++i) phi[i] = phi[i - 1] + phi[i];
  for (int i = 1; i <= cnt; ++i) ans += (phi[n / prm[i]] << 1) - 1;
  printf("%lld", ans);
}

/*
# GCD

球$1 \leq i, j \leq n$，满足$gcd(i, j)$为素数的对数。

$gcd(a, b) = 1$，所以$gcd(ap, bp) = p$。易得，$p ,ap, bp \leq n$，所以对于每个$p$，我们考虑$\sum_{i = 1}^{\lfloor\frac{n}{p}\rfloor}\sum_{j = 1}^{\lfloor\frac{n}{p}\rfloor}{[gcd(i, j) = 1]}$，也就是球对于一个$i$，和所有$\leq i$的数互质的$j$的个数。然后欧拉函数递推~。代码如下：
```cpp
// by kririae
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 1e7 + 5;
int n, prm[N], cnt; ll phi[N], ans = 0;
bitset<N> vis;
int main()
{
  scanf("%d", &n);
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if(!vis[i]) prm[++cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= cnt; ++j) {
      if(i * prm[j] > n) break;
      vis[i * prm[j]] = 1;
      if(i % prm[j] == 0) {
        phi[i * prm[j]] = phi[i] * prm[j];
        break;
      } phi[i * prm[j]] = phi[i] * (prm[j] - 1);
    }}
  for (int i = 1; i <= n; ++i) phi[i] = phi[i - 1] + phi[i];
  for (int i = 1; i <= cnt; ++i) ans += (phi[n / prm[i]] << 1) - 1;
  printf("%lld", ans);
}
```
 */