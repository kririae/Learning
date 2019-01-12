#include <bits/stdc++.h>
using namespace std;

int n, s, mx;
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    s += x;
    mx = max(mx, x);
  }
  cout << max(ceil((1.0 * (s << 1) + 1) / n), 1.0 * mx);
}