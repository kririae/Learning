// by kririae
#define ll long long
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
int n, a[maxn], b[maxn], g[maxn], p[maxn], rep[maxn];
int main()
{
	freopen("find.in", "r", stdin);
	freopen("find.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	for (int i = 1; i <= n; ++i) p[a[i]] = i;
	for (int i = 1; i <= n; ++i) rep[i] = p[b[i]];
	memset(g, 0x3f, sizeof(g));
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int pos = lower_bound(g + 1, g + 1 + n, rep[i]) - g;
		g[pos] = rep[i], ans = max(ans, pos);
	}
	printf("%d", ans);
}