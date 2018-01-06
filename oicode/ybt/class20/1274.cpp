#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int f[101][101];
int s[101];
int n, i, j, k, x;
int main() {
	cin >> n;

	for(i = 1; i <= n; ++i) {
		cin >> x;
		s[i] = s[i - 1] + x;
	}

	memset(f, 127 / 3, sizeof(f));

	for(i = 1; i <= n; ++i) {
		f[i][i] = 0;
	}

	for(i = n - 1; i >= 1; --i) {
		for(int j = i + 1; j <= n; ++j) {
			for(k = i; k <= j - 1; ++k) {
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
			}
		}
	}

	cout << f[1][n];
}
