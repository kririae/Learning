#include <bits/stdc++.h>
using namespace std;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i)
    f[a[i]] = f[a[i] - 1] + 1, ans = max(ans, f[a[i]]);
  printf("%d", n - ans);
}