#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int head1[N], nxt1[N * 10], ver1[N * 10],
  head2[N], nxt2[N * 10], ver2[N * 10],
  tot1, tot2;
int n, m, a[N], f[N], g[N];
inline void addedge1(int u, int v) {
  ver1[tot1] = v;
  nxt1[tot1] = head1[u];
  head1[u] = tot1++;
}
inline void addedge2(int u, int v) {
  ver2[tot2] = v;
  nxt2[tot2] = head2[u];
  head2[u] = tot2++;
}
inline void SPFA1() {
  static queue<int> q;
  static bitset<N> vis;
  while (!q.empty()) q.pop();
  memset(f, 0x3f, sizeof(f));
  f[1] = a[1];
  vis[1] = 1;
  q.push(1);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head1[u]; ~i; i = nxt1[i]) {
      int to = ver1[i];
      if (f[to] > min(f[u], a[to])) {
        f[to] = min(f[u], a[to]);
        if (!vis[to]) 
          q.push(to), 
          vis[to] = 1;
      }
    }
  }
}
inline void SPFA2() {
  static queue<int> q;
  static bitset<N> vis;
  while (!q.empty()) q.pop();
  g[n] = a[n];
  vis[n] = 1;
  q.push(n);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head2[u]; ~i; i = nxt2[i]) {
      int to = ver2[i];
      if (g[to] < max(g[u], a[to])) {
        g[to] = max(g[u], a[to]);
        if (!vis[to]) 
          q.push(to), 
          vis[to] = 1;
      }
    }
  }
}
int main() {
  memset(head1, -1, sizeof(head1));
  memset(head2, -1, sizeof(head2));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1, u, v, z; i <= m; ++i) {
    scanf("%d%d%d", &u, &v, &z);
    if (z == 1) addedge1(u, v), addedge2(v, u);
    else {
      addedge1(u, v);
      addedge1(v, u);
      addedge2(u, v);
      addedge2(v, u);
    }
  }
  SPFA1();
  SPFA2();
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans = max(ans, g[i] - f[i]);
  cout << ans << endl;
}