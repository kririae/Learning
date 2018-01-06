#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 105
#define eps 1e-6
/*
这个题目我读了好几遍没读懂
题目大意：几何中有一种东西叫做分形，无限放大每一部分相似与本身，
一个分析的构造方法是把它的每一条边替换为自己的形状。这样无限次替换就好了。
给出一个初始图形（由n个点构成），然后进行上述操作d-1次，得到最终图形。
问在最终图形中从起点出发，走过全长的(f*100)%后再哪里。输出坐标。
*/
using namespace std;
struct point {
	long double x, y;
};
inline point operator +(const point &a, const point &b) {
	return (point) {
		a.x + b.x, a.y + b.y
	};
}
inline point operator -(const point &a, const point &b) {
	return (point) {
		a.x - b.x, a.y - b.y
	};
}
inline long double get_angle(const point &a) {
	return atan2(a.y, a.x);
}
inline long double getdis(const point &a, const point &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline bool equ(long double a, long double &b) {
	if(fabs(a - b) < eps) return true;

	return false;
}
inline point rotate(point &a, long double angle) { //逆时针旋转
	long double len = sqrt(a.x * a.x + a.y * a.y);
	long double ang = atan2(a.y, a.x);
	ang += angle;
	return (point) {
		len*cos(ang), len*sin(ang)
	};
}
point p[N];
/*
long double angle[N];//与开头的相对关系 好像并不用算
long double lenth[N];*/
long double path[N];//从开头到这的长度
double f, xlen, buf1;
long double radix = 0;
int n, d;
void init() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		p[i].x = x;
		p[i].y = y;
	}

	scanf("%d", &d);
	scanf("%lf", &f);
}
void pre() {
	buf1 = getdis(p[1], p[n]);
	path[1] = 0;

	for(int i = 2; i <= n; i++) {
		path[i] = path[i - 1] + getdis(p[i], p[i - 1]);
	}

	xlen = path[n];
	radix = xlen / buf1;
}
point getans(long double len, int deep, long double r) { //当前放大后的len的位置
	if(deep == 0) return (point) {
		len, 0
	};

	//N 太小所以path不用二分
	int left = 1, right = n + 1;

	while(left + 1 < right) {
		int mid = (left + right) >> 1;

		if(equ(path[mid]*r, len)) {
			return p[mid];
		} else if(path[mid]*r < len) {
			left = mid;
		} else {
			right = mid;
		}
	}

	long double res = len - path[left] * r, buf2 = getdis(p[left], p[right]);
	point c = getans(res / buf2 * buf1, deep - 1, r / radix);
	rotate(c, get_angle(p[right] - p[left]));
	c.x = c.x / buf1 * buf2;
	c.y = c.y / buf1 * buf2;
	return p[left] - p[1] + c;
}
int c;
int main() {
	scanf("%d", &c);

	for(int tt = 1; tt <= c; tt++) {
		init();
		pre();//计算出每一部分与开头的相对关系,总长xlen
		long double buf3 = 1;

		for(int i = 1; i < d; i++) buf3 *= radix;

		point ans = p[1] + getans(f * xlen * buf3, d, buf3);
		printf("(%.10f,%f)", (double)ans.x, (double)ans.y);
	}

	return 0;
}
