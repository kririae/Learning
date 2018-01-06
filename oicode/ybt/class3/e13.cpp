#include<iostream>
#include<cstdio>

using namespace std;
int main() {
	int a = 1, b = 1, x, res;
	cin >> k;

	for (int i = 3; i <= k; ++i) {
		x = a + b;
		a = x + b;
	}

	cout << a;
}