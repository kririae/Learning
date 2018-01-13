#include<cstdio>
#include<cmath>
#include<iostream>
#define eps 1e-8
using namespace std;

/*--几何库--*/
struct point {
	double x, y;
};
struct vec {
	point a;
	vec(point a1, point b1)
	{
		a.x = a1.x - b1.x;
		a.y = a1.y - b1.y;
	}
	double cross(vec b)
	{
		return a.x * b.a.y - b.a.x * a.y;
	}
};
struct seg {
	point a, b;
} s[105];
//---------]
int n, T;
bool equ(double a, double b)
{
	if(abs(a - b) < eps) return true;
	return false;
}
bool inter(point a1, point b1, point a2, point b2) //直线与线段交
{
	vec la(a1, b1);
	if(la.cross(vec(a1, a2))*la.cross(vec(a1, b2)) < eps) return true;
	return false;
}
bool jud(point a, point b)
{
	if(equ(a.x, b.x) && equ(a.y, b.y))return 0;
	for(int i = 1; i <= n; i++)
		if(!inter(a, b, s[i].a, s[i].b))return 0;
	return 1;
}
int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lf%lf%lf%lf", &s[i].a.x, &s[i].a.y, &s[i].b.x, &s[i].b.y);
		int flag = 0;
		for(int i = 1; i <= n; i++) {
			if(flag) break;
			for(int j = 1; j <= n; j++) {
				if(jud(s[i].a, s[j].a)) {
					flag = 1;
					break;
				}
				if(jud(s[i].a, s[j].b)) {
					flag = 1;
					break;
				}
				if(jud(s[i].b, s[j].a)) {
					flag = 1;
					break;
				}
				if(jud(s[i].b, s[j].b)) {
					flag = 1;
					break;
				}
			}
		}

		if(!flag)printf("No!\n");
		else printf("Yes!\n");
	}
}
