#include <bits/stdc++.h>
using namespace std;
int value[50005] = {0}, f[50005] = {0};
int main()
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
		cin >> value[i];

	for(int i = 1; i <= n; ++i) {
		f[i] = max(f[i - 1] + value[i], f[i] + value[i]);
	}

	cout << f[n] << endl;
	return 0;
}