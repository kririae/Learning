#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, s, cnt, head[N], in[N], ver[N << 1], nxt[N << 1], tot;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  ++in[u], ++in[v];
  head[u] = tot++;
}
inline void dfs(int x, int fa) {
  int fg = 0;
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != fa)
      fg = 1, dfs(to, x);
  cnt += fg == 0 ? 1 : 0;
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d%d", &n, &s);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  dfs(1, 0);
  if (in[1] == 2) ++cnt;
  double l = 0, r = s, mid;
  while (r - l >= 1e-7) {
    mid = (l + r) / 2;
    if (s - (cnt - 1) * (mid / 2) <= (mid / 2)) r = mid;
    else l = mid;
  }
  printf("%.8lf", l);
}