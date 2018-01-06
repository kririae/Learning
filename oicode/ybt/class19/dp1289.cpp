#include <iostream>
#include <cstring>
using namespace std;
struct posi {
	int value;
	int a;
	int b;
};
posi value[20005];
int main() {
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i) {
		cin >> value[i].value;
		value[i].a = 1;
		value[i].b = 0;
	}

	for(int i = 1; i <= n; ++i) {
		int maxn = 0;

		for(int j = i; j >= 1; --j) {
			if(value[i].value < value[j].value && value[j].a > maxn) {
				maxn = value[j].a;
				value[i].b = j;
			}
		}

		value[i].a = maxn + 1;
	}

	int result = 0;

	for(int i = 1; i <= n; ++i) {
		if(value[i].a > result) {
			result = value[i].a;
		}
	}

	cout << result;
	return 0;
}
