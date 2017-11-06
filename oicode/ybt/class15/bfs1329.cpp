// #define BASIC_VERSION
// #define BASIC_VERSION_PLUS
#define BFS_VERSION
#define DEBUG

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
bool res[1000][1000];

#ifdef DEBUG
void printOut() {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cout << res[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
#endif

#ifdef BASIC_VERSION_PLUS
const int go[4][2] = {{-1,  0},
					  { 1,  0},
					  { 0,  1},
					  { 0, -1}};
void dfs(int x, int y) {
	res[x][y] = false;
	for(int i = 0; i < 3; ++i) 
		if(x + go[i][0] >= 0 && x + go[i][0] <= n - 1 && y + go[i][1] >= 0 && y + go[i][1] <= m - 1) 
			if(res[x + go[i][0]][y + go[i][1]]) dfs(x + go[i][0], y + go[i][1]);
	return;
}
#endif

#ifdef BASIC_VERSION
void dfs(int x, int y) {
	res[x][y] = false;
	// if(x < 0 || y < 0 || x >= n - 1 || y >= m - 1) return;
	if(x >= 1 && res[x - 1][y]) 
		dfs(x - 1, y);
	if(y >= 1 && res[x][y - 1]) 
		dfs(x, y - 1);
	if(x < n - 1 && res[x + 1][y]) 
		dfs(x + 1, y);
	if(y < m - 1 && res[x][y + 1]) 
		dfs(x, y + 1);
	return ;
}
#endif

#ifdef BFS_VERSION
const int go[4][2] = {{-1,  0},
					  { 1,  0},
					  { 0,  1},
					  { 0, -1}};
					  
struct point{ int x; int y;};
point p[10000];
void bfs(int x, int y) {
	int current = 0, processing = 1;
	p[0].x = x; p[0].y = y;
	while(current <= processing) {
		if(res[p[current].x][p[current].y]) {
		// 因为初始化数组的原因，这里采用分散式写法，下一次会使用for循环和打表
		 res[p[current].x][p[current].y] = false;
		 if(p[current].x >= 1 && res[p[current].x - 1][p[current].y]) {
			res[p[current].x - 1][p[current].y] = false;
			p[processing].x = p[current].x - 1;
			p[processing].y = p[current].y;
			++processing;
		 } 
		 if(p[current].x < n - 1 && res[p[current].x + 1][p[current].y]) {
			res[p[current].x + 1][p[current].y] = false;
			p[processing].x = p[current].x + 1;
			p[processing].y = p[current].y;
			++processing;
		 }
		 if(p[current].y >= 1 && res[p[current].x][p[current].y - 1]) {
			res[p[current].x][p[current].y - 1] = false;
			p[processing].x = p[current].x;
			p[processing].y = p[current].y - 1;
			++processing;
		 }
		 if(p[current].y < n - 1 && res[p[current].x][p[current].y + 1]) {
			res[p[current].x][p[current].y + 1] = false;
			p[processing].x = p[current].x;
			p[processing].y = p[current].y + 1;
			++processing;
		 }}
		 ++current;
	}
}
#endif
int main() {
	#ifdef DEBUG
		freopen("bfs1329.in", "r", stdin);
	#endif
	memset(res, false, sizeof(res));
	cin >> n >> m;
	// n 为行 m为列 
	for(int i = 0; i < n; ++i) {
		char c[100];
		scanf("%s", c);
		for(int j = 0; j < m; ++j)
			res[i][j] = (c[j] != '0');
	}
	int summ = 0;
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j) 
			if(res[i][j] == true) {
				summ += 1;
				#ifdef DEBUG
					printOut();
				#endif
				#ifdef BASIC_VERSION || BASIC_VERSION_PLUS
					dfs(i, j);
				#endif
				#ifdef BFS_VERSION
					bfs(i, j);
				#endif
			}
	cout << summ;
	#ifdef DEBUG
		fclose(stdin);
	#endif
	return 0;
}
