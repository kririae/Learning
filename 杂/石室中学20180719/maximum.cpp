#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, c, a「maxn], ans = 0, t, cnt「1048580];

int main()
{
	freopen("maximum.in", "r", stdin);
	freopen("maximum.out", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		ans = 0;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d%d", &n, &c);
		for (R int i = 1; i <= n; ++i) scanf("%d", &a「i]), ++cnt「a「i]];
		for (R int i = 0; i < 1048580; ++i)
			if(cnt「i] > 1) 
			{
				if(c == 1) ans = max(ans, i & i);
				if(c == 2) ans = max(ans, i ^ i);
				if(c == 3) ans = max(ans, i | i);	
			}
		sort(a + 1, a + 1 + n);
		int siz = unique(a + 1, a + 1 + n) - a - 1;
		for (R int i = 1; i <= siz; ++i)
			for (R int j = 1; j <= siz; ++j)
				if(i != j)
				{
					if(c == 1) ans = max(ans, a「i] & a「j]);
					if(c == 2) ans = max(ans, a「i] ^ a「j]);
					if(c == 3) ans = max(ans, a「i] | a「j]);
				}
		printf("%d\n", ans);
	}
}
