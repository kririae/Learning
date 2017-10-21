#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int input[105];
int summ[105];
int summ2[105];
int main() {
	int k;
	cin >> k;
	for(int v = 0; v < k; ++v) {
		memset(summ, 0, sizeof(summ));
		memset(input, 0, sizeof(input));
		memset(summ2, 0, sizeof(summ2));
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i) 
			cin >> input[i];
		summ[0] = 1;
		summ2[n - 1] = 1;
		for(int i = 0; i < n; ++i) {
			int maxn = 0;
			for(int j = 0; j < i; ++j) {
				if(input[j] > input[i] && maxn < summ[j])
					maxn = summ[j];
			}
			summ[i] = maxn + 1;
		}
		for(int i = 0; i < n; ++i) {
			int maxn = 0;
			for(int j = 0; j < i; ++j) {
				if(input[j] < input[i] && maxn < summ2[j])
					maxn = summ2[j];
			}
			summ2[i] = maxn + 1;
		}
		int result = 0;
		int result2 = 0;
		for(int i = 0; i < n; ++i) {
			if(result2 < summ2[i]) result2 = summ2[i];
			if(result < summ[i]) result = summ[i];
		}	
		cout << max(result, result2) <<endl;
	}
	return 0;
}
