#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 10005;
int n, k, head[N], ver[N << 1], nxt[N << 1], edge[N << 1], siz[N], tot;
ll ans = 0, dis[N], a[N];
int root, cnt, sum, vis[N], ms[N];
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  nxt[tot] = head[u];
  edge[tot] = w;
  head[u] = tot++;
}
inline void getroot(int x, int fa) {
  siz[x] = 1, ms[x] = 0;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if ((to = ver[i]) == fa || vis[to])
      continue;
    getroot(to, x);
    siz[x] += siz[to];
    ms[x] = max(ms[x], siz[to]);
  }
  ms[x] = max(ms[x], sum - siz[x]);
  if (ms[x] < ms[root])
    root = x;
}
inline void init(int x, int fa) {
  a[++cnt] = dis[x];
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if ((to = ver[i]) == fa || vis[to]) 
      continue;
    dis[to] = dis[x] + edge[i];
    init(to, x);
  }
}
inline int calc(int x, int y) {
  cnt = 0, dis[x] = 0;
  init(x, 0);
  sort(a + 1, a + 1 + cnt);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int l = i, r = cnt;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (a[mid] >= k - a[i] - y)
        r = mid;
      else l = mid + 1;
    }
    ans += (r - i);
  }
  return ans;
}
inline void solve(int x) {
  ans += calc(x, 0);
  vis[x] = 1;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if (vis[to = ver[i]])
      continue;
    ans -= calc(to, edge[i]);
    sum = siz[to], root = 0;
    getroot(to, -1);
    solve(root);
  }
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d", &n, &k);
  for (int i = 1, s, t, w; i < n; ++i) {
    scanf("%d%d%d", &s, &t, &w);
    addedge(s, t, w);
    addedge(t, s, w);
  }
  root = 0, sum = ms[0] = n;
  getroot(1, 0);
  solve(root);
  printf("%lld\n", ans);
}