#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n, count = 0;
	scanf("%d", &n);
	int a[n];

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int num;
	scanf("%d", &num);

	for (int i = 0; i < n; ++i) {
		if(a[i] == num) count += 1;
	}

	cout << count;
	return 0;
}