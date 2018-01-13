#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	double a, b, c, sum = 0;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		sum += sqrt(a * a + b * b) * 2 / 50 + 1.5 * c;
	}

	sum = ceil(sum);
	cout << sum;
}
