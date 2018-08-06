// by kririae
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2005;
struct Edge
{
  int from, to, cap, flow, cost;
  Edge() {}
  Edge(int _fr, int _to, int _ca, int _fl) : 
  from(_fr), to(_to), cap(_ca), flow(_fl) {} 
};
vector<Edge> edges;
vector<int> G[N];
int n, m, d[N], cnt, cur[N], w[N]; queue<int> q; bitset<N> vis;
inline void addedge(int u, int v, int cap, int wei) 
{
  cnt += 2;
  edges.push_back(Edge(u, v, cap, 0));
  edges.push_back(Edge(v, u, 0, 0));
  G[u].push_back(cnt - 2);
  G[v].push_back(cnt - 1);
}
inline bool bfs()
{
  memset(d, 0, sizeof(d));
  q.push(1), vis.reset(), vis[1] = 1;
  while(!q.empty()) {
    int curr = q.front(); q.pop();
    for (int i = 0; i < G[curr].size(); ++i) {
      Edge &e = edges[G[curr][i]];
      if(e.cap > e.flow && !vis[e.to])
        d[e.to] = d[curr] + 1, vis[e.to] = 1, q.push(e.to);
    }} return vis[n];
}
inline ll dfs(int x, int a)
{
  if(x == n || a == 0) return a;
  ll flow = 0, f;
  for (int &i = cur[x]; i < G[x].size(); ++i) {
    Edge &e = edges[G[x][i]];
    if(d[e.to] == d[x] + 1 && (f = dfs(e.to, min(e.cap - e.flow, a))) > 0) {
      e.flow += f, edges[G[x][i] ^ 1].flow -= f, flow += f, a -= f;
      if(a == 0) break;
    }} return flow;
}
inline ll maxflow()
{
  for (int i = 0; i < edges.size(); ++i) edges[i].flow = 0;
  ll flow = 0;
  while(bfs()) {
    flow += dfs(1, 1e9);
    memset(cur, 0, sizeof(cur)); 
  } return flow;
}
int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v, w; i <= m; ++i)
    scanf("%d%d%d", &u, &v, &w[i]), addedge(u, v, 1);
  int ans = 0, pre = 0; cout << (pre = maxflow()) << " ";
  for (int i = 0; i < edges.size(); i += 2) edges[i].cap += 1e6 - 1 + w[(i >> 1) + 1];
  cout << maxflow() - (pre * 1e6) << endl;
}