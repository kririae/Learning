#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, p, k, head[N], nxt[N * 20], 
ver[N * 20], edge[N * 20], tot;
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline int SPFA(int x) {
  static queue<int> q;
  static bitset<N> vis;
  static int dis[N];
  while (!q.empty()) q.pop();
  vis.reset();
  memset(dis, 0x3f, sizeof dis);
  dis[1] = 0;
  q.push(1);
  vis[1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; ~i; i = nxt[i]) {
      int to = ver[i];
      if (dis[u] + (edge[i] > x) < dis[to]) {
        dis[to] = dis[u] + (edge[i] > x);
        if (!vis[to])
          vis[to] = 1,
          q.push(to);
      }
    }
  }
  return dis[n];
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d%d", &n, &p, &k);
  for (int i = 1, a, b, c; i <= p; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    addedge(a, b, c);
    addedge(b, a, c);
  }
  int l = -1, r = 1000000, ans = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    if (SPFA(mid) <= k) ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  cout << ans << endl;
}