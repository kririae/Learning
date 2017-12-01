#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
#define INF 0x7fffffff
typedef long long LL;
LL start, n, m;
bool vis[MAXN];
LL dis[MAXN];
inline void read(LL &x) {
  x = 0;
  char c = getchar();
  while (!isdigit(c))
    c = getchar();
  while (isdigit(c))
    x = x * 10 + c - '0', c = getchar();
}
struct edge {
  LL to, va;
  edge(LL a, LL b) { to = a, va = b; }
};
vector<edge> v[MAXN];
void add_edge(LL from, LL to, LL va) { v[from].push_back(edge(to, va)); }
void SPFA() {
  queue<LL> q;
  q.push(start);
  vis[start] = 1;
  dis[start] = 0;
  while (!q.empty()) {
    LL now = q.front();
    q.pop();
    vis[now] = 0;
    for (int i = 0; i < v[now].size(); ++i) {
      // cout<<dis[v[now][i].to]<<" "<<dis[now]<<" "<<v[now][i].to<<endl;
      if (dis[v[now][i].to] > dis[now] + v[now][i].va) {
        dis[v[now][i].to] = dis[now] + v[now][i].va;
        if (!vis[v[now][i].to]) {
          q.push(v[now][i].to);
          vis[v[now][i].to] = 1;
        }
      }
    }
  }
}
int main() {
  cin >> n >> m >> start;
  LL a, b, c;
  for (int i = 1; i <= m; ++i) {
    read(a), read(b), read(c);
    add_edge(a, b, c);
  }
  for (int i = 1; i <= n; ++i)
    dis[i] = INF;
  // memset(dis, INF, sizeof(dis));
  // for(int i = 1; i <= 5; ++i) cout<<dis[i]<<" ";
  /*for(int i = 1; i <= n; ++i) {
          for(int j = 0; j < v[i].size(); ++j)
                  printf("%d ", v[i][j].to);
          printf("\n");
  }*/
  SPFA();
  for (int i = 1; i <= n; ++i) {
    cout << dis[i] << " ";
  }
}
