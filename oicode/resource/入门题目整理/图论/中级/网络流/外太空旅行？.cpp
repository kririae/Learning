#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 305
/*-------------------------------------------------------------------
外太空旅行
最小割模型？
---------------------------------------------------------------------*/
using namespace std;
const int INF = 99;
const int LEFT = 0;
const int RIGHT = 1;
struct edge {
	int from, to, flow; //flow-可用流量  返向弧flow=0
	edge(int from_, int to_, int flow_) {
		from = from_;
		to = to_;
		flow = flow_;
	}
};
vector<edge> e;
int e_len = 0;
vector<int> node[N];
void addedge(int from, int to, int flow) {
	e.push_back(edge(from, to, flow));
	node[from].push_back(e_len++);
	e.push_back(edge(to, from, 0));
	node[to].push_back(e_len++);
}
//-----------------------------边模板-----------------------------------
int S, T;
int dis[N];//分层图
bool BFS() { //分层
	memset(dis, 0, sizeof(dis));
	queue<int> x;
	dis[S] = 1;
	x.push(S);

	while(!x.empty()) {
		int u = x.front();
		x.pop();

		for(int i = 0, len = node[u].size(); i < len; i++) {
			edge& ed = e[node[u][i]];

			if(dis[ed.to] != 0 || ed.flow == 0) continue;

			dis[ed.to] = dis[u] + 1;
			x.push(ed.to);
		}
	}

	if(dis[T] == 0) return false;

	return true;
}

int cur[N];
int DFS(int u, int a) { //多路增广  a-可行流
	if(u == T || a == 0) return a;

	int flow = 0;

	for(int i = cur[u], len = node[u].size(); i < len; i++) {
		edge& ed = e[node[u][i]];

		if(dis[ed.to] != dis[u] + 1 || ed.flow == 0) continue;

		int f = DFS(ed.to, min(a, ed.flow));

		if(f) {
			a -= f;
			flow += f;
			ed.flow -= f;
			e[node[u][i] ^ 1].flow += f;

			if(a == 0) return flow;
		}
	}

	return flow;
}

int Dinic() {
	int maxflow = 0;

	while(BFS()) {
		memset(cur, 0, sizeof(cur));
		maxflow += DFS(S, INF);
	}

	return maxflow;
}
//---------------------------Dinic模板---------------------------------
int c(int x, int side) {
	return x + side * 60;
}
int fri[55][55];
int n;
int main() {
	freopen("1.in", "r", stdin);
	scanf("%d", &n);
	int a, b;

	while(scanf("%d%d", &a, &b) == 2) {
		fri[a][b] = fri[b][a] = 1;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(fri[i][j] == 0) {
				addedge(c(i, LEFT), c(j, RIGHT), INF);
			}
		}
	}

	S = 0;
	T = 200;

	for(int i = 1; i <= n; i++) {
		addedge(S, c(i, LEFT), 1);
		addedge(c(i, RIGHT), T, 1);
	}

	int cost = Dinic();
	printf("%d", n - cost);
}

