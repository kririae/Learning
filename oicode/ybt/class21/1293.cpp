#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int pri[4] = { 10, 20, 50, 100 };
bool used[1005];
int value[1005];
int main()
{
	memset(used, false, sizeof(used));
	memset(value, 0, sizeof(value));
	int n;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	used[0] = true;
	value[0] = 1;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j + pri[i] > n) break; // TODO

			if (used[j]) {
				used[j + pri[i]] = true;
				value[j + pri[i]] += value[j];
			}
		}
	}

	cout << value[n];
	return 0;
}