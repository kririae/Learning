// by kririae
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, m, a[N], b[N], c[N], s[N], f[N][N][N], g[N][N];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d", &a[i], &b[i], &c[i]), s[i] = c[i];
	sort(s + 1, s + 1 + n);
	for (int i = 1; i <= n; ++i)
		c[i] = lower_bound(s + 1, s + 1 + n, c[i]) - s;
	// f[i][j][k]表示[i, j]中最小话费是s[k]的总和最大值
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = a[i]; k <= b[i]; ++k)
				

	dp(1, n);
}