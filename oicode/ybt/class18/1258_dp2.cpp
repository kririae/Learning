#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int lines[1005][1005];
int values[1005][1005];
int main()
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= i; ++j)
			cin >> lines[i][j];

	values[1][1] = lines[1][1];

	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) {
			values[i][j] = max(values[i - 1][j - 1], values[i - 1][j]) + lines[i][j];
		}
	}

	int res = 0;

	for(int i = 1; i <= n; ++i) {
		res = max(res, values[n][i]);
	}

	cout << res;
}
