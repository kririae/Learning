#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int n;
	cin >> n;
	int res, max, min;
	cin >> max;
	min = max;

	for(int i = 0; i < n - 1; ++i) {
		cin >> res;

		if(res >= max) max = res;

		if(res <= min) min = res;
	}

	cout << max - min;
	return 0;
}