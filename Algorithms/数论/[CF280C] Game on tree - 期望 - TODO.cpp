// by kririae
// 史上代码复杂度和分析复杂度差距最大的
// 待理解
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

double ans = 0;
int n, head[maxn], ver[maxn << 1], nxt[maxn << 1], tot, dep[maxn];
inline void addedge(int u, int v)
{
  ver[++tot] = v, nxt[tot] = head[u], head[u] = tot;
}
inline void dfs(int x, int fa)
{
  dep[x] = dep[fa] + 1;
  ans += (1.0 / dep[x]);
  for (int i = head[x]; i; i = nxt[i])
  {
    R int to = ver[i];
    if(to == fa) continue;
    dfs(to, x);
  }
}
int main()
{
  scanf("%d", &n);
  R int a, b;
  for (int i = 1; i < n; ++i)
  {
    scanf("%d%d", &a, &b);
    addedge(a, b), addedge(b, a);
  }
  dfs(1, 0);
  printf("%.6lf", ans);
  return 0;
}