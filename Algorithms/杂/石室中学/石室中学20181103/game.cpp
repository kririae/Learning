#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, head[N], ver[N << 1], nxt[N << 1], tot, in[N], vis[N];
queue<int> q;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
int main() {
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  memset(head, -1, sizeof head);
  scanf("%d", &n);
  for (int i = 1, s; i <= n; ++i) {
    scanf("%d", &s);
    for (int j = 1, x; j <= s; ++j) {
      scanf("%d", &x);
      addedge(x, i);
      ++in[i];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (in[i] == 0) q.push(i), vis[i] = 1, ++ans;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; ~i; i = nxt[i]) {
      int to = ver[i];
      if (vis[to] == 1) continue;
      if ((--in[to]) == 0)
        q.push(to), vis[to] = 1, ++ans;
    }
  }
  cout << ans;
}