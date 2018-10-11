#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct IO {
  char ibuf[1 << 18], *s, *t, obuf[1 << 18], *o, vbuf[65];
  IO() : s(ibuf), t(ibuf), o(obuf) {}
  ~IO() { fwrite(obuf, 1, o - obuf, stdout); }
  inline char gc() {
    (s == t) && (t = (s = ibuf) + fread(ibuf, 1, 1 << 18, stdin));
    return s == t ? 0 : *s++;
  }
  inline void pc(char c) {
    (o == obuf + (1 << 18)) && (fwrite(obuf, 1, 1 << 18, stdout), o = obuf);
    *o++ = c;
  }
  template <typename T>
  operator T() {
    register T r = 0, f = 1;
    register char c = gc();
    for (; !isdigit(c); c = gc()) f = c == '-' ? -1 : 1;
    for (; isdigit(c); c = gc()) r = (((r << 2) + r) << 1) + (c - '0');
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
const int N = 1e5 + 5, M = 1e6 + 5;
int n, m, head[N], ver[N << 1], nxt[N << 1], edge[N << 1], tot, flag = 0;
int op[M], a[M], b[M], c[M];
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
namespace P10 {
inline ll Query(int a, int b) {
  for (int i = head[a], to; ~i; i = nxt[i]) {
    to = ver[i];
    if (to == b) {
      flag = 1;
      return edge[i];
    }
    return min(1ll * edge[i], Query(to, b));
  }
}
}  // namespace P10
namespace P30 {
int fa[N], in[N], dep[N], f[N][30], g[N][30];
inline void init() {
  for (int i = 1; i <= n; ++i) fa[i] = i;
  memset(g, 0x3f, sizeof g);
  memset(in, 0, sizeof in);
}
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void dfs(int x) {
  for (int i = head[x], to; ~i; i = nxt[i])
    if ((to = ver[i]) != f[x][0]) {
      dep[to] = dep[x] + 1;
      f[to][0] = x;
      g[to][0] = edge[i];
      dfs(to);
    }
}
inline ll Query(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int ans = 0x3f3f3f3f;
  dep[0] = -1e9;
  for (int t = 25; t >= 0; --t)
    if (dep[f[x][t]] >= dep[y]) {
      ans = min(ans, g[x][t]);
      x = f[x][t];
    }
  if (x == y) return ans;
  for (int t = 25; t >= 0; --t)
    if (f[x][t] != f[y][t]) {
      ans = min(ans, g[x][t]);
      ans = min(ans, g[y][t]);
      x = f[x][t];
      y = f[y][t];
    }
  ans = min(ans, g[x][0]);
  ans = min(ans, g[y][0]);
  return ans;
}
}  // namespace P30
int main() {
  freopen("money.in", "r", stdin);
  freopen("money.out", "w", stdout);
  memset(head, -1, sizeof head);
  n = io, m = io;
  int flag1 = 0, lastans = 0, qwq = 0;
  for (int i = 1; i <= m; ++i) {
    op[i] = io;
    if (op[i] == 1 && qwq == 0) flag1 = 1, qwq = 1;
    if (flag1 == 1 && op[i] == 0) flag1 = 0;
    if (op[i] == 0)
      a[i] = io, b[i] = io, c[i] = io;
    else
      a[i] = io, b[i] = io;
  }
  if (flag1) {
    P30 ::init();
    int flag2 = 0;
    for (int i = 1; i <= m; ++i) {
      if (op[i] == 0) {
        addedge(b[i], a[i], c[i]);
        ++P30 ::in[a[i]];
        P30::fa[P30 ::find(a[i])] = P30 ::find(b[i]);
      } else {
        if (flag2 == 0) {
          for (int i = 1; i <= n; ++i)
            if (P30 ::in[i] == 0) P30::dfs(i);
          for (int t = 1; t <= 25; ++t)
            for (int i = 1; i <= n; ++i) {
              P30::f[i][t] = P30::f[P30::f[i][t - 1]][t - 1];
              P30::g[i][t] =
                  min(P30::g[i][t - 1], P30::g[P30::f[i][t - 1]][t - 1]);
            }
          flag2 = 1;
        }
        a[i] = (a[i] + lastans) % n + 1;
        b[i] = (b[i] + lastans) % n + 1;
        int x = P30 ::find(a[i]), y = P30 ::find(b[i]);
        if (x == y) {
          lastans = P30::Query(a[i], b[i]);
          if (lastans = 0x3f3f3f3f) lastans = 0;
          io = lastans;
          io = '\n';
        } else {
          lastans = 0;
          io = 0;
          io = '\n';
        }
      }
    }
  } else {
    for (int i = 1; i <= m; ++i) {
      if (op[i] == 0) {
        a[i] = (a[i] + lastans) % n + 1;
        b[i] = (b[i] + lastans) % n + 1;
        c[i] = (c[i] + lastans) % n + 1;
        addedge(a[i], b[i], c[i]);
      } else {
        a[i] = (a[i] + lastans) % n + 1;
        b[i] = (b[i] + lastans) % n + 1;
        flag = 0;
        lastans = P10 ::Query(a[i], b[i]);
        lastans = flag ? lastans : 0;
        io = lastans;
        io = '\n';
      }
    }
    return 0;
  }
}