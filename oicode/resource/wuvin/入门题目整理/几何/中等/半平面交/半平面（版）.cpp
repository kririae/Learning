#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<iostream>
#define eps 1e-8
#define db long double
using namespace std;
inline bool equ(db a, db b)
{
	if(abs(a - b) < eps) return true;
	return false;
}
struct point {
	db x, y;
	point operator *(const long double c)
	{
		return (point) {
			x*c, y*c
		};
	}
	point operator +(point c)
	{
		return (point) {
			x + c.x, y + c.y
		};
	}
};
inline point dec(point a, point b)
{
	point ret;
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	return ret;
}
inline db cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
struct seg {
	point a, b;
	long double k;
	seg(db ax, db ay, db bx, db by)
	{
		a.x = ax;
		a.y = ay;
		b.x = bx;
		b.y = by;
	}
	seg() {}
	inline void pre()
	{
		k = atan2(b.y - a.y, b.x - a.x);
	}
};//a->b face to LEFT
inline bool onleft(const seg &a, const point &b)
{
	if(cross(dec(a.b, a.a), dec(b, a.a)) > eps) return true;
	return false;
}
inline bool operator <(const seg &b, const seg& c)
{
	if(!equ(b.k, c.k)) return b.k < c.k; //按角
	return  onleft(c, b.a);
}
inline point get_inter(const seg &a, const seg &b) //&
{
	long double p1 = cross(dec(a.b, a.a), dec(b.b, a.a));
	long double p2 = cross(dec(a.b, a.a), dec(b.a, a.a));
	return dec(b.b, b.a) * (p2 / (p2 - p1)) + b.a;
}
//////////////////////////////几何
int n, cnt, pts;
int dq[20105];
int l, r;
point p2[20105];//i和i-1的交点
seg s[20005];
point out[20105];
int solve()
{
	sort(s, s + cnt);
	int cn2 = 1, cnt3 = 0;
	for(int i = 1; i < cnt; i++) { //去除平行
		if(!equ(s[i].k, s[i - 1].k)) s[cn2++] = s[i];
	}
	cnt = cn2;
	pts = 0;
	l = 0;
	dq[0] = 0;
	r = 1;
	for(int i = 0; i < cnt; i++) {
		while(pts > 0 && !onleft(s[i], p2[r - 1]))	r--, pts--;
		while(pts > 0 && !onleft(s[i], p2[l + 1]))	l++, pts--;
		dq[r++] = i;
		pts++;
		p2[r - 1] = get_inter(s[dq[r - 1]], s[dq[r - 2]]);
	}
	while(pts > 0 && !(onleft(s[dq[l]], p2[r - 1]))) r--, pts--;
	if(!pts) return 0;
	for(int i = l + 1; i < r; i++) {
		out[cnt3++] = p2[i];
	}
	out[cnt3++] = get_inter(s[dq[r - 1]], s[dq[l]]);
	return cnt3;
}
/////////////////////半平面交模板
void init()
{
	scanf("%d", &n);
	s[0] = seg(0, 10000, 0, 0);
	s[1] = seg(0, 0, 10000, 0);
	s[2] = seg(10000, 0, 10000, 10000);
	s[3] = seg(10000, 10000, 0, 10000);
	for(int i = 4; i < n + 4; i++) {
		double ax, ay, bx, by;
		scanf("%lf%lf%lf%lf", &ax, &ay, &bx, &by);
		s[i].a.x = ax, s[i].a.y = ay, s[i].b.x = bx, s[i].b.y = by;
	}
	cnt = n + 4;
	for(int i = 0; i < cnt; i++) {
		s[i].pre();
	}
}
double ans;
int m;
void getS()
{
	ans = 0;
	out[m] = out[0];
	for(int i = 0; i < m; i++) {
		ans += cross(out[i], out[i + 1]);
	}
	printf("%.1f", ans / 2);
}
int main()
{
	init();
	m = solve();
	getS();
	return 0;
}
