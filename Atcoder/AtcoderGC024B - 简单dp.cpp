#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, ans, a[maxn], f[maxn];

int main()
{
	scanf("%d", &n);
	for (R int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (R int i = 1; i <= n; ++i)
		f[a[i]] = f[a[i] - 1] + 1, ans = max(ans, f[a[i]]);
	printf("%d", n - ans);
	return 0;
}