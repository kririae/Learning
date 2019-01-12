#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
struct Q {
  int l, r, id, x;
  bool operator < (const Q &a) const {
    if (id == a.id) {
      if (id & 1) return r < a.r;
      else return r > a.r;
    } else return id < a.id;
  }
} a[N];
int n, q, head[N], ver[N << 1], 
nxt[N << 1], tot, cnt, res[N];
int l = 1, r = 0;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void Add(int x) {
  for (register int i = head[x]; ~i; i = nxt[i])
    if (ver[i] >= l && ver[i] <= r) ++cnt;
}
inline void Delete(int x) {
  for (register int i = head[x]; ~i; i = nxt[i]) 
    if (ver[i] >= l && ver[i] <= r) --cnt;
}
int main() {
//  freopen("dierti.in", "r", stdin);
//  freopen("dierti.out", "w", stdout);
  memset(head, -1, sizeof head);
  scanf("%d%d", &n, &q);
  for (register int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  int sz = sqrt(n) + 1;
  for (register int i = 1, l, r; i <= q; ++i) {
    scanf("%d%d", &l, &r);
    a[i].l = l, a[i].r = r;
    a[i].id = (l / sz) + 1, a[i].x = i;
  }
  sort(a + 1, a + 1 + q);
  for (int i = 1; i <= q; ++i) {
    Q t = a[i];
    while (r > t.r) Delete(r), --r;
    while (r < t.r) ++r, Add(r);
    while (l < t.l) Delete(l), l++;
    while (l > t.l) --l, Add(l);
    res[t.x] = (r - l + 1) - cnt;
  }
  for (int i = 1; i <= q; ++i)
    printf("%d\n", res[i]);
  return 0;
}