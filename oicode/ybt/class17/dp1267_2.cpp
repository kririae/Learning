#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	freopen("dp1267.in", "r", stdin);
	int m, n;
	cin >> m >> n;
	bool used[400];
	int value[400];
	memset(value, 0, sizeof(value));
	memset(used, false, sizeof(used));
	used[0] = true;int endx = 0;
	value[0] = 0;
	for(int w, c, i = 1; i <= n; ++i) {
		cin >> w >> c;
		for(int j = endx; j >= 0; --j) {
			if(used[j] && j + w <= m) {
				if(used[j + w]) {
					if(value[j] + c > value[j + w])
						value[j + w] = value[j] + c;
				}
				else {
					used[j + w] = true;
					value[j + w] = value[j] + c;
				}
				if(j + w > endx) endx = j + w;
			}
		}
	}
	int res = 0;
	for(int i = 1; i <= endx; ++i) {
		if(used[i] && value[i] > res) {
			res = value[i];
		}
	}
	cout << res;
	fclose(stdin);
	return 0;
}
