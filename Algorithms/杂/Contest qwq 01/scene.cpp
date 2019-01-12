#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100005;
int n, a[N], head[N], ver[N << 1],  
nxt[N << 1], edge[N << 1], tot, ans = 1e9, pos;
ll dis[N], siz[N];
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs1(int x, int fa) {
  siz[x] = a[x];
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if ((to = ver[i]) == fa) continue;
    dis[to] = dis[x] + edge[i];
    dfs1(to, x);
    siz[x] += siz[to];
  }
}
inline void dfs2(int x, int fa, ll c) {
  if (c < ans) 
    ans = c,
    pos = x;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if ((to = ver[i]) == fa) continue;
    dfs2(to, x, c + 1ll * (siz[1] - siz[to] * 2) * edge[i]);
  }
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1, u, v, w; i < n; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    addedge(u, v, w);
    addedge(v, u, w);
  }
  dfs1(1, 1);
  ll c = 0;
  for (int i = 1; i <= n; ++i)
    c += (1ll * dis[i] * a[i]);
  dfs2(1, 0, c);
  cout << pos << endl << ans << endl;
}