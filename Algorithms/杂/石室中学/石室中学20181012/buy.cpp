#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 10005;
int n, m, w, fa[N], vis[N];
ll c[N], d[N], l[N], cnt, f[N];
inline int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
  freopen("buy.in", "r", stdin);
  freopen("buy.out", "w", stdout);
  memset(f, -1, sizeof f);
  scanf("%d%d%d", &n, &m, &w);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &c[i], &d[i]);
  for (int i = 1, u, v; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    int x = find(u),
        y = find(v);
    if (x == y) continue;
    fa[x] = y;
    c[y] += c[x];
    d[y] += d[x];
  }
  for (int i = 1; i <= n; ++i) {
    int u = find(i);
    l[++cnt] = u;
  }
  sort(l + 1, l + 1 + cnt);
  int sz = unique(l + 1, l + 1 + cnt) - l - 1;
  f[0] = 0;
  for (int i = 1; i <= sz; ++i)
    for (int j = w; j >= 0; --j)
      if (j + c[l[i]] <= w && ~f[j])
        f[j + c[l[i]]] = max(f[j + c[l[i]]], f[j] + d[l[i]]);
  ll ans = 0;
  for (int i = 0; i <= w; ++i)
    ans = max(ans, f[i]);
  cout << ans;
}