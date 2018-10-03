#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read() {
  int k = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
const int N = 40005, M = 205;
int n, m, sz, a[N], b[N];
namespace Block {
int siz, cnt, L[N], R[N], bl[N];
int f[M][N], g[M][M], c[N], vis[N];
inline int get(int l, int r) {
  memset(c, 0, sizeof c);
  int _v = 0, _c = 0;
  if (l > r) 
    return 0;
  for (int i = l; i <= r; ++i) {
    ++c[a[i]];
    if (c[a[i]] >= _c) {
      if (c[a[i]] == _c)
        _v = min(_v, a[i]);
      else
        _v = a[i];
      _c = c[a[i]];
    }
  }
  return _v;
}
inline void init() {
  siz = sqrt(n);
  cnt = n % siz == 0 ? n / siz : n / siz + 1;
  for (int i = 1; i <= cnt; ++i)
    L[i] = R[i - 1] + 1, 
    R[i] = L[i] + siz - 1;
  R[cnt] = n;
  for (int i = 1; i <= cnt; ++i) {
    for (int j = 1; j <= n; ++j)
      f[i][a[j]] = f[i - 1][a[j]];
    for (int j = L[i]; j <= R[i]; ++j)
      ++f[i][a[j]],
      bl[j] = i;
  }
  memset(c, 0, sizeof c);
  for (int i = 1; i <= cnt; ++i) {
    memset(c, 0, sizeof c);
    int _v = 0, _c = 0;
    for (int j = i; j <= cnt; ++j) {
      for (int k = L[j]; k <= R[j]; ++k) {
        if (++c[a[k]] >= _c) {
          if (c[a[k]] == _c)
            _v = min(_v, a[k]);
          else
            _v = a[k];
          _c = c[a[k]];
        }
      }
      g[i][j] = _v;
    }
  }
}
inline int queryCnt(int l, int r, int x) {
  return f[r][x] - f[l - 1][x];
}
inline int Query(int l, int r) {
  if (bl[l] == bl[r]) 
    return get(l, r);
  memset(c, 0, sizeof c);
  memset(vis, 0, sizeof vis);
  int x = g[bl[l] + 1][bl[r] - 1];
  c[x] += queryCnt(bl[l] + 1, bl[r] - 1, x);
  vis[x] = 1;
  for (int i = l; i <= r; ++i) {
    ++c[a[i]];
    if (vis[a[i]] == 0) 
      c[a[i]] += queryCnt(bl[l] + 1, bl[r] - 1, a[i]),
      vis[a[i]] = 1;
    if (i == L[bl[l] + 1] - 1)
      i = L[bl[r]] - 1;
  }
  int _v = 0, _c = 0;
  for (int i = l; i <= r; ++i) {
    if (c[a[i]] >= _c) {
      if (c[a[i]] == _c)
        _v = min(_v, a[i]);
      else 
        _v = a[i];
      _c = c[a[i]];
    }
    if (i == L[bl[l] + 1] - 1)
      i = L[bl[r]] - 1;
  }
  if (c[x] >= _c) {
    if (c[x] == _c)
      _v = min(_v, x);
    else 
      _v = x;
    _c = c[x];
  }
  return _v;
}
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i)
    a[i] = read(), 
    b[i] = a[i];
  sort(b + 1, b + 1 + n);
  sz = unique(b + 1, b + 1 + n) - b - 1;
  for (int i = 1; i <= n; ++i) 
    a[i] = lower_bound(b + 1, b + 1 + sz, a[i]) - b;
  Block::init();
  int last = 0;
  for (int i = 1, l, r; i <= m; ++i) {
    l = read(), r = read();
    l = (l + last - 1) % n + 1;
    r = (r + last - 1) % n + 1;
    if (l > r) swap(l, r);
    printf("%d\n", last = b[Block::Query(l, r)]);
  }
}