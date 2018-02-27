#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
#define inf 100000000
#define mod 1000000007
#define eps 1e-10
using namespace std;
int n, m;
struct P
{
	double x, y;
} a[505], b[505];
int dis[505][505], mp[505][505];
double operator*(P a, P b)
{
	return a.x * b.y - a.y * b.x;
}
P operator-(P a, P b)
{
	P t;
	t.x = a.x - b.x;
	t.y = a.y - b.y;
	return t;
}
bool col(P x, P y)
{
	if (x.x > y.x)swap(x, y);

	for (int i = 1; i <= m; i++)
		if (b[i].x < x.x || b[i].x > y.x)
			return 0;

	if (x.y > y.y)swap(x, y);

	for (int i = 1; i <= m; i++)
		if (b[i].y < x.y || b[i].y > y.y)
			return 0;

	return 1;
}
int jud(P x, P y)
{
	int c1 = 0, c2 = 0;

	for (int i = 1; i <= m; i++)
	{
		double t = (y - x) * (b[i] - x);

		if (t > eps)c1++;

		if (t < -eps)c2++;

		if (c1 * c2)return 0;
	}

	if (!c1 && !c2 && col(x, y)) {puts("2"); return -1;}

	if (c1) return 1;

	if (c2) return 2;

	return 3;
}

void floyd()
{
	int ans = inf;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			if (dis[i][k] < inf)
				for (int j = 1; j <= n; j++)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	for (int i = 1; i <= n;
		 i++)ans = min(ans, dis[i][i]);

	if (ans == inf || ans <= 2)puts("-1");

	else printf("%d", ans);
}
void solve()
{
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			int flag = jud(a[i], a[j]);

			if (flag == -1)return;

			if (flag == 1)dis[i][j] = 1;

			else if (flag == 2)dis[j][i] = 1;

			else if (flag == 3)dis[i][j] = dis[j][i] = 1;
		}

	floyd();
}
bool spj()
{
	for (int i = 1; i <= n; i++)
		if (fabs(a[i].x - a[1].x) > eps ||
			fabs(a[i].y - a[1].y) > eps)return 0;

	for (int i = 1; i <= m; i++)
		if (fabs(b[i].x - a[1].x) > eps ||
			fabs(b[i].y - a[1].y) > eps)return 0;

	puts("1");
	return 1;
}
int main()
{
	memset(dis, 127 / 3, sizeof(dis));
	scanf("%d%d", &n, &m);
	double K;

	for (int i = 1; i <= n; i++)
		scanf("%lf%lf%lf", &a[i].x, &a[i].y, &K);

	for (int i = 1; i <= m; i++)
		scanf("%lf%lf%lf", &b[i].x, &b[i].y, &K);

	if (spj())return 0;

	solve();
	return 0;
}