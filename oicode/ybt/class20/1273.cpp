#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long value[20000];
bool can[80000];
int main() {
	int n, m;
	cin >> n >> m;
	memset(can, false, sizeof(can));
	memset(value, 0, sizeof(value));
	can[0] = true;
	value[0] = 1;

	for(int v, i = 0; i < n; ++i) {
		cin >> v;

		for(int j = m; j >= 0; --j) {
			if(can[j] && j + v <= m) {
				can[j + v] = true;
				value[j + v] += value[j];
			}
		}
	}

	cout << value[m];
}
