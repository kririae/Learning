// SPFAver kth shortest path
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

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
	for (x = 0; isdigit(c); c = read())
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
    Edge(int fr, int t, int v): from(fr), to(t), val(v) {}
};

struct status
{
    int from, cost;
    status() {}
    status(int fr, int co):from(fr), cost(co) {}
    bool operator < (const status (&a)) const {
        return cost > a.cost;
    }
};

const int maxn = 1005;
int n, m;
int a, b, v;
int s, t, k;
vector<Edge> edges[maxn];
priority_queue<status> pq; // <dist, x>

inline void addedge(int from, int to, int val)
{
    edges[from].push_back(Edge(from, to, val));
}

inline int SPFA(int s, int t, int k)
{
    pq.push(status(s, 0));

    while(!pq.empty())
    {
        status curr = pq.top(); pq.pop();
        if(curr.from == t) --k;
        if(k == 0) return curr.cost;
        for (int i = 0; i < edges[curr.from].size(); ++i)
        {
            Edge &e = edges[curr.from][i];
            pq.push(status(e.to, curr.cost + e.val));
        }
    }

    return -1;
}

inline void solve()
{
    using namespace IO;
    read(n); read(m);
    for (int i = 1; i <= n; ++i)
    {
        read(a); read(b); read(v);
        addedge(a, b, v);
    }
    read(s); read(t); read(k);
    cout << SPFA(s, t, k) << endl;
}
}

int main()
{
    kririae::solve();
    return 0;
}