#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
bool used[1005];
int value[1005];
int main() {
	memset(used, false, sizeof(used));
	memset(value, 0, sizeof(value));
	int t, m;
	cin >> t >> m;
	used[0] = true;

	for (int i = 0; i < m; i++) {
		int time, count;
		cin >> time >> count;

		for (int j = t; j >= 0; --j) {
			if (j + time > t)
				continue;

			if (used[j]) {
				if (value[j + time]) {
					value[j + time] = max(value[j + time], value[j] + count);
				} else {
					used[j + time] = true;
					value[j + time] = value[j] + count;
				}
			}
		}
	}

	int maxn = 0;

	for (int i = 0; i <= t; ++i) {
		maxn = max(maxn, value[i]);
	}

	cout << maxn;
	return 0;
}
