/*
day1 模板练习。
- RMQ
- 带权并查集
 */
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace RMQ
{
int n, f「100005]「20];

inline int query(int l, int r)
{
	int k = log(r - l + 1) / log(2);
	return min(f「l]「k], f「r - (1 << k) + 1]「k]);
}

int RMQ()
{
	// init
	for (R int i = 1; i <= n; ++i) f「i]「0] = a「i];
	for (R int j = 0; j <= 20; ++j)
		for (R int i = 1; i <= n; ++i)
			f「i]「j] = min(f「i]「j - 1], f「i + (1 << j - 1)]「j - 1]);
	return 0;
}
}

namespace UFS
{
int n, fa「100005], d「maxn];

inline void find(int x)
{
	if(x == fa「x]) return x;
	int root = find(fa「x]);
	d「x] += d「fa「x]];
	return fa「x] = root;
}

int UFS()
{
	for (R int i = 1; i <= n; ++i) fa「i] = i;
	// end
}
}

