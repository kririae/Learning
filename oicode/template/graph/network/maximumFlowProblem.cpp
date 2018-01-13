#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
const int inf = 1e9;

struct edge {
	int from, to, cap, flow;
	edge(int a, int b, int c, int d):
		from(a), to(b), cap(c), flow(d) {}
};

vector<edge> graph[maxn]; // 表示一条边
vector<int> linkgraph[maxn]; // 表示某两个边在 graph 中的index
int a[maxn]; // 到当前的可改进量
int p[maxn]; // 入弧编号
void init(int n)
{
	for (int i = 0; i < n; ++i) linkgraph[i].clear();

	graph.clear();
}
void addEdge(int from, int to, int cap, int flow)
{
	graph.push_back(edge(from, to, cap, 0));
	graph.push_back(edge(to, from, 0, 0));
	int sizee = graph.size();
	linkgraph[from].push_back(sizee - 2);
	linkgraph[to].push_back(sizee - 1);
}

int maxFlow(int s, int t)
{
	int flow = 0;

	for (;;) {
		memset(a, 0, sizeof(a));
		queue<int> proc;
		proc.push(s);
		a[s] = inf;

		while (!proc.empty()) {
			int curr = proc.front();
			proc.pop();

			for (int i = 0; i < linkgraph[curr].size(); ++i) {
				edge &e = graph[linkgraph[curr][i]];

				if(a[e.to] == 0 && e.cap > e.flow) {
					p[e.to] = linkgraph[curr][i];
					a[e.to] = min(a[curr], e.cap - e.flow);
					proc.push(e.to);
				}
			}

			if(a[t] != 0) break;
		}

		if(a[t] == 0) break;

		for (int u = t; u != s; u = graph[p[u]].from) {
			graph[p[u]].flow += a[t];
			graph[p[u] ^ 1].flow -= a[t];
		}

		flow += a[t];
	}

	return flow;
}

int main()
{

	return 0;
}
