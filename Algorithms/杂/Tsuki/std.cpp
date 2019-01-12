#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read() {
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}

const int N = 5e5 + 5;
int n, q, head[N], ver[N << 1], 
nxt[N << 1], tot, res[N];
ll t[N];
vector< pair<int, int> > to[N];
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void Add(int p, int x) {
  for (; p <= n; p += p & -p) t[p] += x;
}
inline int Query(int p, int ans = 0) {
  for (; p; p -= p & -p) ans += t[p];
  return ans;
}
int main() {
  // freopen("tsuki.in", "r", stdin);
  // freopen("tsuki.out", "w", stdout);
  memset(head, -1, sizeof head);
  n = read(), q = read();
  for (int i = 1, u, v; i < n; ++i) {
    u = read(), v = read();
    addedge(u, v);
    addedge(v, u);
  }
  for (int i = 1, l, r; i <= q; ++i) {
    l = read(), r = read();
    if (l > r) swap(l, r);
    to[r].push_back(make_pair(l, i));
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = head[i]; ~j; j = nxt[j])
      if (ver[j] <= i) Add(ver[j], 1);
    for (int j = 0; j < to[i].size(); ++j) {
      int l = to[i][j].first, id = to[i][j].second;
      res[id] = (i - l + 1) - (Query(i) - Query(l - 1));
    }
  }
  for (int i = 1; i <= q; ++i) 
    printf("%d\n", res[i]);
}
