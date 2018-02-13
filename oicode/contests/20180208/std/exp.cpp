#include <bits/stdc++.h>
#define LL long long
using namespace std;

inline int read()
{
	char c = getchar();
	int ret = 0, f = 1;
	for (; c < '0' || c > '9'; f = c == '-' ? -1 : 1, c = getchar())
		;
	for (; '0' <= c && c <= '9'; ret = ret * 10 + c - '0', c = getchar())
		;
	return ret * f;
}

inline int getPhi(int x)
{
	int ret = x;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			ret = ret / i * (i - 1);
			while (x % i == 0)
			{
				x /= i;
			}
		}
	}
	return x == 1 ? ret : ret / x * (x - 1);
}

inline int solve(int a, int n, int p)
{
	int phiP = getPhi(p), spj = 0;
	LL pw = 1;
	for (int i = 1; i <= n; i++)
	{
		pw *= i;
		if (pw >= phiP)
		{
			spj = 1;
			pw %= phiP;
		}
	}
	pw += spj * phiP;
	int ret = 1;
	for (int i = 1; i <= pw; i++)
	{
		ret = (LL)ret * a % p;
	}
	return ret;
}

int main()
{
	freopen("exp.in", "r", stdin);
	freopen("exp.out", "w", stdout);

	int T = read();
	for (int i = 1; i <= T; i++)
	{
		int a = read(), n = read(), p = read();
		printf("%d\n", solve(a, n, p));
	}
	return 0;
}
