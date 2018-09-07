#include <bits/stdc++.h>
using namespace std;

const int N = 1000005, M = 10005;
int n, head[M], nxt[N << 1], 
ver[N << 1], tot, cnt = 1, 
vis[N << 1], t[N << 1], ans;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline bool dfs(int x) {
  for (int i = head[x], to; ~i; i = nxt[i])
    if (vis[to = ver[i]] != cnt) {
      vis[to] = cnt;
      if (!t[to] || dfs(t[to]))
        return t[to] = x, true;
    }
  return false;
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  for (int i = 1, a, b; i <= n; ++i) {
    scanf("%d%d", &a, &b);
    addedge(a, i);
    addedge(b, i);
  }
  for (int i = 1; i <= n; ++i, ++cnt)
    if (dfs(i)) ++ans;
    else break;
  cout << ans << endl;
}