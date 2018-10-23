#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N], b[N], f[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) scanf("%d", &b[i]);
  for (int i = 0; i <= 3; ++i) {
    // 枚举第一个
    int fg = 0;
    memset(f, 0, sizeof f);
    f[n] = i;
    for (int j = n - 1; j >= 1; --j) {
      int flag = 0;
      for (int k = 0; k <= 3; ++k) {
        f[j] = k;
        if ((k & f[j + 1]) == a[j] && (k | f[j + 1]) == b[j]) {
          flag = 1;
          break;
        }
      }
      if (!flag) fg = 1;
    }
    if (!fg) {
      puts("YES");
      for (int i = 1; i <= n; ++i)
        cout << f[i] << " ";
      return 0;
    }
  }
  puts("NO");
  return 0;
}