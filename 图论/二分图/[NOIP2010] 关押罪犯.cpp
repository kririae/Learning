#define R register
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 20005;
struct Edge
{
  int from, to, val;
  Edge() {} 
  Edge(int _f, int _t, int _v) : 
  from(_f), to(_t),val(_v) {}
};
int n, m, head「maxn], ver「maxn << 1], nxt「maxn << 1], cnt,
col「maxn];
// ll edges「maxn << 1];
queue<int> q;
vector<Edge> edges「maxn];

inline void addedge(int u, int v, ll d)
{
  // edges「++cnt] = d, ver「cnt] = v, nxt「cnt] = head「u], head「u] = cnt;
  edges「u].push_back(Edge(u, v, d));
  edges「v].push_back(Edge(v, u, d));
}
inline bool check(ll val)
{
  while(!q.empty()) q.pop();
  memset(col, 0, sizeof(col));
  for (int i = 1; i <= n; ++i) 
    if(col「i] == 0)
    {
      q.push(i); col「i] = 1;
      while(!q.empty())
      {
        int curr = q.front(); q.pop();
        // cout << curr << endl;
        for (int i = 0; i < edges「curr].size(); ++i)
        {
          int to = edges「curr]「i].to, qwq = edges「curr]「i].val;
          if(qwq < val) continue;
          if(col「to] == 0) col「to] = 3 - col「curr], q.push(to);
          else if(col「to] == col「curr]) return false;
        }
      }
    }
  return true;
}

int main()
{
  freopen("testdata.in", "r", stdin);
  scanf("%d%d", &n, &m);
  R ll x, y, z;
  for (R int i = 1; i <= m; ++i)
    scanf("%lld%lld%lld", &x, &y, &z), addedge(x, y, z), addedge(y, x, z);
  ll l = 0, r = 1e5;
  while(l < r - 1)
  {
    ll mid = (l + r) / 2;
    if(check(mid)) r = mid;
    else l = mid;
  }
  printf("%d\n", l);
}