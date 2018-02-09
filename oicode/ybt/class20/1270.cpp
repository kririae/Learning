#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int value[205];
bool can[205];
int main()
{
	memset(value, 0, sizeof(value));
	memset(can, false, sizeof(can));
	int m, n;
	cin >> m >> n;
	can[0] = true;

	for(int w, c, p, i = 0; i < n; ++i) {
		cin >> w >> c >> p;

		if(p == 0) p = 0x7f;

		for(int j = m; j >= 0; --j) {
			for(int k = 1; k <= p; ++k) {
				if(j + w * k > m) break;

				if(can[j]) {
					if(can[j + w * k]) {
						value[j + w * k] = max(value[j + w * k], value[j] + c * k);
					} else {
						can[j + w * k] = true;
						value[j + w * k] = value[j] + c * k;
					}
				}
			}
		}
	}

	int maxn = 0;

	for(int i = 0; i <= m; ++i) {
		maxn = max(maxn, value[i]);
	}

	cout << maxn;
}
