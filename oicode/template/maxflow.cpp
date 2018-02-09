/*
* by kriaeth
* time:
* using template v0.0
* read function by xehoth
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>

namespace solve
{
template<typename T>
inline T min(T a, T b)
{
	return a < b ? a : b;
}

template<typename T>
inline T max(T a, T b)
{
	return a < b ? b : a;
}

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

struct Edge {
	int from, to, cap, flow;

	Edge() {}

	Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {}
}

struct EdmondsKarp
{
	const int maxn = 1e5 + 5;
	const int INF = 1e9;

	int n, m; //n, m
	vector<Edge> edges; // 储存边
	vector<int> G[maxn]; // 邻接表储存[i, j]在e中数组的序号
	int a[maxn]; // 起点到i的可改进量
	int p[maxn]; // 最短路树上p的入弧编号
	// 怎么感觉和我平时的风格有点不一样qwq
	
	inline void init(int n) 
	{
		for (int i = 0; i < n; ++i)
			G[i].clear();

		edges.clear();
	}

	inline void AddEdge(int from, int to, int cap) 
	{
		edges.push_back(Edge(from, to, cap, 0)); // 加正边
		edges.push_back(Edge(to, from, 0, 0)); // 加反向弧
		m = edges.size(); // 当前加了多少条边了
		G[from].push_back(m - 2);
		G[to].push_back(m - 1); // 映射关系建立起
	}

	inline void MaxFlow(int s, int t) 
	{
		int flow = 0;
		for (;;)
		{
			memset(a, 0, sizeof(a));

			queue<int> Q;
			Q.push(s);

			a[s] = INF;

			while(!Q.empty()) 
			{
				int x = Q.front(); Q.pop();
				for (int i = 0; i < Q[x].size(); ++i) 
				{
					Edge &e = edges[G[X][i]];

					if(!a[e.to] && e.cap > e.flow)
					{
						p[e.to] = G[x][i];
						a[e.to] = min(a[x], e.cap - e.flow);

						Q.push(e.to);
					}
				}
				if(a[t]) break;
			}
			if(!a[t]) break;

			for (int u = t; u != s; u = edges[p[u]].from)
			{
				edges[p[u]].flow += a[t];
				edges[p[u] ^ 1] -= a[t];
			}

			flow += a[t];
		}
		return flow;
		/*
		lrj写的有点不明所以...感觉是...
		可能是时代不同，建图方式也有点不一样qwq..
		大概可以重新写一次
		 */
	}

	struct EdmondsKarp_kririae
	{
		const int maxn = 1e5 + 5;
		const int INF = 1e9;

		struct Edge
		{
			int from, to, cap, flow;
			Edge() {}
			Edge(int f, int t, int c, int fl): from(f), to(t), cap(c), flow(fl) {}
		}

		vector<Edge> edges[maxn];

		inline void add_edge(int f, int t, int c) 
		{
			edges[f].push_back(Edge(f, t, c, 0));
			edges[t].push_back(Edge(t, f, 0, 0)); // reverse
		}

		inline void init(int n) 
		{
			for (int i = 0; i < n; ++i) edges[i].clear();
		}

		inline void max_flow(int s, int t)
		{
			
		}
	}

}
inline void init()
{

}

inline void solve()
{

}
}

int main()
{
	solve::solve();
	return 0;
}