#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 1005
using namespace std;
char ccc;
int retdr, fh;
inline int read() {
	ccc = getchar();
	fh = 1, retdr = 0;

	while(ccc < '0' || ccc > '9') {
		if(ccc == '-') fh = -1;

		ccc = getchar();
	}

	while(ccc >= '0' && ccc <= '9') retdr = retdr * 10 + ccc - '0', ccc = getchar();

	return retdr * fh;
}
const int INF = 99999999;
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

	for(int &i = cur[u], len = node[u].size(); i < len; i++) { //pay attention to &i
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

int main() {



	return 0;
}
