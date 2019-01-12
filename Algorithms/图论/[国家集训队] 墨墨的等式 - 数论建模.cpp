#define ll long long
#define R register
#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;

namespace BZOJ2118
{
ll n, l, r, a[15], minv = ~(1 << 62), dis[maxn];
queue<int> q;
bitset<maxn> vis;

inline ll get(ll val)
{
	ll ans = 0;
	for (R int i = 0; i < minv; ++i)
		if(dis[i] <= val) ans += (val - dis[i]) / minv + 1;
	return ans;
}

inline void solve()
{
	memset(dis, 0x3f, sizeof(dis));
	scanf("%lld%lld%lld", &n, &l, &r);
	for (R int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (R int i = 1; i <= n; ++i) minv = min(minv, a[i]);
	q.push(0), vis[0] = 1, dis[0] = 0;
	while(!q.empty())
	{
		int curr = q.front(); q.pop(), vis[curr] = 0;
		for (R int i = 1; i <= n; ++i)
		{
			int to = (curr + a[i]) % minv;
			if(dis[to] > dis[curr] + a[i])
			{
				dis[to] = dis[curr] + a[i];
				if(!vis[to]) vis[to] = 1, q.push(to);
			}
		}
	}
	printf("%lld", query(r) - query(l - 1));
}
}

int main()
{
	return BZOJ2118::solve(), 0;
}