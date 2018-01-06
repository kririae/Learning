#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, val;
	edge(int a, int b) {
		to = a, val = b;
	}
};
const int maxn = 1e4 + 5;
int n, s, dis[maxn][maxn];
int maxs, maxe, maxlength;
int linee[maxn];
vector<edge> graph[maxn];
int pre[maxn];

inline int read() {
	char c;
	int res;

	while(!isspace(c = getchar()) && isdigit(c))
		res = res * 10 + c - '0';

	return res;
}

inline void init() {
	cin >> n >> s;

	for (int i = 0; i <= n + 5; ++i)
		for (int j = 0; j <= n + 5; ++j)
			dis[i][j] = 1e9;

	// n = read(); s = read();
	for (register int i = 0; i < n; ++i) {
		register int a, b, c;
		cin >> a >> b >> c;
		// a = read(), b = read(), c = read();
		dis[a][b] = dis[b][a] = c;
		graph[a].push_back(edge(b, c));
		graph[b].push_back(edge(a, c));
	}
}

inline void floyd() {
	for (register int k = 1; k <= n; ++k)
		for (register int i = 1; i <= n; ++i)
			for (register int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

inline void solve(int ind, int deepth) {
	if(deepth >= maxlength) {

	}

	for (int i = 0; i < graph[ind].size(); ++i) {
		pre[graph[ind][i].to] = ind;
		solve(graph[ind][i].to, deepth + graph[ind][i].val);
	}
}

int main() {
	init();
	floyd();

	for (int i = 1; i <= n; ++i)
		solve(1, 0);

	return 0;
}