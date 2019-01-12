#include <bits/stdc++.h>
using namespace std;

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
const int N = 1e6 + 5;
int n, a[N], head[N], ver[N << 2], nxt[N << 2], edge[N << 2];
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot++;
}
int main() {
  memset(head, -1, sizeof head);
  n = read();
  for (int i = 1; i <= n; ++i)
    a[i] = read();
  for (int i = 1; i <= n; ++i) {
    if (i + a[i] + 1 <= n + 1)
      addedge(i, i + a[i] + 1, 0);
    else 
      addedge(i, n + 1, i + a[i] - n);
  }
  printf("%d", dis[n + 1]);
}