#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 50005;
int n, m, head[N], ver[N << 2], nxt[N << 2], tot, vis[N];
ll a[65], edge[N << 2], dis[N];
inline void Addedge(int u, int v, ll w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void Insert(ll x) {
  for (int i = 60; i >= 0; --i)
    if ((x >> i) & 1) {
      if (a[i] == 0) {
        a[i] = x;
        break;
      }
      x ^= a[i];
    }
}
inline ll Query(ll x) {
  for (int i = 60; i >= 0; --i)
    x = max(x, x ^ a[i]);
  return x;
}
inline void Dfs(int x) {
  vis[x] = 1;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    to = ver[i];
    if (vis[to]) Insert(dis[x] ^ dis[to] ^ edge[i]);
    else dis[to] = dis[x] ^ edge[i], Dfs(to);
  }
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d", &n, &m);
  int s, t; ll d;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%lld", &s, &t, &d);
    Addedge(s, t, d);
    Addedge(t, s, d);
  }
  Dfs(1);
  printf("%lld", Query(dis[n]));
}