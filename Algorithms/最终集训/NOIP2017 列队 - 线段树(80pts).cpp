#include <bits/stdc++.h>
#define ls son[k][0]
#define rs son[k][1]
#define ll long long
using namespace std;

int n, m, q, a[1005][1005]; 
ll b[505][50005], c[50005];
inline ll calc(ll x, ll y) {
  return (x - 1) * m + y;
}
inline void work30() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) 
      a[i][j] = calc(i, j);
  int x = 0, y = 0;
  while (q--) {
    scanf("%d%d", &x, &y);
    int t = a[x][y];
    printf("%d\n", t);
    a[x][y] = 0;
    for (int i = y; i <= m; ++i)
      a[x][i] = a[x][i + 1];
    for (int i = x; i <= n; ++i)
      a[i][m] = a[i + 1][m];
    a[n][m] = t;
  }
}
inline void work50() {
  memset(c, 0, sizeof c);
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    b[0][i] = calc(i, m);
  int x = 0, y = 0;
  while (q--) {
    scanf("%d%d", &x, &y);
    if (y == m) {
      ll t = b[0][x];
      b[0][x] = 0;
      printf("%lld\n", t);
      for (int i = x; i <= n; ++i)
        b[0][i] = b[0][i + 1];
      b[0][n] = t;
      continue;
    }
    if (!c[x]) {
      c[x] = ++cnt;
      for (int i = 1; i <= m - 1; ++i)
        b[c[x]][i] = calc(x, i);
    }
    ll t = b[c[x]][y];
    printf("%lld\n", t);
    for (int i = y; i < m - 1; ++i)
      b[c[x]][i] = b[c[x]][i + 1];
    b[c[x]][m - 1] = b[0][x];
    for (int i = x; i < n; ++i)
      b[0][i] = b[0][i + 1];
    b[0][n] = t;
  }
}
const int N = (3e5 + 5) * 2;
struct Seg {
int L[N << 2], R[N << 2], son[N << 2][2], rt;
ll _s[N << 2], s[N << 2], cnt, curr;
inline void pushup(int k) {
  s[k] = s[ls] + s[rs];
  _s[k] = _s[ls] + _s[rs];
}
inline void Build(int &k, int l, int r) {
  k = ++cnt;
  L[k] = l;
  R[k] = r;
  if (l == r)
    return;
  int mid = l + r >> 1;
  Build(ls, l, mid);
  Build(rs, mid + 1, r);
  pushup(k);
}
inline void Modify(int k, int p, ll x) {
  if (L[k] == R[k]) {
    _s[k] = 1;
    s[k] = x;
    return ;
  }
  int mid = L[k] + R[k] >> 1;
  if (p <= mid)
    Modify(ls, p, x);
  else 
    Modify(rs, p, x);
  pushup(k);
}
inline void Insert(ll x) {
  Modify(rt, ++curr, x);
}
inline ll Query(int k, int p) {
  if (L[k] == R[k])
    return s[k];
  int mid = L[k] + R[k] >> 1;
  if (_s[ls] >= p)
    return Query(ls, p);
  else 
    return Query(rs, p - _s[ls]);
}
inline void Del(int k, int p) {
  if (L[k] == R[k])
    return _s[k] = s[k] = 0, void();
  int mid = L[k] + R[k] >> 1;
  if (_s[ls] >= p)
    Del(ls, p);
  else
    Del(rs, p - _s[ls]);
  pushup(k);
}
//inline void Set(int k, int p, ll x) {
//	if (L[k] == R[k]) {
//		_s[k] = 1;
//		 s[k] = x;
//		return;
//	}
//	if (_s[ls] >= p)
//		return Set(ls, p, x);
//	else 
//		return Set(rs, p - _s[ls], x);
//	pushup(k);
//}
} d, e;
int main() {
  scanf("%d%d%d", &n, &m, &q);
  if (n <= 1000 && m <= 1000) {
    work30();	
    return 0;
  }
  if (q <= 500) {
    work50();
    return 0;
  }
  d.Build(d.rt, 1, m + q + 5);
  e.Build(e.rt, 1, n + q + 5);
  for (int i = 1; i <= m - 1; ++i)
    d.Insert(i);
  for (int i = 1; i <= n; ++i)
    e.Insert(calc(i, m));
  int x, y;
  while (q--) {
    scanf("%d%d", &x, &y);
    if (y == m) {
      ll t = e.Query(e.rt, x);
      printf("%lld\n", t);
      e.Del(e.rt, x);
      e.Insert(t);
    } else {
      ll t = d.Query(d.rt, y);
      printf("%lld\n", t);
      d.Del(d.rt, y);
      d.Insert(e.Query(e.rt, x));
      e.Del(e.rt, x);
      e.Insert(t);
    }
  }
}