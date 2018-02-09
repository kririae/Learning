#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	vector<int> res;

	for(int value, i = 0; i < n; ++i) {
		cin >> value;
		v.push_back(value);
	}

	int *se = new int[v.size()];

	for(int i = 1; i < v.size(); ++i) {
		int maxn = 0;

		for(int j = 0; j < i; ++j) {
			if(y[j] > maxn && v[i] > v[j]) {
				maxn = y[j];
			}

			y[i] = maxn + 1;
		}
	}

	cout << result;
}
