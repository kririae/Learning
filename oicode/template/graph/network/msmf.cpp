#include <bits/stdc++.h>
using namespace std;

struct Edge
{
	int from, to, cap, flow, cost;
	Edge() {}
	Edge(int fr, int t, int ca, int fl, int co):
		from(fr), to(t), cap(ca), flow(fl), cost(co) {}
};

const int maxn = 5005;
const int INF = 1e9;
int n, m, s, t;
int u, v, w, f;
vector<Edge> edges;
vector<int> G[maxn];
int inq[maxn]; // 是否在队列中
int d[maxn], p[maxn], a[maxn];
//  bf的数据上一条弧 可改进量

inline void init()
{
	for (int i = 0; i < n; ++i) G[i].clear();

	edges.clear();
}

inline void addedge(int from, int to, int cap,
					int cost)
{
	edges.push_back(Edge(from, to, cap, 0, cost));
	edges.push_back(Edge(from, to, 0, 0, -cost));
	int size = edges.size();
	G[from].push_back(size - 2);
	G[to].push_back(size - 1);
}

// SPFA和DINIC都有利用bfs，这就很臭味相投了
inline bool SPFA(int s, int t, int& flow,
				 int& cost) // 在最短路上增广
{
	for (int i = 0; i < n; ++i) d[i] = INF;

	// 套路的SPFA初始化
	memset(inq, 0, sizeof(inq));
	d[s] = 0;
	inq[s] = true;
	p[s] = 0;
	a[s] = INF;

	queue<int> Q;
	Q.push(s);

	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		inq[u] = false;

		for (int i = 0; i < G[u].size(); ++i)
		{
			Edge& e = edges[G[u][i]];

			// 当且仅当当前边满足最短路的性质（并没有
			// 主要是满足网络流的性质，flow < cap
			if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
			{
				d[e.to] = d[u] +
						  e.cost; // 计算到当前的最短路
				p[e.to] = G[u][i]; // 初始化上一弧，方便往回走
				a[e.to] = min(a[u], e.cap - e.flow);

				// 初始化可改进量数组
				if (!inq[e.to])
				{
					Q.push(e.to);
					inq[e.to] = 1;
				}
			}
		}
	}

	if (d[t] == INF) return false;

	// 修改总值
	flow += a[t];
	cost += d[t] * a[t];
	int u = t;

	// 向前循环修改flow
	while (u != s)
	{
		edges[p[u]].flow += a[t];
		edges[p[u] ^ 1].flow -= a[t];
		u = edges[p[u]].from;
	}

	return true;
}

inline int minCost(int s, int t)
{
	int flow = 0, cost = 0;

	while (SPFA(s, t, flow, cost));

	return cost;
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
	n = read();
	m = read();
	s = read();
	t = read();

	for (int i = 0; i < m; ++i)
	{
		u = read();
		v = read();
		w = read();
		f = read();
		addedge(u, v, w, f);
	}

	cout << minCost(s, t) << endl;
}