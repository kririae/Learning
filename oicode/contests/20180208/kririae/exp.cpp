#include <bits/stdc++.h>
using namespace std;
int t, a, n, p;
// O(n\log{n})
// a^{n!} <(-_-)>
inline int pow(int a, int n, int p)
{
	// kuaisumi
	long long ans = 1;
	long long tempo = a;
	int as = log(n) / log(2) + 2;
	for (int i = 0; i < as; ++i)
	{ // pow
		if (n & (1 << i))
			ans = (long long)(ans * tempo) % p;
		tempo = (long long)(tempo * tempo) % p;
	}
	return ans % p;
}
int main()
{
	freopen("exp.in", "r", stdin);
	freopen("exp.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		cin >> a >> n >> p;
		long long ans = pow(a, n, p);
		for (int i = 0; i < n; ++i)
		{
			ans = pow(ans, n - i, p);
		}
		cout << ans % p << endl;
	}
}
