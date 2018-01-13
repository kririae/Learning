#include <iostream>
using namespace std;
int main()
{
	bool used[20005];
	int v, n;
	cin >> v >> n;
	int maxn = 0;
	used[0] = true;
	int k = 0;

	for(int value, i = 0; i < n; ++i) {
		cin >> value;

		for(int j = k; j >= 0; --j) {
			if(used[j] && j + value <= v) {
				used[j + value] = true;

				if(j + value > k) k = j + value;
			}
		}
	}

	cout << v - k;
	return 0;
}
