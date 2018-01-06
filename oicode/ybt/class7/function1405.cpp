#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool prime(int x) {
	double k = sqrt(x);
	bool is_prime = true;

	for(int i = 2; i <= k; ++i)
		if(x % i == 0) is_prime = false;

	return is_prime;
}
int main() {
	int s;
	cin >> s;
	int maxn = 0;

	for (int i = 2; i <= s / 2; ++i) {
		if(prime(i) && prime(s - i))
			if(maxn < i * (s - i))maxn = i * (s - i);
	}

	cout << maxn;
}