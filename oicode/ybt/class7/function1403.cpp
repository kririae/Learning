#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool prime(int x)
{
	double k = sqrt(x);
	bool is_prime = true;

	for(int i = 2; i <= k; ++i)
		if(x % i == 0) is_prime = false;

	return is_prime;
}
int main()
{
	int n;
	cin >> n;

	for(int i = 2; i <= n - 2; ++i) {
		if(prime(i) && prime(i + 2)) cout << i << " " << i + 2 << endl;;
	}

	return 0;
}
