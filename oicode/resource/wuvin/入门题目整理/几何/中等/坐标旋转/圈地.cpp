#include<cstdio>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define db int
/*
≤ªƒ‹”√%d ∂¡long long
6
-23 -21
18 -19
-7 -20
21 -36
-14 -49
3 32

*/
using namespace std;
struct point {
	db x, y;
	point(db xx = 0, db yy = 0)
	{
		x = xx;
		y = yy;
	}
	bool operator <(const point &b)const
	{
		return x < b.x;
	}
};
struct seg {
	point a, b;
};
point dec(point a, point b)
{
	point ret;
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	return ret;
}
db cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
bool equ(db a, db b)
{
	if(abs(a - b) < eps) return true;
	return false;
}


point operator -(point &a, point &b)
{
	return point(a.x - b.x, a.y - b.y);
}
struct angle {
	double ang;
	int f, t;
	bool operator <(const angle &b)const
	{
		return ang < b.ang;
	}
} a[1000005];
int n;
db ans = 0x7ffff000;
point p[1005];
int pi[1005];
int ip[1005];//index to place   place to index
void cal(int a1, int a2, int b)
{
	point a3 = p[a2] - p[a1];
	point a4 = p[b] - p[a1];
	db ret = abs(cross(a3, a4));
	if(ans > ret) ans = ret;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	sort(p + 1, p + n + 1);
	for(int i = 1; i <= n; i++) pi[i] = ip[i] = i;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(p[i].x == p[j].x) a[cnt].ang = -ans;
			else a[cnt].ang = (p[i].y - p[j].y) / (double)(p[i].x - p[j].x);
			a[cnt].f = i;
			a[cnt].t = j;
			cnt++;
		}
	}
	sort(a, a + cnt);
	for(int i = 0; i < cnt; i++) {
		int f = a[i].f;
		int t = a[i].t;
		if(ip[f] > ip[t]) swap(f, t);
		if(ip[f] > 1) cal(f, t, pi[ip[f] - 1]);
		if(ip[t] < n) cal(f, t, pi[ip[t] + 1]);
		swap(pi[ip[f]], pi[ip[t]]);
		swap(ip[f], ip[t]);
	}
	if(ans & 1) printf("%d.50", ans / 2);
	else printf("%d.00", ans / 2);
	return 0;
}
