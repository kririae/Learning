#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
struct D {
  int x, id;
  bool operator<(const D &d) const { return x < d.x; }
} a[N];
int n, b[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].x);
    a[i].id = i;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) {
    b[i] = a[i].x + (a[i].id - i);
    if (b[i] < b[i - 1])
      goto fail;
  }
fail:
  puts(":(") for (int i = 1; i <= n; ++i)
      printf("%d ", b[i]);
}