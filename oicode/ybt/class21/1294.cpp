#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool v[12885];
int value[12885];
int main()
{
	memset(v, false, sizeof(v));
	memset(value, 0, sizeof(value));
	int n, m;
	cin >> n >> m;
	v[0] = true;

	for (int i = 0; i < n; ++i) {
		int w, c;
		cin >> w >> c;

		for (int k = m; k >= 0; --k) {
			if (k + w > m) continue;

			if (v[k]) {
				v[k + w] = true;
				value[k + w] = max(value[k + w], value[k] + c);
			}
		}
	}

	for (int i = 0; i <= m; ++i) {
		cout << value[i] << " ";
	}

	return 0;
}