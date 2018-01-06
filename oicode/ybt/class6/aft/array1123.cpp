#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int count = 0, m, n;
	cin >> m >> n;
	int j1[m][n];

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> j1[i][j];

	for (int i = 0; i < m; ++i)
		for (int m, j = 0; j < n; ++j) {
			cin >> m;

			if(m == j1[i][j]) count += 1;
		}

	printf("%.2lf", (double(count) / (m * n)) * 100);
	return 0;
}