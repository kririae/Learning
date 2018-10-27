#include <bits/stdc++.h>
using namespace std;
const int tx[5] = {1, -1, 0, 0},
          ty[5] = {0, 0, 1, -1};
const int N = 1005;
int n, k, a[N][N], b[N][N], vis[N][N];
// 榛?鐧?
inline bool check(int x, int y, int col) {
  int ret = 1;
  vis[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int tox = x + tx[i], toy = y + ty[i];
    if (a[tox][toy] == -1) return false;
    if (a[tox][toy] == col && vis[tox][toy] == 0)
      ret &= check(tox, toy, col);
  }
  return ret;
}
inline void eat(int x, int y, int fg) {
  vis[x][y] = 0;
  if (fg) a[x][y] = -1;
  for (int i = 0; i < 4; ++i) {
    int tox = x + tx[i], toy = y + ty[i];
    if (vis[tox][toy] == 1)
      eat(tox, toy, fg);
  }
}
inline int work(int x, int y, int col) {
  if (a[x][y] != -1) {
    puts("illegal");
    exit(0);
  }
  a[x][y] = col;
  for (int i = 0, r; i < 4; ++i) {
    int tox = x + tx[i], toy = y + ty[i];
    if (a[tox][toy] == (col ^ 1)) {
      int r = check(tox, toy, col ^ 1);
      eat(tox, toy, r);
    }
  }
  if (check(x, y, col)) {
    puts("illegal");
    exit(0);
  }
  // check x
  eat(x, y, 0);
  int cnt = 1, t = y;
  while (t + 1 <= n && a[x][t + 1] == col) ++t, ++cnt;
  t = y;
  while (t - 1 >= 1 && a[x][t - 1] == col) --t, ++cnt;
  if (cnt >= k)
    return 1;
  cnt = 1, t = x;
  while (t + 1 <= n && a[t + 1][y] == col) ++t, ++cnt;
  t = x;
  while (t - 1 >= 1 && a[t - 1][y] == col) --t, ++cnt;
  if (cnt >= k)
    return 1;
  cnt = 1;
  int tx = x, ty = y;
  while (tx - 1 >= 1 && tx - 1 <= n && ty - 1 >= 1 && ty - 1 <= n && a[tx - 1][ty - 1] == col)
    --tx, --ty, ++cnt;
  tx = x, ty = y;
  while (tx + 1 >= 1 && tx + 1 <= n && ty + 1 >= 1 && ty + 1 <= n && a[tx + 1][ty + 1] == col)
    ++tx, ++ty, ++cnt;
  if (cnt >= k)
    return 1;
  cnt = 1, tx = x, ty = y;
  while (tx + 1 >= 1 && tx + 1 <= n && ty - 1 >= 1 && ty - 1 <= n && a[tx + 1][ty - 1] == col)
    ++tx, --ty, ++cnt;
  tx = x, ty = y;
  while (tx - 1 >= 1 && tx - 1 <= n && ty + 1 >= 1 && ty + 1 <= n && a[tx - 1][ty + 1] == col)
    --tx, ++ty, ++cnt;
  if (cnt >= k)
    return 1;
  return 0;
}
int main() {
  memset(a, -1, sizeof a);
  scanf("%d%d", &n, &k);
  for (int i = 1, x, y; i <= n; ++i) {
    scanf("%d%d", &x, &y);
    int r = work(x, y, i & 1);
    if (r == 1)
      if (i & 1) {
        printf("ITer %d\n", i);
        return 0;
      } else {
        printf("Kitty %d\n", i);
        return 0;
      }
  }
  puts("draw");
}
