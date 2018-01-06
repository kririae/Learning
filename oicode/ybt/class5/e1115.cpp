#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	int b[n];

	for (int x, i = 0; i < n; ++i) {
		scanf("%d", &x);
		a[i] = x;
		b[i] = x;
	}

	for (int k, t, i = 0; i < n - 1; ++i) {
		k = i;

		for (int j = i + 1; j < n; ++j) {
			if(a[k] < a[j]) k = j;
		}

		if(k != i) t = a[i], a[i] = a[k], a[k] = t;
	}

	//b为完整的数组....
	//a为排序后的数组....
	int index, maxn = a[0];

	for (int i = 0; i < n; ++i) {
		if(maxn == b[i]) index = i;
	}

	//这里求出fmax在b中的index
	/*
	int c[index+1];
	for (int i = 0; i <= maxn; ++i)c[i]=i;*/
	//int c[maxn+1];
	//for (int i = 0; i <= maxn; ++i) c[i]=i;
	for (int count = 0, i = 0; i <= maxn; ++i) {
		count = 0;

		for (int j = 0; j < n; ++j) {
			if(i == b[j]) count += 1;
		}

		cout << count << endl;
	}

	return 0;
}