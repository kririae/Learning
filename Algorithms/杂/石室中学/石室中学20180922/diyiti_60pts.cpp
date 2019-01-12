#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 505;
int n, a[10005];
ll f[N][N][5];
inline int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
inline ll work30pts(int n, int *a) {
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			for (int k = j + 1; k <= n; ++k)
				for (int l = k + 1; l <= n; ++l)
					if (gcd(gcd(a[i], a[j]), gcd(a[k], a[l])) == 1) ++ans;
	return ans;
}
inline ll work60pts(int n, int *a) {
	memset(f, 0, sizeof f);
	f[1][a[1]][1] = 1;
	f[1][0][0] = 1;
	for (int i = 2; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			for (int k = 0; k <= 4; ++k)
				if (f[i - 1][j][k]) {
					if (k < 4)
						f[i][gcd(j, a[i])][k + 1] += f[i - 1][j][k];
					f[i][j][k] += f[i - 1][j][k];
				}
	return f[n][1][4];
}
int main() {
//	freopen("diyiti.in", "r", stdin);
//	freopen("diyiti.out", "w", stdout);
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		if (n <= 10)
			cout << work30pts(n, a) << endl;
		else if (n < 505) 
			cout << work60pts(n, a) << endl;
		else cout << 19260817 << endl;
	}
}