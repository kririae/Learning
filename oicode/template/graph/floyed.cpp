#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct point {
	double x;
	double y;
} p[101];
double value[101][101];
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y;
	}

	int m;
	cin >> m;
	memset(value, 0x7f, sizeof(value));

	for (int x, y, i = 1; i <= m; ++i) {
		cin >> x >> y;
		value[y][x] = value[x][y] =
		                  sqrt(pow(p[x].x - p[y].x, 2) + pow(p[x].y - p[y].y, 2));
	}

	int s, t;
	cin >> s >> t;

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i != j && i != k && j != k &&
				        value[i][k] + value[k][j] < value[i][j]) {
					value[i][j] = value[i][k] + value[k][j];
				}
			}
		}
	}

	printf("%.2lf", value[s][t]);
	return 0;
}
