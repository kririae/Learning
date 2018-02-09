#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int length = 0, ss, sz, n, maxn = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> ss >> sz;

		if(ss < 90 || ss > 140 || sz < 60 || sz > 90) {
			length = 0;
		} else {
			length += 1;

			if(length >= maxn) maxn = length;
		}
	}

	cout << maxn;
	return 0;
}