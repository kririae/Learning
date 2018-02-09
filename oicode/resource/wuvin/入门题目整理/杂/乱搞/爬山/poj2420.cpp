#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
inline int read()
{
	char c = getchar();
	int ret = 0;
	while(c == ' ' || c == '\n') c = getchar();
	while(c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret;
}
int n;
double xx, yy, ans, t;
struct point {
	double x, y;
} p[105];
inline double sqr(double x)
{
	return x * x;
}
inline double dis(double x, double y, point p)
{
	return sqrt(sqr(x - p.x) + sqr(y - p.y));
}
inline double getsum(double x, double y)
{
	double tmp = 0;
	for(int i = 1; i <= n; i++)
		tmp += dis(x, y, p[i]);
	return tmp;
}
int main()
{
	while(scanf("%d", &n) == 1 && n) {
		xx = yy = 0;
		ans = 1e20;
		t = 5000;
		for(int i = 1; i <= n; i++) {
			int x1, y1;
			x1 = read();
			y1 = read();
			p[i].x = x1;
			p[i].y = y1;
			xx += p[i].x;
			yy += p[i].y;
		}
		xx /= n;
		yy /= n;
		ans = getsum(xx, yy); //取个中点
		double tmp, x, y;
		while(t > 0.02) {
			x = y = 0;
			for(int i = 1; i <= n; i++) {
				x += (p[i].x - xx) / dis(xx, yy, p[i]);
				y += (p[i].y - yy) / dis(xx, yy, p[i]);
			}
			tmp = getsum(xx + x * t, yy + y * t); //牛顿迭代
			if(tmp < ans) {
				ans = tmp;
				xx += x * t, yy += y * t;
			}
			t *= 0.9;
		}
		printf("%.0f\n", ans); //%lf poj会WA
	}
	return 0;
}
