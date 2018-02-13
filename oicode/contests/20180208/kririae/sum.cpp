#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &val)
{
	val = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		val = val * 10 + ch - '0';
		ch = getchar();
	}
	val *= f;
}

inline int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

const int maxn = 5000005;
const int mod = 1e9 + 7;
int n;
int a[maxn];
int main()
{
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	long long ans = 0;
	register int i = 1;
	register int j = 1;
	long long res;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			res = gcd(a[i], a[j]);
			// printf("gcd(%d, %d) = %d\n", a[i], a[j], res);
			ans += (long long)(res * (res - 1)) % mod;
		}
	}
	cout << ans % mod << endl;
}
