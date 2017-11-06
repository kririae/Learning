#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000;
int g[maxn][maxn];
int deepth[maxn];
int result[maxn];
int n, m, position;
void find(int i) {
	for(int j = 1; j <= n; ++j) {
		if(g[i][j] == 1) {
			g[i][j] = g[j][i] = 0;
			find(j);
		}
	}
	++position;
	result[position] = i;
} 
int main() {
	memset(g, 0, sizeof(g));
	memset(deepth, 0, sizeof(deepth));
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y; 
		g[x][y] = g[y][x] = 1;
		++deepth[x];
		++deepth[y];
	} 
	int start_position = 1;
		position = 0;
	for(int i = 1; i <= n; ++i) {
		if(deepth[i] % 2== 1)
			start_position = i;
	}
	find(start_position);

	for(int i = 1; i <= position; ++i) {
		cout << result[i] << " ";
	}
}

