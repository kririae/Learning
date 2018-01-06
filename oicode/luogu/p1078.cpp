#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
int n, k, m, s, t;
int coun_cul[maxn];
bool cul_graph[105][105];
int phy_graph[1005][1005] {1e9};

inline void floyd() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if(phy_graph[i][j] > phy_graph[i][k] + phy_graph[k][j]) {
					phy_graph[i][j] = phy_graph[i][k] + phy_graph[k][j]
				}
			}
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k >> m >> s >> t;

	// 国家个数 文化总数 道路条数 起点终点
	for (int i = 1; i <= n; ++i)
		cin >> coun_cul[i];

	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= k; ++j) {
			// i行 第j个数
			int val;
			cin >> val;
			cul_graph[i][j] = val;
		}
	}

	for (register int u, v, d, i = 1; i <= m; ++i) {
		cin >> u >> v >> d;
		phy_graph[u][v] = phy_graph[v][u] = d;
	}

	return 0;
}