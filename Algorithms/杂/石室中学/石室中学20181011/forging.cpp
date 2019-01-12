#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e7 + 5, MOD = 998244353;
int n, a, bx, by, cx, cy, p;
int f[N], c[N], b[N], inv[N];
int main() {
  scanf("%d%d%d%d%d%d%d", &n, &a, &bx, &by, &cx, &cy, &p);
  f[0] = a;
  b[0] = by + 1;
  c[0] = cy + 1;
  for (register int i = 1; i < n; i++) {
    b[i] = ((ll)b[i - 1] * bx + by) % p + 1;
    c[i] = ((ll)c[i - 1] * cx + cy) % p + 1;
  }
  inv[1] = 1;
  for (register int i = 2; i < N; ++i)
    inv[i] = 1ll * (MOD - MOD / i) * inv[MOD % i] % MOD;
  f[1] = (1LL * c[0] * inv[min(b[0], c[0])] % MOD + 1) * a % MOD;
  for (register int i = 2; i <= n; ++i)
    f[i] = (1ll * c[i - 1] * inv[min(c[i - 1], b[i - 2])] % MOD * f[i - 1] + f[i - 2]) % FMOD;
  printf("%d", f[n]);
}