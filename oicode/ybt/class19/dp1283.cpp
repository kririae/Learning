#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct posi {
	int value;
	int a;
	int b;
	posi(): a(1), b(1) {};
};
posi value[20005];
int main()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> value[i].value;

	for(int i = 0; i < n; ++i) {
		int maxn = 0;

		for(int j = 0; j < i; ++j)
			if(value[i].value > value[j].value && maxn < value[j].a)
				maxn = value[j].a;

		value[i].a = maxn + 1;
	}

	for(int i = n - 1; i >= 0; --i) {
		int maxn = 0;

		for(int j = i + 1; j < n; ++j)
			if(value[i].value > value[j].value && maxn < value[j].b)
				maxn = value[j].b;

		value[i].b = maxn + 1;
	}

	int res = 0;

	for(int i = 0; i < n; ++i) {
		if(res < value[i].a + value[i].b) res = value[i].a + value[i].b;
	}

	cout << res - 1;
	return 0;
}
