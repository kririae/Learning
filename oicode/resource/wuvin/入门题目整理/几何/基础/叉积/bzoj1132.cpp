#include<cstdio>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define db long long
using namespace std;
struct point {
	db x, y;
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
db cross(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}
bool equ(db a, db b)
{
	if(abs(a - b) < eps) return true;
	return false;
}

point d[3005];
bool cmp(const point& a, const point &b)
{
	if(!equ(a.x, b.x)) {
		return a.x < b.x;
	} else {
		return a.y < b.y;
	}
}
db x_0, y_0;
point ang[3005];
int n;
db ans;
bool cmp2(const point& a, const point &b)
{
	return cross(a, b) > 0;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &d[i].x, &d[i].y);
	}
	sort(d + 1, d + n + 1, cmp);
	for(int i = 1; i <= n - 2; i++) {
		db xx = 0, yy = 0;
		int cnt = 0;
		for(int j = i + 1; j <= n; j++) {
			ang[cnt] = dec(d[j], d[i]);
			xx += ang[cnt].x;
			yy += ang[cnt].y;
			cnt++;
		}
		sort(ang, ang + cnt, cmp2);
		for(int j = 0; j < cnt; j++) {
			xx -= ang[j].x;
			yy -= ang[j].y;
			point pt;
			pt.x = xx;
			pt.y = yy;
			ans += cross(ang[j], pt);
		}
	}
	if(ans & 1) printf("%lld.5", ans >> 1);
	else printf("%lld.0", ans >> 1);
	return 0;
}
