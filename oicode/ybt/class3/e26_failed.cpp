#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int a, b, k = 0, res, i;
	cin >> a >> b;

	if(b >= 2) {
		for(i = 2; i <= b; i++) {
			if(b % i == 0) {
				k = i;
			}
		}
	} else {
		k = b;
	}

	if(i > b) k = 1;

	res = pow(a, k);

	switch(res % 7) {
	case(0):
		cout << "Sunday";
		break;

	case(1):
		cout << "Monday";
		break;

	case(2):
		cout << "Tuesday";
		break;

	case(3):
		cout << "Wednesday";
		break;

	case(4):
		cout << "Thursday";
		break;

	case(5):
		cout << "Friday";
		break;

	case(6):
		cout << "Saturday";
		break;
	}

	return 0;
}