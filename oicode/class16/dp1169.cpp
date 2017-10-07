#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main() {
	int n;
	cin >> n;
	int v[100000];
	int res[100000];
	for(int value, i = 0; i < n; ++i) {
		cin >> value;
		v[i] = value;
	}
	memset(res, 0, sizeof(res));
	res[0] = 1;	
	for(int i = 1; i < n; ++i) {
		int maxn = 0;
		for(int j = 0; j < i; ++j) 
			if(res[j] >= maxn && v[j] >= v[i]) {
				maxn = res[j];
			}	
		res[i] = maxn + 1;
	}
	int max_num = 0;
	for(int i = 0; i < n; ++i) {
		// cout << res[i] << " ";
		if(res[i] > max_num) max_num = res[i];
	}
	cout << max_num;
}
