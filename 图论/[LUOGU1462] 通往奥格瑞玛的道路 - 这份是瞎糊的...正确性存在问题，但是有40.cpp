// 动态加点的尝试qwq
/*
加了个类似双hash的东西...?
备注：
修改之后正确性没问题（和双hash一样可能会存在问题
但是WA了...没时间调了
 */
#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 10005;

bitset<maxn> vis;
queue<int> q;
int n, m, b, cnt, f[maxn];
ll dis[maxn], check[maxn];
struct Edge
{
  int from, to, val, _f, rnd;
  Edge(int _fr, int _t, int _v) : 
  from(_fr), to(_t), val(_v), _f(f[_fr]), rnd(1ll * rand() * rand() % 10000000) {}
  inline bool operator < (const Edge &e) const 
  { return _f < e._f; }
};
vector<Edge> edges;
vector<Edge> G[maxn];
pair<ll, ll> ans, pre;

inline void addedge(int from, int to, int val)
{
  edges.push_back(Edge(from, to, val));
  edges.push_back(Edge(to, from, val));
}

inline pair<int, int> insert(const Edge& e)
{
  G[e.from].push_back(Edge(e.from, e.to, e.val));
  G[e.to].push_back(Edge(e.to, e.from, e.val));
  q.push(e.from), q.push(e.to);
  vis[e.from] = vis[e.to] = 1;
  while(!q.empty())
  {
    int curr = q.front();
    q.pop();
    vis[curr] = 0;
    for (R int i = 0; i < G[curr].size(); ++i)
    {
      Edge &qwq = G[curr][i];
      if(dis[qwq.from] + qwq.val < dis[qwq.to])
      {
        dis[qwq.to] = dis[qwq.from] + qwq.val;
        check[qwq.to] = check[qwq.from] + qwq.rnd;
        if(!vis[qwq.to]) vis[qwq.to] = 1, q.push(qwq.to);
      }
    }
  }
  return make_pair(dis[n], check[n]);
}

int main()
{
  srand(time(NULL));
  freopen("testdata.in", "r", stdin);
  memset(dis, 0x3f, sizeof(dis));
  scanf("%d%d%d", &n, &m, &b);
  R int x, y, z;
  for (R int i = 1; i <= n; ++i) scanf("%d", &f[i]);
  for (R int i = 1; i <= n; ++i)
    scanf("%d%d%d", &x, &y, &z), addedge(x, y, z);
  sort(edges.begin(), edges.end());
  q.push(1);
  vis[1] = 1;
  dis[1] = 0;
  for (R int i = 0; i < edges.size(); ++i)
  {
    pre = ans;
    ans = insert(edges[i]);
    // cout << ans.first << endl;
    cout << ans.second << " " << pre.second << endl;
    if(ans.first < b && ans.second != pre.second) 
      return printf("%d %d", b, max(edges[i]._f, f[n])), 0;
  }
  puts("AFK");
}