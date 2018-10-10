#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 4005;
inline char gc() {
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read() {
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
int n, m, Tmax, t[N], w[N], T[N], W[N];
ll a[N], b[N], f[5005];
vector<int> d[N];
int main() {
  freopen("restaurant.in", "r", stdin);
  freopen("restaurant.out", "w", stdout);
  int qwq;
  qwq = read();
  while (qwq--) {
    memset(f, -1, sizeof f);
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    int cnt = 0;
    n = read(), m = read(), Tmax = read();
    for (int i = 1; i <= m; ++i)
      d[i].clear();
    for (int i = 1; i <= n; ++i)
      t[i] = read(), w[i] = read();
    for (int i = 1; i <= m; ++i)
      T[i] = read(), W[i] = read();
    for (int i = 1; i <= m; ++i) {
      int x = 0;
      for (int j = 1; j <= n; ++j)
        x = read(), 
        d[i].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
      a[++cnt] = t[i], b[cnt] = w[i];
    for (int i = 1; i <= m; ++i) {
      a[++cnt] += T[i];
      b[cnt] += W[i];
      for (int j = 1; j <= n; ++j)
        a[cnt] += d[i][j - 1] * t[j];
    }
    f[0] = 0;
    for (int i = 1; i <= cnt; ++i)
      for (int j = 0; j <= Tmax; ++j)
        if (f[j] != -1 && j + a[i] <= Tmax)
          f[j + a[i]] = max(f[j + a[i]], f[j] + b[i]);
    ll ans = 0;
    for (int i = 1; i <= Tmax; ++i)
      ans = max(ans, f[i]);
    cout << ans << endl;
  }
}

