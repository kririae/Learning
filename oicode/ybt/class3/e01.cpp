#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int age, sum;
	double res, n;
	sum = 0;
	cin >> n;

	for(int i = 2; i <= n + 1; ++i) {
		cin >> age;
		sum += age;
	}

	res = sum / n;
	printf("%.2lf", res);
}