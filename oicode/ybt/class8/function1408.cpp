#include "iostream"
#include "cstdio"
#include "cstring"
#include "cmath"
using namespace std;
bool prime(int x)
{
	double k = sqrt(x);
	bool is_prime = true;

	for(int i = 2; i <= k; ++i)
		if(x % i == 0) is_prime = false;

	if(x == 0) return false;
	else {
		return is_prime;
	}
}
bool rev(int x)
{
	if(x < 100) return x % 11 == 0 ? true : false;
	else return x / 100 + x / 10 % 10 * 10 + x % 10 * 100 == x ? true : false;
}
int main()
{
	int n;
	cin >> n;
	int count = 0;

	for (int i = 11; i <= n; ++i) {
		if(prime(i) && rev(i)) count += 1;
	}

	cout << count;
	return 0;
}