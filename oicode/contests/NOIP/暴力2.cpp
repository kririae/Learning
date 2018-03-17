#include <cstdio>
using namespace std;
int a[1005], b[1005], m, n, ans, cnt;
void x1(int v)
{
	if (v == m + 1)
	{
		cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i])
				++cnt;
		if (cnt > ans)
			ans = cnt;
		return;
	}
	for (int i = b[v]; i <= n; i += b[v])
		a[i] = 1 - a[i];
	x1(v + 1);
	for (int i = b[v]; i <= n; i += b[v])
		a[i] = 1 - a[i];
	x1(v + 1);
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ++ii)
	{
		for (int i = 0; i <= 1004; ++i)
			a[i] = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; ++i)
			scanf("%d", &b[i]);
		ans = 0;
		x1(1);
		printf("%d\n", ans);
	}
	return 0;
}
