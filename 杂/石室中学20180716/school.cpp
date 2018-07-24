#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 3000005, mod = 1000000007;

ll n, f[maxn], inv[maxn];

int main()
{
  freopen("school.in", "r", stdin);
  freopen("school.out", "w", stdout);
  scanf("%lld", &n);
  f[0] = 1, inv[1] = 1;
  for (R int i = 2; i <= n; ++i)
    inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
  for (R int i = 1; i <= n; ++i)
    f[i] = ((f[i - 1] * (4 * i - 2)) % mod * inv[i + 1]) % mod;
  printf("%lld", f[n - 1]);
}
