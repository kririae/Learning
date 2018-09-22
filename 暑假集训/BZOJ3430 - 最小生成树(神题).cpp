#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 505;
struct Edge {
  int u, v, w;
  Edge() {}
  Edge(int _u, int _v, int _w) :
  u(_u), v(_v), w(_w) {}
  bool operator < (const Edge &a) const {
    return w < a.w;
  }
} edges[N * N * 2];
int n, m, k, tot, fa[N * N], s[N * N], 
a[N][N], b[N * N]; ll ans;
inline int calc(int x, int y) {
  return (x - 1) * m + y;
}
inline void addedge1(int u, int v, int w) {
  edges[++tot].u = u;
  edges[tot].v = v;
  edges[tot].w = w;
}
inline int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &b[calc(i, j)]);
  for (int i = 1; i <= n; ++i) 
    for (int j = 1; j <= m; ++j) {
      if (i != n) 
        addedge1(calc(i, j), calc(i + 1, j), abs(a[i][j] - a[i + 1][j]));
      if (j != m)
        addedge1(calc(i, j), calc(i, j + 1), abs(a[i][j] - a[i][j + 1]));
    }
  sort(edges + 1, edges + 1 + tot);
  for (int i = 1; i <= n * m; ++i)
    fa[i] = i, s[i] = 1;
  for (int i = 1; i <= tot; ++i) {
    Edge &e = edges[i];
    // 将a合并到b上。
    int x = find(e.u);
    int y = find(e.v);
    if(x == y) continue;
    if(s[x] + s[y] >= k) {
      if(s[x] < k) ans += 1ll * b[x] * e.w;
      if(s[y] < k) ans += 1ll * b[y] * e.w;
    }
    fa[x] = y, s[y] += s[x], b[y] += b[x];
  }
  cout << ans << endl;
}