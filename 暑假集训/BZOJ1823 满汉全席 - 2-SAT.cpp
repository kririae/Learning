#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 1005;
int t, n, k, head[N << 1], ver[M << 2], 
nxt[M << 2], tot, bls, dfn[N << 1], 
low[N << 1], cnt, vis[N << 1], bel[N << 1], ans;
stack<int> s;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void tarjan(int x) {
  dfn[x] = low[x] = ++cnt;
  s.push(x);
  vis[x] = 1;
  for (int i = head[x]; ~i; i = nxt[i]) {
    int to = ver[i];
    if (!dfn[to]) {
      tarjan(to);
      low[x] = min(low[x], low[to]);
    } else 
    if (vis[to])
      low[x] = min(low[x], dfn[to]);
  }
  if (dfn[x] == low[x]) {
    int u; ++bls;
    do {
      u = s.top();
      s.pop();
      vis[u] = 0;
      bel[u] = bls;
    } while (u != x);
  }
}
int main() {
//  freopen("1.in", "r", stdin); 
  static char a[10], b[10];
  scanf("%d", &t);
  while (t--) {
    ans = 1, tot = 0, cnt = 0, bls = 0;
    while (!s.empty()) s.pop();
    memset(head, -1, sizeof(head));
    memset(ver, 0, sizeof(ver));
    memset(nxt, 0, sizeof(nxt));
    memset(bel, 0, sizeof(bel));
    memset(vis, 0, sizeof(vis));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    scanf("%d%d", &n, &k);
    for (int i = 1, x, y; i <= k; ++i) {
      scanf("%s%s", a, b);
      sscanf(a + 1, "%d", &x);
      sscanf(b + 1, "%d", &y);
      if (a[0] == 'm')
        if (b[0] == 'h') {
          addedge(x + n, y + n);
          addedge(y, x);
        } else {
          addedge(x + n, y);
          addedge(y + n, x);
        }
      else if (b[0] == 'h') {
          addedge(x, y + n);
          addedge(y, x + n);
        } else {
          addedge(x, y);
          addedge(y + n, x + n);
        }
    }
    for (int i = 1; i <= n; ++i)
      if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= n; ++i)
      if (bel[i] == bel[i + n]) ans = 0;
    printf(ans ? "GOOD\n" : "BAD\n");
  }
}