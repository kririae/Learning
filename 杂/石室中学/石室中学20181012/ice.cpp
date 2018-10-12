#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1005;
int n, a[N][N], x, y, x2, y2, vis[N], dis[N];
queue<pair<int, int> > q;
inline ll calc(int x, int y) {
  return (x - 1) * n + y;
}
inline int SPFA() {
  memset(dis, 0x3f, sizeof dis);
  q.push(make_pair(x, y));
  vis[calc(x, y)] = 1;
  dis[calc(x, y)] = 0;
  while (!q.empty()) {
    pair<int, int> u = q.front();
    q.pop();
    vis[calc(u.first, u.second)] = 0;
    int i = 0;
    for (i = u.first; i <= n; ++i)
      if (a[i][u.second] == 1) break;
    --i;
    if (i != u.first && dis[calc(i, u.second)] > dis[calc(u.first, u.second)] + 1) {
      dis[calc(i, u.second)] = dis[calc(u.first, u.second)] + 1;
      if (!vis[calc(i, u.second)])
        vis[calc(i, u.second)] = 1,
                    q.push(make_pair(i, u.second));
    }
    for (i = u.first; i >= 1; --i)
      if (a[i][u.second] == 1) break;
    ++i;
    if (i != u.first && dis[calc(i, u.second)] > dis[calc(u.first, u.second)] + 1) {
      dis[calc(i, u.second)] = dis[calc(u.first, u.second)] + 1;
      if (!vis[calc(i, u.second)])
        vis[calc(i, u.second)] = 1,
                    q.push(make_pair(i, u.second));
    }
    for (i = u.second; i <= n; ++i)
      if (a[u.first][i] == 1) break;
    --i;
    if (i != u.second && dis[calc(u.first, i)] > dis[calc(u.first, u.second)] + 1) {
      dis[calc(u.first, i)] = dis[calc(u.first, u.second)] + 1;
      if (!vis[calc(u.first, i)])
        vis[calc(u.first, i)] = 1,
                          q.push(make_pair(u.first, i));
    }
    for (i = u.second; i >= 1; --i)
      if (a[u.first][i] == 1) break;
    ++i;
    if (i != u.second && dis[calc(u.first, i)] > dis[calc(u.first, u.second)] + 1) {
      dis[calc(u.first, i)] = dis[calc(u.first, u.second)] + 1;
      if (!vis[calc(u.first, i)])
        vis[calc(u.first, i)] = 1,
                          q.push(make_pair(u.first, i));
    }
  }
  return dis[calc(x2, y2)];
}
int main() {
  freopen("ice.in", "r", stdin);
  freopen("ice.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      scanf("%d", &a[i][j]);
  scanf("%d%d", &x, &y);
  scanf("%d%d", &x2, &y2);
  if (a[x2 - 1][y2] == 0 && a[x2 + 1][y2] == 0 && a[x2][y2 - 1] == 0 && a[x2][y2 + 1] == 0)
    return cout << "impossible", 0;
  int ret = SPFA();
  if (ret != 0x3f3f3f3f)
    cout << ret;
  else
    cout << "impossible";
}