#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int dist[105] = {0};
	int value[105][105] = {0};

	for (int i, j, k, l = 1; l <= m; ++l) {
		cin >> i >> j >> k;
		value[i][j] = value[j][i] = k;
	}

	for (int i = 1; i <= n; ++i) {

	}
}