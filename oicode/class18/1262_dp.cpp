#include <iostream>
#include <cstdio>
using namespace std;
int n;
bool mmp[205][205];
int value[205];
int res[205];
int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) 
		cin >> value[i];
	while(true) {
		int xi, yi;
		cin >> xi >> yi;
		if(xi == 0 && yi == 0) break;
		mmp[xi][yi] = true;
	}
	res[n] = value[n];
	for(int i = n - 1; i >= 1; --i) {
		int maxn = 1000000;
		for(int j = i + 1; j <= n; ++j) {
			if(mmp[i][j]) {
				maxn = value[j] + res[j]
			}
		}
	}
	return 0;
}
