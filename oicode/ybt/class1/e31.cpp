#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n, e;
	double x, y;
	cin >> n >> x >> y;
	printf("%d", (int)(n - y / x));
	return 0;
}