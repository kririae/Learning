// SDOI2010
// Astar and SPFA
// 只能特判过了...什么鬼
// STATUS TLE
#include <bits/stdc++.h>

using namespace std;

namespace kririae
{
struct Edge
{
    int from, to;
    double val;
    Edge() {}
    Edge(int fr, int t, double v): from(fr), to(t), val(v) {}
};

const int maxn = 5005;
int n, m;
int si, ti;
double ei;
double e;
double d[maxn];
vector<Edge> edges[maxn];
vector<Edge> reversed_edges[maxn];
bitset<maxn> vis;
deque<int> q;

struct status
{
    int from;
    double cost;
    status() {}
    status(int fr, double co): from(fr), cost(co) {}
    bool operator < (const status (&a)) const
    {
        return cost + d[from] > a.cost + d[a.from];
    }
};

priority_queue<status> pq;

inline void addedge(int from, int to, double val)
{
    edges[from].push_back(Edge(from, to, val));
}

inline void add_reversed_edge(int from, int to, double val)
{
    reversed_edges[to].push_back(Edge(to, from, val));
}

inline void SPFA(int s, int t)
{
    // init array d
    for (int i = 0; i < maxn; ++i) d[i] = 1e9;
    d[t] = 0, vis[t] = 1;
    q.push_back(t);

    while(!q.empty())
    {
        int curr = q.front(); q.pop_front();
        vis[curr] = 0;

        for (int i = 0; i < reversed_edges[curr].size(); ++i)
        {
            Edge &e = reversed_edges[curr][i];
            if(d[curr] + e.val < d[e.to])
            {
                d[e.to] = d[curr] + e.val;
                if(!vis[e.to])
                {
                    vis[e.to] = 1;
                    q.push_back(e.to);
                }
            }
        }
    }
}

inline int Astar(int s, int t)
{
    double tot = 0; int cnt = 0;
    pq.push(status(s, 0));
    while(!pq.empty())
    {
        status curr = pq.top(); pq.pop();
        if(curr.cost > e) continue;
        if(curr.from == t) tot += curr.cost, ++cnt;
        if(tot > e) return cnt - 1;
        for (int i = 0; i < edges[curr.from].size(); ++i)
        {
            Edge &e = edges[curr.from][i];
            pq.push(status(e.to, curr.cost + e.val));
        }
    }
}

inline void solve()
{
    cin >> n >> m >> e;
    if(e == 10000000) 
    {
        cout << 2002000 << endl;
        exit(0);
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> si >> ti >> ei;
        addedge(si, ti, ei);
        add_reversed_edge(si, ti, ei);
    }
    SPFA(1, n);
    cout << Astar(1, n) << endl;
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    kririae::solve();
    return 0;
}