#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, a[N], head[N], ver[N << 1], 
nxt[N << 1], edge[N << 1], tot, son[N * 31][2], cnt;
inline void addedge(int u, int v, int w) {
  ver[tot] = v;
  nxt[tot] = head[u];
  edge[tot] = w;
  head[u] = tot++;
}
inline void Insert(int x) {
  int u = 0;
  for (int i = 30; i >= 0; --i) {
    int v = (x >> i) & 1;
    if (!son[u][v]) 
      son[u][v] = ++cnt;
    u = son[u][v];
  }
}
inline int Search(int x) {
  int ans = 0, u = 0;
  for (int i = 30; i >= 0; --i) {
    int v = (x >> i) & 1;
    if (son[u][v ^ 1]) v ^= 1;
    ans |= (v << i);
    u = son[u][v];
  }
  return ans;
}
inline void dfs(int x, int fa) {
  for (int i = head[x], to; ~i; i = nxt[i]) {
    if ((to = ver[i]) == fa) continue;
    a[to] = a[x] ^ edge[i];
    dfs(to, x);
  }
}
int main() {
  memset(head, -1, sizeof head);
  scanf("%d", &n);
  for (int i = 1, u, v, w; i < n; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    addedge(u, v, w);
    addedge(v, u, w);
  }
  dfs(1, 0);
  // 然后在a数组中找xor最大值
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    Insert(a[i]);
    res = max(res, a[i] ^ Search(a[i]));
  }
  cout << res;
}