#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

#define N 50001
#define ll long long

using namespace std;

int n, m, pos[N], c[N];
ll s[N], ans;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

ll sqr(ll x)
{
	return x * x;
}

struct data
{
	int l, r, id;
	ll a, b;
} a[N];

bool cmp(data a, data b)
{
	if (pos[a.l] == pos[b.l])return a.r < b.r;

	return a.l < b.l;
}

bool cmp_id(data a, data b)
{
	return a.id < b.id;
}

void init()
{
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);

	int block = int(sqrt(n));

	for (int i = 1; i <= n; i++)
		pos[i] = (i - 1) / block + 1;

	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a[i].l, &a[i].r);
		a[i].id = i;
	}
}

void update(int p, int add)
{
	ans -= sqr(s[c[p]]);
	s[c[p]] += add;
	ans += sqr(s[c[p]]);
}

void solve()
{
	for (int i = 1, l = 1, r = 0; i <= m; i++)
	{
		for (; r < a[i].r; r++)
			update(r + 1, 1);

		for (; r > a[i].r; r--)
			update(r, -1);

		for (; l < a[i].l; l++)
			update(l, -1);

		for (; l > a[i].l; l--)
			update(l - 1, 1);

		if (a[i].l == a[i].r)
		{
			a[i].a = 0;
			a[i].b = 1;
			continue;
		}

		a[i].a = ans - (a[i].r - a[i].l + 1);
		a[i].b = (ll)(a[i].r - a[i].l + 1) *
				 (a[i].r - a[i].l);
		ll k = gcd(a[i].a, a[i].b);
		a[i].a /= k;
		a[i].b /= k;
	}
}

int main()
{
	init();
	sort(a + 1, a + m + 1, cmp);
	solve();
	sort(a + 1, a + m + 1, cmp_id);

	for (int i = 1; i <= m; i++)
		printf("%lld/%lld\n", a[i].a, a[i].b);

	return 0;
}