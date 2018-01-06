#include <iostream>
#include <cstring>
using namespace std;
bool grap[1005][1005];
int deepth[1005];
int result[1005];
int n = 0, m, posi = 0;
void find(int index) {
	for(int i = 1; i <= n; ++i) {
		if(grap[index][i]) {
			grap[index][i] = grap[i][index] = false;
			find(i);
		}
	}

	result[++posi] = index;
}
int main() {
	memset(result, 0, sizeof(result));
	cin >> m;

	for(int x, y, i = 0; i < m; ++i) {
		cin >> x >> y;
		n = max(n, x);
		n = max(n, y);
		grap[x][y] = grap[y][x] = true;
		++deepth[x];
		++deepth[y];
	}

	int starti = 1;

	for(int i = 1; i <= n; ++i) {
		if(deepth[i] % 2 == 1)
			starti = i;
	}

	find(starti);

	for(int i = 1; i <= posi; ++i) {
		cout << result[i] << endl;
	}
}
