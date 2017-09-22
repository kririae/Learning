#include <iostream>
#include <cstdio>
using namespace std;
bool chess[15][15];
int n, m;
void search(int x, int y) {
	// x表示行数 y表示列数；
	if()
	if(chess[x - 1][y]) 
}
int main() {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			char c;
			if('1' == c = getchar()) chess[i][j] = true;
			else chess[i][j] = false;
		}
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
