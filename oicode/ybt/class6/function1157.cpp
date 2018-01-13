#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool is_prime(int p)
{
	bool prime = true;
	int k;
	k = sqrt(p);

	for (int i = 2; i <= k; ++i)
		if(p % i == 0)
			prime = false;

	return prime;
}
int dc(int p)
{
	int res = p;

	for (int i = 2; i < p; ++i)
		if(is_prime(i) && is_prime(p - i)) {
			res = i;
			break;
		}

	return res;
}
int main()
{
	for (int i = 6; i <= 100; ++i)
		if(i % 2 == 0) printf("%d=%d+%d\n", i, dc(i), i - dc(i));

	return 0;
}