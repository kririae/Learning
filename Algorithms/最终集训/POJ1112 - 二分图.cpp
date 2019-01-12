#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int t, n, a[N][N], col[N], cnt1, cnt2, cnt, f[N][N], all, 
head[N], ver[N * N * 2], nxt[N * N * 2], tot;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void color(int x) {
  if (col[x] == 1) ++cnt1;
  else ++cnt2;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    to = ver[i];
    if (!col[to]) 
      col[to] = 3 - col[x],
      color(to);
    else if (col[x] == col[to])
      puts("No solution"), 
      exit(0);
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(a, 0, sizeof a);
    memset(col, 0, sizeof col);
    memset(head, 0, sizeof head);
    memset(nxt, 0, sizeof nxt);
    memset(f, 0, sizeof f);
    memset(head, -1, sizeof head);
    cnt = all = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) a[i][i] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1, to; j <= n; ++j) {
        scanf("%d", &to);
        if (to == 0) break;
        a[i][to] = 1;
      }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) 
            a[i][j] &= a[j][i];
    for (int i = 1; i <= n; ++i) 
      for (int j = 1; j <= n; ++j)
        if (a[i][j] == 0) addedge(i, j);
    f[0][0] = 1;
    // 到第i组，放在第一个team有j人。
    for (int i = 1; i <= n; ++i)
      if (!col[i]) {
        cnt1 = cnt2 = 0;
        col[i] = 1, color(i);
        all += cnt1;
        all += cnt2;
  //      cout << cnt1 << " " << cnt2 << endl;
        ++cnt;
        for (int j = cnt1; j < 105; ++j)
          f[i][j] |= f[i - 1][j - cnt1];
        for (int j = cnt2; j < 105; ++j)
          f[i][j] |= f[i - 1][j - cnt2];
      }
    int ans = 1e9;
    for (int i = 0; i < 105; ++i)
      if (f[cnt][i]) ans = min(ans, abs((all - i) - i));
    cout << ans << endl;
  }
}