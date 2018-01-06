#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	bool if_in7;
	int x;
	cin >> x;

	while(x >= 1) {
		if(x % 10 == 7) {
			if_in7 = true;
			break;
		} else {
			x /= 10;
		}
	}

	cout << if_in7;
	return 0;
}
