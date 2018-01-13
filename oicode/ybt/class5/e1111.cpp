#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	int a[7];
	int x, y;
	int b[7];

	for (int i = 0; i < 7; ++i) {
		scanf("%d%d", &x, &y);
		a[i] = x + y;
		b[i] = x + y;
	}

	bool if_unhapppy = false;
	int t;

	for (int i = 0; i < 7; ++i) {
		if(a[i] > 8) if_unhapppy = true;
	}

	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			if(a[i] > a[j]) t = a[j], a[j] = a[i], a[i] = t;
		}
	}

	if(if_unhapppy) {
		int maxn = a[0];

		for (int i = 0; i < 7; ++i) {
			if(b[i] == maxn) {
				cout << i + 1;
				break;
			}
		}
	} else {
		cout << 0;
	}
}