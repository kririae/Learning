#include <bits/stdc++.h>

using namespace std;

namespace Blue
{
const int maxn = 1000005;

struct Edge
{
    int from, to, cap, flow;
    Edge() {}
    Edge(int fr, int t, int c, int f):
    from(fr), to(t), cap(c), flow(f) {}
};


int n, m, d, l, ti, a[maxn], cur[maxn], dis[maxn], s, t;
vector<Edge> edges;
vector<int> G[maxn];
bitset<maxn> vis;

inline int read(int &f) {
	char c = getchar();
	int ret = 0; f = 1;
	for (; c < '0' || c > '9'; f = c == '-' ? -1 : 1, c = getchar());
	for (; '0' <= c && c <= '9'; ret = ret * 10 + c - '0', c = getchar());
	ret *= f;
}

//vector<Edge> edges;
//vector<int> G[maxn];
//bool vis[maxn];
//int d[maxn], cur[maxn];

inline void addedge(int from, int to, int cap, int flow)
{
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    int size = edges.size();
    G[from].push_back(size - 2);
    G[to].push_back(size - 1);

}

inline bool BFS()
{
    vis.reset();
    queue<int> Q;
    Q.push(s);
    dis[s] = 0;
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
                dis[e.to] = dis[x] + 1;
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

        if (dis[x] + 1 == dis[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
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

inline void solve()
{
	freopen("blue.in", "r", stdin);
//	read(ti);
	cin >> ti;
	while(ti--) {
		cin >> n >> m >> d >> l;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
	
		for (int j = 1; j <= n && a[j] < d; ++j)
			addedge(0, j, 1, 0);
		
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n && a[j] - a[i] < d; ++j)
				addedge(i, j, 1, 0);
				
		for (int i = n; i >= 0; --i)
			if(l - a[i] >= d) break;
			else addedge(i, n + 1, 1, 0);
	
		int res = maxFlow(0, n + 1);
		if(res > m) cout << "Excited" << " " << res << endl;
		else cout << res << endl;
		memset(a, 0, sizeof(a));
	}
}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	Blue::solve();
	return 0;
}
