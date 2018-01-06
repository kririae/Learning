#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int a, b, c, count = 0;
	scanf("%d%d%d", &a, &b, &c);

	for (int i = 0; i < double(c) / a; ++i) {
		int x, y;

		if(int((a * i - c) / double(b)) == (a * i - c) / double(b)) count += 1;
	}

	cout << count;
	return 0;
}