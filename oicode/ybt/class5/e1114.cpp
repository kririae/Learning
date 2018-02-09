#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int m;
	cin >> m;
	double a[m];

	for (int i = 0; i < m; ++i) {
		scanf("%lf", &a[i]);
	}

	double t;

	for (int i = 0; i < m; ++i) {
		for (int j = i; j < m; ++j) {
			if(a[i] > a[j]) t = a[j], a[j] = a[i], a[i] = t;
		}
	}

	double sum = 0;

	for (int i = 1; i < m - 1; ++i) {
		sum += a[i];
	}

	sum /= (m - 2);
	double b[m - 2];

	for (int i = 1; i < m - 1; ++i) {
		b[i - 1] = a[i] - sum > 0 ? a[i] - sum : sum - a[i];
	}

	for (int i = 0; i < m - 2; ++i) {
		for (int j = i; j < m - 2; ++j) {
			if(b[i] > b[j]) t = b[j], b[j] = b[i], b[i] = t;
		}
	}

	printf("%.2lf %.2lf", sum, b[m - 3]);
}