#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool used[7000];
int value[7000];
int main() {
	memset(used, false, sizeof(used));
	memset(value, 0, sizeof(value));
	int n, m, maxn = 0;
	used[0] = true;
	value[0] = 0;
	cin >> n >> m;

	for(int v, w, s, i = 0; i < n; ++m) {
		cin >> v >> w >> s;

		for(int j = maxn; j >= 0; --j) {
			for(int k = 1; k <= s; ++k) {
				if(used[j] && v * k + j <= m) {
					if(used[v * k + j]) {
						value[v * k + j] = max(value[v * k + j], value[j] + v * k);
					} else {
						used[v * k + j] = true;
						value[v * k + j] = value[j] + v * k;
					}

					maxn = max(maxn, v * k + j);
				}
			}
		}
	}

	cout << value[m];
}
