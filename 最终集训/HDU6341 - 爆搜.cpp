#include <bits/stdc++.h>
#define ll long long
using namespace std;

int ans, a[20][20]; char s[20];
inline void rotate(int x, int y) {
  static int tmp[20][20];
  x *= 4, y *= 4, x -= 3, y -= 3;
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      tmp[x + j][y + 4 - i - 1] = a[x + i][y + j];
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      a[x + i][y + j] = tmp[x + i][y + j];
}
inline bool check(int x, int y) {
  static bitset<50> vis;
  for (int i = x * 4 - 3; i <= x * 4; ++i) {
    vis.reset();
    for (int j = 1; j <= y * 4; ++j)
      if(vis[a[i][j]]) return false; 
      else vis[a[i][j]] = 1;
  }
  for (int j = y * 4 - 3; j <= y * 4; ++j) {
    vis.reset();
    for (int i = 1; i <= x * 4; ++i)
      if(vis[a[i][j]]) return false; 
      else vis[a[i][j]] = 1;
  }
  return true;
}
inline void dfs(int x, int y, int res) {
  if(res >= ans) return;
  if(x == 5) return ans = res, void();
  int to_x = x, to_y = y + 1;
  if(to_y == 5) to_y = 1, ++to_x;
  for (int i = 0; i < 4; ++i) {
    if(i) rotate(x, y);
    if(check(x, y))
      dfs(to_x, to_y, res + i);
  }
  rotate(x, y);
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    ans = 1e9;
    for (int i = 1; i <= 16; ++i) {
      scanf("%s", s + 1);
      for (int j = 1; j <= 16; ++j)
        if(s[j] >= 'A' && s[j] <= 'Z') a[i][j] = s[j] - 'A' + 10;
        else a[i][j] = s[j] - '0';
    }
    dfs(1, 1, 0);
    printf("%d\n", ans);
  }
}