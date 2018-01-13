#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int j = 0, y = 0, t = 0, res;

	for(int i = 0; i < n; i++) {
		for(int k = 0; k < 3; k++) {
			cin >> res;

			switch(k) {
			case(0) :
				j += res;
				break;

			case(1) :
				y += res;
				break;

			case(2) :
				t += res;
				break;
			}
		}
	}

	cout << j << " " << y << " " << t << " " << j + y + t;
	return 0;
}