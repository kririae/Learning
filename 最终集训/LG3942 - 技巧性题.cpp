#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k, t, head[N], ver[N << 1], nxt[N << 1], tot;
int f[N], use;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs(int x, int fa) {
  int t = 0;
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != fa) {
      dfs(to, x);
      if (f[to] + 1 >= 0)
        f[x] = max(f[x], f[to] + 1);
      else
        t = min(t, f[to] + 1);
    }
  if (f[x] + t < 0)
    f[x] = t;
  else if (f[x] >= k)
    ++use, f[x] = -k - 1;
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d%d", &n, &k, &t);
  for (int i = 1, x, y; i < n; ++i) {
    scanf("%d%d", &x, &y);
    addedge(x, y);
    addedge(y, x);
  }
  dfs(1, 0);
  if (f[1] >= 0) ++use;
  cout << use;
}