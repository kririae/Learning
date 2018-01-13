#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[105];
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	cin >> a;

	for (int i = 0; i < m; ++i) {
		int l, r;
		char c1, c2;
		cin >> l >> r >> c1 >> c2;

		for (int j = l - 1; j < r; ++j) {
			if(a[j] == c1) a[j] = c2;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << a[i];
	}

	return 0;
}