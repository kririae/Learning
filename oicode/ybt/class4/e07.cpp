#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int n, res1 = 0, res2 = 1;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		res2 *= i;
		res1 += res2;
	}

	cout << res1;
	return 0;
}