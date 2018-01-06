#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int n = 0, res = 0;
	int wzs = 0, ls = 0, day, totalday = 0, count = 0;
	cin >> day;

	while(totalday < day) {
		++ls;
		totalday += ls;
	}

	for(int i = 1; i <= ls; ++i) {
		wzs += i * i;
	}

	cout << wzs - ls*(totalday - day);
	return 0;
}