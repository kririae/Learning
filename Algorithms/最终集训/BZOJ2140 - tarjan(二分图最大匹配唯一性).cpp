#include <bits/stdc++.h>
using namespace std;

const int N = 40000;
int n;
map<string, int> mp;
int head[N], ver[N], nxt[N], tot, bel[N];
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
int dfn[N], low[N], cnt, s[N], top, vis[N], c;
inline void tarjan(int x) {
  dfn[x] = low[x] = ++cnt;
  vis[s[++top] = x] = 1;
  int u;
  for (int i = head[x], to; ~i; i = nxt[i])
    if (!dfn[to = ver[i]]) {
      tarjan(to);
      low[x] = min(low[x], low[to]);
    } else if (vis[to])
      low[x] = min(low[x], dfn[to]);
  if (dfn[x] == low[x]) {
    ++c;
    do {
      vis[u = s[top--]] = 0;
      bel[u] = c;
    } while (u != x);
  }
}
int main() {
  memset(head, -1, sizeof head);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string a, b;
    cin >> a >> b;
    mp[a] = i << 1, mp[b] = (i << 1) | 1;
    addedge(i << 1, (i << 1) | 1);
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    string a, b;
    cin >> a >> b;
    addedge(mp[b], mp[a]);
  }
  for (int i = 1; i <= n << 1; ++i)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= n; ++i)
    if (bel[i << 1] == bel[(i << 1) | 1])
      return puts("Unsafe"), 0;
  puts("Safe");
}