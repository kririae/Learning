#include <bits/stdc++.h>
#define ll long long
#define ls t[k].son[0]
#define rs t[k].son[1]
using namespace std;

const int N = 2e5 + 5;
struct Node {
  int l, r, son[2];
  double pi, li, v;
} t[N << 2];
int n, _t, q, li[N], pi[N], cnt, rt;
inline void Pushup(int k) {
  t[k].v = max(t[ls].v, t[rs].v);
}
inline void Build(int &k, int l, int r) {
  k = ++cnt;
  t[k].l = l, t[k].r = r;
  if (l == r) {
    t[k].pi = pi[l];
    t[k].li = li[l];
    t[k].v = t[k].pi * (1.0 / (t[k].li + 1));
    return;
  }
  int mid = l + r >> 1;
  Build(ls, l, mid);
  Build(rs, mid + 1, r);
  Pushup(k);
}
inline void Modify(int k, int pos, int x) {
  if (t[k].l == t[k].r && t[k].l == pos) {
    t[k].li += x;
    t[k].v = t[k].pi * (1.0 / (t[k].li + 1));
    return;
  }
  int mid = t[k].l + t[k].r >> 1;
  if (pos <= mid) Modify(ls, pos, x);
  else Modify(rs, pos, x);
  Pushup(k);
}
int main() {
//  freopen("disanti.in", "r", stdin);
//  freopen("disanti.out", "w", stdout);
  scanf("%d%d%d", &n, &_t, &q);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &pi[i]);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &li[i]);
  if (_t == 1) {
    Build(rt, 1, n);
    for (int i = 1, op, x; i <= q; ++i) {
      scanf("%d%d", &op, &x);
      if (op == 1)
        Modify(rt, x, 1);
      else
        Modify(rt, x, -1);
      printf("%.9lf\n", t[rt].v);
    }
  } else {
    cout << 0 << endl;
  }
}

/*
2 1 3
4 5
1 2
1 1
1 2
2 1
 */