#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
struct posi {
	int value;
	int a;
	int b;
};
vector<int> res;
posi value[20005];
int main() {
	freopen("test.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i) {
		cin >> value[i].value;
		value[i].a = 1;
		value[i].b = 0;
	}

	for(int i = 1; i <= n; ++i) {
		int maxn = 0;

		for(int j = i - 1; j >= 1; --j) {
			if(value[i].value >= value[j].value && value[j].a > maxn) {
				maxn = value[j].a;
				value[i].b = j;
			}
		}

		value[i].a = maxn + 1;
	}

	int result = 0;
	int max_index = 0;

	for(int i = 1; i <= n; ++i)
		if(value[i].a > result) {
			result = value[i].a;
			max_index = i;
		}

	cout << "maxn=" << result << endl;

	while(max_index >= 1) {
		res.push_back(value[max_index].value);
		max_index = value[max_index].b;
	}

	for(int i = res.size() - 1; i >= 0; --i)
		cout << res[i] << " ";

	fclose(stdin);
	return 0;
}
