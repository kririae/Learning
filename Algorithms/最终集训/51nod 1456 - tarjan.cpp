#include <bits/stdc++.h>
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

const int N = 1e5 + 5;
int n, m, head[N], ver[N],
    nxt[N], tot, cnt, vis[N], c,
    belong[N], fa[N], s[N], siz[N],
    low[N], dfn[N];
stack<int> st;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline void tarjan(int x) {
  dfn[x] = low[x] = ++cnt;
  st.push(x);
  vis[x] = 1;
  for (int i = head[x]; ~i; i = nxt[i]) {
    int to = ver[i];
    if (!dfn[to]) {
      tarjan(to);
      low[x] = min(low[x], low[to]);
    } else if (vis[to])
      low[x] = min(low[x], dfn[to]);
  }
  if (dfn[x] == low[x]) {
    int u;
    ++c;
    do {
      u = st.top();
      st.pop();
      vis[u] = 0;
      belong[u] = c;
    } while (u != x);
  }
}
int main() {
  memset(head, -1, sizeof head);
  n = io, m = io;
  for (int i = 1, u, v; i <= m; ++i) {
    u = io, v = io;
    addedge(u, v);
  }
  for (int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1;
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= n; ++i)
    for (int j = head[i]; ~j; j = nxt[j]) {
      int to = ver[j],
          x = find(i),
          y = find(to);
      if (x != y) {
        if (belong[i] == belong[to])
          s[x] = 1;
        fa[x] = y;
        s[y] += s[x];
        siz[y] += siz[x];
      }
    }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    find(i);
    if (i == fa[i]) {
      if (s[i])
        ans += siz[i];
      else
        ans += siz[i] - 1;
    }
  }
  io = ans;
}