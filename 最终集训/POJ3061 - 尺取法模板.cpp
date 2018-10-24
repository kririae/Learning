#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;

const int N = 100005;
int t, n, b, a[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &b);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &a[i]);
    int l = 0, r = 1, ans = 1e9;
    ll s = 0;
    for (; r <= n; ++r) {
      s += a[r];
      if (s < b) continue;
      while (l < r && s - a[l] >= b)
        s -= a[l++];
      ans = min(ans, r - l + 1);
    }
    cout << (ans > n ? 0 : ans) << endl;
  }
}