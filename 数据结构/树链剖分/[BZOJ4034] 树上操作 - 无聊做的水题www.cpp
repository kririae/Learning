// by kririae
// let me 摸鱼
#include <bits/stdc++.h>
#define ll long long
#define ls t[k].son[0]
#define rs t[k].son[1]
using namespace std;

const int N = 1e6 + 5;
ll n, m, head[N], ver[N << 1], nxt[N << 1], tot; ll a[N], w[N];
ll siz[N], son[N], fa[N], dep[N], id[N], cnt, top[N]; 
struct Node {
  int l, r, son[2];
  ll add, sum;
} t[N << 2]; int root, tcnt;
inline void pushup(int k) {
  t[k].sum = t[ls].sum + t[rs].sum;
}
inline void pushdown(int k) {
  if(!t[k].add) return;
  t[ls].add += t[k].add;
  t[rs].add += t[k].add;
  t[ls].sum += (t[ls].r - t[ls].l + 1) * t[k].add;
  t[rs].sum += (t[rs].r - t[rs].l + 1) * t[k].add;
  t[k].add = 0;
}
inline void build(int &k, int l, int r) {
  k = ++tcnt, t[k].l = l, t[k].r = r;
  if(l == r) return t[k].sum = w[l], void();
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(k);
}
inline void pmodify(int k, int pos, ll val) {
  if(t[k].l == t[k].r && t[k].l == pos)
    return t[k].sum += val, void();
  pushdown(k);
  int mid = t[k].l + t[k].r >> 1;
  if(pos <= mid) pmodify(ls, pos, val);
  else pmodify(rs, pos, val);
  pushup(k);
}
inline void rmodify(int k, int l, int r, ll val) {
  if(t[k].l == l && t[k].r == r) {
    t[k].sum += (r - l + 1) * val;
    t[k].add += val;
    return;
  } int mid = t[k].l + t[k].r >> 1;
  pushdown(k);
  if(r <= mid) rmodify(ls, l, r, val);
  else if(l > mid) rmodify(rs, l, r, val);
  else rmodify(ls, l, mid, val), rmodify(rs, mid + 1, r, val);
  pushup(k);
}
inline ll query(int k, int l, int r) {
  if(t[k].l == l && t[k].r == r)
    return t[k].sum;
  pushdown(k);
  int mid = t[k].l + t[k].r >> 1;
  if(r <= mid) return query(ls, l, r);
  else if(l > mid) return query(rs, l, r);
  else return query(ls, l, mid) + query(rs, mid + 1, r);
}
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
  id[x] = ++cnt, w[cnt] = a[x], top[x] = topf;
  if(!son[x]) return;
  dfs2(son[x], topf);
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if((to = ver[i]) == fa[x] || to == son[x]) continue;
    dfs2(to, to);
  }
}
inline void tadd(int x, ll val) {
  rmodify(root, id[x], id[x] + siz[x] - 1, val);
}
inline void tpadd(int x, ll val) {
  pmodify(root, id[x], val);
}
inline ll qtree(int x) {
  ll ans = 0;
  while(top[x] != 1) {
    ans += query(root, id[top[x]], id[x]);
    x = fa[top[x]];
  } ans += query(root, id[1], id[x]);
  return ans;
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  dfs1(1); dfs2(1, 1);
  build(root, 1, n);
  ll op, x, y;
  while(m--) {
    scanf("%lld", &op);
    switch(op) {
      case 1: scanf("%lld%lld", &x, &y); tpadd(x, y); break;
      case 2: scanf("%lld%lld", &x, &y); tadd(x, y); break;
      case 3: scanf("%lld", &x); printf("%lld\n", qtree(x));
    }
  }
}