#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
  freopen("milk.in", "r", stdin);
  freopen("milk.out", "w", stdout);
  scanf("%d", &n);
  if (n % 2 == 1) {
    puts("-1");
    return 0;
  }
  printf("%d\n", 2);
  printf("%d ", n);
  for (int i = 1; i < n; ++i) {
    if (i & 1)
      printf("%d ", i);
    else
      printf("%d ", n - i);
  }
  puts("");
  printf("%d ", n);
  for (int i = 1; i < n; ++i) {
    if (i & 1)
      printf("%d ", n - i);
    else
      printf("%d ", i);
  }
}
