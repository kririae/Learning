#include <bits/stdc++.h>
using namespace std;

int t, f, n, m, a, b, c;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
    f = c % (n - 2) + 2;
    if (f == 2 && m == 1)
      puts("-1");
    else if ((m & 1) == 0)
      printf("%d\n", (n - 1) + (m) / 2);
    else
      printf("%d\n", (n - 1) + (m) / 2 + 1);
  }
}