#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int m, n, sum = 0;
	cin >> m >> n;
	m = m % 2 == 0 ? m + 1 : m;

	for(m; m <= n; m += 2) {
		sum += m;
	}

	cout << sum;
	return 0;
}