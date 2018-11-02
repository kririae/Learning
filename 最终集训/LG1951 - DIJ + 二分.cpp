#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 10005, M = 50005;
int n, m, u, v, head[N],
    ver[M << 1], nxt[M << 1], tot, vis[N];
ll dis[N], edge[M << 1], f[N], s;
inline void addedge(int u, int v, ll w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline ll judge(ll x) {
  static priority_queue<pair<int, int> > q;
  while (!q.empty()) q.pop();
  memset(dis, 0x3f, sizeof dis);
  memset(vis, 0, sizeof vis);
  q.push(make_pair(0, u));
  dis[u] = 0;
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u], to; ~i; i = nxt[i])
      if (dis[to = ver[i]] > dis[u] + edge[i] && f[to] <= x) {
        dis[to] = dis[u] + edge[i];
        q.push(make_pair(-dis[to], to));
      }
  }
  return dis[v];
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d%d%d%lld", &n, &m, &u, &v, &s);
  ll l = 0, r = 0;
  for (int i = 1; i <= n; ++i) scanf("%lld", &f[i]), r = max(r, f[i]);
  for (int i = 1, u, v; i <= m; ++i) {
    ll w;
    scanf("%d%d%lld", &u, &v, &w);
    addedge(u, v, w);
    addedge(v, u, w);
  }
  ll ans = -1;
  ++r;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (judge(mid) <= s && f[u] <= mid && f[v] <= mid)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans;
}