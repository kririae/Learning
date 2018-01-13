#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;

	do {
		cout << n % 10 << " ";
		n /= 10;
	} while(n >= 1);

	return 0;
}