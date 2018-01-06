/*
* by kriaeth 2017/11/8 20:09
* lcs
*/
#include <bits/stdc++.h>
using namespace std;
int v[1000][1000] = {0};
int a[1000] = {0};
int b[1000] = {0};
int main() {
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	for(int i = 1; i <= n; ++i)
		cin >> b[i];

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(a[i] == b[j]) {
				v[i][j] = v[i - 1][j - 1] + 1;
			} else {
				v[i][j] = max(v[i - 1][j], v[i][j - 1]);
			}
		}
	}

	cout << v[n][n];
	return 0;
}