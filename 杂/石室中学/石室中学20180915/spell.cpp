#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, f[N];
int main() {
  freopen("spell.in", "r", stdin);
  freopen("spell.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < N; ++i) f[i] = -1e9;
  f[0] = 0;
  for (int i = 1, l, d; i <= n; ++i) {
    scanf("%d%d", &l, &d);
    for (int j = n; j >= l; --j)
      if (f[j - l] != -1e9) f[j] = max(f[j], f[j - l] + d);
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    ans = max(ans, f[i]);
  cout << ans;
}