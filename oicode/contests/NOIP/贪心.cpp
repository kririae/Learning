#include <cstdio>
#include <algorithm>
using namespace std;
int t, n, m, a[1001], b[1001];
int main()
{
	scanf("%d", &t);
	for (int iii = 1; iii <= t; ++iii)
	{
		for (int i = 0; i <= 1000; ++i)
			a[i] = -1;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; ++i)
			scanf("%d", &b[i]);
		sort(b + 1, b + 1 + m);
		for (int i = 1; i <= m; ++i)
		{
			int cnt = 0;
			for (int k = b[i]; k <= n; k += b[i])
				cnt -= a[k];
			if (cnt > 0)
				for (int k = b[i]; k <= n; k += b[i])
					a[k] = -a[k];
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i] == 1)
				++ans;
		printf("%d\n", ans);
	}
	return 0;
}
