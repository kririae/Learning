//trangle
#include <iostream>
#include <cstdio>
using namespace std;
int res[233];
/*
int* tr(int n) {
	if(n == 0) {
		res[0] = 1;
		return res;
	}
	res[0] = 1;
	res[n] = 1;
	for(int i = 1; i < n; ++i) {
		int *last = tr(n - 1);
		res[i] = last[i - 1] + last[i];
	}
	return res;
}*/
int main() {
	int n = 4;
	for(int i = 1;i < n; ++i) {
		res[0] = 1;
		res[i] = 1;
		for(int j = 1; j <= i; ++j) {
			res[j] = res[j - 1] + res[j];
		}
	}
	for(int i = 0; i < n + 1; ++i) {
		cout<<res[i]<<" ";
	}
	return 0;
}
