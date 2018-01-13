#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int a[n][m], b[n][m];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> b[i][j];

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < m; ++i) {
			cout << a[k][i] + b[k][i] << " ";
		}

		cout << endl;
	}

	return 0;
}