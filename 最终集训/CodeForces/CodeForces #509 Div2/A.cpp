#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int N = 1005;
int n, a[N];
int main() {
  scanf("%d", &n);
  int x = -inf, y = inf;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    x = max(x, a[i]);
    y = min(y, a[i]);
  }
  printf("%d", x - y - n + 1);
}