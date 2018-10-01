#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 5, M = 1e9 + 7;
ll n, prm[N], vis[N], cnt[N], tot, ans = 1;
int main() {
  scanf("%lld", &n);
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) prm[++tot] = i, vis[i] = i;
    for (int j = 1; j <= tot; ++j) {
      if (1ll * i * prm[j] > n) break;
      vis[i * prm[j]] = prm[j];
      if (i % prm[j] == 0) break;
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = i; j != 1; j /= vis[j]) 
      ++cnt[vis[j]];
  for (int i = 1; i <= n; ++i)
    (ans *= (cnt[i] << 1) + 1) %= M;
  cout << ans << endl;
}