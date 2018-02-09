#include <iostream>
#include <cstring>
using namespace std;
int value[6000];
bool can[6000];
int main()
{
	memset(value, 0, sizeof(value));
	memset(can, false, sizeof(can));
	int n, m;
	cin >> n >> m;
	can[0] = true;

	for(int v, w, s, i = 0; i < n; ++i) {
		cin >> v >> w >> s;

		// k是该奖品的数目
		// v是该奖品的价格
		// w是该奖品的价值
		// value表示在花费某价格下最大的价值
		// can表示该值可取
		for(int j = m; j >= 0; --j) {
			for(int k = 1; k <= s; ++k) {
				if(j + k * v > m) break;

				if(can[j]) {
					if(can[j + k * v]) {
						value[j + k * v] = max(value[j + k * v], value[j] + w * k);
					} else {
						can[j + k * v] = true;
						value[j + k * v] = value[j] + w * k;
					}
				}
			}
		}
	}

	int maxn = 0;

	for(int i = 0; i <= m; ++i)
		maxn = max(value[i], maxn);

	cout << maxn;
}
