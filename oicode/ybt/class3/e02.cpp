#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int n;
	cin >> n;
	double p, res;

	for(int i = 0; i <= n - 1; i++) {
		cin >> p;
		res += p;
	}

	printf("%.4lf", res / n);
	return 0;
}