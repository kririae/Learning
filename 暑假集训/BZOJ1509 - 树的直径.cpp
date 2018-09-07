#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m, x, y, head[N], tmp, 
ver[N << 1], nxt[N << 1];
ll dis[N], dis1[N], dis2[N], edge[N << 1], tot, ans, d;
inline void addedge(int u, int v, ll w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs(int x, ll *dis) {
  static queue<int> q;
  static bitset<N> vis;
  memset(dis, 0x3f, 8 * N);
  vis.reset();
  q.push(x);
  vis[x] = 1;
  dis[x] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; ~i; i = nxt[i]) {
      int to = ver[i];
      if (dis[to] > dis[u] + edge[i]) {
        dis[to] = dis[u] + edge[i];
        if (!vis[to])
          vis[to] = 1,
          q.push(to);
      }
    }
  }
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    ll u, v, w;
    scanf("%lld%lld%lld", &u, &v, &w);
    addedge(u, v, w);
    addedge(v, u, w);
  }
  dfs(1, dis);
  for (int i = x = 1; i <= n; ++i)
    if (dis[i] > dis[x]) x = i;
  dfs(x, dis1);
  for (int i = y = 1; i <= n; ++i)
    if (dis1[i] > dis1[y]) y = i;
  dfs(y, dis2);
  dis1[x] = 0, dis2[y] = 0;
  for (int i = 1; i <= n; ++i)
      ans = max(ans, min(dis1[i], dis2[i]));
  cout << ans + dis1[y] << endl;
}