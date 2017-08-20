#include <cstdio>
#include <iostream>
using namespace std;
double hermite(double n,double x) {
	if(n == 0) return 1.0;
	if(n == 1) return x * 2.0;
	if(n > 1) return 2.0 * x * hermite(n - 1,x) - 2.0 * (n - 1) * hermite(n - 2,x);
}
int main()
{
	int n,x;
	cin>>n>>x;
	printf("%.2lf", hermite(n,x));
	return 0;
}
