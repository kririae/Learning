#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
如果$gcd(r, c) = 1$，那么整个图中不会穿过任意一个点，即箭的路径全都穿过了方块。可以得到，对于$r \times c$的矩形，穿过的方块的个数是$r + c - 1 - a$，$a$是穿过的点的个数。初始点和结束点自然不用计算。可以得到，穿过的点的个数是$gcd(r, c) - 1$。所以对于$r \times c$的矩形，穿过的点的个数就是$x = r + c - gcd(r, c)$。即求$a + b - gcd(a, b) = n$的$(a, b)$的对数。$n = gcd(a, b) * t_1 + gcd(a, b) * t_2 - gcd(a, b)$。$n = gcd(a, b) \cdot (t_1 + t_2 - 1)$。$\frac{n}{gcd(a, b)} = (t_1 + t_2 - 1)$。$t_1, t_2$是整数，所以$gcd(a, b)$一定是$n$的约数。考虑枚举$gcd(a, b) | n$，快速求出$t_1 + t_2 - 1 = \frac{n}{gcd(a, b)}$，$gcd(t_1, t_2) = 1$的个数。又$gcd(a, b) = gcd(b, a - b)$。则$gcd(a + b, a) = gcd(a, b)$。$\frac{n}{gcd(a, b)} + 1 - t_2 = t_1$ $\rightarrow$$gcd(\frac{n}{gcd(a, b)} + 1, t_2) = gcd(t_1, t_2)$。即$\sum_{i|n}{\varphi{(i + 1)}}$。
 */
const int N = 1000005;
int n, prm[N], phi[N], vis[N], cnt;
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n + 1; ++i) {
    if (!vis[i]) prm[++cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= cnt; ++j) {
      if (i * prm[j] > n + 1) break;
      vis[i * prm[j]] = 1;
      if (i % prm[j] == 0) {
        phi[i * prm[j]] = phi[i] * prm[j];
        break;
      } else phi[i * prm[j]] = phi[i] * phi[prm[j]];
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i)
    if (n % i == 0) ans += phi[i + 1];
  cout << ans / 2 + 1 << endl;
}