// BZOJ3829
// by kririae
/*
tijie ver
po姐的解法...和讲题时候讲的相同...这种相对难理解一些
嗯...咕咕咕着？
 */
#include <bits/stdc++.h>

using namespace std;

const int maxn = 500005;
namespace BZOJ3829
{
int n, a[maxn], cnt, s[maxn], d[maxn], f[maxn];
int head[maxn], ver[maxn << 1], next[maxn << 1], tot;
inline void addedge(int u, int v)
{
  ver[++tot] = v, next[tot] = head[u], head[u] = tot;
}
inline bool cmp(int x, int y)
{
  return f[x] - d[x] > f[y] - d[y];
}
inline void dp(int x, int fa)
{
  for (int i = head[x]; i; i = next[i])
    if(ver[i] != fa) dp(ver[i], x);
  cnt = 0;
  for (int i = head[x]; i; i = next[i]) {
    int to = ver[i];
    if(to == fa) continue;
    d[to] += 2;
    f[to] = max(f[to] + 1, d[to]);
    a[++cnt] = to;
  }
  sort(a + 1, a + 1 + cnt, cmp);
  f[x] = s[x];
  for (int i = 1; i <= cnt; ++i) {
    f[x] = max(f[x], d[x] + f[a[i]]);
    d[x] += d[a[i]];
  }
}
inline void solve()
{
  scanf("%d", &n);
  int x, y;
  for (int i = 1; i <= n; ++i)
      scanf("%d", &s[i]);
  for (int i = 1; i < n; ++i)
    scanf("%d%d", &x, &y),
    addedge(x, y), addedge(y, x);
  dp(1, 0);
  // 额外的安装1的时间
  printf("%d", max(f[1], d[1] + s[1]));
}
}

int main()
{
  return BZOJ3829::solve(), 0;
}