#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int n, a[N][N], x, y;
int main() {
  a[1][n / 2] = 1;
  x = 1, y = (n + 1) / 2;
  for (int i = 2; i <= n * n; ++i) {
    if (x == 1 && y != n)
      a[x = n][++y] = i;
    if (y == n && x != 1)
      a[--x][y = 1] = i;
    if (x == 1 && y == n)
      a[++x][y] = i;
    if (x != 1 && y != n)
      if (a[x - 1][y + 1] == 0)
        a[--x][++y] = i;
      else
        a[++x][y] = i;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      printf("%d ", a[i][j]);
    puts("");
  }
}