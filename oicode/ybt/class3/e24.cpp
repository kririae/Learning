#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double a, b, n, res;
	res = a / b;

	for (int i = 0; i < n; ++i) {
		res *= 10;
	}

	cout << (int)(res) % 10;
	return 0;
}
