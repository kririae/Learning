#include <iostream>
#include <algorithm>
using namespace std;
int t, n, k;
int res[105], poi[105], val[105];
int main()
{
	cin >> t;

	for (int l = 0; l < t; ++l) {
		for (int i = 0; i < 105; ++i)
			res[i] = poi[i] = val[i];

		cin >> n >> k;

		for (int i = 0; i < n; ++i)
			cin >> poi[i];

		for (int i = 0; i < n; ++i)
			cin >> val[i];

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) if (poi[i] - poi[j] > k) {
					res[i] = max(res[i], val[i] + res[j]);
				}
		}
	}

	int maxn = 0;

	for (int i = 0; i < n; ++i)
		maxn = max(res[i], maxn);

	cout << maxn << endl;
}
return 0;
}