#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
bool w(int n) {
	int res = 0;

	for (int i = 1; i < n; ++i)
		if(n % i == 0)
			res += i;

	return res == n;
}
int main() {
	int n;
	cin >> n;

	for(int i = 2; i <= n; ++i) {
		if(w(i))cout << i << endl;
	}

	return 0;
}
