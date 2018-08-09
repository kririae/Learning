// by kririae
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, cnt;
int main()
{
	freopen("critique.in", "r", stdin);
	freopen("critique.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if(i % j == j / i) ++cnt;
	cout << cnt << endl;
}