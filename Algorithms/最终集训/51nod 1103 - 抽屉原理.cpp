#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
int n, a[N], s[N], mp[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    s[i] = (1ll * s[i - 1] + a[i]) % n;
    if (s[i] == 0) {
      printf("%d\n", i);
      for (int j = 1; j <= i; ++j)
        printf("%d\n", a[j]);
      return 0;
    } else {
      if (mp[s[i]]) {
        printf("%d\n", i - mp[s[i]]);
        for (int j = mp[s[i]] + 1; j <= i; ++j)
          printf("%d\n", a[j]);
        return 0;
      } else
        mp[s[i]] = i;
    }
  }
}