#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int mother = 0, daughter = 0, l;

	for(int i = 1; i <= 12; ++i) {
		cin >> l;
		daughter += 300;

		if(daughter - l >= 100) {
			mother += (daughter - l) / 100 * 100;
			daughter = daughter - (daughter - l) / 100 * 100 - l;
		} else {
			if(daughter - l < 0) {
				cout << -i;
				return 0;
			} else {
				daughter -= l;
			}
		}
	}

	cout << daughter + mother*(1.2);
	return 0;
}