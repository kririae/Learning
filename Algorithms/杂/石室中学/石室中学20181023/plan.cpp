#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N], b[N], t0[N], t[2][N];
int main() {
  memset(t, -1, sizeof t);
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) scanf("%d", &b[i]);
  for (int i = 0; i <= 1; ++i) {
    for (int j = 1; j < n; ++j) {
      int x = (a[j] >> i) & 1,
          y = (b[j] >> i) & 1;
      cout << x << " " << y << endl;
      if (x == 1) {
        if (y == 0) {
          if (t[i][j] == 0) t[i][j + 1] = 1;
          t[i][j] = 1;
          t[i][j + 1] = 0;
          continue;
        } else {
          if (t[i][j] == 0) goto fail;
          t[i][j] = t[i][j + 1] = 1;
          continue;
        }
      } else {
        // x == 0
        if (y == 0) {
          if (t[i][j] == 1) goto fail;
          t[i][j] = t[i][j + 1] = 0;
          continue;
        } else goto fail;
      }
    }
  }
  puts("YES");
  for (int i = 1; i <= n; ++i)
    cout << t[0][i] << " ";
  cout << endl;
  for (int i = 1; i <= n; ++i)
    cout << t[1][i] << " ";
  return 0;
  fail:
    puts("NO");
  return 0;
}
