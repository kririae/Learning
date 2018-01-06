#include <bits/stdc++.h>
using namespace std;
int n, ans = 0, llll[1000][1000];
int memo[1000][1000];
void search(int, int, int);
int main() {
	cin >> n;

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) {
			cin >> llll[i][j];
		}
	}

	search(1, 1, 0);
	cout << ans;
	return 0;
}
void search(int a, int b, int val) {
	val += llll[a][b];

	if(val <= memo[a][b]) return ;

	memo[a][b] = val;

	if(a == n) {
		if(val > ans) ans = val;

		return;
	}

	search(a + 1, b, val);
	search(a + 1, b + 1, val);
}
