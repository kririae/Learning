#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int input[1005];
int summ[1005];
int main() {
	memset(summ, 0, sizeof(summ));
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) 
		cin >> input[i];
	summ[0] = input[0];
	for(int i = 0; i < n; ++i) {
		int maxn = 0;
		for(int j = 0; j < i; ++j) {
			if(input[j] < input[i] && maxn < summ[j])
				maxn = summ[j];
		}
		summ[i] = maxn + input[i];
	}
	int result = 0;
	for(int i = 0; i < n; ++i) {
		if(result < summ[i]) result = summ[i];
	}
	cout << result;
	return 0;
}
