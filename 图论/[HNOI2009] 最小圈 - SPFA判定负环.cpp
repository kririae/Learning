// by kririae
// 咋T了？？？QAQ
#include <bits/stdc++.h>

using namespace std;

const int N = 3005, M = 10005;
const double eps = 1e-9;
int n, m, flag, head[N], ver[M], nxt[M], cnt[N], tot; double dis[N], edge[M];
bitset<N> vis, vis1; queue<int> q;
inline void addedge(int u, int v, double w) 
{
  ver[++tot] = v;
  edge[tot] = w;
  nxt[tot] = head[u];
  head[u] = tot;
}
// inline bool SPFA(int s, double val)
// {
//   while(!q.empty()) q.pop();
//   vis1[s] = 1, vis[s] = 1, q.push(s), dis[s] = 0;
//   while(!q.empty()) {
//     int curr = q.front(); q.pop(), vis[curr] = 0;
//     if(cnt[curr] >= n) return true;
//     for (int i = head[curr]; i; i = nxt[i]) {
//       int to = ver[i]; double v = edge[i] - val;
//       if(dis[to] > dis[curr] + v) {
//         dis[to] = dis[curr] + v, cnt[to] = cnt[curr] + 1;
//         if(!vis[to]) vis[to] = 1, vis1[to] = 1, q.push(to);
//       }}} 
//   return false;
// }
inline void SPFA(int x, double val)
{
  vis[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int to = ver[i]; double v = edge[i] - val;
    if(dis[to] > dis[x] + v) {
      if(vis[to]) {
          flag = 1; break;
      } else dis[to] = dis[x] + v, SPFA(to, val);
    }
  } vis[x] = 0;
}
inline bool judge(double val)
{
  // SPFA判定负环...
  flag = 0, vis.reset(), vis1.reset();
  memset(dis, 0x3f, sizeof(dis)), memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    SPFA(i, val);
    if(flag) return true;
  }
  return false;
}
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int u, v; double w;
  for (int i = 1; i <= m; ++i)
    cin >> u >> v >> w, addedge(u, v, w);
  double l = -1e5, r = 1e5;
  while(fabs(r - l) > eps) {
    double mid = (l + r) / 2;
    if(judge(mid)) r = mid;
    else l = mid;
  } printf("%.8lf", l);
}