#include <iostream>
#include <cstdio>
using namespace std;
bool used[20005];
int main()
{
	int v, n;
	cin >> v >> n;
	int maxn = 0;
	used[0] = true;
	for (int value, i = 0; i < n; ++i)
	{
		cin >> value;
		for (int k = maxn; k >= 0; --k)
		{
			if (used[k])
			{
				if (k + value > v)
					continue;
				used[k + value] = true;
				if (k + value > maxn)
					maxn = k + value;
			}
		}
	}
	for (int i = v; i >= 0; --i)
	{
		if (used[i])
		{
			cout << v - i;
			return 0;
		}
	}
	return 0;
}