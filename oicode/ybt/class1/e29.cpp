#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int f, s, l, n;
	cin >> f >> s >> n;
	cout << f + (s - f)*(n - 1);
	return 0;
}