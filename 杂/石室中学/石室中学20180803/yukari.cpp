// by kririae
#include <bits/stdc++.h>
#define ll long long
#define ls t[k].son[0]
#define rs t[k].son[1]
using namespace std;

const int N = 150005;
struct Node
{
  int l, r, son[2];
  ll S, L, MID, R;
} t[N << 2];
ll n, m, kx, x[N], X[N], p, a, b, cnt; int rt;
inline void pushup(int k)
{
  t[k].S = t[ls].S + t[rs].S;
  t[k].L = max(t[ls].L, t[ls].S + t[rs].L);
  t[k].R = max(t[rs].R, t[rs].S + t[ls].R);
  t[k].MID = max(max(t[ls].MID, t[rs].MID), t[ls].R + t[rs].L);
}
inline void build(int &k, int l, int r)
{
  k = ++cnt, t[k].l = l, t[k].r = r;
  if(l == r) 
    return t[k].S = t[k].L = t[k].MID = t[k].R = X[l], void();
  int mid = l + r >> 1;
  build(ls, l, mid), build(rs, mid + 1, r);
  pushup(k);
}
inline ll query(int k, int l, int r)
{
  if(t[k].l == l && t[k].r == r)
    return t[k].MID;
  int mid = t[k].l + t[k].r >> 1;
  if(r <= mid) return query(ls, l, r);
  else if(l > mid) return query(rs, l, r);
  else return query(ls, l, mid) + query(rs, mid + 1, r);
}
int main()
{
  scanf("%lld%lld%lld", &n, &m, &kx);
  for (int i = 1; i <= n; ++i) scanf("%lld", &x[i]);
  for (int i = 1; i < n; ++i) X[i] = (x[i + 1] - x[i]) * 50;
  for (int i = 1; i < n; ++i) scanf("%lld", &p), X[i] -= p * kx;
  build(rt, 1, n - 1);
  ll ans = 0;
  for (int i = 1; i <= m; ++i) {
    scanf("%lld%lld", &a, &b);
    ans += max(0ll, query(rt, a, b - 1));
  } printf("%.2lf", ans / 100.0);
}