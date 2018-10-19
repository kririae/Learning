#include <bits/stdc++.h>
using namespace std;

inline char read() {
  static const int IN_LEN = 1000000;
  static char buf[IN_LEN], *s, *t;
  s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
  return s == t ? -1 : *s++;
}
struct InputOutputStream {
  template <typename T>
  inline InputOutputStream &operator>>(T &x) {
    static char c;
    static bool iosig;
    for (c = read(), iosig = false; !isdigit(c); c = read()) {
      if (c == -1) return *this;
      c == '-' ? iosig = true : 0;
    }
    for (x = 0; isdigit(c); c = read()) x = x * 10 + (c ^ '0');
    return iosig ? x = -x : 0, *this;
  }
} io;
const int N = 10005, M = 20005;
int n, m, head[N], ver[M], nxt[M], edge[M], tot, flag, dis[N], cnt[N], vis[N];
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline void SPFA(int x) {
  vis[x] = 1;
  cnt[x] = 1;
  for (int i = head[x]; ~i; i = nxt[i]) {
    int to = ver[i];
    if (dis[to] > dis[x] + edge[i]) {
      if (vis[to]) {
        flag = 1;
        return;
      }
      dis[to] = dis[x] + edge[i];
      SPFA(to);
    }
  }
  vis[x] = 0;
}
int main() {
  memset(head, -1, sizeof head);
  memset(dis, 0x3f, sizeof dis);
  io >> n >> m;
  for (int i = 1, op, a, b, c; i <= m; ++i) {
    io >> op >> a >> b;
    switch (op) {
      case 1:
        io >> c;
        addedge(a, b, -c);
        break;
      case 2:
        io >> c;
        addedge(b, a, c);
        break;
      case 3:
        addedge(b, a, 0);
        addedge(a, b, 0);
        break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!cnt[i]) {
      dis[i] = 0;
      SPFA(i);
      if (flag)
        goto fail;
    }
  }
  cout << "Yes" << endl;
  return 0;
fail:
  cout << "No" << endl;
  return 0;
}