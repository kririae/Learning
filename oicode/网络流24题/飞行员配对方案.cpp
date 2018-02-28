#include <bits/stdc++.h>
using namespace std;
namespace dinic
{
const int maxn = 2005;
int n, m, s, t, e;

struct Edge
{
    int from, to, cap, flow;
    Edge() {}
    Edge(int fr, int t, int c, int f):
        from(fr), to(t), cap(c), flow(f)
    {}
};

vector<Edge> edges;
vector<int> G[maxn];
bool vis[maxn];
int d[maxn], cur[maxn];

inline void init()
{
    for (int i = 0; i < maxn; ++i)
        G[i].clear();
    edges.clear();
    memset(d, 0, sizeof(d));
}
inline void addedge(int from, int to, int cap,
                    int flow)
{
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    int size = edges.size();
    G[from].push_back(size - 2);
    G[to].push_back(size - 1);

}

inline bool BFS()
{
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = true;

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        for (int i = 0; i < G[x].size(); ++i)
        {
            Edge& e = edges[G[x][i]];

            if (!vis[e.to] && e.cap > e.flow)
            {
                vis[e.to] = true;
                d[e.to] = d[x] + 1;
                Q.push(e.to);
            }
        }
    }
    return vis[t];
}

inline int dfs(int x, int a)
{
    if (x == t || a == 0) return a;

    int flow = 0, f;

    for (int& i = cur[x]; i < G[x].size(); ++i)
    {
        Edge& e = edges[G[x][i]];

        if (d[x] + 1 == d[e.to] &&
                       (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
        {
            e.flow += f;
            edges[G[x][i] ^ 1].flow -= f;
            flow += f;
            a -= f;

            if (a == 0) break;
        }
    }

    return flow;
}

int maxFlow(int st, int ed)
{
    s = st, t = ed;
    int flow = 0;
    while (BFS())
    {
        memset(cur, 0, sizeof(cur));
        flow += dfs(st, 1e9);
    }

    return flow;
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
    using namespace dinic;
    int u, v;
	cin >> m >> n;
	s = n + 1;
	t = n + 2;
	while(cin >> u >> v)
	{
	    if(u == -1 && v == -1) break;
		addedge(u, v, 1, 0);
	}
	for (int i = 1; i <= m; ++i)
		addedge(s, i, 1, 0);
	for (int i = m + 1; i <= n; ++i) 
		addedge(i, t, 1, 0);
	int ans = maxFlow(s, t);
	if(ans == 0) {
	    cout << "No Solution!" << endl;
	    return 0;
	}
	cout << ans << endl;
	for (int i = 0; i < edges.size(); i += 2)
	{
	    if(edges[i].flow == 1 &&
        edges[i].from != s &&
        edges[i].to != s &&
        edges[i].from != t &&
        edges[i].to != t)
        cout << edges[i].from << " " << edges[i].to << endl;
	}
	
}