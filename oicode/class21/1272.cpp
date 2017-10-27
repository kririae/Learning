#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool used[1001][1001];
int value[1001][1001];
int main() {
	memset(used, false, sizeof(used));
	memset(value, 0, sizeof(value));
	int n, m, k;
	cin >> n >> m >> k;
	used[0][0] = true;
	for (int i = 0; i < k; ++i) {
		int c, r;
		cin >> c >> r;
		// value代表在[精灵球数量][体力值]时最大的数量
		for (int j = n; j >= 0; --j) {
			for (int k = m; k >= 0; --k) {
				if (j + c > n || k + r >= m) continue;
				if (used[j][k]) {
					if (used[j + c][k + r]) 
						value[j + c][k + r] = max(value[j + c][k + r], value[j][k] + 1);
					else {
						used[j + c][k + r] = true;
						value[j + c][k + r] = value[j][k] + 1;
					}
				}
			}
		}
	}
	int maxn = 0;
	for (int j = 0; j <= n; ++j) 
		for (int k = 0; k <= m; ++k) 
			if (maxn <= value[j][k]) 
				maxn = value[j][k];
	int miny = 10000000;
	for (int j = 0; j <= n; ++j) 
		for (int k = 0; k <= m; ++k) 
			if (value[j][k] == maxn) 
				miny = min(miny, k);
	cout << maxn << " " << m - miny;
	return 0;
}