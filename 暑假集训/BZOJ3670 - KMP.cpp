#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1000005;
int t, n, f[N], num[N]; ll ans = 1; char a[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(num, 0, sizeof(num));
    memset(f, 0, sizeof(f));
    ans = 1;
    scanf("%s", a);
    n = strlen(a);
    num[1] = 1;
    for (int i = 1, j = 0; i < n; ++i) {
      while(j && a[i] != a[j]) j = f[j];
      f[i + 1] = a[i] == a[j] ? ++j : 0;
      num[i + 1] = num[j] + 1;
    }
    for (int i = 1, j = 0; i < n; ++i) {
      while (j && a[i] != a[j]) j = f[j];
      if (a[i] == a[j]) ++j;
      while ((j << 1) > i + 1) j = f[j];
      (ans *= (num[j] + 1)) %= (int)(1e9 + 7);
    }
    cout << ans << endl;
  }
}