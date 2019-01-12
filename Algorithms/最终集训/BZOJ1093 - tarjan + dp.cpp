#include <bits / stdc++.h>
#define ll long long
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read() {
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 1e5 + 5, M = 1e6 + 5;
pair<int, int> a[M << 1];
int n, m, MOD, head[N], ver[M], nxt[M], tot;
int dfn[N], low[N], cnt, s[N], top, vis[N], bel[N], siz[N], c;
int dis[N], in[N];
ll f[N];
inline void addedge(int u, int v) {
  ver[tot] = v, nxt[tot] = head[u], head[u] = tot++;
}
inline void tarjan(int x) {
  dfn[x] = low[x] = ++cnt;
  vis[s[++top] = x] = 1;
  int u;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if (!dfn[to = ver[i]])
      tarjan(to), low[x] = min(low[x], low[to]);
    else if (vis[to])
      low[x] = min(low[x], dfn[to]);
  }
  if (dfn[x] == low[x]) {
    ++c;
    do
      vis[u = s[top--]] = 0, bel[u] = c, ++siz[c];
    while (u != x);
  }
}
namespace SP {
int head[N], ver[M], nxt[M], tot, vis[N];
queue<int> q;
inline void addedge(int u, int v) {
  ver[tot] = v, nxt[tot] = head[u], head[u] = tot++;
}
inline void LP() {
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u], to; ~i; i = nxt[i]) {
      if (dis[to = ver[i]] <= dis[u] + siz[to]) {
        dis[to] = dis[u] + siz[to];
        if (!vis[to]) vis[to] = 1, q.push(to);
      }
    }
  }
}
}  // namespace SP
namespace DP {
int head[N], ver[M], nxt[M], tot;
inline void addedge(int u, int v) {
  ver[tot] = v, nxt[tot] = head[u], head[u] = tot++;
}
inline ll dfs(int x) {
  if (f[x]) return f[x] % MOD;
  for (int i = head[x]; ~i; i = nxt[i])
    if (dis[ver[i]] + siz[x] == dis[x])
      (f[x] += dfs(ver[i])) %= MOD;
  return f[x] % MOD;
}
}  // namespace DP
int main() {
  memset(head, -1, sizeof head);
  n = read(), m = read(), MOD = read();
  for (int i = 1, u, v; i <= m; ++i)
    u = read(), v = read(), addedge(u, v);
  memset(SP::head, -1, sizeof SP::head);
  memset(DP::head, -1, sizeof DP::head);
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) tarjan(i);
  int tcnt = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = head[i], to; ~j; j = nxt[j])
      if (bel[i] != bel[to = ver[j]])
        a[++tcnt].first = bel[i], a[tcnt].second = bel[to];
  sort(a + 1, a + 1 + tcnt);
  int sz = unique(a + 1, a + 1 + tcnt) - a - 1;
  for (int i = 1; i <= sz; ++i)
    SP::addedge(a[i].first, a[i].second),
        DP::addedge(a[i].second, a[i].first),
        ++in[a[i].second];
  for (int i = 1; i <= c; ++i)
    if (in[i] == 0) SP::q.push(i), dis[i] = siz[i], SP::vis[i] = 1, f[i] = 1;
  SP::LP();
  for (int i = 1; i <= n; ++i) DP::dfs(i);
  ll mv = 0, ans = 0;
  for (int i = 1; i <= n; ++i)
    if (dis[i] > mv) mv = dis[i];
  for (int i = 1; i <= n; ++i)
    if (dis[i] == mv) ans = (ans + f[i]) % MOD;
  cout << mv << endl
       << ans;
}