#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e7 + 5;
ll n, a, b, c, d, pre, cnt1, cnt2;
int main() {
  scanf("%lld%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d, &pre);
  a %= d, b %= d, c %= d;
  for (int i = 1; i <= n; ++i) {
    pre = (a * pre % d * pre % d + b * pre % d + c % d) % d;
    if (__builtin_popcount(pre) & 1)
      ++cnt1;
    else
      ++cnt2;
  }
  printf("%lld", 1ll * cnt1 * cnt2);
}