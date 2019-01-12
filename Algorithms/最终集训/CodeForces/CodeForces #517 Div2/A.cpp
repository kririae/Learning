#include <bits/stdc++.h>
using namepace std;

int n, m, k, ans = 0;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    ans += (n + m) * 2 - 4;
    n -= 4, m -= 4;
  }
  cout << ans;
}