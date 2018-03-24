// STATUS: WA
// FULL TANK POJ3635
// 暴力 + DP
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <bitset>

using namespace std; 

namespace IO
{
inline char read()
{
    static const int IN_LEN = 1000000;
    static char buf[IN_LEN], *s, *t;
    s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin) : 0;
    return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
    static char c;
    static bool iosig;
    for (c = read(), iosig = false; !isdigit(c); c = read())
    {
        if (c == -1) return;
        c == '-' ? iosig = true : 0;
    }
    for (x = 0; isdigit(c); c = read()) x = (x + (x << 2) << 1) + (c ^ '0');
    iosig ? x = -x : 0;
}
}

namespace kririae
{
struct Edge
{
    int from, to, val;
    Edge() {}
    Edge(int f, int t, int v): from(f), to(t), val(v) {}
};

struct status
{
    int city, cost, oil; // 当前点在city，花费了cost，剩余油量是oil
    status() {}
    status(int c, int co, int oi): city(c), cost(co), oil(oi) {}
    bool operator < (const status (&a)) const 
    { return cost > a.cost; }
};

const int maxn = 1005;
int n, m, p[maxn], u, v, d, b[maxn][maxn], q, c, s, e;
vector<Edge> edges[maxn];
// bool vis[maxn][maxn];
bitset<maxn> vis[maxn];

inline void addedge(int from, int to, int val)
{
    edges[from].push_back(Edge(from, to, val));
    edges[to].push_back(Edge(to, from, val));
}

inline void solve(int c, int s, int e)
{
    priority_queue<status> pq;
    memset(b, 0x3f, sizeof(b));
    // memset(vis, 0, sizeof(vis));
    for (int i = 0; i <= n; ++i) vis[i].reset();
    b[s][0] = 0;
    
    pq.push(status(s, 0, 0));
    
    while(!pq.empty())
    {
        status curr = pq.top(); pq.pop();
        // cout << curr.city << " " << curr.oil << endl;
        if(vis[curr.city][curr.oil]) continue;
        vis[curr.city][curr.oil] = 1;

        if(curr.city == e) { cout << curr.cost << endl; return; }
        if(curr.oil < c && !vis[curr.city][curr.oil + 1] && b[curr.city][curr.oil] + p[curr.city] < b[curr.city][curr.oil + 1])
        {
            pq.push(status(curr.city, curr.cost + p[curr.city], curr.oil + 1));
            b[curr.city][curr.oil + 1] = b[curr.city][curr.oil] + p[curr.city];
        }

        for (int i = 0; i < edges[curr.city].size(); ++i)
        {
            Edge &e = edges[curr.city][i];
            if(curr.oil >= e.val && !vis[e.to][curr.oil - e.val] && b[e.to][curr.oil - e.val] > curr.cost)
            {
                b[e.to][curr.oil - e.val] = curr.cost;
                pq.push(status(e.to, curr.cost, curr.oil - e.val));
            }
        }
    }
    cout << "impossible" << endl;
}

inline void solve()
{
    using namespace IO;
    read(n); read(m);
    for (int i = 1; i <= n; ++i) read(p[i]);
    for (int i = 1; i <= m; ++i)
    {
        read(u); read(v); read(d);
        addedge(u + 1, v + 1, d);
    }

    read(q);
    for (int i = 1; i <= q; ++i)
    {
        read(c); read(s); read(e);
        ++s, ++e;
        // b[city][fuel] -> 城市编号，剩余油量
        solve(c, s, e);
        // cout << (res == -1 ? "impossible" : res) << endl;
    }
}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    kririae::solve();
    return 0;    
}