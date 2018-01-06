#include <bits/stdc++.h>
long long a[101] = {0}, b[101] = {0};
int main() {
	int x, y, z;
	std::cin >> x >> y >> z;

	for(int i = 1; i <= x; ++i) {
		a[i] = 1;
		b[i] = 0;
	}

	for(int i = x + 1; i <= z + 1; ++i) {
		b[i] = y * a[i - x];
		a[i] = a[i - 1] + b[i - 2];
	}

	std::cout << a[z + 1] << endl;
}