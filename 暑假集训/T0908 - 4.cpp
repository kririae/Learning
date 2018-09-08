#include <bits/stdc++.h>
using namespace std;

const int N = 30;
char s[N];
int n, m, a[N][N], g[N * N][N * N], del[N * N][N * N];
int vis[N * N], to1[N * N], to2[N * N], cnt = 1, tot;
inline int calc(int x, int y) {
  return (x - 1) * m + y;
}
inline bool dfs(int x, int *to) {
  for (int i = 1; i <= calc(n, m); ++i)
    if (g[x][i] && vis[i] != cnt) {
      vis[i] = cnt;
      if (!to[i] || dfs(to[i], to))
        return to[i] = x, true;
    }
  return false;
}
inline int Match(int *to) {
  memset(vis, 0, sizeof vis);
  int ans = 0, cnt = 1;
  for (int i = 1; i <= calc(n, m); ++i, ++cnt)
    ans += dfs(i, to);
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    memset(s, 0, sizeof(s));
    scanf("%s", s + 1);
    for (int j = 1; j <= m; ++j)
      if (s[j] == '.') a[i][j] = 1, ++tot;
      else a[i][j] = 0;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 0) continue;
      if (a[i - 1][j]) g[calc(i, j)][calc(i - 1, j)] = 1;
      if (a[i][j - 1]) g[calc(i, j)][calc(i, j - 1)] = 1;
      if (a[i + 1][j]) g[calc(i, j)][calc(i + 1, j)] = 1;
      if (a[i][j + 1]) g[calc(i, j)][calc(i, j + 1)] = 1;
    }
//  for (int i = 1; i <= calc(n, m); ++i)
//      for (int j = 1; j <= calc(n, m); ++j)
//             if (g[i][j]) cout << i << " " << j << endl;
  int mt = Match(to1);
  if (mt != tot || tot % 2) return puts("No"), 0;
//  for (int i = 1; i <= calc(n, m); ++i) 
//      cout << to1[i] << " ";
  for (int i = 1; i <= calc(n, m); ++i) {
    if (to1[i]) {
      g[i][to1[i]] = g[to1[i]][i] = 0;
      memset(to2, 0, sizeof to2);
      memset(vis, 0, sizeof vis);
      if (Match(to2) == mt) return puts("No"), 0;
      g[i][to1[i]] = g[to1[i]][i] = 1;
    }
  }
  puts("Yes");
}