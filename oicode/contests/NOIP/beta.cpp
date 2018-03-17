#include <cstdio>
#include <algorithm>
using namespace std;
int n, k, a[11], cnt, ans = -1;
int main()
{
	freopen("beta.in", "r", stdin);
	freopen("beta.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	if (n == 1 && !a[1] && k == 1)
	{
		printf("0");
		return 0;
	}
	else if (n == 1 && !a[1] && k != 1)
	{
		printf("-1");
		return 0;
	}
	for (int i = 1; i <= k; ++i)
		cnt += a[n];
	if (k == 2)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (!((a[i] + a[j]) % 3) && a[i] * 10 + a[j] > ans)
					ans = a[i] * 10 + a[j];
			}
		}
		printf("%d", ans);
		return 0;
	}
	else if (k == 1)
	{
		for (int i = n; i >= 1; --i)
			if (a[i] % 3 == 0)
			{
				ans = a[i];
				break;
			}
		printf("%d", ans);
		return 0;
	}
	else
	{
		cnt = (k - 3) * a[n];
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				for (int k = 1; k <= n; ++k)
				{
					if (!((a[i] + a[j] + a[k] + cnt) % 3) && a[i] * 100 + a[j] * 10 + a[k] > ans)
						ans = a[i] * 100 + a[j] * 10 + a[k];
				}
			}
		}
		if (ans == -1)
		{
			printf("-1");
			return 0;
		}
		for (int i = 1; i <= k - 3; ++i)
			printf("%d", a[n]);
		printf("%d", ans);
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
