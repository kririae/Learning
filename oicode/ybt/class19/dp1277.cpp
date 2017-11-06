#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[15][15];
int value[15][15][15][15];
int main() {
	memset(map, 0, sizeof(map));
	memset(value, 0, sizeof(value));
	int n;
	cin >> n;
	while(true) {
		int xi, yi, v;
		cin >> xi >> yi >> v;
		if(xi == 0 && yi == 0) break;
		map[xi][yi] = v;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int k = 1; k <= n; ++k) {
				for(int l = 1; l <= n; ++l) {
					int list[4] = 
					{
						value[i - 1][j][k - 1][l], value[i][j - 1][k][l - 1],
						value[i - 1][j][k][l - 1], value[i][j - 1][k - 1][l]
					};
					int maxn = 0;
					for(int i = 0; i < 4; ++i) if(maxn < list[i]) maxn = list[i];
					value[i][j][k][l] = maxn + map[k][l];
					if(i != k && j != l) value[i][j][k][l] += map[i][j]; // 如果没有重复，只加其中一个（为了防止重复 
				}
			}
		}
	}
	cout << value[n][n][n][n];
	return 0;
}
