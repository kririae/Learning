#include <bits/stdc++.h>
using namespace std;

struct Edge
{
	int from, to, cap, flow, cost;
	Edge() {}
	Edge(int fr, int t, int ca, int fl, int co):
	from(fr), to(t), cap(ca), flow(fl), cost(co) {}
};

int n, m, s, t;
vector<Edge> edges;
vector<int> G[maxn];
int inq[maxn]; // 是否在队列中
int d[maxn], p[maxn], a[maxn];
//  bf       上一条弧 可改进量

inline void init()
{
	for (int i = 0; i < n; ++i) g[i].clear();
	edges.clear();
}

inline void addedge(int from, int to, int cap, int cost)
{
	
}
int main()
{
	
	return 0;
}