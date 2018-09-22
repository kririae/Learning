#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;
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
  memset(head, -1, sizeof head);
  scanf("%d%d", &n, &q);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  for (int i = 1, l, r; i <= q; ++i) {
    scanf("%d%d", &l, &r);
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