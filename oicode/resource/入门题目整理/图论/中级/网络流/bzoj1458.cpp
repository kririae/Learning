/*
好久没写网络流了
来写个DINIC
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define M 40005
#define N 305
#define INF 0x3f3f3f3f
using namespace std;
//------图论基础-------
struct edge {
	int fr, to, flow;
} e[M];
int elen;
vector<int> node[N];
void addedge(int f, int t, int flow) {
	e[elen++] = (edge) {
		f, t, flow
	};
	node[f].push_back(elen - 1);
	e[elen++] = (edge) {
		t, f, 0
	};
	node[t].push_back(elen - 1);
}
//--------------------
int S, T, size;
int dis[N];
int cur[N];
bool BFS() {
	memset(dis, 0x3f, sizeof(int) * (size + 3));
	dis[S] = 0;
	queue<int> qu;
	qu.push(S);

	while(!qu.empty()) {
		int u = qu.front();
		qu.pop();

		for(int i = 0, len = node[u].size(); i < len; i++) {
			edge &d = e[node[u][i]];

			if(d.flow <= 0 || dis[d.to] != INF) continue;

			dis[d.to] = dis[u] + 1;
			qu.push(d.to);
		}
	}

	return dis[T] != INF;
}
int DFS(int u, int flow) {
	if(u == T || flow == 0) return flow;

	int retflow = 0;

	for(int &i = cur[u], len = node[u].size(); i < len; i++) {
		edge &d = e[node[u][i]];

		if(d.flow == 0 || dis[d.to] != dis[u] + 1) continue;

		int t = DFS(d.to, min(flow, d.flow));
		flow -= t;
		retflow += t;
		d.flow -= t;
		e[node[u][i] ^ 1].flow += t;

		if(!flow) return retflow;
	}

	return retflow;
}
int Dinic(int start, int end, int maxflow) {
	S = start;
	T = end;
	int ret = 0;

	while(BFS()) {
		memset(cur, 0, sizeof(int) * (size + 3));
		ret += DFS(S, maxflow);
	}

	return ret;
}
//--------------------
int n, m, k;
int lim[205];//1-m m+1-m+n
int map[105][105];
int main() {
	int sums = 0, sumt = 0;
	scanf("%d%d%d", &m, &n, &k);

	for(int i = 1; i <= m; i++) {
		scanf("%d", &lim[i]);
		sums += lim[i];
	}

	for(int i = m + 1; i <= m + n; i++) {
		scanf("%d", &lim[i]);
		sumt += lim[i];
	}

	for(int i = 1, xx, yy; i <= k; i++) {
		scanf("%d%d", &xx, &yy);
		map[xx][yy] = 1;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(map[i][j] == 0) addedge(i, j + m, 1);
		}
	}

	int s1 = n + m + 1, t1 = n + m + 2, s2 = n + m + 3, t2 = n + m + 4;
	size = n + m + 4;

	for(int i = 1; i <= m; i++) {
		addedge(s1, i, lim[i]);
		addedge(s2, i, 150);
	}

	for(int i = m + 1; i <= m + n; i++) {
		addedge(i, t1, lim[i]);
		addedge(i, t2, 150);
	}

	addedge(s1, t2, sumt);
	addedge(s2, t1, sums);
	addedge(t2, s2, INF);

	if(Dinic(s1, t1, INF) == sums + sumt) {
		node[t2].pop_back();
		node[s2].pop_back();
		Dinic(t2, s2, INF);
		int ans = 0;

		for(int i = 0, len = node[s2].size(); i < len; i++) {
			ans += e[node[s2][i]].flow;
		}

		ans = 150 * m - ans + sums;
		printf("%d\n", ans);
	} else {
		puts("JIONG!");
	}

	return 0;
}
