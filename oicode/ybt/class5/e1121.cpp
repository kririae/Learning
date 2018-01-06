#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	int res[m][n];
	int sum = 0;

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &res[i][j]);

	for (int i = 0; i < n; ++i)
		sum += res[0][i];

	for (int i = 1; i < m - 1; ++i) {
		sum += (res[i][0] + res[i][n - 1]);
	}

	for (int i = 0; i < n; ++i)
		sum += res[m - 1][i];

	cout << sum;
}