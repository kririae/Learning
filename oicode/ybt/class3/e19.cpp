#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int count = 0, n, num;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> num;

		if(num % 10 - num / 1000 - num / 10 % 10 - num / 100 % 10 > 0)
			count += 1;
	}

	cout << count;
	return 0;
}