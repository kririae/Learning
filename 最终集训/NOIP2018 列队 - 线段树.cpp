#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e5 + 5;
int n, m, q, a[1005][1005], c[N], X[N], Y[N];
ll d[505][N];
struct BIT {
ll size, cnt, e[N], t[N];
BIT() {}
BIT(int x) : size(x) { 
  memset(t, 0, sizeof t); 
  memset(e, 0, sizeof e);
}
inline void Insert(ll x) {
  for (int i = ++cnt; i <= size; i += i & -i) t[i] += x;
  for (int i = cnt; i <= size; i += i & -i) ++e[i];
}
inline int QueryId(int x) {
  int ans = 0;
  for (; x; x -= x & -x) ans += e[x];
  return ans;
}
inline ll Query(int x) {
  ll ans = 0;
  for (; x; x -= x & -x) ans += t[x];
  return ans;
}
inline int Find(int x) {
  int l = 1, r = size;
  while (l < r) {
    int mid = l + r >> 1;
    if (QueryId(mid) >= x) r = mid;
    else l = mid + 1;
  }
  return l;
}
inline void Add(int x, int v) { 
  x = Find(x);
  for (; x <= size; x += x & -x) t[x] += v;
}
inline void Del(int x) {
  x = Find(x);
  ll v = Query(x) - Query(x - 1);
  for (int i = x; i <= size; i += i & -i) --e[i];
  for (int i = x; i <= size; i += i & -i) t[i] -= v;
}
inline int _find(int x) {
  x = Find(x);
  return Query(x);
}
ll operator [] (int x) {
  return _find(x) - _find(x - 1);
}
};
inline ll calc(int x, int y) {
  return 1ll * (x - 1) * m + y;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  if (n <= 1000 && m <= 1000) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        a[i][j] = (i - 1) * m + j;
    for (int i = 1, x, y; i <= q; ++i) {
      scanf("%d%d", &x, &y);
      int t = a[x][y];
      printf("%d\n", t);
      a[x][y] = 0;
      for (int j = y; j < m; ++j)
        a[x][j] = a[x][j + 1];
      for (int j = x; j <= n; ++j)
        a[j][m] = a[j + 1][m];
      a[n][m] = t;
    }
    return 0;
  }
  if (q <= 500) {
    for (int i = 1; i <= n; ++i)
      d[0][i] = i * m;
    for (int i = 1, x, y; i <= q; ++i) {
      scanf("%d%d", &x, &y);
      if (y == m) {
        printf("%lld\n", d[0][x]);
        ll t = d[0][x];
        for (int j = x; j <= n; ++j)
          d[0][j] = d[0][j + 1];
        d[0][n] = t;
        continue;
      }
      if (!c[x]) {
        c[x] = i;
        for (int j = 1; j < m; ++j)
          d[i][j] = calc(x, j);
      }
      ll t = d[c[x]][y];
      printf("%lld\n", t);
      for (int j = y; j < m - 1; ++j)
        d[c[x]][j] = d[c[x]][j + 1];
      d[c[x]][m - 1] = d[0][x];
      for (int j = x; j <= n; ++j)
        d[0][j] = d[0][j + 1];
      d[0][n] = t;
    }
    return 0;
  }
  int flag = 1;
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d", &X[i], &Y[i]);
    if (X[i] != 1) flag = 0;
  }
  if (flag) {
    // x全都是1的情况
    // vector中[1, n - 1]都是属于行的，[n, n + m - 1]都是属于列的。
    // 进行树状数组维护，两颗，分别维护id和0 1
    static BIT th(m + q + 5), tl(n + q + 5);
    for (int j = 1; j < m; ++j)
      th.Insert(calc(1, j));
    for (int j = 1; j <= n; ++j)
      tl.Insert(calc(j, m));
    for (int i = 1, x, y; i <= q; ++i) {
      x = X[i], y = Y[i];
      if (y == m) {
        ll t = tl[1];
        printf("%lld\n", t);
        tl.Del(1);
        tl.Insert(t);
        continue;
      }
      ll t = th[y];
      printf("%lld\n", t);
      th.Del(y);
      th.Insert(tl[1]);
      tl.Del(1);
      tl.Insert(t);
    }
  }
}