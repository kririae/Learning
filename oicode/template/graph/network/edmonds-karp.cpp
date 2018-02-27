#include <bits/stdc++.h>
using namespace std;
namespace EdmondsKarp
{
const int inf = 1e9;
const int maxn = 10005;

struct Edge
{
	int from, to, cap, flow;
	Edge() {}
	Edge(int fr, int t, int c, int f):
		from(fr), to(t), cap(c), flow(f)
	{}
};

vector<Edge> edges;
vector<int> link[maxn];
int a[maxn];
int in[maxn];

inline void addedge(int from, int to, int cap,
					int flow)
{
	edges.push_back(Edge(from, to, cap, 0));
	edges.push_back(Edge(to, from, 0, 0));
	int size = edges.size();
	link[from].push_back(size - 2);
	link[to].push_back(size - 1);
}

inline int maxFlow(int s, int t)
{
	int flow = 0;

	for (;;)
	{
		memset(a, 0, sizeof(a));
		queue<int> bfs;
		bfs.push(s);
		a[s] = inf;

		while (!bfs.empty())
		{
			int curr = bfs.front();
			bfs.pop();

			for (int i = 0; i < link[curr].size(); ++i)
			{
				Edge& tempo = edges[link[curr][i]];

				if (a[tempo.to] == 0 && tempo.cap > tempo.flow)
				{
					in[tempo.to] = link[curr][i];
					a[tempo.to] = min(a[curr],
									  tempo.cap - tempo.flow);
					bfs.push(tempo.to);
				}

				if (a[t]) break;
			}
		}
        if(!a[t]) break;
		for (int i = t; i != s; i = edges[in[i]].from)
		{
			edges[in[i]].flow += a[t];
			edges[in[i] ^ 1].flow -= a[t];
		}

		flow += a[t];
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

int n, m, s, t;
int u, v, w;
int main()
{
	using namespace EdmondsKarp;
	n = read(), m = read(), s = read(), t = read();
	for (int i = 0; i < m; ++i)
	{
		u = read(), v = read(), w = read();
		addedge(u, v, w, 0);
	}
	cout << maxFlow(s, t) << endl;
}