#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
struct Edge {
	int u, v;
} a[N];
int n, m, vis[N], del[N], fg = 0;
vector<int> to[N], ans[2];
inline void addedge(int u, int v) {
	to[u].push_back(v);
	to[v].push_back(u);
}
inline void dfs(int x) {
	ans[0].push_back(x);
	vis[x] = 1;
	for (int i = 0; i < to[x].size(); ++i) {
		if (del[x] && del[to[x][i]]) continue;
		if (!vis[to[x][i]]) 
			dfs(to[x][i]);
	}
}
inline void work() {
	ans[0].clear();
	memset(vis, 0, sizeof vis);
	dfs(1);
	if (ans[0].size() != n) return;
	if (ans[1].size() == 0) {
		for (int i = 0; i < ans[0].size(); ++i)
			ans[1].push_back(ans[0][i]);
		return;
	}
	for (int i = 0; i < ans[0].size(); ++i) {
		if (ans[0][i] > ans[1][i]) return;
		if (ans[0][i] < ans[1][i]) {
			ans[1].clear();
			for (int j = 0; j < ans[0].size(); ++j)
				ans[1].push_back(ans[0][j]);
			return;
		}
	}
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		addedge(u, v);
		a[i].u = u, a[i].v = v;
	}
	for (int i = 1; i <= n; ++i)
		sort(to[i].begin(), to[i].end());
	if (m == n) {
		for (int i = 1; i <= m; ++i) {
			del[a[i].u] = del[a[i].v] = 1;
			work();
			del[a[i].u] = del[a[i].v] = 0;
		}
  } else {
  	dfs(1);
  	for (int i = 0; i < ans[0].size(); ++i)
			cout << ans[0][i] << " ";
		return 0;
  }
	for (int i = 0; i < ans[1].size(); ++i)
		cout << ans[1][i] << " ";
 	return 0;
}
