#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, m, head[N], ver[N], nxt[N], tot;
int dfn[N], low[N], cnt, s[N], top, vis[N], c, belong[N], siz[N], f[N];
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void tarjan(int x) {
  dfn[x] = low[x] = ++cnt;
  vis[s[++top] = x] = 1;
  int u;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if (!dfn[to = ver[i]]) {
      tarjan(to);
      low[x] = min(low[x], low[to]);
    } else if (vis[to])
      low[x] = min(low[x], dfn[to]);
  }
  if (dfn[x] == low[x]) {
    ++c;
    do {
      vis[u = s[top--]] = 0;
      belong[u] = c;
      ++siz[c];
    } while (u != x);
  }
}
namespace DP {
int head[N << 1], ver[N << 1], nxt[N << 1], tot, in[N], vis[N];
queue<int> q;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  ++in[v];
  head[u] = tot++;
}
inline int Bfs() {
  while (!q.empty()) q.pop();
  q.push(belong[1]);
  vis[belong[1]] = 1;
  while (!q.empty()) {
    int u = q.front();
    vis[u] = 0;
    q.pop();
    for (int i = head[u], to; ~i; i = nxt[i]) {
      if (f[to = ver[i]] < f[u] + siz[u]) {
        f[to] = f[u] + siz[u];
        if (!vis[to]) vis[to] = 1, q.push(to);
      }
    }
  }
  return f[belong[1] + c];
}
}  // namespace DP
int main() {
  memset(head, -1, sizeof head);
  memset(f, 0, sizeof f);
  scanf("%d%d", &n, &m);
  int u, v;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
  }
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= c; ++i)
    siz[i + c] = siz[i];
  memset(DP::head, -1, sizeof DP::head);
  for (int i = 1; i <= n; ++i)
    for (int j = head[i], to; ~j; j = nxt[j]) {
      int x = belong[i],
          y = belong[to = ver[j]];
      if (x != y) {
        // cout << x << " " << y << endl;
        DP::addedge(x, y);
        DP::addedge(y, x + c);
        DP::addedge(x + c, y + c);
      }
    }
  cout << DP::Bfs();
}