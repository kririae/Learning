#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, MOD = 5000011;
int n, k, f[N], s[N];
// f[i]表示第$i$只是牝牛的情况
int main() {
  scanf("%d%d", &n, &k);
  f[0] = 1, s[0] = f[0];
  for (int i = 1; i <= n; ++i) {
    if (i > k)
      f[i] = (f[i] + s[i - k - 1]) % MOD;
    else
      f[i] = 1;
    s[i] = (s[i - 1] + f[i]) % MOD;
  }
  cout << s[n];
}