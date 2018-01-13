#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int a[n];
	memset(a, -1, sizeof(a));

	for (int i = 2; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(j % i == 0) a[j - 1] = -a[j - 1];
		}
	}

	int count = 0;

	for (int i = 0; i < n; ++i) {
		if(a[i] == -1) {
			b[count] = i + 1;
			count += 1;
		}
	}

	for(int i = 0; i < count; i++) {
		cout << b[i];

		if(i < count - 1) cout << ",";
	}
}