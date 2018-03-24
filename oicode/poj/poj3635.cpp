// FULL TANK POJ3635
// 暴力 + DP
#include < bits/stdc++.h > 
using namespace std; 

namespace IO
{
inline char read()
{
    static const int IN_LEN = 1000000;
    static char buf[IN_LEN], *s, *t;
    s == t ? t = (s = buf) +
                    fread(buf, 1, IN_LEN, stdin) : 0;
    return s == t ? -1 : *s++;
}

template <typename T>
inline void read(T &x)
{
    static char c;
    static bool iosig;
    for (c = read(), iosig = false;
            !isdigit(c); c = read())
    {
        if (c == -1) return;
        c == '-' ? iosig = true : 0;
    }
    for (x = 0; isdigit(c);
            c = read())
        x = (x + (x << 2) << 1) + (c ^ '0');
    iosig ? x = -x : 0;
}
}

namespace kririae
{
struct Edge
{
    int from, to, val;
    Edge() {}
    Edge(int f, int t, int v): from(f), to(t), val(v)
    {}
};

struct status
{
    int city, cost, oil;
    bool operator < (const status (&a)) const 
    {
        return cost > a.cost;
    }
};

const int maxn = 1005;
int n, m, p[maxn], u, v, d, b[maxn][maxn], q, c, s, e;
vector<Edge> edges[maxn];
bitset<maxn> vis[maxn];

inline void addedge(int from, int to, int val)
{
    edges[from].push_back(Edge(from, to, val));
    edges[to].push_back(Edge(to, from, val));
}

inline int solve(int c, int s, int e)
{
    priority_queue<status> pq;
    memset(b, 0x3f, sizeof(b));
    for (int i = 1; i <= n; ++i) vis[i].reset(0);
    b[s][0] = 0;

    while(!pq.empty())
    {
        statuc curr = pq.top(); pq.pop();
    }
    return -1;
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
        int res = solve(c, s, e);
        cout << res == -1 ? "impossible" : res << endl;
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