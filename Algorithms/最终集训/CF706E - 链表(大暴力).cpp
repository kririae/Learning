#include <bits/stdc++.h>
#define ll long long
#define reg register
using namespace std;

const int N = 2005;
struct IO {
  char ibuf[1 << 18], *s, *t, obuf[1 << 18], *o, vbuf[65];
  IO() : s(ibuf), t(ibuf), o(obuf) {}
  ~IO() { fwrite(obuf, 1, o - obuf, stdout); }
  inline char gc() {
    (s == t) &&
        (t = (s = ibuf) + fread(ibuf, 1, 1 << 18, stdin));
    return s == t ? 0 : *s++;
  }
  inline void pc(char c) {
    (o == obuf + (1 << 18)) &&
        (fwrite(obuf, 1, 1 << 18, stdout), o = obuf);
    *o++ = c;
  }
  template <typename T>
  operator T() {
    register T r = 0, f = 1;
    register char c = gc();
    for (; !isdigit(c); c = gc())
      f = c == '-' ? -1 : 1;
    for (; isdigit(c); c = gc())
      r = (((r << 2) + r) << 1) + (c - '0');
    return f == 1 ? r : -r;
  }
  void operator=(char x) { pc(x); }
  void operator=(const char *x) {
    register int u = 0;
    while (x[u]) pc(x[u++]);
  }
  template <typename T>
  void operator=(T x) {
    register int u = 0;
    if (x == 0) return pc('0'), void();
    if (x < 0) x = -x, pc('-');
    while (x) vbuf[++u] = x % 10 + 48, x /= 10;
    while (u) pc(vbuf[u--]);
  }
} io;
int n, m, q, A[N][N], id[N][N], b[N][N], u1, u2, u3, u4;
inline void swap(int &a, int &b) {
  register int c = a;
  a = b, b = c;
}
struct Node {
  int r, d, x;
} a[(N + 2) * (N + 2) << 1];
int main() {
  n = io, m = io, q = io;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      A[i][j] = io;
  for (int i = 0; i <= n + 1; ++i)
    for (int j = 0; j <= m + 1; ++j)
      id[i][j] = i * (m + 2) + j;  // (i - 1) * m + j;
  for (int i = 0; i <= n + 1; ++i)
    for (int j = 0; j <= m + 1; ++j) {
      a[id[i][j]].r = id[i][j + 1];
      a[id[i][j]].d = id[i + 1][j];
      a[id[i][j]].x = A[i][j];
      // cout << A[i][j] << " -> " << id[i][j] << endl;
    }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j)
  //     cout << A[i][j] << " ";
  //   cout << endl;
  // }
  for (int i = 1, x1, y1, x2, y2, h, w; i <= q; ++i) {
    x1 = io, y1 = io, x2 = io, y2 = io, h = io, w = io;
    u1 = u2 = id[0][0];
    for (reg int j = 1; j <= x1; ++j) u1 = a[u1].d;
    for (reg int j = 1; j <= x2; ++j) u2 = a[u2].d;
    for (reg int j = 1; j < y1; ++j) u1 = a[u1].r;
    for (reg int j = 1; j < y2; ++j) u2 = a[u2].r;
    u3 = u1, u4 = u2;
    for (reg int j = 1; j <= w; ++j) u3 = a[u3].r;
    for (reg int j = 1; j <= w; ++j) u4 = a[u4].r;
    for (reg int j = 1; j <= h; ++j) {
      swap(a[u1].r, a[u2].r);
      swap(a[u3].r, a[u4].r);
      u1 = a[u1].d;
      u2 = a[u2].d;
      u3 = a[u3].d;
      u4 = a[u4].d;
    }
    u1 = u2 = id[0][0];
    for (reg int j = 1; j < x1; ++j) u1 = a[u1].d;
    for (reg int j = 1; j < x2; ++j) u2 = a[u2].d;
    for (reg int j = 1; j <= y1; ++j) u1 = a[u1].r;
    for (reg int j = 1; j <= y2; ++j) u2 = a[u2].r;
    u3 = u1, u4 = u2;
    for (reg int j = 1; j <= h; ++j) u3 = a[u3].d;
    for (reg int j = 1; j <= h; ++j) u4 = a[u4].d;
    for (reg int j = 1; j <= w; ++j) {
      swap(a[u1].d, a[u2].d);
      swap(a[u3].d, a[u4].d);
      u1 = a[u1].r;
      u2 = a[u2].r;
      u3 = a[u3].r;
      u4 = a[u4].r;
    }
  }
  int u = id[0][0], t = 0;
  for (int i = 1; i <= n; ++i) {
    u = a[u].d, t = u;
    for (int j = 1; j <= m; ++j)
      u = a[u].r, io = a[u].x, io = ' ';
    io = '\n';
    u = t;
  }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j)
  //     cout << A[i][j] << " ";
  //   cout << endl;
  // }
}