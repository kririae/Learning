#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, ans, dfn[N], low[N], 
vis[N], cnt, all; stack<int> s;
int head[N], ver[N], nxt[N], 
edge[N], sta[N], tot;
vector<int> cir[N];

inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  nxt[tot] = head[u];
  edge[tot] = w;
  head[u] = tot++;
}
inline void tarjan(int x) {
  dfn[x] = low[x] = ++cnt;
  vis[x] = 1, s.push(x);
  for (int i = head[x]; ~i; i = nxt[i]) {
    if(!sta[i]) continue;
    int to = ver[i];
    if(!dfn[to]) {
      tarjan(to);
      low[x] = min(low[x], low[to]);
    } else if(vis[to]) 
      low[x] = min(low[x], dfn[to]);
  }
  if(low[x] == dfn[x]) {
    int curr;
    ++all;
    do {
      curr = s.top();
      s.pop();
      vis[curr] = 0;
      cir[all].push_back(curr);
    } while(curr != x);
  }
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  for (int i = 1, a, c; i <= n; ++i) {
    scanf("%d%d", &a, &c);
    addedge(a, i, c);
  }
  for (int i = 1; i <= n; ++i) {
    int x = 0, y = 0;
    for (int e = head[i]; ~e; e = nxt[e]) {
      ans += edge[e];
      if(edge[e] > x)
        x = edge[e], y = e;
    } 
    sta[y] = 1;
    ans -= x;
  }
  for (int i = 1; i <= n; ++i)
    if(!dfn[i]) tarjan(i);
  for (int i = 1; i <= all; ++i) {
    if(cir[i].size() <= 1) continue;
    int m = 1e9;
    for (int j = 0; j < cir[i].size(); ++j)
      for (int e = head[cir[i][j]]; ~e; e = nxt[e])
        if(sta[e]) m = min(m, edge[e]);
    ans += m == 1e9 ? 0 : m;
  }
  printf("%d", ans);
}