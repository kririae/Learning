#include <bits/stdc++.h>
#define ll long long
#define reg register
using namespace std;

const int N = 2005;
int n, m, q1, A[N][N], id[N][N], b[N][N], u1, u2, u3, u4;
inline void spawning(int P, int Q, int R, int S, int Mod) {
  int T = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      T = (T + (1ll * (i + j) * P + 1ll * i * j * Q + 1ll * i * R + 1ll * j * S) % Mod + Mod) % Mod;
      A[i][j] = T;
    }
  A[P % n + 1][P % m + 1] ^= 1;
  A[P % n + 1][Q % m + 1] ^= 1;
  A[P % n + 1][R % m + 1] ^= 1;
  A[P % n + 1][S % m + 1] ^= 1;
  A[Q % n + 1][P % m + 1] ^= 1;
  A[Q % n + 1][Q % m + 1] ^= 1;
  A[Q % n + 1][R % m + 1] ^= 1;
  A[Q % n + 1][S % m + 1] ^= 1;
  A[R % n + 1][P % m + 1] ^= 1;
  A[R % n + 1][Q % m + 1] ^= 1;
  A[R % n + 1][R % m + 1] ^= 1;
  A[R % n + 1][S % m + 1] ^= 1;
  A[S % n + 1][P % m + 1] ^= 1;
  A[S % n + 1][Q % m + 1] ^= 1;
  A[S % n + 1][R % m + 1] ^= 1;
  A[S % n + 1][S % m + 1] ^= 1;
}
inline void checker() {
  long long Pin = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      Pin += (1ll * i * n + j) * A[i][j];
  printf("%lld\n", Pin);
}
inline void swap(int &a, int &b) {
  register int c = a;
  a = b, b = c;
}
struct Node {
  int r, d, x;
} a[(N + 2) * (N + 2) << 1];
int main() {
  freopen("havefun.in", "r", stdin);
  freopen("havefun.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &q1);
  int p, q, r, s, mod;
  scanf("%d%d%d%d%d", &p, &q, &r, &s, &mod);
  spawning(p, q, r, s, mod);
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
  for (int i = 1, x1, y1, x2, y2, h, w; i <= q1; ++i) {
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &h, &w);
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
      u = a[u].r, A[i][j] = a[u].x;
    u = t;
  }
  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= m; ++j)
  //     cout << A[i][j] << " ";
  //   cout << endl;
  // }
  checker();
}
