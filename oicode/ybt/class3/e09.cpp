#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int k, c1 = 0, c5 = 0, c10 = 0, res;
	cin >> k;

	for (int i = 0; i < k; ++i) {
		cin >> res;

		switch(res) {
		case 1:
			c1 += 1;
			break;

		case 5:
			c5 += 1;
			break;

		case 10:
			c10 += 1;
			break;
		}
	}

	cout << c1 << endl << c5 << endl << c10;
	return 0;
}