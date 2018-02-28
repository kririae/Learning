#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

namespace dinic
{
const int maxn = 10005;
int n, m, s, t;

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
inline int read()
{
    char c = getchar();
    int ret = 0, f = 1;

    for (; !isdigit(c);
         f = c == '-' ? -1 : 1, c = getchar());

    for (; isdigit(c);
         ret = ret * 10 + c - '0', c = getchar());

    return ret * f;
}
int u, v, w;
int main()
{
    using namespace dinic;
    n = read(), m = read(), s = read(), t = read();

    for (int i = 0; i < m; ++i)
    {
        u = read(), v = read(), w = read();
        addedge(u, v, w, 0);
    }

    cout << maxFlow(s, t) << endl;
}