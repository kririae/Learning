#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int n, head[N], ver[N * N], nxt[N * N], tot;
inline void addedge(int u, int v) {
  ver[tot] = v;
  nxt[tot] = head[u];
  head[u] = tot++;
}
inline bool color(int x) {
  for (int i = head[x], to; ~i; i = nxt[i]) {
    to = ver[i];
    if (col[x] == col[to])
      return false;
    col[to] = 3 - col[x];
    if (!color(to)) return false;
  }
  return true;
}
int main() {
  while (~scanf("%d", &n)) {
    int a, b;
    memset(head, -1, sizeof head);
    tot = 0;
    while (scanf("%d%d", &a, &b) && a != 0) {
      addedge(a, b);
      addedge(b, a);
    }
    if (n == 0)
      continue;
    int ans = 1;
    for (int i = 1; i <= n; ++i)
      if (!col[i]) {
        col[i] = 1;
        ans &= color(i);
      }
    printf(ans ? "YES\n" : "NO\n");
  }
}