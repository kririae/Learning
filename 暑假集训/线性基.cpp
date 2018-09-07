#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5;
ll n, mx, t, ans, s[N], a[N];
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) 
    scanf("%lld", &s[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = 51; j >= 0; --j)
      if(s[i] & (1ll << j)) {
        if(a[j] == 0) {
          a[j] = s[i];
          break;
        }
        s[i] ^= a[j];
      }
  for (int i = 51; i >= 0; --i) 
    ans = max(ans, ans ^ a[i]);
  printf("%lld", ans);
}