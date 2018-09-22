#include <bits/stdc++.h>
using namespace std;

const int N = 505;
struct Seg {
  int id, min, max;
} h[N], l[N];
int n, cnt = 1, cnt1, cnt2, a[N][N], to[N], vis[N];
inline bool inter(Seg &a, Seg &b) {
  if (a.id < b.min || 
      a.id > b.max || 
      b.id < a.min || 
      b.id > a.max) return false;
  return true;
}
inline bool dfs(int x) {
  for (int i = 1; i <= cnt2; ++i)
    if (a[x][i] && vis[i] != cnt) {
      vis[i] = cnt;
      if (!to[i] || dfs(to[i]))
        return to[i] = x, true;
    }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x1, y1, x2, y2; i <= n; ++i) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 == x2) {
      h[++cnt1].id = x1;
      h[cnt1].min = min(y1, y2);
      h[cnt1].max = max(y1, y2);
    } else {
      l[++cnt2].id = y1;
      l[cnt2].min = min(x1, x2);
      l[cnt2].max = max(x1, x2);
    }
  }
  for (int i = 1; i <= cnt1; ++i)
    for (int j = 1; j <= cnt2; ++j)
      if (inter(h[i], l[j]))
        a[i][j] = 1;
  int ans = 0;
  for (int i = 1; i <= cnt1; ++i, ++cnt)
    ans += dfs(i);
  cout << n - ans << endl;
}