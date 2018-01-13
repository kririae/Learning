#include "cstdio"
#include "iostream"
#include "cstring"
#include "cmath"
using namespace std;
double f(double x, double n)
{
	if(n == 1) return x / (1 + x);

	return x / (n + f(x, n - 1));
}
int main()
{
	double x, n;
	cin >> x >> n;
	printf("%.2lf", f(x, n));
	return 0;
}