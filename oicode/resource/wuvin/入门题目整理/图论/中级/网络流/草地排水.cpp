#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
struct Edge {
	int from, to, flow, cap;
	Edge(int from, int to, int f, int c): from(from), to(to), flow(f), cap(c) {}
};
int n, m, ans; //n¸öµã   mÌõ±ß
vector<Edge> e;
int len;
vector<int> node[205];
int lens[205];
void addedge(int f, int t, int c) //from to cap
{
	e.push_back(Edge(f, t, 0, c));
	node[f].push_back(len++);
	e.push_back(Edge(t, f, 0, 0));
	node[t].push_back(len++);
}
void init()
{
	scanf("%d%d", &m, &n);
	for(int f, t, c, i = 1; i <= m; i++) {
		scanf("%d%d%d", &f, &t, &c);
		addedge(f, t, c);
	}
	for(int i = 1; i <= n; i++) lens[i] = node[i].size();
}
int start = 1;
int end;
int cur[205];
bool vis[205];
int DFS(int u, int flow)
{
	if(u == end || flow == 0) {
		ans += flow;
		return flow;
	}
	int mf = 0;
	vis[u] = true;
	for(int i = cur[u]; i < lens[u]; i++) {
		Edge& a = e[node[u][i]];
		if(a.flow >= a.cap || vis[a.to]) continue;
		int fl = DFS(a.to, min(a.cap - a.flow, flow));
		if(fl) {
			flow -= fl;
			a.flow += fl;
			e[node[u][i] ^ 1].flow -= fl;
			mf += fl;
		}
		if(!flow) return mf;
	}
	return mf;
}
int main()
{
	init();
	end = n;
	bool flag = true;
	while(flag) {
		flag = false;
		memset(cur, 0, sizeof(cur));
		while(DFS(1, 99999999)) {
			flag = true;
			memset(vis, false, sizeof(vis));
		}
	}
	printf("%d", ans);
	return 0;
}
