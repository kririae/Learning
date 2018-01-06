#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n;
	cin >> n;

	for(int j = 0; j < n; ++j) {
		int r;
		cin >> r;

		if(r == 1) {
			cout << 1;
			return 0;
		}

		if(r == 2) {
			cout << 2;
			return 0;
		}

		int a = 1, b = 2, c, d;

		for(int i = 0; i < r - 2; ++i) {
			d = b;
			c = (2 * b + a) % 32767;
			b = c;
			a = d;
		}

		cout << c << endl;
	}
}
