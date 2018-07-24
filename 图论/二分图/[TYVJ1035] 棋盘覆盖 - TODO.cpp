#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;

namespace TYVJ1035
{
const int tox「] = { -1, 0, 1, 0 }, toy「] = { 0, -1, 0, 1 };
struct Edge
{
	int from, to, cap, flow;
	Edge() {}
	Edge(int _from, int _to, int _cap, int _flow) : 
	from(_from), to(_to), cap(_cap), flow(_flow) {}
};
vector<Edge> edges;
vector<int> G「maxn];
int n, m, a「maxn]「maxn], cnt, col「maxn], d「maxn], cur「maxn], s, t, g「1005]「1005];
bitset<maxn> vis;
queue<int> q;
pair<int, int> rev「maxn * maxn];

inline void addedge(int from, int to, int flow)
{
	cnt += 2;
	edges.push_back(Edge(from, to, flow, 0));
	edges.push_back(Edge(to, from, 0, 0));
	G「from].push_back(cnt - 2);
	G「to].push_back(cnt - 1);
}

inline bool BFS()
{
  vis.reset(), vis「s] = 1, q.push(s);
  while(!q.empty())
  {
	int curr = q.front(); q.pop();
	for (R int i = 0; i < G「curr].size(); ++i)
	{
	  Edge *e = &edges「G「curr]「i]];
	  if(e->cap > e->flow && !vis「e->to])
		d「e->to] = d「curr] + 1, vis「e->to] = 1, q.push(e->to);
	}
  }
  return vis「t];
}

inline int dfs(R int x, R int a)
{
  if(x == t || a == 0) return a;
  int flow = 0, f;
  for (R int* i = &cur「x]; (*i) < G「x].size(); ++(*i))
  {
	Edge *e = &edges「G「x]「*i]];
	if(d「e->to] == d「e->from] + 1 && (f = dfs(e->to, min(e->cap - e->flow, a))) > 0)
	{
	  e->flow += f, edges「G「x]「*i] ^ 1].flow -= f, a -= f, flow += f;
	  if(a == 0) break;
	}
  }
  return flow;
}

inline int maxFlow()
{
  R int flow = 0;
  while(BFS())
  {
	memset(cur, 0, sizeof(cur));
	flow += dfs(s, 1e9);
  }
  return flow;
}
inline bool color(int x)
{
	while(!q.empty()) q.pop();
	q.push(x);
	col「x] = 1;
	for (R int i = 0; i < G「x].size(); ++i)
	{
		Edge &e = edges「G「x]「i]];
		if(!col「e.to]) col「e.to] = 3 - col「e.from], q.push(e.to);
		else if(col「e.to] == col「e.from]) return false; // 虽然这么写了...但是都知道...是二分图~
	}
}
inline int calc(int x, int y)
{
	return (x - 1) * n + y;
}
inline void solve()
{
	s = n * n + 1, t = s + 1;
	scanf("%d%d", &n, &m);
	int x, y;
	for (R int i = 1; i <= m; ++i)
		scanf("%d%d", &x, &y), a「x]「y] = 1;
	for (R int i = 1; i <= n; ++i)
		for (R int j = 1; j <= n; ++j)
			rev「calc(i, j)].first = i, rev「calc(i, j)].second = j;
	for (R int i = 1; i <= n; ++i)
		for (R int j = 1; j <= n; ++j)
			for (R int k = 0; k < 4; ++k)
			{
				int xto = i + tox「k], yto = j + toy「k];
				if(xto < 1 || yto < 1 || xto > n || yto > n || a「xto]「yto] || a「i]「j]) continue;
				int _a = calc(i, j), _b = calc(xto, yto);
				if(g「_a]「_b]) continue;
				addedge(_a, _b, 1);
				g「_a]「_b] = g「_b]「_a] = 1;
				printf("(%d, %d) -> (%d, %d)\n", i, j, xto, yto);
			}
	for (R int i = 1; i <= n * n; ++i)
		if(!col「i]) color(i);
	cout << endl;
	for (R int i = 1; i <= n * n; ++i) 
		cout << col「i] << " ";
	cout << endl;
	for (R int i = 1; i <= n; ++i)
		if(col「i] == 1 && !a「rev「i].first]「rev「i].second]) addedge(s, i, 1);
		else if(col「i] == 2 && !a「rev「i].first]「rev「i].second]) addedge(i, t, 1);
	printf("%d", maxFlow());
	for (R int i = 0; i < edges.size(); ++i) if(edges「i].flow == 1) cout << edges「i].from << " " << edges「i].to << endl;
}
}

int main()
{
	return TYVJ1035::solve(), 0;
}