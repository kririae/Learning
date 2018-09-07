// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define ll long long
#define ls t[k].son[0]
#define rs t[k].son[1]
using namespace std;

namespace BZOJ4568 {
const int N = 20005;
struct Node {
  int l, r, son[2];
  ll b[65];
} t[N << 2]; int root, tcnt; ll g[N], w[N];
int n, q, head[N], ver[N << 1], nxt[N << 1], tot;
int siz[N], son[N], fa[N], dep[N], id[N], top[N], cnt;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void dfs1(int x) {
  siz[x] = 1, son[x] = 0;
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if((to = ver[i]) == fa[x]) continue;
    fa[to] = x, dep[to] = dep[x] + 1;
    dfs1(to);
    if(siz[to] > siz[son[x]]) son[x] = to;
    siz[x] += siz[to];
  }
}
inline void dfs2(int x, int topf) {
  id[x] = ++cnt, w[cnt] = g[x], top[x] = topf;
  if(!son[x]) return;
  dfs2(son[x], topf);
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if((to = ver[i]) == fa[x] || to == son[x]) continue;
    dfs2(to, to);
  }
}
inline void insert(ll x, ll *a) {
  for (int j = 60; j >= 0; --j)
    if(x & (1ll << j)) {
      if(a[j] == 0) return a[j] = x, void();
      x ^= a[j];
    }
}
inline void merge(ll *a, ll *b) {
  for (int i = 0; i <= 60; ++i) if(b[i]) insert(b[i], a);
}
inline ll gmax(ll *a, ll ans = 0) {
  for (int i = 60; i >= 0; --i) ans = max(ans, ans ^ a[i]);
  return ans;
}
inline void pushup(int k) {
  merge(t[k].b, t[ls].b), merge(t[k].b, t[rs].b);
}
inline void build(int &k, int l, int r) {
  k = ++tcnt, t[k].l = l, t[k].r = r;
  if(l == r) return insert(w[l], t[k].b), void();
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(k);
}
inline void query(int k, int l, int r, ll *ans) {
  if(t[k].l == l && t[k].r == r) return merge(ans, t[k].b), void();
  int mid = t[k].l + t[k].r >> 1;
  if(r <= mid) query(ls, l, r, ans);
  else if(l > mid) query(rs, l, r, ans);
  else query(ls, l, mid, ans), query(rs, mid + 1, r, ans);
}
inline ll work(int x, int y) {
  static ll ans[65], tmp[65];
  memset(ans, 0, sizeof(ans)); 
  while(top[x] != top[y]) {
    if(dep[top[x]] < dep[top[y]]) swap(x, y);
    memset(tmp, 0, sizeof(tmp));
    query(root, id[top[x]], id[x], tmp);
    merge(ans, tmp);
    x = fa[top[x]];
  } 
  if(dep[x] > dep[y]) swap(x, y);
  memset(tmp, 0, sizeof(tmp));
  query(root, id[x], id[y], tmp);
  merge(ans, tmp);
  return gmax(ans);
}
inline void solve() {
  memset(head, -1, sizeof(head));
  n = read(), q = read();
  for (int i = 1; i <= n; ++i) g[i] = read();
  for (int i = 1, x, y; i < n; ++i) {
    x = read(), y = read();
    addedge(x, y);
    addedge(y, x);
  }
  dfs1(1), dfs2(1, 1), build(root, 1, n);
  for (int i = 1, x, y; i <= q; ++i) {
    x = read(), y = read();
    printf("%lld\n", work(x, y));
  }
}
}

int main() {
  return BZOJ4568::solve(), 0;
}