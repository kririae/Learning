#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int w, b; double f[N][N];
int main() {
  scanf("%d%d", &w, &b);
  for (int i = 1; i <= w; ++i)
    f[i][0] = 1;
  for (int i = 1; i <= w; ++i)
    for (int j = 1; j <= b; ++j) {
      f[i][j] = (i * 1.0) / (i + j);
      if (j >= 3)
        f[i][j] += ((j * 1.0) / (i + j)) * ((j - 1.0) / (i + j - 1)) * ((j - 2.0) / (i + j - 2)) * f[i][j - 3];
      if (j >= 2)
        f[i][j] += ((j * 1.0) / (i + j)) * ((j - 1.0) / (i + j - 1)) * (i * 1.0 / (i + j - 2)) * f[i - 1][j - 2];
    }
  printf("%.9lf", f[w][b]);
}