#include <iostream>
#include <cstdio>
#include<cmath>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	int res[m][n], res2[m][n];

	for (int i = 0; i < m; ++i)
		for (int k, j = 0; j < n; ++j) {
			scanf("%d", &k);
			res[i][j] = k;
			res2[i][j] = k;
		}

	for (int k = 1; k < m - 1; ++k) {
		for (int i = 1; i < n - 1; ++i) {
			res[k][i] = round((res2[k - 1][i] + res2[k + 1][i] + res2[k][i - 1] + res2[k][i + 1] + res2[k][i]) / double(5));
		}
	}

	for (int l = 0; l < m; ++l) {
		for (int i = 0; i < n; ++i) {
			cout << res[l][i] << " ";
		}

		cout << endl;
	}

	return 0;
}
