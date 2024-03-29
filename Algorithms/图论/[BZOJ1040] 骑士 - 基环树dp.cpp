// by kririae
#include <bits/stdc++.h>
#define ll long long
#define oo (1 << 30)
using namespace std;

namespace BZOJ1040
{
const int N = 1000005;
int n, a[N], flag, tot, x, y, head[N], ver[N << 1], nxt[N << 1], lim[N << 1];
ll ans = 0, f[N][2]; bitset<N> vis;
inline void addedge(int u, int v) 
{
  nxt[tot] = head[u];
  ver[head[u] = tot++] = v;
}
inline void dp(int x, int fa, int ct)
{
  vis[x] = 1, f[x][0] = 0, f[x][1] = x == ct ? 0 : a[x];
  for (int i = head[x]; ~i; i = nxt[i]) {
    int to = ver[i];
    if(to == fa || lim[i] == 1) continue;
    dp(to, x, ct);
    f[x][0] += max(f[to][1], f[to][0]);
    f[x][1] += f[to][0];
  }
}
inline void round(int x, int fa)
{
  if(flag == 1) return;
  vis[x] = 1; 
  for (int i = head[x]; ~i; i = nxt[i]) {
    int to = ver[i];
    if(to == fa) continue;
    if(vis[to]) {
      lim[i] = lim[i ^ 1] = 1;
      BZOJ1040::x = x, y = to;
      return flag = 1, void();
    } round(to, x);
  }
}
inline void solve()
{
  memset(head, -1, sizeof(head));
  scanf("%d", &n);
  for (int i = 1, b; i <= n; ++i)
    scanf("%d%d", &a[i], &b), addedge(b, i), addedge(i, b);
  for (int i = 1; i <= n; ++i)
    if(!vis[i]) {
      flag = 0, round(i, 0);
      ll tmp = 0;
      dp(x, 0, y); tmp = max(f[x][0], f[x][1]);
      dp(y, 0, x); tmp = max(tmp, max(f[y][0], f[y][1]));
      ans += tmp;
    }
  printf("%lld\n", ans);
} 
}

int main()
{
  return BZOJ1040::solve(), 0;
}