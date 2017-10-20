// memory search;
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int r;
int lines[1005][1005];
int memo[1005][1005];
int dfs(int x, int y) {
	if(memo[x][y] == -1) {
		if(x == r) memo[x][y] = lines[x][y];
		else memo[x][y] = lines[x][y] + max(dfs(x + 1, y), dfs(x + 1, y + 1));
	}
	return memo[x][y];
}
int main() {
	memset(memo, -1, sizeof(memo));
	memset(lines, 0, sizeof(lines));
	cin >> r;
	for(int i = 1; i <= r; ++i) 
		for(int j = 1; j <= i; ++j) 
			cin >> lines[i][j];
	dfs(1, 1);
	cout << memo[1][1];
	return 0;
}
