#include <bits/stdc++.h>
using namespace std;
int value[1000005] = {0}, pre[1000005] = {0}, fu[1000005] = {0};
int main()
{
	int t;
	cin >> t;

	for (int k = 0; k < t; ++k) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; ++i)
			scanf("%d", &value[i]);

		int maxn = -2000000, minn = 2000000;

		// 从前到后 刷新最小值, 并且计算到当前的最大值
		for (int i = 1; i <= n; ++i) {
			if(minn > value[i]) minn = value[i];

			pre[i] = max(value[i] - minn, pre[i - 1]);
		}

		// 从后到前, 刷最大值, 并且计算当前位置选不选?
		for(int i = n; i >= 1; --i) {
			if(maxn < value[i]) maxn = value[i];

			fu[i] = max(maxn - value[i], fu[i + 1]);
		}

		int profit = 0;

		for(int i = 1; i <= n; ++i)
			profit = max(pre[i] + fu[i], profit);

		printf("%d\n", profit);
		memset(value, 0, sizeof(value));
		memset(pre, 0, sizeof(pre));
		memset(fu, 0, sizeof(fu));
	}

	return 0;
}