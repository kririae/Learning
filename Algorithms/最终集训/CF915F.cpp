#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 5;
struct Edge { int u, v, w, x; } b[N];
int n, a[N], fa[N], siz[N]; ll ans1, ans2;
inline bool cmp1(const Edge &x, const Edge &y) { return x.w > y.w; }
inline bool cmp2(const Edge &x, const Edge &y) { return x.w < y.w; }
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void init() { for (int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &b[i].u, &b[i].v);
    b[i].w = max(a[b[i].u], a[b[i].v]);
    b[i].x = min(a[b[i].u], a[b[i].v]);
  }
  sort(b + 1, b + n, cmp1); init();
  for (int i = 1; i < n; ++i) {
    int x = find(b[i].u), y = find(b[i].v);
    if (x == y) continue;
    ans1 += siz[x] * siz[y] * b[i].w;
    fa[x] = y;
    siz[y] += siz[x];
  }
  sort(b + 1, b + n, cmp2); init();
  for (int i = 1; i < n; ++i) {
    int x = find(b[i].u), y = find(b[i].v);
    if (x == y) continue;
    ans2 += siz[x] * siz[y] * b[i].w;
    fa[x] = y;
    siz[y] += siz[x];
  }
  printf("%lld", ans2 - ans1);
}