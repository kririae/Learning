#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, fa[N], f[N], g[N];
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i < n; ++i) {
    scanf("%d", &x);
    fa[i] = x;
  }
  int ans = 0;
  for (int i = n; i >= 1; --i) {
    if (f[i] + 1 >= 0)
      f[fa[i]] = max(f[fa[i]], f[i] + 1);
    else g[fa[i]] = min(g[fa[i]], f[i] + 1);
    if (f[x] + g[x] < 0)
      f[x] = g[x];
    else if (f[x] >= 2)
      f[x] = -3, ++ans;
  }
  cout << ans;
}