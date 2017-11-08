//
// Created by Margatroid on 2017/8/8.
//

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
const int inf = 2147483647;
struct edge
{
    int f, t, d;
    edge(int f, int t, int d) : f(f), t(t), d(d) {}
};
struct node
{
    int d, u;
    node(int d, int u) : d(d), u(u) {};
    const bool operator<(const node &x) const { return d > x.d; }
};
struct dijkstra
{
    int n, m;
    vector<edge> edges;
    vector<int> g[maxn];
    bitset<maxn> done;
    int d[maxn], p[maxn];
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i <= n; ++i)
            g[i].clear();
        edges.clear();
    }
    void addedge(int f, int t, int d)
    {
        edges.push_back(edge(f, t, d));
        g[f].push_back(edges.size() - 1);
    }
    void dijk(int s)
    {
        priority_queue<node> q;
        for (int i = 1; i <= n; ++i)
            d[i] = inf;
        d[s] = 0;
        for (int i = 1; i <= n; ++i)
            done[i] = 0;
        q.push(node(0, s));
        while (!q.empty())
        {
            node x = q.top();
            q.pop();
            if (done[x.u]) continue;
            done[x.u] = 1;
            for (int i = 0; i < g[x.u].size(); ++i)
            {
                edge l = edges[g[x.u][i]];
                if (d[l.t] > d[l.f] + l.d)
                {
                    d[l.t] = d[l.f] + l.d;
                    p[l.t] = g[x.u][i];
                    q.push(node(d[l.t], l.t));
                }
            }
        }
    }
};