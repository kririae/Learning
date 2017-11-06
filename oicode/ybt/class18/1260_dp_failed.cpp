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
posi value[30005];
int h[30005];
int all = 0;
int main() {
	// freopen("test.in", "r", stdin);
	int indexi = 0, key;
	while(scanf("%d", &key) == 1) {
		++indexi;
		value[indexi].value = key;
		value[indexi].a = 1;
		value[indexi].b = 0;
	}
	int n = indexi;
	for(int i = 1; i <= n; ++i) {
		int maxn = 0;
		for(int j = i - 1; j >= 1; --j) {
			if(value[i].value < value[j].value && value[j].a > maxn) {
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
	cout << result << endl;
	for(int i = 1; i <= n; ++i) {
		int usingnw = 0;
		for(int j = 1; j <= all; ++j) {
			if(h[j] >= value[i].value) {
				if(usingnw == 0) usingnw = j;
				else if(h[j] < h[usingnw]) usingnw = j;
			}
		}
		if(usingnw == 0) {
			++all;
			usingnw = all;
		}
		h[usingnw] = value[i].value;
	}
	cout << all;
	return 0;
}
