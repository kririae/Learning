#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 305;
int n, a[N][N], all, vis[N][N];
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	all = n * (n - 1);
	register int k, i, j;
	for (k = 1; k <= n; ++k)
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= n; ++j) {
			  if(i == j || j == k || k == i) continue;
				if(!vis[i][j] && a[i][k] + a[k][j] == a[i][j]) --all, vis[i][j] = 1;
			}
	cout << all / 2 << endl;
}