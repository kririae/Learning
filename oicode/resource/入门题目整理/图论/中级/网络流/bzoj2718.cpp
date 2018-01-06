#include<bits/stdc++.h>
#define N 505
using namespace std;
const int INF = 9999999;
struct edge {
	int next, to, flow; //flow-可用流量  返向弧flow=0
};
edge e[400005];
int e_len = 1;
int head[N];
void addedge(int from, int to, int flow) {
	e[++e_len] = (edge) {
		head[from], to, flow
	};
	head[from] = e_len;
	e[++e_len] = (edge) {
		head[to], from, 0
	};
	head[to] = e_len;
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

		for(int i = head[u]; i; i = e[i].next) {
			edge& ed = e[i];

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

	for(int &i = cur[u]; i; i = e[i].next) {
		edge& ed = e[i];

		if(dis[ed.to] != dis[u] + 1 || ed.flow == 0) continue;

		int f = DFS(ed.to, min(a, ed.flow));

		if(f) {
			a -= f;
			flow += f;
			ed.flow -= f;
			e[i ^ 1].flow += f;

			if(a == 0) return flow;
		}
	}

	return flow;
}
int Dinic() {
	int maxflow = 0;

	while(BFS()) {
		for(int i = 0; i <= 500; i++) cur[i] = head[i];

		maxflow += DFS(S, INF);
	}

	return maxflow;
}
int n, m;
int c(int x, int side) { //side 0-1
	return x + side * (n + 1);
}
/*
要用floyd传递闭包
详见某个已保存网页
*/
bitset<N> d[N];
int main() {
	scanf("%d%d", &n, &m);
	S = 0;
	T = n + 1;

	for(int f, t, i = 1; i <= m; i++) {
		scanf("%d%d", &f, &t);
		d[f][t] = 1;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(d[j][i]) d[j] |= d[i]; //注意有向
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(d[i][j]) addedge(c(i, 0), c(j, 1), 1);
		}
	}

	for(int i = 1; i <= n; i++) {
		addedge(S, c(i, 0), 1);
		addedge(c(i, 1), T, 1);
	}

	int a = Dinic();
	int ans = n - a;
	printf("%d", ans);
	return 0;
}
