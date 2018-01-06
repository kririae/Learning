#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool is_prime(int p) {
	bool prime = true;
	int k;
	k = sqrt(p);

	for (int i = 2; i <= k; ++i) {
		if(p % i == 0) prime = false;
	}

	return prime;
}
int main() {
	for (int i = 11; i <= 99; ++i)
		if(is_prime(i) && is_prime(((i / 10) + (i % 10) * 10))) cout << i << endl;
}