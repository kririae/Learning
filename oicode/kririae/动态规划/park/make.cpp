#include <bits/stdc++.h>

using namespace std;

int t, n, m, k, p;

inline long long rand_huge()
{
	return rand() * rand();
}

int main()
{
	freopen("park.in", "w", stdout);
	t = 3;
	n = 100;
	m = 200;
	k = 50;
	p = 23333;
	cout << t << endl;
	for (int i = 1; i <= t; ++i)
	{
		cout << n << " " << m << " " << k << " " << p << endl;
		for (int j = 1; j <= m; ++j)
			cout << rand_huge() % n << " " << rand_huge() % n << " " << rand() % 1001 << endl;
	}
}
