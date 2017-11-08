#include <bits/stdc++.h>
using namespace std;
int f[202][202];
int main() {
	int m, n;
	cin >> m >> n;
	for(int i = 1; i <= n; ++i) {
		int w, c;
		cin >> w >> c;
		for(int v = m; v > 0; --v) {
			// 对这个算法详解一下吧... 
			if(w <= v) f[i][v] = max(f[i - 1][v], f[i - 1][v - w] + c);
			else f[i][v] = f[i - 1][v];
		}
	}
	cout << f[n][m];
	return 0;
}
