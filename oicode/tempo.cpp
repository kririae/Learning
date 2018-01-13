#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e3 + 5;
char g[maxn][maxn];
int f, t;
int h, l;
int dx[] {-1, 0, 1, 0};
int dy[] {0, 1, 0, -1};
bool vis[maxn][maxn];
inline void dfs(int x, int y)
{
	if(x >= h || x < 0 | y >= l || y < 0) return;

	if(vis[x][y]) return;

	g[x][y] = t;
	vis[x][y] = true;

	for (int i = 0; i < 4; ++i) {
		auto &curr = g[x + dx[i]][y + gy[i]];

		if(curr == f) {
			dfs(x + dx[i], y + dy[i]);
		}
	}
}
int main()
{

	return 0;
}