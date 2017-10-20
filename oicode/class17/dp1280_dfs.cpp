#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int r, c, md = 0;
const int go[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int map[105][105];
int xxx[105][105];
int dfs(int x, int y) {
	int xmax = 0;
	for(int i = 0; i < 4; ++i) {
		int go_x = x + go[i][0];
		int go_y = y + go[i][1];
		if(go_x <= 0 || go_y <= 0 || go_x > r || go_y > c) continue;
		if(map[go_x][go_y] >= map[x][y]) continue; 
		if(xxx[go_x][go_y] == 0)
			dfs(go_x, go_y);
		if(xxx[go_x][go_y] > xmax) xmax = xxx[go_x][go_y];
	}
	xxx[x][y] = xmax + 1;
	return xxx[x][y];
}
int main() {
	memset(map, 0, sizeof(map));
	memset(xxx, 0, sizeof(xxx));
	cin >> r >> c;
	int maxn = 0;
	for(int i = 1; i <= r; ++i) 
		for(int j = 1; j <= c; ++j) {
			cin >> map[i][j];
			if(map[i][j] > maxn) {
				maxn = map[i][j];
			}
		}
	for(int i = 1; i <= r; ++i) {
		for(int j = 1; j <= c; ++j) {
			if(xxx[i][j] == 0)
				dfs(i, j);
		}
	}
	int ans = 0;
	for(int i = 1; i <= r; ++i) 
		for(int j = 1; j <= c; ++j) 
			if(xxx[i][j] > ans) ans = xxx[i][j];
	cout << ans;
	return 0;
}
