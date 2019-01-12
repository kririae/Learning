#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;
int t, n, m, f[1005][20005];
inline void Add(int i, int l, int r, ll x) {
  ++l, ++r;  // 防止为0
  l = min(l, 20001), r = min(r, 20001);
  for (; l <= 20001; l += l & -l) f[i][l] = (1ll * f[i][l] + x) % MOD;
  for (++r; r <= 20001; r += r & -r) f[i][r] = ((1ll * f[i][r] - x) % MOD + MOD) % MOD;
}
inline int Query(int i, int p) {
  int ans = 0;
  ++p;
  for (; p; p -= p & -p) ans = (1ll * ans + f[i][p]) % MOD;
  return ans;
}
int main() {
  Add(1, 0, 0, 1);
  for (int i = 1; i < 1000; ++i)
    for (int j = 0; j <= 20000; ++j)
      Add(i + 1, j, j + i, Query(i, j));
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    printf("%d\n", Query(n, m));
  }
}