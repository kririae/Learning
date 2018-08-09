// 懒得写了
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200005;
int n, ans, a[N], vis[1000005];
int main()
{
	freopen("animal.in", "r", stdin);
	freopen("animal.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i], ++vis[a[i]];
	if(n <= 1000) {
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if(a[i] >= a[j]) ans = max(ans, a[i] % a[j]);
		cout << ans << endl;
	} else {
		return 0;
	}
}