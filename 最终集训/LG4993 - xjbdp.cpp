#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1005, M = 40005, MOD = 998244353;
int n, h[N], g[M];
ll f[N][M];
// 以i结尾，公差为j的等差数列有多少个(j可能为负)
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &h[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      (f[j][h[j] - h[i] + 20000] += f[i][h[j] - h[i] + 20000] + 1) %= MOD;
  ll ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < M; ++j)
      (ans += f[i][j]) %= MOD;
  cout << (ans + n) % MOD;
}