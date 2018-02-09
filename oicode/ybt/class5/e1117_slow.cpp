#include<iostream>
#include<cstdio>
#include<cmath>
int x[20000];
using namespace std;
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
	}

	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if(x[i] == x[j]) x[j] = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		if(x[i] != 0)cout << x[i] << " ";
	}

	return 0;
}