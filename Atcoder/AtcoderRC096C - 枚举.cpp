/*
过于水了，不解释了
 */
#define ll long long
#include <bits/stdc++.h>

using namespace std;

namespace ARC096C
{
ll a, b, c, x, y, ans, tmp, tmp2;
inline void solve()
{
	while(~scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &x, &y))
	{
    	tmp = min(x, y), tmp2 = max(x, y);
    	ans = x * a + y * b;
    	ans = min(ans, (c << 1) * tmp + (x - tmp) * a + (y - tmp) * b);
    	ans = min(ans, (c << 1) * tmp2);
    	printf("%lld", ans), ans = 0;
	}
}
}

int main()
{
    return ARC096C::solve(), 0;
}