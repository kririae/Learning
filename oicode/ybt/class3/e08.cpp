#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int m, n, res = 0;
	cin >> m >> n;

	for(m; m <= n; m++) {
		if(m % 17 == 0) res += m;
	}

	cout << res;
	return 0;
}