#include <iostream>
#include <cstdio>
using namespace std;
int sum(int x)
{
	if(x == 1) return 1;

	return x + sum(x - 1);
}
int main()
{
	int res;
	cin >> res;
	cout << sum(res);
	return 0;
}
