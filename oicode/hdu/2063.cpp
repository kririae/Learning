#include <bits/stdc++.h>
using namespace std;
namespace dinic
{
const int maxn = 1005;
int n, m, s, t, k;

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

int main()
{
    using namespace dinic;
    int u, v;
    for (;;) {
        k = read(); 
        if(k == 0) break;
        n = read(); m = read();
        s = n + m + 1;
        t = n + m + 2;
        for (int i = 0; i < k; ++i)
        {
            u = read(); v = read();
            addedge(u, n + v, 1, 0);
        }
        for (int i = 1; i <= n; ++i)
            addedge(s, i, 1, 0);
        for (int i = n + 1; i <= n + m; ++i) 
            addedge(i, t, 1, 0);
        cout << maxFlow(s, t) << endl;
        init();
    }
}
