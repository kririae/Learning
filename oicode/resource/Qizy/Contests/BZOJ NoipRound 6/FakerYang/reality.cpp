#include <cctype>
#include <cstdio>
#include <algorithm>

const int N = 2000000 + 10;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n;
int adj[N], to[N], next[N];

void link(int a, int b) {
  static int cnt = 1;
  to[cnt] = b;
  next[cnt] = adj[a];
  adj[a] = cnt++;
}

int pre[N], e[N];

int tag[N];

bool found;

bool on[N];
int cycle[N], tot;

void dfs(int a) {
  tag[a] = 1;
  for (int i = adj[a]; i && !found; i = next[i]) {
    int b = to[i];
    if (tag[b] == -1) continue;
    pre[b] = a;
    e[b] = i;
    if (tag[b]) {
      found = true;
      cycle[tot = 1] = b;
      for (int j = a; j != b; j = pre[j]) cycle[++tot] = j;
      std::reverse(cycle + 2, cycle + tot + 1);
    } else {
      dfs(b);
    }
  }
  tag[a] = -1;
}

int q[N];

bool toposort() {
  static int deg[N];
  std::fill(deg + 1, deg + 2 * n + 1, 0);
  for (int a = 1; a <= 2 * n; ++a)
    for (int i = adj[a]; i; i = next[i])
      if (!on[i]) ++deg[to[i]];
  int r = 0;
  for (int i = 1; i <= 2 * n; ++i) if (!deg[i]) q[++r] = i;
  for (int f = 1; f <= r; ++f) {
    int a = q[f];
    for (int i = adj[a]; i; i = next[i]) {
      if (on[i]) continue;
      int b = to[i];
      if (--deg[b] == 0) q[++r] = b;
    }
  }
  return r == 2 * n;
}

int main() {
	freopen("reality.in","r",stdin);
	freopen("reality.out","w",stdout); 
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) link(i, i + n);
  while (m--) {
    int a = nextInt(), b = nextInt();
    link(a + n, b);
  }
  for (int i = 1; i <= 2 * n && !found; ++i) if (!tag[i]) dfs(i);
  if (!found) {
    printf("%d\n", n);
    for (int i = 1; i <= n; ++i) printf("%d%c", i, " \n"[i == n]);
    return 0;
  }
  for (int i = 1; i <= tot; ++i) on[e[cycle[i]]] = true;
  if (!toposort()) return puts("0"), 0;
  static int left[N], right[N];
  for (int i = 1; i <= tot; ++i) left[cycle[i]] = right[cycle[i]] = i;
  for (int i = 2 * n; i > 0; --i) {
    int a = q[i];
    if (!left[a]) left[a] = N;
    for (int j = adj[a]; j; j = next[j])
      if (!on[j]) left[a] = std::min(left[a], left[to[j]]);
  }
  for (int i = 1; i <= 2 * n; ++i) {
    int a = q[i];
    if (!right[a]) right[a] = -N;
    for (int j = adj[a]; j; j = next[j])
      if (!on[j]) right[to[j]] = std::max(right[to[j]], right[a]);
  }
  static bool mark[N];
  for (int i = 1; i <= tot; ++i) {
    int a = cycle[i];
    if (left[a] < i) {
      for (int j = i + 1; j <= tot; ++j) mark[e[cycle[j]]] = true;
      mark[e[cycle[1]]] = true;
      break;
    }
  }
  for (int i = tot; i > 0; --i) {
    int a = cycle[i];
    if (right[a] > i) {
      for (int j = i; j > 1; --j) mark[e[cycle[j]]] = true;
      break;
    }
  }
  std::fill(right + 1, right + 2 * n + 1, 0);
  for (int i = 1; i <= tot; ++i) right[cycle[i]] = i;
  for (int i = 2 * n; i > 0; --i) {
    int a = q[i];
    if (!right[a]) right[a] = -N;
    for (int j = adj[a]; j; j = next[j])
      if (!on[j]) right[a] = std::max(right[a], right[to[j]]);
  }
  for (int i = 1, j = 0; i <= tot; ++i) {
    int a = cycle[i];
    for (j = std::max(j, i + 1); j <= right[a]; ++j) mark[e[cycle[j]]] = true;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) if (on[i] && !mark[i]) ++ans;
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) if (on[i] && !mark[i]) printf("%d ", i);
  return 0;
}
