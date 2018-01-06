#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int a, b, c, x;
	cin >> a >> b >> c;

	//第一个方法qwq
	for(int i = 2; i < a || i < b || i < c; i++) {
		if(a % i == b % i && b % i == c % i) {
			x = i;
			break;
		}
	}

	cout << x;
	return 0;
}
